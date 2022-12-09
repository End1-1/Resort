/********************************************************************************
** Form generated from reading UI file 'dlgprintreservation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGPRINTRESERVATION_H
#define UI_DLGPRINTRESERVATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DlgPrintReservation
{
public:
    QGridLayout *gridLayout;
    QPushButton *btnPrintConfirmation;
    QPushButton *btnClose;
    QPushButton *btnPrintReservation;
    QPushButton *btnPrintRegistrationCard;

    void setupUi(QDialog *DlgPrintReservation)
    {
        if (DlgPrintReservation->objectName().isEmpty())
            DlgPrintReservation->setObjectName(QString::fromUtf8("DlgPrintReservation"));
        DlgPrintReservation->resize(400, 106);
        gridLayout = new QGridLayout(DlgPrintReservation);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnPrintConfirmation = new QPushButton(DlgPrintReservation);
        btnPrintConfirmation->setObjectName(QString::fromUtf8("btnPrintConfirmation"));

        gridLayout->addWidget(btnPrintConfirmation, 0, 0, 1, 1);

        btnClose = new QPushButton(DlgPrintReservation);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        gridLayout->addWidget(btnClose, 1, 1, 1, 1);

        btnPrintReservation = new QPushButton(DlgPrintReservation);
        btnPrintReservation->setObjectName(QString::fromUtf8("btnPrintReservation"));

        gridLayout->addWidget(btnPrintReservation, 0, 1, 1, 1);

        btnPrintRegistrationCard = new QPushButton(DlgPrintReservation);
        btnPrintRegistrationCard->setObjectName(QString::fromUtf8("btnPrintRegistrationCard"));

        gridLayout->addWidget(btnPrintRegistrationCard, 0, 2, 1, 1);


        retranslateUi(DlgPrintReservation);

        QMetaObject::connectSlotsByName(DlgPrintReservation);
    } // setupUi

    void retranslateUi(QDialog *DlgPrintReservation)
    {
        DlgPrintReservation->setWindowTitle(QCoreApplication::translate("DlgPrintReservation", "Print reservation", nullptr));
        btnPrintConfirmation->setText(QCoreApplication::translate("DlgPrintReservation", "Confirmation", nullptr));
        btnClose->setText(QCoreApplication::translate("DlgPrintReservation", "Close", nullptr));
        btnPrintReservation->setText(QCoreApplication::translate("DlgPrintReservation", "Reservation", nullptr));
        btnPrintRegistrationCard->setText(QCoreApplication::translate("DlgPrintReservation", "Registration Card", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgPrintReservation: public Ui_DlgPrintReservation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGPRINTRESERVATION_H
