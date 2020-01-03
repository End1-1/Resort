#include "eyearcombo.h"
#include "cacheyear.h"

EYearCombo::EYearCombo(QWidget *parent) :
    EQComboBox(parent)
{
    setCache(cid_serv_year);
    setIndexForData(QDate::currentDate().year());
}
