/********************************************************************************
** Form generated from reading UI file 'dlgcashop.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCASHOP_H
#define UI_DLGCASHOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QVBoxLayout>
#include <wcashentry.h>

QT_BEGIN_NAMESPACE

class Ui_DlgCashOp
{
public:
    QVBoxLayout *verticalLayout;
    WCashEntry *wAcc;

    void setupUi(QDialog *DlgCashOp)
    {
        if (DlgCashOp->objectName().isEmpty())
            DlgCashOp->setObjectName(QString::fromUtf8("DlgCashOp"));
        DlgCashOp->resize(604, 419);
        verticalLayout = new QVBoxLayout(DlgCashOp);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        wAcc = new WCashEntry(DlgCashOp);
        wAcc->setObjectName(QString::fromUtf8("wAcc"));

        verticalLayout->addWidget(wAcc);


        retranslateUi(DlgCashOp);

        QMetaObject::connectSlotsByName(DlgCashOp);
    } // setupUi

    void retranslateUi(QDialog *DlgCashOp)
    {
        DlgCashOp->setWindowTitle(QCoreApplication::translate("DlgCashOp", "Cash document", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgCashOp: public Ui_DlgCashOp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCASHOP_H
