#include "cacheresthall.h"

CacheRestHall::CacheRestHall() :
    CacheBaseStruct()
{
    fCacheId = cid_rest_hall;
    fLoadQuery = "select f_id, f_name, f_defaultMenu from r_hall";
    fSelectorTitle = QObject::tr("Hall");
    getSelectorTwoField();

}
