#ifndef DLGOPTIONS_H
#define DLGOPTIONS_H

#include "basedialog.h"

namespace Ui {
class DlgOptions;
}

class DlgOptions : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgOptions(QWidget *parent = nullptr);
    ~DlgOptions();
    static void openWindow();

private:
    Ui::DlgOptions *ui;
};

#endif // DLGOPTIONS_H
