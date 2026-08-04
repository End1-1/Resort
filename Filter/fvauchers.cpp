#include "fvauchers.h"
#include <QDate>
#include <QDateTime>
#include <QFile>
#include <QFileDialog>
#include <QInputDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTime>
#include "cachevaucher.h"
#include "stringutils.h"
#include "dlgadvanceentry.h"
#include "dlghdmviewer.h"
#include "dlgprintvoucherasinvoice.h"
#include "paymentmode.h"
#include "pprintvaucher.h"
#include "tablemodel.h"
#include "ui_fvauchers.h"
#include "vauchers.h"
#include "wreportgrid.h"
#include "wvauchereditor.h"

#define SEL_VAUCHER 1

namespace {

QJsonArray queryToJsonArray(DoubleDatabase &db)
{
    QJsonArray arr;
    while (db.nextRow()) {
        QJsonObject jo;
        db.valuesToJsonObject(jo);
        arr.append(jo);
    }
    return arr;
}

QString jsonId(const QJsonValue &v)
{
    if (v.isString()) {
        return v.toString().trimmed();
    }
    if (v.isDouble()) {
        const qint64 id = static_cast<qint64>(v.toDouble());
        return id > 0 ? QString::number(id) : QString();
    }
    return v.toVariant().toString().trimmed();
}

QVariant jsonToDbVariant(const QString &fieldName, const QJsonValue &val)
{
    if (val.isNull() || val.isUndefined()) {
        return QVariant();
    }
    const QString fn = fieldName.toLower();
    if (val.isDouble()) {
        const qint64 n = static_cast<qint64>(val.toDouble());
        if (n == 0 && fn.contains("date")) {
            return QVariant();
        }
        return val.toVariant();
    }
    if (!val.isString()) {
        return val.toVariant();
    }

    const QString s = val.toString().trimmed();
    if (s.isEmpty()) {
        return QVariant();
    }
    if (fn == "f_time" || (fn.endsWith("time") && !fn.contains("date"))) {
        QTime t = QTime::fromString(s, Qt::ISODate);
        if (!t.isValid()) {
            t = QTime::fromString(s, "HH:mm:ss");
        }
        return t.isValid() ? QVariant(t) : QVariant(s);
    }
    if (fn.contains("date")) {
        if (s == "0000-00-00" || s.startsWith("0000-00-00")) {
            return QVariant();
        }
        if (s.contains('T') || (s.contains(' ') && s.contains(':'))) {
            QString parseDt = s;
            if (parseDt.endsWith('Z', Qt::CaseInsensitive)) {
                parseDt.chop(1);
            }
            const int dotPos = parseDt.indexOf('.');
            if (dotPos > 10) {
                parseDt = parseDt.left(dotPos);
            }
            QDateTime dt = QDateTime::fromString(parseDt, "yyyy-MM-ddTHH:mm:ss");
            if (!dt.isValid()) {
                dt = QDateTime::fromString(s, Qt::ISODate);
            }
            if (!dt.isValid()) {
                dt = QDateTime::fromString(s, "yyyy-MM-dd HH:mm:ss");
            }
            if (dt.isValid()) {
                return QVariant(dt);
            }
        }
        const QDate d = QDate::fromString(s.left(10), "yyyy-MM-dd");
        if (d.isValid()) {
            return QVariant(d);
        }
    }
    return val.toVariant();
}

bool upsertFromJson(DoubleDatabase &db, const QString &table, const QJsonObject &rec)
{
    const QString id = jsonId(rec.value("f_id"));
    if (id.isEmpty()) {
        db.fLastError = QString("missing f_id in %1").arg(table);
        return false;
    }
    DoubleDatabase check;
    check[":f_id"] = id;
    if (!check.exec(QString("select f_id from %1 where f_id=:f_id").arg(table))) {
        db.fLastError = check.fLastError;
        return false;
    }
    const bool exists = check.nextRow();
    db.fBindValues.clear();
    for (auto it = rec.constBegin(); it != rec.constEnd(); ++it) {
        db.fBindValues[":" + it.key()] = jsonToDbVariant(it.key(), it.value());
    }
    if (exists) {
        return db.update(table, where_id(ap(id)));
    }
    return db.insert(table, false) != 0;
}

QJsonArray jsonToArray(const QJsonValue &val)
{
    if (val.isArray()) {
        return val.toArray();
    }
    if (val.isObject()) {
        QJsonArray arr;
        arr.append(val.toObject());
        return arr;
    }
    return QJsonArray();
}

} // namespace

FVauchers::FVauchers(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FVauchers)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Vouchers"), ":/images/file.png");
    fBtnRemove = fReportGrid->addToolBarButton(":/images/garbage.png", tr("Cancelation"), SLOT(cancelation()), this);
    fBtnRemove->setFocusPolicy(Qt::ClickFocus);
    fReportGrid->addToolBarButton(":/images/edit.png", tr("Edit"), SLOT(edit()), this)->setFocusPolicy(Qt::ClickFocus);
    fReportGrid->addToolBarButton(":/images/invoice.png", tr("Open invoice"), SLOT(openInvoice()), this)->setFocusPolicy(Qt::ClickFocus);
    fReportGrid->addToolBarButton(":/images/printer.png", tr("Print voucher"), SLOT(printVaucher()), this)->setFocusPolicy(Qt::ClickFocus);
    fReportGrid->addToolBarButton(":/images/printer.png", tr("Print voucher as invoice"), SLOT(printVoucherAsInvoice()), this)->setFocusPolicy(Qt::ClickFocus);
    fBtnRevive = fReportGrid->addToolBarButton(":/images/heart-pulses.png", tr("Revive voucher"), SLOT(reviveVaucher()), this);
    fBtnRevive->setFocusPolicy(Qt::ClickFocus);
    fBtnRevive->setEnabled(false);
    fBtnRevive->setVisible(r__(cr__super_correction));
    QToolButton *btnVaucher = fReportGrid->addToolBarButton(":/images/notepad.png", tr("Edit raw data"), SLOT(editRawData()), this);
    btnVaucher->setVisible(r__(cr__super_correction));
    btnVaucher->setFocusPolicy(Qt::ClickFocus);
    if (r__(cr__super_correction)) {
        fReportGrid->addToolBarButton(":/images/biohazard.png", tr("Eliminate"), SLOT(eliminateVoucher()), this)->setFocusPolicy(Qt::ClickFocus);
        fReportGrid->addToolBarButton(":/images/upward.png", tr("Export"), SLOT(exportVoucher()), this)->setFocusPolicy(Qt::ClickFocus);
        fReportGrid->addToolBarButton(":/images/upward.png", tr("Import"), SLOT(importVoucher()), this)->setFocusPolicy(Qt::ClickFocus);
    }
    fQuery = "SELECT r.f_id,\
            r.f_source,\
            r.f_wdate,\
            r.f_rdate,\
            r.f_time,\
            r.f_user,\
            u.f_username,\
            r.f_room,\
            r.f_guest,\
            r.f_itemCode,\
            r.f_finalName,\
            r.f_amountAmd,\
            r.f_amountVat,\
            r.f_amountAmd / r.f_amountUsd,\
            r.f_fiscal, \
            r.f_paymentMode,\
            i.f_en, \
            r.f_creditCard,\
            r.f_cityLedger,\
            r.f_paymentComment,\
            left(r.f_dc, 1),\
            r.f_doc,\
            r.f_rec,\
            r.f_finance,\
            r.f_remarks,\
            r.f_canceled,\
            r.f_cancelReason, \
            r.f_cancelDate, \
            uc.f_username, \
            r.f_inv, left(fr.f_cardex, 2) \
        FROM m_register r \
        left join users u on u.f_id=r.f_user \
        left join f_payment_type i on i.f_id=r.f_paymentMode \
        left join users uc on uc.f_id=r.f_cancelUser \
        left join f_reservation fr on fr.f_invoice=r.f_inv \
        where f_wdate between :f_date1 and :f_date2 :novat ";

        ui->leVaucherCode->setSelector(this, cache(cid_vaucher), ui->leVacherName);
        //connect(fReportGrid, SIGNAL(doubleClickOnRow(QList<QVariant>)), this, SLOT(doubleClickOnRow(QList<QVariant>)));
        connect(fReportGrid, SIGNAL(clickOnRow(int)), this, SLOT(clickOnRow(int)));
        connect(fReportGrid, SIGNAL(tblMainDoubleClick(QModelIndex)), this, SLOT(tblMainDblClick(QModelIndex)));
}

FVauchers::~FVauchers()
{
    delete ui;
}

void FVauchers::open()
{
    WReportGrid *rg = addTab<WReportGrid>();
    FVauchers *v = new FVauchers(rg);
    rg->addFilterWidget(v);
    v->apply(rg);
}

void FVauchers::openWithFilter(const QDate &d1, const QDate &d2, const QString &itemlist)
{
    WReportGrid *rg = addTab<WReportGrid>();
    FVauchers *v = new FVauchers(rg);
    v->ui->deFrom->setDate(d1);
    v->ui->deTo->setDate(d2);
    v->fItems = itemlist;
    rg->addFilterWidget(v);
    v->apply(rg);
    v->ui->leVaucherCode->setEnabled(false);
}

void FVauchers::apply(WReportGrid *rg)
{
    QString query = fQuery;
    int canceled = 0;
    if (ui->chCanceled->isChecked()) {
        canceled = 120; //this is a column width
    }
    if (ui->chNoVAT->isChecked()) {
        query.replace(":novat", " and r.f_vatmode=3 ");
    } else {
        query.replace(":novat", "");
    }
    fReportGrid->fModel->clearColumns();
    fReportGrid->fModel->setColumn(80, "", tr("Code"))
            .setColumn(0, "", tr("VC"))
            .setColumn(80, "", tr("Date"))
            .setColumn(0, "", tr("Real date"))
            .setColumn(50, "", tr("Time"))
            .setColumn(0, "", tr("UserCode"))
            .setColumn(50, "", tr("OP"))
            .setColumn(60, "", tr("Room"))
            .setColumn(300, "", tr("Guest"))
            .setColumn(0, "", tr("ItemCode"))
            .setColumn(200, "", tr("Voucher"))
            .setColumn(80, "", tr("Amount"))
            .setColumn(40, "", tr("VAT"))
            .setColumn(80, "", tr("Amount USD"))
            .setColumn(100, "", tr("Tax"))
            .setColumn(0, "", tr("Payment mode"))
            .setColumn(100, "", tr("Payment"))
            .setColumn(0, "", tr("Card"))
            .setColumn(80, "", tr("CL"))
            .setColumn(150, "", tr("Comment"))
            .setColumn(30, "", tr("D/C"))
            .setColumn(0, "", tr("Doc"))
            .setColumn(0, "", tr("Rec"))
            .setColumn(0, "", tr("Finance"))
            .setColumn(200, "", tr("Remarks"))
            .setColumn(0, "", tr("Canceled"))
            .setColumn(canceled * 2, "", tr("CancelReason"))
            .setColumn(canceled, "", tr("Cancel date"))
            .setColumn(canceled * 2, "", tr("Cancel User"))
            .setColumn(0, "", tr("Invoice"))
            .setColumn(60, "", tr("Cardex group"))
            ;
    query = query.replace(":f_date1", ui->deFrom->dateMySql()).replace(":f_date2", ui->deTo->dateMySql());
    if (ui->leVaucherCode->text().length() > 0) {
        query += " and r.f_source='" + ui->leVaucherCode->text() + "'";
    }
    if (ui->chCanceled->isChecked()) {
        query += " and r.f_canceled=1";
    } else {
        query += " and r.f_canceled=0";
    }
    if (!fItems.isEmpty()) {
        query += " and r.f_itemcode in (" + fItems + ") ";
    }
    query += " order by r.f_source ";
    rg->fModel->setSqlQuery(query);
    rg->fModel->apply(rg);
    QList<int> cols;
    QList<double> vals;
    cols << 11 << 12 << 13;
    rg->fModel->sumOfColumns(cols, vals);
    rg->setTblTotalData(cols, vals);
}

QWidget *FVauchers::firstElement()
{
    return ui->deFrom;
}

QWidget *FVauchers::lastElement()
{
    return ui->deTo;
}

QString FVauchers::reportTitle()
{
    return QString("%1 %2-%2 %3").arg(tr("Vouchers"), ui->deFrom->text(), ui->deTo->text(), ui->leVaucherCode->text());
}

void FVauchers::clickOnRow(int row)
{
    if (row < 0) {
        fBtnRemove->setEnabled(false);
    }
    bool e = true;
    if (!r__(cr__invoice_cancelation_current_date)) {
        e = false;
    } else {
        QList<QVariant> rowData;
        fReportGrid->fillRowValuesOut(rowData);
        if (rowData.count() < 0) {
            return;
        }
        QDate date = rowData.at(2).toDate();
        if (date != WORKING_DATE) {
            e = false;
        }
    }
    e = e || r__(cr__super_correction);
    fBtnRemove->setEnabled(e);
}

void FVauchers::eliminateVoucher()
{
    QList<QVariant> out;
    int row = fReportGrid->fillRowValuesOut(out);
    if (row < 0) {
        return;
    }
    if (message_confirm(QString("<h1><font color=\"red\">%1</font></h1>").arg(tr("Confirm to permanently remove voucher"))) != QDialog::Accepted) {
        return;
    }
    DoubleDatabase l(TrackControl::fDbHost, TrackControl::fDbDb, TrackControl::fDbUser, TrackControl::fDbPass);
    l.open();
    DoubleDatabase fDD;
    fDD[":f_id"] = out.at(0);
    fDD.exec("select * from m_register where f_id=:f_id");
    QString id, invoice, reserve, name;
    if (fDD.nextRow()) {
        id = out.at(0).toString();
        name = fDD.getString("f_finalName");
        invoice = fDD.getString("f_inv");
        reserve = fDD.getString("f_res");
    }
    fDD[":f_id"] = out.at(0);
    fDD.exec("delete from m_register where f_id=:f_id");
    if (out.at(1).toString() == VAUCHER_POINT_SALE_N) {
        fDD[":f_id"] = out.at(0);
        fDD.exec("delete from o_header where f_id=:f_id");
        fDD[":f_header"] = out.at(0);
        fDD.exec("delete from o_dish where f_header=:f_header");
        fDD.exec("delete from o_dish_qty where f_rec not in (select f_id from o_dish)");
//        l[":f_rec"] = out.at(0);
//        l[":f_invoice"] = out.at(0);
//        l.exec("delete from log where f_rec=:f_rec or f_invoice=:f_invoice");
    }
    if (out.at(1).toString() == VAUCHER_EVENT_N) {
        fDD[":f_id"] = out.at(0);
        fDD.exec("delete from o_event where f_id=:f_id");
//        l[":f_rec"] = out.at(0);
//        l[":f_invoice"] = out.at(0);
//        l.exec("delete from log where f_rec=:f_rec or f_invoice=:f_invoice");
    }
//    l[":f_rec"] = out.at(0);
//    l.exec("delete from log where f_rec=:f_rec");
    TrackControl::insert(TRACK_RESERVATION, "ELIMINATE VOUCHER", name, "", id, invoice, reserve);
    fReportGrid->fModel->removeRow(row);
}

void FVauchers::exportVoucher()
{
    QList<QVariant> out;
    int row = fReportGrid->fillRowValuesOut(out);
    if (row < 0) {
        message_info(tr("Nothing was selected"));
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_id"] = out.at(0);
    fDD.exec("select * from m_register where f_id=:f_id");
    if (!fDD.nextRow()) {
        message_error(tr("Voucher not found"));
        return;
    }
    const QString fInv = fDD.getString("f_inv");
    const QString fRes = fDD.getString("f_res");

    QJsonArray jregisters;
    if (!fInv.isEmpty()) {
        fDD[":f_inv"] = fInv;
        fDD.exec("select * from m_register where f_inv=:f_inv");
        jregisters = queryToJsonArray(fDD);
    } else {
        QJsonObject jregister;
        fDD.valuesToJsonObject(jregister);
        jregisters.append(jregister);
    }

    QJsonObject jreservation;
    QJsonArray jreservationguests;
    QJsonArray jguests;
    QString reservationId;
    if (!fRes.isEmpty()) {
        fDD[":f_id"] = fRes;
        fDD.exec("select * from f_reservation where f_id=:f_id");
        if (fDD.nextRow()) {
            fDD.valuesToJsonObject(jreservation);
            reservationId = jreservation.value("f_id").toString();
        }
    } else if (!fInv.isEmpty()) {
        fDD[":f_invoice"] = fInv;
        fDD.exec("select * from f_reservation where f_invoice=:f_invoice");
        if (fDD.nextRow()) {
            fDD.valuesToJsonObject(jreservation);
            reservationId = jreservation.value("f_id").toString();
        }
    }
    if (!reservationId.isEmpty()) {
        fDD[":f_reservation"] = reservationId;
        fDD.exec("select * from f_reservation_guests where f_reservation=:f_reservation");
        jreservationguests = queryToJsonArray(fDD);
        fDD[":f_reservation"] = reservationId;
        fDD.exec("select * from f_guests where f_id in ("
                 "select f_guest from f_reservation where f_id=:f_reservation and f_guest>0 "
                 "union select f_guest from f_reservation_guests where f_reservation=:f_reservation and f_guest>0)");
        jguests = queryToJsonArray(fDD);
    }

    QJsonObject root;
    root["export"] = "m_register_voucher";
    root["m_register"] = jregisters;
    if (!jreservation.isEmpty()) {
        root["f_reservation"] = jreservation;
    }
    root["f_reservation_guests"] = jreservationguests;
    root["f_guests"] = jguests;

    const QString defaultName = out.at(0).toString() + ".json";
    QString filename = QFileDialog::getSaveFileName(this, tr("Export voucher"), defaultName, tr("JSON (*.json)"));
    if (filename.isEmpty()) {
        return;
    }
    if (!filename.endsWith(".json", Qt::CaseInsensitive)) {
        filename += ".json";
    }
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        message_error(tr("Cannot save file"));
        return;
    }
    file.write(QJsonDocument(root).toJson(QJsonDocument::Indented));
    file.close();
    message_info(tr("Voucher exported"));
}

void FVauchers::importVoucher()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Import voucher"), "", tr("JSON (*.json)"));
    if (filename.isEmpty()) {
        return;
    }
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        message_error(tr("Cannot open file"));
        return;
    }
    const QJsonObject jdoc = QJsonDocument::fromJson(file.readAll()).object();
    file.close();

    QJsonArray jregisters = jsonToArray(jdoc.value("m_register"));
    if (jregisters.isEmpty() && jdoc.contains("f_id")) {
        jregisters.append(jdoc);
    }
    if (jregisters.isEmpty()) {
        message_error(tr("Invalid voucher JSON: missing m_register"));
        return;
    }

    DoubleDatabase fDD;
    if (!fDD.startTransaction()) {
        message_error(fDD.fLastError);
        return;
    }

    const QJsonArray jguests = jdoc.value("f_guests").toArray();
    for (const QJsonValue &v : jguests) {
        const QJsonObject jguest = v.toObject();
        if (jguest.isEmpty() || jsonId(jguest.value("f_id")).isEmpty()) {
            continue;
        }
        if (!upsertFromJson(fDD, "f_guests", jguest)) {
            fDD.rollback();
            message_error(fDD.fLastError);
            return;
        }
    }

    const QJsonObject jreservation = jdoc.value("f_reservation").toObject();
    if (!jreservation.isEmpty()) {
        if (!upsertFromJson(fDD, "f_reservation", jreservation)) {
            fDD.rollback();
            message_error(fDD.fLastError);
            return;
        }
    }

    const QJsonArray jreservationguests = jdoc.value("f_reservation_guests").toArray();
    for (const QJsonValue &v : jreservationguests) {
        if (!upsertFromJson(fDD, "f_reservation_guests", v.toObject())) {
            fDD.rollback();
            message_error(fDD.fLastError);
            return;
        }
    }

    QString primaryId;
    for (const QJsonValue &v : jregisters) {
        const QJsonObject jregister = v.toObject();
        if (primaryId.isEmpty()) {
            primaryId = jsonId(jregister.value("f_id"));
        }
        if (!upsertFromJson(fDD, "m_register", jregister)) {
            fDD.rollback();
            message_error(fDD.fLastError);
            return;
        }
    }

    if (!fDD.commit()) {
        message_error(fDD.fLastError);
        return;
    }
    TrackControl::insert(TRACK_VAUCHER, "Import voucher", primaryId, "", primaryId);
    apply(fReportGrid);
    message_info(tr("Voucher imported"));
}

void FVauchers::cancelation()
{
    QList<QVariant> out;
    if (fReportGrid->fillRowValuesOut(out) < 0) {
        message_info(tr("Nothing was selected"));
        return;
    }
    if (message_confirm(tr("Confirm to remove selected voucher")) != QDialog::Accepted) {
        return;
    }
    QString reason = QInputDialog::getText(this, tr("Reason for remove"), tr("Reason"));
    if (reason.isEmpty()) {
        message_error(tr("Reason must be specified"));
        return;
    }
    removeVaucher(out.at(0).toString(), reason);
}

void FVauchers::openInvoice()
{
    QList<QVariant> out;
    if (fReportGrid->fillRowValuesOut(out) < 0) {
        message_info(tr("Nothing was selected"));
        return;
    }
    openVaucherInvoice(out.at(0).toString());
}

void FVauchers::reviveVaucher()
{
    QList<QVariant> out;
    if (fReportGrid->fillRowValuesOut(out) < 0) {
        message_info(tr("Nothing was selected"));
        return;
    }
    if (out.at(1).toString() != VAUCHER_ROOMING_N ||
            out.at(1).toString() != VAUCHER_POSTCHARGE_N ||
            out.at(1).toString() != VAUCHER_RECEIPT_N) {
        message_error(tr("The vachers of this type cannot be revived"));
        return;
    }
    if (message_confirm(tr("Confirm to revive the selected voucher")) != QDialog::Accepted) {
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_canceled"] = 0;
    fDD.update("m_register", where_id(ap(out.at(0).toString())));
    fTrackControl->insert("Revive voucher", out.at(0).toString(), "");
    message_info(tr("The voucher was recovered. Please, refresh report"));
}

void FVauchers::correctCLNames()
{
    if (message_confirm(tr("Confirm to correct city ledger names")) != QDialog::Accepted) {
        return;
    }

    //correctCL(fDb);

    message_info(tr("Done"));
}

void FVauchers::correctCLNamesBack()
{
    if (message_confirm(tr("Confirm to correct city ledger names to original")) != QDialog::Accepted) {
        return;
    }

    //correctCLBack(fDb);

    message_info(tr("Done"));
}

void FVauchers::editRawData()
{
    QList<QVariant> out;
    if (fReportGrid->fillRowValuesOut(out) < 0) {
        message_info(tr("Nothing was selected"));
        return;
    }
    WVaucherEditor::load(out.at(0).toString());
}

void FVauchers::edit()
{
    QList<QVariant> out;
    if (fReportGrid->fillRowValuesOut(out) < 0) {
        message_info(tr("Nothing was selected"));
        return;
    }
    openVaucher(out.at(1).toString(), out.at(0).toString());
}

void FVauchers::recover()
{

}

void FVauchers::printVaucher()
{
    QList<QVariant> out;
    if (fReportGrid->fillRowValuesOut(out) < 0) {
        message_info(tr("Nothing was selected"));
        return;
    }
    PPrintVaucher::printVaucher(out.at(0).toString());
}

void FVauchers::printVoucherAsInvoice()
{
    QList<QVariant> out;
    if (fReportGrid->fillRowValuesOut(out) < 0) {
        message_info(tr("Nothing was selected"));
        return;
    }
    QString ch, rv;
    if (out.at(1).toString() == VAUCHER_RECEIPT_N) {
        rv = out.at(0).toString();
    } else {
        ch = out.at(0).toString();
    }
    if (!out.at(29).toString().isEmpty()) {
        DoubleDatabase dd;
        dd[":f_invoice"] = out.at(29);
        dd.exec("select f_id from f_reservation where f_invoice=:f_invoice");
        if (dd.nextRow()) {
            openVaucherInvoice(out.at(0).toString());
            return;
        }
    }
    DlgPrintVoucherAsInvoice *p = DlgPrintVoucherAsInvoice::openInvoiceWindow(out.at(29).toString());
    if (out.at(29).toString().isEmpty()) {
        p->addVoucher(out.at(0).toString());
    }
}

void FVauchers::doubleClickOnRow(const QList<QVariant> &values)
{
    if (values.count() == 0) {
        message_info(tr("Nothing is selected"));
        return;
    }
    openVaucher(values.at(1).toString(), values.at(0).toString());
}

void FVauchers::on_chCanceled_clicked(bool checked)
{
    fBtnRevive->setEnabled(checked);
    apply(fReportGrid);
}

void FVauchers::on_toolButton_2_clicked()
{
    ui->deFrom->setDate(ui->deFrom->date().addDays(1));
    ui->deTo->setDate(ui->deTo->date().addDays(1));
    apply(fReportGrid);
}

void FVauchers::on_toolButton_clicked()
{
    ui->deFrom->setDate(ui->deFrom->date().addDays(-1));
    ui->deTo->setDate(ui->deTo->date().addDays(-1));
    apply(fReportGrid);
}

void FVauchers::tblMainDblClick(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    if (index.column() == 14) {
        DoubleDatabase dd;
        dd[":f_replyTaxCode"] = fReportGrid->fModel->data(index.row(), 14, Qt::EditRole).toInt();
        dd.exec("select * from airwick.tax_print where f_replyTaxCode=:f_replyTaxCode");
        if (dd.nextRow()) {
            DlgHDMViewer(fReportGrid->fModel->data(index.row(), 14, Qt::EditRole).toString(), dd.getString("f_queryjson"), this).exec();
        } else {
            message_error(tr("Invalid fiscal code"));
            return;
        }
    } else {
        openVaucher(fReportGrid->fModel->data(index.row(), 1, Qt::EditRole).toString(),
                    fReportGrid->fModel->data(index.row(), 0, Qt::EditRole).toString());
    }
}
