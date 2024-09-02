#include "dlgquickadvance.h"
#include "ui_dlgquickadvance.h"
#include "dlgprinttaxsm.h"
#include "cacheinvoiceitem.h"
#include "dlgquickadvanceapply.h"
#include "paymentmode.h"
#include "cachecreditcard.h"
#include "utils.h"
#include "dlgquickadvanceaction.h"

DlgQuickAdvance::DlgQuickAdvance(QWidget *parent) :
    BaseWidget (parent),
    ui(new Ui::DlgQuickAdvance)
{
    ui->setupUi(this);
    Utils::tableSetColumnWidths(ui->tbl, ui->tbl->columnCount(), 0, 100, 80, 150, 150, 80, 80, 80, 0, 200);
    refresh();
    connect(ui->wDate, SIGNAL(changed()), this, SLOT(refresh()));
}

DlgQuickAdvance::~DlgQuickAdvance()
{
    delete ui;
}

void DlgQuickAdvance::setupTab()
{
    setupTabTextAndIcon(tr("Temporary receipts"), ":/images/hourglass.png");
}

void DlgQuickAdvance::on_btnNew_clicked()
{
    DlgQuickAdvanceAction *d = new DlgQuickAdvanceAction(this);
    d->exec();
    if (d->taxNumber() > 0) {
        DoubleDatabase dd;
        dd[":f_date"] = QDate::currentDate();
        dd[":f_time"] = QTime::currentTime();
        dd[":f_type"] = d->type();
        dd[":f_operator"] = WORKING_USERNAME;
        dd[":f_amountcash"] = d->cash();
        dd[":f_amountcard"] = d->card();
        dd[":f_tax"] = d->taxNumber();
        dd[":f_json"] = d->fJson;
        dd[":f_comment"] = d->remarks();
        dd.insert("m_temp_advance", false);
        refresh();
    }
    d->deleteLater();
}

void DlgQuickAdvance::refresh()
{
    DoubleDatabase dd;
    dd[":f_date1"] = ui->wDate->d1();
    dd[":f_date2"] = ui->wDate->d2();
    dd.exec("select * from m_temp_advance where f_date between :f_date1 and :f_date2 order by f_date desc, f_time desc");
    Utils::fillTableWithData(ui->tbl, dd.fDbRows);
}

void DlgQuickAdvance::on_btnRefresh_clicked()
{
    refresh();
}

void DlgQuickAdvance::on_tbl_doubleClicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    DlgQuickAdvanceAction *d = new DlgQuickAdvanceAction(this);
    d->setJson(ui->tbl->toInt(index.row(), 7), ui->tbl->toString(index.row(), 8), ui->tbl->toString(index.row(), 9));
    d->exec();
    d->deleteLater();
}
