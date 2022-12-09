/********************************************************************************
** Form generated from reading UI file 'dlgprinttaxsideoption.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGPRINTTAXSIDEOPTION_H
#define UI_DLGPRINTTAXSIDEOPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgPrintTaxSideOption
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rbGuest;
    QRadioButton *rbCompany;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPrint;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgPrintTaxSideOption)
    {
        if (DlgPrintTaxSideOption->objectName().isEmpty())
            DlgPrintTaxSideOption->setObjectName(QString::fromUtf8("DlgPrintTaxSideOption"));
        DlgPrintTaxSideOption->resize(274, 102);
        verticalLayout_2 = new QVBoxLayout(DlgPrintTaxSideOption);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(DlgPrintTaxSideOption);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        rbGuest = new QRadioButton(groupBox);
        rbGuest->setObjectName(QString::fromUtf8("rbGuest"));
        rbGuest->setChecked(true);

        horizontalLayout_2->addWidget(rbGuest);

        rbCompany = new QRadioButton(groupBox);
        rbCompany->setObjectName(QString::fromUtf8("rbCompany"));

        horizontalLayout_2->addWidget(rbCompany);


        verticalLayout_2->addWidget(groupBox);

        widget = new QWidget(DlgPrintTaxSideOption);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(32, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnPrint = new QPushButton(widget);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));

        horizontalLayout->addWidget(btnPrint);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(32, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget);


        retranslateUi(DlgPrintTaxSideOption);

        QMetaObject::connectSlotsByName(DlgPrintTaxSideOption);
    } // setupUi

    void retranslateUi(QDialog *DlgPrintTaxSideOption)
    {
        DlgPrintTaxSideOption->setWindowTitle(QString());
        groupBox->setTitle(QString());
        rbGuest->setText(QCoreApplication::translate("DlgPrintTaxSideOption", "Guest part", nullptr));
        rbCompany->setText(QCoreApplication::translate("DlgPrintTaxSideOption", "Company part", nullptr));
        btnPrint->setText(QCoreApplication::translate("DlgPrintTaxSideOption", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgPrintTaxSideOption", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgPrintTaxSideOption: public Ui_DlgPrintTaxSideOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGPRINTTAXSIDEOPTION_H
