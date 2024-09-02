#include "travelline.h"
#include "ui_travelline.h"

TravelLine::TravelLine(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::TravelLine)
{
    ui->setupUi(this);
    for (int i = 0; i < fConfig.jaRoomTypes.count(); i++) {
        QJsonObject jo = fConfig.jaRoomTypes.at(i).toObject();
        ui->cbRoomType->addItem(jo["name"].toString(), jo["api"].toString());
    }
    for (int i = 0; i < fConfig.jaRatePlans.count(); i++) {
        QJsonObject jo = fConfig.jaRatePlans.at(i).toObject();
        ui->cbRate->addItem(jo["name"].toString(), jo["api"].toString());
    }

    DoubleDatabase fDD;
    fDD.exec("select * from travelline");
    if (fDD.nextRow()) {
        QJsonObject jo = QJsonDocument::fromJson(fDD.getString(1).toUtf8()).object();
        ui->letlUrl->setText(jo["url"].toString());
        ui->letlHotelID->setText(jo["hotelid"].toString());
        ui->letlUsername->setText(jo["username"].toString());
        ui->letlPassword->setText(jo["password"].toString());
        QJsonArray ja = QJsonDocument::fromJson(fDD.getString("f_room_types").toUtf8()).array();
        for (int i = 0; i < ja.count(); i++) {
            int r = ui->tbltlRoomTypes->rowCount();
            ui->tbltlRoomTypes->setRowCount(r + 1);
            ui->tbltlRoomTypes->setItem(r, 0, new QTableWidgetItem(ja.at(i)["name"].toString()));
            ui->tbltlRoomTypes->setItem(r, 1, new QTableWidgetItem(ja.at(i)["api"].toString()));
            ui->tbltlRoomTypes->setItem(r, 2, new QTableWidgetItem(ja.at(i)["category"].toString()));
            ui->tbltlRoomTypes->setItem(r, 3, new QTableWidgetItem(ja.at(i)["qty"].toString()));
        }
        ja = QJsonDocument::fromJson(fDD.getString("f_rate_plans").toUtf8()).array();
        for (int i = 0; i < ja.count(); i++) {
            int r = ui->tbltlRatePlan->rowCount();
            ui->tbltlRatePlan->setRowCount(r + 1);
            ui->tbltlRatePlan->setItem(r, 0, new QTableWidgetItem(ja.at(i)["name"].toString()));
            ui->tbltlRatePlan->setItem(r, 1, new QTableWidgetItem(ja.at(i)["api"].toString()));
            ui->tbltlRatePlan->setItem(r, 2, new QTableWidgetItem(ja.at(i)["price"].toString()));
        }
    }
}

TravelLine::~TravelLine()
{
    delete ui;
}

void TravelLine::setupTab()
{
    setupTabTextAndIcon("TravelLine", ":/images/TravelLine.png");
}

void TravelLine::on_btnSetRoomRate_clicked()
{
    fConfig.updateAvailability(ui->deStart->date(), ui->deEnd->date(),
                               ui->cbRoomType->currentData().toString(),
                               ui->cbRate->currentData().toString(),
                               ui->leBookingLimit->text().toInt());
}

void TravelLine::saveConfig()
{
    QJsonObject jo;
    jo["url"] = ui->letlUrl->text();
    jo["hotelid"] = ui->letlHotelID->text();
    jo["username"] = ui->letlUsername->text();
    jo["password"] = ui->letlPassword->text();
    QJsonArray ja;
    for (int i = 0; i < ui->tbltlRoomTypes->rowCount(); i++) {
        QJsonObject jrt;
        jrt["name"] = ui->tbltlRoomTypes->item(i, 0)->text();
        jrt["api"] = ui->tbltlRoomTypes->item(i, 1)->text();
        jrt["category"] = ui->tbltlRoomTypes->item(i, 2)->text();
        jrt["qty"] = ui->tbltlRoomTypes->item(i, 3)->text();
        ja.append(jrt);
    }
    QJsonArray ja2;
    for (int i = 0; i < ui->tbltlRatePlan->rowCount(); i++) {
        QJsonObject jrp;
        jrp["name"] = ui->tbltlRatePlan->item(i, 0)->text();
        jrp["api"] = ui->tbltlRatePlan->item(i, 1)->text();
        jrp["price"] = ui->tbltlRatePlan->item(i, 2)->text();
        ja2.append(jrp);
    }

    DoubleDatabase fDD;
    fDD[":f_connection"] = QJsonDocument(jo).toJson(QJsonDocument::Compact);
    fDD[":f_room_types"] = QJsonDocument(ja).toJson(QJsonDocument::Compact);
    fDD[":f_rate_plans"] = QJsonDocument(ja2).toJson(QJsonDocument::Compact);
    fDD.update("travelline", "where f_id=1");

    message_info(tr("Saved"));
}

void TravelLine::on_pushButton_clicked()
{
    saveConfig();
}

void TravelLine::on_btnAddRoomType_clicked()
{
    int row = ui->tbltlRoomTypes->rowCount();
    ui->tbltlRoomTypes->setRowCount(row + 1);
    ui->tbltlRoomTypes->setItem(row, 0, new QTableWidgetItem(""));
    ui->tbltlRoomTypes->setItem(row, 1, new QTableWidgetItem(""));
    ui->tbltlRoomTypes->setItem(row, 2, new QTableWidgetItem(""));
    ui->tbltlRoomTypes->setItem(row, 3, new QTableWidgetItem(""));
}

void TravelLine::on_btnRemoveRoomType_clicked()
{
    QModelIndexList ml = ui->tbltlRoomTypes->selectionModel()->selectedIndexes();
    if (ml.count() == 0) {
        return;
    }
    ui->tbltlRoomTypes->removeRow(ml.at(0).row());
}

void TravelLine::on_btnAddRatePlan_clicked()
{
    int row = ui->tbltlRatePlan->rowCount();
    ui->tbltlRatePlan->setRowCount(row + 1);
    ui->tbltlRatePlan->setItem(row, 0, new QTableWidgetItem(""));
    ui->tbltlRatePlan->setItem(row, 1, new QTableWidgetItem(""));
    ui->tbltlRatePlan->setItem(row, 2, new QTableWidgetItem(""));
}

void TravelLine::on_btnRemoveRatePlan_clicked()
{
    QModelIndexList ml = ui->tbltlRatePlan->selectionModel()->selectedIndexes();
    if (ml.count() == 0) {
        return;
    }
    ui->tbltlRatePlan->removeRow(ml.at(0).row());
}
