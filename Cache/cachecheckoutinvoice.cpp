#include "cachecheckoutinvoice.h"
#include "preferences.h"

QDate CheckoutMinDate = QDate::currentDate().addDays(-365);

CacheCheckoutInvoice::CacheCheckoutInvoice() :
    CacheBaseStruct()
{
    fCurrPos = -1;
    fLoadQuery = "select r.f_invoice, r.f_INVOICE, r.f_room, g.guest, r.f_startDate, r.f_endDate, "
            "i.amount, u.f_username, r.f_id as f_reservation "
            "from f_reservation r "
            "left join guests g on g.f_id=r.f_guest "
            "left join users u on u.f_Id=r.f_checkoutUser "
            "left join (select f_inv, sum(f_amountAmd) as amount from m_register m "
                "where m.f_finance=1 and m.f_canceled=0 and m.f_sign=1 "
                "group by 1) i on i.f_inv=r.f_invoice "
            "where r.f_endDate > ':date1' and r.f_state=3 :cond "
            "order by r.f_endDate desc ";
    QDate d = __preferences.getDb(def_working_day).toDate().addDays(-365);
    if (d < CheckoutMinDate) {
        d = CheckoutMinDate;
    }
    fLoadQuery.replace(":date1", d.toString(def_mysql_date_format));
    fReplaceUpdateQuery = ":cond";
    fUpdateQuery = " and r.f_invoice=:f_id";
    fCacheId = cid_checkout_invoice;
    fSelectorTitle = QObject::tr("Checkout invoices");
    getSelectorWidths(8, 0, 80, 80, 200, 120, 120, 120, 200);
    QStringList titles;
    titles << QObject::tr("Code")
           << QObject::tr("Name")
           << QObject::tr("Room")
           << QObject::tr("Guest")
           << QObject::tr("Entry")
           << QObject::tr("Departure")
           << QObject::tr("Amount")
           << QObject::tr("Operator");
    getSelectorTitles(titles);
    
}

void CacheCheckoutInvoice::next()
{
    fCurrPos++;
}

void CacheCheckoutInvoice::prev()
{
    fCurrPos--;
}
