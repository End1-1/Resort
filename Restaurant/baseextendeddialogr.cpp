#include "baseextendeddialogr.h"
#include "cacherights.h"
#include "cacheusers.h"
#include "rlogin.h"
#include "user.h"

BaseDialog *fParent = 0;

BaseExtendedDialogR::BaseExtendedDialogR(QWidget *parent) :
    BaseDialog(parent, Qt::FramelessWindowHint)
{
}
