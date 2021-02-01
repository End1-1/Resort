#ifndef RDISHCOMMENT_H
#define RDISHCOMMENT_H

#include "baseextendeddialogr.h"

namespace Ui {
class RDishComment;
}

class RDishComment : public BaseExtendedDialogR
{
    Q_OBJECT

public:
    explicit RDishComment(QWidget *parent = 0);
    ~RDishComment();
    static bool getComment(QString &text, QWidget *parent);
private:
    Ui::RDishComment *ui;
private slots:
    void leTextChanged(const QString &text);
    void on_leText_textChanged(const QString &arg1);
};

#endif // RDISHCOMMENT_H
