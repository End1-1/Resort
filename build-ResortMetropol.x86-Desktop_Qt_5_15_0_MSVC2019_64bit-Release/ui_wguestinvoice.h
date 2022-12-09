/********************************************************************************
** Form generated from reading UI file 'wguestinvoice.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGUESTINVOICE_H
#define UI_WGUESTINVOICE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_WGuestInvoice
{
public:
    QGridLayout *gridLayout;
    QLabel *label_6;
    EQLineEdit *leRoomName;
    QLabel *label_3;
    QLabel *label_9;
    QLabel *label_2;
    EQLineEdit *leInvoice;
    EQLineEdit *leGuest;
    EDateEdit *deDeparture;
    QLabel *label_4;
    EQLineEdit *leBalanceUSD;
    EDateEdit *deEntry;
    QLabel *label_8;
    EQLineEdit *leReserve;
    EQLineEdit *leBalance;
    QLabel *label_7;
    EQLineEdit *leRoom;
    QLabel *label;
    QLabel *label_5;
    QToolButton *btnOpenInvoice;

    void setupUi(QWidget *WGuestInvoice)
    {
        if (WGuestInvoice->objectName().isEmpty())
            WGuestInvoice->setObjectName(QString::fromUtf8("WGuestInvoice"));
        WGuestInvoice->resize(368, 142);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WGuestInvoice->sizePolicy().hasHeightForWidth());
        WGuestInvoice->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(WGuestInvoice);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        label_6 = new QLabel(WGuestInvoice);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        leRoomName = new EQLineEdit(WGuestInvoice);
        leRoomName->setObjectName(QString::fromUtf8("leRoomName"));
        leRoomName->setMinimumSize(QSize(100, 0));
        leRoomName->setMaximumSize(QSize(100, 16777215));
        leRoomName->setFocusPolicy(Qt::NoFocus);
        leRoomName->setReadOnly(true);

        gridLayout->addWidget(leRoomName, 0, 4, 1, 1);

        label_3 = new QLabel(WGuestInvoice);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        label_9 = new QLabel(WGuestInvoice);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 5, 3, 1, 1);

        label_2 = new QLabel(WGuestInvoice);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        leInvoice = new EQLineEdit(WGuestInvoice);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));
        leInvoice->setMinimumSize(QSize(100, 0));
        leInvoice->setMaximumSize(QSize(100, 16777215));
        leInvoice->setFocusPolicy(Qt::NoFocus);
        leInvoice->setReadOnly(true);

        gridLayout->addWidget(leInvoice, 2, 1, 1, 1);

        leGuest = new EQLineEdit(WGuestInvoice);
        leGuest->setObjectName(QString::fromUtf8("leGuest"));
        leGuest->setFocusPolicy(Qt::NoFocus);
        leGuest->setReadOnly(true);

        gridLayout->addWidget(leGuest, 1, 1, 1, 4);

        deDeparture = new EDateEdit(WGuestInvoice);
        deDeparture->setObjectName(QString::fromUtf8("deDeparture"));
        deDeparture->setMinimumSize(QSize(100, 0));
        deDeparture->setMaximumSize(QSize(100, 16777215));
        deDeparture->setFocusPolicy(Qt::NoFocus);
        deDeparture->setReadOnly(true);

        gridLayout->addWidget(deDeparture, 3, 4, 1, 1);

        label_4 = new QLabel(WGuestInvoice);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        leBalanceUSD = new EQLineEdit(WGuestInvoice);
        leBalanceUSD->setObjectName(QString::fromUtf8("leBalanceUSD"));
        leBalanceUSD->setMinimumSize(QSize(100, 0));
        leBalanceUSD->setMaximumSize(QSize(100, 16777215));
        leBalanceUSD->setFocusPolicy(Qt::NoFocus);
        leBalanceUSD->setReadOnly(true);

        gridLayout->addWidget(leBalanceUSD, 5, 4, 1, 1);

        deEntry = new EDateEdit(WGuestInvoice);
        deEntry->setObjectName(QString::fromUtf8("deEntry"));
        deEntry->setMinimumSize(QSize(100, 0));
        deEntry->setMaximumSize(QSize(100, 16777215));
        deEntry->setFocusPolicy(Qt::NoFocus);
        deEntry->setReadOnly(true);

        gridLayout->addWidget(deEntry, 3, 1, 1, 1);

        label_8 = new QLabel(WGuestInvoice);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        leReserve = new EQLineEdit(WGuestInvoice);
        leReserve->setObjectName(QString::fromUtf8("leReserve"));
        leReserve->setMinimumSize(QSize(100, 0));
        leReserve->setMaximumSize(QSize(100, 16777215));
        leReserve->setFocusPolicy(Qt::NoFocus);
        leReserve->setReadOnly(true);

        gridLayout->addWidget(leReserve, 2, 4, 1, 1);

        leBalance = new EQLineEdit(WGuestInvoice);
        leBalance->setObjectName(QString::fromUtf8("leBalance"));
        leBalance->setMinimumSize(QSize(100, 0));
        leBalance->setMaximumSize(QSize(100, 16777215));
        leBalance->setFocusPolicy(Qt::NoFocus);
        leBalance->setReadOnly(true);

        gridLayout->addWidget(leBalance, 5, 1, 1, 1);

        label_7 = new QLabel(WGuestInvoice);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 3, 3, 1, 1);

        leRoom = new EQLineEdit(WGuestInvoice);
        leRoom->setObjectName(QString::fromUtf8("leRoom"));
        leRoom->setMinimumSize(QSize(100, 0));
        leRoom->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(leRoom, 0, 1, 1, 1);

        label = new QLabel(WGuestInvoice);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_5 = new QLabel(WGuestInvoice);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 3, 1, 1);

        btnOpenInvoice = new QToolButton(WGuestInvoice);
        btnOpenInvoice->setObjectName(QString::fromUtf8("btnOpenInvoice"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/goto.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnOpenInvoice->setIcon(icon);

        gridLayout->addWidget(btnOpenInvoice, 2, 2, 1, 1);


        retranslateUi(WGuestInvoice);

        QMetaObject::connectSlotsByName(WGuestInvoice);
    } // setupUi

    void retranslateUi(QWidget *WGuestInvoice)
    {
        WGuestInvoice->setWindowTitle(QCoreApplication::translate("WGuestInvoice", "Form", nullptr));
        label_6->setText(QCoreApplication::translate("WGuestInvoice", "Entry", nullptr));
        label_3->setText(QCoreApplication::translate("WGuestInvoice", "Category", nullptr));
        label_9->setText(QCoreApplication::translate("WGuestInvoice", "Balance, USD", nullptr));
        label_2->setText(QCoreApplication::translate("WGuestInvoice", "Room", nullptr));
        label_4->setText(QCoreApplication::translate("WGuestInvoice", "Invoice", nullptr));
        label_8->setText(QCoreApplication::translate("WGuestInvoice", "Balance", nullptr));
        label_7->setText(QCoreApplication::translate("WGuestInvoice", "Departure", nullptr));
        label->setText(QCoreApplication::translate("WGuestInvoice", "Guest", nullptr));
        label_5->setText(QCoreApplication::translate("WGuestInvoice", "Reserve", nullptr));
        btnOpenInvoice->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WGuestInvoice: public Ui_WGuestInvoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGUESTINVOICE_H
