#ifndef RERESTHALL_H
#define RERESTHALL_H

#include "roweditordialog.h"

namespace Ui {
class RERestHall;
}

class RERestHall : public RowEditorDialog
{
    Q_OBJECT

public:
    explicit RERestHall(QList<QVariant> &values, QWidget *parent = 0);
    ~RERestHall();
protected:
    virtual bool isDataCorrect();
private slots:
    void on_btnCancel_clicked();
    void on_btnOk_clicked();
private:
    Ui::RERestHall *ui;
};

#endif // RERESTHALL_H
