/********************************************************************************
** Form generated from reading UI file 'dlgtaxreference.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGTAXREFERENCE_H
#define UI_DLGTAXREFERENCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgTaxReference
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    EQLineEdit *leRoom;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_2;
    EQLineEdit *leSearch;
    QRadioButton *rbThisInvoice;
    QRadioButton *rbAllInvoice;
    EQLineEdit *leGuest;
    QLabel *label;
    QLabel *label_7;
    EQLineEdit *leInvoice;
    EQLineEdit *leAmount;
    QLabel *label_3;
    EQLineEdit *leEntryName;
    QSpacerItem *horizontalSpacer;
    EQTableWidget *tblData;

    void setupUi(QDialog *DlgTaxReference)
    {
        if (DlgTaxReference->objectName().isEmpty())
            DlgTaxReference->setObjectName(QString::fromUtf8("DlgTaxReference"));
        DlgTaxReference->resize(946, 740);
        verticalLayout = new QVBoxLayout(DlgTaxReference);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(DlgTaxReference);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leRoom = new EQLineEdit(widget);
        leRoom->setObjectName(QString::fromUtf8("leRoom"));
        leRoom->setMaximumSize(QSize(50, 16777215));
        leRoom->setFocusPolicy(Qt::NoFocus);
        leRoom->setReadOnly(true);

        gridLayout->addWidget(leRoom, 0, 1, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 2, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        leSearch = new EQLineEdit(widget);
        leSearch->setObjectName(QString::fromUtf8("leSearch"));

        gridLayout->addWidget(leSearch, 3, 7, 1, 1);

        rbThisInvoice = new QRadioButton(widget);
        rbThisInvoice->setObjectName(QString::fromUtf8("rbThisInvoice"));
        rbThisInvoice->setChecked(true);

        gridLayout->addWidget(rbThisInvoice, 3, 0, 1, 2);

        rbAllInvoice = new QRadioButton(widget);
        rbAllInvoice->setObjectName(QString::fromUtf8("rbAllInvoice"));
        rbAllInvoice->setEnabled(false);

        gridLayout->addWidget(rbAllInvoice, 3, 2, 1, 1);

        leGuest = new EQLineEdit(widget);
        leGuest->setObjectName(QString::fromUtf8("leGuest"));
        leGuest->setFocusPolicy(Qt::NoFocus);
        leGuest->setReadOnly(true);

        gridLayout->addWidget(leGuest, 0, 5, 1, 3);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 6, 1, 1);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 4, 1, 1);

        leInvoice = new EQLineEdit(widget);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));
        leInvoice->setMaximumSize(QSize(50, 16777215));
        leInvoice->setFocusPolicy(Qt::NoFocus);
        leInvoice->setReadOnly(true);

        gridLayout->addWidget(leInvoice, 0, 3, 1, 1);

        leAmount = new EQLineEdit(widget);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));
        leAmount->setReadOnly(true);

        gridLayout->addWidget(leAmount, 2, 7, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 6, 1, 1);

        leEntryName = new EQLineEdit(widget);
        leEntryName->setObjectName(QString::fromUtf8("leEntryName"));
        leEntryName->setReadOnly(true);

        gridLayout->addWidget(leEntryName, 2, 1, 1, 4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 8, 1, 1);


        verticalLayout->addWidget(widget);

        tblData = new EQTableWidget(DlgTaxReference);
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


        retranslateUi(DlgTaxReference);

        QMetaObject::connectSlotsByName(DlgTaxReference);
    } // setupUi

    void retranslateUi(QDialog *DlgTaxReference)
    {
        DlgTaxReference->setWindowTitle(QCoreApplication::translate("DlgTaxReference", "Tax reference", nullptr));
        label_5->setText(QCoreApplication::translate("DlgTaxReference", "Room", nullptr));
        label_6->setText(QCoreApplication::translate("DlgTaxReference", "Invoice", nullptr));
        label_2->setText(QCoreApplication::translate("DlgTaxReference", "Entry", nullptr));
        rbThisInvoice->setText(QCoreApplication::translate("DlgTaxReference", "This invoice", nullptr));
        rbAllInvoice->setText(QCoreApplication::translate("DlgTaxReference", "All invoices", nullptr));
        label->setText(QCoreApplication::translate("DlgTaxReference", "Quick search", nullptr));
        label_7->setText(QCoreApplication::translate("DlgTaxReference", "Guest", nullptr));
        label_3->setText(QCoreApplication::translate("DlgTaxReference", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgTaxReference", "RecId", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgTaxReference", "Room", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgTaxReference", "Invoice", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgTaxReference", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblData->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DlgTaxReference", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblData->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("DlgTaxReference", "Date", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgTaxReference: public Ui_DlgTaxReference {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGTAXREFERENCE_H
