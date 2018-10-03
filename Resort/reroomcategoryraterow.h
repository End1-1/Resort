#ifndef REROOMCATEGORYRATEROW_H
#define REROOMCATEGORYRATEROW_H

#include "roweditordialog.h"

namespace Ui {
class RERoomCategoryRateRow;
}

class RERoomCategoryRateRow : public RowEditorDialog
{
    Q_OBJECT

public:
    explicit RERoomCategoryRateRow(int category, QList<QVariant> &values, QWidget *parent = 0);
    ~RERoomCategoryRateRow();
    virtual void valuesToWidgets();
private slots:
    void on_btnCancel_clicked();
    void on_btnOk_clicked();

private:
    Ui::RERoomCategoryRateRow *ui;
    int fCategory;
};

#endif // REROOMCATEGORYRATEROW_H
