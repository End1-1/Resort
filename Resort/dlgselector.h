#ifndef DLGSELECTOR_H
#define DLGSELECTOR_H

#include <QDialog>
#include <QMap>

class CacheInstance;

namespace Ui {
class DlgSelector;
}

class DlgSelector : public QDialog
{
    Q_OBJECT

public:
    explicit DlgSelector(QWidget *parent = nullptr);
    ~DlgSelector();
    void configure(const QString &title, const QList<int> &columnsWidths, const QStringList &columnTitles);
    void setData(QMap<QString, QList<QVariant> > &data);
    QStringList fCommonFilter;
    QStringList fCodeFilter;
    QStringList fExcludeCodeFilter;
    QMap<int, QStringList> fFieldFilter;
    virtual int exec(QStringList &codes, QStringList &names);
    bool fMultiCheck;
    void filter(const QString &arg1);
    CacheInstance *fCacheInstance;

private slots:
    void on_tblData_doubleClicked(const QModelIndex &index);
    void on_btnCacnel_clicked();
    void on_btnOK_clicked();
    void on_lineEdit_textEdited(const QString &arg1);
    void on_btnRefresh_clicked();    
    void on_tblData_clicked(const QModelIndex &index);

private:
    Ui::DlgSelector *ui;
};

#endif // DLGSELECTOR_H
