#!/usr/bin/env python3
"""Fill Exely PMSConnect Implementation Questionnaire from SmartHotel capabilities."""

from datetime import date
from pathlib import Path

from docx import Document

SRC = Path(r"e:\download\PMSConnect Implementation Questionnaire.docx")
DST = Path(r"e:\download\PMSConnect Implementation Questionnaire - SmartHotel filled.docx")

ANSWERS = {
    2: date.today().strftime("%Y-%m-%d") + " (draft for certification)",
    3: (
        "+ SmartHotel (Resort module) from version 1.9.29 / product 1.9. "
        "Integration module: Excely PMSConnect static library."
    ),
    4: "+ 1.18 (Version field in all OTA requests)",
    5: (
        "+ Brief operator guide available (docs/excely-integration-ru.md): "
        "credentials in Global config → Application → Excely; availability/prices UI; "
        "desk pull button; roomTypeMap JSON. English technical README in excely/README.md."
    ),
    # Room availability
    7: (
        "+ Yes. HotelAvailNotif supports RatePlanCode XOR InvBlockCode. "
        "UI: Directory of Hotel → Excely availability — select rate plan or inventory block per upload."
    ),
    8: (
        "- Not supported (no hostel bed-level inventory). "
        "Availability is by room type / BookingLimit only."
    ),
    9: (
        "- Not automatic yet. Operator uploads manually (or Resync avail. year) "
        "from Excely availability form. Auto-push on PMS occupancy change is planned."
    ),
    10: (
        "- Current UI always sends the selected period (manual/forced). "
        "No delta-only cache of last successful upload yet."
    ),
    11: (
        '+ Manual "Resync avail. year" extends End = Start + 365 days and uploads '
        "BookingLimit/Open-Close for the period."
    ),
    12: "+ Yes. Forced upload for chosen Start/End (Upload availability) and year resync.",
    # Rate plans/prices
    14: (
        "+ one-to-one matching in current UI (Exely InvTypeCode + RatePlanCode from catalog). "
        "Mapping of Exely room types to PMS categories is one-to-one via roomTypeMap JSON "
        "(CM code → local class). Many-to-many not implemented."
    ),
    15: (
        "+ Yes. HotelRateAmountNotif AmountAfterTax for NumberOfGuests (adults on main beds). "
        "UI: price per night + number of adults."
    ),
    16: (
        "+ Configurable in UI (BaseByGuestAmt NumberOfGuests). Typical use 1–4; "
        "no hard protocol cap in our client (practical max depends on Exely rate plan). "
        "Default/common: up to 4 adults."
    ),
    17: "- Not implemented (no Extra Bed adult amounts in RateAmountNotif yet).",
    18: "- Not implemented (no child age-range amounts on main beds).",
    19: "- Not implemented.",
    20: "- Not implemented.",
    21: "- Not implemented (no service rate upload).",
    22: "- Current UI uploads selected period; no delta-only price cache yet.",
    23: "- N/A (extra service price upload not implemented).",
    24: '+ Manual "Resync prices year" for Start..Start+365.',
    # Restrictions
    26: (
        "+ Yes (RestrictionStatus Open/Close via HotelAvailNotif). "
        "Note: some Exely setups return WARN 150 — then BookingLimit-only mode is used."
    ),
    27: "+ Yes (MinLOS in AvailStatusMessage / UI).",
    28: "- Not implemented.",
    29: "- Not implemented.",
    30: "- Not implemented.",
    31: "- Not implemented.",
    32: "- Not implemented.",
    33: "- Not implemented.",
    34: "- Not implemented.",
    35: "- Not implemented.",
    36: (
        "- Restrictions are uploaded manually with availability, "
        "not auto-detected from PMS rule changes."
    ),
    # Booking processing
    38: (
        "+ Yes. Multi-room HotelReservation: each RoomStay stored as separate f_reservation "
        "with f_chm = channelId#index (or bare id for single room). "
        "Different room types supported via InvTypeCode → roomTypeMap."
    ),
    39: (
        "+ Yes. Undelivered Create/Modify pulled via HotelReadReservationRQ; "
        "Modify updates existing f_chm row (guests, dates, amounts, remarks). "
        "Locally canceled bookings are not resurrected (RequestDenied)."
    ),
    40: "+ Yes. Cancel status from Exely sets local reservation to canceled (RESERVE_REMOVED).",
    41: "+ Yes. Operator cancel of a channel booking (f_chm set) sends OTA_CancelRQ to Exely.",
    42: (
        "+ Stored in f_reservation.f_man (adults from GuestCount AgeQualifyingCode Adult / AdultBed). "
        "Shown on reservation form / chart guest counts."
    ),
    43: (
        '- Parsed guest counts currently aggregate adults into f_man; dedicated '
        '"adults on extra beds" field not mapped separately (f_extrabed left 0).'
    ),
    44: (
        "+ Children count stored in f_reservation.f_child. Age group / exact ages from Exely "
        "are not stored as structured fields yet (may appear in remarks if present in comments)."
    ),
    45: "- Not separated from main-bed children count.",
    46: "- Not separated.",
    47: (
        "- Extra services with API codes are not mapped to PMS charge items yet. "
        "Service text may appear in booking comments/remarks if Exely puts it there."
    ),
    48: (
        "- Same as above — not processed as priced line items; "
        "comment-only if delivered in Text/Comments."
    ),
    49: (
        "+ Booking channel / company from BookingChannel CompanyName@Code → resolved to "
        "f_cardex / city ledger when a matching cardex exists; otherwise code/name kept for mapping. "
        "External channel id stored."
    ),
    50: (
        "+ Fields used: Cardex/Company (f_cardex), Booking number (f_booking = External UniqueID), "
        "channel id (f_chm), payment comment, remarks."
    ),
    51: (
        "+ Partially: property can add a new Cardex/counterparty in PMS Directory and map by "
        "company code/name on next import. No automatic create-from-Exely company list UI yet "
        "(catalog companies are readable via HotelAvail)."
    ),
    52: (
        "+ Yes. Guarantee PaymentMethodName / PaymentSystem* → f_paymenttype (cash/card heuristic) "
        "and f_paymentcomment / voucher payment comment."
    ),
    53: (
        "+ Prepaid (GuaranteePayment) is imported as an advance voucher (AV) on the reservation invoice; "
        "re-delivery updates the same voucher by channel marker."
    ),
    54: "+ Yes. Comments / full comment → f_reservation.f_remarks (and register remarks).",
    55: "+ Yes. UniqueID ID_Context=External → f_booking; channel UniqueID → f_chm.",
    56: (
        "+ Accept prices from the Exely booking (RoomStay Total / AmountAfterTax) into "
        "f_roomfee / f_pricepernight / f_total — not recalculated from local PMS rate plans."
    ),
    57: (
        "- Rate Mix (different RatePlanCode per day) not stored day-by-day; "
        "stay uses overall room stay total / average night price."
    ),
    58: "- Extra service prices from booking not applied as separate charges (see services above).",
    59: (
        "+ Arrival/departure dates from TimeSpan Start/End are applied. Clock times are parsed "
        "into draft but do not currently change neighboring-date availability logic "
        "(availability is date-based BookingLimit)."
    ),
    # Exely → PMS
    61: (
        "- Not implemented. Prices flow PMS → Exely (HotelRateAmountNotif), "
        "not Exely → PMS via HotelRatePlanRQ."
    ),
    62: (
        "- Not implemented. Restrictions flow PMS → Exely (HotelAvailNotif), "
        "not Exely → PMS via HotelAvailGetRQ."
    ),
    # Price Assist
    64: "- Not implemented (no OTA_HotelInvCountNotifRQ).",
    # Export
    66: (
        "- Not implemented (no OTA_HotelResNotifRQ export of PMS-originated bookings). "
        "Channel bookings created in Exely are pulled; PMS-only bookings are not pushed to Exely."
    ),
    67: "- Not implemented (no OTA_ProfileCreateRQ / OTA_ProfileModifyRQ).",
    # Hourly
    69: (
        "- Not implemented. Early check-in / late check-out / hourly ServiceInventoryCode "
        "not processed as timed inventory."
    ),
    # Finance
    71: "TBD — to be confirmed by SmartHotel sales (integration module cost for the property).",
    72: "TBD — to be confirmed by SmartHotel sales (onboarding/setup per property).",
    # Manual / support
    74: (
        "+ Manual already available in Russian: docs/excely-integration-ru.md "
        "(credentials, forced availability upload, forced price upload, booking pull, "
        "undelivered re-queue). English module notes: excely/README.md. "
        "Can provide PDF/English copy on request within a few days."
    ),
    75: "TBD — please fill: support email / phone / Telegram for SmartHotel Exely integration issues.",
}


def main() -> None:
    doc = Document(str(SRC))
    table = doc.tables[0]
    for ri, text in ANSWERS.items():
        table.rows[ri].cells[1].text = text
    doc.save(str(DST))
    print(f"Saved: {DST}")
    print(f"Filled rows: {len(ANSWERS)}")


if __name__ == "__main__":
    main()
