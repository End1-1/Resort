#include "dlgquickadvanceaction.h"
#include "ui_dlgquickadvanceaction.h"
#include "utils.h"
#include "message.h"
#include "cacheinvoiceitem.h"
#include "cachetaxmap.h"
#include "dlgprinttaxsm.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

DlgQuickAdvanceAction::DlgQuickAdvanceAction(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgQuickAdvanceAction)
{
    ui->setupUi(this);
    Utils::tableSetColumnWidths(ui->tbl, ui->tbl->columnCount(), 50, 250, 100, 50, 80, 80, 80, 30);
    ui->leItemCode->setSelector(this, cache(cid_invoice_item), ui->leItemName, hint_item);
}

DlgQuickAdvanceAction::~DlgQuickAdvanceAction()
{
    delete ui;
}

void DlgQuickAdvanceAction::callback(int sel, const QString &code)
{
    switch (sel) {
    case hint_item: {
        CacheInvoiceItem ci;
        if (ci.get(code)) {
            CacheTaxMap ct;
            if (ct.get(code)) {
                ui->leItemName->setText(ci.fTaxName());
                ui->leAdg->setText(ci.fAdgt());
                ui->leDep->setText(ct.fName());
                ui->leQty->setText("1");
                ui->lePrice->setFocus();
            }
        }
    }
    }
}

void DlgQuickAdvanceAction::setJson(int taxCode, const QString &json, const QString &remarks)
{
    QJsonDocument jdoc = QJsonDocument::fromJson(json.toUtf8());
    QJsonObject jobj = jdoc.object();
    if (jobj["mode"].toInt() == 3) {
        ui->leaCash->setDouble(jobj["paidAmount"].toDouble());
        ui->leaCard->setDouble(jobj["paidAmountCard"].toDouble());
        ui->tabWidget->removeTab(0);
    } else {
        ui->leGrandCash->setDouble(jobj["paidAmount"].toDouble());
        ui->leGrandTotal->setDouble(jobj["paidAmountCard"].toDouble());
        ui->leGrandCash->setReadOnly(true);
        ui->leGrandCard->setReadOnly(true);
        ui->leGrandTotal->setDouble(ui->leGrandCard->getDouble() + ui->leGrandCash->getDouble());
        ui->btnPrint->setEnabled(false);
        ui->leItemCode->clearSelector();
        ui->btnPlus->setEnabled(false);
        QJsonArray jarr = jobj["items"].toArray();
        for (int i = 0; i < jarr.count(); i++) {
            QJsonObject item = jarr.at(i).toObject();
            int row = ui->tbl->addRow();
            ui->tbl->setItemWithValue(row, 0, item["productCode"].toString());
            ui->tbl->setItemWithValue(row, 1, item["productName"].toString());
            ui->tbl->setItemWithValue(row, 2, item["adgCode"].toString());
            ui->tbl->setItemWithValue(row, 3, item["dep"].toString());
            ui->tbl->setItemWithValue(row, 4, item["qty"].toDouble());
            ui->tbl->setItemWithValue(row, 5, item["price"].toDouble());
            ui->tbl->setItemWithValue(row, 6, item["totalPrice"].toDouble());
        }
        ui->tabWidget->removeTab(1);
    }
    ui->leTaxNumber->setInt(taxCode);
    ui->ptComment->setPlainText(remarks);
}

int DlgQuickAdvanceAction::taxNumber()
{
    return ui->leTaxNumber->asInt();
}

double DlgQuickAdvanceAction::cash()
{
    if (ui->tabWidget->currentIndex() == 0) {
        return ui->leGrandCash->getDouble();
    } else {
        return ui->leaCash->getDouble();
    }
}

double DlgQuickAdvanceAction::card()
{
    if (ui->tabWidget->currentIndex() == 0) {
        return ui->leGrandCard->getDouble();
    } else {
        return ui->leaCard->getDouble();
    }
}

QString DlgQuickAdvanceAction::type()
{
    return ui->tabWidget->currentIndex() == 0 ? "Receipt" : "Advance";
}

QString DlgQuickAdvanceAction::remarks()
{
    return ui->ptComment->toPlainText();
}

void DlgQuickAdvanceAction::removeRow()
{
    QPushButton *b = static_cast<QPushButton*>(sender());
    int row, col;
    ui->tbl->findWidgetCell(b, row, col);
    if (row < 0) {
        return;
    }
    ui->tbl->removeRow(row);
    countTotal();
}
void DlgQuickAdvanceAction::on_btnPlus_clicked()
{
    if (ui->leItemCode->isEmpty()) {
        return;
    }
    if (ui->leTotal->getDouble() < 0.001) {
        message_error(tr("Check the parametrs"));
        return;
    }
    int row = ui->tbl->addRow();
    ui->tbl->setItemWithValue(row, 0, ui->leItemCode->text());
    ui->tbl->setItemWithValue(row, 1, ui->leItemName->text());
    ui->tbl->setItemWithValue(row, 2, ui->leAdg->text());
    ui->tbl->setItemWithValue(row, 3, ui->leDep->text());
    ui->tbl->setItemWithValue(row, 4, ui->leQty->getDouble());
    ui->tbl->setItemWithValue(row, 5, ui->lePrice->getDouble());
    ui->tbl->setItemWithValue(row, 6, ui->leTotal->getDouble());
    ui->tbl->addButton(row, 7, SLOT(removeRow()), this, QIcon(":/images/cancel.png"));
    ui->leItemCode->clear();
    ui->leItemName->clear();
    ui->leAdg->clear();
    ui->leDep->clear();
    ui->leQty->setText("1");
    ui->lePrice->clear();
    ui->leTotal->clear();
    countTotal();
}

void DlgQuickAdvanceAction::on_leQty_textEdited(const QString &arg1)
{
     ui->leTotal->setDouble(ui->lePrice->getDouble() * arg1.toDouble());
}

void DlgQuickAdvanceAction::on_lePrice_textEdited(const QString &arg1)
{
     ui->leTotal->setDouble(ui->leQty->getDouble() * arg1.toDouble());
}

void DlgQuickAdvanceAction::on_leTotal_textEdited(const QString &arg1)
{
    if (ui->leQty->getDouble() > 0.001) {
        ui->lePrice->setDouble(arg1.toDouble() / ui->leQty->getDouble());
    } else {
        ui->lePrice->setDouble(0);
    }
}

void DlgQuickAdvanceAction::on_btnPrint_clicked()
{
    if (ui->tabWidget->currentIndex() == 0) {
        if (ui->tbl->rowCount() == 0) {
            return;
        }
        QSet<int> taxs;
        for (int i = 0; i < ui->tbl->rowCount(); i++) {
            CacheInvoiceItem c;
            if (!c.get(ui->tbl->toString(i, 0))) {
                message_error(tr("Error in tax print. c == 0, case 1."));
                continue;
            }
            CacheTaxMap ci;
            if (!ci.get(c.fCode())) {
                message_error(tr("Tax department undefined for ") + c.fName());
                return;
            }
            taxs.insert(ci.fTax());
        }
        if (taxs.count() == 0) {
            message_error(tr("No fiscal machines"));
            return;
        }
        if (taxs.count() > 1) {
            message_error(tr("Cannot mix fiscal machines here"));
            return;
        }
        DlgPrintTaxSM *d = new DlgPrintTaxSM(taxs.values().at(0), this);
        for (int i = 0; i < ui->tbl->rowCount(); i++) {
            d->addGoods(ui->tbl->toString(i, 3),
                        ui->tbl->toString(i, 2),
                        ui->tbl->toString(i, 0),
                        ui->tbl->toString(i, 1),
                        ui->tbl->toDouble(i, 5),
                        ui->tbl->toDouble(i, 4));
        }
        d->fCashAmount = ui->leGrandCash->getDouble();
        d->fCardAmount = ui->leGrandCard->getDouble();
        if (d->exec() == TAX_OK) {
            ui->tabWidget->removeTab(1);
            for (int i = 0; i < ui->tbl->rowCount(); i++) {
                ui->tbl->removeCellWidget(i, 7);
            }
            fJson = d->fJson;
            ui->leTaxNumber->setInt(d->fTaxCode);
            ui->btnPrint->setEnabled(false);
        }
        delete d;
    } else {
        int taxCode;
        CacheInvoiceItem ci;
        if (!ci.get(fPreferences.getDb(def_advance_voucher_id).toInt())) {
            message_error(tr("Error in tax print. c == 0, case 1."));
            return;
        }
        CacheTaxMap cm;
        if (!cm.get(ci.fCode())) {
            message_error(tr("Tax department undefined for ") + ci.fName());
            return;
        }
        if (!DlgPrintTaxSM::printAdvance(cm.fTax(), ui->leaCash->getDouble(), ui->leaCard->getDouble(), "TEMP", "TEMP", taxCode, fJson)) {
            return;
        }
        ui->tabWidget->removeTab(0);
        ui->leTaxNumber->setInt(taxCode);
    }
}

void DlgQuickAdvanceAction::countTotal()
{
    double total = 0;
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        total += ui->tbl->toDouble(i, 6);
    }
    ui->leGrandTotal->setDouble(total);
    ui->leGrandCash->setDouble(total);
    ui->leGrandCard->setDouble(0);
}

void DlgQuickAdvanceAction::on_leGrandCash_textEdited(const QString &arg1)
{
    double v = arg1.toDouble();
    if (arg1.toDouble() > ui->leGrandTotal->getDouble()) {
        v = ui->leGrandTotal->getDouble();
        ui->leGrandCash->setDouble(v);
    }
    ui->leGrandCard->setDouble(ui->leGrandTotal->getDouble() - v);
}

void DlgQuickAdvanceAction::on_leGrandCard_textEdited(const QString &arg1)
{
    double v = arg1.toDouble();
    if (arg1.toDouble() > ui->leGrandTotal->getDouble()) {
        v = ui->leGrandTotal->getDouble();
        ui->leGrandCard->setDouble(v);
    }
    ui->leGrandCash->setDouble(ui->leGrandTotal->getDouble() - v);
}
