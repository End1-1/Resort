#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "broadcastthread.h"
#include "cachereservation.h"
#include "cacheroom.h"
#include "cacheredreservation.h"
#include "cachereservationcardex.h"
#include "appconfig.h"
#include "logging.h"
#include "doubledatabase.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    AppConfig::fServerAddress = "10.1.0.2";
    __dd1Host = "10.1.0.2";
    __dd1Database = "resort";
    __dd1Username = "root";
    __dd1Password = "root5";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnGo_clicked()
{
    DoubleDatabase db(true, false);
    db.exec("select f_id, f_room from f_reservation where f_state=2");
    int i = 0;
    while (db.nextRow()) {
        BroadcastThread::cmdRefreshCache(cid_reservation, db.getString(0));
        BroadcastThread::cmdRefreshCache(cid_room, db.getString(1));
        BroadcastThread::cmdRefreshCache(cid_red_reservation, db.getString(0));
        BroadcastThread::cmdRefreshCache(cid_reservation_cardex, db.getString(0));
        qDebug() << i++;
        if (i % 20 == 0) {
            for (int j = 0; j < 50; j++) {
                qApp->processEvents();
                QThread::msleep(100);
            }
        }
    }
}
