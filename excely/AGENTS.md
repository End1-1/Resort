# AGENTS.md — Excely PMSConnect module

Guidance for AI agents and developers. This library is **PMS-agnostic** and will be reused in other products (not only SmartHotel/Resort). Prefer changing code under `excely/` over embedding Exely logic inside a host PMS.

When you fix a bug or add a protocol feature here, **update this file** (and `.cursor/rules/excely-pmsconnect.mdc` if the rule summary changes).

## Boundaries

| Layer | Path | Owns |
|-------|------|------|
| Channel DTO / interfaces | `include/excely/channel/` | `Booking`, `IBookingSource`, `IBookingSink` |
| Exely SOAP | `include/excely/pms/` + `src/pms/` | PMSConnect 1.18 client, XML build/parse |
| Resort-shaped draft | `include/excely/resort/` | `BookingDraft`, `toResortDraft` (naming is historical; treat as **generic import draft**) |
| Host PMS adapter | outside `excely/` | DB, UI, rights, QSettings — must **not** live in the static lib |

Host example (SmartHotel): `Resort/excelyresortsink.*`, `Resort/excelyappconfig.*`, desk/availability UI.

New PMS: implement `IBookingSink` (and optionally map via `toResortDraft` / `toImportJson`), reuse `ExelyBookingSource` / `PmsConnectClient`.

## Protocol map (v1.18)

| Operation | SOAPAction suffix | Builder / client API |
|-----------|-------------------|----------------------|
| Pull undelivered | `HotelReadReservationRQ` | `pullUndelivered` / `readUndelivered` |
| Confirm create | `NotifReportRQRequest` | `confirmDelivered` / `confirmReserved` (`ResStatus=Reserved`) |
| Reject create | same | `rejectDelivery` / `requestDenied` |
| Cancel from PMS (after delivered) | `CancelRQ` | `cancelReservation` → `OTA_CancelRQ` |
| Catalog | `HotelAvailRQ` | `hotelAvail` |
| Availability upload | `HotelAvailNotifRQ` | `hotelAvailNotif` |
| Prices upload | `HotelRateAmountNotifRQ` | `hotelRateAmountNotif` |
| Ping | `PingRQRequest` | `ping` |

Spec PDF: `PMSConnect v1.18.pdf` in this folder.

## Hard-won pitfalls (do not regress)

### Guest name empty
OTA nests names as `Customer/PersonName/GivenName|Surname`.  
**Never** `skipElement` on `PersonName` — that drops the name. Descend into `PersonName` and read children (see `parseGuestPerson` in `models.cpp`).

### Children vs babies / extra bed
`GuestCount@AgeQualifyingCode`: anything with `Adult*` → `f_man`. Child codes (`ChildBandBed`, …): if `GuestCount@Age` is **0–2** → `f_baby`, otherwise (Age > 2 or Age omitted) → `f_child`. `AgeBucket` alone is not mapped to years (hotel-specific ranges).  
Babies do **not** need a bed. Adults + children do. Host sets `f_extraBed=1` when `(f_man + f_child) > f_room.f_bedQty` (assigned room, else class capacity). Channel `AdultExtraBed` / `ChildBandExtraBed` also forces extra bed. Fee left 0 (amount is in stay total). `ChildBandWithoutBed` alone does not set the channel flag.

### All ResGuests (not only primary)
`HotelRes` can carry several `ResGuests/ResGuest/Customer`. Parse **every** guest into `Booking.guests`. Host sink must link **all** of them to the stay (primary + extras). Updating only `mainGuest` looks like “Updated: 1” while the second guest never appears in the PMS.

SmartHotel: `ExcelyResortSink::linkReservationGuests` → `f_reservation_guests` (`f_first=1` for primary, `0` for others). Deduplicate primary if it is also listed in `guests`.

### Nationality / country code
Exely sends `CitizenCountryName@Code` (and sometimes `Address/CountryName@Code`) as **ISO-3166 alpha-3** (`AUS`, `GBR`, …).  
Do **not** write that code straight into local guest nationality fields that expect a short code.

Host must map alpha-3 → local short (SmartHotel: `f_nationality.f_alpha3` → `f_short` → `f_guests.f_nation`). Warn when the code is missing from the lookup table. Also descend into `Address` (do not `skipElement` it) so nested `CountryName` is available as fallback.

### Title / NULL in CONCAT
Do not bind `QString()` for `f_title` (null QVariant → SQL NULL → `CONCAT` shows `null`). Use empty string `""`. Same for other optional string columns that UIs concatenate.

### Currency WARN 61
`HotelRateAmountNotif` may return Success **with** `WARN 61 Invalid currency code`. Treat currency mismatch as failure for the operator (prices often did not land). Currency must match the **rate plan / hotel** currency in Exely (UI label can disagree with what PMSConnect accepts).

### Restriction WARN 150
Some providers reject `RestrictionStatus` Open/Close. Prefer sending only `BookingLimit` when that warning appears.

### Do not resurrect canceled local bookings
On Create/Modify import: if `f_chm` already maps to a **canceled** reservation, do **not** set state back to reserve.

**Ack that clears the undelivered queue:** use **`RequestDenied`** (`rejectDelivery`), **not** `NotifReport Reserved`.  
Confirming `Reserved` for an already-canceled local booking leaves the item undelivered — every sync pulls the same 2 bookings again (“Canceled: 2” / “confirm only, not revived” forever).

Host pattern (SmartHotel desk button): `Outcome::AlreadyCanceledLocally` → `rejectDelivery("Already canceled in PMS")` → count as dismissed, not as successful import.

### PMS cancel → Exely
Local cancel of a channel booking (`f_chm` set) must call `OTA_CancelRQ` with channel UniqueID (bare `f_chm`, strip `#roomIndex` suffix).  
`RequestDenied` is **only** for undelivered create rejection, not post-confirm cancel.

### Money is AMD in PMS
Channel amounts (`Total`, `GuaranteePayment`, room fee) in **USD** are converted to AMD on import (`× f_acc_currencies` dollar rate). Room `f_total` / advance `f_amountAmd` are always AMD; `f_totalusd` keeps the original USD when the channel sent USD.

### Prepaid / GuaranteePayment → AV
`GuaranteePayment` amounts are imported as `m_register` advance vouchers (`VAUCHER_ADVANCE_N`) on the primary room invoice. Marker in remarks: `Excely:prepaid:{chmId}:{paymentIndex}` — re-delivery updates amount instead of duplicating.

### Confirm undelivered
After successful sink accept, always `confirmDelivered`. Failed confirm → booking stays undelivered and returns on next pull.

### NotifReport: echo CreateDateTime / LastModifyDateTime verbatim
Exely matches `LastModifyDateTime` against the `ResRetrieveRS` value **exactly**. Reformatting via `QDateTime` (dropping `.323` ms or `+02:00`) makes the confirm silently ineffective — the booking is re-delivered on every pull. Use `Booking::createDateTimeRaw` / `lastModifyDateTimeRaw`.

### Multi-room: one PMS reservation per RoomStay
Each RoomStay → its own local reservation (`f_chm = chmId#IndexNumber`). Confirm with `confirmDeliveredRooms`: one `HotelReservation` per PMS id, each with its own `<RoomStays><RoomStay IndexNumber/>` and `HotelReservationID`. Never send the first room's id for all rooms.

Modify usually brings **new** IndexNumbers: match by key first, then reuse remaining active rows of the same `chmId` in creation order; rows left unmatched are canceled (partial cancellation).

### Do not RequestDenied on transient sink/DB errors
`rejectDelivery` / `RequestDenied` **removes** the item from the Exely undelivered pull queue. Use it only for intentional permanent reject. On import/DB failure, leave undelivered for retry. If the queue was already cleared by a bad reject, re-queue in Exely: Reports → Undelivered bookings to PMS → Deliver to PMS automatically.

**Permanent reject (`Outcome::Rejected` → RequestDenied):**
- Unknown **room type** (CM code missing from host `roomTypeMap`) → always reject, do not create reservation.
- Unknown **rate plan** (not in Exely `HotelAvail` catalog): if the booking has amounts (`RoomStay`/`grandTotal` > 0) → import anyway (warn); if no amounts → reject.

### Nationality without assuming `f_alpha3`
Exely sends ISO alpha-3. Host `f_nationality` may only have `f_short`/`f_name` (no `f_alpha3`). Map alpha-3→alpha-2, look up `f_short`; probe `f_alpha3` only if the column exists. Never fail the whole import on an unknown country code.

### Availability vs prices
`HotelAvailNotif` alone does **not** make the website bookable. Prices need `HotelRateAmountNotif` (or prices already in Exely extranet). Rate plan must have `PriceUploadIsAllowed=true` from catalog.

### Batch price upload
One `OTA_HotelRateAmountNotifRQ` may contain many `RateAmountMessage` nodes. Prefer a batch table over N separate SOAP calls.

Price kinds (host UI → XML):
- **Base occupancy** → `BaseByGuestAmt` (`NumberOfGuests` + amount).
- **Extra adult bed** → `AdditionalGuestAmount` (`MaxAdditionalGuests`, no age attrs).
- **Extra child bed** → `AdditionalGuestAmount` with `AgeQualifyingCode="8"` + `AgeBucket` and/or `MinAge`/`MaxAge`.
- **Child without bed** → `AdditionalGuestAmount` with `BedRequired="false"` + `MinAge`/`MaxAge` (e.g. 2–18).

Rows that share room type + rate plan + dates + currency are merged into one `RateAmountMessage` (`BaseByGuestAmts` + `AdditionalGuestAmounts` together).

### HotelAvailNotifRQ TimeStamp
Root `OTA_HotelAvailNotifRQ` must include `TimeStamp` (ISO-8601), same as `HotelAvailRQ` / `HotelRateAmountNotifRQ`. Exely certification flags missing `TimeStamp` even when BookingLimit/InvBlock are correct.

### MinLOS clear = RemoveMinLOS
Omitting `LengthsOfStay` does **not** clear a previously set MinLOS. To remove: `MinMaxMessageType="RemoveMinLOS"`. Host UI: Min LOS `(omit)`/−1 = do not send; `0` = RemoveMinLOS; `>0` = SetMinLOS.

### Availability auto + delta (host)
Exely requires: (1) upload when PMS occupancy changes; (2) send only changed availability.  
SmartHotel: `ExcelyAvailPusher` computes BookingLimit from free rooms vs last-upload cache (`excely/availLastUpload`). Manual: **Push PMS avail (delta)**; **Full resync from PMS (year)** sends every date and resets the baseline (do this before delta tests — manual quotas like 10/5 in the cache make the next delta look like a jump to PMS free rooms). Unassigned reservations (`f_room=0`) carry no category and do not reduce computed availability. Auto: `autoUploadAvailability` (default **off**) via `requestAutoPush()` after save/cancel/import.

### roomTypeMap
Host-only mapping CM room type code → local room class. Required for chart room assignment on import; **not** used by Exely availability/price upload (those use Exely catalog codes).

### Room assignment must lock the room row
Do not pick a free room from cache and insert it later. Two imports (or an import and a desk save) then land on the same room. Host: `SELECT f_id FROM f_room WHERE f_id=? FOR UPDATE` in the same transaction as the overlap check and the `f_reservation` write. Overlap dates must be read as strings (`DATE_FORMAT`), not `QDate` from a prepared SELECT (Qt 6 / MySQL returns an invalid date and the check treats the room as free). Checkout day stays free: nights occupied are `[start, end)`.

## Host integration checklist (any PMS)

1. Credentials (endpoint, hotelCode, user, password, protocolVersion).
2. Sink: create / modify / cancel by channel id; guest + stay persist; no silent fail on empty credentials.
3. Pull loop: pull → accept → confirm or reject.
4. Outbound cancel when operator cancels a channel booking.
5. Optional: avail + rate upload UI using catalog from `hotelAvail`.
6. Do **not** log secrets. SOAP exchanges are archived under `%TEMP%/resort/excely/` as `e_dd_MM_yyyy_HH_mm_ss_<Action>_{rq|rs}.xml` (OTA request body without credentials + raw response) for certification debugging.

## Changing this module

- Keep Qt Core/Network only in the static lib (no Widgets/SQL).
- Prefer extending `PmsConnectClient` + `models.*` over duplicating SOAP in the host.
- Add fixtures under `tests/fixtures/` when parsing changes.
- Update **this AGENTS.md** and the Cursor rule when behavior or pitfalls change.
