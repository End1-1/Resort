#include "dlggroupreservationfuck.h"
#include "ui_dlggroupreservationfuck.h"
#include "cachereservation.h"
#include "cacheroom.h"
#include "cacheroomarrangment.h"
#include "cacheguest.h"
#include "wguest.h"
#include "dlgreservationremarks.h"
#include "waccinvoice.h"
#include "cachecardex.h"
#include "paymentmode.h"
#include "dlgtracking.h"
#include "cachegroupreservations.h"
#include "dlggrouprevive.h"
#include "winvoice.h"
#include "cacheredreservation.h"
#include "wreservation.h"
#include "vauchers.h"
#include "pprintscene.h"
#include "pprintpreview.h"
#include "wreservationroomtab.h"
#include "ptextrect.h"
#include "pimage.h"
#include <QInputDialog>

DlgGroupReservationFuck::DlgGroupReservationFuck(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::DlgGroupReservationFuck)
{
    ui->setupUi(this);
    Utils::tableSetColumnWidths(ui->tblCat, ui->tblCat->columnCount(),
                                30, 30, 30, 40, 40, 70, 30);
    ui->tblCat->setMaximumWidth(350);
    ui->tblCat->setMinimumWidth(350);
    QStringList ht;
    ht << QString("RS") << QString("Room") << QString("Cat") << QString("Bed") <<
       QString("Arrival") << QString("Departure") << QString("Price") <<
       QString("Nights") << QString("Total") <<
       QString("Arr.") << QString("Guest") << QString("Remarks") <<
       QString("Male") << QString("Female") << QString("Child") << QString("GuestCode") <<
       QString("X") << QString("O") << QString("R") << QString("I") << QString("State") << QString("State id");
    ui->tblRoom->setHorizontalHeaderLabels(ht);
    Utils::tableSetColumnWidths(ui->tblRoom, ui->tblRoom->columnCount(),
                                100, 40, 40, 40, 100, 100, 50, 80, 80, 55, 200, 0, 50, 50, 50, 0, 30, 30, 30, 30, 80, 0);
    DoubleDatabase fDD;
    fDD.exec("select rc.f_short, rm.f_bed, rm.f_rate, count(rm.f_id) as f_room "
             "from f_room rm "
             "inner join f_room_classes rc on rc.f_id=rm.f_class "
             "group by 1, 2");
    ui->tblCat->setRowCount(fDD.rowCount());
    for (int i = 0; i < fDD.rowCount(); i++) {
        ui->tblCat->setItemWithValue(i, 0, fDD.getValue(i, "f_short"));
        ui->tblCat->setItemWithValue(i, 1, fDD.getValue(i, "f_bed"));
        ui->tblCat->setItemWithValue(i, 2, fDD.getValue(i, "f_room"));
        ui->tblCat->setItemWithValue(i, 3, 0);
        EQLineEdit *l = ui->tblCat->addLineEdit(i, 4, false);
        l->setReadOnly(true);
        connect(l, SIGNAL(textChanged(QString)), this, SLOT(preCount(QString)));
        l = ui->tblCat->addLineEdit(i, 5, false);
        l->setReadOnly(true);
        connect(l, SIGNAL(textChanged(QString)), this, SLOT(preCount(QString)));
        ui->tblCat->addButton(i, 6, SLOT(createMultiRoom(int)), this, QIcon(":/images/goto.png"));
    }
    ui->tblCat->setMaximumHeight(((ui->tblCat->rowCount() + 1) *ui->tblCat->verticalHeader()->defaultSectionSize()) + 15);
    ui->tblCat->setMinimumHeight(((ui->tblCat->rowCount() + 1) *ui->tblCat->verticalHeader()->defaultSectionSize()) + 15);
    CacheInstance *ci = cache(cid_room);
    CacheRoom itroom;
    itroom.fInstance = ci;
    QMap<QString, QList<QVariant> >::iterator it = ci->fRows.begin();
    while (it != ci->fRows.end()) {
        itroom.fData = it.value();
        for (int i = 0; i < ui->tblCat->rowCount(); i++) {
            if (ui->tblCat->toString(i, 0) == itroom.fCategoryShort() && ui->tblCat->toString(i, 1) == itroom.fBed()) {
                ui->tblCat->setItemWithValue(i, 3, ui->tblCat->toInt(i, 3) + 1);
                break;
            }
        }
        it++;
    }
    ui->leCardexCode->setSelector(this, cache(cid_cardex), ui->leCardexName, cid_cardex);
    ui->leCardexCode->setInitialValue(fPreferences.getDb(def_default_cardex).toString());
    fCurrRow = -1;
    ui->leGuest->setSelector(this, cache(cid_guest), ui->leGuest);
    connect(ui->teCommonRemark, &EQTextEdit::doubleClicked, [this]() {
        QString remark = ui->teCommonRemark->toPlainText();
        if (DlgReservationRemarks::Remarks(remark)) {
            ui->teCommonRemark->setPlainText(remark);
        }
    });
    connect(ui->teIndRemarks, &EQTextEdit::doubleClicked, [this]() {
        QString remark = ui->teIndRemarks->toPlainText();
        if (DlgReservationRemarks::Remarks(remark)) {
            ui->teIndRemarks->setPlainText(remark);
        }
    });
    fDockRoom = new DlgSimpleSelectRoom(this);
    fDockRoom->show();
    fDockRoom->hide();
    ui->leCLCode->setSelector(this, cache(cid_city_ledger), ui->leCLName);
    ui->leCardCode->setSelector(this, cache(cid_credit_card), ui->leCardName);
    countReserve();
    on_cbModeOfPayment_currentIndexChanged(0);
    ui->cbArr->setIndexForData(fPreferences.getDb(def_room_arrangement));
    connect(cache(cid_reservation), SIGNAL(updated(int, QString)), this, SLOT(reservationCacheUpdated(int, QString)));
    fTrackControl = new TrackControl(TRACK_RESERVATION);
    fGroupTrackControl = new TrackControl(TRACK_RESERVATION_GROUP);
    fGroupTrackControl->addWidget(ui->leGroupName, "Group name")
    .addWidget(ui->leCardexName, "Cardex")
    .addWidget(ui->leCLName, "City ledger")
    .addWidget(ui->teCommonRemark, "All remarks");
}

DlgGroupReservationFuck::~DlgGroupReservationFuck()
{
    delete ui;
    fGroupTrackControl->saveChanges();
    fGroupTrackControl->deleteLater();
}

void DlgGroupReservationFuck::openGroup(int id)
{
    DlgGroupReservationFuck *d = addTab<DlgGroupReservationFuck>();
    d->loadGroup(id);
}

void DlgGroupReservationFuck::loadGroup(int id)
{
    ui->tblRoom->clearContents();
    ui->tblRoom->setRowCount(0);
    DoubleDatabase fDD;
    fDD[":f_id"] = id;
    fDD.exec("select * from f_reservation_group where f_id=:f_id");
    fDD.nextRow();
    ui->leGroupCode->setInt(id);
    ui->leGroupName->setText(fDD.getValue("f_name").toString());
    ui->deArrival->setDate(fDD.getValue("f_entry").toDate());
    ui->deDeparture->setDate(fDD.getValue("f_departure").toDate());
    ui->leCardexCode->setInitialValue(fDD.getValue("f_cardex").toString());
    ui->cbArr->setIndexForData(fDD.getValue("f_arrangement").toInt());
    ui->lePrice->setDouble(fDD.getValue("f_price").toDouble());
    ui->cbModeOfPayment->setIndexForData(fDD.getValue("f_paymentMode").toInt());
    ui->leGuest->fHiddenText = fDD.getValue("f_guest").toString();
    ui->leExtraname->setText(fDD.getValue("f_extra1").toString());
    CacheGuest g;
    if (g.get(ui->leGuest->fHiddenText)) {
        ui->leGuest->setText(g.fName());
        ui->leGuest->fHiddenText = g.fId();
    }
    ui->leCLCode->setInitialValue(fDD.getValue("f_cityLedger").toString());
    ui->leCardCode->setInitialValue(fDD.getValue("f_card").toString());
    ui->teCommonRemark->setPlainText(fDD.getValue("f_remarks").toString());
    on_cbModeOfPayment_currentIndexChanged(0);
    fDD[":f_group"] = id;
    fDD.exec("select r.f_id, r.f_room, rc.f_short, rm.f_bed, r.f_startDate, r.f_endDate, "
             "r.f_pricePerNight, r.f_arrangement, g.guest, r.f_remarks, r.f_guest, r.f_paymentType, "
             "r.f_cardex, r.f_man, r.f_woman, r.f_child, r.f_state, rs.f_en as state_name "
             "from f_reservation r "
             "left join guests g on g.f_id=r.f_guest "
             "left join f_room rm on rm.f_id=r.f_room "
             "left join f_reservation_state rs on rs.f_id=r.f_state "
             "left join f_room_classes rc on rc.f_id=rm.f_class "
             "where r.f_group=:f_group and r.f_state in (1,2,3,6) ");
    bool editable = false;
    for (int i = 0; i < fDD.rowCount(); i++) {
        int row = ui->tblRoom->rowCount();
        ui->tblRoom->setRowCount(row + 1);
        ui->tblRoom->setItemWithValue(row, 0, fDD.getValue(i, "f_id"));
        EQLineEdit *l = ui->tblRoom->addLineEdit(row, 1, false);
        l->fClickBool = true;
        l->setText(fDD.getValue(i, "f_room").toString());
        connect(l, SIGNAL(textEdited(QString)), this, SLOT(roomTextChanged(QString)));
        connect(l, SIGNAL(customButtonClicked(bool)), this, SLOT(openRoomSelectDialog(bool)));
        ui->tblRoom->setItemWithValue(row, 2, fDD.getValue(i, "f_short"));
        ui->tblRoom->setItemWithValue(row, 3, fDD.getValue(i, "f_bed"));
        EDateEdit *d = ui->tblRoom->addDateEdit(row, 4, false);
        d->setDate(fDD.getValue(i, "f_startDate").toDate());
        connect(d, SIGNAL(textEdited(QString)), this, SLOT(roomTextChanged(QString)));
        d = ui->tblRoom->addDateEdit(row, 5, false);
        d->setDate(fDD.getValue(i, "f_endDate").toDate());
        connect(d, SIGNAL(textEdited(QString)), this, SLOT(roomTextChanged(QString)));
        l = ui->tblRoom->addLineEdit(row, 6, false);
        l->setDouble(fDD.getValue(i, "f_pricePerNight").toDouble());
        connect(l, SIGNAL(textChanged(QString)), this, SLOT(roomPriceChanged(QString)));
        EQComboBox *c = ui->tblRoom->addComboBox(row, 9);
        c->setCache(cid_room_arrangment);
        c->setCurrentIndex(c->findData(fDD.getValue(i, "f_arrangement").toInt()));
        EQLineEdit *lg = ui->tblRoom->addLineEdit(row, 10, false);
        lg->setText(fDD.getValue(i, "guest").toString());
        lg->fHiddenText = fDD.getValue(i, "f_guest").toString();
        connect(lg, SIGNAL(customButtonClicked(bool)), this, SLOT(singleGuestLineEdit(bool)));
        connect(lg, SIGNAL(focusIn()), this, SLOT(singleGuestFocusOut()));
        ui->tblRoom->setItemWithValue(row, 11, fDD.getValue(i, "f_remarks"));
        lg = ui->tblRoom->addLineEdit(row, 12, false);
        lg->setInt(fDD.getValue(i, "f_man").toInt());
        lg = ui->tblRoom->addLineEdit(row, 13, false);
        lg->setInt(fDD.getValue(i, "f_woman").toInt());
        lg = ui->tblRoom->addLineEdit(row, 14, false);
        lg->setInt(fDD.getValue(i, "f_child").toInt());
        ui->tblRoom->setItemWithValue(row, 15, fDD.getValue(i, "f_guest"));
        ui->tblRoom->addButton(row, 16, SLOT(removeRow()), this, QIcon(":/images/garbage.png"));
        ui->tblRoom->setItemWithValue(row, 17, "O");
        if (fDD.getValue(i, "f_state").toInt() == 2) {
            editable = true;
        }
        if (fDD.getValue(i, "f_state").toInt() != 2) {
            ui->tblRoom->lineEdit(row, 1)->setEnabled(false);
            ui->tblRoom->dateEdit(row, 4)->setEnabled(false);
            ui->tblRoom->dateEdit(row, 5)->setEnabled(false);
            ui->tblRoom->lineEdit(row, 6)->setEnabled(false);
            ui->tblRoom->comboBox(row, 9)->setEnabled(false);
            ui->tblRoom->lineEdit(row, 10)->setEnabled(false);
            ui->tblRoom->lineEdit(row, 12)->setEnabled(false);
            ui->tblRoom->lineEdit(row, 13)->setEnabled(false);
            ui->tblRoom->lineEdit(row, 14)->setEnabled(false);
        }
        if (fDD.getValue(i, "f_state").toInt() == 2) {
            ui->tblRoom->addButton(row, 18, SLOT(editReserve()), this, QIcon(":/images/bed.png"));
        }
        if (fDD.getValue(i, "f_state").toInt() == 3) {
            ui->tblRoom->button(row, 16)->setEnabled(false);
            ui->tblRoom->addButton(row, 18, SLOT(editReserve()), this, QIcon(":/images/bed.png"));
            ui->tblRoom->addButton(row, 19, SLOT(editAInvoice()), this, QIcon(":/images/invoice.png"));
        }
        if (fDD.getValue(i, "f_state").toInt() == 1) {
            ui->tblRoom->button(row, 16)->setEnabled(false);
            ui->tblRoom->addButton(row, 18, SLOT(editReserve()), this, QIcon(":/images/bed.png"));
            ui->tblRoom->addButton(row, 19, SLOT(editInvoice()), this, QIcon(":/images/invoice.png"));
        }
        if (fDD.getValue(i, "f_state").toInt() == RESERVE_REMOVED) {
            ui->tblRoom->button(row, 16)->setEnabled(false);
        }
        ui->tblRoom->setItemWithValue(row, 20, fDD.getValue(i, "state_name").toString());
        ui->tblRoom->setItemWithValue(row, 21, fDD.getValue(i, "f_state").toInt());
        makeTrackControl(row);
    }
    countTotalReservation();
    ui->wll->setEnabled(editable || r__(cr__super_correction));
    ui->wl->setEnabled(editable || r__(cr__super_correction));
    ui->wr->setEnabled(editable || r__(cr__super_correction));
    ui->btnSave->setEnabled(editable || r__(cr__super_correction));
    ui->btnClear->setEnabled(editable || r__(cr__super_correction));
    ui->btnClearFilter->setEnabled(editable || r__(cr__super_correction));
    fGroupTrackControl->fRecord = ui->leGroupCode->text();
    fGroupTrackControl->resetChanges();
}

void DlgGroupReservationFuck::setup()
{
    setupTabTextAndIcon(tr("Group reservation"), ":/images/groupreservation.png");
}

void DlgGroupReservationFuck::callback(int sel, const QString &code)
{
    switch (sel) {
        case cid_cardex: {
            CacheCardex cc;
            if (!cc.get(code)) {
                return;
            }
            ui->leCardCode->setProperty("vatmode", cc.fVatMode());
            DoubleDatabase dd;
            for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
                dd[":f_id"] = ui->tblRoom->toString(i, 0);
                dd[":f_vatmode"] = cc.fVatMode();
                dd.exec("update f_reservation set f_vatmode=:f_vatmode where f_id=:f_id");
            }
            break;
        }
    }
}

void DlgGroupReservationFuck::reservationCacheUpdated(int cacheId, const QString &id)
{
    Q_UNUSED(cacheId);
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        if (ui->tblRoom->toString(i, 0).compare(id) == 0) {
            ui->tblRoom->item(i, 0)->setBackground(Qt::magenta);
            ui->tblRoom->setCurrentCell(-1, -1);
            return;
        }
    }
}

void DlgGroupReservationFuck::singleGuestFocusOut()
{
}

void DlgGroupReservationFuck::singleGuestLineEdit(bool)
{
}

void DlgGroupReservationFuck::preCount(const QString &str)
{
    Q_UNUSED(str)
    double total = 0;
    int qty = 0;
    for (int i = 0; i < ui->tblCat->rowCount(); i++) {
        total += (ui->tblCat->lineEdit(i, 5)->asDouble());
        qty += ui->tblCat->lineEdit(i, 4)->asInt();
    }
    /*for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        if (ui->tblRoom->toInt(i, 21) != 2) {
            //total -= ui->tblRoom->toDouble(i, 8);
            qty --;
        }
    }*/
    ui->lePreQty->setInt(qty);
    ui->lePreAmount->setDouble(total);
}

void DlgGroupReservationFuck::removeRow()
{
    EPushButton *btn = static_cast<EPushButton *>(sender());
    int row = -1;
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        EPushButton *btnWidget = static_cast<EPushButton *>(ui->tblRoom->cellWidget(i, 16));
        if (btnWidget == btn) {
            row = i;
            break;
        }
    }
    if (row < 0) {
        return;
    }
    if (message_confirm(tr("Confirm to remove selected row")) != QDialog::Accepted) {
        return;
    }
    if (ui->tblRoom->toString(row, 0).isEmpty()) {
        ui->tblRoom->removeRow(row);
        countTotalReservation();
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_state"] = RESERVE_REMOVED;
    fDD.update("f_reservation", where_id(ap(ui->tblRoom->toString(row, 0))));
    BroadcastThread::cmdRefreshCache(cid_reservation, ui->tblRoom->toString(row, 0));
    fGroupTrackControl->insertMessage("Reservation removed", QString("%1, %2").arg(ui->tblRoom->toString(row,
                                      0)).arg(ui->tblRoom->lineEdit(row, 1)->text()), "");
    ui->tblRoom->removeRow(row);
    message_info(tr("Reservation was canceled."));
    countTotalReservation();
}

void DlgGroupReservationFuck::editReserve()
{
    EPushButton *btn = static_cast<EPushButton *>(sender());
    int row = -1;
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        EPushButton *btnWidget = static_cast<EPushButton *>(ui->tblRoom->cellWidget(i, 18));
        if (btnWidget == btn) {
            row = i;
            break;
        }
    }
    if (row < 0) {
        return;
    }
    WReservation::openReserveWindows(ui->tblRoom->toString(row, 0));
}

void DlgGroupReservationFuck::editInvoice()
{
    EPushButton *btn = static_cast<EPushButton *>(sender());
    int row = -1;
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        EPushButton *btnWidget = static_cast<EPushButton *>(ui->tblRoom->cellWidget(i, 19));
        if (btnWidget == btn) {
            row = i;
            break;
        }
    }
    if (row < 0) {
        return;
    }
    CacheReservation r;
    if (r.get(ui->tblRoom->toString(row, 0))) {
        WInvoice::openInvoiceWindow(r.fInvoice());
    }
}

void DlgGroupReservationFuck::editAInvoice()
{
    EPushButton *btn = static_cast<EPushButton *>(sender());
    int row = -1;
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        EPushButton *btnWidget = static_cast<EPushButton *>(ui->tblRoom->cellWidget(i, 19));
        if (btnWidget == btn) {
            row = i;
            break;
        }
    }
    if (row < 0) {
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_id"] = ui->tblRoom->toString(row, 0);
    fDD.exec("select f_invoice from f_reservation where f_id=:f_id");
    if (fDD.rowCount() > 0) {
        WAccInvoice *wa = addTab<WAccInvoice>();
        wa->load(fDD.getValue("f_invoice").toString());
    }
}

void DlgGroupReservationFuck::countReserve()
{
    QSet<int> rooms;
    CacheReservation cr;
    cr.exludeList(ui->deArrival->date(), ui->deDeparture->date(), rooms);
    QMap<QString, QMap<QString, int> > total;
    for (int i = 0; i < ui->tblCat->rowCount(); i++) {
        total[ui->tblCat->toString(i, 0)][ui->tblCat->toString(i, 1)] = ui->tblCat->toInt(i, 2);
    }
    foreach (int i, rooms) {
        CacheRoom r ;
        if (!r.get(i)) {
            continue;
        }
        total[r.fCategoryShort()][r.fBed()] = total[r.fCategoryShort()][r.fBed()] - 1;
    }
    for (QMap<QString, QMap<QString, int> >::const_iterator l1 = total.begin(); l1 != total.end(); l1++) {
        for (QMap<QString, int>::const_iterator lb = ( *l1).begin(); lb != ( *l1).end(); lb++) {
            for (int i = 0; i < ui->tblCat->rowCount(); i++) {
                if (ui->tblCat->toString(i, 0) == l1.key() && ui->tblCat->toString(i, 1) == lb.key()) {
                    ui->tblCat->setItemWithValue(i, 3, lb.value());
                }
            }
        }
    }
}

void DlgGroupReservationFuck::countTotalReservation()
{
    for (int i = 0; i < ui->tblCat->rowCount(); i++) {
        ui->tblCat->lineEdit(i, 4)->clear();
        ui->tblCat->lineEdit(i, 5)->clear();
    }
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        for (int j = 0; j < ui->tblCat->rowCount(); j++) {
            if (ui->tblCat->toString(j, 0) == ui->tblRoom->toString(i, 2)
                    && ui->tblCat->toString(j, 1) == ui->tblRoom->toString(i, 3)) {
                if (ui->tblRoom->toInt(i, 21) != 2) {
                    continue;
                }
                ui->tblCat->lineEdit(j, 4)->setInt(ui->tblCat->lineEdit(j, 4)->asInt() + 1);
                ui->tblCat->lineEdit(j, 5)->setDouble(ui->tblCat->lineEdit(j, 5)->asDouble() +
                                                      (ui->tblRoom->lineEdit(i, 6)->asDouble() * (ui->tblRoom->dateEdit(i, 4)->date().daysTo(ui->tblRoom->dateEdit(i,
                                                              5)->date()))));
                break;
            }
        }
        ui->tblRoom->setItemWithValue(i, 7,
                                      ui->tblRoom->dateEdit(i, 4)->date().daysTo(ui->tblRoom->dateEdit(i, 5)->date()));
        ui->tblRoom->setItemWithValue(i, 8,
                                      ui->tblRoom->toInt(i, 7) *ui->tblRoom->lineEdit(i, 6)->asDouble());
    }
}

void DlgGroupReservationFuck::makeTrackControl(int row)
{
    TrackControl *t = new TrackControl(TRACK_RESERVATION);
    t->fReservation = ui->tblRoom->toString(row, 0);
    t->addWidget(ui->tblRoom->lineEdit(row, 1), "(In group) Room");
    t->addWidget(ui->tblRoom->dateEdit(row, 4), "(In group) Entry date");
    t->addWidget(ui->tblRoom->dateEdit(row, 5), "(In group) Departure date");
    t->addWidget(ui->tblRoom->lineEdit(row, 6), "(In group) Price");
    t->addWidget(ui->tblRoom->comboBox(row, 9), "(In group) Arrangement");
    t->addWidget(ui->tblRoom->lineEdit(row, 10), "(In group) Guest");
    ui->tblRoom->item(row, 0)->setData(Qt::UserRole, QVariant::fromValue(t));
}

void DlgGroupReservationFuck::createRooms(const QString &cat, const QString &bed, int count, double price)
{
    if (count < 1) {
        return;
    }
    QSet<int> rooms;
    CacheReservation cr;
    cr.exludeList(ui->deArrival->date(), ui->deDeparture->date(), rooms);
    CacheInstance *ci = cache(cid_room);
    CacheRoom r;
    r.fInstance = ci;
    QMap<QString, QList<QVariant> >::iterator it = ci->fRows.begin();
    while (it != ci->fRows.end()) {
        if (count == 0) {
            break;
        }
        r.fData = it.value();
        if (rooms.contains(r.fCode().toInt())) {
            it++;
            continue;
        }
        if (cat == r.fCategoryShort() && bed == r.fBed()) {
            count--;
            int row = ui->tblRoom->rowCount();
            ui->tblRoom->setRowCount(row + 1);
            ui->tblRoom->setItemWithValue(row, 0, "");
            EQLineEdit *l = ui->tblRoom->addLineEdit(row, 1, false);
            l->fClickBool = true;
            l->setText("");
            connect(l, SIGNAL(textEdited(QString)), this, SLOT(roomTextChanged(QString)));
            connect(l, SIGNAL(customButtonClicked(bool)), this, SLOT(openRoomSelectDialog(bool)));
            ui->tblRoom->setItemWithValue(row, 2, r.fCategoryShort());
            ui->tblRoom->setItemWithValue(row, 3, r.fBed());
            EDateEdit *d = ui->tblRoom->addDateEdit(row, 4, false);
            d->setDate(ui->deArrival->date());
            connect(d, SIGNAL(textEdited(QString)), this, SLOT(roomTextChanged(QString)));
            d = ui->tblRoom->addDateEdit(row, 5, false);
            d->setDate(ui->deDeparture->date());
            connect(d, SIGNAL(textEdited(QString)), this, SLOT(roomTextChanged(QString)));
            l = ui->tblRoom->addLineEdit(row, 6, false);
            l->setDouble(price);
            connect(l, SIGNAL(textChanged(QString)), this, SLOT(roomPriceChanged(QString)));
            EQComboBox *c = ui->tblRoom->addComboBox(row, 9);
            c->setCache(cid_room_arrangment);
            c->setCurrentIndex(c->findText(ui->cbArr->currentText()));
            EQLineEdit *lg = ui->tblRoom->addLineEdit(row, 10, false);
            lg->setText(ui->leGuest->text());
            connect(lg, SIGNAL(customButtonClicked(bool)), this, SLOT(singleGuestLineEdit(bool)));
            connect(lg, SIGNAL(focusIn()), this, SLOT(singleGuestFocusOut()));
            ui->tblRoom->setItemWithValue(row, 11, ui->teCommonRemark->toPlainText());
            ui->tblRoom->addLineEdit(row, 12, false);
            ui->tblRoom->addLineEdit(row, 13, false);
            ui->tblRoom->addLineEdit(row, 14, false);
            ui->tblRoom->setItemWithValue(row, 15, ui->leGuest->fHiddenText);
            ui->tblRoom->addButton(row, 16, SLOT(removeRow()), this, QIcon(":/images/garbage.png"));
            ui->tblRoom->setItemWithValue(row, 17, "O");
            ui->tblRoom->addButton(row, 18, SLOT(editReserve()), this, QIcon(":/images/bed.png"));
            ui->tblRoom->setItemWithValue(row, 20, tr("Reserved"));
            ui->tblRoom->setItemWithValue(row, 21, RESERVE_RESERVE);
            fGroupTrackControl->insertMessage("New room",
                                              QString("%1-%2, %3 - %4").arg(r.fCode()).arg(r.fRoomDescription()).arg(ui->deArrival->text()).arg(
                                                  ui->deDeparture->text()), "");
        }
        it++;
    }
    countTotalReservation();
}

void DlgGroupReservationFuck::on_deArrival_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    if (ui->deArrival->date() < WORKING_DATE) {
        //message_error(tr("Invalid arrival date"));
        return;
    }
    countReserve();
}

void DlgGroupReservationFuck::on_deDeparture_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    if (ui->deDeparture->date() < WORKING_DATE) {
        //message_error(tr("Invalid departure date"));
        return;
    }
    countReserve();
}

void DlgGroupReservationFuck::on_tblRoom_clicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    C5TableWidgetItem *item = ui->tblRoom->item(index.row(), 11);
    if (!item) {
        return;
    }
    fCurrRow = -1;
    ui->teIndRemarks->setPlainText(item->text());
    fCurrRow = index.row();
}

void DlgGroupReservationFuck::on_btnAddGuest_clicked()
{
    QList<QVariant> values;
    WGuest *g = WGuest::guest(values);
    if (g->exec() == QDialog::Accepted) {
        CacheGuest guest;
        guest.get(values.at(0).toString());
        int wait = 10000;
        while (!guest.get(values.at(0).toString()) && wait > 0) {
            qApp->processEvents();
            wait--;
        }
        if (!guest.get(values.at(0).toString())) {
            message_error(tr("Cannot register new guest, contact to application developer"));
            return;
        }
        ui->leGuest->setText(guest.fName());
        ui->leGuest->fHiddenText = guest.fCode();
    }
    delete g;
}

void DlgGroupReservationFuck::on_leGuest_returnPressed()
{
    if (ui->leGuest->text().trimmed().isEmpty()) {
        return;
    }
    DoubleDatabase fDD;
    QStringList fn = ui->leGuest->text().split(" ");
    if (fn.count() > 0) {
        QString searchName = fn.at(0).toLower();
        if (fn.count() > 1) {
            searchName += " " + fn.at(1).toLower();
        }
        fDD.exec("select f_id from f_guests where concat(lower(f_firstName), ' ', lower(f_lastName)) like '" + searchName +
                 "%'");
        if (fDD.nextRow()) {
            CacheInstance *ci = cache(cid_guest);
            ci->fFieldFilter.clear();
            ci->fFieldFilter["f_fullName"] << ui->leGuest->text();
            QString guestCode = ci->get(ui->leGuest->text());
            CacheGuest gg;
            if (gg.get(guestCode)) {
            }
        } else {
            fDD[":f_title"] = "";
            fDD[":f_firstName"] = fn.at(0);
            if (fn.count() > 1) {
                fDD[":f_lastName"] = fn.at(1);
            } else {
                fDD[":f_lastName"] = "";
            }
            int gid = fDD.insert("f_guests");
            BroadcastThread::cmdRefreshCache(cid_guest, QString::number(gid));
            CacheGuest gg;
            int wait = 10000;
            while (!gg.get(gid) && wait > 0) {
                qApp->processEvents();
                wait--;
            }
            if (!gg.get(gid)) {
                return;
            }
            ui->leGuest->setText(gg.fName());
            ui->leGuest->fHiddenText = gg.fCode();
        }
    }
}

void DlgGroupReservationFuck::on_teIndRemarks_textChanged()
{
    if (fCurrRow < 0) {
        return;
    }
    ui->tblRoom->setItemWithValue(fCurrRow, 11, ui->teIndRemarks->toPlainText());
}

void DlgGroupReservationFuck::on_btnCreateGroup_clicked()
{
    for (int i = 0; i < ui->tblCat->rowCount(); i++) {
        if (ui->tblCat->lineEdit(i, 4)->asInt() < 1) {
            ui->tblCat->lineEdit(i, 4)->clear();
            continue;
        }
        if (ui->tblCat->toInt(i, 3) - ui->tblCat->toInt(i, 4) > -1) {
            createRooms(ui->tblCat->toString(i, 0), ui->tblCat->toString(i, 1),
                        ui->tblCat->lineEdit(i, 4)->asInt(), ui->tblCat->lineEdit(i, 5)->asDouble());
        } else {
            createRooms(ui->tblCat->toString(i, 0), ui->tblCat->toString(i, 1),
                        ui->tblCat->toInt(i, 4), ui->tblCat->lineEdit(i, 5)->asDouble());
        }
        ui->tblCat->lineEdit(i, 4)->clear();
    }
}

void DlgGroupReservationFuck::save()
{
    ui->tblRoom->setCurrentCell(-1, -1);
    bool flagAnotherSaved = false;
    bool flagGuestQtyWarning = false;
    if (ui->leGroupName->isEmpty()) {
        message_error(tr("The group name cannot be empty"));
        return;
    }
    DoubleDatabase fDD;
    if (ui->leGroupCode->asInt() == 0) {
        fDD[":f_name"] = ui->leGroupName->text();
        ui->leGroupCode->setInt(fDD.insert("f_reservation_group"));
        fDD[":f_firstName"] = ui->leGroupName->text();
        fDD[":f_lastName"] = "";
        fDD[":f_title"] = "";
        fDD[":f_nation"] = "-";
        ui->leGuest->fHiddenText = QString::number(fDD.insert("f_guests"));
        ui->leGuest->setText(ui->leGroupName->text());
        BroadcastThread::cmdRefreshCache(cid_guest, ui->leGuest->fHiddenText);
    }
    fDD[":f_name"] = ui->leGroupName->text();
    fDD[":f_entry"] = ui->deArrival->date();
    fDD[":f_departure"] = ui->deDeparture->date();
    fDD[":f_cardex"] = ui->leCardexCode->text();
    fDD[":f_arrangement"] = ui->cbArr->currentData();
    fDD[":f_price"] = ui->lePrice->asDouble();
    fDD[":f_guest"] = ui->leGuest->fHiddenText;
    fDD[":f_paymentMode"] = ui->cbModeOfPayment->currentData();
    fDD[":f_remarks"] = ui->teCommonRemark->toPlainText();
    fDD[":f_cityLedger"] = ui->leCLCode->asInt();
    fDD[":f_card"] = ui->leCardCode->asInt();
    fDD[":f_extra1"] = ui->leExtraname->text();
    fDD.update("f_reservation_group", where_id(ui->leGroupCode->asInt()));
    bool err = false;
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        if (ui->tblRoom->item(i, 0)->background() == Qt::magenta) {
            flagAnotherSaved = true;
            continue;
        }
        if (ui->tblRoom->toInt(i, 21) != RESERVE_RESERVE) {
            continue;
        }
        if (ui->tblRoom->dateEdit(i, 4)->date() < WORKING_DATE) {
            ui->tblRoom->setValue(i, 17, "X");
            err = true;
            continue;
        }
        if (ui->tblRoom->toString(i, 17) == "X") {
            err = true;
            continue;
        }
        QString errorStr;
        if (!WReservationRoomTab::check(ui->tblRoom->lineEdit(i, 1)->asInt(),
                                        ui->tblRoom->dateEdit(i, 4)->date(), ui->tblRoom->dateEdit(i, 5)->date(), ui->tblRoom->toString(i, 0), errorStr)) {
            err = true;
            ui->tblRoom->setItemWithValue(i, 17, "X");
            continue;
        }
        bool isNew = ui->tblRoom->toString(i, 0).isEmpty();
        QString invId;
        if (ui->tblRoom->toString(i, 0).isEmpty()) {
            fDD[":f_author"] = WORKING_USERID;
            fDD[":f_createTime"] = QDateTime::currentDateTime();
            fDD[":f_created"] = QDate::currentDate();
            invId = uuidx("IN");
            fDD[":f_invoice"] = invId;
        } else {
            fDD[":f_id"] = ui->tblRoom->toString(i, 0);
            fDD.exec("select f_invoice from f_reservation where f_id=:f_id");
            if (fDD.nextRow()) {
                invId = fDD.getString(0);
            }
        }
        fDD[":f_state"] = RESERVE_RESERVE;
        fDD[":f_reserveState"] = CONFIRM_CONFIRM;
        fDD[":f_room"] = ui->tblRoom->lineEdit(i, 1)->asInt();
        fDD[":f_arrangement"] = ui->tblRoom->comboBox(i, 9)->currentData();
        fDD[":f_mealIncluded"] = 0;
        if (ui->tblRoom->toString(i, 15).toInt() == 0) {
            ui->tblRoom->setItemWithValue(i, 15, ui->leGuest->fHiddenText);
            EQLineEdit *lgg = ui->tblRoom->lineEdit(i, 10);
            lgg->setText(ui->leGroupName->text());
            lgg->fHiddenText = ui->leGuest->fHiddenText;
        }
        int totalGuest = ui->tblRoom->lineEdit(i, 12)->asInt() + ui->tblRoom->lineEdit(i,
                         13)->asInt() + ui->tblRoom->lineEdit(i, 14)->asInt();
        if (totalGuest == 0) {
            flagGuestQtyWarning = true;
        }
        fDD[":f_guest"] = ui->tblRoom->toInt(i, 15);
        fDD[":f_man"] = totalGuest == 0 ? 1 : ui->tblRoom->lineEdit(i, 12)->asInt();
        fDD[":f_woman"] = ui->tblRoom->lineEdit(i, 13)->asInt();
        fDD[":f_child"] = ui->tblRoom->lineEdit(i, 14)->asInt();
        fDD[":f_baby"] = 0;
        fDD[":f_cardex"] = ui->leCardexCode->text();
        fDD[":f_cityLedger"] = ui->leCLCode->asInt();
        fDD[":f_startDate"] = ui->tblRoom->dateEdit(i, 4)->date();
        fDD[":f_endDate"] = ui->tblRoom->dateEdit(i, 5)->date();
        fDD[":f_arrivalTime"] = "00:00:00";
        fDD[":f_arrivalFee"] = 0;
        fDD[":f_departureTime"] = "00:00:00";
        fDD[":f_earlyCheckIn"] = 0;
        fDD[":f_earlyCheckInTime"] = "00:00:00";
        fDD[":f_earlyCheckInFee"] = 0;
        fDD[":f_lateCheckOut"] = 0;
        fDD[":f_lateCheckOutTime"] = "00:00:00";
        fDD[":f_lateCheckOutFee"] = 0;
        fDD[":f_paymentType"] = ui->cbModeOfPayment->currentData();
        fDD[":f_roomFee"] = ui->tblRoom->lineEdit(i, 6)->asDouble();
        fDD[":f_mealQty"] = 0;
        fDD[":f_mealPrice"] = 0;
        fDD[":f_extraBed"] = 0;
        fDD[":f_extraBedFee"] = 0;
        fDD[":f_pricePerNight"] = ui->tblRoom->lineEdit(i, 6)->asDouble();
        fDD[":f_vat"] = def_vat;
        fDD[":f_vatAmount"] = Utils::countVATAmount(ui->tblRoom->lineEdit(i, 6)->asDouble(), VAT_INCLUDED);
        fDD[":f_vatMode"] = ui->leCardCode->property("vatmode");
        fDD[":f_total"] = ui->tblRoom->dateEdit(i, 4)->date().daysTo(ui->tblRoom->dateEdit(i,
                          5)->date()) * ui->tblRoom->lineEdit(i, 6)->asDouble();
        fDD[":f_grandTotal"] = ui->tblRoom->dateEdit(i, 4)->date().daysTo(ui->tblRoom->dateEdit(i,
                               5)->date()) * ui->tblRoom->lineEdit(i, 6)->asDouble();
        fDD[":f_totalUSD"] = def_usd;
        fDD[":f_novatReason"] = "";
        fDD[":f_remarks"] = ui->tblRoom->toString(i, 11);
        fDD[":f_commission"] = 0;
        fDD[":f_group"] = ui->leGroupCode->asInt();
        fDD[":f_booking"] = "";
        fDD[":f_pickup"] = 0;
        fDD[":f_lastEdit"] = WORKING_USERID;
        if (ui->tblRoom->toString(i, 0).isEmpty()) {
            DoubleDatabase did;
            did.open();
            QString rsId = uuidx(VAUCHER_RESERVATION_N);
            did.insertId("f_reservation", rsId);
            ui->tblRoom->setItemWithValue(i, 0, rsId);
            fTrackControl->resetChanges();
            fTrackControl->fReservation = ui->tblRoom->toString(i, 0);
            fTrackControl->insert("Created in group: " + ui->leGroupName->text(), QString("%1-%2, %3, %4:%5")
                                  .arg(ui->tblRoom->dateEdit(i, 4)->text())
                                  .arg(ui->tblRoom->dateEdit(i, 5)->text())
                                  .arg(ui->tblRoom->lineEdit(i, 6)->text())
                                  .arg(ui->tblRoom->toString(i, 2))
                                  .arg(ui->tblRoom->lineEdit(i, 1)->text()),  "");
            makeTrackControl(i);
        }
        fDD.update("f_reservation", where_id(ap(ui->tblRoom->toString(i, 0))));
        fDD[":f_id"] = ui->tblRoom->toString(i, 0);
        fDD.exec("update f_reservation set f_pricepernight=f_roomfee+f_extrabedfee+f_mealprice where f_id=:f_id");
        fDD[":f_id"] = ui->tblRoom->toString(i, 0);
        fDD.exec("update f_reservation set f_total=f_pricepernight*datediff(f_enddate, f_startdate) where f_id=:f_id");
        fDD[":f_id"] = ui->tblRoom->toString(i, 0);
        fDD.exec("update f_reservation set f_grandtotal=f_pricepernight*datediff(f_enddate, f_startdate) where f_id=:f_id");
        fDD[":f_reservation"] = ui->tblRoom->toString(i, 0);
        fDD.exec("delete from f_reservation_guests where f_reservation=:f_reservation and f_first=1");
        fDD[":f_reservation"] = ui->tblRoom->toString(i, 0);
        fDD[":f_guest"] = ui->tblRoom->toString(i, 15);
        fDD[":f_first"] = 1;
        fDD.insert("f_reservation_guests");
        QString rid = ui->tblRoom->toString(i, 0);
        if (isNew) {
            fDD[":f_id"] = rid;
            fDD.insert("m_register", false);
            fDD[":f_inv"] = invId;
            fDD[":f_source"] = VAUCHER_RESERVATION_N;
            fDD[":f_wdate"] = ui->tblRoom->dateEdit(i, 4)->date();
            fDD[":f_rdate"] = QDate::currentDate();
            fDD[":f_time"] = QTime::currentTime();
            fDD[":f_user"] = WORKING_USERID;
            fDD[":f_room"] = ui->tblRoom->lineEdit(i, 1)->asInt();
            fDD[":f_guest"] = ui->tblRoom->lineEdit(i, 10)->text();
            fDD[":f_itemCode"] = fPreferences.getDb(def_reservation_voucher_id);
            fDD[":f_finalName"] = tr("RESERVATION ") + ui->tblRoom->toString(i, 0);
            fDD[":f_amountAmd"] = ui->tblRoom->dateEdit(i, 4)->date().daysTo(ui->tblRoom->dateEdit(i,
                                  5)->date()) * ui->tblRoom->lineEdit(i, 6)->asDouble();
            fDD[":f_amountVat"] = Utils::countVATAmount(ui->tblRoom->lineEdit(i, 6)->asDouble(), VAT_INCLUDED);;
            fDD[":f_amountUsd"] = def_usd;
            fDD[":f_fiscal"] = 0;
            fDD[":f_paymentMode"] = PAYMENT_CASH;
            fDD[":f_creditCard"] = 0;
            fDD[":f_cityLedger"] = 0;
            fDD[":f_paymentComment"] = vaucherPaymentName(PAYMENT_CASH, "0", "0");
            fDD[":f_dc"] = "";
            fDD[":f_sign"] = 1;
            fDD[":f_doc"] = "";
            fDD[":f_rec"] = "";
            fDD[":f_finance"] = 0;
            fDD[":f_remarks"] = ui->tblRoom->toString(i, 11);
            fDD[":f_canceled"] = 0;
            fDD[":f_cancelReason"] = "";
            fDD[":f_side"] = 0;
            fDD.update("m_register", where_id(ap(rid)));
        }
        fDD[":f_wdate"] = ui->tblRoom->dateEdit(i, 4)->date();
        fDD[":f_room"] = ui->tblRoom->lineEdit(i, 1)->asInt();
        fDD[":f_guest"] = ui->tblRoom->toString(i, 10);
        fDD[":f_finalName"] = tr("RESERVATION ") + ui->tblRoom->toString(i, 0);
        fDD[":f_amountAmd"] = ui->tblRoom->dateEdit(i, 4)->date().daysTo(ui->tblRoom->dateEdit(i,
                              5)->date()) * ui->tblRoom->lineEdit(i, 6)->asDouble();
        fDD[":f_amountVat"] = Utils::countVATAmount(ui->tblRoom->lineEdit(i, 6)->asDouble(), VAT_INCLUDED);;
        fDD[":f_amountUsd"] = def_usd;
        fDD[":f_fiscal"] = 0;
        fDD[":f_paymentMode"] = PAYMENT_CASH;
        fDD[":f_creditCard"] = 0;
        fDD[":f_cityLedger"] = 0;
        fDD[":f_paymentComment"] = vaucherPaymentName(PAYMENT_CASH, "0", "0");
        fDD[":f_dc"] = "";
        fDD[":f_sign"] = 1;
        fDD[":f_doc"] = "";
        fDD[":f_rec"] = "";
        fDD[":f_finance"] = 0;
        fDD[":f_remarks"] = ui->tblRoom->toString(i, 11);
        fDD[":f_canceled"] = 0;
        fDD[":f_cancelReason"] = "";
        fDD[":f_side"] = 0;
        fDD.update("m_register", where_id(ap(rid)));
        fDD[":f_room"] = ui->tblRoom->lineEdit(i, 1)->asInt();
        fDD[":f_inv"] = invId;
        fDD.exec("update m_register set f_room=:f_room where f_inv=:f_inv");
        BroadcastThread::cmdRefreshCache(cid_reservation, ui->tblRoom->toString(i, 0));
        BroadcastThread::cmdRefreshCache(cid_group_reservation, ui->leGroupCode->text());
        BroadcastThread::cmdRefreshCache(cid_red_reservation, ui->tblRoom->toString(i, 0));
        TrackControl *t = ui->tblRoom->item(i, 0)->data(Qt::UserRole).value<TrackControl *>();
        if (t) {
            if (t->hasChanges()) {
                t->saveChanges();
            }
        }
    }
    if (err) {
        message_error(tr("Some reservation was not saved. Check for 'X' in the table"));
    } else {
        message_info(tr("Saved"));
        BroadcastThread::cmdRefreshCache(cid_group_reservation, ui->leGroupCode->text());
    }
    if (flagGuestQtyWarning) {
        message_info(tr("The count of the guest automatically was set to 1 where count of the guests equal to zero"));
    }
    if (flagAnotherSaved) {
        message_info(
            tr("The reservations that's colored magenta could not be saved, because there are saved in another document."));
    }
    countReserve();
    fDD.commit();
    fDD.close();
    fDD.open();
}

void DlgGroupReservationFuck::on_btnSave_clicked()
{
    disconnect(cache(cid_reservation), SIGNAL(updated(int, QString)), this, SLOT(reservationCacheUpdated(int, QString)));
    save();
    fGroupTrackControl->fRecord = ui->leGroupCode->text();
    fGroupTrackControl->saveChanges();
    connect(cache(cid_reservation), SIGNAL(updated(int, QString)), this, SLOT(reservationCacheUpdated(int, QString)));
}

void DlgGroupReservationFuck::on_btnRemarksToAll_clicked()
{
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        if (ui->tblRoom->toInt(i, 21) != RESERVE_RESERVE) {
            continue;
        }
        ui->tblRoom->setItemWithValue(i, 11, ui->teCommonRemark->toPlainText());
        fGroupTrackControl->insert("Remarks for reservations", ui->teCommonRemark->toPlainText(), "");
    }
}

void DlgGroupReservationFuck::on_btnRemarksToAll_2_clicked()
{
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        if (ui->tblRoom->toInt(i, 21) != RESERVE_RESERVE) {
            continue;
        }
        ui->tblRoom->lineEdit(i, 10)->setText(ui->leGuest->text());
        ui->tblRoom->setItemWithValue(i, 15, ui->leGuest->fHiddenText);
    }
    fGroupTrackControl->insert("Remarks for reservations", ui->teCommonRemark->toPlainText(), "");
}

void DlgGroupReservationFuck::roomTextChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    int col, row;
    if (!ui->tblRoom->findWidgetCell(static_cast<QWidget * >(sender()), row, col)) {
        return;
    }
    CacheRoom r;
    if (!r.get(ui->tblRoom->lineEdit(row, 1)->text())) {
        ui->tblRoom->setItemWithValue(row, 17, "X");
        return;
    }
    ui->tblRoom->setItemWithValue(row, 2, r.fCategoryShort());
    ui->tblRoom->setItemWithValue(row, 3, r.fBed());
    QMap<QString, CacheReservation> out;
    bool startOk = true;
    bool endOk = true;
    CacheReservation cr;
    cr.check(ui->tblRoom->dateEdit(row, 4)->date(),
             ui->tblRoom->dateEdit(row, 5)->date(),
             ui->tblRoom->lineEdit(row, 1)->asInt(), out, startOk, endOk, ui->tblRoom->toString(row, 0));
    if (!startOk || !endOk) {
        ui->tblRoom->setItemWithValue(row, 17, "X");
    } else {
        ui->tblRoom->setItemWithValue(row, 17, "O");
    }
    countTotalReservation();
}

void DlgGroupReservationFuck::openRoomSelectDialog(bool v)
{
    QStringList exclude;
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        if (ui->tblRoom->itemValue(i, 21, Qt::DisplayRole).toInt() != RESERVE_RESERVE) {
            continue;
        }
        if (ui->tblRoom->lineEdit(i, 1)->text().length() > 0) {
            exclude.append(ui->tblRoom->lineEdit(i, 1)->text());
        }
    }
    int row, col;
    if (!ui->tblRoom->findWidgetCell(static_cast<QWidget * >(sender()), row, col)) {
        return;
    }
    CacheRoom r;
    fDockRoom->fSingleSelection = v;
    if (fDockRoom->getRoom(ui->tblRoom->toString(row, 2), ui->tblRoom->dateEdit(row, 4)->date(),
                           ui->tblRoom->dateEdit(row, 5)->date(), exclude, ui->tblCat->toString(row, 1), v) != QDialog::Accepted) {
        return;
    }
    if (!r.get(fDockRoom->fRoomCode)) {
        return;
    }
    ui->tblRoom->lineEdit(row, 1)->setText(r.fCode());
    countTotalReservation();
}

void DlgGroupReservationFuck::createMultiRoom(int tag)
{
    QStringList exclude;
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        if (ui->tblRoom->itemValue(i, 21, Qt::DisplayRole).toInt() != RESERVE_RESERVE) {
            continue;
        }
        if (ui->tblRoom->lineEdit(i, 1)->text().length() > 0) {
            exclude.append(ui->tblRoom->lineEdit(i, 1)->text());
        }
    }
    int currRow = ui->tblRoom->rowCount();
    ui->tblCat->lineEdit(tag, 4)->clear();
    if (fDockRoom->getRoom(ui->tblCat->toString(tag, 0), ui->deArrival->date(),
                           ui->deDeparture->date(), exclude, ui->tblCat->toString(tag, 1), true) != QDialog::Accepted) {
        return;
    }
    QStringList rooms;
    fDockRoom->getRoomsList(rooms);
    createRooms(ui->tblCat->toString(tag, 0), ui->tblCat->toString(tag, 1),
                rooms.count(), fDockRoom->price());
    foreach (QString s, rooms) {
        if (currRow == ui->tblRoom->rowCount()) {
            return;
        }
        ui->tblRoom->lineEdit(currRow++, 1)->setText(s);
    }
    countTotalReservation();
}

void DlgGroupReservationFuck::roomPriceChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    countTotalReservation();
}

void DlgGroupReservationFuck::on_btnArrangeToAll_clicked()
{
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        if (ui->tblRoom->toInt(i, 21) != RESERVE_RESERVE) {
            continue;
        }
        ui->tblRoom->comboBox(i, 9)->setCurrentIndex(ui->cbArr->currentIndex());
        fGroupTrackControl->insert("Room arrangement for reservations", ui->cbArr->currentText(), "");
    }
}

void DlgGroupReservationFuck::on_btnPriceToAll_clicked()
{
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        if (ui->tblRoom->toInt(i, 21) != RESERVE_RESERVE) {
            continue;
        }
        if (ui->tblRoom->toString(i, 2) == ui->cbCat->currentText()
                && ui->tblRoom->toString(i, 3) == ui->cbBed->currentData().toString()) {
            ui->tblRoom->lineEdit(i, 6)->setText(ui->lePrice->text());
        }
        fGroupTrackControl->insert("Price for reservations",
                                   QString("%1,%2").arg(ui->cbCat->currentText()).arg(ui->cbBed->currentText()), "");
    }
    countTotalReservation();
}

void DlgGroupReservationFuck::on_btnClear_clicked()
{
    for (int i = ui->tblRoom->rowCount() - 1; i > -1; i--) {
        if (ui->tblRoom->toString(i, 0).isEmpty()) {
            ui->tblRoom->removeRow(i);
            fGroupTrackControl->insert("Remove unsaved", ui->tblRoom->lineEdit(i, 1)->text(), "");
        }
    }
}

void DlgGroupReservationFuck::on_btnDateAll_clicked()
{
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        if (ui->tblRoom->toInt(i, 21) != RESERVE_RESERVE) {
            continue;
        }
        ui->tblRoom->dateEdit(i, 4)->setDate(ui->deArrival->date());
        ui->tblRoom->dateEdit(i, 5)->setDate(ui->deDeparture->date());
        fGroupTrackControl->insert("Arrival/departure changed", ui->deArrival->text() + "/" + ui->deDeparture->text(), "");
    }
}

void DlgGroupReservationFuck::on_btnArrangeToAll_2_clicked()
{
    if (ui->leCardexCode->isEmpty()) {
        return;
    }
    DoubleDatabase fDD;
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        if (ui->tblRoom->toInt(i, 21) != RESERVE_RESERVE) {
            continue;
        }
        if (ui->tblRoom->toString(i, 0).isEmpty()) {
            continue;
        }
        fDD[":f_cardex"] = ui->leCardexCode->text();
        fDD.update("f_reservation", where_id(ap(ui->tblRoom->toString(i, 0))));
        fDD[":f_cardex"] = ui->leCardexCode->text();
        fDD.update("f_reservation_group", where_id(ui->leGroupCode->asInt()));
        BroadcastThread::cmdRefreshCache(cid_reservation, ui->tblRoom->lineEdit(i, 1)->text());
        TrackControl *t = ui->tblRoom->item(i, 0)->data(Qt::UserRole).value<TrackControl *>();
        if (t) {
            t->insert("Cardex changed", ui->leCardCode->text(), "");
        }
        fGroupTrackControl->insert("Cardex for reservations", ui->leCardexCode->text(), "");
    }
}

void DlgGroupReservationFuck::on_btnAllPayments_clicked()
{
    DoubleDatabase fDD;
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        if (ui->tblRoom->toInt(i, 21) != RESERVE_RESERVE) {
            continue;
        }
        if (ui->tblRoom->toString(i, 0).isEmpty()) {
            continue;
        }
        fDD[":f_paymentType"] = ui->cbModeOfPayment->currentData();
        fDD.update("f_reservation", where_id(ap(ui->tblRoom->toString(i, 0))));
        TrackControl *t = ui->tblRoom->item(i, 0)->data(Qt::UserRole).value<TrackControl *>();
        if (t) {
            t->insert("Cardex changed", ui->leCardCode->text(), "");
        }
    }
    fGroupTrackControl->insert("Payment mode for reservations", ui->cbModeOfPayment->currentText(), "");
}

void DlgGroupReservationFuck::on_cbModeOfPayment_currentIndexChanged(int index)
{
    Q_UNUSED(index)
    /*
    ui->leCLCode->clear();
    dockResponse<CI_CityLedger, CacheCityLedger>(ui->leCLCode, ui->leCLName, 0);


    ui->leCardCode->clear();
    dockResponse<CI_CreditCard, CacheCreditCard>(ui->leCardCode, ui->leCardName, 0);
    */
}

void DlgGroupReservationFuck::on_btnAllCL_clicked()
{
    DoubleDatabase fDD;
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        if (ui->tblRoom->toString(i, 0).isEmpty()) {
            continue;
        }
        if (ui->tblRoom->toInt(i, 21) != RESERVE_RESERVE) {
            continue;
        }
        fDD[":f_cityLedger"] = ui->leCLCode->asInt();
        fDD.update("f_reservation", where_id(ap(ui->tblRoom->toString(i, 0))));
    }
    fDD[":f_cityLedger"] = ui->leCardexCode->text();
    fDD.update("f_reservation_group", where_id(ui->leGroupCode->asInt()));
}

void DlgGroupReservationFuck::on_btnAllCard_clicked()
{
    DoubleDatabase fDD;
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        if (ui->tblRoom->toString(i, 0).isEmpty()) {
            continue;
        }
        if (ui->tblRoom->toInt(i, 21) != RESERVE_RESERVE) {
            continue;
        }
        fDD[":f_card"] = ui->leCardCode->asInt();
        fDD.update("f_reservation", where_id(ap(ui->tblRoom->toString(i, 0))));
    }
}

void DlgGroupReservationFuck::on_tblCat_cellDoubleClicked(int row, int column)
{
    Q_UNUSED(column)
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        ui->tblRoom->setRowHidden(i, true);
        if (ui->tblCat->toString(row, 0) == ui->tblRoom->toString(i, 2)
                && ui->tblCat->toString(row, 1) == ui->tblRoom->toString(i, 3)) {
            ui->tblRoom->setRowHidden(i, false);
        }
    }
}

void DlgGroupReservationFuck::on_btnClearFilter_clicked()
{
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        ui->tblRoom->setRowHidden(i, false);
    }
}

void DlgGroupReservationFuck::on_btnPrint_clicked()
{
    PPrintPreview *pv = new PPrintPreview(fMainWindow->fPreferences.getDefaultParentForMessage());
    PPrintScene *ps = pv->addScene(0, QPageLayout::Landscape);
    int top = 10;
    //PTextRect *trInfo = new PTextRect(1500, 20, 500, 400, fPreferences.getDb(def_vouchers_right_header).toString(),
    //                                  0, QFont("Arial", 25));
    int rowHeight = 80;
    QPen boldPen(Qt::black);
    boldPen.setWidth(6);
    QFont f("Arial", 30);
    f.setItalic(true);
    f.setBold(true);
    PTextRect th;
    th.setRectPen(boldPen);
    th.setBorders(false, false, false, false);
    th.setFont(f);
    th.setTextAlignment(Qt::AlignLeft);
    ps->addTextRect(20, top, 500, 80, QObject::tr("GROUP RESERVATION") + ": ", &th);
    top += ps->addTextRect(510, top, 2700, 80, ui->leGroupName->text(), &th)->textHeight();
    ps->addTextRect(20, top, 500, 80, QObject::tr("Cardex") + ": ", &th);
    top += ps->addTextRect(510, top, 2700, 80, ui->leCardexCode->text() + "/" + ui->leCardexName->text(),
                           &th)->textHeight();
    ps->addTextRect(20, top, 500, 80, QObject::tr("Arrival") + ": ", &th);
    top += ps->addTextRect(510, top, 2700, 80, ui->deArrival->text(), &th)->textHeight();
    ps->addTextRect(20, top, 500, 80, QObject::tr("Departure") + ": ", &th);
    top += ps->addTextRect(510, top, 2700, 80, ui->deDeparture->text(), &th)->textHeight();
    ps->addTextRect(20, top, 500, 80, QObject::tr("Arrangement") + ": " + ui->deArrival->text(), &th);
    top += ps->addTextRect(510, top, 2700, 80, ui->cbArr->currentText(), &th)->textHeight();
    //  top += trInfo->textHeight();
    top += 10;
    f.setPointSize(30);
    f.setItalic(false);
    f.setBold(false);
    th.setFont(f);
    th.setBorders(true, true, true, true);
    th.setTextAlignment(Qt::AlignHCenter);
    QList<int> cols;
    QStringList vals;
    cols << 60
         << 230
         << 130
         << 130
         << 130
         << 240
         << 240
         << 160
         << 160
         << 250
         << 130
         << 600
         << 100
         << 100
         << 100
         << 250
         ;
    vals << tr("Code")
         << tr("Room")
         << tr("Cat.")
         << tr("Bed")
         << tr("Arrival")
         << tr("Departure")
         << tr("Price")
         << tr("Nights")
         << tr("Total")
         << tr("Arr.")
         << tr("Guest")
         << tr("M")
         << tr("F")
         << tr("Ch")
         << tr("State")
         ;
    ps->addTableRow(top, rowHeight, cols, vals, &th);
    int totMan = 0,
        totNight = 0,
        totFemal = 0,
        totChild = 0;
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        vals << ui->tblRoom->toString(i, 0)
             << ui->tblRoom->lineEdit(i, 1)->text()
             << ui->tblRoom->toString(i, 2)
             << ui->tblRoom->toString(i, 3)
             << ui->tblRoom->dateEdit(i, 4)->text()
             << ui->tblRoom->dateEdit(i, 5)->text()
             << ui->tblRoom->lineEdit(i, 6)->text()
             << ui->tblRoom->toString(i, 7)
             << ui->tblRoom->toString(i, 8)
             << ui->tblRoom->comboBox(i, 9)->currentText()
             << ui->tblRoom->lineEdit(i, 10)->text()
             << ui->tblRoom->lineEdit(i, 12)->text()
             << ui->tblRoom->lineEdit(i, 13)->text()
             << ui->tblRoom->lineEdit(i, 14)->text()
             << ui->tblRoom->toString(i, 20)
             ;
        ps->addTableRow(top, rowHeight, cols, vals, &th);
        if (top > sizeLandscape.height() - 200) {
            top = 10;
            ps = pv->addScene(0, QPageLayout::Landscape);
        }
        totMan += ui->tblRoom->lineEdit(i, 12)->text().toInt();
        totFemal += ui->tblRoom->lineEdit(i, 13)->text().toInt();
        totChild += ui->tblRoom->lineEdit(i, 14)->text().toInt();
        totNight += ui->tblRoom->toInt(i, 7);
    }
    vals << tr("Total")
         << QString::number(ui->tblRoom->rowCount())
         << ""
         << ""
         << ""
         << ""
         << ""
         << QString::number(totNight)
         << ui->lePreAmount->text()
         << ""
         << ""
         << QString::number(totMan)
         << QString::number(totFemal)
         << QString::number(totChild)
         << ""
         ;
    ps->addTableRow(top, rowHeight, cols, vals, &th);
    if (top > sizeLandscape.height() - 200) {
        top = 10;
        ps = pv->addScene(0, QPageLayout::Landscape);
    }
    top += rowHeight;
    top += rowHeight;
    QString footer = QString("%1: %2, %3: %4")
                     .arg(QObject::tr("Printed"))
                     .arg(QDateTime::currentDateTime().toString(def_date_time_format))
                     .arg(QObject::tr("Operator"))
                     .arg(WORKING_USERNAME);
    f.setBold(true);
    f.setPointSize(18);
    th.setBorders(false, false, false, false);
    th.setFont(f);
    th.setTextAlignment(Qt::AlignRight);
    ps->addTextRect(20, top, 2100, rowHeight, footer, &th);
    pv->exec();
    delete pv;
}

void DlgGroupReservationFuck::on_btnCancelGroup_clicked()
{
    bool ok = false;
    QString reason = QInputDialog::getText(this, tr("Cancelation reason"), tr("Reason"), QLineEdit::Normal, "",
                                           &ok).trimmed();
    if (!ok) {
        return;
    }
    if (reason.isEmpty()) {
        message_error("Please, specify the reason on cancelation");
        return;
    }
    if (message_confirm(tr("Confirm to removing whole group")) != RESULT_YES) {
        return;
    }
    DoubleDatabase fDD;
    QString cannotCancel;
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        if (ui->tblRoom->toInt(i, 21) != RESERVE_RESERVE) {
            continue;
        }
        fDD[":f_id"] = ui->tblRoom->toString(i, 0);
        fDD.exec("select r.f_invoice, r.f_room, g.guest from f_reservation r "
                 "left join guests g on g.f_id=r.f_guest "
                 "where r.f_id=:f_id");
        if (!fDD.nextRow()) {
            continue;
        }
        QString r = fDD.getValue("f_room").toString() + ", " + fDD.getValue("guest").toString() + "<br>";
        fDD[":f_inv"] = fDD.getValue("f_invoice");
        fDD.exec("select * from m_register where f_inv=:f_inv and f_source='AV' and f_canceled=0 and f_finance=1");
        if (fDD.rowCount() > 0) {
            cannotCancel += r;
            continue;
        }
        fDD[":f_state"] = RESERVE_REMOVED;
        fDD[":f_cancelUser"] = WORKING_USERID;
        fDD[":f_cancelDate"] = QDateTime::currentDateTime();
        fDD.update("f_reservation", where_id(ap(ui->tblRoom->toString(i, 0))));
        fDD[":f_id"] = ui->tblRoom->toString(i, 0);
        fDD[":f_reason"] = tr("Group") + ": " + reason;
        fDD.insert("f_reservation_cancel_reason", false);
        BroadcastThread::cmdRefreshCache(cid_reservation, ui->tblRoom->toString(i, 0));
        BroadcastThread::cmdRefreshCache(cid_red_reservation, ui->tblRoom->toString(i, 0));
        TrackControl tc(TRACK_RESERVATION);
        tc.fReservation = ui->tblRoom->toString(i, 0);
        tc.insert("Canceled in group", "", "");
    }
    if (!cannotCancel.isEmpty()) {
        message_info(tr("Next reservations was not canceled, because have an advance") + "<br>" + cannotCancel);
    } else {
        fDD[":f_canceled"] = 1;
        fDD[":f_cancelDate"] = QDateTime::currentDateTime();
        fDD[":f_cancelUser"] = WORKING_USERID;
        fDD[":f_cancelReason"] = reason;
        fDD.update("f_reservation_group", where_id(ui->leGroupCode->asInt()));
        fGroupTrackControl->insertMessage("Group was canceled", "", "");
        message_info(tr("Reservation group was successfully canceled"));
    }
    loadGroup(ui->leGroupCode->asInt());
}

void DlgGroupReservationFuck::on_btnReviveReservations_clicked()
{
    DlgGroupRevive *d = new DlgGroupRevive(this);
    for (int i = 0; i < ui->tblRoom->rowCount(); i++) {
        if (ui->tblRoom->itemValue(i, 21).toInt() == RESERVE_REMOVED) {
            d->addRow(ui->tblRoom->itemValue(i, 0).toString(),
                      ui->tblRoom->lineEdit(i, 1)->asInt(),
                      ui->tblRoom->dateEdit(i, 4)->date(),
                      ui->tblRoom->dateEdit(i, 5)->date(),
                      ui->tblRoom->toString(i, 10));
        }
    }
    if (d->exec() == QDialog::Accepted) {
        fGroupTrackControl->insert("Group revive", "", "");
        loadGroup(ui->leGroupCode->asInt());
    }
    delete d;
}

void DlgGroupReservationFuck::on_btnCopyLast_clicked()
{
    if (message_confirm(tr("Copy from last?")) != QDialog::Accepted) {
        return;
    }
    DoubleDatabase dd;
    dd.exec("select max(f_id) from f_reservation_group");
    if (dd.nextRow()) {
        dd[":f_id"] = dd.getInt(0);
        dd.exec("select * from f_reservation_group where f_id=:f_id");
        if (dd.nextRow()) {
            ui->deArrival->setDate(dd.getDate("f_entry"));
            ui->deDeparture->setDate(dd.getDate("f_departure"));
            ui->cbArr->setIndexForData(dd.getInt("f_arrangement"));
            ui->cbModeOfPayment->setIndexForData(dd.getInt("f_paymentmode"));
            ui->leCardexCode->setInitialValue(dd.getString("f_cardex"));
            ui->leCLCode->setInitialValue(dd.getInt("f_cityledger"));
            ui->teCommonRemark->setPlainText(dd.getString("f_remarks"));
            ui->leCardCode->setInitialValue(dd.getInt("f_card"));
        }
    }
}

void DlgGroupReservationFuck::on_btnTrackChanges_clicked()
{
    DlgTracking::showTracking(TRACK_RESERVATION_GROUP, ui->leGroupCode->text());
}
