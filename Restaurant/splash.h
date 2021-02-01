#ifndef SPLASH_H
#define SPLASH_H

#include "baseextendeddialogr.h"

namespace Ui {
class Splash;
}

class Splash : public BaseExtendedDialogR
{
    Q_OBJECT

public:
    explicit Splash(QWidget *parent = 0);
    ~Splash();
    void setText(const QString &text);

private:
    Ui::Splash *ui;
};

#endif // SPLASH_H
