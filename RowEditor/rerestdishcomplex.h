#ifndef RERESTDISHCOMPLEX_H
#define RERESTDISHCOMPLEX_H

#include "roweditordialog.h"

namespace Ui {
class RERestDishComplex;
}

class RERestDishComplex : public RowEditorDialog
{
    Q_OBJECT

public:
    explicit RERestDishComplex(QList<QVariant> &values, QWidget *parent = 0);
    ~RERestDishComplex();
    virtual void callback(int sel, const QString &code);
    virtual void valuesToWidgets();
    virtual void clearWidgets();
private slots:
    void removeRow(int row);
    void on_btnCancel_clicked();
    void on_btnOK_clicked();
    void on_btnAdd_clicked();

private:
    Ui::RERestDishComplex *ui;
    void countTotal();
};

#endif // RERESTDISHCOMPLEX_H
