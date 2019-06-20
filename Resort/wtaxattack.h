#ifndef WTAXATTACK_H
#define WTAXATTACK_H

#include "basewidget.h"

namespace Ui {
class WTaxAttack;
}

class WTaxAttack : public BaseWidget
{
    Q_OBJECT

public:
    explicit WTaxAttack(QWidget *parent = nullptr);
    ~WTaxAttack();
    virtual void setup();

private slots:
    void checkboxClicked(bool v);
    void checkAll();
    void uncheckAll();
    void on_btnRefresh_clicked();
    void on_tbl_doubleClicked(const QModelIndex &index);
    void on_leSearch_textChanged(const QString &arg1);
    void on_leInvoice_returnPressed();
    void on_tbl_customContextMenuRequested(const QPoint &pos);
    void on_btnPrintTax_clicked();

private:
    Ui::WTaxAttack *ui;
    void countAmounts();
    void setCheckboxChecked(bool v);
};

#endif // WTAXATTACK_H
