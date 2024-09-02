#include "dlgreportbuildergroups.h"
#include "ui_dlgreportbuildergroups.h"
#include <QInputDialog>

DlgReportBuilderGroups::DlgReportBuilderGroups(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgReportBuilderGroups)
{
    ui->setupUi(this);
    DoubleDatabase fDD;
    fDD.exec("select f_id, f_name from serv_reports_group order by f_name");
    while (fDD.nextRow()) {
        QListWidgetItem *item = new QListWidgetItem(ui->lwList);
        item->setText(fDD.getString(1));
        item->setData(Qt::UserRole, fDD.getValue(0));
        ui->lwList->addItem(item);
    }
}

DlgReportBuilderGroups::~DlgReportBuilderGroups()
{
    delete ui;
}

void DlgReportBuilderGroups::on_btnClose_clicked()
{
    accept();
}

void DlgReportBuilderGroups::on_btnNew_clicked()
{
    QString name = QInputDialog::getText(this, tr("New name"), tr("Name"));
    if (name.isEmpty()) {
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_name"] = name;
    int id = fDD.insert("serv_reports_group");
    QListWidgetItem *item = new QListWidgetItem(ui->lwList);
    item->setText(name);
    item->setData(Qt::UserRole, id);
    ui->lwList->addItem(item);
}

void DlgReportBuilderGroups::on_btnEdit_clicked()
{
    QListWidgetItem *item = ui->lwList->currentItem();
    if (!item) {
        message_error(tr("Nothing is selected"));
        return;
    }
    QString name = QInputDialog::getText(this, tr("New name"), tr("Name"), QLineEdit::Normal, item->text());
    if (name.isEmpty()) {
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_name"] = name;
    fDD.update("serv_reports_group", where_id(item->data(Qt::UserRole).toInt()));
    item->setText(name);
    message_info(tr("Group name successfuly updated"));
}

void DlgReportBuilderGroups::on_btnRemove_clicked()
{
    QListWidgetItem *item = ui->lwList->currentItem();
    if (!item) {
        message_error(tr("Nothing is selected"));
        return;
    }
    if (message_confirm(tr("Confirm to delete selected group.<br><b>ALL REPORTS THATS ASSIGNED TO THIS GROUP WILL BE REMOVE TOO!</b>")) != QDialog::Accepted) {
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_group"] = item->data(Qt::UserRole);
    fDD.exec("delete from serv_reports where f_group=:f_group");
    fDD[":f_id"] = item->data(Qt::UserRole);
    fDD.exec("delete from serv_reports_group where f_id=:f_id");
    ui->lwList->removeItemWidget(item);
    message_info(tr("Group successfuly removed :("));
}
