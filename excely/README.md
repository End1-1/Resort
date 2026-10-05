# Excely PMSConnect (standalone + Resort desk)

Qt/C++ client for **Exely PMSConnect protocol v1.18** — pull undelivered channel-manager bookings and confirm delivery.

Linked into **Resort** as static lib `ExcelyPmsConnect`. Desk button **Excely** on `WMainDesk` runs a one-shot pull → DB sink → confirm.

## Layers

```
IBookingSource  ←── ExelyBookingSource (SOAP PMSConnect)
       │
  Channel::Booking          (universal DTO for any CM)
       │
  Resort::toResortDraft()
       │
  Resort::BookingDraft      (f_reservation-shaped intermediate)
       │
  ExcelyResortSink          (Resort: f_reservation + f_chmstatus=1)
```

| Piece | Role |
|-------|------|
| [`include/excely/channel/`](include/excely/channel/) | Universal `Booking` + `IBookingSource` / `IBookingSink` |
| [`include/excely/resort/`](include/excely/resort/) | `BookingDraft` + mapper → import JSON |
| [`include/excely/pms/`](include/excely/pms/) | SOAP client, OTA XML build/parse |
| [`Resort/excelyappconfig.*`](../Resort/excelyappconfig.h) | QSettings loader |
| [`Resort/excelyresortsink.*`](../Resort/excelyresortsink.h) | DB persist + lilac `f_chmstatus` |

Imported reserves get `f_chmstatus=1` so the room chart paints lilac until the operator opens/saves the reservation (status → 2).

## Protocol notes

- Auth: SOAP header `Security Username/Password` (`https://www.hopenapi.com/Api/PMSConnect`)
- Read: `HotelReadReservationRQ` / body `OTA_ReadRQ` `SelectionType=Undelivered`
- Confirm: `NotifReportRQ` / `OTA_NotifReportRQ` `ResStatus=Reserved` (+ optional `RequestDenied`)
- Test endpoint: `https://pmsconnect.test.hopenapi.com/Api/PMSConnect.svc`
- Prod: `https://pmsconnect.hopenapi.com/Api/PMSConnect.svc`
- Limits: ≤30 ReadRQ/hour; confirm within ~20 minutes; poll every **5 minutes**

## Resort QSettings (`SmartHotel` / `SmartHotel`, group `excely/`)

| Key | Purpose |
|-----|---------|
| `endpoint` | PMSConnect URL (default: test host) |
| `username` | API user |
| `password` | API password |
| `hotelCode` | Exely hotel code |
| `protocolVersion` | default `1.18` |
| `roomTypeMap` | JSON object mapping CM room type code → `f_room_classes.f_short` or class `f_id` |

Example `roomTypeMap`:

```json
{ "5003606": "STD", "5003607": "DLX" }
```

Do **not** commit secrets. Seed test credentials only in local QSettings / `pmsconnect.ini`.

Without `hotelCode` / `username` / `password`, the desk button shows an error (no silent fail).

## Build (standalone poller)

```bat
cmake -S excely -B D:\build.6.10.2\excely -DCMAKE_PREFIX_PATH=C:\Development\Qt\6.10.2\msvc2022_64
cmake --build D:\build.6.10.2\excely --config Release
```

Resort links the same library via `add_subdirectory(../excely)` in `Resort/CMakeLists.txt`.

## Configure poller INI

```bat
copy excely\config\pmsconnect.example.ini excely\config\pmsconnect.ini
```

Fill `hotelCode`, `username`, `password`.

## Run poller

```bat
pmsconnect_poller --config excely\config\pmsconnect.ini --once --dry-run
pmsconnect_poller --config excely\config\pmsconnect.ini --ping
pmsconnect_poller --config excely\config\pmsconnect.ini --hotel-avail
pmsconnect_poller --config excely\config\pmsconnect.ini
```

`--dry-run` pulls and prints universal + Resort draft JSON but does **not** send `NotifReport`.

## Fixture

Sample `OTA_ResRetrieveRS`: [`tests/fixtures/ota_resretrieve_sample.xml`](tests/fixtures/ota_resretrieve_sample.xml)

## Spec

See `PMSConnect v1.18.pdf` in this folder.
