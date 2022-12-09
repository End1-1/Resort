/********************************************************************************
** Form generated from reading UI file 'dlgquickadvanceapply.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGQUICKADVANCEAPPLY_H
#define UI_DLGQUICKADVANCEAPPLY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgQuickAdvanceApply
{
public:
    QGridLayout *gridLayout;
    EQLineEdit *leGuest;
    QLabel *label_7;
    EQLineEdit *leCardTypeName;
    EQLineEdit *leRoom;
    QLabel *label_2;
    EQLineEdit *leVoucherType;
    EQLineEdit *leInvoice;
    EQLineEdit *leReserve;
    QLabel *label_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnApply;
    QPushButton *btnPrint;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    EQLineEdit *leType;
    QLabel *label_8;
    QLabel *label_5;
    EQLineEdit *leVoucher;
    EQLineEdit *leCardType;
    EQLineEdit *leAmount;
    QLabel *label_3;
    EQLineEdit *leVoucherTypeName;
    QLabel *label_6;
    EQLineEdit *leTypeName;
    QLabel *label;
    QLabel *label_9;
    QLineEdit *leRoomShort;
    QLabel *label_10;
    QLineEdit *leTax;

    void setupUi(QDialog *DlgQuickAdvanceApply)
    {
        if (DlgQuickAdvanceApply->objectName().isEmpty())
            DlgQuickAdvanceApply->setObjectName(QString::fromUtf8("DlgQuickAdvanceApply"));
        DlgQuickAdvanceApply->resize(484, 267);
        gridLayout = new QGridLayout(DlgQuickAdvanceApply);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leGuest = new EQLineEdit(DlgQuickAdvanceApply);
        leGuest->setObjectName(QString::fromUtf8("leGuest"));
        leGuest->setFocusPolicy(Qt::ClickFocus);
        leGuest->setReadOnly(true);

        gridLayout->addWidget(leGuest, 1, 1, 1, 3);

        label_7 = new QLabel(DlgQuickAdvanceApply);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 8, 0, 1, 1);

        leCardTypeName = new EQLineEdit(DlgQuickAdvanceApply);
        leCardTypeName->setObjectName(QString::fromUtf8("leCardTypeName"));
        leCardTypeName->setEnabled(false);
        leCardTypeName->setFocusPolicy(Qt::ClickFocus);
        leCardTypeName->setReadOnly(true);

        gridLayout->addWidget(leCardTypeName, 8, 2, 1, 2);

        leRoom = new EQLineEdit(DlgQuickAdvanceApply);
        leRoom->setObjectName(QString::fromUtf8("leRoom"));
        leRoom->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(leRoom, 0, 1, 1, 1);

        label_2 = new QLabel(DlgQuickAdvanceApply);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leVoucherType = new EQLineEdit(DlgQuickAdvanceApply);
        leVoucherType->setObjectName(QString::fromUtf8("leVoucherType"));
        leVoucherType->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(leVoucherType, 5, 1, 1, 1);

        leInvoice = new EQLineEdit(DlgQuickAdvanceApply);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));
        leInvoice->setMaximumSize(QSize(100, 16777215));
        leInvoice->setFocusPolicy(Qt::ClickFocus);
        leInvoice->setReadOnly(true);

        gridLayout->addWidget(leInvoice, 3, 1, 1, 1);

        leReserve = new EQLineEdit(DlgQuickAdvanceApply);
        leReserve->setObjectName(QString::fromUtf8("leReserve"));
        leReserve->setFocusPolicy(Qt::ClickFocus);
        leReserve->setReadOnly(true);

        gridLayout->addWidget(leReserve, 3, 3, 1, 1);

        label_4 = new QLabel(DlgQuickAdvanceApply);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 2, 1, 1);

        widget = new QWidget(DlgQuickAdvanceApply);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(97, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnApply = new QPushButton(widget);
        btnApply->setObjectName(QString::fromUtf8("btnApply"));

        horizontalLayout->addWidget(btnApply);

        btnPrint = new QPushButton(widget);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));
        btnPrint->setEnabled(false);

        horizontalLayout->addWidget(btnPrint);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(96, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 9, 0, 1, 4);

        leType = new EQLineEdit(DlgQuickAdvanceApply);
        leType->setObjectName(QString::fromUtf8("leType"));
        leType->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(leType, 6, 1, 1, 1);

        label_8 = new QLabel(DlgQuickAdvanceApply);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 6, 0, 1, 1);

        label_5 = new QLabel(DlgQuickAdvanceApply);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 7, 0, 1, 1);

        leVoucher = new EQLineEdit(DlgQuickAdvanceApply);
        leVoucher->setObjectName(QString::fromUtf8("leVoucher"));
        leVoucher->setMaximumSize(QSize(100, 16777215));
        leVoucher->setFocusPolicy(Qt::ClickFocus);
        leVoucher->setReadOnly(true);

        gridLayout->addWidget(leVoucher, 2, 1, 1, 1);

        leCardType = new EQLineEdit(DlgQuickAdvanceApply);
        leCardType->setObjectName(QString::fromUtf8("leCardType"));
        leCardType->setEnabled(false);
        leCardType->setMaximumSize(QSize(100, 16777215));
        leCardType->setReadOnly(false);

        gridLayout->addWidget(leCardType, 8, 1, 1, 1);

        leAmount = new EQLineEdit(DlgQuickAdvanceApply);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));
        leAmount->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(leAmount, 7, 1, 1, 1);

        label_3 = new QLabel(DlgQuickAdvanceApply);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        leVoucherTypeName = new EQLineEdit(DlgQuickAdvanceApply);
        leVoucherTypeName->setObjectName(QString::fromUtf8("leVoucherTypeName"));
        leVoucherTypeName->setFocusPolicy(Qt::ClickFocus);
        leVoucherTypeName->setReadOnly(true);

        gridLayout->addWidget(leVoucherTypeName, 5, 2, 1, 2);

        label_6 = new QLabel(DlgQuickAdvanceApply);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        leTypeName = new EQLineEdit(DlgQuickAdvanceApply);
        leTypeName->setObjectName(QString::fromUtf8("leTypeName"));
        leTypeName->setFocusPolicy(Qt::ClickFocus);
        leTypeName->setReadOnly(true);

        gridLayout->addWidget(leTypeName, 6, 2, 1, 2);

        label = new QLabel(DlgQuickAdvanceApply);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_9 = new QLabel(DlgQuickAdvanceApply);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 2, 0, 1, 1);

        leRoomShort = new QLineEdit(DlgQuickAdvanceApply);
        leRoomShort->setObjectName(QString::fromUtf8("leRoomShort"));
        leRoomShort->setFocusPolicy(Qt::ClickFocus);
        leRoomShort->setReadOnly(true);

        gridLayout->addWidget(leRoomShort, 0, 2, 1, 2);

        label_10 = new QLabel(DlgQuickAdvanceApply);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 2, 2, 1, 1);

        leTax = new QLineEdit(DlgQuickAdvanceApply);
        leTax->setObjectName(QString::fromUtf8("leTax"));
        leTax->setReadOnly(true);

        gridLayout->addWidget(leTax, 2, 3, 1, 1);

        QWidget::setTabOrder(leRoom, leVoucherType);
        QWidget::setTabOrder(leVoucherType, leType);
        QWidget::setTabOrder(leType, leAmount);
        QWidget::setTabOrder(leAmount, leCardType);
        QWidget::setTabOrder(leCardType, btnApply);
        QWidget::setTabOrder(btnApply, btnPrint);
        QWidget::setTabOrder(btnPrint, btnCancel);

        retranslateUi(DlgQuickAdvanceApply);

        QMetaObject::connectSlotsByName(DlgQuickAdvanceApply);
    } // setupUi

    void retranslateUi(QDialog *DlgQuickAdvanceApply)
    {
        DlgQuickAdvanceApply->setWindowTitle(QCoreApplication::translate("DlgQuickAdvanceApply", "Release temporary voucher", nullptr));
        label_7->setText(QCoreApplication::translate("DlgQuickAdvanceApply", "Card", nullptr));
        label_2->setText(QCoreApplication::translate("DlgQuickAdvanceApply", "Guest", nullptr));
        label_4->setText(QCoreApplication::translate("DlgQuickAdvanceApply", "Reserve", nullptr));
        btnApply->setText(QCoreApplication::translate("DlgQuickAdvanceApply", "Apply", nullptr));
        btnPrint->setText(QCoreApplication::translate("DlgQuickAdvanceApply", "Print", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgQuickAdvanceApply", "Cancel", nullptr));
        label_8->setText(QCoreApplication::translate("DlgQuickAdvanceApply", "Mode of payment", nullptr));
        label_5->setText(QCoreApplication::translate("DlgQuickAdvanceApply", "Amount", nullptr));
        label_3->setText(QCoreApplication::translate("DlgQuickAdvanceApply", "Invoice", nullptr));
        label_6->setText(QCoreApplication::translate("DlgQuickAdvanceApply", "Type of voucher", nullptr));
        label->setText(QCoreApplication::translate("DlgQuickAdvanceApply", "Room", nullptr));
        label_9->setText(QCoreApplication::translate("DlgQuickAdvanceApply", "Voucher", nullptr));
        label_10->setText(QCoreApplication::translate("DlgQuickAdvanceApply", "Tax", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgQuickAdvanceApply: public Ui_DlgQuickAdvanceApply {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGQUICKADVANCEAPPLY_H
