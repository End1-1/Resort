/********************************************************************************
** Form generated from reading UI file 'dlgpostbreakfast.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGPOSTBREAKFAST_H
#define UI_DLGPOSTBREAKFAST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqdoubleedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgPostBreakfast
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout;
    EQLineEdit *lePMComment;
    QLabel *label;
    QLabel *label_2;
    EQLineEdit *leVoucher;
    QLabel *label_3;
    QLabel *label_7;
    EDateEdit *deDate;
    EQLineEdit *leInvoice;
    EQLineEdit *leRes;
    QLabel *label_5;
    QLabel *label_4;
    EQDoubleEdit *leQty;
    QLabel *label_6;
    QLabel *label_13;
    QLineEdit *leRoom;
    QLabel *label_8;
    EQLineEdit *leGuest;
    EQLineEdit *leHall;
    EQLineEdit *leDishName;
    QLabel *label_9;
    EQLineEdit *leDish;
    EQLineEdit *leTableName;
    EQLineEdit *leHallName;
    EQLineEdit *leTable;
    QLabel *label_12;
    EQLineEdit *lePMCode;
    QLabel *label_11;
    QLabel *label_14;
    EQDoubleEdit *leAmount;
    EQLineEdit *leTax;
    QLabel *label_10;
    QPushButton *btnPrintTax;
    EQLineEdit *lePrice;
    EQLineEdit *leStore;
    QLabel *lbCard;
    EQLineEdit *leCardCode;
    EQLineEdit *leCardName;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgPostBreakfast)
    {
        if (DlgPostBreakfast->objectName().isEmpty())
            DlgPostBreakfast->setObjectName(QString::fromUtf8("DlgPostBreakfast"));
        DlgPostBreakfast->resize(594, 412);
        verticalLayout = new QVBoxLayout(DlgPostBreakfast);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(DlgPostBreakfast);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lePMComment = new EQLineEdit(frame);
        lePMComment->setObjectName(QString::fromUtf8("lePMComment"));
        lePMComment->setEnabled(false);
        lePMComment->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(lePMComment, 9, 2, 1, 3);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        leVoucher = new EQLineEdit(frame);
        leVoucher->setObjectName(QString::fromUtf8("leVoucher"));
        leVoucher->setEnabled(false);
        leVoucher->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(leVoucher, 0, 1, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 5, 1, 1);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        deDate = new EDateEdit(frame);
        deDate->setObjectName(QString::fromUtf8("deDate"));

        gridLayout->addWidget(deDate, 1, 1, 1, 1);

        leInvoice = new EQLineEdit(frame);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));
        leInvoice->setEnabled(false);
        leInvoice->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(leInvoice, 0, 6, 1, 1);

        leRes = new EQLineEdit(frame);
        leRes->setObjectName(QString::fromUtf8("leRes"));
        leRes->setEnabled(false);
        leRes->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(leRes, 0, 4, 1, 1);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        leQty = new EQDoubleEdit(frame);
        leQty->setObjectName(QString::fromUtf8("leQty"));

        gridLayout->addWidget(leQty, 6, 1, 1, 1);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 7, 0, 1, 1);

        label_13 = new QLabel(frame);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 5, 0, 1, 1);

        leRoom = new QLineEdit(frame);
        leRoom->setObjectName(QString::fromUtf8("leRoom"));
        leRoom->setEnabled(false);
        leRoom->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(leRoom, 1, 4, 1, 1);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 1, 2, 1, 1);

        leGuest = new EQLineEdit(frame);
        leGuest->setObjectName(QString::fromUtf8("leGuest"));
        leGuest->setEnabled(false);
        leGuest->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(leGuest, 2, 1, 1, 6);

        leHall = new EQLineEdit(frame);
        leHall->setObjectName(QString::fromUtf8("leHall"));

        gridLayout->addWidget(leHall, 3, 1, 1, 1);

        leDishName = new EQLineEdit(frame);
        leDishName->setObjectName(QString::fromUtf8("leDishName"));
        leDishName->setEnabled(false);
        leDishName->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(leDishName, 5, 2, 1, 3);

        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 9, 0, 1, 1);

        leDish = new EQLineEdit(frame);
        leDish->setObjectName(QString::fromUtf8("leDish"));

        gridLayout->addWidget(leDish, 5, 1, 1, 1);

        leTableName = new EQLineEdit(frame);
        leTableName->setObjectName(QString::fromUtf8("leTableName"));
        leTableName->setEnabled(false);
        leTableName->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(leTableName, 4, 2, 1, 3);

        leHallName = new EQLineEdit(frame);
        leHallName->setObjectName(QString::fromUtf8("leHallName"));
        leHallName->setEnabled(false);
        leHallName->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(leHallName, 3, 2, 1, 3);

        leTable = new EQLineEdit(frame);
        leTable->setObjectName(QString::fromUtf8("leTable"));

        gridLayout->addWidget(leTable, 4, 1, 1, 1);

        label_12 = new QLabel(frame);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 4, 0, 1, 1);

        lePMCode = new EQLineEdit(frame);
        lePMCode->setObjectName(QString::fromUtf8("lePMCode"));

        gridLayout->addWidget(lePMCode, 9, 1, 1, 1);

        label_11 = new QLabel(frame);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 3, 0, 1, 1);

        label_14 = new QLabel(frame);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 6, 2, 1, 1);

        leAmount = new EQDoubleEdit(frame);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));
        leAmount->setEnabled(false);

        gridLayout->addWidget(leAmount, 7, 1, 1, 1);

        leTax = new EQLineEdit(frame);
        leTax->setObjectName(QString::fromUtf8("leTax"));
        leTax->setEnabled(false);
        leTax->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(leTax, 8, 1, 1, 1);

        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 8, 0, 1, 1);

        btnPrintTax = new QPushButton(frame);
        btnPrintTax->setObjectName(QString::fromUtf8("btnPrintTax"));

        gridLayout->addWidget(btnPrintTax, 8, 2, 1, 3);

        lePrice = new EQLineEdit(frame);
        lePrice->setObjectName(QString::fromUtf8("lePrice"));
        lePrice->setEnabled(false);
        lePrice->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(lePrice, 6, 4, 1, 1);

        leStore = new EQLineEdit(frame);
        leStore->setObjectName(QString::fromUtf8("leStore"));
        leStore->setEnabled(false);

        gridLayout->addWidget(leStore, 5, 5, 1, 2);

        lbCard = new QLabel(frame);
        lbCard->setObjectName(QString::fromUtf8("lbCard"));

        gridLayout->addWidget(lbCard, 10, 0, 1, 1);

        leCardCode = new EQLineEdit(frame);
        leCardCode->setObjectName(QString::fromUtf8("leCardCode"));

        gridLayout->addWidget(leCardCode, 10, 1, 1, 1);

        leCardName = new EQLineEdit(frame);
        leCardName->setObjectName(QString::fromUtf8("leCardName"));
        leCardName->setEnabled(false);

        gridLayout->addWidget(leCardName, 10, 2, 1, 3);


        verticalLayout->addWidget(frame);

        widget = new QWidget(DlgPostBreakfast);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(192, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(192, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        QWidget::setTabOrder(deDate, leHall);
        QWidget::setTabOrder(leHall, leTable);
        QWidget::setTabOrder(leTable, leDish);
        QWidget::setTabOrder(leDish, leQty);
        QWidget::setTabOrder(leQty, leAmount);
        QWidget::setTabOrder(leAmount, lePMCode);
        QWidget::setTabOrder(lePMCode, btnPrintTax);
        QWidget::setTabOrder(btnPrintTax, btnSave);
        QWidget::setTabOrder(btnSave, btnCancel);

        retranslateUi(DlgPostBreakfast);

        QMetaObject::connectSlotsByName(DlgPostBreakfast);
    } // setupUi

    void retranslateUi(QDialog *DlgPostBreakfast)
    {
        DlgPostBreakfast->setWindowTitle(QCoreApplication::translate("DlgPostBreakfast", "Breakfast", nullptr));
        label->setText(QCoreApplication::translate("DlgPostBreakfast", "Voucher", nullptr));
        label_2->setText(QCoreApplication::translate("DlgPostBreakfast", "Reservation", nullptr));
        label_3->setText(QCoreApplication::translate("DlgPostBreakfast", "Invoice", nullptr));
        label_7->setText(QCoreApplication::translate("DlgPostBreakfast", "Date", nullptr));
        label_5->setText(QCoreApplication::translate("DlgPostBreakfast", "Qty", nullptr));
        label_4->setText(QCoreApplication::translate("DlgPostBreakfast", "Guest", nullptr));
        label_6->setText(QCoreApplication::translate("DlgPostBreakfast", "Amount", nullptr));
        label_13->setText(QCoreApplication::translate("DlgPostBreakfast", "Dish", nullptr));
        label_8->setText(QCoreApplication::translate("DlgPostBreakfast", "Room", nullptr));
        label_9->setText(QCoreApplication::translate("DlgPostBreakfast", "Payment", nullptr));
        label_12->setText(QCoreApplication::translate("DlgPostBreakfast", "Table", nullptr));
        label_11->setText(QCoreApplication::translate("DlgPostBreakfast", "Hall", nullptr));
        label_14->setText(QCoreApplication::translate("DlgPostBreakfast", "Price", nullptr));
        label_10->setText(QCoreApplication::translate("DlgPostBreakfast", "Tax number", nullptr));
        btnPrintTax->setText(QCoreApplication::translate("DlgPostBreakfast", "Print Tax", nullptr));
        lbCard->setText(QCoreApplication::translate("DlgPostBreakfast", "Credit card", nullptr));
        btnSave->setText(QCoreApplication::translate("DlgPostBreakfast", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgPostBreakfast", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgPostBreakfast: public Ui_DlgPostBreakfast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGPOSTBREAKFAST_H
