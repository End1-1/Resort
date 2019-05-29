#ifndef WCARDEX_H
#define WCARDEX_H

#include "basewidget.h"

namespace Ui {
class WCardex;
}

class WCardex : public BaseWidget
{
    Q_OBJECT

public:
    explicit WCardex(QWidget *parent = nullptr);
    ~WCardex();
    bool empty();
    QString cardex();

private:
    Ui::WCardex *ui;
};

#endif // WCARDEX_H
