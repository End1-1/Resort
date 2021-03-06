#include "dlglist.h"
#include "ui_dlglist.h"

DlgList::DlgList(QWidget *parent) :
    BaseExtendedDialogR(parent),
    ui(new Ui::DlgList)
{
    ui->setupUi(this);
}

DlgList::~DlgList()
{
    delete ui;
}

bool DlgList::getValue(const QString &caption, QString &name, QVariant &result, const QString &sql)
{
    bool r = false;
    DlgList *d = new DlgList();
    d->ui->lbCaption->setText(caption);
    d->build(sql);
    if (d->exec() == QDialog::Accepted) {
        result = d->fResult;
        name = d->fName;
        r = true;
    }
    delete d;
    return r;
}

void DlgList::on_btnCancel_clicked()
{
    reject();
}

void DlgList::build(const QString &sql)
{
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.exec(sql);
    while (fDD.nextRow()) {
        QListWidgetItem *item = new QListWidgetItem(ui->lst);
        item->setData(Qt::UserRole, fDD.getValue(0));
        item->setText(fDD.getString(1));
        item->setSizeHint(QSize(50, 50));
        ui->lst->addItem(item);
    }
}

void DlgList::on_btnOk_clicked()
{
    QListWidgetItem *item = ui->lst->currentItem();
    if (!item) {
        return;
    }
    fName = item->text();
    fResult = item->data(Qt::UserRole);
    accept();
}
