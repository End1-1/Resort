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
    void on_btnHelp_clicked();

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
    void roomArrangementByAge(QList<QList<QVariant> > &rows, const QString &month, QStringList &titles);
    void nationality(QList<QList<QVariant> > &rows, const QString &month);
    void nationalityYearly(QList<QList<QVariant> > &rows, const QString &month);
    void cardex(QList<QList<QVariant> > &rows, const QString &month);
    void marketsigment(QList<QList<QVariant> > &rows, const QString &month);
    void cardexCategory(QList<QList<QVariant> >&rows, const QString &month, QList<int> &widths, QStringList &titles, QList<int> &sumCols);
};

#endif // WREPORTSSETOLD_H
