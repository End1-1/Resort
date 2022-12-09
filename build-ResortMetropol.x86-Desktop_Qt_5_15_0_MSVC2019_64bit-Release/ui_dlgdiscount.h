/********************************************************************************
** Form generated from reading UI file 'dlgdiscount.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGDISCOUNT_H
#define UI_DLGDISCOUNT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgDiscount
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    EQLineEdit *leRoomName;
    QLineEdit *leReservation;
    EQLineEdit *leInvoice;
    EQLineEdit *leFinalAmount;
    EQLineEdit *leType;
    EQLineEdit *leVaucher;
    QLabel *lbCityLedger;
    QLabel *label_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *rbGuest;
    QRadioButton *rbCityLedger;
    EDateEdit *deDate;
    QLabel *label_8;
    EQLineEdit *leRoomCode;
    QLabel *label_5;
    QLabel *lbGuest;
    QLabel *label_7;
    QLabel *label_9;
    EQLineEdit *leTypeCode;
    QLabel *label;
    QLabel *lbRoom;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *btnLog;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnPrint;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    EQLineEdit *leAmount;
    EQLineEdit *leCLName;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *gbGuest;
    QRadioButton *rbCompany;
    EQLineEdit *leCLCode;
    QLabel *label_6;
    EQLineEdit *leGuest;
    EQLineEdit *leValue;
    QPlainTextEdit *peRemarks;

    void setupUi(QDialog *DlgDiscount)
    {
        if (DlgDiscount->objectName().isEmpty())
            DlgDiscount->setObjectName(QString::fromUtf8("DlgDiscount"));
        DlgDiscount->resize(414, 409);
        verticalLayout = new QVBoxLayout(DlgDiscount);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leRoomName = new EQLineEdit(DlgDiscount);
        leRoomName->setObjectName(QString::fromUtf8("leRoomName"));
        leRoomName->setFocusPolicy(Qt::NoFocus);
        leRoomName->setReadOnly(true);

        gridLayout->addWidget(leRoomName, 3, 3, 1, 1);

        leReservation = new QLineEdit(DlgDiscount);
        leReservation->setObjectName(QString::fromUtf8("leReservation"));

        gridLayout->addWidget(leReservation, 1, 3, 1, 1);

        leInvoice = new EQLineEdit(DlgDiscount);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));
        leInvoice->setMaximumSize(QSize(222, 16777215));
        leInvoice->setReadOnly(true);

        gridLayout->addWidget(leInvoice, 2, 3, 1, 1);

        leFinalAmount = new EQLineEdit(DlgDiscount);
        leFinalAmount->setObjectName(QString::fromUtf8("leFinalAmount"));
        leFinalAmount->setMaximumSize(QSize(80, 16777215));
        leFinalAmount->setFocusPolicy(Qt::NoFocus);
        leFinalAmount->setReadOnly(true);

        gridLayout->addWidget(leFinalAmount, 9, 3, 1, 1);

        leType = new EQLineEdit(DlgDiscount);
        leType->setObjectName(QString::fromUtf8("leType"));
        leType->setReadOnly(true);

        gridLayout->addWidget(leType, 7, 2, 1, 2);

        leVaucher = new EQLineEdit(DlgDiscount);
        leVaucher->setObjectName(QString::fromUtf8("leVaucher"));
        leVaucher->setReadOnly(true);

        gridLayout->addWidget(leVaucher, 2, 1, 1, 1);

        lbCityLedger = new QLabel(DlgDiscount);
        lbCityLedger->setObjectName(QString::fromUtf8("lbCityLedger"));

        gridLayout->addWidget(lbCityLedger, 5, 0, 1, 1);

        label_3 = new QLabel(DlgDiscount);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        widget_2 = new QWidget(DlgDiscount);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        rbGuest = new QRadioButton(widget_2);
        rbGuest->setObjectName(QString::fromUtf8("rbGuest"));
        rbGuest->setChecked(true);

        horizontalLayout_4->addWidget(rbGuest);

        rbCityLedger = new QRadioButton(widget_2);
        rbCityLedger->setObjectName(QString::fromUtf8("rbCityLedger"));

        horizontalLayout_4->addWidget(rbCityLedger);


        gridLayout->addWidget(widget_2, 0, 0, 1, 4);

        deDate = new EDateEdit(DlgDiscount);
        deDate->setObjectName(QString::fromUtf8("deDate"));
        deDate->setReadOnly(true);

        gridLayout->addWidget(deDate, 1, 1, 1, 1);

        label_8 = new QLabel(DlgDiscount);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 7, 0, 1, 1);

        leRoomCode = new EQLineEdit(DlgDiscount);
        leRoomCode->setObjectName(QString::fromUtf8("leRoomCode"));
        leRoomCode->setMaximumSize(QSize(80, 16777215));
        leRoomCode->setFocusPolicy(Qt::NoFocus);
        leRoomCode->setReadOnly(false);

        gridLayout->addWidget(leRoomCode, 3, 1, 1, 1);

        label_5 = new QLabel(DlgDiscount);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 9, 0, 1, 1);

        lbGuest = new QLabel(DlgDiscount);
        lbGuest->setObjectName(QString::fromUtf8("lbGuest"));

        gridLayout->addWidget(lbGuest, 4, 0, 1, 1);

        label_7 = new QLabel(DlgDiscount);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 8, 0, 1, 1);

        label_9 = new QLabel(DlgDiscount);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 1, 0, 1, 1);

        leTypeCode = new EQLineEdit(DlgDiscount);
        leTypeCode->setObjectName(QString::fromUtf8("leTypeCode"));
        leTypeCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leTypeCode, 7, 1, 1, 1);

        label = new QLabel(DlgDiscount);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        lbRoom = new QLabel(DlgDiscount);
        lbRoom->setObjectName(QString::fromUtf8("lbRoom"));

        gridLayout->addWidget(lbRoom, 3, 0, 1, 1);

        widget = new QWidget(DlgDiscount);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 0));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnLog = new QToolButton(widget);
        btnLog->setObjectName(QString::fromUtf8("btnLog"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/tracking.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLog->setIcon(icon);

        horizontalLayout_2->addWidget(btnLog);

        horizontalSpacer = new QSpacerItem(94, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout_2->addWidget(btnOk);

        btnPrint = new QPushButton(widget);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));

        horizontalLayout_2->addWidget(btnPrint);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_2->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(94, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 12, 0, 1, 4);

        label_2 = new QLabel(DlgDiscount);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 2, 1, 1);

        leAmount = new EQLineEdit(DlgDiscount);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));
        leAmount->setMaximumSize(QSize(80, 16777215));
        leAmount->setFocusPolicy(Qt::NoFocus);
        leAmount->setReadOnly(true);

        gridLayout->addWidget(leAmount, 6, 1, 1, 1);

        leCLName = new EQLineEdit(DlgDiscount);
        leCLName->setObjectName(QString::fromUtf8("leCLName"));

        gridLayout->addWidget(leCLName, 5, 2, 1, 2);

        groupBox_2 = new QGroupBox(DlgDiscount);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        gbGuest = new QRadioButton(groupBox_2);
        gbGuest->setObjectName(QString::fromUtf8("gbGuest"));
        gbGuest->setChecked(true);

        horizontalLayout_3->addWidget(gbGuest);

        rbCompany = new QRadioButton(groupBox_2);
        rbCompany->setObjectName(QString::fromUtf8("rbCompany"));

        horizontalLayout_3->addWidget(rbCompany);


        gridLayout->addWidget(groupBox_2, 8, 1, 1, 3);

        leCLCode = new EQLineEdit(DlgDiscount);
        leCLCode->setObjectName(QString::fromUtf8("leCLCode"));
        leCLCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leCLCode, 5, 1, 1, 1);

        label_6 = new QLabel(DlgDiscount);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 9, 2, 1, 1);

        leGuest = new EQLineEdit(DlgDiscount);
        leGuest->setObjectName(QString::fromUtf8("leGuest"));
        leGuest->setFocusPolicy(Qt::NoFocus);
        leGuest->setReadOnly(true);

        gridLayout->addWidget(leGuest, 4, 1, 1, 3);

        leValue = new EQLineEdit(DlgDiscount);
        leValue->setObjectName(QString::fromUtf8("leValue"));
        leValue->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leValue, 9, 1, 1, 1);

        peRemarks = new QPlainTextEdit(DlgDiscount);
        peRemarks->setObjectName(QString::fromUtf8("peRemarks"));

        gridLayout->addWidget(peRemarks, 10, 0, 1, 4);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(DlgDiscount);

        QMetaObject::connectSlotsByName(DlgDiscount);
    } // setupUi

    void retranslateUi(QDialog *DlgDiscount)
    {
        DlgDiscount->setWindowTitle(QCoreApplication::translate("DlgDiscount", "Discount", nullptr));
        lbCityLedger->setText(QCoreApplication::translate("DlgDiscount", "CityLedger", nullptr));
        label_3->setText(QCoreApplication::translate("DlgDiscount", "Amount", nullptr));
        rbGuest->setText(QCoreApplication::translate("DlgDiscount", "Guest", nullptr));
        rbCityLedger->setText(QCoreApplication::translate("DlgDiscount", "City ledger", nullptr));
        label_8->setText(QCoreApplication::translate("DlgDiscount", "Type", nullptr));
        label_5->setText(QCoreApplication::translate("DlgDiscount", "Discount amount", nullptr));
        lbGuest->setText(QCoreApplication::translate("DlgDiscount", "Guest", nullptr));
        label_7->setText(QCoreApplication::translate("DlgDiscount", "Discount for", nullptr));
        label_9->setText(QCoreApplication::translate("DlgDiscount", "Date", nullptr));
        label->setText(QCoreApplication::translate("DlgDiscount", "Voucher", nullptr));
        lbRoom->setText(QCoreApplication::translate("DlgDiscount", "Room", nullptr));
        btnLog->setText(QString());
        btnOk->setText(QCoreApplication::translate("DlgDiscount", "OK", nullptr));
        btnPrint->setText(QCoreApplication::translate("DlgDiscount", "Print", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgDiscount", "Cancel", nullptr));
        label_2->setText(QCoreApplication::translate("DlgDiscount", "Invoice", nullptr));
        groupBox_2->setTitle(QString());
        gbGuest->setText(QCoreApplication::translate("DlgDiscount", "Guest", nullptr));
        rbCompany->setText(QCoreApplication::translate("DlgDiscount", "Company", nullptr));
        label_6->setText(QCoreApplication::translate("DlgDiscount", "Final amount", nullptr));
        peRemarks->setPlaceholderText(QCoreApplication::translate("DlgDiscount", "Remarks", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgDiscount: public Ui_DlgDiscount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGDISCOUNT_H
