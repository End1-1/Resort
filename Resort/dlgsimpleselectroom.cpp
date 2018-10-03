#include "dlgsimpleselectroom.h"
#include "ui_dlgsimpleselectroom.h"
#include "cachereservation.h"
#include "cacheroom.h"
#include "cachebed.h"

DlgSimpleSelectRoom::DlgSimpleSelectRoom(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgSimpleSelectRoom)
{
    ui->setupUi(this);
    ui->tblData->setSortingEnabled(false);
    qApp->processEvents();

    QTableWidgetItem *i1 = new QTableWidgetItem(tr("Any"));
    i1->setData(Qt::UserRole, 0);
    QTableWidgetItem *i2 = new QTableWidgetItem(tr("Yes"));
    i1->setData(Qt::UserRole, 1);
    QTableWidgetItem *i3 = new QTableWidgetItem(tr("No"));
    i2->setData(Qt::UserRole, 2);
    ui->tblSmoke->setItem(0, 0, i1);
    ui->tblSmoke->setItem(0, 1, i2);
    ui->tblSmoke->setItem(0, 2, i3);

    ui->tblFloor->setColumnCount(9);
    ui->tblFloor->setRowCount(1);
    for (int i = 0; i < ui->tblFloor->columnCount(); i++) {
        ui->tblFloor->setItem(0, i, new QTableWidgetItem(QString::number(i + 1)));
    }
    fSingleSelection = false;
}

DlgSimpleSelectRoom::~DlgSimpleSelectRoom()
{
    delete ui;
}

int DlgSimpleSelectRoom::getRoom(const QString &cat, const QDate &d1, const QDate &d2, QStringList exclude, const QString &bed, bool v)
{
    ui->tblData->setSelectionMode(v ? QAbstractItemView::MultiSelection : QAbstractItemView::SingleSelection);
    fExclude = exclude;
    fBed = bed;
    fDate1 = d1;
    fDate2 = d2;
    ui->lbCat->setText(cat);
    filter();
    return exec();
}

double DlgSimpleSelectRoom::price()
{
    return ui->lePrice->asDouble();
}

void DlgSimpleSelectRoom::getRoomsList(QStringList &rooms)
{
    for (int r = 0; r < ui->tblData->rowCount(); r++) {
        for (int c = 0; c < ui->tblData->columnCount(); c++) {
            QTableWidgetItem *item = ui->tblData->item(r, c);
            if (!item) {
                break;
            }
            if (item->checkState() == Qt::Checked) {
                rooms.append(item->data(Qt::UserRole).toString());
            }
        }
    }
}

void DlgSimpleSelectRoom::on_tblData_doubleClicked(const QModelIndex &index)
{
    if (!fSingleSelection) {
        return;
    }
    if (!index.isValid()) {
        return;
    }
    fRoomCode = index.data(Qt::UserRole).toString();
    if (!fRoomCode.isEmpty()) {
        accept();
    }
}

void DlgSimpleSelectRoom::on_tblSmoke_clicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    fSmoke = index.column();
    filter2();
}

void DlgSimpleSelectRoom::on_tblFloor_clicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    fFloor = index.data(Qt::DisplayRole).toInt();
    filter2();
}

void DlgSimpleSelectRoom::on_tblBed_clicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    fBed = index.data(Qt::DisplayRole).toString();
    filter2();
}

void DlgSimpleSelectRoom::on_btnClearRoomFilter_clicked()
{
    fBed = "";
    fSmoke = 0;
    fFloor = 0;
    ui->tblFloor->clearSelection();
    ui->tblSmoke->clearSelection();
    filter2();
}

void DlgSimpleSelectRoom::filter()
{
    QSet<int> out;
    CacheReservation cr;
    cr.exludeList(fDate1, fDate2, out);
    QStringList roomList;
    CacheInstance *ci = cache(cid_room);
    CacheRoom croom;
    croom.fInstance = ci;
    QMap<QString, QList<QVariant> >::iterator it = ci->fRows.begin();
    while (it != ci->fRows.end()) {
        croom.fData = it.value();
        if (out.contains(croom.fCode().toInt())) {
            it++;
            continue;
        }
        if (fExclude.contains(croom.fCode())) {
            it++;
            continue;
        }
        if (croom.fCategoryShort() != ui->lbCat->text()) {
            it++;
            continue;
        }
        if (croom.fBed() != fBed) {
            it++;
            continue;
        }
        roomList.append(croom.fCode());
        it++;
    }
    Utils::setupTableFullColumnWidth(ui->tblData, 100, roomList.count());
    int col = 0, row = 0;
    foreach (QString s, roomList) {
        CacheRoom r;
        r.get(s);
        ui->tblData->setItemWithValue(row, col, r.fName(), s);
        ui->tblData->item(row, col)->setCheckState(Qt::Unchecked);
        col++;
        if (col >= ui->tblData->columnCount()) {
            col = 0;
            row++;
        }
    }
    on_btnClearRoomFilter_clicked();
    filter2();
}

void DlgSimpleSelectRoom::filter2()
{
    for (int r = 0; r < ui->tblData->rowCount(); r++) {
        for (int c = 0; c < ui->tblData->columnCount(); c++) {
            QTableWidgetItem *item = ui->tblData->item(r, c);
            if (!item) {
                break;
            }
            CacheRoom cr ;
            if (!cr.get(item->data(Qt::UserRole).toString())) {
                break;
            }
            item->setFlags(item->flags() | Qt::ItemIsEnabled);
            if (!fBed.isEmpty()) {
                if (fBed != cr.fBed()) {
                    item->setFlags(item->flags() ^ Qt::ItemIsEnabled);
                    continue;
                }
            }
            if (fFloor > 0) {
                if (fFloor != cr.fFloor()) {
                    item->setFlags(item->flags() ^ Qt::ItemIsEnabled);
                    continue;
                }
            }
            if (fSmoke > 0) {
                if (fSmoke - 1 != cr.fSmoke()) {
                    item->setFlags(item->flags() ^ Qt::ItemIsEnabled);
                    continue;
                }
            }
        }
    }
}

void DlgSimpleSelectRoom::on_btnMultiSelect_clicked()
{
    accept();
}


void DlgSimpleSelectRoom::on_tblData_clicked(const QModelIndex &index)
{
    int total = 0;
    for (int r = 0; r < ui->tblData->rowCount(); r++) {
        for (int c = 0; c < ui->tblData->columnCount(); c++) {
            QTableWidgetItem *item = ui->tblData->item(r, c);
            if (!item) {
                continue;
            }
            if (fSingleSelection) {
                if (r != index.row() || c != index.column()) {
                    item->setCheckState(Qt::Unchecked);
                }
            }
            if (item->checkState() == Qt::Checked) {
                total++;
            }
        }
    }
    ui->lbTotal->setText(QString("Total: %1").arg(total));
}
