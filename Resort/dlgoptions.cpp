#include "dlgoptions.h"
#include "ui_dlgoptions.h"

DlgOptions::DlgOptions(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgOptions)
{
    ui->setupUi(this);
    QString text;
    DoubleDatabase dd;
    dd.exec("select f_id, f_en from f_invoice_item where f_id in (" + fPreferences.getDb(def_rooming_list).toString() + ")");
    text += "ROOMING VOUCHERS: ";
    bool f = true;
    while (dd.nextRow()) {
        if (f) {
            text += ", ";
        } else {
            f = false;
        }
        text += QString("%1(%2)").arg(dd.getString(1)).arg(dd.getString(0));
    }
    text += "\r\n";
    f = true;
    text += "CANCELATION(PENALTY) VOUCHERS: ";
    dd.exec("select f_id, f_en from f_invoice_item where f_id in (" + fPreferences.getDb(def_penalty_list).toString() + ")");
    while (dd.nextRow()) {
        if (f) {
            text += ", ";
        } else {
            f = false;
        }
        text += QString("%1(%2)").arg(dd.getString(1)).arg(dd.getString(0));
    }
    text += "\r\n";
    ui->tb->setText(text);
}

DlgOptions::~DlgOptions()
{
    delete ui;
}

void DlgOptions::openWindow()
{
    auto *d = new DlgOptions(fPreferences.getDefaultParentForMessage());
    d->exec();
    delete d;
}
