#ifndef RERESTDISHTYPE_H
#define RERESTDISHTYPE_H

#include "roweditordialog.h"

namespace Ui {
class RERestDishType;
}

class RERestDishType : public RowEditorDialog
{
    Q_OBJECT

public:
    explicit RERestDishType(QList<QVariant> &values, QWidget *parent = 0);
    ~RERestDishType();
protected:
    virtual bool isDataCorrect();
private slots:
    void on_btnCancel_clicked();
    void on_btnOk_clicked();
    void on_btnBgColor_clicked();
    void on_btnTextColor_clicked();
private:
    Ui::RERestDishType *ui;
};

#endif // RERESTDISHTYPE_H
