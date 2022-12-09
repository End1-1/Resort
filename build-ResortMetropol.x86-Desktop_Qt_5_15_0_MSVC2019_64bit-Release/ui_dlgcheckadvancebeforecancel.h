/********************************************************************************
** Form generated from reading UI file 'dlgcheckadvancebeforecancel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCHECKADVANCEBEFORECANCEL_H
#define UI_DLGCHECKADVANCEBEFORECANCEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgCheckAdvanceBeforeCancel
{
public:
    QGridLayout *gridLayout;
    EQLineEdit *leGuest;
    QPushButton *btnCancelreservation;
    EQLineEdit *leRoom;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *leInvoice;
    QLabel *label_4;
    EQLineEdit *leBalance;
    QLineEdit *leReservation;
    QLabel *label_2;
    QPushButton *btnNoShow;
    QLabel *label;
    QPushButton *btnTransferToCL;
    QPushButton *btnRefund;
    QPushButton *btnCancel;
    QLabel *label_6;
    QPlainTextEdit *teReason;

    void setupUi(QDialog *DlgCheckAdvanceBeforeCancel)
    {
        if (DlgCheckAdvanceBeforeCancel->objectName().isEmpty())
            DlgCheckAdvanceBeforeCancel->setObjectName(QString::fromUtf8("DlgCheckAdvanceBeforeCancel"));
        DlgCheckAdvanceBeforeCancel->resize(381, 498);
        gridLayout = new QGridLayout(DlgCheckAdvanceBeforeCancel);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leGuest = new EQLineEdit(DlgCheckAdvanceBeforeCancel);
        leGuest->setObjectName(QString::fromUtf8("leGuest"));
        leGuest->setReadOnly(true);

        gridLayout->addWidget(leGuest, 3, 2, 1, 1);

        btnCancelreservation = new QPushButton(DlgCheckAdvanceBeforeCancel);
        btnCancelreservation->setObjectName(QString::fromUtf8("btnCancelreservation"));
        btnCancelreservation->setEnabled(false);
        btnCancelreservation->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(btnCancelreservation, 9, 0, 1, 3);

        leRoom = new EQLineEdit(DlgCheckAdvanceBeforeCancel);
        leRoom->setObjectName(QString::fromUtf8("leRoom"));
        leRoom->setReadOnly(true);

        gridLayout->addWidget(leRoom, 2, 2, 1, 1);

        label_3 = new QLabel(DlgCheckAdvanceBeforeCancel);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_5 = new QLabel(DlgCheckAdvanceBeforeCancel);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        leInvoice = new QLineEdit(DlgCheckAdvanceBeforeCancel);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));
        leInvoice->setEnabled(false);

        gridLayout->addWidget(leInvoice, 1, 2, 1, 1);

        label_4 = new QLabel(DlgCheckAdvanceBeforeCancel);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        leBalance = new EQLineEdit(DlgCheckAdvanceBeforeCancel);
        leBalance->setObjectName(QString::fromUtf8("leBalance"));
        leBalance->setReadOnly(true);

        gridLayout->addWidget(leBalance, 4, 2, 1, 1);

        leReservation = new QLineEdit(DlgCheckAdvanceBeforeCancel);
        leReservation->setObjectName(QString::fromUtf8("leReservation"));
        leReservation->setEnabled(false);

        gridLayout->addWidget(leReservation, 0, 2, 1, 1);

        label_2 = new QLabel(DlgCheckAdvanceBeforeCancel);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        btnNoShow = new QPushButton(DlgCheckAdvanceBeforeCancel);
        btnNoShow->setObjectName(QString::fromUtf8("btnNoShow"));
        btnNoShow->setEnabled(true);
        btnNoShow->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(btnNoShow, 8, 0, 1, 3);

        label = new QLabel(DlgCheckAdvanceBeforeCancel);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 4, 0, 1, 1);

        btnTransferToCL = new QPushButton(DlgCheckAdvanceBeforeCancel);
        btnTransferToCL->setObjectName(QString::fromUtf8("btnTransferToCL"));
        btnTransferToCL->setEnabled(false);
        btnTransferToCL->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(btnTransferToCL, 7, 0, 1, 3);

        btnRefund = new QPushButton(DlgCheckAdvanceBeforeCancel);
        btnRefund->setObjectName(QString::fromUtf8("btnRefund"));
        btnRefund->setEnabled(false);
        btnRefund->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(btnRefund, 6, 0, 1, 3);

        btnCancel = new QPushButton(DlgCheckAdvanceBeforeCancel);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(btnCancel, 10, 0, 1, 3);

        label_6 = new QLabel(DlgCheckAdvanceBeforeCancel);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        teReason = new QPlainTextEdit(DlgCheckAdvanceBeforeCancel);
        teReason->setObjectName(QString::fromUtf8("teReason"));
        teReason->setMinimumSize(QSize(0, 50));
        teReason->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(teReason, 5, 2, 1, 1);


        retranslateUi(DlgCheckAdvanceBeforeCancel);

        QMetaObject::connectSlotsByName(DlgCheckAdvanceBeforeCancel);
    } // setupUi

    void retranslateUi(QDialog *DlgCheckAdvanceBeforeCancel)
    {
        DlgCheckAdvanceBeforeCancel->setWindowTitle(QCoreApplication::translate("DlgCheckAdvanceBeforeCancel", "Reservation advance", nullptr));
        btnCancelreservation->setText(QCoreApplication::translate("DlgCheckAdvanceBeforeCancel", "CANCEL RESERVATION", nullptr));
        label_3->setText(QCoreApplication::translate("DlgCheckAdvanceBeforeCancel", "Room", nullptr));
        label_5->setText(QCoreApplication::translate("DlgCheckAdvanceBeforeCancel", "Invoice", nullptr));
        label_4->setText(QCoreApplication::translate("DlgCheckAdvanceBeforeCancel", "Guest", nullptr));
        label_2->setText(QCoreApplication::translate("DlgCheckAdvanceBeforeCancel", "Reservation", nullptr));
        btnNoShow->setText(QCoreApplication::translate("DlgCheckAdvanceBeforeCancel", "Charge Cancelation/No show fee", nullptr));
        label->setText(QCoreApplication::translate("DlgCheckAdvanceBeforeCancel", "Balance on reservation", nullptr));
        btnTransferToCL->setText(QCoreApplication::translate("DlgCheckAdvanceBeforeCancel", "Transfer amount", nullptr));
        btnRefund->setText(QCoreApplication::translate("DlgCheckAdvanceBeforeCancel", "Refund", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgCheckAdvanceBeforeCancel", "Back", nullptr));
        label_6->setText(QCoreApplication::translate("DlgCheckAdvanceBeforeCancel", "Cancelation reason", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgCheckAdvanceBeforeCancel: public Ui_DlgCheckAdvanceBeforeCancel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCHECKADVANCEBEFORECANCEL_H
