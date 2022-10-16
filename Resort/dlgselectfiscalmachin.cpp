#include "dlgselectfiscalmachin.h"
#include "ui_dlgselectfiscalmachin.h"
#include "taxhelper.h"
#include <QListWidgetItem>

DlgSelectFiscalMachin::DlgSelectFiscalMachin(QSet<int> machines, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgSelectFiscalMachin)
{
    ui->setupUi(this);
    fSelectedMachine = 0;
    for (int i: machines) {
        TaxPoint tp = TaxHelper::fInstance->fTaxPoints[i];
        auto *l = new QListWidgetItem(ui->lst);
        l->setSizeHint(QSize(200, 30));
        l->setText(tp.name);
        l->setData(Qt::UserRole, tp.id);
        ui->lst->addItem(l);
    }
    auto *l = new QListWidgetItem(ui->lst);
    l->setSizeHint(QSize(200, 30));
    l->setText(tr("Cancel"));
    l->setData(Qt::UserRole, 0);
    ui->lst->addItem(l);
}

DlgSelectFiscalMachin::~DlgSelectFiscalMachin()
{
    delete ui;
}

void DlgSelectFiscalMachin::on_lst_itemClicked(QListWidgetItem *item)
{
    fSelectedMachine = item->data(Qt::UserRole).toInt();
    accept();
}
