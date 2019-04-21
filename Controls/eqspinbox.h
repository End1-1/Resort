#ifndef EQSPINBOX_H
#define EQSPINBOX_H

#include <QSpinBox>

class EQSpinBox : public QSpinBox
{
    Q_OBJECT
    Q_PROPERTY (QString Field READ getField WRITE setField)
public:
    EQSpinBox(QWidget *parent = nullptr);
    void setBgColor(const QColor &color);
    QString getField();
    void setField(const QString &field);
private:
    QString fField;
};

#endif // EQSPINBOX_H
