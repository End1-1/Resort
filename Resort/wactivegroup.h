#ifndef WACTIVEGROUP_H
#define WACTIVEGROUP_H

#include "basewidget.h"

namespace Ui {
class WActiveGroup;
}

class WActiveGroup : public BaseWidget
{
    Q_OBJECT

public:
    explicit WActiveGroup(QWidget *parent = nullptr);
    ~WActiveGroup();
    int group();

private:
    Ui::WActiveGroup *ui;
};

#endif // WACTIVEGROUP_H
