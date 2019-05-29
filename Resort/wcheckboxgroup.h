#ifndef WCHECKBOXGROUP_H
#define WCHECKBOXGROUP_H

#include <QWidget>

class QCheckBox;

class WCheckBoxGroup : public QWidget
{
    Q_OBJECT
public:
    explicit WCheckBoxGroup(QWidget *parent = nullptr);
    QList<QCheckBox *> checked() const;
    QList<QCheckBox *> all() const;
    void checkAll(bool v);

signals:

public slots:
};

#endif // WCHECKBOXGROUP_H
