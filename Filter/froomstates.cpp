#include "froomstates.h"
#include "ui_froomstates.h"
#include "wreportgrid.h"
#include "roomstate.h"
#include "chardefaults.h"
#include "dlghouseitem.h"

static QMap<int, QColor> fColorOfStates;

FRoomStates::FRoomStates(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FRoomStates)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("State of the room"), ":/images/window.png");
    if (fPreferences.getDb(def_touchscreen).toBool()) {
        connect(fReportGrid, SIGNAL(clickOnRow(int)), this, SLOT(clickOnRow(int)));
        fReportGrid->fTableView->verticalHeader()->setDefaultSectionSize(50);
    } else {
        connect(fReportGrid, SIGNAL(doubleClickOnRow(QList<QVariant>)), this, SLOT(dbClick(QList<QVariant>)));
    }
    connect(cache(cid_room), SIGNAL(updated(int,QString)), this, SLOT(roomUpdated(int, QString)));
    if (fColorOfStates.count() == 0) {
        fColorOfStates[ROOM_STATE_NONE] = Qt::white;
        fColorOfStates[ROOM_STATE_CHECKIN] = static_cast<QColor>(__ss.value("checkincolor", -16733441).toInt()), QColor::fromRgb(70, 170, 255);
        fColorOfStates[ROOM_STATE_DIRTY] = Qt::yellow;
        fColorOfStates[ROOM_STATE_OUTOF] = Qt::gray;
    }
}

FRoomStates::~FRoomStates()
{
    delete ui;
}


void FRoomStates::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    if (fPreferences.getDb(def_touchscreen).toBool()) {
        rg->fModel->setColumn(0, "", tr("State"))
                .setColumn(60, "", tr("Room"))
                .setColumn(100, "", tr("Name"))
                .setColumn(60, "", tr("State"))
                .setColumn(110, "", tr("Entry"))
                .setColumn(110, "", tr("Departure"))
                .setColumn(50, "", tr("Adults"))
                .setColumn(50, "", tr("Childs"))
                .setColumn(40, "", tr("Nation"))
                .setColumn(120, "", tr("Guest"))
                .setColumn(100, "", tr("Cardex"))
                .setColumn(450, "", tr("Remarks"))
                .setColumn(0, "", tr("Dont disturbe"));
    } else {
        rg->fModel->setColumn(0, "", tr("State"))
                .setColumn(60, "", tr("Room"))
                .setColumn(150, "", tr("Name"))
                .setColumn(105, "", tr("State"))
                .setColumn(110, "", tr("Entry"))
                .setColumn(110, "", tr("Departure"))
                .setColumn(70, "", tr("Adults"))
                .setColumn(70, "", tr("Childs"))
                .setColumn(100, "", tr("Nation"))
                .setColumn(300, "", tr("Guest"))
                .setColumn(300, "", tr("Cardex"))
                .setColumn(450, "", tr("Remarks"))
                .setColumn(0, "", tr("Dont disturbe"));
    }
    QString query = "select r.f_state, r.f_id, r.f_short, rs.f_en, "
            "rn.f_startdate, rn.f_enddate, rn.f_man+rn.f_woman, rn.f_child, "
            "na.f_name, CONCAT(g.f_title, ' ',g.f_firstName, ' ',g.f_lastName) as guest, ca.f_name, "
            "rn.f_remarks, r.f_donotdisturbe "
            "from f_room r "
            "left join f_reservation rn on rn.f_room=r.f_id and rn.f_state=1 "
            "left join f_guests g on g.f_id=rn.f_guest "
            "left join f_room_state rs on rs.f_id=r.f_state "
            "left join f_nationality na on na.f_short=g.f_nation "
            "left join f_cardex ca on ca.f_cardex=rn.f_cardex "
            "order by r.f_building, r.f_id ";
    rg->fModel->setSqlQuery(query);
    rg->fModel->apply(rg);
    for (int i = 0; i < rg->fModel->rowCount(); i++) {
        rg->fModel->setBackgroundColor(i, getRowColor(i));
    }
}

QWidget *FRoomStates::firstElement()
{
    return this;
}

QWidget *FRoomStates::lastElement()
{
    return this;
}

QString FRoomStates::reportTitle()
{
    return QString("%1 %2").arg(tr("State of the rooms"), QDateTime::currentDateTime().toString(def_date_time_format));
}

QColor FRoomStates::getRowColor(int row) const
{
    QColor c = fColorOfStates[fReportGrid->fModel->data(row, 0).toInt()];
    if (fReportGrid->fModel->data(row, 12).toInt() > 0) {
        c = QColor::fromRgb(__s.value("donotdisturbecolor", -5570689).toInt());
    }
    return c;
}

void FRoomStates::dbClick(const QList<QVariant> &row)
{
    if (row.count() == 0) {
        return;
    }
    DlgHouseItem::openWindow(row.at(1).toInt());
//    RoomState *rs = new RoomState(this);
//    rs->uncheckStiky();
//    rs->setRoom(row.at(1).toString());
//    rs->exec();
    //    delete rs;
}

void FRoomStates::clickOnRow(int row)
{
    if (row < 0) {
        return;
    }
    DlgHouseItem::openWindow(fReportGrid->fModel->data(row, 1).toInt());
}

void FRoomStates::roomUpdated(int cacheid, const QString &name)
{
    Q_UNUSED(cacheid);
    CacheRoom cr;
    if (!cr.get(name)) {
        return;
    }
    for (int i = 0; i < fReportGrid->fModel->rowCount(); i++) {
        if (fReportGrid->fModel->data(i, 1).toInt() == cr.fCode().toInt()) {
            fReportGrid->fModel->setData(i, 0, cr.fState());
            fReportGrid->fModel->setData(i, 12, (int) cr.fDoNotDisturbe());
            fReportGrid->fModel->setData(i, 3, cr.fStateName());
            fReportGrid->fModel->setBackgroundColor(i, getRowColor(i));
        }
    }
}

