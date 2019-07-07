#include "cachecardex.h"

CacheCardex::CacheCardex() :
    CacheBaseStruct()
{
    fCacheId = cid_cardex;
    fLoadQuery = "select c.f_cardex, c.f_name, c.f_vatMode, v.f_" + def_lang +","
              "c.f_commission, f_dateTo, f_bookingRequired, c.f_group "
              "from f_cardex c "
              "inner join f_vat_mode v on v.f_id=c.f_vatMode "
              "where f_dateTo > '" + fWorkingDate.toString(def_mysql_date_format) + "' :cond";
    fReplaceUpdateQuery = ":cond";
    fUpdateQuery = " and c.f_cardex=:f_id ";
    fSelectorTitle = QObject::tr("Cardex");
    getSelectorWidths(5, 80, 250, 100, 100, 120);
    QStringList titles;
    titles << QObject::tr("Code")
           << QObject::tr("Name")
           << QObject::tr("VAT")
           << QObject::tr("Commission")
           << QObject::tr("Valid to");
    getSelectorTitles(titles);
    
}
