#ifndef DLGNOTES_H
#define DLGNOTES_H

#include "roweditordialog.h"

namespace Ui {
class DlgNotes;
}

class DlgNotes : public RowEditorDialog
{
    Q_OBJECT

public:
    explicit DlgNotes(QList<QVariant> &values, QWidget *parent = 0);
    ~DlgNotes();
    virtual void setValues();
    void setScheduleVisible(bool value = true);

private slots:
    void on_buttonBox_accepted();
    void on_btnSchedule_clicked();
    void on_btnDissmiss_clicked();
    void on_buttonBox_rejected();

private:
    Ui::DlgNotes *ui;
};

#endif // DLGNOTES_H
