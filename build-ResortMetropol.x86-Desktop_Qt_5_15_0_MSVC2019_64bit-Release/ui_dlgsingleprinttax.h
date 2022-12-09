/********************************************************************************
** Form generated from reading UI file 'dlgsingleprinttax.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGSINGLEPRINTTAX_H
#define UI_DLGSINGLEPRINTTAX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgSinglePrintTax
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    EQTableWidget *tbl;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPrint;
    QPushButton *btnClose;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgSinglePrintTax)
    {
        if (DlgSinglePrintTax->objectName().isEmpty())
            DlgSinglePrintTax->setObjectName(QString::fromUtf8("DlgSinglePrintTax"));
        DlgSinglePrintTax->resize(809, 136);
        verticalLayout_3 = new QVBoxLayout(DlgSinglePrintTax);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget = new QWidget(DlgSinglePrintTax);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tbl = new EQTableWidget(widget);
        if (tbl->columnCount() < 10)
            tbl->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        tbl->setObjectName(QString::fromUtf8("tbl"));
        tbl->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tbl->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbl->setSelectionMode(QAbstractItemView::NoSelection);
        tbl->verticalHeader()->setVisible(false);
        tbl->verticalHeader()->setMinimumSectionSize(0);
        tbl->verticalHeader()->setDefaultSectionSize(25);

        verticalLayout_2->addWidget(tbl);


        verticalLayout_3->addWidget(widget);

        widget_2 = new QWidget(DlgSinglePrintTax);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnPrint = new QPushButton(widget_2);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));

        horizontalLayout->addWidget(btnPrint);

        btnClose = new QPushButton(widget_2);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        horizontalLayout->addWidget(btnClose);

        horizontalSpacer_2 = new QSpacerItem(299, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addWidget(widget_2);


        retranslateUi(DlgSinglePrintTax);

        QMetaObject::connectSlotsByName(DlgSinglePrintTax);
    } // setupUi

    void retranslateUi(QDialog *DlgSinglePrintTax)
    {
        DlgSinglePrintTax->setWindowTitle(QCoreApplication::translate("DlgSinglePrintTax", "Tax print", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tbl->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgSinglePrintTax", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tbl->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgSinglePrintTax", "Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tbl->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgSinglePrintTax", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tbl->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgSinglePrintTax", "Name of tax", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tbl->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DlgSinglePrintTax", "Qty", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tbl->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("DlgSinglePrintTax", "Dept", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tbl->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("DlgSinglePrintTax", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tbl->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("DlgSinglePrintTax", "Mode of payment", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tbl->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("DlgSinglePrintTax", "Adg", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tbl->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("DlgSinglePrintTax", "Voucher", nullptr));
        btnPrint->setText(QCoreApplication::translate("DlgSinglePrintTax", "Print", nullptr));
        btnClose->setText(QCoreApplication::translate("DlgSinglePrintTax", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgSinglePrintTax: public Ui_DlgSinglePrintTax {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGSINGLEPRINTTAX_H
