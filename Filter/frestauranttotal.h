#ifndef FRESTAURANTTOTAL_H
#define FRESTAURANTTOTAL_H

#include "wfilterbase.h"
#include "ptextrect.h"
#include "pimage.h"
#include "pprintpreview.h"

namespace Ui {
class FRestaurantTotal;
}

class WReportGrid;

class FRestaurantTotal : public WFilterBase
{
    Q_OBJECT

public:
    explicit FRestaurantTotal(QWidget *parent = nullptr);
    ~FRestaurantTotal();
    virtual void apply(WReportGrid *rg);
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    QString reportTitle();
    static void open();
    static void removeVoucher(const QString &id);

private:
    Ui::FRestaurantTotal *ui;
    void printNewPage(int &top, int &left, int &page, PPrintPreview *pp, PPrintScene *&ps, int nextHeight = 0);

private slots:
    void printReceipt();
    void removeOrder();
    void removePermanently();
    void on_btnOrdersSubtotal_clicked();
    void doubleClick(const QList<QVariant> &row);
    void on_btnPrevDate_clicked();
    void on_btnNextDate_clicked();
};

#endif // FRESTAURANTTOTAL_H
