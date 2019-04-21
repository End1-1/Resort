#ifndef EFILTERLINEEDIT_H
#define EFILTERLINEEDIT_H

#include <QWidget>

namespace Ui {
class EFilterLineEdit;
}

class EFilterLineEdit : public QWidget
{
    Q_OBJECT

public:
    explicit EFilterLineEdit(QWidget *parent = nullptr);
    ~EFilterLineEdit();

private:
    Ui::EFilterLineEdit *ui;
};

#endif // EFILTERLINEEDIT_H
