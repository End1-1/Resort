#ifndef DLGMAIN_H
#define DLGMAIN_H

#include "preferences.h"
#include <QDialog>
#include <QSerialPort>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QTimer>

namespace Ui {
class DlgMain;
}

class DlgMain : public QDialog
{
    Q_OBJECT

public:
    explicit DlgMain(QWidget *parent = nullptr);
    ~DlgMain();
    virtual void closeEvent(QCloseEvent *e);

private:
    Preferences fPref;
    Ui::DlgMain *ui;
    QSerialPort fPort;
    QString fBuffer;
    QMap<QString, int> fCallMap;
    QMap<QString, double> rates;
    QMap<QString, int> fCallType;
    QMenu fTrayMenu;
    QSystemTrayIcon fTrayIcon;
    bool fCanClose;
    QTimer fReadFromFileTimer;
    void processLine(const QString &line);
    void processLine1(QString line);
    void processLog1(const QString &num1, const QString &num2, const QString &durationStr, const QString &direction, const QDate &date, const QTime &time);
    void callLog(const QString &txt);
    void writeToFile(const QString &line);
    void configureComPort();

private slots:
    void readyRead();
    void readFromFileTimeout();
    void portError(QSerialPort::SerialPortError serialPortError);
    void iconClicked(QSystemTrayIcon::ActivationReason r);
    void appTerminate();
    void on_leUserId_textChanged(const QString &arg1);
    void on_leHost_textChanged(const QString &arg1);
    void on_leDb_textChanged(const QString &arg1);
    void on_leUsername_textChanged(const QString &arg1);
    void on_lePassword_textChanged(const QString &arg1);
    void on_btnReconnect_clicked();
    void on_chFileLog_clicked(bool checked);
    void on_leATSPort_textChanged(const QString &arg1);
    void on_cbATS_currentIndexChanged(int index);
    void on_cbComData_currentIndexChanged(int index);
    void on_cbComParity_currentIndexChanged(int index);
    void on_leLine_textChanged(const QString &arg1);
    void on_leIncomingNumber_textChanged(const QString &arg1);
    void on_lePathToExecutable_textChanged(const QString &arg1);
    void on_leTime_textChanged(const QString &arg1);
    void on_leAirHost_textChanged(const QString &arg1);
    void on_leAirDb_textChanged(const QString &arg1);
    void on_leAirUser_textChanged(const QString &arg1);
    void on_leAirPass_textChanged(const QString &arg1);
    void on_btnTest_clicked();
    void on_leRawData_textChanged(const QString &arg1);
    void on_cbComFlowControl_currentIndexChanged(int index);
    void on_leIntCallItemCode_textChanged(const QString &arg1);
    void on_leOutCallItemCode_textChanged(const QString &arg1);
    void on_chReadFromFile_clicked(bool checked);
    void on_btnFile_clicked();
};

#endif // DLGMAIN_H

