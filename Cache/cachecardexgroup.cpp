#include "cachecardexgroup.h"

CacheCardexGroup::CacheCardexGroup() :
    CacheBaseStruct()
{
    fLoadQuery = "select f_id, f_code from f_cardex_group";
    fUpdateQuery = "f_id=:f_id";
    fCacheId = cid_cardex_group;
    fSelectorTitle = QObject::tr("Cardex group");
    getSelectorTwoField();
    
}
