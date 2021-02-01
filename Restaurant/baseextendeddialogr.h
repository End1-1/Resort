#ifndef BASEEXTENDEDDIALOGR_H
#define BASEEXTENDEDDIALOGR_H

#include "basedialog.h"
#include "utils.h"

class BaseExtendedDialogR : public BaseDialog {
    Q_OBJECT
public:
    BaseExtendedDialogR(QWidget *parent = nullptr);
protected:
};

extern BaseDialog *fParent;

#endif // BASEEXTENDEDDIALOGR_H
