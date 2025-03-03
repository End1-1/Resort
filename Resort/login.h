#ifndef LOGIN_H
#define LOGIN_H

#include "baseextendeddialog.h"
#include <QUdpSocket>
#include <QTimer>

namespace Ui
{
class Login;
}

class Login : public BaseExtendedDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    void setLockUser(int id);

private slots:
    void on_btnCancel_clicked();
    void on_btnAddDatabase_clicked();
    void on_btnLogin_clicked();
    void on_leUsername_textChanged(const QString &arg1);
    void on_btnCancel2_clicked();
    void on_btnLoginPin_clicked();
    void on_btn1_clicked();
    void on_btn2_clicked();
    void on_btn3_clicked();
    void on_btn4_clicked();
    void on_btn5_clicked();
    void on_btn6_clicked();
    void on_btn7_clicked();
    void on_btn8_clicked();
    void on_btn9_clicked();
    void on_btn0_clicked();
    void on_btnClearPin_clicked();
    void socketConnected();

private:
    Ui::Login *ui;
    int fLockUser;
    QMap<QString, QMap<QString, QString> > fDatabaseList;
    void getDatabases();
};

#endif // LOGIN_H
