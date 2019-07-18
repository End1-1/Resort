#ifndef WHOMEPAGE_H
#define WHOMEPAGE_H

#include <QWidget>

namespace Ui {
class WHomePage;
}

class WHomePage : public QWidget
{
    Q_OBJECT

public:
    explicit WHomePage(QWidget *parent = nullptr);
    ~WHomePage();

private:
    Ui::WHomePage *ui;
};

#endif // WHOMEPAGE_H
