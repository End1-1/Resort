#include "fexportreservation.h"
#include "ui_fexportreservation.h"
#include "wreportgrid.h"
#include "vauchers.h"
#include "wreservation.h"
#include "cachereservestate.h"

FExportReservation::FExportReservation(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FExportReservation)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Export reservations"), ":/images/database.png");
    fReportGrid->addToolBarButton(":/images/invoice.png", tr("Open invoice"), SLOT(openInvoice()),
                                  this)->setFocusPolicy(Qt::ClickFocus);
    fReportGrid->addToolBarButton(":/images/bed.png", tr("Open reservation"), SLOT(openReservation()),
                                  this)->setFocusPolicy(Qt::ClickFocus);
    ui->leStateCode->setSelector(this, cache(cid_reserve_state), ui->leStateName);
    connect(ui->wd, &WDate2::changed, [this]() {
        apply(fReportGrid);
    });
    connect(fReportGrid->fModel, SIGNAL(sortFinished()), this, SLOT(sortFinished()));
}

FExportReservation::~FExportReservation()
{
    delete ui;
}

QString FExportReservation::reportTitle()
{
    return QString("%1 %2-%3")
           .arg(tr("Export reservations"))
           .arg(ui->wd->dss1())
           .arg(ui->wd->dss2());
}

QWidget *FExportReservation::firstElement()
{
    return ui->wd->fw();
}

QWidget *FExportReservation::lastElement()
{
    return ui->wd->lw();
}

void FExportReservation::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(30, "", tr(""))
    .setColumn(30, "", tr(""))
    .setColumn(80, "", tr("Code"))
    .setColumn(80, "", tr("Invoice"))
    .setColumn(100, "", tr("State"))
    .setColumn(120, "", tr("Entry"))
    .setColumn(120, "", tr("Departure"))
    .setColumn(250, "", tr("Guest"))
    .setColumn(200, "", tr("Cardex"))
    .setColumn(0, "", tr("F"))
    .setColumn(100, "", tr("Group"))
    .setColumn(120, "", tr("Created"))
    ;
    QString query = "select '', '', r.f_id, r.f_invoice, rs.f_" + def_lang + ", "
                    "r.f_startDate, r.f_endDate, g.guest, c.f_name, r.f, gr.f_name, r.f_created "
                    "from f_reservation r "
                    "left join f_reservation_state rs on rs.f_id=r.f_state "
                    "left join guests g on g.f_id=r.f_guest "
                    "left join f_cardex c on c.f_cardex=r.f_cardex "
                    "left join f_reservation_group gr on gr.f_id=r.f_group "
                    "where r.f_state<>0 ";
    if (ui->leStateCode->asInt() > 0) {
        query += " and r.f_state=" + ui->leStateCode->text();
    }
    if (ui->rbEntry->isChecked()) {
        query += " and r.f_startDate between " + ui->wd->ds1() + " and " + ui->wd->ds2();
    } else if (ui->rbDeparture->isChecked()) {
        query += " and r.f_endDate between " + ui->wd->ds1() + " and " + ui->wd->ds2() + "";
    } else if (ui->rbCreated->isChecked()) {
        query += " and r.f_created between " + ui->wd->ds1() + " and " + ui->wd->ds2() + "";
    } else if (ui->rbCanceled->isChecked()) {
        query += " and r.f_cancelDate between " + ui->wd->ds1() + " and " + ui->wd->ds2() + "";
    }
    rg->fModel->setSqlQuery(query);
    rg->fModel->apply(rg);
    rg->fModel->fCheckBoxColumns.append(0);
    rg->fModel->fCheckBoxColumns.append(1);
    rg->fModel->fCheckBoxIsCheckable.append(0);
    sortFinished();
}

void FExportReservation::openInvoice()
{
    QList<QVariant> out;
    if (fReportGrid->fillRowValuesOut(out) < 0) {
        return;
    }
    openInvoiceWithId(out.at(3).toString());
}

void FExportReservation::openReservation()
{
    QList<QVariant> out;
    if (fReportGrid->fillRowValuesOut(out) < 0) {
        return;
    }
    WReservation::openReserveWindows(out.at(2).toString());
}

void FExportReservation::on_btnStartExport_clicked()
{
    if (message_confirm(tr("Confirm to start export reservations")) != QDialog::Accepted) {
        return;
    }
    for (int i = 0; i < fReportGrid->fModel->rowCount(); i++) {
        if (fReportGrid->fModel->data(i, 0, Qt::CheckStateRole).toInt() == Qt::Checked) {
            exportReservation(fReportGrid->fModel->data(i, 2).toString());
            fReportGrid->fModel->setData(i, 1, 1);
        }
    }
    message_info(tr("Done"));
}

void FExportReservation::sortFinished()
{
    for (int i = 0, count = fReportGrid->fModel->rowCount(); i < count; i++) {
        if (fReportGrid->fModel->data(i, 9).toInt() == 1) {
            fReportGrid->fModel->setBackgroundColor(i, Qt::gray);
        } else {
            fReportGrid->fModel->setBackgroundColor(i, Qt::white);
        }
    }
}

void FExportReservation::exportReservation(const QString &id)
{
    DoubleDatabase fDD;
    QString errStr;
    QStringList dbParams = fPreferences.getDb("AHC").toString().split(";", Qt::SkipEmptyParts);
    DoubleDatabase sDb;
    sDb.setDatabase(dbParams[0], dbParams[1], dbParams[2], dbParams[3]);
    if (!sDb.open()) {
        message_error("Connection error, " + sDb.fLastError);
        return;
    }
    sDb.startTransaction();
    DoubleDatabase dd;
    dd.open();
    fDD[":f_id"] = id;
    fDD.exec("select * from f_reservation where f_id=:f_id");
    fDD.nextRow();
    fDD.getBindValues(0, sDb.fBindValues);
    if (ui->chOverride->isChecked()) {
        dd[":f_id"] = sDb[":f_id"];
        dd.exec("delete from f_reservation where f_id=:f_id");
    }
    if (!sDb.insert("f_reservation", false)) {
        errStr += sDb.fLastError + "<br>";
    }
    if (fDD.getValue("f_group").toInt() > 0) {
        DoubleDatabase dt;
        dt.open();
        dt[":f_id"] = fDD.getValue(0, "f_group").toInt();
        dt.exec("select * from f_reservation_group where f_id=:f_id");
        if (dt.rowCount() == 0) {
            errStr += "Missing group for this reservation <br>";
        }
        if (ui->chOverride->isChecked()) {
            dd[":f_id"] = fDD.getValue(0, "f_group").toInt();
            dd.exec("delete from f_reservation_group where f_id=:f_id");
        }
        dt.getBindValues(0, sDb.fBindValues);
        if (sDb[":f_extra1"].toString().trimmed().length() > 0) {
            sDb[":f_name"] = sDb[":f_extra1"];
        }
        if (ui->chOverride->isChecked()) {
            dd[":f_id"] = sDb[":f_id"];
            dd.exec("delete form f_reservation_group where f_id=:f_id");
        }
        if (!sDb.insert("f_reservation_group", false)) {
            errStr += sDb.fLastError;
        }
    }
    DoubleDatabase dr2;
    dr2.open();
    dr2[":f_inv"] = fDD.getValue("f_invoice");
    dr2.exec("select * from m_register where f_inv=:f_inv");
    for (int i = 0; i < dr2.rowCount(); i++) {
        dr2.getBindValues(i, sDb.fBindValues);
        if (ui->chOverride->isChecked()) {
            dd[":f_id"] = sDb[":f_id"];
            dd.exec("delete from m_register where f_id=:f_id");
        }
        if (!sDb.insert("m_register", false)) {
            errStr += sDb.fLastError + "<br>";
        }
    }
    //RESTAURANT VOUCHERS OF ONLINE RESERVATIONS
    for (int i = 0; i < dr2.rowCount(); i++) {
        if (dr2.getValue(i, "f_source").toString() == VAUCHER_POINT_SALE_N) {
            DoubleDatabase dt1;
            dt1.open();
            dt1[":f_id"] = dr2.getValue(i, "f_id");
            dt1.exec("select * from o_header where f_id=:f_id");
            if (dt1.rowCount() == 0) {
                errStr += "Missing header for " + dr2.getValue(i, "f_id").toString() + "<br>";
                continue;
            }
            dt1.getBindValues(0, sDb.fBindValues);
            if (ui->chOverride->isChecked()) {
                dd[":f_id"] = dr2.getValue(i, "f_id");
                dd.exec("delete from o_header where f_id=:f_id");
            }
            if(!sDb.insert("o_header", false)) {
                errStr += sDb.fLastError + "<br>";
            }
            DoubleDatabase dt2;
            dt2.open();
            dt2[":f_header"] = dr2.getValue(i, "f_id");
            dt2.exec("select * from o_dish where f_header=:f_header");
            for (int j = 0; j < dt2.rowCount(); j++) {
                dt2.getBindValues(j, sDb.fBindValues);
                if (ui->chOverride->isChecked()) {
                    dd[":f_id"] = sDb[":f_id"];
                    dd.exec("delete from o_dish where f_id=:f_id");
                }
                if (!sDb.insert("o_dish", false)) {
                    errStr += sDb.fLastError + "<br>";
                }
            }
        }
    }
    DoubleDatabase dr3;
    dr3.open();
    dr3[":f_id"] = id;
    dr3.exec("select * from f_guests where f_id in (select f_guest from f_reservation_guests where f_reservation=:f_id)");
    for (int i = 0; i < dr3.rowCount(); i++) {
        dr3.getBindValues(i, sDb.fBindValues);
        dd[":f_id"] = sDb[":f_id"];
        dd.exec("delete from f_guests where f_id=:f_id");
        if (!sDb.insert("f_guests", false)) {
            errStr += sDb.fLastError + "<br>";
        }
    }
    //END GUESTS
    //F_RESERVATION_GUESTS
    DoubleDatabase dr4;
    dr4.open();
    dr4[":f_id"] = id;
    dr4.exec("select * from f_reservation_guests where f_reservation=:f_id");
    dd[":f_reservation"] = id;
    dd.exec("delete from f_reservation_guests where f_reservation=:f_reservation");
    for (int i = 0; i < dr4.rowCount(); i++) {
        dr4.getBindValues(i, sDb.fBindValues);
        sDb.fBindValues.remove(":f_id");
        if(!sDb.insert("f_reservation_guests", false)) {
            errStr += sDb.fLastError + "<br>";
        }
    }
    if (errStr.length() > 0) {
        message_error(errStr);
        sDb.rollback();
    } else {
        dr4[":f"] = 1;
        dr4.update("f_reservation", where_id(ap(id)));
        sDb.commit();
    }
}

void FExportReservation::on_chSelectAll_clicked(bool checked)
{
    for (int i = 0; i < fReportGrid->fModel->rowCount(); i++) {
        fReportGrid->fModel->setData(fReportGrid->fModel->index(i, 0), (checked ? Qt::Checked : Qt::Unchecked),
                                     Qt::CheckStateRole);
    }
    fReportGrid->fTableView->viewport()->update();
}
