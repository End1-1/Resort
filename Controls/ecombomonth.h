#ifndef ECOMBOMONTH_H
#define ECOMBOMONTH_H

#include "ecomboboxcompleter.h"

class EComboMonth : public EComboBoxCompleter
{
public:
    EComboMonth(QWidget *parent = nullptr);
    virtual void setData();
};

#endif // ECOMBOMONTH_H
