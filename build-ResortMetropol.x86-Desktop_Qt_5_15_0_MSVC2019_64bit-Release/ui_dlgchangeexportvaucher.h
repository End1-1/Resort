/********************************************************************************
** Form generated from reading UI file 'dlgchangeexportvaucher.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCHANGEEXPORTVAUCHER_H
#define UI_DLGCHANGEEXPORTVAUCHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgChangeExportVaucher
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    EDateEdit *deDate;
    QLabel *label_2;
    QTimeEdit *teTime;
    QLabel *label_4;
    EQLineEdit *leItemCode;
    EQLineEdit *leItemName;
    QLabel *label_3;
    EQLineEdit *leAmount;
    QLineEdit *leSource;

    void setupUi(QDialog *DlgChangeExportVaucher)
    {
        if (DlgChangeExportVaucher->objectName().isEmpty())
            DlgChangeExportVaucher->setObjectName(QString::fromUtf8("DlgChangeExportVaucher"));
        DlgChangeExportVaucher->resize(358, 138);
        gridLayout = new QGridLayout(DlgChangeExportVaucher);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(DlgChangeExportVaucher);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(74, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOK = new QPushButton(widget);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));

        horizontalLayout->addWidget(btnOK);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(74, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 3, 0, 1, 5);

        label = new QLabel(DlgChangeExportVaucher);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        deDate = new EDateEdit(DlgChangeExportVaucher);
        deDate->setObjectName(QString::fromUtf8("deDate"));
        deDate->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(deDate, 0, 1, 1, 1);

        label_2 = new QLabel(DlgChangeExportVaucher);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        teTime = new QTimeEdit(DlgChangeExportVaucher);
        teTime->setObjectName(QString::fromUtf8("teTime"));

        gridLayout->addWidget(teTime, 0, 4, 1, 1);

        label_4 = new QLabel(DlgChangeExportVaucher);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        leItemCode = new EQLineEdit(DlgChangeExportVaucher);
        leItemCode->setObjectName(QString::fromUtf8("leItemCode"));
        leItemCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leItemCode, 1, 1, 1, 1);

        leItemName = new EQLineEdit(DlgChangeExportVaucher);
        leItemName->setObjectName(QString::fromUtf8("leItemName"));

        gridLayout->addWidget(leItemName, 1, 3, 1, 2);

        label_3 = new QLabel(DlgChangeExportVaucher);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        leAmount = new EQLineEdit(DlgChangeExportVaucher);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));
        leAmount->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leAmount, 2, 1, 1, 1);

        leSource = new QLineEdit(DlgChangeExportVaucher);
        leSource->setObjectName(QString::fromUtf8("leSource"));
        leSource->setMaximumSize(QSize(25, 16777215));
        leSource->setReadOnly(true);

        gridLayout->addWidget(leSource, 1, 2, 1, 1);


        retranslateUi(DlgChangeExportVaucher);

        QMetaObject::connectSlotsByName(DlgChangeExportVaucher);
    } // setupUi

    void retranslateUi(QDialog *DlgChangeExportVaucher)
    {
        DlgChangeExportVaucher->setWindowTitle(QCoreApplication::translate("DlgChangeExportVaucher", "Type of sale", nullptr));
        btnOK->setText(QCoreApplication::translate("DlgChangeExportVaucher", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgChangeExportVaucher", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("DlgChangeExportVaucher", "Date", nullptr));
        label_2->setText(QCoreApplication::translate("DlgChangeExportVaucher", "Time", nullptr));
        label_4->setText(QCoreApplication::translate("DlgChangeExportVaucher", "Type of sale", nullptr));
        label_3->setText(QCoreApplication::translate("DlgChangeExportVaucher", "Amount", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgChangeExportVaucher: public Ui_DlgChangeExportVaucher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCHANGEEXPORTVAUCHER_H
