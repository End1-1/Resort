#ifndef FROOMSTATES_H
#define FROOMSTATES_H

#include "wfilterbase.h"

namespace Ui {
class FRoomStates;
}

class FRoomStates : public WFilterBase
{
    Q_OBJECT

public:
    explicit FRoomStates(QWidget *parent = nullptr);
    ~FRoomStates();
    virtual void apply(WReportGrid *rg) override;
    virtual QWidget *firstElement() override;
    virtual QWidget *lastElement() override;
    virtual QString reportTitle() override;

private:
    Ui::FRoomStates *ui;
    QColor getRowColor(int row) const;

private slots:
    void dbClick(const QList<QVariant> &row);
    void clickOnRow(int row);
    void roomUpdated(int cacheid, const QString &name);

};

#endif // FROOMSTATES_H
