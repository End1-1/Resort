#include "finvoices.h"
#include "ui_finvoices.h"
#include "wreportgrid.h"
#include "waccinvoice.h"
#include <QDesktopServices>
#include <QTemporaryFile>
#include <QToolButton>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFileDialog>

FInvoices::FInvoices(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FInvoices)
{
    ui->setupUi(this);
    ui->deStart->setDate(WORKING_DATE.addDays(-1 * 180));

    if(r__(cr__super_correction)) {
        if(fPreferences.getDb("HC").toInt() == 0) {
            QToolButton *btn = fReportGrid->addToolBarButton(":/images/biohazard.png", tr("Eliminate!"), SLOT(removeInvoiceWithAllReference()), this);
            btn->setToolTip(tr("Remove invoice with all references"));
            btn->setFocusPolicy(Qt::ClickFocus);
        }

        auto *btn = fReportGrid->addToolBarButton(":/images/upward.png", tr("Export"), SLOT(exportToJson()), this);
        btn->setToolTip(tr("Remove invoice with all references"));
        btn->setFocusPolicy(Qt::ClickFocus);
        btn = fReportGrid->addToolBarButton(":/images/upward.png", tr("Import"), SLOT(importFromJson()), this);
        btn->setToolTip(tr("Remove invoice with all references"));
        btn->setFocusPolicy(Qt::ClickFocus);
    }

    ui->chContainsEmptyRooming->setVisible(false);
}

FInvoices::~FInvoices()
{
    delete ui;
}

void FInvoices::apply(WReportGrid *rg)
{
    QString where = "where r.f_state=3 and  (r.f_endDate between '"
                    + ui->deStart->date().toString(def_mysql_date_format) + "' and '"
                    + ui->deEnd->date().toString(def_mysql_date_format) + "') ";

    if(ui->chContainsEmptyRooming->isChecked()) {
        where += " and f.f>0 ";
    }

    if(ui->chNoVAT->isChecked()) {
        where += " and r.f_vatmode=3 ";
    }

    where +=  "order by r.f_endDate, r.f_room ";
    buildQuery(rg, where);
    QList<int> cols;
    cols << 4 << 5 << 6;
    QList<double> vals;
    fReportGrid->fModel->sumOfColumns(cols, vals);
    fReportGrid->setTblTotalData(cols, vals);
}

QWidget* FInvoices::firstElement()
{
    return ui->deStart;
}

QWidget* FInvoices::lastElement()
{
    return ui->deEnd;
}

QString FInvoices::reportTitle()
{
    return QString("%1 From %2 To %3").arg(tr("Invoices"), ui->deStart->text(), ui->deEnd->text());
}

QCheckBox* FInvoices::chFreeRooming()
{
    return ui->chContainsEmptyRooming;
}

void FInvoices::openReport(bool free)
{
    QList<int> widths;
    widths << 80
           << 120
           << 80
           << 300
           << 100
           << 100
           << 100
           << 100
           << 100
           ;
    QStringList fields;
    fields << "r.f_invoice"
           << "r.f_endDate"
           << "r.f_room"
           << "concat(g.f_title,' ',g.f_firstName,' ',g.f_lastName) as f_guest"
           << "coalesce(c.amount,0) as f_credit"
           << "coalesce(d.amount,0) as f_debet"
           << "coalesce(b.amount,0) as f_balance"
           << "coalesce(f.f, 0) as f"
           << "r.f_booking";
    QStringList titles;
    titles << tr("Number")
           << tr("Date")
           << tr("Room")
           << tr("Guest")
           << tr("Debit")
           << tr("Credit")
           << tr("Balance")
           << tr("Free")
           << tr("Booking");
    QMap<QString, bool> includes;
    includes["r.f_invoice"] = true;
    includes["r.f_endDate"] = true;
    includes["r.f_room"] = true;
    includes["concat(g.f_title,' ',g.f_firstName,' ',g.f_lastName) as f_guest"] = true;
    includes["coalesce(c.amount,0) as f_credit"] = true;
    includes["coalesce(d.amount,0) as f_debet"] = true;
    includes["coalesce(b.amount,0) as f_balance"] = true;
    includes["coalesce(f.f, 0) as f"] = true;
    includes["r.f_booking"] = true;
    QStringList tables;
    tables << "f_reservation r"
           << "f_guests g"
           << "(select f_inv, sum(f_amountAmd) as amount from m_register where f_sign=1 and f_finance=1  and f_canceled=0 group by 1) c"
           << "(select f_inv, sum(f_amountAmd) as amount from m_register where f_sign=-1 and f_finance=1 and f_canceled=0 group by 1) d"
           << "(select f_inv, sum(f_amountAmd*f_sign) as amount from m_register where f_canceled=0 and f_finance=1 group by 1) b"
           << QString("(select f_inv, count(f_id) as f from m_register where f_canceled=0 and f_finance=1 and f_itemCode in (%1) and f_amountAmd<1 group by 1) f")
           .arg(fPreferences.getDb("rooming_list").toString());
    QStringList joins;
    joins << "from"
          << "left"
          << "left"
          << "left"
          << "left"
          << "left"
          << "left";
    QStringList joinConds;
    joinConds << ""
              << "g.f_id=r.f_guest"
              << "c.f_inv=r.f_invoice"
              << "d.f_inv=r.f_invoice"
              << "b.f_inv=r.f_invoice"
              << "f.f_inv=r.f_invoice"
              ;
    QString title = tr("Invoices");
    QString icon = ":/images/invoice.png";
    WReportGrid *rg = addTab<WReportGrid>();
    rg->setQueryModel<FInvoices>(widths, fields, titles, includes, tables, joins, joinConds, title, icon);
    WAccInvoice *ai = new WAccInvoice(rg);
    FInvoices *v = static_cast<FInvoices*>(rg->fFilter);
    v->chFreeRooming()->setChecked(free);
    v->apply(rg);
    Q_UNUSED(ai)
}

void FInvoices::removeInvoiceWithAllReference()
{
    QList<QVariant> out;
    int row;

    if((row = fReportGrid->fillRowValuesOut(out)) < 0) {
        message_info(tr("Nothing was selected"));
        return;
    }

    QString inv = out.at(0).toString();

    if(inv.isEmpty()) {
        return;
    }

    if(message_confirm(tr("Confirm remove selected invoice with all reference. Log will disabled for this action.")) != QDialog::Accepted) {
        return;
    }

    QList<int> ps;
    DoubleDatabase fDD;
    fDD[":f_inv"] = inv;
    fDD.exec("select f_doc from m_register where f_inv=:f_inv and f_source='PS'");

    while(fDD.nextRow()) {
        ps << fDD.getInt(0);
    }

    foreach(int id, ps) {
        fDD[":f_header"] = id;
        fDD.exec("delete from o_dish where f_header=:f_header");
        fDD[":f_id"] = id;
        fDD.exec("delete from o_header where f_id=:f_id");
    }

    fDD[":f_inv"] = inv;
    fDD.exec("delete from m_register where f_inv=:f_inv");
    fDD[":f_invoice"] = inv;
    fDD.exec("delete from f_reservation where f_invoice=:f_invoice");
    fReportGrid->fModel->removeRow(row);
    message_info(tr("Invoice removed with all references. Refresh reports."));
}

void FInvoices::exportToJson()
{
    QJsonObject je;
    je["export"] = "EXPORTED INVOICES";
    QJsonArray ja;

    for(int i = 0; i < fReportGrid->fModel->rowCount(); i++) {
        QString invoice = fReportGrid->fModel->stringData(i, 0);
        QJsonObject jreservation;
        DoubleDatabase fDD;
        fDD[":f_invoice"] = invoice;
        fDD.exec("select * from f_reservation where f_invoice=:f_invoice");

        if(fDD.nextRow()) {
            fDD.valuesToJsonObject(jreservation);
        }

        fDD[":f_reservation"] = jreservation["f_id"].toString();
        fDD.exec("select * from f_reservation_guests where f_reservation=:f_reservation");
        QJsonArray jreservationguests;

        while(fDD.nextRow()) {
            QJsonObject jr;
            fDD.valuesToJsonObject(jr);
            jreservationguests.append(jr);
        }

        fDD[":f_inv"] = invoice;
        fDD.exec("select * from m_register where f_inv=:f_inv");
        QJsonArray jmregister;

        while(fDD.nextRow()) {
            QJsonObject jr;
            fDD.valuesToJsonObject(jr);
            jmregister.append(jr);
        }

        fDD[":f_reservation"] = jreservation["f_id"].toString();
        fDD.exec("select * from f_guests where f_id in (select f_guest from f_reservation_guests where f_reservation=:f_reservation)");
        QJsonArray jguests;

        while(fDD.nextRow()) {
            QJsonObject jr;
            fDD.valuesToJsonObject(jr);
            jguests.append(jr);
        }

        QJsonObject jfull;
        jfull["f_reservation_guests"] = jreservationguests;
        jfull["f_reservation"] = jreservation;
        jfull["m_register"] = jmregister;
        jfull["f_guests"] = jguests;
        ja.append(jfull);
    }

    je["invoices"] = ja;
    QString filename = QFileDialog::getSaveFileName(this, "", "", "*.json");

    if(filename.isEmpty()) {
        return;
    }

    QFile f(filename);

    if(!f.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("Cannot save file!"));
        return;
    }

    f.write(QJsonDocument(je).toJson());
    f.close();
}

void FInvoices::importFromJson()
{
    QString filename = QFileDialog::getOpenFileName(this, "", "", "*.json");

    if(filename.isEmpty()) {
        return;
    }

    QFile f(filename);

    if(!f.open(QIODevice::ReadOnly)) {
        f.close();
        return;
    }

    QJsonObject jdoc = QJsonDocument::fromJson(f.readAll()).object();
    QJsonArray jinvoices = jdoc["invoices"].toArray();
    DoubleDatabase fDD;
    QStringList existsInvoices;

    for(int i = 0; i < jinvoices.size(); i++) {
        QJsonObject jinvoice = jinvoices.at(i).toObject();
        QString invoiceNum = jinvoice["f_reservation"].toObject()["f_invoice"].toString();
        fDD[":f_invoice"] = invoiceNum;
        fDD.exec("select * from f_reservation where f_invoice=:f_invoice");

        if(fDD.nextRow()) {
            existsInvoices.append(invoiceNum);
            continue;
        }

        QJsonArray jguests = jinvoice["f_guests"].toArray();

        for(int g = 0; g < jguests.size(); g++) {
            QJsonObject jguest = jguests.at(g).toObject();
            fDD.insert("f_guests", jguest);
        }

        fDD.insert("f_reservation", jinvoice["f_reservation"].toObject());
        QJsonArray jreservationguests = jinvoice["f_reservation_guests"].toArray();

        for(int g = 0; g < jreservationguests.size(); g++) {
            QJsonObject jguest = jreservationguests.at(g).toObject();
            fDD.insert("f_reservation_guests", jguest);
        }

        QJsonArray mregister = jinvoice["m_register"].toArray();

        for(int g = 0; g < mregister.size(); g++) {
            QJsonObject  jregister = mregister.at(g).toObject();
            fDD.insert("m_register", jregister);
        }
    }

    message_info(tr("End of import"));

    if(!existsInvoices.isEmpty()) {
        QTemporaryFile temp(QDir::tempPath() + "/myapp_XXXXXX.txt");
        temp.setAutoRemove(false);

        if(!temp.open()) {
            qWarning("Cannot open temporary file");
            return;
        }

        QTextStream out(&temp);

        for(const QString &line : existsInvoices)
            out << line << '\n';

        out.flush();
        const QString path = temp.fileName();
        temp.close();
        QDesktopServices::openUrl(QUrl::fromLocalFile(path));
    }
}

void FInvoices::on_btnNext_clicked()
{
    Utils::dateEditNext(ui->deStart, ui->deEnd);
}

void FInvoices::on_btnPrev_clicked()
{
    Utils::dateEditPrev(ui->deStart, ui->deEnd);
}
