/********************************************************************************
** Form generated from reading UI file 'dlgremotinvoices.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGREMOTINVOICES_H
#define UI_DLGREMOTINVOICES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgRemotInvoices
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EQLineEdit *leSearch;
    QSpacerItem *horizontalSpacer;
    EQTableWidget *tblData;

    void setupUi(QDialog *DlgRemotInvoices)
    {
        if (DlgRemotInvoices->objectName().isEmpty())
            DlgRemotInvoices->setObjectName(QString::fromUtf8("DlgRemotInvoices"));
        DlgRemotInvoices->resize(802, 585);
        verticalLayout = new QVBoxLayout(DlgRemotInvoices);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(DlgRemotInvoices);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        leSearch = new EQLineEdit(widget);
        leSearch->setObjectName(QString::fromUtf8("leSearch"));

        horizontalLayout->addWidget(leSearch);

        horizontalSpacer = new QSpacerItem(357, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);

        tblData = new EQTableWidget(DlgRemotInvoices);
        if (tblData->columnCount() < 4)
            tblData->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tblData->setObjectName(QString::fromUtf8("tblData"));

        verticalLayout->addWidget(tblData);


        retranslateUi(DlgRemotInvoices);

        QMetaObject::connectSlotsByName(DlgRemotInvoices);
    } // setupUi

    void retranslateUi(QDialog *DlgRemotInvoices)
    {
        DlgRemotInvoices->setWindowTitle(QCoreApplication::translate("DlgRemotInvoices", "Exported Invoices", nullptr));
        label->setText(QCoreApplication::translate("DlgRemotInvoices", "Search", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgRemotInvoices", "Invoice", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgRemotInvoices", "Entry", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgRemotInvoices", "Departure", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgRemotInvoices", "Guest", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgRemotInvoices: public Ui_DlgRemotInvoices {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGREMOTINVOICES_H
