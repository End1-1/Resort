#include "dlgselector.h"
#include "ui_dlgselector.h"
#include "cacheinstance.h"

DlgSelector::DlgSelector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgSelector)
{
    ui->setupUi(this);
    fMultiCheck = false;
}

DlgSelector::~DlgSelector()
{
    delete ui;
}

void DlgSelector::configure(const QString &title, const QList<int> &columnsWidths, const QStringList &columnTitles)
{
    setWindowTitle(title);
    ui->tblData->setColumnCount(columnsWidths.count() + 1);
    ui->tblData->setColumnWidth(0, 25);
    for (int i = 0; i < columnsWidths.count(); i++) {
        ui->tblData->setColumnWidth(i + 1, columnsWidths.at(i));
    }
    QStringList header = columnTitles;
    header.insert(0, "");
    ui->tblData->setHorizontalHeaderLabels(header);
}

void DlgSelector::setData(QMap<QString, QList<QVariant> > &data)
{
    ui->tblData->clear();
    ui->tblData->setRowCount(data.count());
    QMap<QString, QList<QVariant> >::iterator it = data.begin();
    int row = 0;
    while (it != data.end()) {
        for (int j = 0, colCount = ui->tblData->columnCount(); j < colCount; j++) {
            C5TableWidgetItem *item = new C5TableWidgetItem();
            if (j == 0) {
                item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
                item->setCheckState(Qt::Unchecked);
            } else {
                item->setData(Qt::EditRole, it.value().at(j - 1));
            }
            ui->tblData->setItem(row, j, item);
        }
        row++;
        it++;
    }
}

int DlgSelector::exec(QStringList &codes, QStringList &names)
{
    for (int i = 0, count = ui->tblData->rowCount(); i < count; i++) {
        ui->tblData->setItemChecked(i, 0, false);
    }
    if (!fMultiCheck) {
        ui->tblData->setColumnWidth(0, 0);
    }
    filter("");
    ui->lineEdit->setFocus();
    int result = QDialog::exec();
    if (result == QDialog::Accepted) {
        for (int i = 0, count = ui->tblData->rowCount(); i < count; i++) {
            if (ui->tblData->itemChecked(i, 0)) {
                codes << ui->tblData->item(i, 1)->data(Qt::EditRole).toString();
                names << ui->tblData->item(i, 2)->data(Qt::EditRole).toString();
            }
        }
    }
    ui->lineEdit->clear();
    fCodeFilter.clear();
    fFieldFilter.clear();
    fExcludeCodeFilter.clear();
    return result;
}

void DlgSelector::filter(const QString &arg1)
{
    for (int i = 0, rowCount = ui->tblData->rowCount(); i < rowCount; i++) {
        bool hide = true;
        for (int j = 1, colCount = ui->tblData->columnCount(); j < colCount; j++) {
            QString v = ui->tblData->item(i, j)->data(Qt::EditRole).toString();
            if (j == 1) {
                if(fCodeFilter.count() > 0) {
                    bool codeFound = false;
                    foreach (QString s, fCodeFilter) {
                        if (s == v) {
                            codeFound = true;
                            break;
                        }
                    }
                    if (codeFound) {

                    } else {
                        goto here;
                    }
                }
                if (fExcludeCodeFilter.count()) {
                    foreach (QString s, fExcludeCodeFilter) {
                        if (s == v) {
                            goto here;
                        }
                    }
                }
            }
            for (QMap<int, QStringList>::const_iterator it = fFieldFilter.begin(); it != fFieldFilter.end(); it++) {
                QString v1 = ui->tblData->item(i, it.key() + 1)->data(Qt::EditRole).toString();
                bool codeFound = false;
                foreach (QString s, it.value()) {
                    if (s == v1) {
                        codeFound = true;
                        break;
                    }
                }
                if (codeFound) {

                } else {
                    goto here;
                }
            }
            hide = !v.contains(arg1, Qt::CaseInsensitive);
            if (!hide) {
                if (fCommonFilter.count() > 0) {
                    hide = true;
                    foreach (QString s, fCommonFilter) {
                        if (v.contains(s, Qt::CaseInsensitive)) {
                            hide = false;
                            goto here;
                        }
                    }
                }
                if (!hide) {
                    break;
                }
            }
        }
        here:
        ui->tblData->setRowHidden(i, hide);
    }
}

void DlgSelector::on_tblData_doubleClicked(const QModelIndex &index)
{
    if (!fMultiCheck) {
        for (int i = 0, count = ui->tblData->rowCount(); i < count; i++) {
            ui->tblData->setItemChecked(i, 0, false);
        }
    }
    ui->tblData->setItemChecked(index.row(), 0, !ui->tblData->itemChecked(index.row(), 0));
    if (!fMultiCheck) {
        ui->tblData->setItemChecked(index.row(), 0, true);
        accept();
    }
}

void DlgSelector::on_btnCacnel_clicked()
{
    reject();
}

void DlgSelector::on_btnOK_clicked()
{
    if (fMultiCheck) {
        for (int i = 0; i < ui->tblData->rowCount(); i++) {
            if (ui->tblData->itemChecked(i, 0)) {
                accept();
                return;
            }
        }
    } else {
        QModelIndexList ml = ui->tblData->selectionModel()->selectedRows();
        if (ml.count() > 0) {
            on_tblData_doubleClicked(ml.at(0));
        }
    }
}

void DlgSelector::on_lineEdit_textEdited(const QString &arg1)
{
    filter(arg1);
}

void DlgSelector::on_btnRefresh_clicked()
{
    if (fCacheInstance) {
        fCacheInstance->load();
        setData(fCacheInstance->fRows);
        filter(ui->lineEdit->text());
    }
}

void DlgSelector::on_tblData_clicked(const QModelIndex &index)
{
    if (fMultiCheck) {
        ui->tblData->setItemChecked(index.row(), 0, !ui->tblData->itemChecked(index.row(), 0));
    }
}
