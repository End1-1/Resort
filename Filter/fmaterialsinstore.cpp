#include "fmaterialsinstore.h"
#include "ui_fmaterialsinstore.h"
#include "cachereststore.h"
#include "cachedish.h"
#include "wreportgrid.h"
#include "ftstorereport.h"

#define SEL_DISH 1

FMaterialsInStore::FMaterialsInStore(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FMaterialsInStore)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Materials in store"), ":/images/storage.png");
    ui->leStore->setSelector(this, cache(cid_rest_store), ui->leStore);
    ui->leMaterial->setSelector(this, cache(cid_dish), ui->leMaterial);
    connect(fReportGrid, SIGNAL(doubleClickOnRow(QList<QVariant>)), this, SLOT(doubleClickOnRow(QList<QVariant>)));
}

FMaterialsInStore::~FMaterialsInStore()
{
    delete ui;
}

QWidget *FMaterialsInStore::firstElement()
{
    return ui->deDate;
}

QString FMaterialsInStore::reportTitle()
{
    return QString("%1, %2")
            .arg("Materials in the store")
            .arg(ui->deDate->text());
}

void FMaterialsInStore::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(150, "", tr("Store"))
            .setColumn(300, "", tr("Material"))
            .setColumn(100, "", tr("Qty"))
            .setColumn(100, "", tr("Price"))
            .setColumn(100, "", tr("Total"));
    QString where;
    if (!ui->leStore->isEmpty()) {
        where += " and b.f_store in (" + ui->leStore->fHiddenText + ") ";
    }
    if (!ui->leMaterial->isEmpty()) {
        where += " and b.f_material in (" + ui->leMaterial->fHiddenText + ") ";
    }
    QString query = "select s.f_name as f_store, d.f_en as f_material, sum(b.f_qty*b.f_sign) as f_qty, "
            "sum(b.f_total)/sum(b.f_qty) as f_price, sum(b.f_total*b.f_sign) as f_total "
            "from r_body b "
            "left join r_store s on s.f_id=b.f_store "
            "left join r_dish d on d.f_id=b.f_material "
            "left join r_docs bd on bd.f_id=b.f_doc "
            "where bd.f_date<=" + ui->deDate->dateMySql() + " and bd.f_state=1 " + where +
            "group by 1, 2 ";
    rg->fModel->setSqlQuery(query);
    rg->fModel->apply(rg);
    QList<int> col;
    col << 2 << 4;
    QList<double> val;
    rg->fModel->sumOfColumns(col, val);
    rg->setTblTotalData(col, val);
}

void FMaterialsInStore::doubleClickOnRow(const QList<QVariant> &row)
{
    if (row.count() == 0) {
        return;
    }
    FTStoreReport *f = FTStoreReport::openFilterReport<FTStoreReport, WReportGrid>();
    f->setParams(ui->leStore->fHiddenText, row.at(1).toString());
}

