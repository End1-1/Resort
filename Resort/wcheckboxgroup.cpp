#include "wcheckboxgroup.h"
#include <QCheckBox>

WCheckBoxGroup::WCheckBoxGroup(QWidget *parent) :
    QWidget(parent)
{

}

QList<QCheckBox *> WCheckBoxGroup::checked() const
{
    QList<QCheckBox *> chl;
    QObjectList ol = children();
    for (QObject *o: ol) {
        QCheckBox *ch = dynamic_cast<QCheckBox*>(o);
        if (ch) {
            if (ch->isChecked()) {
                chl.append(ch);
            }
        }
    }
    return chl;
}

QList<QCheckBox *> WCheckBoxGroup::all() const
{
    QList<QCheckBox *> chl;
    QObjectList ol = children();
    for (QObject *o: ol) {
        QCheckBox *ch = dynamic_cast<QCheckBox*>(o);
        if (ch) {
            chl.append(ch);
        }
    }
    return chl;
}

void WCheckBoxGroup::checkAll(bool v)
{
    QObjectList ol = children();
    for (QObject *o: ol) {
        QCheckBox *ch = dynamic_cast<QCheckBox*>(o);
        if (ch) {
            ch->setChecked(v);
        }
    }
}
