#include "cacheguesttitle.h"

CacheGuestTitle::CacheGuestTitle()
{
    fLoadQuery = "select f_" + def_lang + ", f_" + def_lang + " from f_guests_title";
    fUpdateQuery = "f_id=:f_id";
    fCacheId = cid_guest_title;
    fSelectorTitle = QObject::tr("Guest title");
    getSelectorTwoField();
    
}
