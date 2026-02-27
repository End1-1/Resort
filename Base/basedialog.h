#ifndef BASEDIALOG_H
#define BASEDIALOG_H

#include "base.h"
#include "cacheone.h"
#include "cacherights.h"
#include <QDialog>
#include <QKeyEvent>

class BaseDialog : public QDialog, public Base
{
public:
    BaseDialog(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::Widget);

protected:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void returnPressed();
    virtual void escapePressed();
};

#endif // BASEDIALOG_H
