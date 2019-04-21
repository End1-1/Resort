#ifndef RADIOGROUPWIDGET_H
#define RADIOGROUPWIDGET_H

#include <QWidget>

class RadioGroupWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RadioGroupWidget(QWidget *parent = nullptr);
    int radioTag();
};

#endif // RADIOGROUPWIDGET_H
