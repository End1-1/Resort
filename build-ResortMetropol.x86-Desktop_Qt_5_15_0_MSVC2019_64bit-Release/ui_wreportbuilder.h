/********************************************************************************
** Form generated from reading UI file 'wreportbuilder.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WREPORTBUILDER_H
#define UI_WREPORTBUILDER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <ecomboboxcompleter.h>
#include <eqcombobox.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_WReportBuilder
{
public:
    QGridLayout *gridLayout_2;
    QListWidget *lwNames;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_4;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QListWidget *lwCols;
    QLabel *label_10;
    QPushButton *btnExtractCols;
    QPushButton *btnAddFilter_2;
    QLineEdit *leSum;
    QPushButton *btnRemoveFilter_2;
    QLabel *label_15;
    QLineEdit *leSubtotals;
    QWidget *widget_5;
    QGridLayout *gridLayout;
    EQLineEdit *leColTitle;
    QLabel *label_5;
    EQLineEdit *leColWidth;
    EQLineEdit *leColField;
    QSpacerItem *verticalSpacer;
    QLabel *label_6;
    QLabel *label_4;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_9;
    QGridLayout *gridLayout_6;
    QListWidget *lwFilters;
    QLabel *label_14;
    QPushButton *btnAddFilter;
    QPushButton *btnRemoveFilter;
    QWidget *widget_10;
    QGridLayout *gridLayout_7;
    QLabel *ddfas;
    QSpacerItem *verticalSpacer_2;
    EQLineEdit *leFilterField;
    QLabel *label_17;
    EQComboBox *cbFilterType;
    QLabel *label_16;
    EQLineEdit *leFilterMark;
    QLabel *label_13;
    QLabel *lbMark;
    EQLineEdit *leFilterTitle;
    EQLineEdit *leFilterBuild;
    EQLineEdit *leFilterExprEmpty;
    QLabel *label_11;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QTextEdit *teSQL;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_9;
    EQLineEdit *leCode;
    QLabel *label_8;
    EQLineEdit *leName;
    QLabel *label;
    EComboBoxCompleter *cbMenu;
    QPushButton *btnEditGrup;
    QLabel *label_12;
    QComboBox *cbMainMenu;
    QLabel *label_2;
    EQLineEdit *leGroupAccess;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnNew;
    QPushButton *btnSave;
    QPushButton *btnRemove;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *WReportBuilder)
    {
        if (WReportBuilder->objectName().isEmpty())
            WReportBuilder->setObjectName(QString::fromUtf8("WReportBuilder"));
        WReportBuilder->resize(824, 611);
        gridLayout_2 = new QGridLayout(WReportBuilder);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lwNames = new QListWidget(WReportBuilder);
        lwNames->setObjectName(QString::fromUtf8("lwNames"));
        lwNames->setMaximumSize(QSize(200, 16777215));
        lwNames->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_2->addWidget(lwNames, 1, 0, 1, 1);

        widget = new QWidget(WReportBuilder);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(-1, -1, -1, 0);
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout_3 = new QGridLayout(widget_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        lwCols = new QListWidget(widget_4);
        lwCols->setObjectName(QString::fromUtf8("lwCols"));
        lwCols->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lwCols->setDragEnabled(true);
        lwCols->setDragDropMode(QAbstractItemView::InternalMove);
        lwCols->setDefaultDropAction(Qt::MoveAction);

        gridLayout_3->addWidget(lwCols, 2, 0, 1, 6);

        label_10 = new QLabel(widget_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 4, 0, 1, 1);

        btnExtractCols = new QPushButton(widget_4);
        btnExtractCols->setObjectName(QString::fromUtf8("btnExtractCols"));
        btnExtractCols->setMaximumSize(QSize(25, 25));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/zoom-in.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExtractCols->setIcon(icon);

        gridLayout_3->addWidget(btnExtractCols, 0, 5, 1, 1);

        btnAddFilter_2 = new QPushButton(widget_4);
        btnAddFilter_2->setObjectName(QString::fromUtf8("btnAddFilter_2"));
        btnAddFilter_2->setMaximumSize(QSize(25, 25));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddFilter_2->setIcon(icon1);

        gridLayout_3->addWidget(btnAddFilter_2, 0, 4, 1, 1);

        leSum = new QLineEdit(widget_4);
        leSum->setObjectName(QString::fromUtf8("leSum"));

        gridLayout_3->addWidget(leSum, 4, 1, 1, 5);

        btnRemoveFilter_2 = new QPushButton(widget_4);
        btnRemoveFilter_2->setObjectName(QString::fromUtf8("btnRemoveFilter_2"));
        btnRemoveFilter_2->setMaximumSize(QSize(25, 25));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/garbage.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRemoveFilter_2->setIcon(icon2);

        gridLayout_3->addWidget(btnRemoveFilter_2, 0, 3, 1, 1);

        label_15 = new QLabel(widget_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 3, 0, 1, 1);

        leSubtotals = new QLineEdit(widget_4);
        leSubtotals->setObjectName(QString::fromUtf8("leSubtotals"));

        gridLayout_3->addWidget(leSubtotals, 3, 1, 1, 5);


        horizontalLayout_3->addWidget(widget_4);

        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        gridLayout = new QGridLayout(widget_5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        leColTitle = new EQLineEdit(widget_5);
        leColTitle->setObjectName(QString::fromUtf8("leColTitle"));
        leColTitle->setProperty("AlwaysUpper", QVariant(false));

        gridLayout->addWidget(leColTitle, 1, 1, 1, 1);

        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        leColWidth = new EQLineEdit(widget_5);
        leColWidth->setObjectName(QString::fromUtf8("leColWidth"));
        leColWidth->setProperty("AlwaysUpper", QVariant(false));

        gridLayout->addWidget(leColWidth, 2, 1, 1, 1);

        leColField = new EQLineEdit(widget_5);
        leColField->setObjectName(QString::fromUtf8("leColField"));
        leColField->setReadOnly(false);
        leColField->setProperty("AlwaysUpper", QVariant(false));

        gridLayout->addWidget(leColField, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 85, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        label_6 = new QLabel(widget_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(widget_5);


        gridLayout_4->addWidget(widget_3, 2, 0, 1, 1);

        widget_8 = new QWidget(widget);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_4 = new QHBoxLayout(widget_8);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_9 = new QWidget(widget_8);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        gridLayout_6 = new QGridLayout(widget_9);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        lwFilters = new QListWidget(widget_9);
        lwFilters->setObjectName(QString::fromUtf8("lwFilters"));
        lwFilters->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lwFilters->setDragEnabled(true);
        lwFilters->setDragDropMode(QAbstractItemView::InternalMove);
        lwFilters->setDefaultDropAction(Qt::MoveAction);

        gridLayout_6->addWidget(lwFilters, 2, 0, 1, 3);

        label_14 = new QLabel(widget_9);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_6->addWidget(label_14, 0, 0, 1, 1);

        btnAddFilter = new QPushButton(widget_9);
        btnAddFilter->setObjectName(QString::fromUtf8("btnAddFilter"));
        btnAddFilter->setMaximumSize(QSize(25, 25));
        btnAddFilter->setIcon(icon1);

        gridLayout_6->addWidget(btnAddFilter, 0, 2, 1, 1);

        btnRemoveFilter = new QPushButton(widget_9);
        btnRemoveFilter->setObjectName(QString::fromUtf8("btnRemoveFilter"));
        btnRemoveFilter->setMaximumSize(QSize(25, 25));
        btnRemoveFilter->setIcon(icon2);

        gridLayout_6->addWidget(btnRemoveFilter, 0, 1, 1, 1);


        horizontalLayout_4->addWidget(widget_9);

        widget_10 = new QWidget(widget_8);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        gridLayout_7 = new QGridLayout(widget_10);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        ddfas = new QLabel(widget_10);
        ddfas->setObjectName(QString::fromUtf8("ddfas"));

        gridLayout_7->addWidget(ddfas, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 85, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_2, 6, 1, 1, 1);

        leFilterField = new EQLineEdit(widget_10);
        leFilterField->setObjectName(QString::fromUtf8("leFilterField"));
        leFilterField->setReadOnly(false);
        leFilterField->setProperty("AlwaysUpper", QVariant(false));

        gridLayout_7->addWidget(leFilterField, 0, 1, 1, 1);

        label_17 = new QLabel(widget_10);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_7->addWidget(label_17, 0, 0, 1, 1);

        cbFilterType = new EQComboBox(widget_10);
        cbFilterType->addItem(QString());
        cbFilterType->addItem(QString());
        cbFilterType->addItem(QString());
        cbFilterType->addItem(QString());
        cbFilterType->addItem(QString());
        cbFilterType->setObjectName(QString::fromUtf8("cbFilterType"));

        gridLayout_7->addWidget(cbFilterType, 2, 1, 1, 1);

        label_16 = new QLabel(widget_10);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_7->addWidget(label_16, 1, 0, 1, 1);

        leFilterMark = new EQLineEdit(widget_10);
        leFilterMark->setObjectName(QString::fromUtf8("leFilterMark"));
        leFilterMark->setProperty("AlwaysUpper", QVariant(false));

        gridLayout_7->addWidget(leFilterMark, 4, 1, 1, 1);

        label_13 = new QLabel(widget_10);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_7->addWidget(label_13, 2, 0, 1, 1);

        lbMark = new QLabel(widget_10);
        lbMark->setObjectName(QString::fromUtf8("lbMark"));

        gridLayout_7->addWidget(lbMark, 4, 0, 1, 1);

        leFilterTitle = new EQLineEdit(widget_10);
        leFilterTitle->setObjectName(QString::fromUtf8("leFilterTitle"));
        leFilterTitle->setProperty("AlwaysUpper", QVariant(false));

        gridLayout_7->addWidget(leFilterTitle, 1, 1, 1, 1);

        leFilterBuild = new EQLineEdit(widget_10);
        leFilterBuild->setObjectName(QString::fromUtf8("leFilterBuild"));
        leFilterBuild->setProperty("AlwaysUpper", QVariant(false));

        gridLayout_7->addWidget(leFilterBuild, 3, 1, 1, 1);

        leFilterExprEmpty = new EQLineEdit(widget_10);
        leFilterExprEmpty->setObjectName(QString::fromUtf8("leFilterExprEmpty"));

        gridLayout_7->addWidget(leFilterExprEmpty, 5, 1, 1, 1);

        label_11 = new QLabel(widget_10);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_7->addWidget(label_11, 5, 0, 1, 1);


        horizontalLayout_4->addWidget(widget_10);


        gridLayout_4->addWidget(widget_8, 2, 1, 1, 1);

        widget_6 = new QWidget(widget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout_2 = new QVBoxLayout(widget_6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget_6);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        teSQL = new QTextEdit(widget_6);
        teSQL->setObjectName(QString::fromUtf8("teSQL"));

        verticalLayout_2->addWidget(teSQL);


        gridLayout_4->addWidget(widget_6, 1, 0, 1, 2);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(widget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_2->addWidget(label_9);

        leCode = new EQLineEdit(widget_2);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setMaximumSize(QSize(50, 16777215));
        leCode->setReadOnly(true);

        horizontalLayout_2->addWidget(leCode);

        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_2->addWidget(label_8);

        leName = new EQLineEdit(widget_2);
        leName->setObjectName(QString::fromUtf8("leName"));
        leName->setProperty("AlwaysUpper", QVariant(false));

        horizontalLayout_2->addWidget(leName);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        cbMenu = new EComboBoxCompleter(widget_2);
        cbMenu->setObjectName(QString::fromUtf8("cbMenu"));

        horizontalLayout_2->addWidget(cbMenu);

        btnEditGrup = new QPushButton(widget_2);
        btnEditGrup->setObjectName(QString::fromUtf8("btnEditGrup"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/file.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnEditGrup->setIcon(icon3);

        horizontalLayout_2->addWidget(btnEditGrup);

        label_12 = new QLabel(widget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_2->addWidget(label_12);

        cbMainMenu = new QComboBox(widget_2);
        cbMainMenu->addItem(QString());
        cbMainMenu->addItem(QString());
        cbMainMenu->addItem(QString());
        cbMainMenu->addItem(QString());
        cbMainMenu->addItem(QString());
        cbMainMenu->addItem(QString());
        cbMainMenu->addItem(QString());
        cbMainMenu->addItem(QString());
        cbMainMenu->addItem(QString());
        cbMainMenu->setObjectName(QString::fromUtf8("cbMainMenu"));

        horizontalLayout_2->addWidget(cbMainMenu);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        leGroupAccess = new EQLineEdit(widget_2);
        leGroupAccess->setObjectName(QString::fromUtf8("leGroupAccess"));

        horizontalLayout_2->addWidget(leGroupAccess);

        horizontalSpacer = new QSpacerItem(81, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout_4->addWidget(widget_2, 0, 0, 1, 2);


        gridLayout_2->addWidget(widget, 1, 1, 1, 1);

        widget_7 = new QWidget(WReportBuilder);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setMinimumSize(QSize(0, 0));
        horizontalLayout = new QHBoxLayout(widget_7);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnNew = new QPushButton(widget_7);
        btnNew->setObjectName(QString::fromUtf8("btnNew"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/revive.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNew->setIcon(icon4);

        horizontalLayout->addWidget(btnNew);

        btnSave = new QPushButton(widget_7);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSave->setIcon(icon5);

        horizontalLayout->addWidget(btnSave);

        btnRemove = new QPushButton(widget_7);
        btnRemove->setObjectName(QString::fromUtf8("btnRemove"));
        btnRemove->setIcon(icon2);

        horizontalLayout->addWidget(btnRemove);

        horizontalSpacer_2 = new QSpacerItem(542, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_2->addWidget(widget_7, 0, 0, 1, 2);

        QWidget::setTabOrder(leColField, leColTitle);
        QWidget::setTabOrder(leColTitle, leColWidth);
        QWidget::setTabOrder(leColWidth, leFilterField);
        QWidget::setTabOrder(leFilterField, leFilterTitle);
        QWidget::setTabOrder(leFilterTitle, cbFilterType);
        QWidget::setTabOrder(cbFilterType, leFilterBuild);
        QWidget::setTabOrder(leFilterBuild, leFilterMark);
        QWidget::setTabOrder(leFilterMark, leCode);
        QWidget::setTabOrder(leCode, leName);
        QWidget::setTabOrder(leName, cbMenu);
        QWidget::setTabOrder(cbMenu, btnEditGrup);
        QWidget::setTabOrder(btnEditGrup, leGroupAccess);
        QWidget::setTabOrder(leGroupAccess, btnAddFilter_2);
        QWidget::setTabOrder(btnAddFilter_2, btnRemoveFilter_2);
        QWidget::setTabOrder(btnRemoveFilter_2, btnNew);
        QWidget::setTabOrder(btnNew, lwNames);
        QWidget::setTabOrder(lwNames, btnSave);
        QWidget::setTabOrder(btnSave, lwFilters);
        QWidget::setTabOrder(lwFilters, btnAddFilter);
        QWidget::setTabOrder(btnAddFilter, btnRemoveFilter);
        QWidget::setTabOrder(btnRemoveFilter, btnRemove);
        QWidget::setTabOrder(btnRemove, btnExtractCols);
        QWidget::setTabOrder(btnExtractCols, lwCols);
        QWidget::setTabOrder(lwCols, teSQL);
        QWidget::setTabOrder(teSQL, leSum);

        retranslateUi(WReportBuilder);

        QMetaObject::connectSlotsByName(WReportBuilder);
    } // setupUi

    void retranslateUi(QWidget *WReportBuilder)
    {
        WReportBuilder->setWindowTitle(QCoreApplication::translate("WReportBuilder", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("WReportBuilder", "Columns", nullptr));
        label_10->setText(QCoreApplication::translate("WReportBuilder", "Sum for", nullptr));
        btnExtractCols->setText(QString());
        btnAddFilter_2->setText(QString());
        btnRemoveFilter_2->setText(QString());
        label_15->setText(QCoreApplication::translate("WReportBuilder", "Subtotals", nullptr));
        label_5->setText(QCoreApplication::translate("WReportBuilder", "Title", nullptr));
        leColWidth->setInputMask(QCoreApplication::translate("WReportBuilder", "###", nullptr));
        label_6->setText(QCoreApplication::translate("WReportBuilder", "Width", nullptr));
        label_4->setText(QCoreApplication::translate("WReportBuilder", "Field", nullptr));
        label_14->setText(QCoreApplication::translate("WReportBuilder", "Filters", nullptr));
        btnAddFilter->setText(QString());
        btnRemoveFilter->setText(QString());
        ddfas->setText(QCoreApplication::translate("WReportBuilder", "Build", nullptr));
        label_17->setText(QCoreApplication::translate("WReportBuilder", "Field", nullptr));
        cbFilterType->setItemText(0, QCoreApplication::translate("WReportBuilder", "COMBOBOX", nullptr));
        cbFilterType->setItemText(1, QCoreApplication::translate("WReportBuilder", "INTEGER", nullptr));
        cbFilterType->setItemText(2, QCoreApplication::translate("WReportBuilder", "STRING", nullptr));
        cbFilterType->setItemText(3, QCoreApplication::translate("WReportBuilder", "DATE", nullptr));
        cbFilterType->setItemText(4, QCoreApplication::translate("WReportBuilder", "COMBO MONTH", nullptr));

        label_16->setText(QCoreApplication::translate("WReportBuilder", "Title", nullptr));
        label_13->setText(QCoreApplication::translate("WReportBuilder", "Data type", nullptr));
        lbMark->setText(QCoreApplication::translate("WReportBuilder", "Filter values\n"
"SQL string", nullptr));
        label_11->setText(QCoreApplication::translate("WReportBuilder", "Expresion\n"
"if empty", nullptr));
        label_7->setText(QCoreApplication::translate("WReportBuilder", "Query", nullptr));
        label_9->setText(QCoreApplication::translate("WReportBuilder", "Code", nullptr));
        label_8->setText(QCoreApplication::translate("WReportBuilder", "Name", nullptr));
        label->setText(QCoreApplication::translate("WReportBuilder", "Group", nullptr));
        cbMenu->setProperty("SQL", QVariant(QCoreApplication::translate("WReportBuilder", "select f_id, f_name from serv_reports_group", nullptr)));
        btnEditGrup->setText(QString());
        label_12->setText(QCoreApplication::translate("WReportBuilder", "Menu", nullptr));
        cbMainMenu->setItemText(0, QCoreApplication::translate("WReportBuilder", "None", nullptr));
        cbMainMenu->setItemText(1, QCoreApplication::translate("WReportBuilder", "Reservation", nullptr));
        cbMainMenu->setItemText(2, QCoreApplication::translate("WReportBuilder", "Reception", nullptr));
        cbMainMenu->setItemText(3, QCoreApplication::translate("WReportBuilder", "Cashier", nullptr));
        cbMainMenu->setItemText(4, QCoreApplication::translate("WReportBuilder", "City Ledger", nullptr));
        cbMainMenu->setItemText(5, QCoreApplication::translate("WReportBuilder", "Bookkeeping", nullptr));
        cbMainMenu->setItemText(6, QCoreApplication::translate("WReportBuilder", "Restaurant", nullptr));
        cbMainMenu->setItemText(7, QCoreApplication::translate("WReportBuilder", "Analytics", nullptr));
        cbMainMenu->setItemText(8, QCoreApplication::translate("WReportBuilder", "Other Reports", nullptr));

        label_2->setText(QCoreApplication::translate("WReportBuilder", "Access", nullptr));
        btnNew->setText(QCoreApplication::translate("WReportBuilder", "New", nullptr));
        btnSave->setText(QCoreApplication::translate("WReportBuilder", "Save", nullptr));
        btnRemove->setText(QCoreApplication::translate("WReportBuilder", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WReportBuilder: public Ui_WReportBuilder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WREPORTBUILDER_H
