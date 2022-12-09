/********************************************************************************
** Form generated from reading UI file 'dlgsearchinvoice.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGSEARCHINVOICE_H
#define UI_DLGSEARCHINVOICE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgSearchInvoice
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EDateEdit *deStart;
    QLabel *label_2;
    EDateEdit *deEnd;
    QToolButton *btnRefresh;
    QSpacerItem *horizontalSpacer;
    QLineEdit *leFilter;
    QToolButton *btnClearFilter;
    EQTableWidget *tblData;

    void setupUi(QDialog *DlgSearchInvoice)
    {
        if (DlgSearchInvoice->objectName().isEmpty())
            DlgSearchInvoice->setObjectName(QString::fromUtf8("DlgSearchInvoice"));
        DlgSearchInvoice->resize(682, 495);
        verticalLayout = new QVBoxLayout(DlgSearchInvoice);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(DlgSearchInvoice);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        deStart = new EDateEdit(widget);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        horizontalLayout->addWidget(deStart);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        deEnd = new EDateEdit(widget);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        horizontalLayout->addWidget(deEnd);

        btnRefresh = new QToolButton(widget);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon);

        horizontalLayout->addWidget(btnRefresh);

        horizontalSpacer = new QSpacerItem(132, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        leFilter = new QLineEdit(widget);
        leFilter->setObjectName(QString::fromUtf8("leFilter"));

        horizontalLayout->addWidget(leFilter);

        btnClearFilter = new QToolButton(widget);
        btnClearFilter->setObjectName(QString::fromUtf8("btnClearFilter"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/remove_filter.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClearFilter->setIcon(icon1);

        horizontalLayout->addWidget(btnClearFilter);


        verticalLayout->addWidget(widget);

        tblData = new EQTableWidget(DlgSearchInvoice);
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


        retranslateUi(DlgSearchInvoice);

        QMetaObject::connectSlotsByName(DlgSearchInvoice);
    } // setupUi

    void retranslateUi(QDialog *DlgSearchInvoice)
    {
        DlgSearchInvoice->setWindowTitle(QCoreApplication::translate("DlgSearchInvoice", "Search for invoice", nullptr));
        label->setText(QCoreApplication::translate("DlgSearchInvoice", "From", nullptr));
        label_2->setText(QCoreApplication::translate("DlgSearchInvoice", "To", nullptr));
        btnRefresh->setText(QCoreApplication::translate("DlgSearchInvoice", "...", nullptr));
        btnClearFilter->setText(QCoreApplication::translate("DlgSearchInvoice", "...", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgSearchInvoice", "Invoice Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgSearchInvoice", "Reserve Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgSearchInvoice", "Room", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgSearchInvoice", "Entry", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblData->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DlgSearchInvoice", "Departure", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblData->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("DlgSearchInvoice", "Guest", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgSearchInvoice: public Ui_DlgSearchInvoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGSEARCHINVOICE_H
