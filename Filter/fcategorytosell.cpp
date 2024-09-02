#include "fcategorytosell.h"
#include "ui_fcategorytosell.h"
#include "wreportgrid.h"

FCategoryToSell::FCategoryToSell(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FCategoryToSell)
{
    ui->setupUi(this);
}

FCategoryToSell::~FCategoryToSell()
{
    delete ui;
}

void FCategoryToSell::setup()
{
    fReportGrid->setupTabTextAndIcon(tr("Category to sell"), ":/images/app.png");
}

void FCategoryToSell::apply(WReportGrid *rg)
{

    QList<QVariant> emptyRow;
    emptyRow << "" << "" << "" << "" << "" << "" << "" << "" << "" << "";
    rg->fModel->clearColumns();
    rg->fModel->clearData();
    rg->fModel->setColumn(80, "", tr("Cat."))
            .setColumn(200, "", tr("Description"));
    if (ui->chGroupByView->isChecked()) {
        rg->fModel->setColumn(80, "", tr("View"));
    }
    if (ui->chGroupByBed->isChecked()) {
        rg->fModel->setColumn(80, "", tr("Bed"));
    }
    rg->fModel->setColumn(80, "", tr("Total"))
            .setColumn(80, "", tr("Confirmed"))
            .setColumn(80, "", tr("Guaranted"))
            .setColumn(80, "", tr("Tentative"))
            .setColumn(80, "", tr("Waiting"))
            .setColumn(80, "", tr("Block"))
            .setColumn(80, "", tr("CheckIn"))
            .setColumn(80, "", tr("Still to sell"));
    QString query = "select rc.f_short, rc.f_description, :view :bed  count(rm.f_id) "
                    "from f_room rm "
                    "left join f_room_classes rc on rc.f_id=rm.f_class "
                    "left join f_room_view rv on rv.f_id=rm.f_view ";
    QString group = "group by rc.f_short,rc.f_description,";
    int off = 0;
    if (ui->chGroupByBed->isChecked()) {
        query.replace(":view", "rv.f_short,");
        group += "rv.f_short,";
        emptyRow << "";
        off++;
    } else {
        query.replace(":view", "");
    }
    if (ui->chGroupByView->isChecked()) {
        query.replace(":bed", "rm.f_bed,");
        group += "rm.f_bed,";
        emptyRow << "";
        off++;
    } else {
        query.replace(":bed", "");
    }
    group.remove(group.length() - 1, 1);
    query += group;
    QMap<QString, int> map;
    DoubleDatabase db;
    db.exec(query);
    QString mapName;
    while (db.nextRow()) {
        QList<QVariant> row = emptyRow;
        int col = 0;
        row[col] = db.getString(col);
        mapName = db.getString(col);
        col++;
        row[col] = db.getString(col);
        mapName += "+" + db.getString(col);
        col++;
        if (ui->chGroupByBed->isChecked()) {
            row[col] = db.getString(col);
            mapName += "+" + db.getString(col);
            col++;
        }
        if (ui->chGroupByView->isChecked()) {
            row[col] = db.getString(col);
            mapName += "+" + db.getString(col);
            col++;
        }
        row[col] = db.getString(col);
        col++;
        map[mapName] = rg->fModel->rowCount();
        rg->fModel->appendRow(row);
    }
    query = "select rc.f_short, rc.f_description, :view :bed r.f_reserveState, r.f_state, r.f_room "
            "from f_reservation r "
            "left join f_room rm on rm.f_id=r.f_room "
            "left join f_room_classes rc on rc.f_id=rm.f_class "
            "left join f_room_view rv on rv.f_id=rm.f_view "
            "where  r.f_state in (1,2) and "
            "((r.f_startdate <=:date1 and  r.f_enddate > :date1) "
            "or (r.f_startdate >= :date1 and r.f_enddate < :date2)  "
            "or (r.f_startdate <:date2 and r.f_enddate>:date2)) ";
    query.replace(":date1", ui->deStart->dateMySql()).replace(":date2", ui->deEnd->dateMySql());
    if (ui->chGroupByBed->isChecked()) {
        query.replace(":view", "rv.f_short,");
        emptyRow << "";
    } else {
        query.replace(":view", "");
    }
    if (ui->chGroupByView->isChecked()) {
        query.replace(":bed", "rm.f_bed,");
        emptyRow << "";
    } else {
        query.replace(":bed", "");
    }
    db.exec(query);
    QList<int> rooms;
    while (db.nextRow()) {
        mapName = db.getString(0) + "+" + db.getString(1);
        int col = 2;
        if (ui->chGroupByBed->isChecked()) {
            mapName += "+" + db.getString(col);
            col++;
        }
        if (ui->chGroupByView->isChecked()) {
            mapName += "+" + db.getString(col);
            col++;
        }
        if (rooms.contains(db.getInt(col + 2))) {
            continue;
        }
        rooms << db.getInt(col + 2);
        int row = map[mapName];
        int dataCol = 0;
        if (db.getInt(col + 1) == RESERVE_CHECKIN) {
            dataCol = 8 + off;
        } else {
            dataCol = 3 + off + CONFIRM_CONFIRM;
        }
        rg->fModel->setData(row, dataCol, rg->fModel->data(row, dataCol, Qt::DisplayRole).toDouble() + 1);
    }
    for (int i = 0; i < rg->fModel->rowCount(); i++) {
        rg->fModel->setData(i, 9 + off,
                            rg->fModel->data(i, 2 + off, Qt::DisplayRole).toDouble() -
                            rg->fModel->data(i, 3 + off, Qt::DisplayRole).toDouble() -
                            rg->fModel->data(i, 4 + off, Qt::DisplayRole).toDouble() -
                            rg->fModel->data(i, 5 + off, Qt::DisplayRole).toDouble() -
                            rg->fModel->data(i, 6 + off, Qt::DisplayRole).toDouble() -
                            rg->fModel->data(i, 7 + off, Qt::DisplayRole).toDouble() -
                            rg->fModel->data(i, 8 + off, Qt::DisplayRole).toDouble());
    }
    rg->fModel->apply(rg);
}

QWidget *FCategoryToSell::firstElement()
{
    return ui->deStart;
}

QWidget *FCategoryToSell::lastElement()
{
    return ui->deEnd;
}
