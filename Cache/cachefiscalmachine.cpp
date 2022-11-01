#include "cachefiscalmachine.h"

CacheFiscalMachine::CacheFiscalMachine() :
    CacheBaseStruct()
{
    fLoadQuery = "select f_id,  f_name, f_ip, f_port, f_password from s_tax_map ";
    fUpdateQuery = "f_id=:f_id";
    fCacheId = cid_fiscalmachine;
    fSelectorTitle = QObject::tr("Fiscal machine");
    getSelectorWidths(5, 80, 180, 200, 100, 200);
    QStringList titles;
    titles << QObject::tr("Code")
           << QObject::tr("IP address")
           << QObject::tr("Name")
           << QObject::tr("Port")
           << QObject::tr("Password");
    getSelectorTitles(titles);
}
