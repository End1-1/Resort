#include "basedialog.h"

BaseDialog::BaseDialog(QWidget *parent, Qt::WindowFlags flags) :
    QDialog(parent, flags),
    Base()
{

}

void BaseDialog::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Return || e->key() == Qt::Key_Enter) {
        returnPressed();
        return;
    } else if (e->key() == Qt::Key_Escape) {
        escapePressed();
        return;
    }
    QDialog::keyPressEvent(e);
}

void BaseDialog::returnPressed()
{
    focusNextChild();
}

void BaseDialog::escapePressed()
{

}
