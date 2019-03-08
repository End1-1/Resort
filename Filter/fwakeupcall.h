#ifndef FWAKEUPCALL_H
#define FWAKEUPCALL_H

#include "wfilterbase.h"

namespace Ui {
class FWakeupCall;
}

class FWakeupCall : public WFilterBase
{
    Q_OBJECT

public:
    explicit FWakeupCall(QWidget *parent = 0);
    ~FWakeupCall();
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual void apply(WReportGrid *rg);
private:
    Ui::FWakeupCall *ui;

private slots:
    void openDialog(const QList<QVariant> &values);
};

#endif // FWAKEUPCALL_H
