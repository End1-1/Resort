#ifndef ECOLORLINEEDIT_H
#define ECOLORLINEEDIT_H

#include "eqlineedit.h"

class EColorLineEdit : public EQLineEdit
{
    Q_OBJECT
    Q_PROPERTY (QString Field READ getField WRITE setField)

public:
    EColorLineEdit(QWidget *parent = nullptr);
    QString getField();
    void setField(const QString &name);
    QColor color();
    void setColor(int c);

protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *e);

private:
    QString fField;
    int fColor;

private slots:
    void colorChanged(const QString &arg);

signals:
     void doubleClicked();
};

#endif // ECOLORLINEEDIT_H
