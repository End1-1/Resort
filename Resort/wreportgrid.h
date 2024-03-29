#ifndef WREPORTGRID_H
#define WREPORTGRID_H

#include "basewidget.h"
#include "tablemodel.h"
#include "roweditordialog.h"
#include "wfilterbase.h"
#include "pprintpreview.h"
#include "rgdoubleclickdelegate.h"
#include <QHeaderView>

#define tr_col(lang, width) (def_lang == lang ? width : 0)

class FTrackChanges;
class FCityLedgerBalance;
class FCategoryToSell;

namespace Ui {
class WReportGrid;
}

typedef struct {
    QString fFontName;
    int fFontSize;
    bool fPrintOnly;
    bool fFontBold;
    bool fValid;
    int fRowHeight;
} Report;

class WReportGrid : public BaseWidget
{
    Q_OBJECT
public:
    friend class WFilterBase;
    friend class FTrackChanges;
    friend class FCityLedgerBalance;
    friend class FCategoryToSell;
    explicit WReportGrid(QWidget *parent = nullptr);
    ~WReportGrid();
    QToolButton *addToolBarButton(const QString &image, const QString &text, const char *slot, QObject *receiver = nullptr, int pos = 1000);
    int fillRowValuesOut(QList<QVariant> &out);
    void setTblTotalData(const QList<int> &columns, const QList<double> &values);
    void setTblNoTotalData();
    void countToTotal(int col);
    virtual void setup();
    virtual void setupTabTextAndIcon(const QString &name, const QString &image);
    void addFilterWidget(WFilterBase *f);

    template<class T>
    void setStaticModel(const QString &sqlQuery, const QList<int> &widths, const QStringList &titles,
                        const QString &title, const QString &iconName) {
        fStaticQuery = sqlQuery;
        for (int i = 0; i < widths.count(); i++) {
            fModel->setColumn(widths.at(i), "", titles.at(i));
        }
        setupTabTextAndIcon(title, iconName);
        fFilter = new T(this);
        addFilterWidget(fFilter);
        fFilter->apply(this);
    }

    template<class T>
    void setQueryModel(const QList<int> &widhts, const QStringList &fields, const QStringList &titles,
                       const QMap<QString,bool> &includes, const QStringList &tables, const QStringList &joins,
                       const QStringList &joinConds, const QString &title, const QString &iconName) {
        fFieldsWidths = widhts;
        fFields = fields;
        fFieldTitles = titles;
        fIncludes = includes;
        fTables = tables;
        fJoins = joins;
        fJoinConds = joinConds;
        setupTabTextAndIcon(title, iconName);
        fFilter = new T(this);
        addFilterWidget(fFilter);
        fFilter->apply(this);
    }

    template<class T>
    void setQueryModel() {
        fFilter = new T(this);
        fFilter->setup();
        addFilterWidget(fFilter);
        fFilter->apply(this);
    }

    virtual void getModelData(QList<QList<QVariant> > &out);

    template<class T>
    T *fullSetup(const QList<int> widths, const QStringList &fields, const QStringList &titles,
                   const QString &title, const QString &icon, const QString &query, bool showNewBtn = true) {
        setupTabTextAndIcon(title, icon);
        for (int i = 0, count = widths.count(); i < count; i++) {
            fModel->setColumn(widths.at(i), fields.at(i), titles.at(i));
        }
        fStaticQuery = query;
        fModel->setSqlQuery(query);
        fModel->apply(this);
        T *t = 0;
        if (showNewBtn) {
            t = new T(fRowValues, this);
            fRowEditorDialog = t;
        }
        setBtnNewVisible(showNewBtn);
        return t;
    }
    void setHelp(const QString &helpFile);
    RowEditorDialog *fRowEditorDialog;
    QList<QVariant> fRowValues;
    TableModel *fModel;
    QTableView *fTableView;
    EQTableWidget *fTableTotal;
    QString fStaticQuery;
    WFilterBase *fFilter;
    RGDoubleClickDelegate *fRgDoubleClick;
    QList<int> fFieldsWidths;
    QStringList fFields;
    QStringList fFieldTitles;
    QStringList fTables;
    QStringList fJoins;
    QStringList fJoinConds;
    BaseWidget *fTitleWidget;
    QMap<QString,bool> fIncludes;
    QString fGridClassName;
    static QMap<QString, Report> fReportOptions;
    void connectHeaderResize();
    void disconnectHeaderResize();
    void dontResizeSave(bool v);
    void setBtnNewVisible(bool value = true);
    virtual QWidget *gridOptionWidget();

protected:
    QString fHelp;
    virtual void processValues(int row, bool isNew);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual bool event(QEvent *event);

private slots:
    void registerInReportBuilder(bool msg = true);
    void newSum(const QList<int> &columns, const QList<double> &values);
    void tblMainHeaderClicked(int index);
    void tblMainHeaderResized(int index, int oldSize, int newSize);
    void tblMainCustomeMenu(const QPoint &point);
    void tblMaingridCustomMenu(const QPoint &point);
    void actionCopyGrid(bool v);
    void actionFilterColumn(bool v);
    void rowCount(int count);
    void totalGridHScroll(int value);
    void tblMainGridHScroll(int value);
    void on_leQuickSearch_textChanged(const QString &arg1);
    void on_btnExcel_clicked();
    void on_tblMain_doubleClicked(const QModelIndex &index);
    void on_btnNew_clicked();
    virtual void on_btnRefresh_clicked();
    void on_tblMain_clicked(const QModelIndex &index);
    void on_btnClearQuickSearch_clicked();
    void on_btnPrint_clicked();
    void on_btnConfigGrid_clicked();
    void endApply();
    void on_btnHelp_clicked();
    void on_btnFirst_clicked();
    void on_btnBack_clicked();
    void on_btnNext_clicked();
    void on_btnLast_clicked();
    void on_btnZoomOut_clicked();
    void on_btnZoopIn_clicked();
    void on_cbZoom_currentIndexChanged(int index);
    void on_btnPrint2_clicked();

private:
    Ui::WReportGrid *ui;
    QMenu *fTableMenu;
    QMenu *fGridMenu;
    bool fSaveResizedColumn;
    void fillRowValues(int row);
    int fPageNumber;
    float fScaleFactor;
    QList<PPrintScene*> fPrintScene;
    void setPage();
    PPrintScene *addScene(int tmpl, PrintOrientation po);
    void setPrintOrientation(PrintOrientation po);
    void printOnPaper();
    bool fPrintOut;
    bool fPrintOutReady;

signals:
    void doubleClickOnRow(const QList<QVariant> &values);
    void clickOnRow(int row);
    void newBtn();
    void tblMainDoubleClick(const QModelIndex &);
};

#endif // WREPORTGRID_H
