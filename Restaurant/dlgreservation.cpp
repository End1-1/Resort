#include "dlgreservation.h"
#include "ui_dlgreservation.h"
#include "rmessage.h"

DlgReservation::DlgReservation(QWidget *parent) :
    BaseExtendedDialogR(parent),
    ui(new Ui::DlgReservation)
{
    ui->setupUi(this);
    ui->tblItem->setVisible(false);
    fItemCode = 0;
    fMode = 0;
    connect(ui->kbd, SIGNAL(textChanged(QString)), this, SLOT(kdbText(QString)));
    connect(ui->kbd, SIGNAL(reject()), this, SLOT(reject()));
    connect(ui->kbd, SIGNAL(accept()), this, SLOT(kbdAccept()));
    showMaximized();
}

DlgReservation::~DlgReservation()
{
    delete ui;
}

void DlgReservation::loadRoom()
{
    fMode = 1;
    ui->tblItem->setVisible(true);
    ui->tblData->setColumnCount(7);
    Utils::tableSetColumnWidths(ui->tblData, ui->tblData->columnCount(),
                                0, 80, 300, 200, 100, 50, 300);
    QStringList labels;
    labels << tr("Reserve id")
           << tr("Room")
           << tr("Guest")
           << tr("Departure")
           << tr("Pax")
           << tr("Nat")
           << tr("Remarks");
    ui->tblData->setHorizontalHeaderLabels(labels);
    QString query = "select r.f_id, r.f_room, concat(g.f_title, ' ', g.f_firstName, ' ', g.f_lastName), \
            r.f_endDate, r.f_man + r.f_woman + r.f_child + r.f_baby, g.f_nation, r.f_remarks \
            from f_reservation r \
            inner join f_guests g on g.f_id=r.f_guest \
            where r.f_state=1 "
            "order by r.f_room ";
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.exec(query);
    if (fDD.rowCount() == 0) {
        return;
    }
    while (fDD.nextRow()) {
        int row = ui->tblData->rowCount();
        ui->tblData->setRowCount(row + 1);
        for (int i = 0; i < ui->tblData->columnCount(); i++) {
            ui->tblData->setItem(row, i, new QTableWidgetItem(fDD.getString(i)));
        }
    }
    query = "select o.f_item, i.f_" + def_lang + " from o_reserve_item o "
            "inner join f_invoice_item i on i.f_id=o.f_item ";
    fDD.exec(query);
    if (fDD.rowCount() == 0) {
        return;
    }
    int col;
    ui->tblItem->setRowCount(1);
    while (fDD.nextRow()) {
        col = ui->tblItem->columnCount();
        ui->tblItem->setColumnCount(col + 1);
        QTableWidgetItem *item = new QTableWidgetItem(fDD.getString(1));
        item->setData(Qt::UserRole, fDD.getValue(0));
        ui->tblItem->setItem(0, col, item);
    }
    if (ui->tblItem->columnCount() > 0) {
        ui->tblItem->setCurrentCell(0, 0);
        fItemCode = ui->tblItem->item(0, 0)->data(Qt::UserRole).toInt();
    }
}

void DlgReservation::loadCL()
{
    fMode = 2;
    ui->tblData->setColumnCount(2);
    Utils::tableSetColumnWidths(ui->tblData, ui->tblData->columnCount(),
                                100, 400);
    QStringList labels;
    labels << tr("City ledger")
           << tr("Name");
    ui->tblData->setHorizontalHeaderLabels(labels);
    QString query = "select f_id, f_name from f_city_ledger ";
    //fDD[":f_dateTo"] = WORKING_DATE;
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.exec(query);
    while (fDD.nextRow()) {
        int row = ui->tblData->rowCount();
        ui->tblData->setRowCount(row + 1);
        for (int i = 0; i < ui->tblData->columnCount(); i++) {
            ui->tblData->setItem(row, i, new QTableWidgetItem(fDD.getString(i)));
        }
    }
}

void DlgReservation::loadCars()
{
    fMode = 3;
    ui->tblData->setColumnCount(2);
    Utils::tableSetColumnWidths(ui->tblData, ui->tblData->columnCount(),
                                0, 400);
    QStringList labels;
    labels << tr("Code")
           << tr("Name");
    ui->tblData->setHorizontalHeaderLabels(labels);
    QString query = "select f_id, concat(f_model, ' ', f_class) from d_car_model order by 2";
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.exec(query);
    while (fDD.nextRow()) {
        int row = ui->tblData->rowCount();
        ui->tblData->setRowCount(row + 1);
        for (int i = 0; i < ui->tblData->columnCount(); i++) {
            ui->tblData->setItem(row, i, new QTableWidgetItem(fDD.getString(i)));
        }
    }
}

void DlgReservation::kdbText(const QString &text)
{
    ui->leSearch->setText(text);
}

void DlgReservation::kbdAccept()
{
    if (fMode == 1) {
        if (fItemCode == 0) {
            return;
        }
    }
    if (fMode == 2) {
        if (fReservationId.isEmpty()) {
            return;
        }
    }
    accept();
}

void DlgReservation::on_leSearch_textChanged(const QString &arg1)
{
    ui->kbd->setText(arg1);
    for (int i = 0, rowCount = ui->tblData->rowCount(); i < rowCount; i++) {
        ui->tblData->setRowHidden(i, true);
        for (int j = 0, colCount = ui->tblData->columnCount(); j < colCount; j++) {
            if (ui->tblData->item(i, j)->text().contains(arg1, Qt::CaseInsensitive)) {
                ui->tblData->setRowHidden(i, false);
                goto mark;
            }
        }
        mark:
        continue;
    }
}

void DlgReservation::on_btnClear_clicked()
{
    ui->leSearch->clear();
}

void DlgReservation::on_tblData_clicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    /// room
    if (fMode == 1) {
        fItemCode = 1;
        fReservationId = ui->tblData->item(index.row(), 0)->text();
        ui->leHint->setText(tr("Room #") + ui->tblData->item(index.row(), 1)->text() + ", "
                            + ui->tblData->item(index.row(), 2)->text());
    }
    /// cl
    if (fMode == 2) {
        fReservationId = ui->tblData->item(index.row(), 0)->text();
        ui->leHint->setText(ui->tblData->item(index.row(), 0)->text() + ", "
                            + ui->tblData->item(index.row(), 1)->text());
    }
}

void DlgReservation::on_tblItem_clicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    fItemCode = index.data(Qt::UserRole).toInt();
}
