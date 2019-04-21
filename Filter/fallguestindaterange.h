#ifndef FALLGUESTINDATERANGE_H
#define FALLGUESTINDATERANGE_H

#include "wfilterbase.h"

namespace Ui {
class FAllGuestInDateRange;
}

class FAllGuestInDateRange : public WFilterBase
{
    Q_OBJECT

public:
    explicit FAllGuestInDateRange(QWidget *parent = nullptr);
    ~FAllGuestInDateRange();
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual void apply(WReportGrid *rg);

private slots:
    void on_btnForward_clicked();
    void on_btnBack_clicked();

private:
    Ui::FAllGuestInDateRange *ui;
};

#endif // FALLGUESTINDATERANGE_H
