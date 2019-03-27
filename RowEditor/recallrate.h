#ifndef RECALLRATE_H
#define RECALLRATE_H

#include "roweditordialog.h"

namespace Ui {
class RECallRate;
}

class RECallRate : public RowEditorDialog
{
    Q_OBJECT

public:
    explicit RECallRate(QList<QVariant> &values, QWidget *parent = 0);
    ~RECallRate();

private slots:
    void on_btnCancel_clicked();

    void on_btnOK_clicked();

private:
    Ui::RECallRate *ui;
};

#endif // RECALLRATE_H
