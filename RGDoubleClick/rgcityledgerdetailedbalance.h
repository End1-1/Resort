#ifndef RGCITYLEDGERDETAILEDBALANCE_H
#define RGCITYLEDGERDETAILEDBALANCE_H

#include "rgdoubleclickdelegate.h"

class RGCityLedgerDetailedBalance : public RGDoubleClickDelegate
{
public:
    RGCityLedgerDetailedBalance(QObject *parent = nullptr);
    virtual void doubleClick(TableModel *t, int row);
};

#endif // RGCITYLEDGERDETAILEDBALANCE_H
