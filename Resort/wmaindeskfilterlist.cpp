#include "wmaindeskfilterlist.h"
#include "ui_wmaindeskfilterlist.h"

WMainDeskFilterList::WMainDeskFilterList(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::WMainDeskFilterList)
{
    ui->setupUi(this);
}

WMainDeskFilterList::~WMainDeskFilterList()
{
    delete ui;
}

bool WMainDeskFilterList::filter(const QStringList &values, const QString &title, QString &out)
{
    WMainDeskFilterList *d = new WMainDeskFilterList(fPreferences.getDefaultParentForMessage());
    d->ui->lstValues->addItems(values);
    d->ui->lstValues->insertItem(0, tr("Clear"));
    d->setWindowTitle(title);
    int sel = 0;
    if (out.length() > 0) {
        sel = values.indexOf(out);
    }
    d->ui->lstValues->setCurrentRow(sel);
    for (int i = 0; i < d->ui->lstValues->count(); i++) {
        QListWidgetItem *item = d->ui->lstValues->item(i);
        item->setSizeHint(QSize(300, 30));
    }
    d->ui->lstValues->setCurrentRow(sel);
    QPoint p = QCursor::pos();
    d->move(p);
    bool result = d->exec() == QDialog::Accepted;
    if (result) {
        out = d->ui->lstValues->currentItem()->text();
    }
    return result;
}

void WMainDeskFilterList::on_lstValues_itemClicked(QListWidgetItem *item)
{
    Q_UNUSED(item);
    if (ui->lstValues->row(item) == 0) {
        item->setText("");
    }
    accept();
}
