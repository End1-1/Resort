#ifndef WCITYLEDGERLIST_H
#define WCITYLEDGERLIST_H

#include "wreportgrid.h"

class WCityLedgerList : public WReportGrid
{
    Q_OBJECT
public:
    explicit WCityLedgerList(QWidget *parent = nullptr);
    virtual void setupTab() override;

private slots:
    void exportToJson();
    void importFromJson();
};

#endif // WCITYLEDGERLIST_H
