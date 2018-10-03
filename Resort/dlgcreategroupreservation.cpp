#include "dlgcreategroupreservation.h"
#include "ui_dlgcreategroupreservation.h"
#include "wgroupreserverect.h"
#include "wreservation.h"
#include "wreservationroomtab.h"
#include "cacheroomcategory.h"
#include "cachebed.h"
#include "dlgreservationremarks.h"
#include "wguest.h"

DlgCreateGroupReservation::DlgCreateGroupReservation(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgCreateGroupReservation)
{
    ui->setupUi(this);
    loadRooms();

    QTableWidgetItem *i1 = new QTableWidgetItem(tr("Any"));
    i1->setData(Qt::UserRole, 0);
    QTableWidgetItem *i2 = new QTableWidgetItem(tr("Yes"));
    i1->setData(Qt::UserRole, 1);
    QTableWidgetItem *i3 = new QTableWidgetItem(tr("No"));
    i2->setData(Qt::UserRole, 2);
    ui->tblSmoke->setItem(0, 0, i1);
    ui->tblSmoke->setItem(0, 1, i2);
    ui->tblSmoke->setItem(0, 2, i3);

    CacheInstance *ci = cache(cid_room_category);
    ui->tblCategory->setColumnCount(ci->count());
    ui->tblCategory->setRowCount(1);
    int col = 0;
    QMap<QString, QList<QVariant> >::iterator it = ci->fRows.begin();
    while (it != ci->fRows.end()) {
        ui->tblCategory->setItem(0, col++, new QTableWidgetItem(it.value().at(1).toString()));
        it++;
    }

    ci = cache(cid_bed);
    ui->tblBed->setColumnCount(ci->count());
    ui->tblBed->setRowCount(1);
    col = 0;
    it = ci->fRows.begin();
    while (it != ci->fRows.end()) {
        ui->tblBed->setItem(0, col++, new QTableWidgetItem(it.value().at(0).toString()));
        it++;
    }

    col = 0;
    ui->tblFloor->setColumnCount(9);
    ui->tblFloor->setRowCount(1);
    for (int i = 0; i < ui->tblFloor->columnCount(); i++) {
        ui->tblFloor->setItem(0, i, new QTableWidgetItem(QString::number(i + 1)));
    }

    fSingleMode = false;
}

DlgCreateGroupReservation::~DlgCreateGroupReservation()
{
    delete ui;
}

void DlgCreateGroupReservation::loadRooms()
{
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.exec("select f_id, f_floor, f_short, f_rate from f_room order by f_id");
    int floor = 0;
    int row = 0;
    int col = 0;
    QStringList floors;
    while (fDD.nextRow()) {
        if (floor != fDD.getInt(1)) {
            floor = fDD.getInt(1);
            floors << QString::number(floor);
            row = ui->tblData->rowCount();
            ui->tblData->setRowCount(row + 1);
            col = 0;
        }
        WGroupReserveRect *w = new WGroupReserveRect();
        connect(w, SIGNAL(checkClicked(bool)), this, SLOT(singleHandle(bool)));
        QString k = fDD.getString(2);
        QString s = k.remove(0, 4);
        w->setRoomName(fDD.getString(0), fDD.getString(0) + "\n" + s);
        ui->tblData->setCellWidget(row, col, w);
        col++;
        if (col > ui->tblData->columnCount() - 1) {
            floors << QString::number(floor);
            row = ui->tblData->rowCount();
            ui->tblData->setRowCount(row + 1);
            col = 0;
        }
    }
    ui->tblData->setVerticalHeaderLabels(floors);
    QSize size(ui->tblData->size());
    size.setWidth((ui->tblData->columnCount() * ui->tblData->horizontalHeader()->defaultSectionSize()) + 20);
    size.setHeight((floors.count() * ui->tblData->verticalHeader()->defaultSectionSize()) + 25);
    ui->tblData->setMinimumHeight(size.height());
    ui->tblData->setMaximumHeight(size.height());
    adjustSize();
    makeRooms();
}

void DlgCreateGroupReservation::setSingleMode(bool mode)
{
    fSingleMode = mode;
    if (fSingleMode) {
        ui->wdtGroup->setVisible(false);
        ui->btnCreate->setText(tr("Select"));
        setWindowTitle(tr("Select room"));
    }
}

void DlgCreateGroupReservation::setReservationTab(WReservationRoomTab *t)
{
    fTab = t;
    ui->deArrival->setDate(t->date1());
    ui->deDeparture->setDate(t->date2());
    makeRooms();
}

void DlgCreateGroupReservation::singleHandle(bool v)
{
    if (!fSingleMode) {
        return;
    }
    if (!v) {
        return;
    }
    WGroupReserveRect *gro = static_cast<WGroupReserveRect*>(sender());
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        for (int j = 0; j < ui->tblData->columnCount(); j++) {
            if (ui->tblData->cellWidget(i, j)) {
                WGroupReserveRect *gr = static_cast<WGroupReserveRect*>(ui->tblData->cellWidget(i, j));
                if (gr->isEnabled()) {
                    if (gr->checked()) {
                        if (gr != gro) {
                            gr->uncheck();
                        }
                    }
                }
            }
        }
    }
}


void DlgCreateGroupReservation::makeRooms()
{
    QModelIndexList selCat = ui->tblCategory->selectionModel()->selectedIndexes();
    QStringList lstCat;
    for (int i = 0; i < selCat.count(); i++) {
        lstCat << selCat.at(i).data(Qt::DisplayRole).toString();
    }
    QModelIndexList selFloor = ui->tblFloor->selectionModel()->selectedIndexes();
    QStringList lstFloor;
    for (int i = 0; i < selFloor.count(); i++) {
        lstFloor << selFloor.at(i).data(Qt::DisplayRole).toString();
    }
    QModelIndexList selBed = ui->tblBed->selectionModel()->selectedIndexes();
    QStringList lstBed;
    for (int i = 0;i < selBed.count(); i++) {
        lstBed << selBed.at(i).data(Qt::DisplayRole).toString();
    }
    QModelIndexList selSmoke = ui->tblSmoke->selectionModel()->selectedIndexes();
    int smoke = 0;
    if (selSmoke.count() > 0) {
        smoke = selSmoke.at(0).column();
    }
    QSet<int> excluded;
    CacheReservation cr;
    cr.exludeList(ui->deArrival->date(), ui->deDeparture->date(), excluded);
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        for (int j = 0; j < ui->tblData->columnCount(); j++) {
            if (ui->tblData->cellWidget(i, j)) {
                WGroupReserveRect *gr = static_cast<WGroupReserveRect*>(ui->tblData->cellWidget(i, j));
                CacheRoom room;
                room.get(gr->code());
                bool enabled = !excluded.contains(room.fCode().toInt());
                if (lstCat.count() > 0) {
                    enabled = enabled && lstCat.contains(room.fCategoryShort());
                }
                if (lstFloor.count() > 0) {
                    enabled = enabled && lstFloor.contains(QString::number(room.fFloor()));
                }
                if (lstBed.count() > 0) {
                    enabled = enabled && lstBed.contains(room.fBed());
                }
                if (smoke > 0) {
                    enabled = enabled && room.fSmoke() == (smoke == 1 ? 1 : 0);
                }
                gr->setEnabled(enabled);
            }
        }
    }

}


void DlgCreateGroupReservation::on_btnCreate_clicked()
{
    bool noReservation = true;
    if (!fSingleMode) {

    } else {
        noReservation = false;
        QString code;
        for (int i = 0; i < ui->tblData->rowCount(); i++) {
            for (int j = 0; j < ui->tblData->columnCount(); j++) {
                if (ui->tblData->cellWidget(i, j)) {
                    WGroupReserveRect *gr = static_cast<WGroupReserveRect*>(ui->tblData->cellWidget(i, j));
                    if (gr->isEnabled()) {
                        if (gr->checked()) {
                            code = gr->code();
                        }
                    }
                }
            }
        }
        fTab->setBaseData(ui->deArrival->date(), ui->deDeparture->date(), code);
    }
    if (noReservation) {
        message_error(tr("Nothing was selected"));
        return;
    }
    accept();
}

void DlgCreateGroupReservation::on_btnClearRoomFilter_clicked()
{
    ui->tblBed->clearSelection();
    ui->tblCategory->clearSelection();
    ui->tblFloor->clearSelection();
    ui->tblSmoke->clearSelection();
    makeRooms();
}

void DlgCreateGroupReservation::on_tblCategory_clicked(const QModelIndex &index)
{
    Q_UNUSED(index)
    makeRooms();
}

void DlgCreateGroupReservation::on_tblBed_clicked(const QModelIndex &index)
{
    Q_UNUSED(index)
    makeRooms();
}

void DlgCreateGroupReservation::on_tblFloor_clicked(const QModelIndex &index)
{
    Q_UNUSED(index)
    makeRooms();
}

void DlgCreateGroupReservation::on_tblSmoke_clicked(const QModelIndex &index)
{
    Q_UNUSED(index)
    makeRooms();
}

void DlgCreateGroupReservation::on_deArrival_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1)
    if (ui->deArrival->date() < WORKING_DATE) {
        ui->deArrival->setStyleSheet("background:red");
        return;
    } else {
        ui->deArrival->setStyleSheet("background:white");
    }
    makeRooms();
}

void DlgCreateGroupReservation::on_deDeparture_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1)
    if (ui->deDeparture->date() < WORKING_DATE) {
        ui->deDeparture->setStyleSheet("background:red");
        return;
    } else {
        ui->deDeparture->setStyleSheet("background:white");
    }
    makeRooms();
}

