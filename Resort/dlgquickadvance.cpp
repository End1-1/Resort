#include "dlgquickadvance.h"
#include "ui_dlgquickadvance.h"
#include "dlgprinttaxsm.h"
#include "cacheinvoiceitem.h"
#include "dlgquickadvanceapply.h"
#include "paymentmode.h"
#include "cachecreditcard.h"
#include "utils.h"

DlgQuickAdvance::DlgQuickAdvance(QWidget *parent) :
    BaseWidget (parent),
    ui(new Ui::DlgQuickAdvance)
{
    ui->setupUi(this);
    ui->leCash->setValidator(new QDoubleValidator(0, 999999999, 2));
    ui->leCard->setValidator(new QDoubleValidator(0, 999999999, 2));
    ui->leQty->setValidator(new QIntValidator());
    ui->leCardType->setSelector(this, cache(cid_credit_card), ui->leCardTypeName);
    DoubleDatabase dd(true, false);
    dd.exec("select t.*, c.f_name as f_creditcardname "
            "from m_temp_advance t "
            "left join f_credit_card c on c.f_id=t.f_creditcard "
            "where t.f_applied=0 and t.f_canceled=0");
    while (dd.nextRow()) {
        int row = ui->tbl->addRow();
        ui->tbl->setItemWithValue(row, 0, dd.getInt("f_id"));
        ui->tbl->setItemWithValue(row, 1, dd.getDate("f_date").toString(def_date_format));
        ui->tbl->setItemWithValue(row, 2, dd.getTime("f_time").toString(def_time_format));
        ui->tbl->setItemWithValue(row, 3, dd.getString("f_operator"));
        ui->tbl->setItemWithValue(row, 4, dd.getInt("f_room"));
        ui->tbl->setItemWithValue(row, 5, float_str(dd.getDouble("f_amountcash"), 2));
        ui->tbl->setItemWithValue(row, 6, float_str(dd.getDouble("f_amountcard"), 2));
        ui->tbl->setItemWithValue(row, 7, dd.getInt("f_creditcard"));
        ui->tbl->setItemWithValue(row, 8, dd.getString("f_creditcardname"));
        ui->tbl->setItemWithValue(row, 9, dd.getInt("f_tax") == 0 ? "NO" : "YES");
        ui->tbl->addButton(row, 10, SLOT(cancelRow()), this, QIcon(":/images/cancel.png"));
        ui->tbl->addButton(row, 11, SLOT(applyRow()), this, QIcon(":/images/bedroom.png"));
        ui->tbl->setItemWithValue(row, 12, dd.getString("f_qty"));
    }
    countTotal();
    Utils::tableSetColumnWidths(ui->tbl, ui->tbl->columnCount(), 0, 100, 80, 150, 70, 80, 80, 0, 120, 50, 80, 80);
}

DlgQuickAdvance::~DlgQuickAdvance()
{
    delete ui;
}

void DlgQuickAdvance::setupTab()
{
    setupTabTextAndIcon(tr("Temporary receipts"), ":/images/hourglass.png");
}

void DlgQuickAdvance::cancelRow()
{
    QPushButton *b = static_cast<QPushButton*>(sender());
    int row, col;
    if (!ui->tbl->findWidgetCell(b, row, col)) {
        return;
    }
    if (message_confirm(tr("Confirm to remove selected receipt")) != QDialog::Accepted) {
        return;
    }
    DoubleDatabase dd(true, doubleDatabase);
    dd[":f_id"] = ui->tbl->toInt(row, 0);
    dd.exec("update m_temp_advance set f_canceled=1 where f_id=:f_id");
    TrackControl tc(TRACK_COMMON);
    tc.insert("New temporary receipt", QString("Room: %1, cash: %2, card: %3, tax: %4")
              .arg(ui->tbl->toString(row, 4))
              .arg(ui->tbl->toString(row, 5))
              .arg(ui->tbl->toString(row, 6))
              .arg(ui->tbl->toString(row, 7)), "");
    ui->tbl->removeRow(row);
    countTotal();
}

void DlgQuickAdvance::applyRow()
{
    QPushButton *b = static_cast<QPushButton*>(sender());
    int row, col;
    if (!ui->tbl->findWidgetCell(b, row, col)) {
        return;
    }
    if (message_confirm(tr("Confirm to apply selected receipt")) != QDialog::Accepted) {
        return;
    }
    double amount = ui->tbl->toDouble(row, 5) > 0.001 ? ui->tbl->toDouble(row, 5) : ui->tbl->toDouble(row, 6);
    int paymode = ui->tbl->toDouble(row, 5) > 0.001 ? PAYMENT_CASH : PAYMENT_CARD;
    if (!DlgQuickAdvanceApply::apply(ui->tbl->toInt(row, 4), amount, paymode, ui->tbl->toInt(row, 7), ui->tbl->toString(row, 9))) {
        return;
    }
    DoubleDatabase dd(true, doubleDatabase);
    dd[":f_id"] = ui->tbl->toInt(row, 0);
    dd.exec("update m_temp_advance set f_applied=1 where f_id=:f_id");
    TrackControl tc(TRACK_COMMON);
    tc.insert("Temporary receipt applied", QString("Room: %1, cash: %2, card: %3, tax: %4; cardname: %5")
              .arg(ui->tbl->toString(row, 4))
              .arg(ui->tbl->toString(row, 5))
              .arg(ui->tbl->toString(row, 6))
              .arg(ui->tbl->toString(row, 9))
              .arg(ui->tbl->toString(row, 8)), "");
    ui->tbl->removeRow(row);
    countTotal();
}

void DlgQuickAdvance::on_btnPrint_clicked()
{
    if (ui->leCard->asDouble() > 0.001) {
        if (ui->leCardType->asInt() == 0) {
            message_error(tr("Type of card is not selected"));
            return;
        }
    }
    if (ui->leQty->asInt() < 1) {
        message_error(tr("Quantiry cannot be equal to zero"));
        return;
    }
    int rm = fPreferences.getDb(def_room_charge_id).toInt();
    CacheInvoiceItem ii;
    if (!ii.get(rm)) {
        message_error(tr("No item for tax defined"));
        return;
    }
    DlgPrintTaxSM dpt(this);
    double price = ui->leCash->asDouble() > 0.001 ? ui->leCash->asDouble() : ui->leCard->asDouble();
    dpt.addGoods(ii.fVatDept(), ii.fAdgt(), ii.fCode(), ii.fTaxName(), price / ui->leQty->asInt(), ui->leQty->asInt());
    dpt.fOrder = "QADV";
    if (ui->leCard->asDouble() > 0.001) {
        dpt.fCashAmount = 0.0;
        dpt.fCardAmount = ui->leCard->asDouble();
    }
    dpt.fPrepaid = 0;
    int result = dpt.exec();
    if (result == TAX_OK) {
        appendRow("YES");
    }
}

void DlgQuickAdvance::on_btnJustAppend_clicked()
{
    if (ui->leCard->asDouble() > 0.001) {
        if (ui->leCardType->asInt() == 0) {
            message_error(tr("Type of card is not selected"));
            return;
        }
    }
    appendRow("NO");
}

void DlgQuickAdvance::appendRow(const QString &tax)
{
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    DoubleDatabase dd(true, doubleDatabase);
    dd[":f_date"] = date;
    dd[":f_time"] = time;
    dd[":f_operator"] = WORKING_USERNAME;
    dd[":f_room"] = ui->leRoom->asInt();
    dd[":f_amountcash"] = ui->leCash->asDouble();
    dd[":f_amountcard"] = ui->leCard->asDouble();
    dd[":f_creditcard"] = ui->leCardType->asInt();
    dd[":f_qty"] = ui->leQty->asInt();
    int row = ui->tbl->addRow();
    ui->tbl->setItemWithValue(row, 0, dd.insert("m_temp_advance"));
    ui->tbl->setItemWithValue(row, 1, date.toString(def_date_format));
    ui->tbl->setItemWithValue(row, 2, time.toString(def_time_format));
    ui->tbl->setItemWithValue(row, 3, WORKING_USERNAME);
    ui->tbl->setItemWithValue(row, 4, ui->leRoom->text());
    ui->tbl->setItemWithValue(row, 5, ui->leCash->text());
    ui->tbl->setItemWithValue(row, 6, ui->leCard->text());
    ui->tbl->setItemWithValue(row, 7, ui->leCardType->asInt());
    ui->tbl->setItemWithValue(row, 8, ui->leCardTypeName->text());
    ui->tbl->setItemWithValue(row, 9, tax);
    ui->tbl->addButton(row, 10, SLOT(cancelRow()), this, QIcon(":/images/cancel.png"));
    ui->tbl->addButton(row, 11, SLOT(applyRow()), this, QIcon(":/images/bedroom.png"));
    ui->tbl->setItemWithValue(row, 12, ui->leQty->asInt());
    ui->leRoom->clear();
    ui->leQty->clear();
    ui->leCash->clear();
    ui->leCard->clear();
    ui->leRoom->setFocus();
    ui->leCardType->clear();
    ui->leCardTypeName->clear();
    countTotal();
    TrackControl tc(TRACK_COMMON);
    tc.insert("New temporary receipt", QString("Room: %1, cash: %2, card: %3, tax: %4")
              .arg(ui->leRoom->text())
              .arg(ui->leCash->text())
              .arg(ui->leCard->text())
              .arg(tax), "");
}

void DlgQuickAdvance::countTotal()
{
    double card = 0, cash = 0;
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        cash += ui->tbl->toDouble(i, 5);
        card += ui->tbl->toDouble(i, 6);
    }
    ui->leTotalCard->setDouble(card);
    ui->leTotalCash->setDouble(cash);
    ui->leGrandTotal->setDouble(card + cash);
}

void DlgQuickAdvance::on_leCard_textChanged(const QString &arg1)
{
    if (arg1.toDouble() > 0.001) {
        ui->leCash->clear();
        ui->leCardType->setEnabled(true);
        ui->leCardTypeName->setEnabled(true);
    } else {
        ui->leCardType->setEnabled(false);
        ui->leCardTypeName->setEnabled(false);
    }
}

void DlgQuickAdvance::on_leCash_textChanged(const QString &arg1)
{
    if (arg1.toDouble() > 0.001) {
        ui->leCard->clear();
        ui->leCardType->setEnabled(false);
        ui->leCardTypeName->setEnabled(false);
    }
}
