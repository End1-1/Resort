#include "whotelstatus.h"
#include "ui_whotelstatus.h"

WHotelStatus::WHotelStatus(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WHotelStatus)
{
    ui->setupUi(this);
    DoubleDatabase fDD;
    QStringList row1, row2, row3, row4;
    row1 << "Working date" << "" << "Arrivals" << "" << "Empty room" << "" << "Paid occ." << "" << "Male" << "" << "F/B" << "0";
    row2 << "Rooms in hotel" << "" << "Departures" << "" << "Room to sell" << "" << "Comp. occ" << "" << "Female" << "" << "H/B" << "0";
    row3 << "Number of beds" << "" << "Occupied" << "" << "Avg. room rate" << "" << "   " << "" << "Childs" << "" << "B/B" << "0";
    row4 << "Available rooms" << "" << ""       << "" << "Curr. occ." << "" << "    " << "" << "" << "" << "B/O" << "0";
    ui->tblMain->setRowCount(4);
    for (int i = 0; i < ui->tblMain->columnCount(); i++) {
        ui->tblMain->setItemWithValue(0, i, row1.at(i));
    }
    for (int i = 0; i < ui->tblMain->columnCount(); i++) {
        ui->tblMain->setItemWithValue(1, i, row2.at(i));
    }
    for (int i = 0; i < ui->tblMain->columnCount(); i++) {
        ui->tblMain->setItemWithValue(2, i, row3.at(i));
    }
    for (int i = 0; i < ui->tblMain->columnCount(); i++) {
        ui->tblMain->setItemWithValue(3, i, row4.at(i));
    }

    ui->tblMain->setItemWithValue(0, 1, WORKING_DATE);
    ui->tblMain->setItemWithValue(1, 1, fDD.singleResult("select count(f_id) from f_room").toInt());
    ui->tblMain->setItemWithValue(2, 1, fDD.singleResult("select sum(f_bedQty) from f_room").toInt());
    ui->tblMain->setItemWithValue(2, 3, fDD.singleResult("select count(f_id) from f_reservation where f_state=1").toInt());
    ui->tblMain->setItemWithValue(0, 5, ui->tblMain->toInt(1, 1) - ui->tblMain->toInt(2, 3));
    ui->tblMain->setItemWithValue(2, 5, fDD.singleResult("select sum(f_pricePerNight) / count(f_id) from f_reservation where f_state=1"));
    fDD.exec("select sum(f_man) as man, sum(f_woman) as woman, sum(f_child) as child from f_reservation where f_state=1");
    fDD.nextRow();
    ui->tblMain->setItemWithValue(0, 9, fDD.getValue("man"));
    ui->tblMain->setItemWithValue(1, 9, fDD.getValue("woman"));
    ui->tblMain->setItemWithValue(2, 9, fDD.getValue("child"));
    QMap<QString, int> fBB;
    fBB["F/B"] = 0;
    fBB["H/B"] = 1;
    fBB["B/B"] = 2;
    fBB["B/O"] = 3;
    fDD.exec("select ra.f_" + def_lang + ", count(r.f_id) from f_reservation r "
              "left join f_room_arrangement ra on ra.f_id=r.f_arrangement "
              "where f_state=1 group by 1");
    for (int i = 0; i  < fDD.rowCount(); i++) {
        ui->tblMain->setItemWithValue(fBB[fDD.getValue(i, 0).toString()], 11, fDD.getValue(i, 1));
    }

    fDD[":f_startDate"] = WORKING_DATE;
    fDD[":f_state"] = RESERVE_RESERVE;
    fDD.exec("select r.f_room, concat(g.f_firstName, ' ', g.f_lastName), "
               "r.f_man+r.f_woman+r.f_child, r.f_endDate "
               "from f_reservation r "
               "left join f_guests g on g.f_id=r.f_guest "
               "where r.f_startDate=:f_startDate and r.f_state=:f_state");
    ui->tblArrivals->setColumnCount(4);
    QStringList ht;
    ht << QString("Room") << QString("Guest") << QString("Pax") << QString("Depature");
    ui->tblArrivals->setHorizontalHeaderLabels(ht);
    Utils::tableSetColumnWidths(ui->tblArrivals, ui->tblArrivals->columnCount(),
                                80, 150, 50, 100);
    Utils::fillTableWithData(ui->tblArrivals, fDD.fDbRows);
    ui->lbArrivals->setText(QString("%1 (%2)").arg(tr("Arrivals Today")).arg(fDD.rowCount()));
    ui->tblMain->setItemWithValue(0, 3, fDD.rowCount());

    fDD[":f_startDate"] = WORKING_DATE;
    fDD[":f_state"] = RESERVE_CHECKIN;
    fDD.exec("select r.f_room, concat(g.f_firstName, ' ', g.f_lastName), "
               "r.f_man+r.f_woman+r.f_child, r.f_endDate "
               "from f_reservation r "
               "left join f_guests g on g.f_id=r.f_guest "
               "where r.f_startDate=:f_startDate and r.f_state=:f_state");
    ui->tblAlreadyArrived->setColumnCount(4);
    ht.clear();
    ht << QString("Room") << QString("Guest") << QString("Pax") << QString("Depature");
    ui->tblAlreadyArrived->setHorizontalHeaderLabels(ht);
    Utils::tableSetColumnWidths(ui->tblAlreadyArrived, ui->tblAlreadyArrived->columnCount(),
                                80, 150, 50, 100);
    Utils::fillTableWithData(ui->tblAlreadyArrived, fDD.fDbRows);
    ui->lbAlreadyAriived->setText(QString("%1 (%2)").arg(tr("Already arrived")).arg(fDD.rowCount()));

    fDD[":f_endDate"] = WORKING_DATE;
    fDD[":f_state"] = RESERVE_CHECKIN;
    fDD.exec("select r.f_room, concat(g.f_firstName, ' ', g.f_lastName), "
               "r.f_man+r.f_woman+r.f_child, r.f_endDate "
               "from f_reservation r "
               "left join f_guests g on g.f_id=r.f_guest "
               "where r.f_endDate=:f_endDate and r.f_state=:f_state");
    ui->tblDepartures->setColumnCount(4);
    ht.clear();
    ht << QString("Room") << QString("Guest") << QString("Pax") << QString("Depature");
    ui->tblDepartures->setHorizontalHeaderLabels(ht);
    Utils::tableSetColumnWidths(ui->tblDepartures, ui->tblDepartures->columnCount(),
                                80, 150, 50, 100);
    Utils::fillTableWithData(ui->tblDepartures, fDD.fDbRows);
    ui->lbDepartures->setText(QString("%1 (%2)").arg(tr("Departures Today")).arg(fDD.rowCount()));
    ui->tblMain->setItemWithValue(1, 3, fDD.rowCount());

    fDD[":f_endDate"] = WORKING_DATE;
    fDD[":f_state"] = RESERVE_CHECKOUT;
    fDD.exec("select r.f_room, concat(g.f_firstName, ' ', g.f_lastName), "
               "r.f_man+r.f_woman+r.f_child, r.f_endDate "
               "from f_reservation r "
               "left join f_guests g on g.f_id=r.f_guest "
               "where r.f_endDate=:f_endDate and r.f_state=:f_state");
    ui->tblAlreadyCheckout->setColumnCount(4);
    ht.clear();
    ht << QString("Room") << QString("Guest") << QString("Pax") << QString("Depature");
    ui->tblAlreadyCheckout->setHorizontalHeaderLabels(ht);
    Utils::tableSetColumnWidths(ui->tblAlreadyCheckout, ui->tblAlreadyCheckout->columnCount(),
                                80, 150, 50, 100);
    Utils::fillTableWithData(ui->tblAlreadyCheckout, fDD.fDbRows);
    ui->lbAlreadyCheckout->setText(QString("%1 (%2)").arg(tr("Already checkout")).arg(fDD.rowCount()));

    fDD[":f_state"] = RESERVE_CHECKIN;
    fDD.exec("select r.f_room, concat(g.f_firstName, ' ', g.f_lastName), "
               "r.f_startDate, r.f_endDate, r.f_man+r.f_woman+r.f_child "
               "from f_reservation r "
               "left join f_guests g on g.f_id=r.f_guest "
               "where r.f_state=:f_state order by r.f_room ");
    ui->tblGuestInHouse->setColumnCount(5);
    ht.clear();
    ht << QString("Room") << QString("Guest") << QString("Arrival") << QString("Departure") << QString("Pax");
    ui->tblGuestInHouse->setHorizontalHeaderLabels(ht);
    Utils::tableSetColumnWidths(ui->tblGuestInHouse, ui->tblGuestInHouse->columnCount(),
                                80, 150, 100, 100, 0);
    Utils::fillTableWithData(ui->tblGuestInHouse, fDD.fDbRows);
    ui->lbGuestInHouse->setText(QString("%1 (Occ. rooms: %2, Total guests: %3)").arg(tr("Guest in house")).arg(fDD.rowCount()).arg((int)ui->tblGuestInHouse->sumOfColumn(4)));

    Utils::tableSetColumnWidths(ui->tblCategory, ui->tblCategory->columnCount(), 30, 150, 50, 50);
    fDD.exec("select c.f_short, c.f_description, coalesce(rmc.qty, 0), coalesce(rc.qty, 0) \
               from f_room_classes c \
               left join (select rm.f_class, count(f_id) as qty from f_room rm group by 1) rmc on rmc.f_class=c.f_id \
               left join (select rm.f_class, count(r.f_id) as qty from f_reservation r left join f_room rm on rm.f_id=r.f_room where r.f_state=1 group by 1) rc on rc.f_class=c.f_id \
               group by 1, 2, 3");
    Utils::fillTableWithData(ui->tblCategory, fDD.fDbRows);

    Utils::tableSetColumnWidths(ui->tblRoomStatus, ui->tblRoomStatus->columnCount(), 200, 50);
    fDD.exec("select rs.f_en, coalesce(rmc.total, 0) \
               from f_room_state rs \
               left join (select r.f_state, count(r.f_id) as total from f_room r group by 1) rmc on rmc.f_state=rs.f_id");
    Utils::fillTableWithData(ui->tblRoomStatus, fDD.fDbRows);

    Utils::tableSetColumnWidths(ui->tblNationality, ui->tblNationality->columnCount(),
                                40, 200, 50, 50);
    fDD.exec("select n.f_short, n.f_name, coalesce(rn.total, 0), coalesce(rp.total, 0) \
               from f_nationality n \
               left join (select g.f_nation, count(r.f_id) as total from f_reservation r \
                   left join f_guests g on g.f_id=r.f_guest \
                   where r.f_state=1 group by 1) rn on rn.f_nation=n.f_short \
               left join (select g.f_nation, count(rg.f_id) as total from f_reservation_guests rg \
                   left join f_reservation r on r.f_id=rg.f_reservation \
                   left join f_guests g on g.f_id=rg.f_guest \
                   where r.f_state=1 group by 1) rp on rp.f_nation=n.f_short \
               where rn.total is not null");
    Utils::fillTableWithData(ui->tblNationality, fDD.fDbRows);

    ui->tblMain->setMaximumHeight((ui->tblMain->rowCount() * ui->tblMain->verticalHeader()->defaultSectionSize()) + 5);
    int maxWidth = 0;
    for (int i = 0; i < ui->tblRoomStatus->columnCount(); i++) {
        maxWidth += ui->tblRoomStatus->columnWidth(i);
    }
    maxWidth += 20;
    ui->tblRoomStatus->setMaximumWidth(maxWidth);

    maxWidth = 0;
    for (int i = 0; i < ui->tblCategory->columnCount(); i++) {
        maxWidth += ui->tblCategory->columnWidth(i);
    }
    maxWidth += 20;
    ui->tblCategory->setMaximumWidth(maxWidth);
    //Availables rooms
    ui->tblMain->setItemWithValue(3, 1, ui->tblMain->itemValue(1, 1).toInt()
                         - ui->tblMain->itemValue(0, 3).toInt()
                         - ui->tblMain->itemValue(2, 3).toInt()
                         + ui->tblMain->itemValue(1, 3).toInt());
    //Curr occ.
    ui->tblMain->setItemWithValue(3, 5, float_str(ui->tblMain->itemValue(2, 3).toDouble()
                                  / ui->tblMain->itemValue(1, 1).toDouble()
                                  * 100, 0) + "%");
    //Paid occ.
    fDD[":f_state"] = RESERVE_CHECKIN;
    fDD[":f_rate"] = 0;
    fDD.exec("select count(f_id) from f_reservation where f_state=:f_state and f_pricepernight>:f_rate");
    fDD.nextRow();
    ui->tblMain->setItemWithValue(0, 7, float_str(fDD.getInt(0)
                                                  / ui->tblMain->itemValue(2, 3).toDouble()
                                                  * 100, 0) + "%");

    //Comp occ.
    fDD[":f_state"] = RESERVE_CHECKIN;
    fDD[":f_rate"] = 0;
    fDD.exec("select count(f_id) from f_reservation where f_state=:f_state and f_pricepernight=:f_rate");
    fDD.nextRow();
    ui->tblMain->setItemWithValue(1, 7, float_str(fDD.getInt(0)
                                                  / ui->tblMain->itemValue(2, 3).toDouble()
                                                  * 100, 0) + "%");
}

WHotelStatus::~WHotelStatus()
{
    delete ui;
}

void WHotelStatus::setup()
{
    setupTabTextAndIcon(tr("Hotel Status"), ":/images/info.png");
}
