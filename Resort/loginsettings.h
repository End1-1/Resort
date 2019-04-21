#ifndef LOGINSETTINGS_H
#define LOGINSETTINGS_H

#include "baseextendeddialog.h"

namespace Ui {
class LoginSettings;
}

class LoginSettings : public BaseExtendedDialog
{
    Q_OBJECT

public:
    explicit LoginSettings(QWidget *parent = nullptr);
    ~LoginSettings();

private slots:
    void on_btnCancel_clicked();
    void on_btnOk_clicked();

private:
    Ui::LoginSettings *ui;
};

#endif // LOGINSETTINGS_H
