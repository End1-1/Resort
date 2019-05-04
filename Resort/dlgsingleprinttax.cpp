#include "dlgsingleprinttax.h"
#include "ui_dlgsingleprinttax.h"
#include "cacheinvoiceitem.h"
#include "paymentmode.h"
#include "message.h"
#include "dlgprinttaxsm.h"

DlgSinglePrintTax::DlgSinglePrintTax(QWidget *parent) :
    BaseDialog (parent),
    ui(new Ui::DlgSinglePrintTax)
{
    ui->setupUi(this);
    Utils::tableSetColumnWidths(ui->tbl, ui->tbl->columnCount(), 30, 50, 200, 200, 80, 80, 50, 100, 0, 0);
    int w = 40;
    for (int i = 0; i < ui->tbl->columnCount(); i++) {
        w += ui->tbl->columnWidth(i);
    }
    setMinimumWidth(w);
}

DlgSinglePrintTax::~DlgSinglePrintTax()
{
    delete ui;
}

void DlgSinglePrintTax::callback(int sel, const QString &code)
{
    sel--;
    CacheInvoiceItem c;
    if (c.get(code)) {
        ui->tbl->lineEdit(sel, 3)->setText(c.fTaxName());
        ui->tbl->comboBox(sel, 5)->setCurrentText(c.fVatDept());
        ui->tbl->setItemWithValue(sel, 8, c.fAdgt());
    }
}


int DlgSinglePrintTax::addItem(const QString &itemCode, double amount, int modeOfPayment, const QString &voucher)
{
    int row = ui->tbl->addRow();
    ui->tbl->addCheckBox(row, 0)->setChecked(true);
    EQLineEdit *lname = ui->tbl->addLineEdit(row, 2, false);
    lname->setReadOnly(true);
    EQLineEdit *ltax = ui->tbl->addLineEdit(row, 3, false);
    ltax->setReadOnly(true);
    EQComboBox *cdept = ui->tbl->addComboBox(row, 5);
    cdept->addItem("1");
    cdept->addItem("2");
    cdept->addItem("3");
    cdept->setCurrentIndex(0);
    EQLineEdit *lcode = ui->tbl->addLineEdit(row, 1, false);
    lcode->setSelector(this, cache(cid_invoice_item), lname, row + 1);
    lcode->setInitialValue(itemCode);
    EQLineEdit *lqty = ui->tbl->addLineEdit(row, 4, false);
    lqty->setDouble(1);
    EQLineEdit *lamount = ui->tbl->addLineEdit(row, 6, false);
    lamount->setDouble(amount);
    EQComboBox *cmode = ui->tbl->addComboBox(row, 7);
    cmode->addItem(tr("Cash"));
    cmode->addItem(tr("Card"));
    cmode->addItem(tr("Prepaid"));
    switch (modeOfPayment) {
    case PAYMENT_CASH:
        cmode->setCurrentIndex(0);
        break;
    case PAYMENT_CARD:
        cmode->setCurrentIndex(1);
        break;
    case PAYMENT_ADVANCE:
        cmode->setCurrentIndex(2);
        break;
    }
    ui->tbl->setItemWithValue(row, 9, voucher);
    ui->tbl->setMinimumHeight((ui->tbl->rowCount() + 1) * ui->tbl->verticalHeader()->defaultSectionSize() + 5);
    ui->tbl->setMaximumHeight((ui->tbl->rowCount() + 1) * ui->tbl->verticalHeader()->defaultSectionSize() + 5);
    adjustSize();
    return row;
}

void DlgSinglePrintTax::on_btnClose_clicked()
{
    reject();
}

void DlgSinglePrintTax::on_btnPrint_clicked()
{
    double card = 0.0;
    double prepaid = 0.0;
    QSet<QString> errRows;
    QStringList rows;
    DlgPrintTaxSM *d = new DlgPrintTaxSM(this);
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        if (ui->tbl->checkBox(i, 0)->isChecked()) {
            if (ui->tbl->lineEdit(i, 1)->asInt() == 0) {
                errRows << QString::number(i);
                continue;
            }
            if (ui->tbl->lineEdit(i, 4)->asDouble() < 0.01) {
                errRows << QString::number(i);
                continue;
            }
            if (ui->tbl->lineEdit(i, 6)->asDouble() < 0.01) {
                errRows << QString::number(i);
                continue;
            }
            rows << QString::number(i);
            switch (ui->tbl->comboBox(i, 7)->currentIndex()) {
            case 0:
                break;
            case 1:
                card += ui->tbl->lineEdit(i, 6)->asDouble();
                break;
            case 2:
                prepaid += ui->tbl->lineEdit(i, 6)->asDouble();
                break;
            }
            d->addGoods(ui->tbl->comboBox(i, 5)->currentText(),
                        ui->tbl->itemValue(i, 8, Qt::EditRole).toString(),
                        ui->tbl->lineEdit(i, 1)->text(),
                        ui->tbl->lineEdit(i, 3)->text(),
                        ui->tbl->lineEdit(i, 6)->asDouble() / ui->tbl->lineEdit(i, 4)->asDouble(),
                        ui->tbl->lineEdit(i, 4)->asDouble());
        }
    }
    if (errRows.count() == 0) {
        d->fCardAmount = card;
        d->fPrepaid = prepaid;
        if (d->exec() == TAX_OK) {
            DoubleDatabase dd(true, doubleDatabase);
            foreach (QString r, rows) {
                dd[":f_fiscal"] = d->fTaxCode;
                dd[":f_id"] = ui->tbl->itemValue(r.toInt(), 9).toString();
                dd.exec("update m_register set f_fiscal=:f_fiscal where f_id=:f_id");
            }
            accept();
        }
    } else {
        QString err(tr("Next row contains mistake"));
        foreach (QString s, errRows) {
            err += s + "<br>";
        }
        message_error(err);
    }
    d->deleteLater();
}

