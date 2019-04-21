#ifndef FTRACKCHANGES_H
#define FTRACKCHANGES_H

#include "wfilterbase.h"

namespace Ui {
class FTrackChanges;
}

class FTrackChanges : public WFilterBase
{
    Q_OBJECT
public:
    explicit FTrackChanges(QWidget *parent = nullptr);
    ~FTrackChanges();
    virtual void apply(WReportGrid *rg);
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();

private slots:
    void on_btnClearLog_clicked();

private:
    Ui::FTrackChanges *ui;
};

#endif // FTRACKCHANGES_H
