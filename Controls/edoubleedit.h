#ifndef EDOUBLEEDIT_H
#define EDOUBLEEDIT_H

#include <QLineEdit>

class EDoubleEdit : public QLineEdit
{
    Q_OBJECT

public:
    EDoubleEdit(QWidget *parent = nullptr, double min = 0.0, double max = 999999999.0, int prec = 2);
    void setText(const QString &text);
    void setDouble(double d);
    QString text() const;
    double &getDouble();

private:
    double fValue;
};

#endif // EDOUBLEEDIT_H
