/********************************************************************************
** Form generated from reading UI file 'fcityledgerbalanceextended.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCITYLEDGERBALANCEEXTENDED_H
#define UI_FCITYLEDGERBALANCEEXTENDED_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_FCityLedgerBalanceExtended
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QToolButton *btnPrevDate;
    EDateEdit *deStart;
    QLabel *label_2;
    EDateEdit *deEnd;
    QToolButton *btnNextDate;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FCityLedgerBalanceExtended)
    {
        if (FCityLedgerBalanceExtended->objectName().isEmpty())
            FCityLedgerBalanceExtended->setObjectName(QString::fromUtf8("FCityLedgerBalanceExtended"));
        FCityLedgerBalanceExtended->resize(817, 41);
        horizontalLayout = new QHBoxLayout(FCityLedgerBalanceExtended);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FCityLedgerBalanceExtended);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        btnPrevDate = new QToolButton(FCityLedgerBalanceExtended);
        btnPrevDate->setObjectName(QString::fromUtf8("btnPrevDate"));
        btnPrevDate->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrevDate->setIcon(icon);

        horizontalLayout->addWidget(btnPrevDate);

        deStart = new EDateEdit(FCityLedgerBalanceExtended);
        deStart->setObjectName(QString::fromUtf8("deStart"));
        deStart->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(deStart);

        label_2 = new QLabel(FCityLedgerBalanceExtended);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        deEnd = new EDateEdit(FCityLedgerBalanceExtended);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));
        deEnd->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(deEnd);

        btnNextDate = new QToolButton(FCityLedgerBalanceExtended);
        btnNextDate->setObjectName(QString::fromUtf8("btnNextDate"));
        btnNextDate->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNextDate->setIcon(icon1);

        horizontalLayout->addWidget(btnNextDate);

        horizontalSpacer = new QSpacerItem(496, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FCityLedgerBalanceExtended);

        QMetaObject::connectSlotsByName(FCityLedgerBalanceExtended);
    } // setupUi

    void retranslateUi(QWidget *FCityLedgerBalanceExtended)
    {
        FCityLedgerBalanceExtended->setWindowTitle(QCoreApplication::translate("FCityLedgerBalanceExtended", "Form", nullptr));
        label->setText(QCoreApplication::translate("FCityLedgerBalanceExtended", "From", nullptr));
        btnPrevDate->setText(QCoreApplication::translate("FCityLedgerBalanceExtended", "...", nullptr));
        label_2->setText(QCoreApplication::translate("FCityLedgerBalanceExtended", "To", nullptr));
        btnNextDate->setText(QCoreApplication::translate("FCityLedgerBalanceExtended", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FCityLedgerBalanceExtended: public Ui_FCityLedgerBalanceExtended {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCITYLEDGERBALANCEEXTENDED_H
