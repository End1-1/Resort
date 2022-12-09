/********************************************************************************
** Form generated from reading UI file 'dlgclinitialbalance.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCLINITIALBALANCE_H
#define UI_DLGCLINITIALBALANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgCLInitialBalance
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    EDateEdit *deDate;
    QLabel *label;
    EQLineEdit *leText;
    EQLineEdit *leAmount;
    QLabel *label_3;
    QLabel *label_2;
    QRadioButton *rbCredit;
    QRadioButton *rbDebit;
    QLabel *label_4;
    EQLineEdit *leVaucher;
    QRadioButton *rbTC;

    void setupUi(QDialog *DlgCLInitialBalance)
    {
        if (DlgCLInitialBalance->objectName().isEmpty())
            DlgCLInitialBalance->setObjectName(QString::fromUtf8("DlgCLInitialBalance"));
        DlgCLInitialBalance->resize(383, 160);
        gridLayout = new QGridLayout(DlgCLInitialBalance);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(DlgCLInitialBalance);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(87, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(86, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 4, 0, 1, 4);

        deDate = new EDateEdit(DlgCLInitialBalance);
        deDate->setObjectName(QString::fromUtf8("deDate"));

        gridLayout->addWidget(deDate, 1, 1, 1, 1);

        label = new QLabel(DlgCLInitialBalance);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        leText = new EQLineEdit(DlgCLInitialBalance);
        leText->setObjectName(QString::fromUtf8("leText"));

        gridLayout->addWidget(leText, 2, 1, 1, 3);

        leAmount = new EQLineEdit(DlgCLInitialBalance);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));

        gridLayout->addWidget(leAmount, 1, 3, 1, 1);

        label_3 = new QLabel(DlgCLInitialBalance);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(DlgCLInitialBalance);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 2, 1, 1);

        rbCredit = new QRadioButton(DlgCLInitialBalance);
        rbCredit->setObjectName(QString::fromUtf8("rbCredit"));
        rbCredit->setChecked(true);

        gridLayout->addWidget(rbCredit, 3, 1, 1, 1);

        rbDebit = new QRadioButton(DlgCLInitialBalance);
        rbDebit->setObjectName(QString::fromUtf8("rbDebit"));

        gridLayout->addWidget(rbDebit, 3, 3, 1, 1);

        label_4 = new QLabel(DlgCLInitialBalance);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        leVaucher = new EQLineEdit(DlgCLInitialBalance);
        leVaucher->setObjectName(QString::fromUtf8("leVaucher"));
        leVaucher->setReadOnly(true);

        gridLayout->addWidget(leVaucher, 0, 1, 1, 1);

        rbTC = new QRadioButton(DlgCLInitialBalance);
        rbTC->setObjectName(QString::fromUtf8("rbTC"));

        gridLayout->addWidget(rbTC, 3, 0, 1, 1);

        QWidget::setTabOrder(deDate, leAmount);
        QWidget::setTabOrder(leAmount, leText);
        QWidget::setTabOrder(leText, rbCredit);
        QWidget::setTabOrder(rbCredit, rbDebit);
        QWidget::setTabOrder(rbDebit, btnOk);
        QWidget::setTabOrder(btnOk, btnCancel);

        retranslateUi(DlgCLInitialBalance);

        QMetaObject::connectSlotsByName(DlgCLInitialBalance);
    } // setupUi

    void retranslateUi(QDialog *DlgCLInitialBalance)
    {
        DlgCLInitialBalance->setWindowTitle(QCoreApplication::translate("DlgCLInitialBalance", "Initial balance for city ledger", nullptr));
        btnOk->setText(QCoreApplication::translate("DlgCLInitialBalance", "Create", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgCLInitialBalance", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("DlgCLInitialBalance", "Date", nullptr));
        label_3->setText(QCoreApplication::translate("DlgCLInitialBalance", "Description", nullptr));
        label_2->setText(QCoreApplication::translate("DlgCLInitialBalance", "Amount", nullptr));
        rbCredit->setText(QCoreApplication::translate("DlgCLInitialBalance", "DEBIT", nullptr));
        rbDebit->setText(QCoreApplication::translate("DlgCLInitialBalance", "CREDIT", nullptr));
        label_4->setText(QCoreApplication::translate("DlgCLInitialBalance", "Voucher", nullptr));
        rbTC->setText(QCoreApplication::translate("DlgCLInitialBalance", "ADVANCE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgCLInitialBalance: public Ui_DlgCLInitialBalance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCLINITIALBALANCE_H
