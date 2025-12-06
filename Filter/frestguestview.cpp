#include "frestguestview.h"
#include "ui_frestguestview.h"
#include "wreportgrid.h"

FRestGuestView::FRestGuestView(QWidget *parent)
    : WFilterBase(parent), ui(new Ui::FRestGuestView)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Arrivals/Departures for restaurant"), ":/images/groupreservation.png");
}

FRestGuestView::~FRestGuestView() { delete ui; }

void FRestGuestView::apply(WReportGrid *rg)
{
    rg->fModel->clearData();
    rg->fModel->clearColumns();
    rg->fModel->setColumn(200, "staus", tr("Status"))
    .setColumn(100, "f_arrangement", tr("BB"))
    .setColumn(150, "cardex", tr("Cardex"))
    .setColumn(100, "f_rooms", tr("Rooms"))
    .setColumn(100, "f_guests", tr("Guests"));
    QString sql = R"(
WITH waiting AS (
    SELECT
        'Waiting for arrivals' AS status,
        ra.f_en AS arrangement,
        ca.f_name AS cardex,
        COUNT(r.f_id) AS f_rooms,
        SUM(f_man + f_woman + f_child) AS f_guests
    FROM f_reservation r
    LEFT JOIN f_room_arrangement ra ON ra.f_id = r.f_arrangement
    LEFT JOIN f_cardex ca ON ca.f_cardex=r.f_cardex
    WHERE f_startdate = current_date AND f_state = 2
    GROUP BY 1,2,3
),
waiting_total AS (
    SELECT
        'Subtotal' AS status,
        NULL AS arrangement,
        NULL AS cardex,
        SUM(f_rooms) AS f_rooms,
        SUM(f_guests) AS f_guests
    FROM waiting
),

inhouse AS (
    SELECT
        'Inhouse guests' AS status,
        ra.f_en AS arrangement,
         ca.f_name AS cardex,
        COUNT(r.f_id) AS f_rooms,
        SUM(f_man + f_woman + f_child) AS f_guests
    FROM f_reservation r
    LEFT JOIN f_room_arrangement ra ON ra.f_id = r.f_arrangement
    LEFT JOIN f_cardex ca ON ca.f_cardex=r.f_cardex
    WHERE f_state = 1
    GROUP BY 1,2,3
),
inhouse_total AS (
    SELECT
        'Subtotal' AS status,
        NULL AS arrangement,
        NULL AS cardex,
        SUM(f_rooms) AS f_rooms,
        SUM(f_guests) AS f_guests
    FROM inhouse
),

departure AS (
    SELECT
        'Await departures' AS status,
        ra.f_en AS arrangement,
        ca.f_name AS cardex,
        COUNT(r.f_id) AS f_rooms,
        SUM(f_man + f_woman + f_child) AS f_guests
    FROM f_reservation r
    LEFT JOIN f_room_arrangement ra ON ra.f_id = r.f_arrangement
    LEFT JOIN f_cardex ca ON ca.f_cardex=r.f_cardex
    WHERE f_enddate = current_date and f_state in (1,2,3)
    GROUP BY 1,2,3
),
departure_total AS (
    SELECT
        'Subtotal' AS status,
        NULL AS arrangement,
        NULL AS cardex,
        SUM(f_rooms) AS f_rooms,
        SUM(f_guests) AS f_guests
    FROM departure
)

SELECT * FROM waiting
UNION ALL
SELECT * FROM waiting_total
UNION ALL
SELECT * FROM inhouse
UNION ALL
SELECT * FROM inhouse_total
UNION ALL
SELECT * FROM departure
UNION ALL
SELECT * FROM departure_total
)";
    rg->fModel->setSqlQuery(sql.replace("\r", " ").replace("\n", " "));
    rg->fModel->apply(rg);
}

QWidget* FRestGuestView::firstElement()
{
    return this;
}

QWidget* FRestGuestView::lastElement()
{
    return this;
}

QString FRestGuestView::reportTitle()
{
    return tr("Today guests");
}
