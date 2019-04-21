#include "fcallrates.h"
#include "ui_fcallrates.h"
#include "wreportgrid.h"
#include "recallrate.h"

FCallRates::FCallRates(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FCallRates)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Call rates"), ":/images/phone.png");
    fReportGrid->fRowEditorDialog = new RECallRate(fReportGrid->fRowValues, this);
}

FCallRates::~FCallRates()
{
    delete ui;
}

QString FCallRates::reportTitle()
{
    return tr("Call rates");
}

QWidget *FCallRates::firstElement()
{
    return this;
}

QWidget *FCallRates::lastElement()
{
    return this;
}

void FCallRates::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(0, "", tr("Id"))
            .setColumn(50, "", tr("Direction"))
            .setColumn(50, "", tr("Local"))
            .setColumn(200, "", tr("Area"))
            .setColumn(100, "", tr("Code"))
            .setColumn(100, "", tr("Rate"));
    rg->fModel->setSqlQuery("select f_id, f_direction, f_local, f_area, f_code, f_rate from f_call_rate");
    rg->fModel->apply(rg);
}
