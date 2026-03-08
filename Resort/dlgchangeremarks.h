#ifndef DLGCHANGEREMARKS_H
#define DLGCHANGEREMARKS_H

#include <QDialog>

namespace Ui {
class DlgChangeRemarks;
}

class DlgChangeRemarks : public QDialog
{
    Q_OBJECT

public:
    explicit DlgChangeRemarks(const QString &remarks, QWidget *parent = nullptr);

    ~DlgChangeRemarks();

    QString result;

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::DlgChangeRemarks *ui;
};

#endif // DLGCHANGEREMARKS_H
