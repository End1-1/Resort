#include "dlgreservationdateprices.h"
#include "ui_dlgreservationdateprices.h"
#include "doubledatabase.h"
#include "utils.h"
#include "message.h"
#include "eqlineedit.h"

#include <QDoubleValidator>

QList<QDate> DlgReservationDatePrices::stayDates(const QDate &entry, const QDate &departure)
{
    QList<QDate> dates;
    if (!entry.isValid() || !departure.isValid() || entry > departure) {
        return dates;
    }
    if (entry == departure) {
        dates << entry;
        return dates;
    }
    for (QDate d = entry; d < departure; d = d.addDays(1)) {
        dates << d;
    }
    return dates;
}

DlgReservationDatePrices::DlgReservationDatePrices(const QString &reservationId,
                                                   const QDate &entry,
                                                   const QDate &departure,
                                                   double defaultPrice,
                                                   bool readOnly,
                                                   QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgReservationDatePrices),
    fReservationId(reservationId),
    fEntry(entry),
    fDeparture(departure),
    fDefaultPrice(defaultPrice),
    fReadOnly(readOnly)
{
    ui->setupUi(this);
    ui->lbEntry->setText(entry.toString(def_date_format));
    ui->lbDeparture->setText(departure.toString(def_date_format));
    fDates = stayDates(entry, departure);
    Utils::tableSetColumnWidths(ui->tblData, ui->tblData->columnCount(), 120, 120);
    buildTable();
    if (fReadOnly) {
        applyReadOnly();
    }
}

DlgReservationDatePrices::~DlgReservationDatePrices()
{
    delete ui;
}

bool DlgReservationDatePrices::edit(const QString &reservationId,
                                    const QDate &entry,
                                    const QDate &departure,
                                    double defaultPrice,
                                    double &roomTotal,
                                    QWidget *parent)
{
    DlgReservationDatePrices d(reservationId, entry, departure, defaultPrice, false, parent);
    if (d.exec() != QDialog::Accepted) {
        return false;
    }
    roomTotal = d.roomTotal();
    return true;
}

void DlgReservationDatePrices::view(const QString &reservationId,
                                    const QDate &entry,
                                    const QDate &departure,
                                    double defaultPrice,
                                    QWidget *parent)
{
    DlgReservationDatePrices d(reservationId, entry, departure, defaultPrice, true, parent);
    d.exec();
}

double DlgReservationDatePrices::roomTotal() const
{
    double total = 0;
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        EQLineEdit *le = ui->tblData->lineEdit(i, 1);
        if (le) {
            total += le->asDouble();
        }
    }
    return total;
}

void DlgReservationDatePrices::applyReadOnly()
{
    setWindowTitle(tr("Daily room prices (view)"));
    ui->btnFillDefault->setVisible(false);
    ui->btnOk->setVisible(false);
    ui->btnCancel->setText(tr("Close"));
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        EQLineEdit *le = ui->tblData->lineEdit(i, 1);
        if (le) {
            le->setReadOnly(true);
        }
    }
}

void DlgReservationDatePrices::buildTable()
{
    ui->tblData->setRowCount(fDates.count());

    QMap<QDate, double> savedPrices;
    if (!fReservationId.isEmpty()) {
        DoubleDatabase fDD;
        fDD[":f_reservation"] = fReservationId;
        fDD.exec("select f_date, f_price from f_reservation_prices "
                 "where f_reservation=:f_reservation order by f_date");
        while (fDD.nextRow()) {
            savedPrices[fDD.getDate(0)] = fDD.getDouble(1);
        }
    }

    for (int i = 0; i < fDates.count(); i++) {
        const QDate &d = fDates.at(i);
        ui->tblData->setItem(i, 0, new C5TableWidgetItem(d.toString(def_date_format)));
        ui->tblData->item(i, 0)->setFlags(ui->tblData->item(i, 0)->flags() & ~Qt::ItemIsEditable);
        ui->tblData->item(i, 0)->setData(Qt::UserRole, d);

        double price = savedPrices.contains(d) ? savedPrices.value(d) : fDefaultPrice;
        EQLineEdit *le = ui->tblData->addLineEdit(i, 1, false);
        QDoubleValidator *dv = new QDoubleValidator(0, 999999999, 2);
        dv->setNotation(QDoubleValidator::StandardNotation);
        dv->setLocale(appNumberLocale());
        le->setValidator(dv);
        le->setDouble(price);
        connect(le, SIGNAL(textChanged(QString)), this, SLOT(updateTotal()));
    }

    updateTotal();
}

void DlgReservationDatePrices::updateTotal()
{
    ui->lbTotal->setText(float_str(roomTotal(), 2));
}

void DlgReservationDatePrices::on_btnFillDefault_clicked()
{
    if (fReadOnly) {
        return;
    }
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        EQLineEdit *le = ui->tblData->lineEdit(i, 1);
        if (le) {
            le->setDouble(fDefaultPrice);
        }
    }
    updateTotal();
}

bool DlgReservationDatePrices::save()
{
    DoubleDatabase fDD;
    fDD.startTransaction();
    fDD[":f_reservation"] = fReservationId;
    if (!fDD.exec("delete from f_reservation_prices where f_reservation=:f_reservation")) {
        fDD.rollback();
        message_error(fDD.fLastError);
        return false;
    }

    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        EQLineEdit *le = ui->tblData->lineEdit(i, 1);
        if (!le) {
            continue;
        }
        fDD[":f_reservation"] = fReservationId;
        fDD[":f_date"] = ui->tblData->item(i, 0)->data(Qt::UserRole).toDate();
        fDD[":f_price"] = le->asDouble();
        if (!fDD.insert("f_reservation_prices", false)) {
            fDD.rollback();
            message_error(fDD.fLastError);
            return false;
        }
    }

    if (!fDD.commit()) {
        message_error(fDD.fLastError);
        return false;
    }
    return true;
}

void DlgReservationDatePrices::on_btnOk_clicked()
{
    if (fReadOnly) {
        accept();
        return;
    }
    if (fReservationId.isEmpty()) {
        message_error(tr("Reservation is not saved yet"));
        return;
    }
    if (ui->tblData->rowCount() == 0) {
        message_error(tr("No stay dates to save"));
        return;
    }
    if (!save()) {
        return;
    }
    accept();
}

void DlgReservationDatePrices::on_btnCancel_clicked()
{
    reject();
}
