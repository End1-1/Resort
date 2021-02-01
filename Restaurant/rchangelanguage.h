#ifndef RCHANGELANGUAGE_H
#define RCHANGELANGUAGE_H

#include "baseextendeddialogr.h"

namespace Ui {
class RChangeLanguage;
}

class RChangeLanguage : public BaseExtendedDialogR
{
    Q_OBJECT

public:
    explicit RChangeLanguage(QWidget *parent = 0);
    ~RChangeLanguage();
    static bool changeLanguage(QWidget *parent = 0);

private slots:
    void on_btnCancel_clicked();

    void on_btnOk_clicked();

private:
    Ui::RChangeLanguage *ui;
};

#endif // RCHANGELANGUAGE_H
