#include "cachetransferfromcl.h"

CacheTransferFromCL::CacheTransferFromCL()
{
    fCacheId = cid_transfer_fromcl;
    fLoadQuery = "select m.f_cityLedger, c.f_name, sum(m.f_amountAmd*f_sign) as amount from m_register m "
            "inner join f_city_ledger c on c.f_id=m.f_cityLedger "
            "where f_canceled=0 :cond "
            "group by 1, 2 "
            "having sum(m.f_amountAmd*f_sign) < 0 ";
    fUpdateQuery = " and m.f_cityLedger=:f_id";
    fReplaceUpdateQuery = ":cond";
    fSelectorTitle = QObject::tr("City ledger balance");
    getSelectorWidths(3, 80, 200, 80);
    QStringList titles;
    titles << QObject::tr("Code")
           << QObject::tr("Name")
           << QObject::tr("Amount");
    getSelectorTitles(titles);
}
