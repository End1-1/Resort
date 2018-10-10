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
#include "qsockettextthread.h"
#include <QDebug>

class Q1 : public QThread {
public:
    Q1(int sl) {
        fSl = sl;
    }
    int fSl;
protected:
    virtual void run() {
        DoubleDatabase db(true, false);
        db.exec("select f_id, f_room from f_reservation where f_state=2");
        while (db.nextRow()) {
            BroadcastThread::cmdRefreshCache(cid_reservation, db.getString(0));
            BroadcastThread::cmdRefreshCache(cid_room, db.getString(1));
            BroadcastThread::cmdRefreshCache(cid_red_reservation, db.getString(0));
            BroadcastThread::cmdRefreshCache(cid_reservation_cardex, db.getString(0));
            QThread::msleep(fSl);
            qApp->processEvents();
        }
    }
};

class Q2 : public QThread {
public:
    Q2(int sl, int c) {
        fSl = sl;
        fC = c;
    }
    int fSl;
    int fC;
protected:
    virtual void run() {
        for (int i = 0; i < fC; i++) {
            QSocketTextThread *t = new QSocketTextThread();
            t->start();
            QThread::msleep(fSl);
            qApp->processEvents();
        }
    }
};

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
    Q1 *q1 = new Q1(ui->leUSleep->text().toInt());
    q1->start();
}

void MainWindow::on_btnGoMakeNewConnection_clicked()
{
    Q2 *q2 = new Q2(ui->leMSleep->text().toInt(), ui->leMKCount->text().toInt());
    q2->start();
}
