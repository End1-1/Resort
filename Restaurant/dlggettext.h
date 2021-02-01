#ifndef DLGGETTEXT_H
#define DLGGETTEXT_H

#include "baseextendeddialogr.h"

namespace Ui {
class DlgGetText;
}

class DlgGetText : public BaseExtendedDialogR
{
    Q_OBJECT

public:
    explicit DlgGetText(QWidget *parent = 0);
    ~DlgGetText();
    static bool getText(QString &out, const QString &prefix = "");
private:
    Ui::DlgGetText *ui;
private slots:
    void textChanged(const QString &text);
};

#endif // DLGGETTEXT_H
