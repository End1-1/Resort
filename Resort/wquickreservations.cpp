#include "wquickreservations.h"
#include "ui_wquickreservations.h"
#include "utils.h"
#include "wquickreservationspax.h"
#include "dlgcreategroupreservation.h"
#include "winvoice.h"
#include "trackcontrol.h"
#include "wreservationroomtab.h"
#include "cachereservation.h"
#include "edoubleedit.h"
#include "cachenation.h"
#include "roomstate.h"
#include "wreservation.h"
#include "wquickreservationsguests.h"
#include "cacheroom.h"
#include "cacheredreservation.h"
#include "dlgtracking.h"
#include "cachecardex.h"
#include "wquickreservationscheckin.h"
#include <QPainter>

static const int col_room_state = 0;
static const int col_reservation = 1;
static const int col_room = 2;
static const int col_room_category = 3;
static const int col_date_entry = 4;
static const int col_date_departure = 5;
static const int col_rate = 6;
static const int col_pax = 7;
static const int col_first_name = 8;
static const int col_last_name = 9;
static const int col_nat = 11;
static const int col_cardex = 12;
static const int col_invoice = 14;
static const int col_guest_code = 15;

WQuickReservations::WQuickReservations(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WQuickReservations)
{
    ui->setupUi(this);
    ui->leCardex->setSelector(this, cache(cid_cardex), ui->leCardexName);
    ui->tbl->setItemDelegate(new WQuickReservationsDelegate(this));
    Utils::tableSetColumnWidths(ui->tbl, ui->tbl->columnCount(), 20, 100, 50, 100, 80, 80, 60, 50, 150, 150, 100, 80, 150, 150, 0, 0);
    ui->tblTotal->setColumnCount(ui->tbl->columnCount());
    for (int i = 0; i < ui->tbl->columnCount(); i++) {
        ui->tblTotal->setColumnWidth(i, ui->tbl->columnWidth(i));
    }
    ui->deDate->setDate(WORKING_DATE);
    refresh();
    ui->tbl->installEventFilter(this);
    ui->leCardex->installEventFilter(this);
    ui->deDate->installEventFilter(this);
    connect(cache(cid_room), SIGNAL(updated(int,QString)), this, SLOT(roomUpdated(int, QString)));
}

WQuickReservations::~WQuickReservations()
{
    delete ui;
}

void WQuickReservations::setup()
{
    setupTabTextAndIcon(tr("Reservations"), ":/images/bedroom.png");
}

QString WQuickReservations::reservationCode(int row)
{
    return ui->tbl->toString(row, col_reservation);
}

QString WQuickReservations::invoiceCode(int row)
{
    return ui->tbl->toString(row, col_invoice);
}

int WQuickReservations::room(int row)
{
    return ui->tbl->toInt(row, col_room);
}

int WQuickReservations::roomState(int row)
{
    return ui->tbl->toInt(row, col_room_state);
}

int WQuickReservations::guestCode(int row)
{
    return ui->tbl->toInt(row, col_guest_code);
}

QString WQuickReservations::guestFullName(int row)
{
    return ui->tbl->toString(row, col_first_name) + " " + ui->tbl->toString(row, col_last_name);
}

QDate WQuickReservations::dateEntry(int row)
{
    return ui->tbl->toDate(row, col_date_entry);
}

QDate WQuickReservations::dateDeparture(int row)
{
    return ui->tbl->toDate(row, col_date_departure);
}

QString WQuickReservations::cardex(int row)
{
    return ui->tbl->toString(row, col_cardex);
}

QAbstractItemModel *WQuickReservations::model()
{
    return ui->tbl->model();
}

void WQuickReservations::updateTable()
{
    ui->tbl->viewport()->update();
}

void WQuickReservations::broadcast(int row)
{
    BroadcastThread::cmdRefreshCache(cid_reservation, reservationCode(row));
    BroadcastThread::cmdRefreshCache(cid_room, QString::number(room(row)));
    BroadcastThread::cmdRefreshCache(cid_red_reservation, reservationCode(row));
}

bool WQuickReservations::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        auto *ke = static_cast<QKeyEvent*>(event);
        switch (ke->key()) {
        case Qt::Key_Plus:
            ke->accept();
            if (ke->modifiers() & Qt::ControlModifier) {
                setRowSelected(-1);
            } else {
                setRowSelected(1);
            }
            return true;
        case Qt::Key_Minus:
            ke->accept();
            if (ke->modifiers() & Qt::ControlModifier) {
                setRowSelected(-2);
            } else {
                setRowSelected(0);
            }
            return true;
        }
    }
    return BaseWidget::eventFilter(watched, event);
}

void WQuickReservations::roomUpdated(int cacheId, const QString &code)
{
    Q_UNUSED(code);
    switch (cacheId) {
    case cid_room:
        updateTable();
        break;
    }
}

void WQuickReservations::on_btnRefresh_clicked()
{
    refresh();
}

void WQuickReservations::refresh()
{
    DoubleDatabase dd(true, false);
    QString query = "select rm.f_state, r.f_id, r.f_room, rm.f_short, r.f_startdate, r.f_enddate, r.f_roomfee, "
                    "r.f_man+r.f_woman+r.f_child as f_pax, "
                    "g.f_firstname, g.f_lastname, g.f_passport, n.f_name, cx.f_name, cl.f_name, "
                    "r.f_invoice, r.f_guest "
                    "from f_reservation r "
                    "left join f_room rm on rm.f_id=r.f_room "
                    "left join f_guests g on g.f_id=r.f_guest "
                    "left join f_nationality n on n.f_short=g.f_nation "
                    "left join f_cardex cx on cx.f_cardex=r.f_cardex "
                    "left join f_city_ledger cl on cl.f_id=r.f_cityledger "
                    "where r.f_startdate=:f_startdate and r.f_state=:f_state :cardex "
                    "order by r.f_room ";
    if (ui->leCardex->isEmpty()) {
        query.replace(":cardex", "");
    } else {
        query.replace(":cardex", QString(" and r.f_cardex='%1'").arg(ui->leCardex->text()));
    }
    dd[":f_startdate"] = ui->deDate->date();
    dd[":f_state"] = RESERVE_RESERVE;
    dd.exec(query);
    Utils::fillTableWithData(ui->tbl, dd.fDbRows);
    ui->tbl->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);
    QStringList tl;
    tl << QString::number(ui->tbl->rowCount());
    ui->tblTotal->setVerticalHeaderLabels(tl);
    int pax = 0;
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        pax += ui->tbl->toInt(i, col_pax);
    }
    ui->tblTotal->setValue(0, col_pax, pax);
}

void WQuickReservations::setRowSelected(int flag)
{
    if (flag < 0) {
        flag = flag == -1 ? 1 : 0;
        for (int i = 0; i < ui->tbl->rowCount(); i++) {
            ui->tbl->setValue(i, 0, flag, Qt::UserRole);
        }
        ui->tbl->viewport()->update();
        return;
    }
    int row = ui->tbl->currentRow();
    if (row < 0) {
        return;
    }
    ui->tbl->setValue(row, 0, flag, Qt::UserRole);
    ui->tbl->viewport()->update();
}


WQuickReservationsDelegate::WQuickReservationsDelegate(WQuickReservations *w)
{
    fSrc = w;
}

void WQuickReservationsDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (!index.isValid()) {
        return;
    }
    painter->save();
    QColor bgColor = Qt::white;
    if (index.column() == 0) {
        CacheRoom r;
        if (r.get(fSrc->room(index.row()))) {
            QString status;
            switch (r.fState()) {
            case ROOM_STATE_NONE:
                status = "VR";
                break;
            case ROOM_STATE_CHECKIN:
                bgColor = QColor::fromRgb(__s.value("checkincolor", -16733441).toInt());
                status = "CI";
                break;
            case ROOM_STATE_DIRTY:
                bgColor = Qt::yellow;
                status = "DR";
                break;
            case ROOM_STATE_OUTOF:
            case ROOM_STATE_OUTINVENTORY:
                bgColor = Qt::gray;
                status = "OO";
                break;
            }
            painter->fillRect(option.rect, bgColor);
            painter->drawText(option.rect, status);
        }
    } else {
        int selFlag = fSrc->model()->data(fSrc->model()->index(index.row(), 0), Qt::UserRole).toInt();
        QPen textColor(Qt::black);
        if (selFlag == 1) {
            bgColor = Qt::cyan;
        }
        if (option.state & QStyle::State_Selected) {
            bgColor = Qt::blue;
            textColor.setColor(Qt::white);
        }
        painter->setPen(textColor);
        painter->fillRect(option.rect, bgColor);
        QRect rText = option.rect;
        rText.adjust(2, 2, 0, 0);
        painter->drawText(rText, index.data().toString());
    }
    painter->restore();
}

QWidget *WQuickReservationsDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    QWidget *w = nullptr;
    switch (index.column()) {
    if (!r__(cr__room_status_change)) {
        message_error(tr("Access denied"));
        return nullptr;
    }
    case col_room_state: {
        int roomState = fSrc->roomState(index.row());
        switch (roomState) {
        case ROOM_STATE_NONE:
            break;
        case ROOM_STATE_DIRTY: {
            auto *rs = new RoomState(fSrc);
            rs->setRoom(QString::number(fSrc->room(index.row())));
            if (rs->exec() == QDialog::Accepted) {
                fSrc->updateTable();
            }
            delete rs;
            break;
        }
        case ROOM_STATE_CHECKIN: {
            DoubleDatabase dd(true, false);
            dd[":f_room"] = fSrc->room(index.row());
            dd[":f_state"] = RESERVE_CHECKIN;
            dd.exec("select f_invoice from f_reservation where f_room=:f_room and f_state=:f_state");
            if (dd.nextRow()) {
                WInvoice::openInvoiceWindow(dd.getString(0));
            }
            break;
        }
        }
        break;
    }
    case col_room:
    case col_room_category: {
        auto *r = new DlgCreateGroupReservation(parent);
        r->setDates(fSrc->dateEntry(index.row()), fSrc->dateDeparture(index.row()));
        r->setSingleMode(true);
        if (r->exec() == QDialog::Accepted) {
            QString err;
            if (WReservationRoomTab::check(r->fCode.toInt(), fSrc->dateEntry(index.row()), fSrc->dateDeparture(index.row()), fSrc->reservationCode(index.row()), err)) {
                DoubleDatabase dd(true, doubleDatabase);
                dd[":f_room"] = r->fCode.toInt();
                dd.update("f_reservation", where_id(ap(fSrc->reservationCode(index.row()))));
                dd[":f_room"] = r->fCode;
                dd.update("m_register", where_id(ap(fSrc->reservationCode(index.row()))));
                QModelIndex mr = fSrc->model()->index(index.row(), col_room);
                TrackControl::insert(TRACK_RESERVATION, "Room", fSrc->model()->data(mr).toString(), r->fCode, "", fSrc->invoiceCode(index.row()), fSrc->reservationCode(index.row()));
                fSrc->model()->setData(mr, r->fCode);
                CacheRoom cr;
                if (cr.get(r->fCode)) {
                    QModelIndex mc = fSrc->model()->index(index.row(), col_room_category);
                    fSrc->model()->setData(mc, cr.fName());
                }
                fSrc->broadcast(index.row());
            } else {
                message_error(err);
            }
        }
        delete r;
        break;
    }
    case col_date_entry:
    case col_date_departure:
        w = new EDateEdit(parent);
        static_cast<EDateEdit*>(w)->setFrame(false);
        break;
    case col_rate: {
        qDebug() << index.data(Qt::EditRole);
        auto *l = new EDoubleEdit(parent);
        l->setFrame(false);
        w = l;
        break;
    }
    case col_pax: {
        auto *p = new WQuickReservationsPax(parent);
        p->setReservationCode(fSrc->reservationCode(index.row()));
        p->move(fSrc->mapToGlobal(option.rect.topLeft()));
        p->exec();
        setModelData(p, fSrc->model(), index);
        delete p;
        break;
    }
    case col_first_name:
    case col_last_name: {
        auto *l = new EQLineEdit(parent);
        l->setFrame(false);
        w = l;
        break;
    }
    case col_nat: {
        auto *c = cache(cid_nation);
        QStringList codes, names;
        if (c->selector(codes, names, false)) {
            DoubleDatabase dd(true, doubleDatabase);
            dd[":f_reservation"] = fSrc->reservationCode(index.row());
            dd.exec("select f_guest from f_reservation_guests where f_reservation=:f_reservation");
            bool first = true;
            QString guestCodes;
            while (dd.nextRow()) {
                if (first) {
                    first = false;
                } else {
                    guestCodes += ",";
                }
                guestCodes += dd.getString(0);
            }
            dd[":f_nation"] = codes.at(0);
            dd.exec("update f_guests set f_nation=:f_nation where f_id in (" + guestCodes + ")");
            QModelIndex mc = fSrc->model()->index(index.row(), col_nat);
            TrackControl::insert(TRACK_RESERVATION, "Nation of " + fSrc->guestFullName(index.row()), fSrc->model()->data(mc).toString(), codes.at(0), "", fSrc->invoiceCode(index.row()), fSrc->reservationCode(index.row()));
            fSrc->model()->setData(mc, names.at(0));
        }
        break;
    }
    case col_cardex: {
        auto *c = cache(cid_cardex);
        QStringList codes, names;
        if (c->selector(codes, names, false)) {
            DoubleDatabase dd(true, doubleDatabase);
            dd[":f_cardex"] = codes.at(0);
            dd.update("f_reservation", where_id(ap(fSrc->reservationCode(index.row()))));
            QModelIndex mc = fSrc->model()->index(index.row(), col_cardex);
            if (fSrc->cardex(index.row()) != names.at(0)) {
                TrackControl::insert(TRACK_RESERVATION, "Cardex ", fSrc->model()->data(mc).toString(), names.at(0), "", fSrc->invoiceCode(index.row()), fSrc->reservationCode(index.row()));
            }
            fSrc->model()->setData(mc, names.at(0));
        }
        break;
    }
    default:
        w = new QWidget(parent);
        break;
    }
    return w;
}

void WQuickReservationsDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    switch (index.column()) {
    case col_date_entry:
    case col_date_departure: {
        auto *d = static_cast<EDateEdit*>(editor);
        d->setDate(index.data(Qt::EditRole).toDate());
        break;
    }
    case col_rate: {
        auto *l = static_cast<EDoubleEdit*>(editor);
        l->setDouble(index.data(Qt::EditRole).toDouble());
        break;
    }
    case col_first_name:
    case col_last_name: {
        auto *l = static_cast<EQLineEdit*>(editor);
        l->setText(index.data(Qt::EditRole).toString());
        break;
    }
    }
}

void WQuickReservationsDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    switch (index.column()) {
    case 0: {
        auto *c = static_cast<EQCheckBox*>(editor);
        model->setData(index, c->isChecked() ? "x" : "", Qt::EditRole);
        break;
    }
    case col_date_entry: {
            auto *d = static_cast<EDateEdit*>(editor);
            QString err;
            if (WReservationRoomTab::check(fSrc->room(index.row()), d->date(), fSrc->dateDeparture(index.row()), fSrc->reservationCode(index.row()), err)) {
                DoubleDatabase dd(true, doubleDatabase);
                dd[":f_startdate"] = d->date();
                dd.update("f_reservation", where_id(ap(fSrc->reservationCode(index.row()))));
                TrackControl::insert(TRACK_RESERVATION, "Entry date", model->data(index).toString(), d->text(), "", fSrc->invoiceCode(index.row()), fSrc->reservationCode(index.row()));
                model->setData(index, d->date());
                fSrc->broadcast(index.row());
            } else {
                message_error(err);
            }
            break;
        }
    case col_date_departure: {
        auto *d = static_cast<EDateEdit*>(editor);
        QString err;
        if (WReservationRoomTab::check(fSrc->room(index.row()), fSrc->dateEntry(index.row()), d->date(), fSrc->reservationCode(index.row()), err)) {
            DoubleDatabase dd(true, doubleDatabase);
            dd[":f_enddate"] = d->date();
            dd.update("f_reservation", where_id(ap(fSrc->reservationCode(index.row()))));
            TrackControl::insert(TRACK_RESERVATION, "Departure date", model->data(index).toString(), d->text(), "", fSrc->invoiceCode(index.row()), fSrc->reservationCode(index.row()));
            model->setData(index, d->date());
            fSrc->broadcast(index.row());
        } else {
            message_error(err);
        }
        break;
    }
    case col_rate: {
        auto *l = static_cast<EDoubleEdit*>(editor);
        DoubleDatabase dd(true, doubleDatabase);
        dd[":f_roomfee"] = l->getDouble();
        dd.update("f_reservation", where_id(ap(fSrc->reservationCode(index.row()))));
        dd[":f_id"] = fSrc->reservationCode(index.row());
        dd.exec("update f_reservation set f_pricepernight=coalesce(f_roomfee, 0)+coalesce(f_extrabedfee, 0)+coalesce(f_mealprice, 0) where f_id=:f_id");
        dd[":f_id"] = fSrc->reservationCode(index.row());
        dd.exec("update f_reservation set f_grandtotal=f_pricepernight* datediff(f_enddate, f_startdate) where f_id=:f_id");
        TrackControl::insert(TRACK_RESERVATION, "Room rate", model->data(index).toString(), l->text(), "", fSrc->invoiceCode(index.row()), fSrc->reservationCode(index.row()));
        model->setData(index, l->getDouble());
        break;
    }
    case col_pax: {
        auto *p = static_cast<WQuickReservationsPax*>(editor);
        model->setData(index, p->pax());
        break;
    }
    case col_first_name: {
            auto *l = static_cast<EQLineEdit*>(editor);
            DoubleDatabase dd(true, doubleDatabase);
            dd[":f_firstname"] = l->text();
            dd.update("f_guests", where_id(fSrc->guestCode(index.row())));
            TrackControl::insert(TRACK_RESERVATION, "First name of guest of " + fSrc->guestFullName(index.row()), fSrc->model()->data(fSrc->model()->index(index.row(), col_first_name)).toString(), l->text(), "", fSrc->invoiceCode(index.row()), fSrc->reservationCode(index.row()));
            model->setData(index, l->text());
            break;
        }
    case col_last_name: {
        auto *l = static_cast<EQLineEdit*>(editor);
        DoubleDatabase dd(true, doubleDatabase);
        dd[":f_lastname"] = l->text();
        dd.update("f_guests", where_id(fSrc->guestCode(index.row())));
        TrackControl::insert(TRACK_RESERVATION, "Last name of guest of " + fSrc->guestFullName(index.row()), fSrc->model()->data(fSrc->model()->index(index.row(), col_last_name)).toString(), l->text(), "", fSrc->invoiceCode(index.row()), fSrc->reservationCode(index.row()));
        model->setData(index, l->text());
        break;
    }
    }
}

void WQuickReservationsDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QItemDelegate::updateEditorGeometry(editor, option, index);
}

void WQuickReservations::on_btnTrackControl_clicked()
{
    int row = ui->tbl->currentRow();
    if (row < 0) {
        return;
    }
    DlgTracking::showTracking(ui->tbl->toString(row, col_reservation));
}

void WQuickReservations::on_btnOpenReservation_clicked()
{
    int row = ui->tbl->currentRow();
    if (row < 0) {
        return;
    }
    WReservation::openReserveWindows(reservationCode(row));
}

void WQuickReservations::on_btnGuests_clicked()
{
    int row = ui->tbl->currentRow();
    if (row < 0) {
        return;
    }
    WQuickReservationsGuests *g = new WQuickReservationsGuests(this);
    g->setRoom(reservationCode(row));
    g->exec();
    g->deleteLater();
}

void WQuickReservations::on_btnCheckinSelected_clicked()
{
    QStringList codes;
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        if (ui->tbl->itemValue(i, 0, Qt::UserRole).toInt() == 1) {
            codes << ui->tbl->toString(i, col_reservation);
        }
    }
    if (codes.count() == 0) {
        message_info(tr("No reservations was selected"));
        return;
    }
    WQuickReservationsCheckin *w = new WQuickReservationsCheckin(this);
    w->setReservations(codes);
    w->exec();
    delete w;
    refresh();
}