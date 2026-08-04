#include "wcityledgerlist.h"
#include "recityledger.h"
#include "cacherights.h"
#include "cachecityledger.h"
#include "broadcastthread.h"
#include "message.h"
#include "doubledatabase.h"
#include "stringutils.h"

#include <QDesktopServices>
#include <QFile>
#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QTemporaryFile>
#include <QTextStream>
#include <QToolButton>
#include <QUrl>
#include <QDir>

WCityLedgerList::WCityLedgerList(QWidget *parent) :
    WReportGrid(parent)
{
    fModel->setColumn(80, "f_id", tr("Code"))
            .setColumn(300, "f_name", tr("Name"))
            .setColumn(300, "f_address", tr("Address"))
            .setColumn(200, "f_phone", tr("Phone"))
            .setColumn(200, "f_email", tr("Email"))
            .setColumn(100, "f_extra1", tr("Extra1"))
            .setColumn(100, "f_extra2", tr("Extra2"))
            .setColumn(80, "f_alwaysinvoice", tr("Always invoice"));

    fModel->setSqlQuery("select f_id, f_name, f_address, f_phone, f_email, f_extra1, f_extra2, f_alwaysinvoice "
                        "from f_city_ledger order by f_id");
    fModel->apply(this);

    fRowEditorDialog = new RECityLedger(fRowValues, this);
    setBtnNewVisible();

    if (r__(cr__super_correction)) {
        auto *btn = addToolBarButton(":/images/upward.png", tr("Export"), SLOT(exportToJson()), this);
        btn->setToolTip(tr("Export city ledger to JSON"));
        btn->setFocusPolicy(Qt::ClickFocus);
        btn = addToolBarButton(":/images/upward.png", tr("Import"), SLOT(importFromJson()), this);
        btn->setToolTip(tr("Import city ledger from JSON"));
        btn->setFocusPolicy(Qt::ClickFocus);
    }
}

void WCityLedgerList::setupTab()
{
    setupTabTextAndIcon(tr("City Ledger"), ":/images/currency.png");
}

void WCityLedgerList::exportToJson()
{
    QJsonObject je;
    je["export"] = "EXPORTED CITY LEDGER";
    QJsonArray ja;
    DoubleDatabase fDD;

    for (int i = 0; i < fModel->rowCount(); i++) {
        const int id = fModel->data(i, 0).toInt();
        fDD[":f_id"] = id;
        if (!fDD.exec("select * from f_city_ledger where f_id=:f_id") || !fDD.nextRow()) {
            continue;
        }
        QJsonObject row;
        fDD.valuesToJsonObject(row);
        ja.append(row);
    }

    je["f_city_ledger"] = ja;
    const QString filename = QFileDialog::getSaveFileName(this, tr("Export"), "", "*.json");
    if (filename.isEmpty()) {
        return;
    }
    QFile f(filename);
    if (!f.open(QIODevice::WriteOnly)) {
        message_error(tr("Cannot save file!"));
        return;
    }
    f.write(QJsonDocument(je).toJson());
    f.close();
    message_info(tr("Export completed"));
}

void WCityLedgerList::importFromJson()
{
    const QString filename = QFileDialog::getOpenFileName(this, tr("Import"), "", "*.json");
    if (filename.isEmpty()) {
        return;
    }
    QFile f(filename);
    if (!f.open(QIODevice::ReadOnly)) {
        return;
    }

    const QJsonObject jdoc = QJsonDocument::fromJson(f.readAll()).object();
    f.close();

    if (jdoc["export"].toString() != "EXPORTED CITY LEDGER" || !jdoc.contains("f_city_ledger")) {
        message_error(tr("This is not a City Ledger export file"));
        return;
    }
    if (jdoc.contains("f_cardex")) {
        message_error(tr("This is a Partners (Cardex) file. Import it from Partners."));
        return;
    }

    const QJsonArray rows = jdoc["f_city_ledger"].toArray();
    if (rows.isEmpty()) {
        message_error(tr("No City Ledger records in file"));
        return;
    }

    QMessageBox box(this);
    box.setIcon(QMessageBox::Question);
    box.setWindowTitle(tr("Import"));
    box.setText(tr("What to do if a record already exists?"));
    QAbstractButton *btnSkip = box.addButton(tr("Skip"), QMessageBox::AcceptRole);
    QAbstractButton *btnUpdate = box.addButton(tr("Update"), QMessageBox::ActionRole);
    box.addButton(QMessageBox::Cancel);
    box.exec();
    if (box.clickedButton() == box.button(QMessageBox::Cancel) || box.clickedButton() == nullptr) {
        return;
    }
    const bool updateExisting = (box.clickedButton() == btnUpdate);
    Q_UNUSED(btnSkip);

    DoubleDatabase fDD;
    QStringList existsIds;
    int imported = 0;
    int updated = 0;
    int skipped = 0;

    for (int i = 0; i < rows.size(); i++) {
        const QJsonObject row = rows.at(i).toObject();
        const int id = row["f_id"].toVariant().toInt();
        fDD[":f_id"] = id;
        fDD.exec("select f_id from f_city_ledger where f_id=:f_id");
        if (fDD.nextRow()) {
            existsIds.append(QString::number(id));
            if (!updateExisting) {
                skipped++;
                continue;
            }
            fDD.bindFromJsonObject(row, QStringList() << "f_id");
            if (!fDD.update("f_city_ledger", where_id(id))) {
                message_error(fDD.fLastError);
                continue;
            }
            updated++;
            BroadcastThread::cmdRefreshCache(cid_city_ledger, QString::number(id));
            continue;
        }
        if (fDD.insert("f_city_ledger", row) == 0) {
            message_error(fDD.fLastError);
            continue;
        }
        imported++;
        BroadcastThread::cmdRefreshCache(cid_city_ledger, QString::number(id));
    }

    fModel->apply(this);
    message_info(tr("End of import. Imported: %1, Updated: %2, Skipped: %3")
                 .arg(imported).arg(updated).arg(skipped));

    if (!existsIds.isEmpty()) {
        QTemporaryFile temp(QDir::tempPath() + "/cityledger_exists_XXXXXX.txt");
        temp.setAutoRemove(false);
        if (!temp.open()) {
            return;
        }
        QTextStream out(&temp);
        out << (updateExisting ? tr("Already exists, updated:") : tr("Already exists, skipped:")) << '\n';
        for (const QString &line : existsIds) {
            out << line << '\n';
        }
        out.flush();
        const QString path = temp.fileName();
        temp.close();
        QDesktopServices::openUrl(QUrl::fromLocalFile(path));
    }
}
