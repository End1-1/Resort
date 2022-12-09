/********************************************************************************
** Form generated from reading UI file 'dlginvoicecancelation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGINVOICECANCELATION_H
#define UI_DLGINVOICECANCELATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgInvoiceCancelation
{
public:
    QVBoxLayout *verticalLayout;
    EQTableWidget *tblData;
    QTextEdit *teReason;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgInvoiceCancelation)
    {
        if (DlgInvoiceCancelation->objectName().isEmpty())
            DlgInvoiceCancelation->setObjectName(QString::fromUtf8("DlgInvoiceCancelation"));
        DlgInvoiceCancelation->resize(685, 452);
        verticalLayout = new QVBoxLayout(DlgInvoiceCancelation);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tblData = new EQTableWidget(DlgInvoiceCancelation);
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

        verticalLayout->addWidget(tblData);

        teReason = new QTextEdit(DlgInvoiceCancelation);
        teReason->setObjectName(QString::fromUtf8("teReason"));
        teReason->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(teReason);

        widget = new QWidget(DlgInvoiceCancelation);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(237, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);


        retranslateUi(DlgInvoiceCancelation);

        QMetaObject::connectSlotsByName(DlgInvoiceCancelation);
    } // setupUi

    void retranslateUi(QDialog *DlgInvoiceCancelation)
    {
        DlgInvoiceCancelation->setWindowTitle(QCoreApplication::translate("DlgInvoiceCancelation", "Cancelation", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgInvoiceCancelation", "RecId", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgInvoiceCancelation", "Souce", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgInvoiceCancelation", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgInvoiceCancelation", "ItemId", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblData->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DlgInvoiceCancelation", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblData->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("DlgInvoiceCancelation", "Amount", nullptr));
        teReason->setPlaceholderText(QCoreApplication::translate("DlgInvoiceCancelation", "Reason for cancelation", nullptr));
        btnOk->setText(QCoreApplication::translate("DlgInvoiceCancelation", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgInvoiceCancelation", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgInvoiceCancelation: public Ui_DlgInvoiceCancelation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGINVOICECANCELATION_H
