/********************************************************************************
** Form generated from reading UI file 'fcityledgerbalance.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCITYLEDGERBALANCE_H
#define UI_FCITYLEDGERBALANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqcheckbox.h>

QT_BEGIN_NAMESPACE

class Ui_FCityLedgerBalance
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    EDateEdit *deStart;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    EQCheckBox *chZeroBalance;

    void setupUi(QWidget *FCityLedgerBalance)
    {
        if (FCityLedgerBalance->objectName().isEmpty())
            FCityLedgerBalance->setObjectName(QString::fromUtf8("FCityLedgerBalance"));
        FCityLedgerBalance->resize(815, 40);
        verticalLayout = new QVBoxLayout(FCityLedgerBalance);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        deStart = new EDateEdit(FCityLedgerBalance);
        deStart->setObjectName(QString::fromUtf8("deStart"));
        deStart->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(deStart, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        label = new QLabel(FCityLedgerBalance);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        chZeroBalance = new EQCheckBox(FCityLedgerBalance);
        chZeroBalance->setObjectName(QString::fromUtf8("chZeroBalance"));
        chZeroBalance->setFocusPolicy(Qt::ClickFocus);
        chZeroBalance->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(chZeroBalance, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(FCityLedgerBalance);

        QMetaObject::connectSlotsByName(FCityLedgerBalance);
    } // setupUi

    void retranslateUi(QWidget *FCityLedgerBalance)
    {
        FCityLedgerBalance->setWindowTitle(QCoreApplication::translate("FCityLedgerBalance", "Form", nullptr));
        deStart->setInputMask(QCoreApplication::translate("FCityLedgerBalance", "00/00/0000", nullptr));
        deStart->setText(QCoreApplication::translate("FCityLedgerBalance", "//", nullptr));
        label->setText(QCoreApplication::translate("FCityLedgerBalance", "Start date", nullptr));
        chZeroBalance->setText(QCoreApplication::translate("FCityLedgerBalance", "Zero balances", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FCityLedgerBalance: public Ui_FCityLedgerBalance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCITYLEDGERBALANCE_H
