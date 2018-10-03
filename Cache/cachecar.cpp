#include "cachecar.h"

CacheCar::CacheCar()
{
    fCacheId = cid_car;
    fLoadQuery = "select f_id, concat(f_model, ' ', f_class)  f_name from d_car_model";
    fUpdateQuery = "f_id=:f_id";
    fSelectorTitle = QObject::tr("Car model");
    getSelectorTwoField();
    
}
