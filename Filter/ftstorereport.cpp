#include "ftstorereport.h"
#include "ui_ftstorereport.h"
#include "wreportgrid.h"
#include "cachestorepartners.h"
#include "cachedish.h"
#include "cachereststore.h"

FTStoreReport::FTStoreReport(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FTStoreReport)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("T report"), ":/images/notepad.png");
    connect(ui->wd, &WDate2::changed, [this]() {
        apply(fReportGrid);
    });

    ui->leGoods->setSelector(this, cache(cid_dish), ui->leGoods);
    ui->lePartner->setSelector(this, cache(cid_store_partners), ui->lePartner);
    ui->leStore->setSelector(this, cache(cid_rest_store), ui->leStore);

}

FTStoreReport::~FTStoreReport()
{
    delete ui;
}

QString FTStoreReport::reportTitle()
{
    QString title = tr("T report %1 - %2").arg(ui->wd->ds1()).arg(ui->wd->ds2());
    if (!ui->lePartner->isEmpty()) {
        title += ", " + ui->lePartner->text();
    }
    if (!ui->leGoods->isEmpty()) {
        title += ", " + ui->leGoods->text();
    }
    return title;
}

QWidget *FTStoreReport::firstElement()
{
    return ui->wd->fw();
}

void FTStoreReport::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->clearData();
    rg->fModel->setColumn(120, "", tr("Date"))
            .setColumn(80, "", tr("Begin, qty"))
            .setColumn(80, "", tr("Begin, amount"))
            .setColumn(80, "", tr("Input, qty"))
            .setColumn(80, "", tr("Input, amount"))
            .setColumn(80, "", tr("Output, qty"))
            .setColumn(80, "", tr("Output, amount"))
            .setColumn(80, "", tr("Final, qty"))
            .setColumn(80, "", tr("Final, amount"))
            ;
    QDate d1 = ui->wd->d1();
    QDate d2 = ui->wd->d2();
    QMap<QDate, int> dateMap;
    int r = d1.daysTo(d2) + 1;
    for (int i = 0; i < r; i++) {
        dateMap[d1.addDays(i)] = i;
        QList<QVariant> row;
        row << d1.addDays(i)
            << 0
            << 0
            << 0
            << 0
            << 0
            << 0
            << 0
            << 0;
        rg->fModel->appendRow(row);
    }
    rg->fModel->apply(rg);

    QString where;
    if (!ui->leStore->isEmpty()) {
        where += " and b.f_store in (" + ui->leStore->fHiddenText + ") ";
    }
    if (!ui->leGoods->isEmpty()) {
        where += " and b.f_material in (" + ui->leGoods->fHiddenText + ") ";
    }
    if (!ui->lePartner->isEmpty()) {
        where += " and d.f_partner in (" + ui->lePartner->fHiddenText + ") ";
    }
    QString query = "select d.f_date, "
            "b.f_material as matcode, m.f_en as f_material, b.f_qty, b.f_price, b.f_total, b.f_sign "
            "from r_body b "
            "left join r_docs d on d.f_id=b.f_doc "
            "left join r_partners pn on pn.f_id=d.f_partner "
            "left join r_doc_type dt on dt.f_id=d.f_type "
            "left join r_store s on s.f_id=b.f_store "
            "left join r_dish m on m.f_id=b.f_material "
            "where d.f_date between " + ui->wd->ds1() + " and " + ui->wd->ds2() +
            " and d.f_state=1 " +  where;
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.exec(query);
    while (fDD.nextRow()) {
        r = dateMap[fDD.getDate(0)];
        int col;
        if (fDD.getInt(6) == 1) {
            col = 3;
        } else {
            col = 5;
        }
        rg->fModel->setData(r, col, rg->fModel->data(r, col).toDouble() + fDD.getDouble(3));
        rg->fModel->setData(r, col + 1, rg->fModel->data(r, col + 1).toDouble() + fDD.getDouble(5));
    }

    where = "";
    if (!ui->leStore->isEmpty()) {
        where += " and b.f_store in (" + ui->leStore->fHiddenText + ") ";
    }
    if (!ui->leGoods->isEmpty()) {
        where += " and b.f_material in (" + ui->leGoods->fHiddenText + ") ";
    }
    query = "select sum(b.f_qty*b.f_sign) as f_qty, "
            "sum(b.f_total)/sum(b.f_qty) as f_price, sum(b.f_total*b.f_sign) as f_total "
            "from r_body b "
            "left join r_store s on s.f_id=b.f_store "
            "left join r_dish d on d.f_id=b.f_material "
            "left join r_docs bd on bd.f_id=b.f_doc "
            "where bd.f_date<=" + ui->wd->ds1() + " and bd.f_state=1 " + where ;

    fDD.exec(query);
    fDD.nextRow();
    if (rg->fModel->rowCount() > 0) {
        rg->fModel->setData(0, 1, fDD.getValue(0));
        rg->fModel->setData(0, 2, fDD.getValue(2));
    }

    for (int i = 0; i < rg->fModel->rowCount(); i++) {
        rg->fModel->setData(i, 7, rg->fModel->data(i, 1, Qt::EditRole).toDouble()
                            + rg->fModel->data(i, 3, Qt::EditRole).toDouble()
                            - rg->fModel->data(i, 5, Qt::EditRole).toDouble());
        rg->fModel->setData(i, 8, rg->fModel->data(i, 2, Qt::EditRole).toDouble()
                            + rg->fModel->data(i, 4, Qt::EditRole).toDouble()
                            - rg->fModel->data(i, 6, Qt::EditRole).toDouble());
        if (i < rg->fModel->rowCount() - 1) {
            rg->fModel->setData(i + 1, 1, rg->fModel->data(i, 7, Qt::EditRole));
            rg->fModel->setData(i + 1, 2, rg->fModel->data(i, 8, Qt::EditRole));
        }
    }

    QList<int> cols;
    cols << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8;
    QList<double> vals;
    rg->fModel->sumOfColumns(cols, vals);
    if (vals.count() > 0 && rg->fModel->rowCount() > 0) {
        vals[0] = rg->fModel->data(0, 1, Qt::EditRole).toDouble();
        vals[1] = rg->fModel->data(0, 2, Qt::EditRole).toDouble();
        vals[6] = vals[0] + vals[2] - vals[4];
        vals[7] = vals[1] + vals[3] - vals[5];
        rg->setTblTotalData(cols, vals);
    }

    for (int i = rg->fModel->rowCount() - 1; i > -1; i--) {
        if (rg->fModel->data(i, 3, Qt::EditRole).toDouble() < 0.001 && rg->fModel->data(i, 5, Qt::EditRole).toDouble() < 0.001) {
            rg->fModel->removeRow(i);
        }
    }
}

void FTStoreReport::setParams(const QString &store, const QString &goods)
{
    ui->leStore->setInitialValue(store);
    ui->leGoods->setInitialValue(goods);
    apply(fReportGrid);
}