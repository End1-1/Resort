#ifndef WGUEST_H
#define WGUEST_H

#include "roweditordialog.h"

namespace Ui {
class WGuest;
}

class WGuest : public RowEditorDialog
{
    Q_OBJECT

public:
    static WGuest *guest(QList<QVariant> &values, bool noCheckNation = true);
    ~WGuest();
private slots:
    void on_btnCancel_clicked();
    void on_btnOk_clicked();
    void on_btnRemove_clicked();

private:
    explicit WGuest(QList<QVariant> &values, QWidget *parent = 0);
    Ui::WGuest *ui;
    bool fNoCheckNation;
};

#endif // WGUEST_H
