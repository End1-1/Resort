#ifndef FROOMSTATE_H
#define FROOMSTATE_H

#include "wfilterbase.h"

namespace Ui {
class FRoomState;
}

class FRoomState : public WFilterBase
{
    Q_OBJECT

public:
    explicit FRoomState(QWidget *parent = nullptr);
    ~FRoomState();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual QString reportTitle();
    virtual void apply(WReportGrid *rg);
    static void openReport();

private slots:
    void on_btnDateLeft_clicked();
    void on_btnDateRight_clicked();

private:
    Ui::FRoomState *ui;
};

#endif // FROOMSTATE_H
