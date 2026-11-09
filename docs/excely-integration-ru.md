# Интеграция Excely (SmartHotel)

Краткое руководство по настройке PMSConnect в программе.

Есть **две разные вещи**: импорт броней и выгрузка доступности. Карта типов (`roomTypeMap`) нужна только для импорта.

---

## 1. Подключение (обязательно для всего)

**Application → Global config → вкладка Application → блок Excely**

Заполните и сохраните:

| Поле | Что писать |
|------|------------|
| Endpoint | тест: `https://pmsconnect.test.hopenapi.com/Api/PMSConnect.svc` |
| Hotel code | код отеля в Exely |
| Username / Password | логин API |
| Protocol | `1.18` |

Без этого ни кнопка на шахматке, ни форма доступности работать не будут.

Прод-endpoint: `https://pmsconnect.hopenapi.com/Api/PMSConnect.svc`.

Настройки пишутся в QSettings `SmartHotel` / `SmartHotel`, группа `excely/`.

---

## 2. Выгрузка доступности (Excely availability)

Форма **не** берёт категории из вашей БД. Типы и тарифы приходят **из Exely**.

1. **Directory of Hotel → Excely availability**  
   (нужно право *Excely availability* / `cr__excely_availability` = 153 в User rights).
2. Нажмите **Refresh catalog**.
3. После успеха в логе будет что-то вроде: `Catalog: N room types, M rate plans`.
4. Тогда заполнятся **Room type**, **Rate plan** / **Inv block**.

Дальше: даты, Available rooms (`BookingLimit`), Open/Close → **Upload availability**  
или **Resync avail. year** (End = Start + 365 дней).

### Квота из PMS (дельта) — то, что просит Exely

Кнопки **Push PMS avail (delta)** / **Push PMS year (delta)** считают свободные номера по занятости в PMS и отправляют в Exely **только изменившиеся даты** (кэш последней успешной выгрузки).

Нужна заполненная **Room type map**. Опционально в Global config: **Avail inv. block** — если квоту нужно слать в конкретный inventory block.

### Авто-выгрузка квоты (выключена по умолчанию)

В **Global config → Excely**: чекбокс *Auto-upload availability when bookings change (delta only)*.  
Если включить — после сохранения/отмены брони и после импорта Excely (с паузой ~4 с) уходит дельта на горизонт **Auto / PMS push days** (по умолчанию 365).  
В обычной работе оставляйте выключенным и жмите Push PMS вручную.

### Цены (обязательно для брони на сайте)

Без цен сайт часто не даёт забронировать, даже при Open и квоте > 0.

Вкладка **Prices (batch)**:
1. Refresh catalog.
2. Выберите тип / тариф (без `[prices locked]`), даты, цену, валюту и **Price type** → **+ Add to table**.
3. Наберите нужные строки → **Upload all prices (1 request)**.

Типы цен (как у экзаменатора Exely):
| Price type | XML |
|---|---|
| Base occupancy (adults) | `BaseByGuestAmt` / `NumberOfGuests` |
| Extra adult bed | `AdditionalGuestAmount` (`MaxAdditionalGuests`) |
| Extra child bed | `AdditionalGuestAmount` `AgeQualifyingCode=8` + Age bucket / Min–Max age |
| Child without bed | `AdditionalGuestAmount` `BedRequired=false` + Min–Max age (напр. 2–18) |

Строки с одним типом номера / тарифом / датами / валютой склеиваются в один `RateAmountMessage` (база + доп. гости вместе). Все сообщения уходят одним `OTA_HotelRateAmountNotifRQ`.

Если после Refresh список пустой — в Exely для этого hotel code нет каталога, либо ошибка логина (смотрите текст ошибки / лог формы).

Протокол доступности: `OTA_HotelAvailNotifRQ` (SOAPAction `…/HotelAvailNotifRQ`).

---

## 3. Карта типов (`roomTypeMap`) — только для импорта броней

Нужна, когда нажимаете **Excely** на шахматке: бронь из канала должна попасть в вашу категорию и свободный номер.

В том же блоке Excely в Global config поле **Room type map (JSON)**:

```json
{ "5003606": "STD", "5003607": "DLX" }
```

- слева — **код типа в Exely** (тот же, что в каталоге после Refresh);
- справа — **`f_short` вашей категории** из Directory (Categories) или числовой `f_id` класса.

Без карты бронь создаётся, но **`f_room = 0`** — на шахматке не видно, пока номер не назначат вручную.

---

## 4. Импорт броней (кнопка Excely на шахматке)

1. Настроить credentials и по возможности `roomTypeMap` → Save.
2. На шахматке нажать **Excely**.
3. Программа: pull undelivered → запись в `f_reservation` (`f_chm`, `f_chmstatus=1`) → confirm.
4. Новые брони рисуются **сиреневым**, пока оператор не откроет/сохранит резерв (`f_chmstatus` → 2).

Отмена в PMS брони с `f_chm` → `OTA_CancelRQ` в Exely.  
Повторный Create/Modify из Exely **не оживляет** уже отменённую локально бронь (только confirm).

Все гости из `ResGuests` пишутся в `f_reservation_guests` (не только основной).  
Национальность из Exely — код ISO-3 (`AUS`, `GBR`…): мапится в `f_short` (через alpha-2 / при наличии `f_alpha3`). Если кода нет в справочнике — предупреждение, бронь всё равно импортируется.

Гости и кровати: Age 0–2 → `f_baby` (кровать не занимает); старше → `f_child` (нужна кровать).  
`f_extraBed=1`, если `(f_man + f_child) > f_room.f_bedQty` (или канал прислал ExtraBed). Сейчас: SG / Single → `f_bedQty=1`, остальные → `2`.

Отказ импорта (`RequestDenied`, бронь не создаём):
- неизвестный код категории (нет в `roomTypeMap`);
- неизвестный код тарифа **и** в брони нет сумм. Если суммы есть — импортируем несмотря на код тарифа.

Если после ошибки синка **Pulled: 0**, а изменения в Exely есть: **Reports → Undelivered bookings to PMS → Action → Deliver to PMS automatically** (сброшенная очередью undelivered). Ошибка импорта больше не шлёт `RequestDenied` — бронь остаётся на повтор.

Лимиты Exely: ≤30 ReadRQ/час; подтверждение roughly в течение ~20 минут.

---

## 5. Рабочий порядок

1. Настроить credentials → Save.  
2. Availability → **Refresh catalog** → квота Open → **Upload availability**.  
3. Та же форма → цена + валюта → **Upload prices** (на те же даты / тариф).  
4. Заполнить `roomTypeMap` по кодам из каталога.  
5. **Global config → Application → Excely** → включить **Show Excely button and auto-update on the room chart** (по умолчанию выключено).  
6. На шахматке кнопка **Excely** — забрать новые брони. Галка **Auto** — опрос каждые 2 минуты.

---

## Где что в коде / UI

| Где | Что |
|-----|-----|
| Desk кнопка **Excely** | Импорт undelivered броней. Видна только если в глобальных настройках включён Excely на шахматке |
| **Directory of Hotel → Excely availability** | Квота (`HotelAvailNotif`) + цены (`HotelRateAmountNotif`) |
| **Global config → Application → Excely** | Credentials + `roomTypeMap` |
| `excely/README.md` | Техническое описание модуля PMSConnect |

### Ключи QSettings (`excely/`)

| Key | Назначение |
|-----|------------|
| `endpoint` | URL PMSConnect |
| `username` / `password` | API |
| `hotelCode` | Код отеля |
| `protocolVersion` | по умолчанию `1.18` |
| `roomTypeMap` | JSON: код CM → `f_short` / `f_id` класса |
| `chartEnabled` | Кнопка Excely и автообновление на шахматке. По умолчанию выключено |

Секреты в репозиторий не коммитить.

---

## Для агентов / перенос в другую PMS

Модуль `excely/` — отдельная библиотека. Подсказки и грабли: [`excely/AGENTS.md`](../excely/AGENTS.md).  
Правило Cursor: `.cursor/rules/excely-pmsconnect.mdc`.

