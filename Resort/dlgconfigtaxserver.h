#ifndef DLGCONFIGTAXSERVER_H
#define DLGCONFIGTAXSERVER_H

#include <QDialog>

namespace Ui {
class DlgConfigTaxServer;
}

class TrackControl;

class DlgConfigTaxServer : public QDialog
{
    Q_OBJECT

public:
    explicit DlgConfigTaxServer(QWidget *parent = nullptr);
    ~DlgConfigTaxServer();
    static QString address();
    static quint16 port();
    static QString password();
    static bool remote();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::DlgConfigTaxServer *ui;
    TrackControl *fTrack;
};

#endif // DLGCONFIGTAXSERVER_H
