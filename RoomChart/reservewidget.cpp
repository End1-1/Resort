#include "reservewidget.h"
#include "logging.h"
#include "ui_reservewidget.h"
#include "reserverect.h"
#include "cacheusers.h"
#include "reservewidgetaction.h"
#include "cachereservation.h"
#include "cachecardex.h"
#include "dlgooroomprop.h"
#include "vauchers.h"
#include "paymentmode.h"
#include "wreservationroomtab.h"
#include "message.h"
#include <QResizeEvent>

ReserveWidget::ReserveWidget(ReserveRect *rr, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReserveWidget)
{
    ui->setupUi(this);
    fRoom.get(rr->fRoom.fCode());
    fDateStart = rr->fDateStart;
    fDateEnd = rr->fDateEnd;
    //setSize();
}

ReserveWidget::ReserveWidget(const QString &code, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReserveWidget)
{
    ui->setupUi(this);
    fReservation.get(code);
    fDateStart = fReservation.fDateStart();
    fDateEnd = fReservation.fDateEnd();
    QSize s(COLUMN_WIDTH - 1, ROW_HEIGHT - 1);
    ui->btnCancel->setMaximumSize(s);
    ui->btnCancel->setMinimumSize(s);
    fRoom.get(fReservation.fRoom());
    setSize();
    setToolTip(fReservation.fRemarks());
    if (fReservation.fState() == RESERVE_OUTOFROOM) {
        if (__preferences.getLocalDate(def_working_day) >= fReservation.fDateStart() && __preferences.getLocalDate(def_working_day) <= fReservation.fDateEnd()) {

        }
    }
}

ReserveWidget::~ReserveWidget()
{
    delete ui;
}

void ReserveWidget::createService()
{
    DoubleDatabase fDD;
    fDD.startTransaction();
    QString err;
    if (!WReservationRoomTab::checkLocked(fDD, fRoom.fCode().toInt(), fDateStart, fDateEnd, QString(), err)) {
        fDD.rollback();
        if (err.isEmpty()) {
            err = tr("Cannot create draft");
        }
        writelog("room lock/overlap in ReserveWidget:createService " + err);
        message_error(err);
        return;
    }
    QString invId = uuidx(VAUCHER_INVOICE_N);
    fId = uuidx("RS");
    if (!fDD.insertId("f_reservation", fId)) {
        fDD.rollback();
        const QString insertErr = fDD.fLastError.isEmpty()
                ? tr("Cannot create draft")
                : fDD.fLastError;
        writelog("insert reservation failed in ReserveWidget:createService " + insertErr);
        message_error(insertErr);
        return;
    }
    fDD[":f_id"] = fId;
    fDD[":f_state"] = RESERVE_SERVICE;
    fDD[":f_reserveState"] = CONFIRM_BLOCK;
    fDD[":f_room"] = fRoom.fCode();
    fDD[":f_roomFee"] = fRoom.fPrice();
    fDD[":f_arrangement"] = 0;//__preferences.getDb(def_room_arrangement).toInt();
    fDD[":f_paymentType"] = PAYMENT_CASH;
    fDD[":f_man"] = 1;
    fDD[":f_mealIncluded"] = 1;
    const QString cardex = __preferences.getDb(def_default_cardex).toString();
    fDD[":f_cardex"] = cardex;
    CacheCardex cardexRow;
    if (cardexRow.get(cardex)) {
        fDD[":f_vatMode"] = cardexRow.fVatMode().toInt();
    }
    fDD[":f_startDate"] = fDateStart;
    fDD[":f_endDate"] = fDateEnd;
    fDD[":f_author"] = __preferences.getLocal(def_working_user_id).toInt();
    fDD[":f_invoice"] = invId;
    if (!fDD.update("f_reservation", where_id(ap(fId))) || !fDD.commit()) {
        fDD.rollback();
        const QString commitErr = fDD.fLastError.isEmpty()
                ? tr("Cannot create draft")
                : fDD.fLastError;
        writelog("commit reservation failed in ReserveWidget:createService " + commitErr);
        message_error(commitErr);
        return;
    }

    TrackControl tc(TRACK_RESERVATION);
    tc.fReservation = fId;
    tc.fInvoice = invId;
    tc.insert("-=CREATED DRAFT=-", QString("%1, %2 - %3, room #%4")
                              .arg(fId + "/" + invId)
                              .arg(fDateStart.toString(def_date_format))
                              .arg(fDateEnd.toString(def_date_format))
                              .arg(fRoom.fCode()), "");
    BroadcastThread::cmdRefreshCache(cid_reservation, fId);
}

void ReserveWidget::removeService()
{
    if (fReservation.fArrangement() > 0) {
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_state"] = RESERVE_SERVICE_REMOVED;
    fDD.update("f_reservation", where_id(ap(fReservation.fId())));

    TrackControl tc(TRACK_RESERVATION);
    tc.fRecord = fReservation.fId();
    tc.fReservation = fReservation.fId();
    tc.fInvoice = fReservation.fInvoice();
    tc.insert("-=REMOVE DRAFT=-", QString("%1, %2 - %3, room #%4")
                              .arg(fReservation.fId() + "/" + fReservation.fInvoice())
                              .arg(fDateStart.toString(def_date_format))
                              .arg(fDateEnd.toString(def_date_format))
                              .arg(fRoom.fCode()), "");
    deleteLater();
    BroadcastThread::cmdRefreshCache(cid_reservation, fReservation.fId());
}

void ReserveWidget::resizeEvent(QResizeEvent *e)
{
    QString state;
    switch (fReservation.fState()) {
    case RESERVE_OUTOFINVENTORY:
        state = "O/I ";
        setStyleSheet("background:#4a4a4a;");
        ui->lbCaption->setStyleSheet("color:white;");
        break;
    case RESERVE_OUTOFROOM:
        state = "O/O ";
        setStyleSheet("background:#585858;");
        ui->lbCaption->setStyleSheet("color:white;");
        break;
    default:
        setStyleSheet("background:#c7a0f4;");
        ui->lbCaption->setStyleSheet("color:black;");
        break;
    }

    QFont f(qApp->font().family(), 6);
    QString text = "#" + fRoom.fCode();
    if (e->size().width() < COLUMN_WIDTH * 3) {
        text = "";
    } if (e->size().width() > COLUMN_WIDTH * 3) {
        text = state + text + "\n" + QString("%1 - %2")
                .arg(fDateStart.toString("dd, ddd"))
                .arg(fDateEnd.toString("dd, ddd"));
        f.setPointSize(6);
    }
    if (e->size().width() > COLUMN_WIDTH * 6) {
        f.setPointSize(8);
        text = QString("%1#%2 %3 - %4")
                .arg(state)
                .arg(fRoom.fCode())
                .arg(fDateStart.toString("dd, ddd"))
                .arg(fDateEnd.toString("dd, ddd"));
    }
    ui->lbCaption->setFont(f);
    ui->lbCaption->setText(text);
    QWidget::resizeEvent(e);
}

void ReserveWidget::on_btnCancel_clicked()
{
    DoubleDatabase fDD;
    if (fReservation.fState() == RESERVE_OUTOFROOM) {
        DlgOORoomProp *d = new DlgOORoomProp(fReservation.fId(), fMainWindow);
        d->exec();
        delete d;
        return;
    }
    ReserveWidgetAction *ra = new ReserveWidgetAction(__preferences.getDefaultParentForMessage());
    ra->setReservation(fReservation.fId());
    CacheUsers cu;
    cu.get(fReservation.fAuthor());
    ra->setAuthor(cu.fName());
    ra->setRemarks(fReservation.fRemarks());
    ra->lock(fReservation.fArrangement());
    bool broadcast = true;
    if (ra->exec() == QDialog::Accepted) {
        QString remarks = ra->remarks();
        if (remarks != fReservation.fRemarks()) {
            fReservation.fRemarks() = remarks;
            fDD[":f_remarks"] = ra->remarks();
            fDD.update("f_reservation", where_id(ap(fReservation.fId())));
            broadcast = true;
        }
        switch (ra->fResult) {
        case 1:
            emit editReserv(fReservation.fId());
            break;
        case 2:
            fDD[":f_arrangement"] = __preferences.getLocal(def_working_user_id).toInt();
            fDD.update("f_reservation", where_id(ap(fReservation.fId())));
            break;
        case 3:
            fDD[":f_arrangement"] = 0;
            fDD.update("f_reservation", where_id(ap(fReservation.fId())));
            break;
        case 4:
            fReservation.setValue("f_arrangement", 0);
            removeService();
            return;
        case 5:
            fDD[":f_state"] = RESERVE_OUTOFROOM;
            fDD.update("f_reservation", where_id(ap(fReservation.fId())));
            if (fReservation.fDateStart() == __preferences.getLocal(def_working_day).toDate()) {
                fDD[":f_state"] = RESERVE_OUTOFROOM;
                fDD.update("f_room", where_id(fReservation.fRoom()));
            }
            broadcast = true;
            break;
        case 6:
            fDD[":f_state"] = RESERVE_OUTOFINVENTORY;
            fDD.update("f_reservation", where_id(ap(fReservation.fId())));
            if (fReservation.fDateStart() == __preferences.getLocalDate(def_working_day)) {
                fDD[":f_state"] = RESERVE_OUTOFINVENTORY;
                fDD.update("f_room", where_id(fReservation.fRoom()));
            }
            broadcast = true;
            break;
        }
    } else {
        broadcast = false;
    }
    if (broadcast) {
        BroadcastThread::cmdRefreshCache(cid_reservation, fReservation.fId());
        BroadcastThread::cmdRefreshCache(cid_room, fReservation.fRoom());
    }
    delete ra;
}

void ReserveWidget::setSize()
{
    int width;
    if (fReservation.fState() == RESERVE_SERVICE) {
        // Half-day on both ends: start afternoon, end morning (like a normal stay handoff)
        if (fDateEnd > fDateStart) {
            width = COLUMN_WIDTH * fDateStart.daysTo(fDateEnd);
        } else {
            width = COLUMN_WIDTH / 2;
        }
    } else {
        int div = 1;
        if (fReservation.hasNext()) {
            div = 2;
        }
        width = ((fDateStart.daysTo(fDateEnd)) * COLUMN_WIDTH) + (COLUMN_WIDTH / div);
    }
    setMinimumSize(width, ROW_HEIGHT);
    setMaximumSize(width, ROW_HEIGHT);
}
