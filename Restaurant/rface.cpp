#include "rface.h"
#include "ui_rface.h"
#include "rlogin.h"
#include "rmessage.h"
#include "rdesk.h"
#include "splash.h"
#include "dlgbreakfast.h"
#include "appconfig.h"
#include "dlgonebreakfasat.h"
#include "cacherights.h"
#include "rchangehall.h"
#include "dlgexitbyversion.h"
#include "broadcastthread.h"
#include "dlgbanket.h"
#include <QPainter>
#include <QScrollBar>
#include <QItemDelegate>
#include <QThread>
#include <QHostInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkProxy>

#define hall_refresh_timeout 10

class TableItemDelegate : public QItemDelegate {
protected:
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
        QRect rectFill =  option.rect;
        rectFill.adjust(2, 2, -2, -2);
        painter->fillRect(rectFill, Qt::white);
        if (!index.isValid()) {
            return;
        }
        TableStruct *t = index.data(Qt::UserRole).value<TableStruct*>();
        if (!t) {
            return;
        }

        if (!t->fOrder.isEmpty()) {
            painter->fillRect(rectFill, QColor::fromRgb(200, 245, 195));
        }

        if (t->fPrint != 0) {
            painter->fillRect(rectFill, Qt::yellow);
        }

        if (t->fLockStation.length() > 0) {
            painter->fillRect(rectFill, QColor::fromRgb(245, 166, 166));
        }

        QRect rectTable = rectFill;
        rectTable.adjust(3, 3, -3, -3);
        QFont f(qApp->font());
        f.setPointSize(18);
        f.setBold(true);
        painter->setPen(Qt::black);
        painter->setFont(f);
        painter->drawText(rectTable, t->fName);
        painter->setPen(Qt::darkRed);
        rectTable.adjust(-1, -1, 0, 0);
        painter->drawText(rectTable, t->fName);

        if (t->fOrder.length() > 0) {
            int y = rectTable.top() + 10;
            int x = rectTable.left() + QFontMetrics(f).width(t->fName) + 15;
            int tableNameHeight = rectTable.top() + QFontMetrics(f).height() + 5;
            f.setPointSize(8);
            painter->setFont(f);
            int deltaY = QFontMetrics(f).height() - 1;
            painter->drawText(x, y, t->fStaff);
            y += deltaY;
            painter->drawText(x, y, t->fAmount);
            x = rectTable.left();
            y = tableNameHeight + 2;
            painter->drawText(x, y, t->fDateOpen);
            y += deltaY;
            painter->drawText(x, y, t->fComment);
        }
    }
};

RFace::RFace(QWidget *parent) :
    BaseExtendedDialogR(parent),
    ui(new Ui::RFace),
    fCommand(nullptr)
{
    ui->setupUi(this);
    fCanClose = false;
    ui->tblTables->setItemDelegate(new TableItemDelegate());
    fCurrenTableState = 0;
    fTimerCounter = 0;
    fSocket.setProxy(QNetworkProxy::NoProxy);
    fIsConfigured = true;
    // setup tax parameters
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_app"] = "menu";
    fDD.exec("select f_version from s_app where f_app='menu'");
    if (fDD.nextRow()) {
        fMenuNumber = fDD.getInt(0);
    } else {
        fMenuNumber = 0;
    }
    fDD[":f_comp"] = QHostInfo::localHostName();
    fDD.exec("select f_address, f_port, f_password, f_adg, f_hall, f_menu from s_tax_print where upper(f_comp)=upper(:f_comp)");
    if (fDD.nextRow()) {
        QList<QList<QVariant> > &fDbRows = fDD.fDbRows;
        fPreferences.setDb(def_tax_address, fDbRows.at(0).at(0).toString());
        fPreferences.setDb(def_tax_port, fDbRows.at(0).at(1).toString());
        fPreferences.setDb(def_tax_password, fDbRows.at(0).at(2).toString());
        fPreferences.setDb(def_tax_adg, fDbRows.at(0).at(3).toString());
        qDebug() << fDbRows.at(0).at(4).toString();
        fPreferences.setDb(def_default_hall, fDbRows.at(0).at(4).toString());
        fPreferences.setDb(def_default_menu, fDbRows.at(0).at(5).toString());
        fCurrentHall = fDbRows.at(0).at(4).toInt();

        qDebug() << fPreferences.getDb(def_default_hall);
        if (fPreferences.getDb(def_default_hall).toInt() == 0) {
            message_error("Please, set default hall for this station.");
            fIsConfigured = false;
            qApp->quit();
        }

        timeout();
        connect(&fTimer, SIGNAL(timeout()), this, SLOT(timeout()));
        fTimer.start(2000);
    }
    fParent = this;
    ui->btnBreakFast->setVisible(false);
    fDD[":f_id"] = 2;
    fDD.exec("select f_rate from f_acc_currencies where f_id=:f_id");
    if (fDD.nextRow()) {
        def_usd = fDD.getDouble(0);
    }
    ui->frErr->setVisible(false);
    if (doubleDatabase) {
        ui->frErr->setStyleSheet("background-color:blue;");
        ui->frErr->setVisible(true);
    }
    connect(this, SIGNAL(updateCache(int,QString)), &fCacheOne, SLOT(updateCache(int,QString)));
    __rface = this;

    fDD.exec("select current_timestamp");
    fDD.nextRow();
    if (QDateTime::currentDateTime() < fDD.getValue(0).toDateTime().addSecs(-300)) {
        fIsConfigured = false;
        message_error(tr("Server time and workstation time note same, aborting."));
        return;
    }
}

RFace::~RFace()
{
    delete ui;
}

bool RFace::setup()
{
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_comp"] = def_station + QHostInfo::localHostName();
    fDD.exec("select f_active, f_host, f_port, f_password from serv_tax where upper(f_comp)=upper(:f_comp)");
    if (fDD.nextRow()) {
        if (fDD.getInt(0) > 0) {
            __TAX_HOST = fDD.getValue("f_host").toString();
            __TAX_PORT = fDD.getValue("f_port").toString();
            __TAX_PASS = fDD.getValue("f_pass").toString();
        }
    } else {
        fDD[":f_active"] = 0;
        fDD[":f_comp"] = def_station + QHostInfo::localHostName();
        fDD.insert("serv_tax", false);
    }

    fCommand.setSocket(&fSocket);
    connect(&fSocket, SIGNAL(readyRead()), this, SLOT(socketReadyRead()));
    connect(&fSocket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
    connect(&fCommand, SIGNAL(parseCommand(QString)), this, SLOT(parseCommand(QString)));
    fSocket.connectToHost(AppConfig::fServerAddress, 1250);
    if (fSocket.waitForConnected()) {
        QString data = QString("{\"db\" : {\"database\" : \"%1\", \"user\" : \"%2\", \"password\" : \"password\"}, "
                               "\"command\" : {\"command\": \"identify\"}}")
                .arg(__dd1Database)
                .arg(WORKING_USERNAME);
        int size = data.toUtf8().length();
        QByteArray dataToSend;
        dataToSend.append(reinterpret_cast<const char*>(&size), sizeof(size));
        dataToSend.append(data.toUtf8(), data.toUtf8().length());
        fSocket.write(dataToSend, dataToSend.length());
        fSocket.flush();
    } else {
        message_error(tr("Cannot connect to broadcast server, force logout"));
        message_error(__dd1Host);
        //return false;
    }
    Splash s(this);
    s.show();
    s.setText(tr("Load hall..."));
    fHall.init();
    int rowHeight = 60;
    int rowCount = ui->tblTables->height() / rowHeight;
    int delta = ui->tblTables->height() - (rowCount * rowHeight);
    rowHeight += (delta / rowCount);
    ui->tblTables->verticalHeader()->setDefaultSectionSize(rowHeight);
    setupTables(fCurrentHall, 0);
    s.setText(tr("Load menu..."));
    DishesTable dt;
    dt.init(&s);
    s.setText(tr("Setup current menu..."));

    s.hide();
    return true;
}

void RFace::secondDbError()
{
    ui->frErr->setStyleSheet("background-color:red;");
    ui->frErr->setVisible(true);
}

void RFace::timeout()
{
    fTimer.stop();
    ui->lbWorkingDate->setText(QString("%1\n%2 %3").arg(tr("Working date")).arg(WORKING_DATE.toString(def_date_format)).arg(QTime::currentTime().toString("HH:mm")));
    fTimerCounter++;
    if (fTimerCounter % hall_refresh_timeout == 0) {
        fHall.refresh();
        ui->tblTables->viewport()->update();
        DoubleDatabase fDD(true, doubleDatabase);
        fDD[":f_app"] = _APPLICATION_;
        fDD.exec("select f_version from s_app where lower(f_app)=lower(:f_app)");
        if (fDD.nextRow()) {
            if (Utils::getVersionString(qApp->applicationFilePath()) != fDD.getString(0)) {
                DlgExitByVersion::exit(Utils::getVersionString(qApp->applicationFilePath()), fDD.getString(0));
                return;
            }
        }
        fDD[":f_app"] = "menu";
        fDD.exec("select f_version from s_app where f_app='menu'");
        if (fDD.nextRow()) {
            int menu = fDD.getInt(0);
            if (menu != fMenuNumber) {
                DlgExitByVersion::exit(QString::number(fMenuNumber), fDD.getString(0));
                return;
            }
        }
    }
    fTimer.start();
}

void RFace::socketReadyRead()
{
    QTcpSocket *s = static_cast<QTcpSocket*>(sender());
    fCommand.readBytes(s->readAll());
}

void RFace::socketDisconnected()
{
    message_error(tr("Connection to the server lost. Application will quit"));
    qApp->quit();
}

void RFace::parseCommand(const QString &command)
{
    QJsonDocument jDoc = QJsonDocument::fromJson(command.toUtf8());
    QJsonObject jObj = jDoc.object();
    QString cmd = jObj.value("command").toString();
    if (cmd == "refresh_reservations") {
    } else if (cmd == "update_cache") {
        int cacheId = jObj.value("cache").toInt();
        QString item = jObj.value("item").toString();
        emit updateCache(cacheId, item);
    } else if (cmd == "session") {
        AppConfig::fAppSession = jObj["session"].toString();
    } else {
        QVariantMap m = jObj.toVariantMap();
        switch (m["command"].toInt()) {
        case cmd_end_of_day:
            message_info("Global configuration was changed. Applicationn will quit");
            qApp->quit();
            break;
        case cmd_global_settings:
            message_info("End of Day :) Application will now quit");
            qApp->quit();
            break;
        }
    }
}

void RFace::on_tableWidget_clicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
}

void RFace::on_btnExit_clicked()
{
    if (!message_question(tr("Confirm to close application")) ) {
        return;
    }
    QString session = QString("{\"command\":{\"command\":\"logout\",\"session\":\"%1\"}}").arg(AppConfig::fAppSession);
    int s = session.length();
    QByteArray bs;
    bs.append(reinterpret_cast<const char*>(&s), sizeof(s));
    bs.append(session);
    fSocket.write(bs.data(), bs.length());
    fSocket.flush();
    fSocket.waitForBytesWritten();
    fSocket.disconnect();
    fCanClose = true;
    qApp->quit();
}

User *RFace::login()
{
    QString login;
    if (RLogin::getLogin(login, tr("Login"), this)) {
        User *u = new User(login, this);
        if (!u->isValid()) {
            delete u;
            u = nullptr;
            message_error(tr("Access denied"));
            return nullptr;
        }
        return u;
    } else {
        return nullptr;
    }
}

void RFace::setupTables(int hallId, int busy)
{
    QList<TableStruct*> tables;
    ui->tblTables->clearContents();
    Hall::filterTables(hallId, busy, tables);
    int tablesCount = tables.count();
    Utils::setupTableFullColumnWidth(ui->tblTables, 150, tablesCount);
    int row = 0, col = 0;
    for (QList<TableStruct*>::const_iterator it = tables.begin(); it != tables.end(); it++) {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setData(Qt::UserRole, QVariant::fromValue(*it));
        ui->tblTables->setItem(row, col, item);
        col++;
        if (col > ui->tblTables->columnCount() - 1) {
            col = 0;
            row++;
        }
    }
}

void RFace::scrollTables(int direction)
{
    int value = (ui->tblTables->height() / ui->tblTables->verticalHeader()->defaultSectionSize()) - 1;
    int currValue = ui->tblTables->verticalScrollBar()->value();
    ui->tblTables->verticalScrollBar()->setValue(currValue + (value * direction));
}

void RFace::on_tblTables_clicked(const QModelIndex &index)
{
    if (!index.isValid())  {
        return;
    }
    TableStruct *t = index.data(Qt::UserRole).value<TableStruct*>();
    if (!t) {
        return;
    }
    User *user = nullptr;
    fTimer.stop();
    if ((user = login())) {
        RDesk *d = new RDesk(this);
        d->prepareToShow();
        d->setStaff(user);
        if (d->setup(t)) {
            d->exec();
            fHall.refresh();
            ui->tblTables->viewport()->update();
        }
        delete d;
    }
    fTimer.start(2000);
}

void RFace::on_btnUp_clicked()
{
    scrollTables(-1);
}

void RFace::on_btnDown_clicked()
{
    scrollTables(1);
}

void RFace::on_btnChangeHall_clicked()
{
    setupTables(fCurrentHall, fCurrenTableState);
    RChangeHall *h = new RChangeHall(this);
    h->setup(Hall::fHallTable);
    if (h->exec() == QDialog::Accepted)  {
        fCurrentHall = h->hall();
        setupTables(fCurrentHall, fCurrenTableState);
    }
    delete h;
}

void RFace::on_btnBreakFast_clicked()
{
    User *u = login();
    if (!u) {
        return;
    }
    if (!g__(cr__o_breakfast, u->fId)) {
        return;
    }
    DlgOneBreakfasat *b = new DlgOneBreakfasat(u, this);
    b->exec();
    delete b;
}

void RFace::on_btnBanket_clicked()
{
    User *u = login();
    if (!u) {
        return;
    }
    if (!g__(cr__o_banquet, u->fId)) {
        return;
    }
    DlgBanket *b = new DlgBanket(u, this);
    b->exec();
    delete b;
}

void RFace::on_btnTools_clicked()
{
    User *user = nullptr;
    if ((user = login())) {
        RDesk *d = new RDesk(this);
        d->setStaff(user);
        d->openTools();
        delete d;
    }
}

void RFace::closeEvent(QCloseEvent *e)
{
    if (fCanClose) {
        QDialog::closeEvent(e);
        return;
    }
    e->ignore();
    on_btnExit_clicked();
}
