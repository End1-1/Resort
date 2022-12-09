/********************************************************************************
** Form generated from reading UI file 'dlgdebtpay.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGDEBTPAY_H
#define UI_DLGDEBTPAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqdoubleedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgDebtPay
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    EQLineEdit *leCode;
    QLabel *label_2;
    EDateEdit *leDate;
    QLabel *label_3;
    EQLineEdit *leCostCode;
    EQLineEdit *leCostName;
    QLabel *label_4;
    EQDoubleEdit *leAmount;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgDebtPay)
    {
        if (DlgDebtPay->objectName().isEmpty())
            DlgDebtPay->setObjectName(QString::fromUtf8("DlgDebtPay"));
        DlgDebtPay->resize(518, 181);
        verticalLayout = new QVBoxLayout(DlgDebtPay);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(DlgDebtPay);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leCode = new EQLineEdit(widget);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setEnabled(false);
        leCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leDate = new EDateEdit(widget);
        leDate->setObjectName(QString::fromUtf8("leDate"));
        leDate->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leDate, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        leCostCode = new EQLineEdit(widget);
        leCostCode->setObjectName(QString::fromUtf8("leCostCode"));
        leCostCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leCostCode, 2, 1, 1, 1);

        leCostName = new EQLineEdit(widget);
        leCostName->setObjectName(QString::fromUtf8("leCostName"));
        leCostName->setEnabled(false);

        gridLayout->addWidget(leCostName, 2, 2, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        leAmount = new EQDoubleEdit(widget);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));
        leAmount->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leAmount, 3, 1, 1, 1);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(DlgDebtPay);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(154, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget_2);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget_2);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(154, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_2);


        retranslateUi(DlgDebtPay);

        QMetaObject::connectSlotsByName(DlgDebtPay);
    } // setupUi

    void retranslateUi(QDialog *DlgDebtPay)
    {
        DlgDebtPay->setWindowTitle(QCoreApplication::translate("DlgDebtPay", "Payment of debt", nullptr));
        label->setText(QCoreApplication::translate("DlgDebtPay", "Code", nullptr));
        label_2->setText(QCoreApplication::translate("DlgDebtPay", "Date", nullptr));
        label_3->setText(QCoreApplication::translate("DlgDebtPay", "Holder", nullptr));
        label_4->setText(QCoreApplication::translate("DlgDebtPay", "Amount", nullptr));
        btnOk->setText(QCoreApplication::translate("DlgDebtPay", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgDebtPay", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgDebtPay: public Ui_DlgDebtPay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGDEBTPAY_H
