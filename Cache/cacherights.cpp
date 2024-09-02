#include "cacherights.h"
#include "cacheone.h"
#include "doubledatabase.h"

int CacheRights::fGroup = 0;

CacheRights::CacheRights() :
    CacheBaseStruct()
{
    fLoadQuery = "select f_right, f_flag, f_group from users_rights where f_flag=1 and f_group="
            + QString::number(fGroup);
    fCacheId = cid_user_rights;
}

bool CacheRights::check(int right)
{
    if (fGroup == 1) {
        return true;
    }
    CacheRights r;
    bool result = r.get(QString::number(right));
    return result;
}

bool CacheRights::checkGroup(int right, int user)
{
    if (right == 1) {
        return true;
    }
    DoubleDatabase dd;
    dd.open();
    dd[":f_id"] = user;
    dd.exec("select f_group from users where f_id=:f_id");
    dd.nextRow();
    dd[":f_group"] = dd.getInt(0);
    dd[":f_right"] = right;
    dd.exec("select f_right, f_flag, f_group from users_rights where f_flag=1 and f_group=:f_group and f_right=:f_right");
    return dd.nextRow();
}

