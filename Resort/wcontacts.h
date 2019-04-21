#ifndef WCONTACTS_H
#define WCONTACTS_H

#include "wreportgrid.h"

class WContacts : public WReportGrid
{
    Q_OBJECT

public:
    explicit WContacts(QWidget *parent = nullptr);
    ~WContacts();
protected:
    virtual void setupTab();
private slots:
    void removeContact();
};

#endif // WCONTACTS_H
