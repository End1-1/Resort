/********************************************************************************
** Form generated from reading UI file 'dlgofferinvoiceextra.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGOFFERINVOICEEXTRA_H
#define UI_DLGOFFERINVOICEEXTRA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgOfferInvoiceExtra
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *btnExtraRooming;
    QPushButton *btnDayUse;
    QPushButton *btnLateCheckout;
    QPushButton *btnEarlyCheckin;
    QPushButton *btnCancel;

    void setupUi(QDialog *DlgOfferInvoiceExtra)
    {
        if (DlgOfferInvoiceExtra->objectName().isEmpty())
            DlgOfferInvoiceExtra->setObjectName(QString::fromUtf8("DlgOfferInvoiceExtra"));
        DlgOfferInvoiceExtra->resize(350, 242);
        DlgOfferInvoiceExtra->setMinimumSize(QSize(350, 0));
        verticalLayout = new QVBoxLayout(DlgOfferInvoiceExtra);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnExtraRooming = new QPushButton(DlgOfferInvoiceExtra);
        btnExtraRooming->setObjectName(QString::fromUtf8("btnExtraRooming"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnExtraRooming->sizePolicy().hasHeightForWidth());
        btnExtraRooming->setSizePolicy(sizePolicy);
        btnExtraRooming->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(btnExtraRooming);

        btnDayUse = new QPushButton(DlgOfferInvoiceExtra);
        btnDayUse->setObjectName(QString::fromUtf8("btnDayUse"));
        sizePolicy.setHeightForWidth(btnDayUse->sizePolicy().hasHeightForWidth());
        btnDayUse->setSizePolicy(sizePolicy);
        btnDayUse->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(btnDayUse);

        btnLateCheckout = new QPushButton(DlgOfferInvoiceExtra);
        btnLateCheckout->setObjectName(QString::fromUtf8("btnLateCheckout"));
        sizePolicy.setHeightForWidth(btnLateCheckout->sizePolicy().hasHeightForWidth());
        btnLateCheckout->setSizePolicy(sizePolicy);
        btnLateCheckout->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(btnLateCheckout);

        btnEarlyCheckin = new QPushButton(DlgOfferInvoiceExtra);
        btnEarlyCheckin->setObjectName(QString::fromUtf8("btnEarlyCheckin"));
        sizePolicy.setHeightForWidth(btnEarlyCheckin->sizePolicy().hasHeightForWidth());
        btnEarlyCheckin->setSizePolicy(sizePolicy);
        btnEarlyCheckin->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(btnEarlyCheckin);

        btnCancel = new QPushButton(DlgOfferInvoiceExtra);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        sizePolicy.setHeightForWidth(btnCancel->sizePolicy().hasHeightForWidth());
        btnCancel->setSizePolicy(sizePolicy);
        btnCancel->setMinimumSize(QSize(0, 40));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancel->setIcon(icon);

        verticalLayout->addWidget(btnCancel);


        retranslateUi(DlgOfferInvoiceExtra);

        QMetaObject::connectSlotsByName(DlgOfferInvoiceExtra);
    } // setupUi

    void retranslateUi(QDialog *DlgOfferInvoiceExtra)
    {
        DlgOfferInvoiceExtra->setWindowTitle(QCoreApplication::translate("DlgOfferInvoiceExtra", "Posting extra charges", nullptr));
        btnExtraRooming->setText(QCoreApplication::translate("DlgOfferInvoiceExtra", "EXTRA ROOMING", nullptr));
        btnDayUse->setText(QCoreApplication::translate("DlgOfferInvoiceExtra", "DAY USE", nullptr));
        btnLateCheckout->setText(QCoreApplication::translate("DlgOfferInvoiceExtra", "LATE CHECKOUT", nullptr));
        btnEarlyCheckin->setText(QCoreApplication::translate("DlgOfferInvoiceExtra", "EARLY CHECKIN", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgOfferInvoiceExtra", "CANCEL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgOfferInvoiceExtra: public Ui_DlgOfferInvoiceExtra {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGOFFERINVOICEEXTRA_H
