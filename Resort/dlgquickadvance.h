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
    void cancelRow();
    void applyRow();
    void on_btnPrint_clicked();
    void on_btnJustAppend_clicked();
    void on_leCard_textChanged(const QString &arg1);
    void on_leCash_textChanged(const QString &arg1);

private:
    Ui::DlgQuickAdvance *ui;
    void appendRow(const QString &tax);
    void countTotal();
};

#endif // DLGQUICKADVANCE_H
