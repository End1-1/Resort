#include "fhotelhierarchy.h"
#include "ui_fhotelhierarchy.h"
#include "wreportgrid.h"

FHotelHierarchy::FHotelHierarchy(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FHotelHierarchy)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Hotel hierarchy"), ":/images/hierarchy.png");
}

FHotelHierarchy::~FHotelHierarchy()
{
    delete ui;
}

QString FHotelHierarchy::reportTitle()
{
    return tr("Hotel hierarchy");
}

QWidget *FHotelHierarchy::firstElement()
{
    return this;
}

QWidget *FHotelHierarchy::lastElement()
{
    return this;
}

void FHotelHierarchy::apply(WReportGrid *rg)
{
    rg->fModel->clearData();
    rg->fTableView->clearSpans();
    rg->fTableView->verticalHeader()->setDefaultSectionSize(60);
    rg->fModel->clearColumns();
    rg->fModel->setColumn(100, "", tr("Floor"))
            .setColumn(80, "", "X")
            .setColumn(80, "", "X")
            .setColumn(80, "", "X")
            .setColumn(80, "", "X")
            .setColumn(80, "", "X")
            .setColumn(80, "", "X")
            .setColumn(80, "", "X")
            .setColumn(80, "", "X")
            .setColumn(80, "", "X")
            .setColumn(80, "", "X");
    QList<QVariant> emptyRow;
    emptyRow << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "";
    DoubleDatabase db;
    db.exec("select c.f_short, r.f_short, r.f_floor, r.f_building "
            "from f_room r "
            "left join f_room_classes c on c.f_id=r.f_class "
            "order by r.f_building, r.f_floor");
    int building = 0;
    int floor = 0;
    int lastRowFloor = 0;
    int col = 0;
    int rowNum = 0;
    while (db.nextRow()) {
        if (building != db.getInt(3)) {
            if (building > 0) {
                rg->fTableView->setSpan(lastRowFloor, 0, rg->fModel->rowCount() - lastRowFloor, 1);
            }
            building = db.getInt(3);
            floor = db.getInt(2);
            QList<QVariant> row = emptyRow;
            row[0] = QString("%1 #%2").arg(tr("Building")).arg(building);
            rowNum = rg->fModel->appendRow(row);
            rg->fTableView->setSpan(rowNum, 0, 1, rg->fModel->columnCount());
            lastRowFloor = rowNum + 1;
            col = 0;
        }
        if (floor != db.getInt(2)) {
            if (floor > 0) {
                rg->fTableView->setSpan(lastRowFloor, 0, rg->fModel->rowCount() - lastRowFloor, 1);
                rowNum = rg->fModel->appendRow(emptyRow);
                rg->fTableView->setSpan(rowNum, 0, 1, rg->fModel->columnCount());
                lastRowFloor = rg->fModel->rowCount();
                col = 0;
            }
            floor = db.getInt(2);
        }
        if (col == 0) {
            rowNum = rg->fModel->appendRow(emptyRow);
            rg->fModel->setData(rowNum, 0, floor);
            col++;
        }
        rg->fModel->setData(rowNum, col, db.getString(1));
        col++;
        if (col == 11) {
            col = 0;
        }
    }
    rg->fTableView->setSpan(lastRowFloor, 0, rg->fModel->rowCount() - lastRowFloor, 1);
    rg->fModel->apply(rg);
}
