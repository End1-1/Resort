#include "froomcatsale.h"
#include "ui_froomcatsale.h"
#include "wreportgrid.h"
#include "cacheroomcategory.h"
#include "vauchers.h"

FRoomCatSale::FRoomCatSale(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FRoomCatSale)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Category statistics"), ":/images/graph.png");
    ui->leCat->setSelector(this, cache(cid_room_category), ui->leCatName);
    connect(fReportGrid, &WReportGrid::doubleClickOnRow, this, &FRoomCatSale::doubleClickOnRow);
}

FRoomCatSale::~FRoomCatSale()
{
    delete ui;
}

QString FRoomCatSale::reportTitle()
{
    QString r = QString("%1, %2 - %3").arg(tr("Category statistics"), ui->wd->dss1(), ui->wd->dss2());
    return r;
}

void FRoomCatSale::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(80, "", tr("Voucher"))
            .setColumn(120, "", tr("Date"))
            .setColumn(100, "", tr("Invoice"))
            .setColumn(300, "", tr("Guest"))
            .setColumn(100, "", tr("Category"))
            .setColumn(100, "", tr("Room"))
            .setColumn(100, "", tr("Price"));
    QString sql = "select m.f_id, m.f_wdate, m.f_inv, m.f_guest, "
                "rc.f_description, m.f_room, m.f_amountamd "
                "from m_register  m "
                "left join f_room r on r.f_id=m.f_room "
                "left join f_room_classes rc on rc.f_id=r.f_class "
                "where m.f_canceled=0 and m.f_source='RM' "
                "and m.f_wdate between :d1 and :d2 :cat "
                "order by m.f_wdate, m.f_inv ";
    sql.replace(":d1", ui->wd->ds1()).replace(":d2", ui->wd->ds2());
    if (ui->leCat->isEmpty()) {
        sql.replace(":cat", "");
    } else {
        sql.replace(":cat", QString(" and r.f_class=%1 ").arg(ui->leCat->text()));
    }
    rg->fModel->setSqlQuery(sql);
    rg->fModel->apply(rg);
    QList<int> cols;
    cols.append(6);
    QList<double> vals;
    rg->fModel->sumOfColumns(cols, vals);
    rg->setTblTotalData(cols, vals);
}

QWidget *FRoomCatSale::firstElement()
{
    return ui->wd->fw();
}

QWidget *FRoomCatSale::lastElement()
{
    return nullptr;
}

void FRoomCatSale::doubleClickOnRow(const QList<QVariant> &vals)
{
    if (vals.count() == 0) {
        return;
    }
    openInvoiceWithId(vals.at(2).toString());
}
