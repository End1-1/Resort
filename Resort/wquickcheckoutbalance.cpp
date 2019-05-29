#include "wquickcheckoutbalance.h"
#include "ui_wquickcheckoutbalance.h"

WQuickCheckoutBalance::WQuickCheckoutBalance(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::WQuickCheckoutBalance)
{
    ui->setupUi(this);
}

WQuickCheckoutBalance::~WQuickCheckoutBalance()
{
    delete ui;
}
