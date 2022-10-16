#include "edateedit.h"

QDate EDateEditFirstDate = QDate::currentDate();
QDate EDateEditMinDate = QDate::fromString("1900-01-01", "yyyy-MM-dd");

EDateEdit::EDateEdit(QWidget *parent) :
    QLineEdit(parent)
{
    setInputMask("00/00/0000");
    setDate(EDateEditFirstDate);
    connect(this, SIGNAL(textChanged(QString)), this, SLOT(newText(QString)));
    //setMaximumWidth(100);
    fRow = 0;
    fColumn = 0;
    fDoNoCheckMinDate = false;
}

void EDateEdit::setText(const QString &text)
{
    QDate d = QDate::fromString(text, def_date_format);
    if (d.isValid() && d < EDateEditMinDate && !fDoNoCheckMinDate) {
        d = EDateEditMinDate;
    }
    QLineEdit::setText(d.toString(def_date_format));
}

void EDateEdit::setDate(const QDate &date)
{
    QDate d = date;
    if (d.isValid() && d < EDateEditMinDate && !fDoNoCheckMinDate) {
        d = EDateEditMinDate;
    }
    setText(d.toString(def_date_format));
}

QString EDateEdit::getField()
{
    return fField;
}

void EDateEdit::setField(const QString &field)
{
    fField = field;
}

bool EDateEdit::getCheckMinDate()
{
    return fDoNoCheckMinDate;
}

void EDateEdit::setCheckMinDate(bool v)
{
    fDoNoCheckMinDate = v;
}

bool EDateEdit::valid()
{
    return date().isValid();
}

void EDateEdit::focusInEvent(QFocusEvent *e)
{
    QLineEdit::focusInEvent(e);
    setCursorPosition(0);
}

void EDateEdit::setBgColor(const QColor &color)
{
    QPalette palette;
    palette.setColor(QPalette::Base, color);
    if (!valid()) {
        palette.setColor(QPalette::Base, Qt::red);
    }
    setPalette(palette);
}

void EDateEdit::newText(const QString &arg1)
{
    QDate d = QDate::fromString(arg1, def_date_format);
    if (d.isValid() && d < EDateEditMinDate) {
        if (!fDoNoCheckMinDate) {
            d = EDateEditMinDate;
        }
    }
    if (valid()) {
        setBgColor(Qt::white);
    } else {
        setBgColor(Qt::red);
    }
    int cp = cursorPosition();
    if (valid()) {
        QLineEdit::setText(d.toString(def_date_format));
    }
    setCursorPosition(cp);
    emit dateChanged(d);
}
