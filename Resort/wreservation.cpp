#include "wreservation.h"
#include "ui_wreservation.h"
#include "wguest.h"
#include "wreservationroomtab.h"
#include "cacheroom.h"
#include "cacheguest.h"
#include "dlgtracking.h"
#include "dlgopengrouporsingle.h"
#include "dlggroupreservationfuck.h"
#include "dlghelp.h"
#include "logging.h"
#include <QPushButton>
#include <QCloseEvent>

WReservation::WReservation(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WReservation)
{
    ui->setupUi(this);
    ui->lbGroup->setVisible(false);
    ui->leGroup->setVisible(false);
    ui->leGroupName->setVisible(false);
    ui->btnRecheckin->setVisible(r__(cr__re_checkin));
    ui->btnCancelation->setVisible(r__(cr__reserve_cancelation));
    ui->btnAddRemoveGroup->setVisible(r__(cr__reservation_group_reservation));
    ui->btnCancelGroup->setVisible(false);
    ui->btnSetGroupParams->setVisible(false);
    ui->btnSendConfirmation->setVisible(r__(cr__email_confirmation));
    QToolButton *b = new QToolButton();
    b->setIcon(QIcon(":/images/add.png"));
    connect(b, SIGNAL(clicked()), this, SLOT(newRoomTab()));
    ui->tab->setCornerWidget(b, Qt::TopRightCorner);
    connect(ui->tab, SIGNAL(tabCloseRequested(int)), this, SLOT(tabCloseRequest(int)));
    connect(ui->tab, SIGNAL(currentChanged(int)), this, SLOT(tabIndexChanged(int)));
    ui->btnTracking->setVisible(fPreferences.getDb(def_show_logs).toBool());
}

WReservation::~WReservation()
{
    delete ui;
}

void WReservation::loadReservation(const QString &id)
{
    WReservationRoomTab *r = newRoomTab();
    if (!r) {
        return;
    }
    ui->tab->tabBar()->tabButton(0, QTabBar::RightSide)->resize(0, 0);
    r->loadReservation(id);
    QString toolTip;
    ui->btnCheckIn->setEnabled(r->canCheckIn(toolTip));
    ui->btnCheckIn->setToolTip(toolTip);
    r->startTrackControl();
    r->trackControl()->resetChanges();
}

void WReservation::loadGroup(int id, int initFromRoom)
{
    DoubleDatabase fDD;
    fDD[":f_group"] = id;
    fDD.exec("select f_id from f_reservation where f_group=:f_group");
    while (fDD.nextRow()) {
        WReservationRoomTab *r = newRoomTab();
        ui->tab->tabBar()->tabButton(0, QTabBar::RightSide)->resize(0, 0);
        r->loadReservation(fDD.getString(0));
        QString toolTip;
        ui->btnCheckIn->setEnabled(r->canCheckIn(toolTip));
        ui->btnCheckIn->setToolTip(toolTip);
        r->startTrackControl();
        r->trackControl()->resetChanges();
    }
    if (initFromRoom > 0) {
        for (int i = 0; i < ui->tab->count(); i++) {
            WReservationRoomTab *r = static_cast<WReservationRoomTab *>(ui->tab->widget(i));
            if (r->roomCode().toInt() == initFromRoom) {
                ui->tab->setCurrentIndex(i);
                break;
            }
        }
    }
}

void WReservation::setInitialParams(const QDate &date1, const QDate &date2, QList<CacheRoom *> rooms)
{
    fDate1 = date1;
    fDate2 = date2;
    for (QList<CacheRoom * >::const_iterator it = rooms.begin(); it != rooms.end(); it++) {
        WReservationRoomTab *r = newRoomTab();
        if (!r) {
            return;
        }
        if (!( *it)) {
            return;
        }
        r->setBaseData(date1, date2, ( *it)->fCode());
        if (ui->tab->count() == 1) {
            ui->tab->tabBar()->tabButton(0, QTabBar::RightSide)->resize(0, 0);
        }
        if (fPreferences.getDb(def_room_arrangement).toInt() > 0) {
            r->cbRoomArrangement()->setIndexForData(fPreferences.getDb(def_room_arrangement).toInt());
        }
        r->startTrackControl();
    }
}

bool WReservation::activateDoc(const QString &id)
{
    for (int i = 0; i < ui->tab->count(); i++) {
        WReservationRoomTab *wr = static_cast<WReservationRoomTab *>(ui->tab->widget(i));
        if (wr->docId() == id) {
            ui->tab->setCurrentIndex(i);
            return true;
        }
    }
    return false;
}

int WReservation::groupId()
{
    return ui->leGroup->asInt();
}

QString WReservation::groupName()
{
    return ui->leGroupName->text();
}

void WReservation::setGroup(int group)
{
    bool visible = group > 0;
    ui->lbGroup->setVisible(visible);
    ui->leGroup->setVisible(visible);
    ui->leGroupName->setVisible(visible);
    ui->btnCancelGroup->setVisible(r__(cr__reserve_cancelation) && visible);
    ui->btnSetGroupParams->setVisible(r__(cr__edit_reservation) && visible);
    ui->leGroup->setInt(group);
    DoubleDatabase dd;
    dd[":f_id"] = group;
    dd.exec("select f_name from f_reservation_group where f_id=:f_id");
    if (dd.nextRow()) {
        ui->leGroupName->setText(dd.getString(0));
    }
}

void WReservation::openReserveWindows(const QString &code )
{
    DoubleDatabase fDD;
    fDD[":f_id"] = code;
    fDD.exec("select f_id, f_group from f_reservation where f_id=:f_id");
    if (!fDD.nextRow()) {
        message_error(tr("Could not load reservation"));
        return;
    }
    WReservation *w = nullptr;
    for (int i = 0; i < fMainWindow->fTab->count(); i++) {
        w = dynamic_cast<WReservation *>(fMainWindow->fTab->widget(i));
        if (w) {
            if (w->activateDoc(fDD.getString(0))) {
                fMainWindow->fTab->setCurrentIndex(i);
                return;
            }
        }
    }
    w = addTab<WReservation>();
    w->setGroup(fDD.getInt(1));
    w->loadReservation(fDD.getString(0));
    w->setFocus();
}

void WReservation::openReserveGroup(int group)
{
    WReservation *w = addTab<WReservation>();
    w->setGroup(group);
    w->loadGroup(group);
    w->setFocus();
}

void WReservation::openVaucher(const QString &id)
{
    DoubleDatabase fDD;
    fDD[":f_id"] = id;
    fDD.exec("select f_res from m_register where f_id=:f_id");
    if (fDD.nextRow()) {
        QString reserveId = fDD.getString(0);
        openReserveWindows(reserveId);
    }
}

void WReservation::handleBroadcast(const QMap<QString, QVariant> &data)
{
    if (data.contains("modified")) {
        for (int i = 0, count = ui->tab->count(); i < count; i++) {
            WReservationRoomTab *r = static_cast<WReservationRoomTab *>(ui->tab->widget(i));
            r->setModifiedByOther(data);
            QString why;
            ui->btnCheckIn->setEnabled(r->canCheckIn(why));
            ui->btnCheckIn->setToolTip(why);
        }
    }
}

void WReservation::setupTab()
{
    setupTabTextAndIcon(tr("Reservation"), ":/images/checkin.png");
}

bool WReservation::canClose()
{
    bool canClose = true;
    for (int i = 0, count = ui->tab->count(); i < count; i++) {
        WReservationRoomTab *r = static_cast<WReservationRoomTab *>(ui->tab->widget(i));
        bool tabClose = r->canClose();
        if (!tabClose) {
            switch (message_yesnocancel(QString("%1 #%2 %3")
                                        .arg(tr("Room"))
                                        .arg(r->roomCode())
                                        .arg(tr("modified, save changes?")))) {
                case RESULT_YES: {
                    QStringList errors;
                    if (!r->checkDoc(errors)) {
                        fMainWindow->setCurrentWidget(this);
                        ui->tab->setCurrentIndex(i);
                        QString errorMsg;
                        for (QStringList::const_iterator it = errors.begin(); it != errors.end(); it++) {
                            errorMsg += *it + "<br>";
                        }
                        message_error(errorMsg);
                        return false;
                    }
                    canClose = canClose && r->save();
                    break;
                }
                case RESULT_NO:
                    canClose = canClose && true;
                    break;
                case RESULT_NOALL:
                    canClose = true;
                    return canClose;
                case RESULT_CANCEL:
                    canClose = canClose && false;
                    fMainWindow->setCurrentWidget(this);
                    ui->tab->setCurrentIndex(i);
                    return false;
            }
        }
    }
    return canClose;
}

void WReservation::loadFromData(const QList<QVariant> &data)
{
    WReservation *w = 0;
    for (int i = 0; i < fMainWindow->fTab->count(); i++) {
        w = dynamic_cast<WReservation *>(fMainWindow->fTab->widget(i));
        if (w) {
            if (w->activateDoc(data.at(0).toString())) {
                fMainWindow->fTab->setCurrentIndex(i);
                return;
            }
        }
    }
    w = addTab<WReservation>();
    w->loadReservation(data.at(0).toString());
}

WReservationRoomTab *WReservation::newRoomTab(bool autocreate)
{
    DoubleDatabase fDD;
    WReservationRoomTab *rlast = 0;
    if (ui->tab->count() == 1 && ui->leGroup->asInt() == 0) {
        if (!autocreate) {
            if (message_confirm(tr("Create group reservation?")) == QDialog::Accepted) {
                int groupId = 0;
                fDD[":f_date"] = WORKING_DATE;
                fDD[":f_time"] = QTime::currentTime();
                groupId = fDD.insert("f_reservation_group");
                setGroup(groupId);
                rlast = static_cast<WReservationRoomTab *>(ui->tab->widget(0));
            } else {
                return 0;
            }
        }
    }
    if (!rlast && ui->tab->count() > 0) {
        rlast = static_cast<WReservationRoomTab *>(ui->tab->widget(0));
    }
    WReservationRoomTab *r = new WReservationRoomTab(this);
    r->setTab(ui->tab, ui->tab->count());
    ui->tab->addTab(r, QIcon(":/images/room-key.png"), tr("Room"));
    ui->tab->setCurrentIndex(ui->tab->count() - 1);
    connect(r, SIGNAL(roomChanged(QString, int)), this, SLOT(roomNameChanged(QString, int)));
    connect(r, SIGNAL(commonChanges()), this, SLOT(commonChanges()));
    r->startTrackControl();
    if (rlast) {
        //r->copyLast(rlast->reserveId());
    }
    return r;
}

void WReservation::commonChanges()
{
    WReservationRoomTab *r = static_cast<WReservationRoomTab *>(ui->tab->widget(ui->tab->currentIndex()));
    if (r->date1() != fDate1 || r->date2() != fDate2) {
        fDate1 = r->date1();
        fDate2 = r->date2();
    }
    ui->btnSave->setEnabled(r->reserveState() == RESERVE_RESERVE
                            || r->reserveState() == RESERVE_CHECKIN
                            || r->reserveState() == RESERVE_SERVICE);
    QString tp;
    ui->btnCheckIn->setEnabled(r->canCheckIn(tp));
    ui->btnCheckIn->setToolTip(tp);
    ui->btnCancelation->setEnabled(r->canCancel());
    ui->btnCopyLast->setEnabled(r->canCopyLast());
    ui->lbAuthor->setText(tr("Author") + ": " + r->author());
    ui->lbLastModify->setText(tr("Last modify") + ": " + r->lastModify());
    ui->btnRecheckin->setEnabled(r->canRecheckin());
    ui->btnRevive->setEnabled(r->reserveState() == RESERVE_REMOVED);
    ui->btnInvoice->setEnabled(r->canOpenInvoice());
}

void WReservation::tabCloseRequest(int index)
{
    if (index == 0) {
        return;
    }
    bool cc = true;
    WReservationRoomTab *r = static_cast<WReservationRoomTab *>(ui->tab->widget(index));
    if (!r->canClose()) {
        int msgResult = message_yesnocancel(QString("%1 #%2 %3")
                                            .arg(tr("Room"))
                                            .arg(r->roomCode())
                                            .arg(tr("was changed, save modifications?")));
        switch (msgResult) {
            case RESULT_YES: {
                QStringList errors;
                if (!r->checkDoc(errors)) {
                    fMainWindow->setCurrentWidget(this);
                    ui->tab->setCurrentIndex(index);
                    QString errorMsg;
                    for (QStringList::const_iterator it = errors.constBegin(); it != errors.constEnd(); it++) {
                        errorMsg += *it + "<br>";
                    }
                    message_error(errorMsg);
                    return;
                }
                cc = r->save();
                break;
            }
            case RESULT_NO:
                break;
            case RESULT_CANCEL:
                fMainWindow->setCurrentWidget(this);
                ui->tab->setCurrentIndex(index);
                cc = false;
                break;
        }
    }
    if (cc) {
        ui->tab->removeTab(index);
        delete r;
    }
}

void WReservation::tabIndexChanged(int index)
{
    Q_UNUSED(index)
    commonChanges();
}

void WReservation::roomNameChanged(const QString &name, int index)
{
    ui->tab->setTabText(index, name);
    QString rooms;
    bool first = true;
    for (int i = 0; i < ui->tab->count(); i++) {
        if (first) {
            first = false;
        } else {
            rooms += ",";
        }
        WReservationRoomTab *r = static_cast<WReservationRoomTab *>(ui->tab->widget(i));
        if (r->roomName().length() == 0) {
            rooms += "#0";
        } else {
            rooms += "#" + r->roomName();
        }
    }
    setupTabTextAndIcon(QString("%1 %2").arg(tr("Reservation"), rooms), ":/images/checkin.png");
}

void WReservation::on_btnSave_clicked()
{
    QStringList errors;
    for (int i = 0; i < ui->tab->count(); i++) {
        WReservationRoomTab *r = static_cast<WReservationRoomTab *>(ui->tab->widget(i));
        r->checkDoc(errors);
    }
    if (errors.count() > 0) {
        QString errorMessage;
        for (QStringList::const_iterator it = errors.constBegin(); it != errors.constEnd(); it++) {
            errorMessage += *it + "<br>";
        }
        message_error(errorMessage);
        return;
    }
    bool allSaved = true;
    bool saved = false;
    for (int i = 0; i < ui->tab->count(); i++) {
        WReservationRoomTab *r = static_cast<WReservationRoomTab *>(ui->tab->widget(i));
        allSaved = allSaved && r->save();
        if (!saved && allSaved) {
            saved = true;
        }
    }
    if (allSaved) {
        message_info(tr("Saved"));
    } else {
        message_error(tr("Could not save reservation (s)"));
    }
}

void WReservation::on_btnCheckIn_clicked()
{
    bool allSaved = true;
    QString errorString;
    logging::justLog("Before checkin pressed");
    WReservationRoomTab *r = static_cast<WReservationRoomTab *>(ui->tab->currentWidget());
    logging::justLog(QString("Checkin pressed. %1 %2").arg(r->reserveId()).arg(r->roomCode()));
    allSaved = allSaved && r->checkIn(errorString);
    ui->btnCheckIn->setEnabled(r->reserveState() == RESERVE_RESERVE);
    if (allSaved) {
        logging::writeLog(QString("Checkin success. %1 %2").arg(r->reserveId()).arg(r->roomCode()));
        if (ui->tab->count() == 1) {
            removeFromTabWidget();
        }
    } else {
        logging::justLog(QString("Checkin failed. %1 %2 %3").arg(r->reserveId()).arg(r->roomCode()).arg(errorString));
        message_error(tr("Checkin failed") + "<br>" + errorString);
    }
}

void WReservation::on_btnCancelation_clicked()
{
    WReservationRoomTab *r = static_cast<WReservationRoomTab *>(ui->tab->currentWidget());
    if (r->cancelReservation()) {
        ui->btnCancelation->setEnabled(false);
    }
}

void WReservation::on_btnCopyLast_clicked()
{
    WReservationRoomTab *r = static_cast<WReservationRoomTab *>(ui->tab->currentWidget());
    r->copyLast();
}

void WReservation::on_btnPrint_clicked()
{
    activeRoom()->print();
}

void WReservation::on_btnTracking_clicked()
{
    DlgTracking::showTracking(TRACK_RESERVATION,
                              static_cast<WReservationRoomTab *>(ui->tab->currentWidget())->reserveId());
}

void WReservation::on_btnRecheckin_clicked()
{
    int user = WORKING_USERID;
    if (!r__(cr__re_checkin)) {
        user = DlgRaiseUser::raiseUser(cr__re_checkin);
    }
    if (user == 0) {
        message_error(tr("Access denied"));
        return;
    }
    r()->reCheckin();
}

void WReservation::on_btnRevive_clicked()
{
    WReservationRoomTab *r =  static_cast<WReservationRoomTab *>(ui->tab->widget(ui->tab->currentIndex()));
    if (!r->canRevive()) {
        return;
    }
    r->revive();
}

WReservationRoomTab *WReservation::activeRoom()
{
    if (ui->tab->count() == 0) {
        return 0;
    }
    return static_cast<WReservationRoomTab *>(ui->tab->widget(ui->tab->currentIndex()));
}

void WReservation::on_btnCancelGroup_clicked()
{
    DoubleDatabase fDD;
    if (message_confirm(tr("Confirm to remove reservation group")) != QDialog::Accepted) {
        return;
    }
    QList<QList<QVariant> > dbrows;
    fDD[":f_state"] = RESERVE_RESERVE;
    fDD[":f_group"] = ui->leGroup->asInt();
    fDD.exec("select f_id from f_reservation where f_state=:f_state and f_group=:f_group", dbrows);
    fDD[":f_group"] = ui->leGroup->asInt();
    fDD[":f_state"] = RESERVE_REMOVED;
    fDD[":f_cancelUser"] = WORKING_USERID;
    fDD[":f_cancelDate"] = QDateTime::currentDateTime();
    fDD[":f_state1"] = RESERVE_RESERVE;
    fDD.exec("update f_reservation set f_state=:f_state, f_cancelUser=:f_cancelUser, f_cancelDate=:f_cancelDate where f_group=:f_group and f_state=:f_state1");
    for (int i = 0; i < ui->tab->count(); i++) {
        WReservationRoomTab *r = static_cast<WReservationRoomTab *>(ui->tab->widget(i));
        r->loadReservation(r->reserveId());
        // ui->btnCancelation->setEnabled(false);
    }
    ui->btnCancelGroup->setEnabled(false);
    ui->btnSetGroupParams->setEnabled(false);
    for (int i = 0; i < dbrows.count(); i++) {
        BroadcastThread::cmdRefreshCache(cid_reservation, dbrows.at(0).at(0).toString());
    }
}

void WReservation::on_btnSetGroupParams_clicked()
{
    /*
    QStringList errors;
    bool saveall = false;
    for (int i = 0; i < ui->tab->count(); i++) {
        WReservationRoomTab *r = static_cast<WReservationRoomTab*>(ui->tab->widget(i));
        if (r->reserveId().isEmpty()) {
            if (saveall) {
                if (r->checkDoc(errors)) {
                    r->save();
                } else {
                    message_error_lst(errors);
                    return;
                }
            } else {
                if (message_confirm(tr("There are not saved reservation, save?") != QDialog::Accepted) {
                    return;
                } else {
                    saveall = true;
                    if (r->checkDoc(errors)) {
                        r->save();
                    } else {
                        message_error_lst(errors);
                        return;
                    }
                }
            }
        }
    }

    DlgGroupParams *d = new DlgGroupParams(this);
    for (int i = 0; i < ui->tab->count(); i++) {
        WReservationRoomTab *r = static_cast<WReservationRoomTab*>(ui->tab->widget(i));
        d->setGroupId(ui->leGroup->asInt());
        d->setDate(r->date1(), r->date2());
    }
    if (d->exec() == QDialog::Accepted) {
        QVariant v;
        QStringList rooms = d->checkedRooms();
        foreach (QString s, rooms) {
            fDD[":f_group"] = ui->leGroup->asInt();
            fDD[":f_room"] = s.toInt();
            fDD.exec("select f_id, f_guest from f_reservation where f_group=:f_group and f_room=:f_room");
            QString reserve = fDbRows.at(0).at(0).toString();
            int guest = fDbRows.at(0).at(1).toInt();
            if (d->guest(v)) {
                fDD[":f_reservation"] = reserve;
                fDD[":f_guest"] = guest;
                fDD.exec("delete from f_reservation_guests where f_reservation=:f_reservation and f_guest=:f_guest");
                fDD[":f_reservation"] = reserve;
                fDD[":f_guest"] = v;
                fDD.insert("f_reservation_guests");
            }

            if (d->cardex(v)) {
                fDD[":f_cardex"] = v.toString();
            }
            if (d->guest(v)) {
                fDD[":f_guest"] = v.toString();
            }
            if (d->arrangement(v)) {
                fDD[":f_arrangement"] = v.toString();
            }
            if (d->remarks(v)) {
                fDD[":f_remarks"] = v.toString();
            }
            if (fDD.count() > 0) {
                fDD[":f_group"] = ui->leGroup->asInt();
                fDD[":f_room"] = s.toInt();
                fDD.update("f_reservation", fDD, "where f_group=:f_group and f_room=:f_room");
            }
            BroadcastThread::cmdRefreshCache(cid_reservation, reserve);
        }

        for (int i = 0; i < ui->tab->count(); i++) {
            WReservationRoomTab *r = static_cast<WReservationRoomTab*>(ui->tab->widget(i));
            if (!d->roomChecked(r->roomCode())) {
                continue;
            }
            if (d->cardex(v)) {
                r->setCardex(CacheCardex::instance()->get(v.toString()));
                fDD[":f_cardex"] = v.toString();
            }
            if (d->guest(v)) {
                r->setGuest(v.toInt(), true);
                fDD[":f_guest"] = v.toString();
            }
            if (d->arrangement(v)) {
                r->setArrangement(v.toInt());
                fDD[":f_arrangement"] = v.toString();
            }
            r->trackControl()->resetChanges(r->reserveId());
        }
    }
    delete d;
    */
    DlgGroupReservationFuck *d = addTab<DlgGroupReservationFuck>();
    d->loadGroup(ui->leGroup->asInt());
    /*
    for (int i = 0; i < ui->tab->count(); i++) {
        WReservationRoomTab *r = static_cast<WReservationRoomTab*>(ui->tab->widget(i));
        r->loadReservation(r->reserveId());
    }
    */
}

void WReservation::on_btnHelp_clicked()
{
    DlgHelp *d = new DlgHelp("reservation", this);
    d->exec();
    delete d;
}

void WReservation::on_btnAddRemoveGroup_clicked()
{
    r()->addRemoveFromGroup();
}

WReservationRoomTab *WReservation::r()
{
    return  static_cast<WReservationRoomTab *>(ui->tab->widget(ui->tab->currentIndex()));
}

void WReservation::on_btnSendConfirmation_clicked()
{
    r()->sendConfirmation();
}

void WReservation::on_btnInvoice_clicked()
{
    r()->openInvoice();
}
