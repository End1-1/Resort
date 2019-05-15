#include "edoubleedit.h"
#include "stringutils.h"
#include <QDoubleValidator>

EDoubleEdit::EDoubleEdit(QWidget *parent, double min, double max, int prec) :
    QLineEdit(parent)
{
    auto dv = new QDoubleValidator(min, max, prec);
    dv->setNotation(QDoubleValidator::StandardNotation);
    setValidator(dv);
    fValue = 0.0;
    setText("0");
    connect(this, &QLineEdit::textChanged, [this](const QString &arg){
        this->setText(arg);
    });
}

void EDoubleEdit::setText(const QString &text)
{
    bool ok;
    fValue = QLocale().toDouble(text, &ok);
    if (ok) {
        QLineEdit::setText(text);
    }
}

void EDoubleEdit::setDouble(double d)
{
    fValue = d;
    QLineEdit::setText(float_str(d));
}

QString EDoubleEdit::text() const
{
    return float_str(fValue);
}

double &EDoubleEdit::getDouble()
{
    return fValue;
}
