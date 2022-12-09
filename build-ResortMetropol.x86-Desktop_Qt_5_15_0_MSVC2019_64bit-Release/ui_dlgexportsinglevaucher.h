/********************************************************************************
** Form generated from reading UI file 'dlgexportsinglevaucher.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGEXPORTSINGLEVAUCHER_H
#define UI_DLGEXPORTSINGLEVAUCHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgExportSingleVaucher
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label;
    EQLineEdit *leInvoice;
    EQLineEdit *leRoom;
    QLabel *label_2;
    EQLineEdit *leGuest;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    EQLineEdit *leFinalName;
    QLabel *label_5;
    EQLineEdit *leAmount;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_6;
    EDateEdit *deDate;
    QLabel *label_7;
    QTimeEdit *teTime;

    void setupUi(QDialog *DlgExportSingleVaucher)
    {
        if (DlgExportSingleVaucher->objectName().isEmpty())
            DlgExportSingleVaucher->setObjectName(QString::fromUtf8("DlgExportSingleVaucher"));
        DlgExportSingleVaucher->resize(692, 170);
        gridLayout = new QGridLayout(DlgExportSingleVaucher);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(DlgExportSingleVaucher);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 4, 1, 1);

        label = new QLabel(DlgExportSingleVaucher);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leInvoice = new EQLineEdit(DlgExportSingleVaucher);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));
        leInvoice->setMaximumSize(QSize(80, 16777215));
        leInvoice->setReadOnly(false);

        gridLayout->addWidget(leInvoice, 0, 1, 1, 1);

        leRoom = new EQLineEdit(DlgExportSingleVaucher);
        leRoom->setObjectName(QString::fromUtf8("leRoom"));
        leRoom->setMaximumSize(QSize(50, 16777215));
        leRoom->setReadOnly(true);

        gridLayout->addWidget(leRoom, 0, 3, 1, 1);

        label_2 = new QLabel(DlgExportSingleVaucher);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        leGuest = new EQLineEdit(DlgExportSingleVaucher);
        leGuest->setObjectName(QString::fromUtf8("leGuest"));
        leGuest->setReadOnly(true);

        gridLayout->addWidget(leGuest, 0, 5, 1, 1);

        widget = new QWidget(DlgExportSingleVaucher);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(241, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(241, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 2, 0, 1, 6);

        groupBox = new QGroupBox(DlgExportSingleVaucher);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        leFinalName = new EQLineEdit(groupBox);
        leFinalName->setObjectName(QString::fromUtf8("leFinalName"));
        leFinalName->setMinimumSize(QSize(300, 0));
        leFinalName->setReadOnly(false);

        gridLayout_2->addWidget(leFinalName, 0, 2, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 3, 1, 1);

        leAmount = new EQLineEdit(groupBox);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));
        leAmount->setMinimumSize(QSize(100, 0));
        leAmount->setMaximumSize(QSize(100, 16777215));
        leAmount->setReadOnly(false);

        gridLayout_2->addWidget(leAmount, 0, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(163, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 5, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        deDate = new EDateEdit(groupBox);
        deDate->setObjectName(QString::fromUtf8("deDate"));

        gridLayout_2->addWidget(deDate, 1, 2, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 1, 3, 1, 1);

        teTime = new QTimeEdit(groupBox);
        teTime->setObjectName(QString::fromUtf8("teTime"));

        gridLayout_2->addWidget(teTime, 1, 4, 1, 1);


        gridLayout->addWidget(groupBox, 1, 0, 1, 6);


        retranslateUi(DlgExportSingleVaucher);

        QMetaObject::connectSlotsByName(DlgExportSingleVaucher);
    } // setupUi

    void retranslateUi(QDialog *DlgExportSingleVaucher)
    {
        DlgExportSingleVaucher->setWindowTitle(QCoreApplication::translate("DlgExportSingleVaucher", "Export voucher", nullptr));
        label_3->setText(QCoreApplication::translate("DlgExportSingleVaucher", "Guest", nullptr));
        label->setText(QCoreApplication::translate("DlgExportSingleVaucher", "Export to invoice #", nullptr));
        label_2->setText(QCoreApplication::translate("DlgExportSingleVaucher", "Room", nullptr));
        btnOk->setText(QCoreApplication::translate("DlgExportSingleVaucher", "Export", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgExportSingleVaucher", "Cancel", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DlgExportSingleVaucher", "Voucher", nullptr));
        label_4->setText(QCoreApplication::translate("DlgExportSingleVaucher", "Name", nullptr));
        label_5->setText(QCoreApplication::translate("DlgExportSingleVaucher", "Amount", nullptr));
        label_6->setText(QCoreApplication::translate("DlgExportSingleVaucher", "Date", nullptr));
        label_7->setText(QCoreApplication::translate("DlgExportSingleVaucher", "Time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgExportSingleVaucher: public Ui_DlgExportSingleVaucher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGEXPORTSINGLEVAUCHER_H
