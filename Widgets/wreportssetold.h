#ifndef WREPORTSSETOLD_H
#define WREPORTSSETOLD_H

#include "basewidget.h"
#include <QButtonGroup>

class WReportGrid;

namespace Ui {
class WReportsSetOld;
}

class WReportsSetOld : public BaseWidget
{
    Q_OBJECT

public:
    explicit WReportsSetOld(QWidget *parent = nullptr);
    ~WReportsSetOld();
    virtual void setup();
    virtual QString title();

private slots:
    void rbClicked();
    void on_btnGo_clicked();    
    void on_chYear_clicked(bool checked);

private:
    Ui::WReportsSetOld *ui;
    QList<QWidget*> fFilterWidgets;
    QMap<QWidget*, QString> fFilterFields;
    QMap<QWidget*, QString> fFilterBuilds;
    QMap<QWidget*, QString> fFilterDefExpr;
    QButtonGroup fBtnGroup;
    QButtonGroup fBtnMonth;
    void category(QList<QList<QVariant> > &rows, const QString &month);
    void occupancy(QList<QList<QVariant> > &rows, const QString &month);
    void roomArrangement(QList<QList<QVariant> > &rows, const QString &month);
    void nationality(QList<QList<QVariant> > &rows, const QString &month);
    void nationalityYearly(QList<QList<QVariant> > &rows, const QString &month);
};

#endif // WREPORTSSETOLD_H
