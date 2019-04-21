#ifndef WWEB_H
#define WWEB_H

#include "basewidget.h"

namespace Ui {
class WWeb;
}

class WWeb : public BaseWidget
{
    Q_OBJECT

public:
    explicit WWeb(QWidget *parent = nullptr);
    ~WWeb();

private slots:
    void on_leAddress_returnPressed();

    void on_btnGo_clicked();

private:
    Ui::WWeb *ui;
};

#endif // WWEB_H
