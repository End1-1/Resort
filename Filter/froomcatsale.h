#ifndef FROOMCATSALE_H
#define FROOMCATSALE_H

#include "wfilterbase.h"

namespace Ui {
class FRoomCatSale;
}

class FRoomCatSale : public WFilterBase
{
    Q_OBJECT

public:
    explicit FRoomCatSale(QWidget *parent = nullptr);
    ~FRoomCatSale();
    virtual QString reportTitle() override;
    virtual void apply(WReportGrid *rg) override;
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();

private:
    Ui::FRoomCatSale *ui;

private slots:
    void doubleClickOnRow(const QList<QVariant> &vals);
};

#endif // FROOMCATSALE_H
