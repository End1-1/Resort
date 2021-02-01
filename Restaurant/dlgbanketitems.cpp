#include "dlgbanketitems.h"
#include "ui_dlgbanketitems.h"

DlgBanketItems::DlgBanketItems(QWidget *parent) :
    BaseExtendedDialogR(parent),
    ui(new Ui::DlgBanketItems)
{
    ui->setupUi(this);
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_rest"] = "1";
    fDD.exec("select f_id, f_en from f_invoice_item where f_rest=:f_rest order by 2");
    while (fDD.nextRow()) {
        QListWidgetItem *item = new QListWidgetItem(ui->lst);
        item->setSizeHint(QSize(0, 50));
        item->setData(Qt::UserRole, fDD.getValue(0));
        item->setText(fDD.getString(1));
        ui->lst->addItem(item);
    }
}

DlgBanketItems::~DlgBanketItems()
{
    delete ui;
}

bool DlgBanketItems::getItem(int &code, QString &name)
{
    bool result = false;
    DlgBanketItems *d = new DlgBanketItems();
    if (d->exec() == QDialog::Accepted) {
        result = true;
        code = d->ui->lst->currentItem()->data(Qt::UserRole).toInt();
        name = d->ui->lst->currentItem()->text();
    }
    delete d;
    return result;
}

void DlgBanketItems::on_btnCancel_clicked()
{
    reject();
}

void DlgBanketItems::on_btnOk_clicked()
{
    if (ui->lst->currentRow() < 0) {
        return;
    }
    accept();
}
