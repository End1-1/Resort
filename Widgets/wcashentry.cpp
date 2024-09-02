#include "wcashentry.h"
#include "ui_wcashentry.h"
#include "cachecashdoc.h"
#include "cachecashdesk.h"
#include "cacheinvoiceitem.h"
#include "cachecashdoc.h"
#include "cachestorepartners.h"

#define SEL_DEBIT 1
#define SEL_CREDIT 2
#define SEL_PARTNER 3
#define SEL_DOC_TYPE 4

WCashEntry::WCashEntry(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WCashEntry)
{
    ui->setupUi(this);
    ui->leDebit->setSelector(this, cache(cid_cash_desk), ui->leDebitName);
    ui->leCashout->setSelector(this, cache(cid_cash_desk), ui->leCashOutName);
    ui->leCredit->setSelector(this, cache(cid_invoice_item), ui->leCreditName);
    ui->lePartnerCode->setSelector(this, cache(cid_store_partners), ui->lePartnerName);
    ui->leDocTypeNum->setSelector(this, cache(cid_cash_doc), ui->leDocTypeName);
    on_chEnable_stateChanged(0);
    fIn = true;
}

WCashEntry::~WCashEntry()
{
    delete ui;
}

void WCashEntry::save()
{
    DoubleDatabase fDD;
    DoubleDatabase d2;
    d2.open();
    if (!ui->chEnable->isChecked()) {
        return;
    }
    QString err;
    if (!isCorrent(err)) {
        message_error(err);
        return;
    }
    if (ui->leCode->asInt() == 0) {
        fDD[":f_id"] = 0;
        ui->leCode->setInt(fDD.insert("c_cash"));
    }
    if (ui->rbCashIn->isChecked()) {
        fDD[":f_date"] = ui->deDate->date();
        fDD[":f_docType"] = ui->leDocTypeNum->asInt();
        fDD[":f_docNum"] = ui->leDocNum->asInt();
        fDD[":f_debit"] = ui->leDebit->asInt();
        fDD[":f_credit"] = ui->leCredit->asInt();
        fDD[":f_partner"] = ui->lePartnerCode->asInt();
        fDD[":f_amount"] = ui->leAmount->asDouble();
        fDD[":f_comment"] = ui->leComment->text();
        fDD.update("c_cash", where_id(ui->leCode->asInt()));
    } else if (ui->rbCashOut->isChecked()) {
        fDD[":f_date"] = ui->deDate->date();
        fDD[":f_docType"] = ui->leDocTypeNum->asInt();
        fDD[":f_docNum"] = ui->leDocNum->asInt();
        fDD[":f_debit"] = ui->leCashout->asInt();
        fDD[":f_credit"] = ui->leCredit->asInt();
        fDD[":f_partner"] = ui->lePartnerCode->asInt();
        fDD[":f_amount"] = ui->leAmount->asDouble() * -1;
        fDD[":f_comment"] = ui->leComment->text();
        fDD.update("c_cash", where_id(ui->leCode->asInt()));
    } else if (ui->rbCashMove->isChecked()) {
        if (ui->leDocNum->asInt() == 0) {
            d2[":f_id"] = 0;
            ui->leDocNum->setInt(d2.insert("c_cash"));
        }
        fDD[":f_date"] = ui->deDate->date();
        fDD[":f_docType"] = ui->leDocTypeNum->asInt();
        fDD[":f_docNum"] = ui->leDocNum->asInt();
        fDD[":f_debit"] = (fIn ? ui->leDebit->asInt() : ui->leCashout->asInt());
        fDD[":f_credit"] = ui->leCredit->asInt();
        fDD[":f_partner"] = ui->lePartnerCode->asInt();
        fDD[":f_amount"] = (fIn ? ui->leAmount->asDouble() : ui->leAmount->asDouble() * -1);
        fDD[":f_comment"] = ui->leComment->text();
        fDD.update("c_cash", where_id(ui->leCode->asInt()));
        fDD[":f_date"] = ui->deDate->date();
        fDD[":f_docType"] = ui->leDocTypeNum->asInt();
        fDD[":f_docNum"] = ui->leCode->asInt();
        fDD[":f_debit"] = (fIn ? ui->leCashout->asInt() : ui->leDebit->asInt());
        fDD[":f_credit"] = ui->leCredit->asInt();
        fDD[":f_partner"] = ui->lePartnerCode->asInt();
        fDD[":f_amount"] = (fIn ? ui->leAmount->asDouble() * -1 : ui->leAmount->asDouble());
        fDD[":f_comment"] = ui->leComment->text();
        fDD.update("c_cash", where_id(ui->leDocNum->asInt()));
    }
    message_info(tr("Saved"));
}

void WCashEntry::load(int doc)
{
    ui->wOp->setEnabled(false);
    ui->leCode->setInt(doc);
    DoubleDatabase fDD;
    fDD[":f_id"] = doc;
    fDD.exec("select * from c_cash where f_id=:f_id");
    if (fDD.rowCount() == 0) {
        message_error(tr("Invalid document number"));
        return;
    }
    if (fDD.getValue("f_docType").toInt() == CASHDOC_MOVE) {
        ui->rbCashMove->setChecked(true);
        cashOp(CASHOP_MOVE);
    } else {
        if (fDD.getValue("f_amount").toDouble() > 0.1) {
            ui->rbCashIn->setChecked(true);
            cashOp(CASHOP_IN);
        } else {
            ui->rbCashOut->setChecked(true);
            cashOp(CASHOP_OUT);
        }
    }
    ui->leDocTypeNum->setInitialValue(fDD.getValue("f_docType").toInt());
    ui->leDocNum->setInt(fDD.getValue("f_docNum").toInt());
    ui->deDate->setDate(fDD.getValue("f_date").toDate());
    ui->leAmount->setDouble(abs(fDD.getValue("f_amount").toDouble()));
    if (fDD.getValue("f_amount").toDouble() > 0.1) {
        ui->leDebit->setInitialValue(fDD.getValue("f_debit").toInt());
    } else {
        ui->leCashout->setInitialValue(fDD.getValue("f_debit").toInt());
    }
    ui->leCredit->setInitialValue(fDD.getValue("f_credit").toInt());
    ui->lePartnerCode->setInitialValue(fDD.getValue("f_partner").toInt());
    ui->leComment->setText(fDD.getValue("f_comment").toString());
    if (ui->rbCashMove->isChecked()) {
        if (ui->leAmount->asDouble() > 0.1) {
            fIn = true;
        } else {
            fIn = false;
        }
        fDD[":f_docType"] = CASHDOC_MOVE;
        fDD[":f_id"] = ui->leDocNum->asInt();
        fDD.exec("select f_debit from c_cash where f_id=:f_id and f_docType=:f_docType");
        if (fDD.rowCount() == 0) {
            message_error(tr("Error in cash movement document"));
            return;
        }
        if (fIn) {
            ui->leCashout->setInitialValue(fDD.getValue("f_debit").toInt());
        } else {
            ui->leDebit->setInitialValue(fDD.getValue("f_debit").toInt());
        }
    }
}

void WCashEntry::enable()
{
    ui->chEnable->setChecked(true);
}

void WCashEntry::disable()
{
    ui->chEnable->setChecked(false);
}

int WCashEntry::debit()
{
    return ui->leDebit->asInt();
}

int WCashEntry::credit()
{
    return ui->leCredit->asInt();
}

int WCashEntry::cashOp()
{
    if (ui->rbCashIn->isChecked()) {
        return CASHOP_IN;
    } else if (ui->rbCashOut->isChecked()) {
        return CASHOP_OUT;
    } else if (ui->rbCashMove->isChecked()) {
        return CASHOP_MOVE;
    } else {
        return CASHOP_NONE;
    }
}

void WCashEntry::cashOp(int c)
{
    switch (c) {
        case CASHOP_NONE:
            ui->rbCashIn->setChecked(false);
            ui->rbCashOut->setChecked(false);
            ui->rbCashMove->setChecked(false);
            ui->lbCashIn->setVisible(false);
            ui->leDebit->setVisible(false);
            ui->leDebitName->setVisible(false);
            ui->lbCachout->setVisible(false);
            ui->leCashout->setVisible(false);
            ui->leCashOutName->setVisible(false);
            break;
        case CASHOP_IN:
            ui->rbCashIn->setChecked(true);
            break;
        case CASHOP_OUT:
            ui->rbCashOut->setChecked(true);
            break;
        case CASHOP_MOVE:
            ui->rbCashMove->setChecked(true);
            ui->leDocTypeNum->setInt(CASHDOC_MOVE);
            break;
        default:
            break;
    }
    ui->lbCashIn->setVisible(c == CASHOP_IN || c == CASHOP_MOVE);
    ui->leDebit->setVisible(c == CASHOP_IN || c == CASHOP_MOVE);
    ui->leDebitName->setVisible(c == CASHOP_IN || c == CASHOP_MOVE);
    ui->lbCachout->setVisible(c == CASHOP_OUT || c == CASHOP_MOVE);
    ui->leCashout->setVisible(c == CASHOP_OUT || c == CASHOP_MOVE);
    ui->leCashOutName->setVisible(c == CASHOP_OUT || c == CASHOP_MOVE);
}

QString WCashEntry::comment()
{
    return ui->leComment->text();
}

void WCashEntry::comment(const QString &c)
{
    ui->leComment->setText(c);
}

QDate WCashEntry::date()
{
    return ui->deDate->date();
}

void WCashEntry::date(const QDate &date)
{
    ui->deDate->setDate(date);
}

double WCashEntry::amount()
{
    return ui->leAmount->asDouble();
}

void WCashEntry::amount(double a)
{
    ui->leAmount->setDouble(a);
}

void WCashEntry::docType(int t)
{
    ui->leDocTypeNum->setInitialValue(t);
    switch (t) {
        case CASHDOC_DEBT:
            ui->rbCashOut->setChecked(true);
            cashOp(CASHOP_OUT);
    }
}

void WCashEntry::docNum(int n)
{
    ui->leDocNum->setInt(n);
}

int WCashEntry::partner()
{
    return ui->lePartnerCode->asInt();
}

void WCashEntry::partner(int p)
{
    ui->lePartnerCode->setInitialValue(p);
}

bool WCashEntry::isCorrent(QString &errors)
{
    if (!ui->chEnable->isChecked()) {
        return true;
    }
    errors.clear();
    if (!cashOp()) {
        errors += tr("Cash operation is not defined") + "<br>";
    }
    if (ui->rbCashIn->isChecked() || ui->rbCashMove->isChecked()) {
        if (ui->leDebit->asInt() == 0) {
            errors += tr("Cash in is not defined") + "<br>";
        }
    }
    if (ui->rbCashOut->isChecked() || ui->rbCashMove->isChecked()) {
        if (ui->leCredit->asInt() == 0) {
            errors += tr("Purpose is not defined") + "<br>";
        }
    }
    if (ui->leDocTypeNum->asInt() == 0) {
        errors += tr("Document type was not selected") + "<br>";
    }
    if (ui->leAmount->asDouble() < 0.1) {
        errors += tr("Amount must be greater than 0") + "<br>";
    }
    return errors.isEmpty();
}

void WCashEntry::setSaveVisible(bool v)
{
    ui->wOK->setVisible(v);
}

void WCashEntry::on_btnCancel_clicked()
{
    emit rejected();
}

void WCashEntry::on_btnSave_clicked()
{
    emit accepted();
}

void WCashEntry::on_chEnable_stateChanged(int arg1)
{
    //    ui->leCode->setEnabled(ui->leCode->isEnabled() && arg1);
    //    ui->leDocTypeNum->setEnabled(ui->leDocTypeNum->isEnabled() && arg1);
    //    ui->deDate->setEnabled(ui->deDate->isEnabled() && arg1);
    //    ui->leAmount->setEnabled(ui->leAmount->isEnabled() && arg1);
    //    ui->leDebit->setEnabled(ui->leDebit->isEnabled() && arg1);
    //    ui->leCredit->setEnabled(ui->leCredit->isEnabled() && arg1);
    //    ui->lePartnerCode->setEnabled(ui->lePartnerCode->isEnabled() && arg1);
    //    ui->leComment->setEnabled(ui->leComment->isEnabled() && arg1);
    ui->leCode->setEnabled(arg1);
    ui->leDocTypeNum->setEnabled(arg1);
    ui->deDate->setEnabled(arg1);
    ui->leAmount->setEnabled(arg1);
    ui->leDebit->setEnabled(arg1);
    ui->leCredit->setEnabled(arg1);
    ui->lePartnerCode->setEnabled(arg1);
    ui->leComment->setEnabled(arg1);
}

void WCashEntry::on_chEnable_clicked(bool checked)
{
    on_chEnable_stateChanged(checked);
}

void WCashEntry::on_rbCashIn_clicked()
{
    cashOp(CASHOP_IN);
}

void WCashEntry::on_rbCashOut_clicked()
{
    cashOp(CASHOP_OUT);
}

void WCashEntry::on_rbCashMove_clicked()
{
    cashOp(CASHOP_MOVE);
}
