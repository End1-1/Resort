#include "wcardexlist.h"
#include "dlgcardex.h"
#include "cacherights.h"
#include "cachecardex.h"
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

WCardexList::WCardexList(QWidget *parent) :
    WReportGrid(parent)
{
    fModel->setColumn(0, "f_id", tr("Code"))
            .setColumn(50, "F_group", tr("Group"))
            .setColumn(0, "", tr("Group code"))
            .setColumn(100,"f_cardex",tr("Cardex"))
            .setColumn(100,"f_cityLedger",tr("City Ledger"))
            .setColumn(300,"f_name",tr("Name"))
            .setColumn(150,"f_addr1",tr("Address 1"))
            .setColumn(150,"f_addr2",tr("Address 2"))
            .setColumn(150,"f_contact",tr("Contact"))
            .setColumn(150,"f_contactPos",tr("Contact pos"))
            .setColumn(100,"f_email",tr("Email"))
            .setColumn(100,"f_tel",tr("Tel."))
            .setColumn(100,"f_fax",tr("Fax"))
            .setColumn(100,"f_dateFrom",tr("Valid from"))
            .setColumn(100,"f_dateTo",tr("Valid to"))
            .setColumn(100,"f_commission",tr("Commission"))
            .setColumn(0, "f_vatMode", tr("VAT code"))
            .setColumn(80, "f_vatModeName", tr("VAT"))
            .setColumn(0, "f_bookingRequired", tr("Booking required"))
            .setColumn(100, "f_extra1", tr("Extra1"))
            .setColumn(100, "f_extra2", tr("Extra2"))
            ;

    fModel->setSqlQuery("select c.f_id, c.f_group, g.f_id, c.f_cardex,f_cityLedger,c.f_name,f_addr1,f_addr2, "
                        "f_contact,f_contactPos,"
                        "f_email,f_tel,f_fax,f_dateFrom,f_dateTo,f_commission,f_vatMode, v.f_" + def_lang + ", "
                        "f_bookingRequired, f_extra1, f_extra2 "
                        "from f_cardex c "
                        "left join f_vat_mode v on v.f_id=c.f_vatMode "
                        "left join f_cardex_group g on c.f_group=g.f_code "
                        "order by c.f_cardex");
    fModel->apply(this);

    fRowEditorDialog = new DlgCardex(fRowValues, this);
    setBtnNewVisible();

    if (r__(cr__super_correction)) {
        auto *btn = addToolBarButton(":/images/upward.png", tr("Export"), SLOT(exportToJson()), this);
        btn->setToolTip(tr("Export partners (cardex) to JSON"));
        btn->setFocusPolicy(Qt::ClickFocus);
        btn = addToolBarButton(":/images/upward.png", tr("Import"), SLOT(importFromJson()), this);
        btn->setToolTip(tr("Import partners (cardex) from JSON"));
        btn->setFocusPolicy(Qt::ClickFocus);
    }
}

void WCardexList::setupTab()
{
    setupTabTextAndIcon(tr("Partners"), ":/images/partner.png");
}

void WCardexList::exportToJson()
{
    QJsonObject je;
    je["export"] = "EXPORTED CARDEX";
    QJsonArray ja;
    DoubleDatabase fDD;

    for (int i = 0; i < fModel->rowCount(); i++) {
        const int id = fModel->data(i, 0).toInt();
        fDD[":f_id"] = id;
        if (!fDD.exec("select * from f_cardex where f_id=:f_id") || !fDD.nextRow()) {
            continue;
        }
        QJsonObject row;
        fDD.valuesToJsonObject(row);
        ja.append(row);
    }

    je["f_cardex"] = ja;
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

void WCardexList::importFromJson()
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

    if (jdoc["export"].toString() != "EXPORTED CARDEX" || !jdoc.contains("f_cardex")) {
        message_error(tr("This is not a Partners (Cardex) export file"));
        return;
    }
    if (jdoc.contains("f_city_ledger")) {
        message_error(tr("This is a City Ledger file. Import it from City Ledger."));
        return;
    }

    const QJsonArray rows = jdoc["f_cardex"].toArray();
    if (rows.isEmpty()) {
        message_error(tr("No Partners (Cardex) records in file"));
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
    QStringList existsCodes;
    int imported = 0;
    int updated = 0;
    int skipped = 0;

    for (int i = 0; i < rows.size(); i++) {
        const QJsonObject row = rows.at(i).toObject();
        const QString cardex = row["f_cardex"].toString();
        fDD[":f_cardex"] = cardex;
        fDD.exec("select f_id from f_cardex where f_cardex=:f_cardex");
        if (fDD.nextRow()) {
            existsCodes.append(cardex);
            if (!updateExisting) {
                skipped++;
                continue;
            }
            const int existingId = fDD.getValue(0).toInt();
            fDD.bindFromJsonObject(row, QStringList() << "f_id");
            if (!fDD.update("f_cardex", where_id(existingId))) {
                message_error(fDD.fLastError);
                continue;
            }
            updated++;
            BroadcastThread::cmdRefreshCache(cid_cardex, cardex);
            continue;
        }
        if (fDD.insert("f_cardex", row) == 0) {
            message_error(fDD.fLastError);
            continue;
        }
        imported++;
        BroadcastThread::cmdRefreshCache(cid_cardex, cardex);
    }

    fModel->apply(this);
    message_info(tr("End of import. Imported: %1, Updated: %2, Skipped: %3")
                 .arg(imported).arg(updated).arg(skipped));

    if (!existsCodes.isEmpty()) {
        QTemporaryFile temp(QDir::tempPath() + "/cardex_exists_XXXXXX.txt");
        temp.setAutoRemove(false);
        if (!temp.open()) {
            return;
        }
        QTextStream out(&temp);
        out << (updateExisting ? tr("Already exists, updated:") : tr("Already exists, skipped:")) << '\n';
        for (const QString &line : existsCodes) {
            out << line << '\n';
        }
        out.flush();
        const QString path = temp.fileName();
        temp.close();
        QDesktopServices::openUrl(QUrl::fromLocalFile(path));
    }
}
