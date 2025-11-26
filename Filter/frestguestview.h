#ifndef FRESTGUESTVIEW_H
#define FRESTGUESTVIEW_H

#include "wfilterbase.h"

namespace Ui
{
class FRestGuestView;
}

class FRestGuestView : public WFilterBase
{
    Q_OBJECT
public:
    explicit FRestGuestView(QWidget *parent = nullptr);
    ~FRestGuestView();
    virtual void apply(WReportGrid *rg);
    virtual QWidget* firstElement();
    virtual QWidget* lastElement();
    virtual QString reportTitle();
private:
    Ui::FRestGuestView* ui;
};

#endif // FRESTGUESTVIEW_H
