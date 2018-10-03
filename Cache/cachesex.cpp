#include "cachesex.h"

CacheSex::CacheSex() :
    CacheBaseStruct()
{
    fCacheId = cid_sex;
    fLoadQuery = "select f_id, f_" + def_lang + " from f_guests_sex";
    fSelectorTitle = QObject::tr("Sex");
    getSelectorTwoField();

}
