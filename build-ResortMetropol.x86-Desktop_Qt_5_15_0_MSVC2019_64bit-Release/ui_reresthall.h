/********************************************************************************
** Form generated from reading UI file 'reresthall.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RERESTHALL_H
#define UI_RERESTHALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqcheckbox.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_RERestHall
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    EQLineEdit *leServiceItem;
    QLabel *label_9;
    EQLineEdit *leItemId;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    EQLineEdit *leCode;
    QLabel *Code;
    EQLineEdit *leService;
    EQLineEdit *leNameAm;
    QLabel *label_2;
    EQLineEdit *leMenuCode;
    QLabel *label_3;
    EQLineEdit *leMenuName;
    QLabel *label_5;
    EQLineEdit *leReceiptPrinter;
    QLabel *label_7;
    QLabel *label_4;
    EQLineEdit *leNoVatDept;
    QLabel *label_6;
    EQLineEdit *leVATDept;
    EQCheckBox *chShowBanket;
    EQCheckBox *chShowHall;
    QLabel *label_8;
    EQLineEdit *lePrefix;

    void setupUi(QDialog *RERestHall)
    {
        if (RERestHall->objectName().isEmpty())
            RERestHall->setObjectName(QString::fromUtf8("RERestHall"));
        RERestHall->resize(410, 344);
        verticalLayout = new QVBoxLayout(RERestHall);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leServiceItem = new EQLineEdit(RERestHall);
        leServiceItem->setObjectName(QString::fromUtf8("leServiceItem"));

        gridLayout->addWidget(leServiceItem, 8, 1, 1, 1);

        label_9 = new QLabel(RERestHall);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 8, 0, 1, 1);

        leItemId = new EQLineEdit(RERestHall);
        leItemId->setObjectName(QString::fromUtf8("leItemId"));
        leItemId->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leItemId, 4, 1, 1, 1);

        label = new QLabel(RERestHall);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 4, 0, 1, 1);

        widget = new QWidget(RERestHall);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(99, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(99, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 12, 0, 1, 3);

        leCode = new EQLineEdit(RERestHall);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setFocusPolicy(Qt::NoFocus);
        leCode->setReadOnly(true);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 2);

        Code = new QLabel(RERestHall);
        Code->setObjectName(QString::fromUtf8("Code"));

        gridLayout->addWidget(Code, 0, 0, 1, 1);

        leService = new EQLineEdit(RERestHall);
        leService->setObjectName(QString::fromUtf8("leService"));

        gridLayout->addWidget(leService, 3, 1, 1, 2);

        leNameAm = new EQLineEdit(RERestHall);
        leNameAm->setObjectName(QString::fromUtf8("leNameAm"));

        gridLayout->addWidget(leNameAm, 1, 1, 1, 2);

        label_2 = new QLabel(RERestHall);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leMenuCode = new EQLineEdit(RERestHall);
        leMenuCode->setObjectName(QString::fromUtf8("leMenuCode"));
        leMenuCode->setMaximumSize(QSize(80, 16777215));
        leMenuCode->setProperty("ShowButton", QVariant(true));

        gridLayout->addWidget(leMenuCode, 2, 1, 1, 1);

        label_3 = new QLabel(RERestHall);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        leMenuName = new EQLineEdit(RERestHall);
        leMenuName->setObjectName(QString::fromUtf8("leMenuName"));
        leMenuName->setFocusPolicy(Qt::NoFocus);
        leMenuName->setReadOnly(true);

        gridLayout->addWidget(leMenuName, 2, 2, 1, 1);

        label_5 = new QLabel(RERestHall);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        leReceiptPrinter = new EQLineEdit(RERestHall);
        leReceiptPrinter->setObjectName(QString::fromUtf8("leReceiptPrinter"));

        gridLayout->addWidget(leReceiptPrinter, 5, 1, 1, 2);

        label_7 = new QLabel(RERestHall);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 7, 0, 1, 1);

        label_4 = new QLabel(RERestHall);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        leNoVatDept = new EQLineEdit(RERestHall);
        leNoVatDept->setObjectName(QString::fromUtf8("leNoVatDept"));

        gridLayout->addWidget(leNoVatDept, 7, 1, 1, 2);

        label_6 = new QLabel(RERestHall);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        leVATDept = new EQLineEdit(RERestHall);
        leVATDept->setObjectName(QString::fromUtf8("leVATDept"));

        gridLayout->addWidget(leVATDept, 6, 1, 1, 2);

        chShowBanket = new EQCheckBox(RERestHall);
        chShowBanket->setObjectName(QString::fromUtf8("chShowBanket"));
        chShowBanket->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(chShowBanket, 10, 1, 1, 1);

        chShowHall = new EQCheckBox(RERestHall);
        chShowHall->setObjectName(QString::fromUtf8("chShowHall"));
        chShowHall->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(chShowHall, 10, 2, 1, 1);

        label_8 = new QLabel(RERestHall);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 9, 0, 1, 1);

        lePrefix = new EQLineEdit(RERestHall);
        lePrefix->setObjectName(QString::fromUtf8("lePrefix"));

        gridLayout->addWidget(lePrefix, 9, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        QWidget::setTabOrder(leNameAm, leMenuCode);
        QWidget::setTabOrder(leMenuCode, leService);
        QWidget::setTabOrder(leService, leItemId);
        QWidget::setTabOrder(leItemId, leReceiptPrinter);
        QWidget::setTabOrder(leReceiptPrinter, btnOk);
        QWidget::setTabOrder(btnOk, btnCancel);
        QWidget::setTabOrder(btnCancel, leMenuName);

        retranslateUi(RERestHall);

        QMetaObject::connectSlotsByName(RERestHall);
    } // setupUi

    void retranslateUi(QDialog *RERestHall)
    {
        RERestHall->setWindowTitle(QCoreApplication::translate("RERestHall", "Hall", nullptr));
        leServiceItem->setProperty("Field", QVariant(QCoreApplication::translate("RERestHall", "f_serviceItem", nullptr)));
        label_9->setText(QCoreApplication::translate("RERestHall", "Service item", nullptr));
        leItemId->setProperty("Field", QVariant(QCoreApplication::translate("RERestHall", "f_itemForInvoice", nullptr)));
        label->setText(QCoreApplication::translate("RERestHall", "Item id (invoice)", nullptr));
        btnOk->setText(QCoreApplication::translate("RERestHall", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("RERestHall", "Cancel", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("RERestHall", "f_id", nullptr)));
        Code->setText(QCoreApplication::translate("RERestHall", "Code", nullptr));
        leService->setProperty("Field", QVariant(QCoreApplication::translate("RERestHall", "f_defaultSvc", nullptr)));
        leNameAm->setProperty("Field", QVariant(QCoreApplication::translate("RERestHall", "f_name", nullptr)));
        label_2->setText(QCoreApplication::translate("RERestHall", "Name", nullptr));
        leMenuCode->setProperty("Field", QVariant(QCoreApplication::translate("RERestHall", "f_defaultMenu", nullptr)));
        label_3->setText(QCoreApplication::translate("RERestHall", "Receipt Printer", nullptr));
        label_5->setText(QCoreApplication::translate("RERestHall", "Menu", nullptr));
        leReceiptPrinter->setProperty("Field", QVariant(QCoreApplication::translate("RERestHall", "f_receiptPrinter", nullptr)));
        label_7->setText(QCoreApplication::translate("RERestHall", "Tax print, no VAT dept", nullptr));
        label_4->setText(QCoreApplication::translate("RERestHall", "Tax print, VAT dept", nullptr));
        leNoVatDept->setProperty("Field", QVariant(QCoreApplication::translate("RERestHall", "f_noVatDept", nullptr)));
        label_6->setText(QCoreApplication::translate("RERestHall", "Service value", nullptr));
        leVATDept->setProperty("Field", QVariant(QCoreApplication::translate("RERestHall", "f_vatDept", nullptr)));
        chShowBanket->setText(QCoreApplication::translate("RERestHall", "Show in banket", nullptr));
        chShowBanket->setProperty("Field", QVariant(QCoreApplication::translate("RERestHall", "f_showBanket", nullptr)));
        chShowHall->setText(QCoreApplication::translate("RERestHall", "Show in hall", nullptr));
        chShowHall->setProperty("Field", QVariant(QCoreApplication::translate("RERestHall", "f_showHall", nullptr)));
        label_8->setText(QCoreApplication::translate("RERestHall", "Order prefix", nullptr));
        lePrefix->setProperty("Field", QVariant(QCoreApplication::translate("RERestHall", "f_prefix", nullptr)));
    } // retranslateUi

};

namespace Ui {
    class RERestHall: public Ui_RERestHall {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RERESTHALL_H
