#include "cacheguest.h"

CacheGuest::CacheGuest() :
    CacheBaseStruct()
{
    fLoadQuery = "select g.f_id, concat(g.f_title, ' ', g.f_firstName, ' ', g.f_lastName) as f_fullName, g.f_title,  "
            "g.f_nation, n.f_name as f_natFull, g.f_passport, g.f_firstName, g.f_lastName "
            "from f_guests g "
            "left join f_nationality n on n.f_short=g.f_nation ";
    fUpdateQuery = "g.f_id=:f_id";
    fCacheId = cid_guest;
    fSelectorTitle = QObject::tr("Guests");
    getSelectorWidths(8, 80, 300, 50, 50, 100, 100, 0, 0);
    QStringList titles;
    titles << QObject::tr("Code")
           << QObject::tr("Name")
           << QObject::tr("Title")
           << QObject::tr("Nation")
           << QObject::tr("Nation")
           << QObject::tr("Passport")
           << QObject::tr("First name")
           << QObject::tr("Last name");
    getSelectorTitles(titles);
    
}
