#include "fstoremovement.h"
#include "ui_fstoremovement.h"
#include "wreportgrid.h"
#include "storedoc.h"
#include "cachereststore.h"
#include "cachestoredoc.h"
#include "cachedish.h"
#include "cachestorepartners.h"

#define SEL_DOC_TYPE 1
#define SEL_DISH 2

FStoreMovement::FStoreMovement(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FStoreMovement)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Store movement"), ":/images/storage.png");
    connect(fReportGrid, SIGNAL(doubleClickOnRow(QList<QVariant>)), this, SLOT(doubleClicked(QList<QVariant>)));
    ui->leAction->setSelector(this, cache(cid_store_doc_type), ui->leAction);
    ui->leStore->setSelector(this, cache(cid_rest_store), ui->leStore);
    ui->leMaterial->setSelector(this, cache(cid_dish), ui->leMaterial);
    ui->lePartner->setSelector(this, cache(cid_store_partners), ui->lePartner);
}

FStoreMovement::~FStoreMovement()
{
    delete ui;
}

QWidget *FStoreMovement::firstElement()
{
    return ui->deStart;
}

QString FStoreMovement::reportTitle()
{
    return QString("%1, %2-%3")
            .arg(tr("Store movement"))
            .arg(ui->deStart->text())
            .arg(ui->deEnd->text());
}

void FStoreMovement::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(100, "", tr("Document"))
            .setColumn(100, "", tr("Date"))
            .setColumn(120, "", tr("Action"))
            .setColumn(150, "", tr("Store"))
            .setColumn(200, "", tr("Material"))
            .setColumn(80, "", tr("Qty"))
            .setColumn(80, "", tr("Price"))
            .setColumn(80, "", tr("Total"));
    QString query = "select b.f_doc, d.f_date, dt.f_name as f_action, s.f_name as f_store, "
            "m.f_en as f_material, b.f_qty * b.f_sign as f_qty, b.f_price, b.f_total * b.f_sign as f_total "
            "from r_body b "
            "left join r_docs d on d.f_id=b.f_doc "
            "left join r_doc_type dt on dt.f_id=d.f_type "
            "left join r_store s on s.f_id=b.f_store "
            "left join r_dish m on m.f_id=b.f_material "
            "where d.f_date between " + ui->deStart->dateMySql() + " and " + ui->deEnd->dateMySql() +
            " and d.f_state=1 ";
    if (!ui->leAction->isEmpty()) {
        query += " and d.f_type in (" + ui->leAction->fHiddenText + ") ";
    }
    if (!ui->leStore->isEmpty()) {
        query += " and b.f_store in (" + ui->leStore->fHiddenText + ") ";
    }
    if (!ui->leMaterial->isEmpty()) {
        query += " and b.f_material in (" + ui->leMaterial->fHiddenText + ") ";
    }
    if (!ui->lePartner->isEmpty()) {
        query += " and d.f_partner in (" + ui->lePartner->fHiddenText + ") ";
    }
    rg->fModel->setSqlQuery(query);
    rg->fModel->apply(rg);
    QList<int> col;
    col << 5 << 7;
    QList<double> val;
    rg->fModel->sumOfColumns(col, val);
    rg->setTblTotalData(col, val);
}

void FStoreMovement::doubleClicked(const QList<QVariant> &row)
{
    if (row.count() == 0) {
        message_error(tr("Nothing was selected"));
        return;
    }
    StoreDoc *d = addTab<StoreDoc>();
    d->loadDoc(row.at(0).toString());
}

void FStoreMovement::on_btnDateLeft_clicked()
{
    ui->deStart->setDate(ui->deStart->date().addDays(-1));
    ui->deEnd->setDate(ui->deEnd->date().addDays(-1));
    apply(fReportGrid);
}

void FStoreMovement::on_btnDateRight_clicked()
{
    ui->deStart->setDate(ui->deStart->date().addDays(1));
    ui->deEnd->setDate(ui->deEnd->date().addDays(1));
    apply(fReportGrid);
}
