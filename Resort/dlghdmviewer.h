#ifndef DLGHDMVIEWER_H
#define DLGHDMVIEWER_H

#include <QDialog>

namespace Ui {
class DlgHDMViewer;
}

class DlgHDMViewer : public QDialog
{
    Q_OBJECT

public:
    explicit DlgHDMViewer(const QString &fiscal, const QString &jsonText, QWidget *parent = nullptr);
    ~DlgHDMViewer();

private:
    Ui::DlgHDMViewer *ui;
};

#endif // DLGHDMVIEWER_H
