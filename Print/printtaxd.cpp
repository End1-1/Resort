#include "printtaxd.h"
#include "ui_printtaxd.h"
#include <QFile>
#include <QDir>
#include <QProcess>
#include "paymentmode.h"
#include "dlgprinttaxsm.h"

PrintTaxD::PrintTaxD(int taxid, QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::PrintTaxD)
{
    ui->setupUi(this);
    ui->chCheckUncheckAll->setChecked(true);
    fTaxCode = 0;
    fTaxID = taxid;
}

PrintTaxD::~PrintTaxD()
{
    delete ui;
}

void PrintTaxD::setPrepaid(const QString &amount)
{
    ui->leAvailablePrepaid->setText(amount);
}

void PrintTaxD::build()
{
    QSet<QString> depts;
    ui->tblData->clearContents();
    Utils::tableSetColumnWidths(ui->tblData, ui->tblData->columnCount(),
                                     0, 0, 200, 100, 30, 0, 0, 70, 100);
    ui->tblData->setRowCount(fRecList.count());
    for (int i = 0; i < fRecList.count(); i++) {
        depts << fDept.at(i);
        ui->tblData->setItem(i, 0, new C5TableWidgetItem(fRecList.at(i)));
        ui->tblData->setItem(i, 1, new C5TableWidgetItem(fCodeList.at(i)));
        ui->tblData->setItem(i, 2, new C5TableWidgetItem(fNameList.at(i)));
        ui->tblData->setItem(i, 3, new C5TableWidgetItem(fPriceList.at(i)));
        ui->tblData->setItem(i, 4, new C5TableWidgetItem());
        ui->tblData->setItemChecked(i, 4, true);
        ui->tblData->setItem(i, 5, new C5TableWidgetItem(fAdgCode.at(i)));
        ui->tblData->setItem(i, 6, new C5TableWidgetItem(fTaxNameList.at(i)));
        ui->tblData->setItem(i, 7, new C5TableWidgetItem(fQtyList.at(i)));
        ui->tblData->setItem(i, 8, new C5TableWidgetItem(QString::number(fQtyList.at(i).toDouble() * fPriceList.at(i).toDouble())));
    }
    countAmount();
    int col = 0;
    foreach (QString s, depts) {
        ui->tblFilter->setItem(0, col++, new C5TableWidgetItem(s));
    }
}

void PrintTaxD::on_btnCancel_clicked()
{
    reject();
}

bool PrintTaxD::print()
{
    QSet<QString> depts;
    for (int i = 0; i <  ui->tblData->rowCount(); i++) {
        if (ui->tblData->item(i, 4)->checkState() != Qt::Checked) {
            continue;
        }
        if (ui->tblData->item(i, 4)->checkState() != Qt::Checked) {
            continue;
        }
        depts << fDept.at(i);
    }
    DlgPrintTaxSM dpt(fTaxID, this);
    for (int i = 0; i < fCodeList.count(); i++) {
        if (ui->tblData->item(i, 4)->checkState() != Qt::Checked) {
            continue;
        }
        dpt.addGoods(fDept.at(i),
                     fAdgCode.at(i),
                     fCodeList.at(i),
                     fTaxNameList.at(i),
                     fPriceList.at(i).toDouble(),
                     fQtyList.at(i).toDouble());
    }
    dpt.fOrder = fInvoice;
    dpt.fCardAmount = fAmountCard.toDouble();
    dpt.fPrepaid = fAmountPre.toDouble();

    int result = dpt.exec();
    TrackControl::insert(2, "Print fiscal", dpt.fTaxCode, QString::number(result), "", fInvoice);
    if (result == TAX_OK) {
        fTaxCode = dpt.fTaxCode;
        return true;
    }
    return false;
}

int PrintTaxD::exec2()
{
    connect(&fTimer, SIGNAL(timeout()), this, SLOT(timeout()));
    fTimer.start(1000);
    return exec();
}

void PrintTaxD::timeout()
{
    on_btnPrint_clicked();
}

void PrintTaxD::countAmount()
{
    double total = 0;
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        if (ui->tblData->itemChecked(i, 4)) {
            total += ui->tblData->toDouble(i, 3) * ui->tblData->toDouble(i, 7);
        }
    }
    ui->leTotal->setDouble(total);
    ui->leCash->setDouble(total);
    ui->leCard->setDouble(0);
    fAmountCard = QString::number(ui->leCard->asDouble());
    fAmountCash = QString::number(ui->leCash->asDouble());
    fAmountPre = QString::number(ui->lePre->asDouble());
    if (ui->leAvailablePrepaid->asDouble() > 0.1) {
        if (ui->leAvailablePrepaid->asDouble() >= ui->leTotal->asDouble()) {
            ui->lePre->setText(QString::number(ui->leTotal->asDouble()));
        } else {
            ui->lePre->setText(QString::number(ui->leAvailablePrepaid->asDouble()));
        }
        correctAmounts(ui->lePre, ui->leCash, ui->leCard);
    }
}

void PrintTaxD::filter()
{
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        ui->tblData->setRowHidden(i, false);
        if (fFilter.length()) {
            if (fDept.at(i) != fFilter) {
                ui->tblData->setRowHidden(i, true);
                ui->tblData->item(i, 4)->setCheckState(Qt::Unchecked);
                continue;
            }
        }
    }
    countAmount();
}

void PrintTaxD::on_btnPrint_clicked()
{
//    if (ui->leCash->asDouble() > 299000) {
//        message_error(tr("Stop! Think twice!"));
//        return;
//    }
    if (!print()) {
        return;
    }
    DoubleDatabase fDD;
    double pre = ui->lePre->asDouble();
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        if (!ui->tblData->itemChecked(i, 4)) {
            continue;
        }
        double usedPre = 0;
        if (pre > 0) {
            usedPre = fQtyList.at(i).toDouble() * fPriceList.at(i).toDouble();
            if (usedPre > pre) {
                usedPre = pre;
            }
            pre -= usedPre;
        }

        fDD[":f_fiscal"] = fTaxCode;
        fDD[":f_fiscaldate"] = QDate::currentDate();
        fDD[":f_fiscaltime"] = QTime::currentTime();
        fDD[":f_usedPrepaid"] = usedPre;
        fDD.update("m_register", where_id(ap(ui->tblData->toString(i, 0))));

        fDD[":f_tax"] = fTaxCode;
        fDD[":f_wdate"] = WORKING_DATE;
        fDD[":f_vaucher"] = ui->tblData->toString(i, 0);
        fDD[":f_invoice"] = fInvoice;
        fDD[":f_date"] = QDate::currentDate();
        fDD[":f_time"] = QTime::currentTime();
        fDD[":f_name"] = ui->tblData->toString(i, 2);
        fDD[":f_amountCash"] = ui->leCash->asDouble();
        fDD[":f_amountCard"] = ui->leCard->asDouble();
        fDD[":f_amountPrepaid"] = ui->lePre->asDouble();
        fDD[":f_user"] = WORKING_USERID;
        fDD[":f_comp"] = HOSTNAME;
        fDD.insert("m_tax_history");
    }
    //TODO IN FUTURE UPDATE TAX PREPAID AMOUNT
    if (ui->lePre->asDouble() > 0.001) {
        fDD[":f_invoice"] = fInvoice;
        fDD[":f_amount"] = ui->lePre->asDouble();
        fDD.insert("f_used_advance");
    }


    accept();
}

void PrintTaxD::on_tblData_clicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    if (index.column() == 4) {
        countAmount();
    }
}

void PrintTaxD::on_leCard_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1)
    correctAmounts(ui->leCard, ui->leCash, ui->lePre);
}

void PrintTaxD::on_leCash_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1)
    correctAmounts(ui->leCash, ui->leCard, ui->lePre);
}

void PrintTaxD::on_lePre_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1)
    correctAmounts(ui->lePre, ui->leCash, ui->leCard);
}

void PrintTaxD::correctAmounts(EQLineEdit *l1, EQLineEdit *l2, EQLineEdit *l3)
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
    fAmountCard = QString::number(ui->leCard->asDouble());
    fAmountCash = QString::number(ui->leCash->asDouble());
    fAmountPre = QString::number(ui->lePre->asDouble());
}

void PrintTaxD::on_chCheckUncheckAll_clicked(bool checked)
{
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        if (ui->tblData->isRowHidden(i)) {
            continue;
        }
        ui->tblData->setItemChecked(i, 4, checked);
    }
    countAmount();
}

void PrintTaxD::on_tblFilter_clicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    fFilter = index.data(Qt::DisplayRole).toString();
    filter();
}

void PrintTaxD::on_btnClearFilter_clicked()
{
    fFilter = "";
    filter();
}
