#include "dlgprintrandomtax.h"
#include "ui_dlgprintrandomtax.h"
#include "dlgprinttaxsm.h"
#include "cacheinvoiceitem.h"
#include "cachevatmode.h"
#include <QDir>
#include <QFile>
#include <QProcess>

DlgPrintRandomTax::DlgPrintRandomTax(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgPrintRandomTax)
{
    ui->setupUi(this);
    Utils::tableSetColumnWidths(ui->tblData, ui->tblData->columnCount(),
                                0, 300, 100, 100, 100, 30, 0, 0, 0);

    ui->leItemCode->setSelector(this, cache(cid_invoice_item), ui->leItemName);
    ui->leVAT->setSelector(this, cache(cid_vat_mode), ui->leVAT);
}

DlgPrintRandomTax::~DlgPrintRandomTax()
{
    delete ui;
}

void DlgPrintRandomTax::setHeader(const QString &room, const QString &guest, const QString &invoice)
{
    ui->leRoom->setText(room);
    ui->leGuest->setText(guest);
    ui->leInvoice->setText(invoice);
    DoubleDatabase fDD;
    fDD[":f_invoice"] = invoice;
    fDD.exec("select f_vatMode from f_reservation where f_invoice=:f_invoice");
    if (fDD.nextRow()) {
        ui->leVAT->setInitialValue(fDD.getString(0));
    }
}

void DlgPrintRandomTax::countTotal()
{
    double total = 0;
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        total += ui->tblData->toDouble(i, 3);
    }
    ui->leTotal->setDouble(total);
    ui->leCash->setDouble(total);
    ui->leCard->setDouble(0);
    ui->lePrepaiment->setDouble(0);
}

void DlgPrintRandomTax::correctAmounts(EQLineEdit *l1, EQLineEdit *l2, EQLineEdit *l3)
{
    double total = ui->leTotal->asDouble();
    if (l1->asDouble() > total) {
        l1->setDouble(total);
        l2->setDouble(0);
        l3->setDouble(0);
    }
    l2->setDouble(total - l3->asDouble() - l1->asDouble());
    if (l2->asDouble() < 0) {
        l3->setDouble(l3->asDouble() + l2->asDouble());
        l2->setDouble(0);
    }
}

void DlgPrintRandomTax::on_btnAdd_clicked()
{
    if (ui->leItemCode->asInt() == 0) {
        return;
    }
    CacheInvoiceItem ii;
    if (!ii.get(ui->leItemCode->text())) {
        message_error(tr("Invalid item code"));
        return;
    }
    int qty = ui->leItemQty->asInt();
    double price = ui->leItemAmount->asDouble() / qty;
    for (int i = 0; i < qty; i++) {
        int row = ui->tblData->rowCount();
        ui->tblData->setRowCount(row + 1);
        int col = 0;
        ui->tblData->setItem(row, col++, Utils::tableItem(ui->leItemCode->text()));
        ui->tblData->setItem(row, col++, Utils::tableItem(ui->leItemName->text()));
        ui->tblData->setItem(row, col++, Utils::tableItem("1"));
        ui->tblData->setItem(row, col++, Utils::tableItem(price, 2));
        ui->tblData->setItem(row, col++, Utils::tableItem(price, 2));
        ui->tblData->addButton(row, col++, SLOT(btnClickWithTag(int)), this, QIcon(":/images/garbage.png"));
        ui->tblData->setItem(row, col++, Utils::tableItem(ii.fAdgt()));
        ui->tblData->setItem(row, col++, Utils::tableItem(0));
        ui->tblData->setItem(row, col++, Utils::tableItem(ii.fVaucher()));
    }
    ui->leItemCode->clear();
    ui->leItemName->clear();
    ui->leItemQty->setText("1");
    ui->leItemAmount->clear();
    countTotal();
    ui->leItemCode->setFocus();
}

void DlgPrintRandomTax::btnClickWithTag(int tag)
{
    tag = -1;
    EPushButton *src = static_cast<EPushButton*>(sender());
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        EPushButton *btn = static_cast<EPushButton*>(ui->tblData->cellWidget(i, 5));
        if (btn == src) {
            tag = i;
            break;
        }
    }
    if (tag < 0) {
        return;
    }
    DoubleDatabase fDD;
    if (ui->tblData->toInt(tag, 7) > 0) {
        fDD[":f_id"] = ui->tblData->toInt(tag, 7);
        fDD.exec("delete from m_free_tax where f_id=:f_id");
    }
    ui->tblData->removeRow(tag);
    countTotal();
}

void DlgPrintRandomTax::on_leCash_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1)
    correctAmounts(ui->leCash, ui->leCard, ui->lePrepaiment);
}

void DlgPrintRandomTax::on_btnPrint_clicked()
{
    if (ui->tblData->rowCount() == 0) {
        message_error(tr("Nothing to print"));
        return;
    }
    DlgPrintTaxSM dpt(fPreferences.getDb(def_default_fiscal_machine).toInt(), this);
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        CacheInvoiceItem ii;
        ii.get(ui->tblData->toString(i, 0));
        dpt.addGoods((ui->leVAT->fHiddenText.toInt() == VAT_INCLUDED ? ii.fVatDept() : ii.fNoVatDept()),
                     ii.fAdgt(),
                     ii.fCode(),
                     ii.fTaxName(),
                     ui->tblData->toDouble(i, 3),
                     ui->tblData->toDouble(i, 2));

    }
    dpt.fOrder = ui->leInvoice->text();
    dpt.fCardAmount = ui->leCard->asDouble();
    dpt.fPrepaid = ui->lePrepaiment->asDouble();
    DoubleDatabase fDD;
    int result = dpt.exec();
    if (result == TAX_OK) {
        for (int i = 0; i < ui->tblData->rowCount(); i++) {
//            if (ui->tblData->item(i, 4)->checkState() != Qt::Checked) {
//                continue;
//            }
//            fDD[":f_fiscal"] = dpt.fTaxCode;
//            fDD.update("m_register", fDD, ap(ui->tblData->toString(i, 8)));

            fDD[":f_invoice"] = ui->leInvoice->text();
            fDD[":f_item"] = ui->tblData->toInt(i, 0);
            fDD[":f_amount"] = ui->tblData->toDouble(i, 4);
            fDD[":f_user"] = WORKING_USERID;
            fDD[":f_date"] = QDateTime::currentDateTime();
            fDD[":f_source"] = ui->tblData->toString(i, 8);
            fDD[":f_taxCode"] = dpt.fTaxCode;
            ui->tblData->setItem(i, 7, Utils::tableItem(fDD.insert("m_free_tax")));
        }
        accept();
    }
}

void DlgPrintRandomTax::on_leCard_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1)
    correctAmounts(ui->leCard, ui->leCash, ui->lePrepaiment);
}

void DlgPrintRandomTax::on_btnRetryPrint_clicked()
{
    QDir d;
    QString fileName = QString("tax_%1.json").arg(ui->leInvoice->text());
    QFile f(d.currentPath() + "/" + fileName);
    if (f.exists()) {
        QStringList args;
        args << fPreferences.getDb(def_tax_address).toString()
             << fPreferences.getDb(def_tax_port).toString()
             << fPreferences.getDb(def_tax_password).toString()
             << fileName;
        QProcess *p = new QProcess();
        p->start(d.currentPath() + "/printtax.exe", args);
    } else {
        on_btnPrint_clicked();
    }
}

void DlgPrintRandomTax::on_lePrepaiment_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1)
    correctAmounts(ui->lePrepaiment, ui->leCash, ui->leCard);
}

void DlgPrintRandomTax::on_leItemQty_textEdited(const QString &arg1)
{
    if (arg1.toInt() > 100) {
        ui->leItemQty->setText("100");
    }
}
