#ifndef REINVOICEITEM_H
#define REINVOICEITEM_H

#include "roweditordialog.h"

namespace Ui {
class REInvoiceItem;
}

class REInvoiceItem : public RowEditorDialog
{
    Q_OBJECT

public:
    explicit REInvoiceItem(QList<QVariant> &values, QWidget *parent = 0);
    ~REInvoiceItem();
    virtual void valuesToWidgets();
private slots:
    void on_tnCancel_clicked();

    void on_btnOk_clicked();

private:
    Ui::REInvoiceItem *ui;
    QMap<QString, int> fTaxMap;
};

#endif // REINVOICEITEM_H
