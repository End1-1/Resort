#include "cacheone.h"
#include "cachebed.h"
#include "cacheactiveroom.h"
#include "cachecar.h"
#include "cachecardex.h"
#include "cachecardexgroup.h"
#include "cachecashdesk.h"
#include "cachecashdoc.h"
#include "cachecheckoutinvoice.h"
#include "cachecityledger.h"
#include "cachecladvance.h"
#include "cachecouponseria.h"
#include "cachecoupontype.h"
#include "cachecreditcard.h"
#include "cachecurrencies.h"
#include "cachedebtcostumer.h"
#include "cacheyear.h"
#include "cachedish.h"
#include "cacheactivegroup.h"
#include "cachedishstate.h"
#include "cachedocpayment.h"
#include "cachegroupreservations.h"
#include "cacheguest.h"
#include "cachefiscalmachine.h"
#include "cacheguesttitle.h"
#include "cacheinvoiceitem.h"
#include "cacheinvoiceitemgroup.h"
#include "cachemenudishes.h"
#include "cachenation.h"
#include "cacheorderstate.h"
#include "cachetransferfromcl.h"
#include "cachepaymentmode.h"
#include "cacheredreservation.h"
#include "cachereminderstate.h"
#include "cachereservation.h"
#include "cachereservationcardex.h"
#include "cachereservegroup.h"
#include "cachereservestate.h"
#include "cachereservestatus.h"
#include "cacherestdebtholder.h"
#include "cacherestdishmod.h"
#include "cacherestdishpart.h"
#include "cacherestdishtype.h"
#include "cacherestfullmenu.h"
#include "cacheresthall.h"
#include "cacherestmenu.h"
#include "cacherestprinters.h"
#include "cachereststore.h"
#include "cacheresttable.h"
#include "cacherights.h"
#include "cacheroom.h"
#include "cacheroomarrangment.h"
#include "cacheroomcategory.h"
#include "cacheroominventory.h"
#include "cacheroominventorystate.h"
#include "cacheroomstate.h"
#include "cacheroomview.h"
#include "cachesex.h"
#include "cachestoredoc.h"
#include "cachestoredocstate.h"
#include "cachestorepartners.h"
#include "cachetaxmap.h"
#include "cachetrackingtables.h"
#include "cacheusers.h"
#include "cacheusersgroups.h"
#include "cacheusersstate.h"
#include "cachevatmode.h"
#include "cachevaucher.h"
#include "trackcontrol.h"

QMap<int, CacheInstance*> CacheOne::fCacheOne;

CacheOne::CacheOne()
{

}

void CacheOne::clearAll()
{
    QMapIterator<int, CacheInstance*> it(fCacheOne);
    while (it.hasNext()) {
        it.next();
        it.value()->clear();
    }
    qDeleteAll(fCacheOne);
    fCacheOne.clear();
}

void CacheOne::updateCache(int cacheId, const QString &id)
{
    if (!fCacheOne.contains(cacheId)) {
        return;
    }
    CacheInstance *ci = cache(cacheId);
    ci->update(id);
}

CacheInstance *CacheOne::getCache(int id)
{
    if (fCacheOne.contains(id)) {
        return fCacheOne[id];
    }

    CacheInstance *result = nullptr;
    CacheBaseStruct *cbs = nullptr;
    switch (id) {
    case cid_bed:
        cbs = new CacheBed();
        break;
    case cid_active_room:
        cbs = new CacheActiveRoom();
        break;
    case cid_car:
        cbs = new CacheCar();
        break;
    case cid_cardex:
        cbs = new CacheCardex();
        break;
    case cid_cardex_group:
        cbs = new CacheCardexGroup();
        break;
    case cid_cash_desk:
        cbs = new CacheCashDesk();
        break;
    case cid_cash_doc:
        cbs = new CacheCashDoc();
        break;
    case cid_checkout_invoice:
        cbs = new CacheCheckoutInvoice();
        break;
    case cid_city_ledger:
        cbs = new CacheCityLedger();
        break;
    case cid_cache_cl_advance:
        cbs = new CacheCLAdvance();
        break;
    case cid_coupon_seria:
        cbs = new CacheCouponSeria();
        break;
    case cid_coupon_type:
        cbs = new CacheCouponType();
        break;
    case cid_credit_card:
        cbs = new CacheCreditCard();
        break;
    case cid_currencies:
        cbs = new CacheCurrencies();
        break;
    case cid_debt_costumer:
        cbs = new CacheDebtCostumer();
        break;
    case cid_dish:
        cbs = new CacheDish();
        break;
    case cid_dish_state:
        cbs = new CacheDishState();
        break;
    case cid_doc_payment:
        cbs = new CacheDocPayment();
        break;
    case cid_group_reservation:
        cbs = new CacheGroupReservations();
        break;
    case cid_guest:
        cbs = new CacheGuest();
        break;
    case cid_guest_title:
        cbs = new CacheGuestTitle();
        break;
    case cid_invoice_item:
        cbs = new CacheInvoiceItem();
        break;
    case cid_invoice_group:
        cbs = new CacheInvoiceItemGroup();
        break;
    case cid_menu_dishes:
        cbs = new CacheMenuDishes();
        break;
    case cid_nation:
        cbs = new CacheNation();
        break;
    case cid_order_state:
        cbs = new CacheOrderState();
        break;
    case cid_payment_mode:
        cbs = new CachePaymentMode();
        break;
    case cid_red_reservation:
        cbs = new CacheRedReservation();
        break;
    case cid_reminder_state:
        cbs = new CacheReminderState();
        break;
    case cid_reservation:
        cbs = new CacheReservation();
        break;
    case cid_reservation_cardex:
        cbs = new   CacheReservationCardex();
        break;
    case cid_reserve_group:
        cbs = new CacheReserveGroup();
        break;
    case cid_reserve_state:
        cbs = new CacheReserveState();
        break;
    case cid_reserve_status:
        cbs = new CacheReserveStatus();
        break;
    case cid_rest_debt_holder:
        cbs = new CacheRestDebtHolder();
        break;
    case cid_rest_dish_mod:
        cbs = new CacheRestDishMod();
        break;
    case cid_rest_dish_part:
        cbs = new CacheRestDishPart();
        break;
    case cid_rest_dish_type:
        cbs = new CacheRestDishType();
        break;
    case cid_rest_full_menu:
        cbs = new CacheRestFullMenu();
        break;
    case cid_rest_hall:
        cbs = new CacheRestHall();
        break;
    case cid_rest_menu:
        cbs = new CacheRestMenu();
        break;
    case cid_rest_printers:
        cbs = new CacheRestPrinters();
        break;
    case cid_rest_store:
        cbs = new CacheRestStore();
        break;
    case cid_rest_table:
        cbs = new CacheRestTable();
        break;
    case cid_user_rights:
        cbs = new CacheRights();
        break;
    case cid_room:
        cbs = new CacheRoom();
        break;
    case cid_room_arrangment:
        cbs = new CacheRoomArrangment();
        break;
    case cid_room_category:
        cbs = new CacheRoomCategory();
        break;
    case cid_room_inventory:
        cbs = new CacheRoomInventory();
        break;
    case cid_room_inventory_state:
        cbs = new CacheRoomInventoryState();
        break;
    case cid_room_state:
        cbs = new CacheRoomState();
        break;
    case cid_room_view:
        cbs = new CacheRoomView();
        break;
    case cid_sex:
        cbs = new CacheSex();
        break;
    case cid_store_doc_type:
        cbs = new CacheStoreDocType();
        break;
    case cid_store_doc_state:
        cbs = new CacheStoreDocState();
        break;
    case cid_store_partners:
        cbs = new CacheStorePartners();
        break;
    case cid_tax_map:
        cbs = new CacheTaxMap();
        break;
    case cid_tracking_tables:
        cbs = new CacheTrackingTables();
        break;
    case cid_users:
        cbs = new CacheUsers();
        break;
    case cid_users_group:
        cbs = new CacheUsersGroups();
        break;
    case cid_users_state:
        cbs = new CacheUsersState();
        break;
    case cid_vat_mode:
        cbs = new CacheVatMode();
        break;
    case cid_vaucher:
        cbs = new CacheVaucher();
        break;
    case cid_transfer_fromcl:
        cbs = new CacheTransferFromCL();
        break;
    case cid_active_group:
        cbs = new CacheActiveGroup();
        break;
    case cid_serv_year:
        cbs = new CacheYear();
        break;
    case cid_fiscalmachine:
        cbs = new CacheFiscalMachine();
        break;
    default:
        TrackControl tc(0);
        tc.insert("UNKNOWN CASH ID", QString::number(id),"");
        return nullptr;
    }

    result = new CacheInstance(cbs);
    fCacheOne[id] = result;
    return result;
}
