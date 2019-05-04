#ifndef DLGCARDEX_H
#define DLGCARDEX_H

#include "roweditordialog.h"

namespace Ui {
class DlgCardex;
}

class DlgCardex : public RowEditorDialog
{
    Q_OBJECT

public:
    explicit DlgCardex(QList<QVariant> &values, QWidget *parent = nullptr);
    ~DlgCardex();
    virtual void setValues();

protected:
    virtual bool isDataCorrect();

private slots:
    void on_btnCancel_clicked();
    void on_btnOk_clicked();
    void on_btnRemove_clicked();

private:
    Ui::DlgCardex *ui;
};

#endif // DLGCARDEX_H
