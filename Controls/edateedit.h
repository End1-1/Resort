#ifndef EDATEEDIT_H
#define EDATEEDIT_H

#include "defines.h"
#include <QLineEdit>

extern QDate EDateEditFirstDate;
extern QDate EDateEditMinDate;

class EDateEdit : public QLineEdit
{
    Q_OBJECT
    Q_PROPERTY(QString Field READ getField WRITE setField)
public:
    EDateEdit(QWidget *parent = 0);
    void setText(const QString &text);
    inline QDate date() { return QDate::fromString(text(), def_date_format);}
    inline void setDate(const QDate &date) { QDate d = date; if (d < EDateEditMinDate) {d = EDateEditMinDate;} setText(d.toString(def_date_format)); }
    inline QString dateMySql(bool appostroph = true) {return (appostroph ? QString("'%1'").arg(date().toString(def_mysql_date_format)) : date().toString(def_mysql_date_format));}
    QString getField();
    void setField(const QString &field);
    int fRow;
    int fColumn;
protected:
    virtual void focusInEvent(QFocusEvent *e);
private:
    bool fIsValid;
    QString fField;
    void setBgColor(const QColor &color);
private slots:
    void newText(const QString &arg1);
signals:
    void dateChanged(const QDate &date);
};

#endif // EDATEEDIT_H
