#include "wcityledger.h"
#include "ui_wcityledger.h"
#include "cachecityledger.h"
#include "dbmregister.h"

static const int hint_cl = 1;

WCityLedger::WCityLedger(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WCityLedger)
{
    ui->setupUi(this);
    ui->leCL->setSelector(this, cache(cid_city_ledger), ui->leCLName, hint_cl);
}

WCityLedger::~WCityLedger()
{
    delete ui;
}

void WCityLedger::callback(int sel, const QString &code)
{
    Q_UNUSED(code);
    switch (sel) {
    case hint_cl:
        setBalance();
        break;
    }
}

void WCityLedger::clear()
{
    ui->leCL->setInitialValue("");
}

void WCityLedger::setDBMRegister(DBMRegister *r)
{
    r->setleCityLedger(ui->leCL, ui->leCLName);
}

int WCityLedger::cityLedger()
{
    return ui->leCL->asInt();
}

QString WCityLedger::cityLedgerName() const
{
    return ui->leCLName->text();
}

void WCityLedger::setCL(int code)
{
    ui->leCL->setInitialValue(code);
}

void WCityLedger::clearSelector()
{
    ui->leCL->clearSelector();
}

void WCityLedger::initSelector()
{
    ui->leCL->setSelector(this, cache(cid_city_ledger), ui->leCLName, hint_cl);
}

void WCityLedger::setBalance()
{
    ui->leBalance->clear();
    if (ui->leCL->asInt() == 0) {
        return;
    }
    DoubleDatabase dd;
    dd[":f_cityledger"] = ui->leCL->asInt();
#ifdef _METROPOL_
    dd.exec("select sum(m.f_amountamd*f_sign) from m_register m \
             where f_cityLedger=:f_cityledger and f_canceled=0 and f_finance=1 ");
#else
    if (!dd.exec("select sum(if(m.f_source in ('CH', 'PS', 'PE', 'RF', 'RM'), m.f_amountamd, if(m.f_source in ('RV','CR', 'AV', 'DS'), \
             m.f_amountAmd*m.f_sign*-1, m.f_amountAmd*m.f_sign*1))) as f_amountamd from m_register m \
            where f_cityLedger=:f_cityledger and f_canceled=0 and f_finance=1 ")) {
        message_error(dd.fLastError);
    }
#endif
    if (dd.nextRow()) {
        ui->leBalance->setDouble(dd.getDouble(0));
    }
}
