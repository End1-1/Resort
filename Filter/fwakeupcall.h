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
    explicit FWakeupCall(QWidget *parent = nullptr);
    ~FWakeupCall();
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual void apply(WReportGrid *rg);

private:
    Ui::FWakeupCall *ui;

private slots:
    void openDialog(const QList<QVariant> &values);
};

#endif // FWAKEUPCALL_H
