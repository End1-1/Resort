#include "froomstates.h"
#include "ui_froomstates.h"
#include "wreportgrid.h"
#include "roomstate.h"

FRoomStates::FRoomStates(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FRoomStates)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("State of the room"), ":/images/window.png");
    connect(fReportGrid, SIGNAL(doubleClickOnRow(QList<QVariant>)), this, SLOT(dbClick(QList<QVariant>)));
}

FRoomStates::~FRoomStates()
{
    delete ui;
}


void FRoomStates::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(80, "", tr("Code"))
            .setColumn(150, "", tr("Name"))
            .setColumn(105, "", tr("State"))
            .setColumn(300, "", tr("Guest"));
    QString query = "select r.f_id, r.f_short, rs.f_en, g.guest "
            "from f_room r "
            "left join f_reservation rn on rn.f_room=r.f_id and rn.f_state=1 "
            "left join guests g on g.f_id=rn.f_guest "
            "left join f_room_state rs on rs.f_id=r.f_state "
            "order by r.f_building, r.f_id ";
    rg->fModel->setSqlQuery(query);
    rg->fModel->apply(rg);
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
    return QString("%1 %2").arg(tr("State of the rooms")).arg(QDateTime::currentDateTime().toString(def_date_time_format));
}

void FRoomStates::dbClick(const QList<QVariant> &row)
{
    if (row.count() == 0) {
        return;
    }
    RoomState *rs = new RoomState(this);
    rs->setRoom(row.at(0).toString());
    rs->exec();
    delete rs;
}
