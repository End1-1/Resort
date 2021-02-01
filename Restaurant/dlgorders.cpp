#include "dlgorders.h"
#include "ui_dlgorders.h"
#include "rmessage.h"
#include "printtax.h"
#include "hall.h"
#include "cacherights.h"
#include "cacheinvoiceitem.h"
#include "dlgprinttax.h"
#include "paymentmode.h"
#include <QScrollBar>
#include <QInputDialog>

DlgOrders::DlgOrders(int staff, QWidget *parent) :
    BaseExtendedDialogR(parent),
    ui(new Ui::DlgOrders)
{
    ui->setupUi(this);
    //ui->btnByNumber->setVisible(r__(cr__super_correction));
    fStaffId = staff;
    Utils::tableSetColumnWidths(ui->tblData, ui->tblData->columnCount(),
                                100, 200, 100, 400, 100, 50, 0);
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_dateCash"] = WORKING_DATE;
    fDD[":f_state"] = ORDER_STATE_CLOSED;
    fDD.exec("select oh.f_id, h.f_name, t.f_name, concat(u.f_firstName, ' ', u.f_lastName),"
               "oh.f_total, oh.f_tax, oh.f_paymentMode, '' "
               "from o_header oh "
               "left join r_hall h on h.f_id=oh.f_hall "
               "left join r_table t on t.f_id=oh.f_table "
               "left join users u on u.f_id=oh.f_staff "
               "where oh.f_dateCash=:f_dateCash and oh.f_state=:f_state");
    Utils::fillTableWithData(ui->tblData, fDD.fDbRows);
    showFullScreen();
}

DlgOrders::~DlgOrders()
{
    delete ui;
}

void DlgOrders::on_btnPrintTax_clicked()
{
    int row = ui->tblData->currentRow();
    if (row < 0) {
        message_error(tr("Nothing is selected"));
        return;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_id"] = ui->tblData->item(row, 0)->data(Qt::EditRole).toString();
    fDD.exec("select f_hall, f_paymentMode, f_total from o_header where f_id=:f_id");
    fDD.nextRow();
    QString vatDept = Hall::fHallMap[fDD.getValue("f_hall").toInt()]->fVatDept;

    QString taxpayer;
    taxpayer = QInputDialog::getText(this, tr("Enter taxpayer pin"), tr("Taxpayer pin"));

    int taxCode = 0;
    int result = DlgPrintTax::printTax(vatDept, ui->tblData->item(row, 0)->data(Qt::EditRole).toString(),
                                       (PAYMENT_CASH == fDD.getValue("f_paymentMode").toInt() ? 0 : fDD.getValue("f_total").toDouble()), taxCode, taxpayer);
    if (result != TAX_OK) {
        return;
    }

}

void DlgOrders::on_btnCancel_clicked()
{
    reject();
}

void DlgOrders::on_btnDown_clicked()
{
    ui->tblData->verticalScrollBar()->setValue(ui->tblData->verticalScrollBar()->value() + 6);
}

void DlgOrders::on_btnUp_clicked()
{
    ui->tblData->verticalScrollBar()->setValue(ui->tblData->verticalScrollBar()->value() - 6);
}

void DlgOrders::on_btnByNumber_clicked()
{
    QString num;
    num = QInputDialog::getText(this, tr("Enter number"), tr("Order id"));
    if (num.isEmpty()) {
        return;
    }
    num = num.toUpper();
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_state"] = ORDER_STATE_CLOSED;
    fDD[":f_id"] = num;
    fDD.exec("select oh.f_id, h.f_name, t.f_name, concat(u.f_firstName, ' ', u.f_lastName),"
               "oh.f_total, oh.f_tax, oh.f_paymentMode, '' "
               "from o_header oh "
               "left join r_hall h on h.f_id=oh.f_hall "
               "left join r_table t on t.f_id=oh.f_table "
               "left join users u on u.f_id=oh.f_staff "
               "where oh.f_id=:f_id and oh.f_state=:f_state ");
    Utils::fillTableWithData(ui->tblData, fDD.fDbRows);
}
