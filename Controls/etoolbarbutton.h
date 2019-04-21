#ifndef ETOOLBARBUTTON_H
#define ETOOLBARBUTTON_H

#include <QToolButton>

class EToolbarButton : public QToolButton
{
    Q_OBJECT
    Q_PROPERTY(QString fTag READ getTag WRITE setTag)
public:
    EToolbarButton(QWidget *parent = nullptr);
    QString getTag();
    void setTag(const QString &tag);
private:
    QString fTag;
};

#endif // ETOOLBARBUTTON_H
