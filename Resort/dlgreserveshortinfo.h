#ifndef DLGRESERVESHORTINFO_H
#define DLGRESERVESHORTINFO_H

#include "basedialog.h"
#include "trackcontrol.h"

namespace Ui {
class DlgReserveShortInfo;
}

class DlgReserveShortInfo : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgReserveShortInfo(QWidget *parent = nullptr);
    ~DlgReserveShortInfo();
    static void loadShortInfo(const QString &id);
private slots:
    void on_btnCancel_clicked();

    void on_btnOK_clicked();

private:
    Ui::DlgReserveShortInfo *ui;
    bool loadInfo();
    TrackControl *fTrackControl;
};

#endif // DLGRESERVESHORTINFO_H
