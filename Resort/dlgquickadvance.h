#ifndef DLGQUICKADVANCE_H
#define DLGQUICKADVANCE_H

#include "basewidget.h"

namespace Ui {
class DlgQuickAdvance;
}

class DlgQuickAdvance : public BaseWidget
{
    Q_OBJECT

public:
    explicit DlgQuickAdvance(QWidget *parent = nullptr);
    ~DlgQuickAdvance();
    virtual void setupTab();

private slots:
    void on_btnNew_clicked();

private:
    Ui::DlgQuickAdvance *ui;

private slots:
    void refresh();
    void on_btnRefresh_clicked();
    void on_tbl_doubleClicked(const QModelIndex &index);
};

#endif // DLGQUICKADVANCE_H
