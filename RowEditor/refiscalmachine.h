#ifndef REFISCALMACHINE_H
#define REFISCALMACHINE_H

#include "roweditordialog.h"

namespace Ui {
class REFiscalMachine;
}

class REFiscalMachine : public RowEditorDialog
{
    Q_OBJECT

public:
    explicit REFiscalMachine(QList<QVariant> &values, QWidget *parent = nullptr);
    ~REFiscalMachine();

private slots:
    void on_btnCancel_clicked();
    void on_btnOk_clicked();
    void on_btnRemove_clicked();

private:
    Ui::REFiscalMachine *ui;
};

#endif // REFISCALMACHINE_H
