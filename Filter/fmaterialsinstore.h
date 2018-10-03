#ifndef FMATERIALSINSTORE_H
#define FMATERIALSINSTORE_H

#include "wfilterbase.h"

namespace Ui {
class FMaterialsInStore;
}

class FMaterialsInStore : public WFilterBase
{
    Q_OBJECT

public:
    explicit FMaterialsInStore(QWidget *parent = 0);
    ~FMaterialsInStore();
    virtual QWidget *firstElement();
    virtual QString reportTitle();
    virtual void apply(WReportGrid *rg);
private:
    Ui::FMaterialsInStore *ui;
private slots:
    void doubleClickOnRow(const QList<QVariant> &row);
};

#endif // FMATERIALSINSTORE_H
