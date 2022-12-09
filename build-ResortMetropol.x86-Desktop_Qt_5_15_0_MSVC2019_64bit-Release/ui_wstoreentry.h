/********************************************************************************
** Form generated from reading UI file 'wstoreentry.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WSTOREENTRY_H
#define UI_WSTOREENTRY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_WStoreEntry
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *btnSave;
    QToolButton *btnPrint;
    QToolButton *btnRemove;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    EDateEdit *deLastDate;
    QToolButton *btnCalculate;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    EQLineEdit *leDocNum;
    QLabel *label_2;
    EDateEdit *deDate;
    QLabel *label_3;
    EQLineEdit *leStore;
    EQLineEdit *leStoreName;
    QLabel *label_4;
    EQLineEdit *leAmount;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QSpacerItem *horizontalSpacer;
    EQTableWidget *tblData;

    void setupUi(QWidget *WStoreEntry)
    {
        if (WStoreEntry->objectName().isEmpty())
            WStoreEntry->setObjectName(QString::fromUtf8("WStoreEntry"));
        WStoreEntry->resize(838, 783);
        verticalLayout = new QVBoxLayout(WStoreEntry);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_3 = new QWidget(WStoreEntry);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnSave = new QToolButton(widget_3);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setMinimumSize(QSize(40, 40));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSave->setIcon(icon);
        btnSave->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(btnSave);

        btnPrint = new QToolButton(widget_3);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));
        btnPrint->setMinimumSize(QSize(40, 40));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrint->setIcon(icon1);
        btnPrint->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(btnPrint);

        btnRemove = new QToolButton(widget_3);
        btnRemove->setObjectName(QString::fromUtf8("btnRemove"));
        btnRemove->setMinimumSize(QSize(40, 40));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/garbage.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRemove->setIcon(icon2);
        btnRemove->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(btnRemove);

        horizontalSpacer_2 = new QSpacerItem(655, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        deLastDate = new EDateEdit(widget_3);
        deLastDate->setObjectName(QString::fromUtf8("deLastDate"));

        horizontalLayout_2->addWidget(deLastDate);

        btnCalculate = new QToolButton(widget_3);
        btnCalculate->setObjectName(QString::fromUtf8("btnCalculate"));
        btnCalculate->setMinimumSize(QSize(40, 40));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/calculator.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCalculate->setIcon(icon3);
        btnCalculate->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(btnCalculate);


        verticalLayout->addWidget(widget_3);

        widget = new QWidget(WStoreEntry);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leDocNum = new EQLineEdit(widget);
        leDocNum->setObjectName(QString::fromUtf8("leDocNum"));
        leDocNum->setEnabled(false);
        leDocNum->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(leDocNum, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        deDate = new EDateEdit(widget);
        deDate->setObjectName(QString::fromUtf8("deDate"));
        deDate->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(deDate, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        leStore = new EQLineEdit(widget);
        leStore->setObjectName(QString::fromUtf8("leStore"));
        leStore->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(leStore, 2, 1, 1, 1);

        leStoreName = new EQLineEdit(widget);
        leStoreName->setObjectName(QString::fromUtf8("leStoreName"));
        leStoreName->setEnabled(false);

        gridLayout->addWidget(leStoreName, 2, 2, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        leAmount = new EQLineEdit(widget);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));
        leAmount->setEnabled(false);
        leAmount->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(leAmount, 3, 1, 1, 1);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(WStoreEntry);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolButton = new QToolButton(widget_2);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon4);

        horizontalLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(widget_2);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setIcon(icon2);

        horizontalLayout->addWidget(toolButton_2);

        horizontalSpacer = new QSpacerItem(655, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget_2);

        tblData = new EQTableWidget(WStoreEntry);
        if (tblData->columnCount() < 6)
            tblData->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tblData->setObjectName(QString::fromUtf8("tblData"));
        tblData->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblData->setSelectionMode(QAbstractItemView::SingleSelection);
        tblData->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(tblData);


        retranslateUi(WStoreEntry);

        QMetaObject::connectSlotsByName(WStoreEntry);
    } // setupUi

    void retranslateUi(QWidget *WStoreEntry)
    {
        WStoreEntry->setWindowTitle(QCoreApplication::translate("WStoreEntry", "Form", nullptr));
        btnSave->setText(QCoreApplication::translate("WStoreEntry", "...", nullptr));
        btnPrint->setText(QCoreApplication::translate("WStoreEntry", "...", nullptr));
        btnRemove->setText(QCoreApplication::translate("WStoreEntry", "...", nullptr));
        label_5->setText(QCoreApplication::translate("WStoreEntry", "Count output", nullptr));
        btnCalculate->setText(QCoreApplication::translate("WStoreEntry", "...", nullptr));
        label->setText(QCoreApplication::translate("WStoreEntry", "Document number", nullptr));
        label_2->setText(QCoreApplication::translate("WStoreEntry", "Date", nullptr));
        label_3->setText(QCoreApplication::translate("WStoreEntry", "Store", nullptr));
        label_4->setText(QCoreApplication::translate("WStoreEntry", "Amount", nullptr));
        toolButton->setText(QCoreApplication::translate("WStoreEntry", "...", nullptr));
        toolButton_2->setText(QCoreApplication::translate("WStoreEntry", "...", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WStoreEntry", "Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("WStoreEntry", "GoodsId", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("WStoreEntry", "Goods", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("WStoreEntry", "Qty", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblData->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("WStoreEntry", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblData->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("WStoreEntry", "Amount", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WStoreEntry: public Ui_WStoreEntry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WSTOREENTRY_H
