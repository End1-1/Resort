#include "radiogroupwidget.h"
#include <QRadioButton>
#include <QVariant>

RadioGroupWidget::RadioGroupWidget(QWidget *parent) :
    QWidget(parent)
{

}

int RadioGroupWidget::radioTag()
{
    QObjectList ol = children();
    foreach (QObject *o, ol) {
        QRadioButton *b = dynamic_cast<QRadioButton*>(o);
        if (b) {
            if (b->isChecked()) {
                return b->property("Tag").toInt();
            }
        }
    }
    return 0;
}
