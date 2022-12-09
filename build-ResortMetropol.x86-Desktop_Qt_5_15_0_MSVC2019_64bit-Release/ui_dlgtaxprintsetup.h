/********************************************************************************
** Form generated from reading UI file 'dlgtaxprintsetup.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGTAXPRINTSETUP_H
#define UI_DLGTAXPRINTSETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgTaxPrintSetup
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    EQLineEdit *leHallName;
    EQLineEdit *leMenuName;
    EQLineEdit *leHallCode;
    EQLineEdit *leMenuCode;
    EQLineEdit *leAddress;
    EQLineEdit *lePort;
    EQLineEdit *lePassword;
    QLineEdit *leAdg;

    void setupUi(QDialog *DlgTaxPrintSetup)
    {
        if (DlgTaxPrintSetup->objectName().isEmpty())
            DlgTaxPrintSetup->setObjectName(QString::fromUtf8("DlgTaxPrintSetup"));
        DlgTaxPrintSetup->resize(349, 222);
        verticalLayout = new QVBoxLayout(DlgTaxPrintSetup);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(DlgTaxPrintSetup);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_3 = new QLabel(DlgTaxPrintSetup);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(DlgTaxPrintSetup);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(DlgTaxPrintSetup);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(DlgTaxPrintSetup);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        widget = new QWidget(DlgTaxPrintSetup);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(69, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 6, 0, 1, 3);

        label_6 = new QLabel(DlgTaxPrintSetup);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        leHallName = new EQLineEdit(DlgTaxPrintSetup);
        leHallName->setObjectName(QString::fromUtf8("leHallName"));

        gridLayout->addWidget(leHallName, 4, 2, 1, 1);

        leMenuName = new EQLineEdit(DlgTaxPrintSetup);
        leMenuName->setObjectName(QString::fromUtf8("leMenuName"));

        gridLayout->addWidget(leMenuName, 5, 2, 1, 1);

        leHallCode = new EQLineEdit(DlgTaxPrintSetup);
        leHallCode->setObjectName(QString::fromUtf8("leHallCode"));
        leHallCode->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(leHallCode, 4, 1, 1, 1);

        leMenuCode = new EQLineEdit(DlgTaxPrintSetup);
        leMenuCode->setObjectName(QString::fromUtf8("leMenuCode"));
        leMenuCode->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(leMenuCode, 5, 1, 1, 1);

        leAddress = new EQLineEdit(DlgTaxPrintSetup);
        leAddress->setObjectName(QString::fromUtf8("leAddress"));

        gridLayout->addWidget(leAddress, 0, 1, 1, 2);

        lePort = new EQLineEdit(DlgTaxPrintSetup);
        lePort->setObjectName(QString::fromUtf8("lePort"));

        gridLayout->addWidget(lePort, 1, 1, 1, 2);

        lePassword = new EQLineEdit(DlgTaxPrintSetup);
        lePassword->setObjectName(QString::fromUtf8("lePassword"));

        gridLayout->addWidget(lePassword, 2, 1, 1, 2);

        leAdg = new QLineEdit(DlgTaxPrintSetup);
        leAdg->setObjectName(QString::fromUtf8("leAdg"));

        gridLayout->addWidget(leAdg, 3, 1, 1, 2);


        verticalLayout->addLayout(gridLayout);

        QWidget::setTabOrder(leAddress, lePort);
        QWidget::setTabOrder(lePort, lePassword);
        QWidget::setTabOrder(lePassword, leAdg);
        QWidget::setTabOrder(leAdg, btnOk);
        QWidget::setTabOrder(btnOk, btnCancel);

        retranslateUi(DlgTaxPrintSetup);

        QMetaObject::connectSlotsByName(DlgTaxPrintSetup);
    } // setupUi

    void retranslateUi(QDialog *DlgTaxPrintSetup)
    {
        DlgTaxPrintSetup->setWindowTitle(QCoreApplication::translate("DlgTaxPrintSetup", "Tax Printer Setup", nullptr));
        label_5->setText(QCoreApplication::translate("DlgTaxPrintSetup", "Hall", nullptr));
        label_3->setText(QCoreApplication::translate("DlgTaxPrintSetup", "Password", nullptr));
        label->setText(QCoreApplication::translate("DlgTaxPrintSetup", "IP Address", nullptr));
        label_2->setText(QCoreApplication::translate("DlgTaxPrintSetup", "Port", nullptr));
        label_4->setText(QCoreApplication::translate("DlgTaxPrintSetup", "ADG code", nullptr));
        btnOk->setText(QCoreApplication::translate("DlgTaxPrintSetup", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgTaxPrintSetup", "Cancel", nullptr));
        label_6->setText(QCoreApplication::translate("DlgTaxPrintSetup", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgTaxPrintSetup: public Ui_DlgTaxPrintSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGTAXPRINTSETUP_H
