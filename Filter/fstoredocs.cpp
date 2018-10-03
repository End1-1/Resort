#include "fstoredocs.h"
#include "ui_fstoredocs.h"
#include "wreportgrid.h"
#include "storedoc.h"
#include "cachestoredoc.h"
#include "cachestoredocstate.h"
#include "cachestorepartners.h"
#include "cachereststore.h"

#define SEL_DOC_STATE 1
#define SEL_DOC_TYPE 2
#define SEL_PARTNER 3

FStoreDocs::FStoreDocs(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FStoreDocs)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Documents in store"), ":/images/storage.png");
    fReportGrid->addToolBarButton(":/images/copy.png", tr("Copy"), SLOT(copyDoc()), this)->setFocusPolicy(Qt::NoFocus);
    connect(fReportGrid, SIGNAL(doubleClickOnRow(QList<QVariant>)), this, SLOT(doubleClicked(QList<QVariant>)));

    ui->leState->setSelector(this, cache(cid_store_doc_state), ui->leState);
    ui->leDocType->setSelector(this, cache(cid_store_doc_type), ui->leDocType);
    ui->leState->setSelector(this, cache(cid_rest_store), ui->leStore);
    ui->lePartner->setSelector(this, cache(cid_store_partners), ui->lePartner);
}

FStoreDocs::~FStoreDocs()
{
    delete ui;
}

QWidget *FStoreDocs::firstElement()
{
    return ui->deStart;
}

QString FStoreDocs::reportTitle()
{
    return QString("%1 %2-%3")
            .arg(tr("Documents in store"))
            .arg(ui->deStart->text())
            .arg(ui->deEnd->text());
}

void FStoreDocs::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(120, "", tr("Document number"))
            .setColumn(120, "", tr("Date"))
            .setColumn(220, "", tr("Type"))
            .setColumn(120, "", tr("State"))
            .setColumn(100, "", tr("Amount"))
            .setColumn(100, "", tr("Invoice"))
            .setColumn(150, "", tr("Invoice date"))
            .setColumn(150, "", tr("Operator"))
            .setColumn(150, "", tr("Registered"))
            .setColumn(400, "", tr("Comment"));
    QString query = "select distinct(d.f_id) as f_id, d.f_date, dt.f_name, ds.f_name, "
            "d.f_amount, d.f_inv, d.f_invDate, u.f_username, d.f_fullDate, d.f_remarks "
            "from r_docs d "
            "left join r_doc_type dt on dt.f_id=d.f_type "
            "left join r_doc_state ds on ds.f_id=d.f_state "
            "left join users u on u.f_id=d.f_op ";
    QString where = "where d.f_date between " + ui->deStart->dateMySql() + " and " + ui->deEnd->dateMySql();
    if (!ui->leDocType->isEmpty()) {
        where += " and d.f_type in (" + ui->leDocType->fHiddenText + ") ";
    }
    if (!ui->leState->isEmpty()) {
        where += " and d.f_state in (" + ui->leState->fHiddenText + ") ";
    }
    if (!ui->lePartner->isEmpty()) {
        where += " and d.f_partner in (" + ui->lePartner->fHiddenText + ") ";
    }
    if (!ui->leStore->isEmpty()) {
        where += " and b.f_store in (" + ui->leStore->fHiddenText + ") ";
        query += " left join r_body b on b.f_doc=d.f_id ";
    }
    rg->fModel->setSqlQuery(query + where);
    rg->fModel->apply(rg);
    QList<int> col;
    col << 4;
    QList<double> val;
    rg->fModel->sumOfColumns(col, val);
    rg->setTblTotalData(col, val);
}

void FStoreDocs::openReport()
{
    openFilterReport<FStoreDocs, WReportGrid>();
}

void FStoreDocs::copyDoc()
{
    QList<QVariant> out;
    int row = fReportGrid->fillRowValuesOut(out);
    if (row < 0) {
            message_error(tr("Nothing is seleted."));
            return;
    }
    StoreDoc *d = addTab<StoreDoc>();
    d->copyDoc(out.at(0).toString());
}

void FStoreDocs::doubleClicked(const QList<QVariant> &row)
{
    if (row.count() == 0) {
        message_error(tr("Nothing is seleted."));
        return;
    }
    StoreDoc *d = addTab<StoreDoc>();
    d->loadDoc(row.at(0).toString());
}

void FStoreDocs::on_btnDateLeft_clicked()
{
    ui->deStart->setDate(ui->deStart->date().addDays(-1));
    ui->deEnd->setDate(ui->deEnd->date().addDays(-1));
    apply(fReportGrid);
}

void FStoreDocs::on_btnDateRight_clicked()
{
    ui->deStart->setDate(ui->deStart->date().addDays(1));
    ui->deEnd->setDate(ui->deEnd->date().addDays(1));
    apply(fReportGrid);
}
