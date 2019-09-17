#ifndef REROOMBED_H
#define REROOMBED_H

#include "roweditordialog.h"

namespace Ui {
class RERoomBed;
}

class RERoomBed : public RowEditorDialog
{
    Q_OBJECT

public:
    explicit RERoomBed(QList<QVariant> &values, QWidget *parent = 0);
    ~RERoomBed();

private slots:
    void on_btnCancel_clicked();

    void on_btnOk_clicked();

private:
    Ui::RERoomBed *ui;

    // RowEditorDialog interface
protected:
    void valuesToWidgets();
};

#endif // REROOMBED_H
