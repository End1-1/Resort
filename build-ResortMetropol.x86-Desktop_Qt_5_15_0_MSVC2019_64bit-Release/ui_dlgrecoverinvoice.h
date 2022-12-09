/********************************************************************************
** Form generated from reading UI file 'dlgrecoverinvoice.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGRECOVERINVOICE_H
#define UI_DLGRECOVERINVOICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgRecoverInvoice
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    EQLineEdit *leInvoice;
    QPlainTextEdit *teLog;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnRecover;
    QPushButton *btnRecoverRestaurant;
    QPushButton *btnClose;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgRecoverInvoice)
    {
        if (DlgRecoverInvoice->objectName().isEmpty())
            DlgRecoverInvoice->setObjectName(QString::fromUtf8("DlgRecoverInvoice"));
        DlgRecoverInvoice->resize(400, 448);
        gridLayout = new QGridLayout(DlgRecoverInvoice);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DlgRecoverInvoice);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leInvoice = new EQLineEdit(DlgRecoverInvoice);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));

        gridLayout->addWidget(leInvoice, 0, 1, 1, 1);

        teLog = new QPlainTextEdit(DlgRecoverInvoice);
        teLog->setObjectName(QString::fromUtf8("teLog"));

        gridLayout->addWidget(teLog, 1, 0, 1, 2);

        widget = new QWidget(DlgRecoverInvoice);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(34, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnRecover = new QPushButton(widget);
        btnRecover->setObjectName(QString::fromUtf8("btnRecover"));

        horizontalLayout->addWidget(btnRecover);

        btnRecoverRestaurant = new QPushButton(widget);
        btnRecoverRestaurant->setObjectName(QString::fromUtf8("btnRecoverRestaurant"));

        horizontalLayout->addWidget(btnRecoverRestaurant);

        btnClose = new QPushButton(widget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        horizontalLayout->addWidget(btnClose);

        horizontalSpacer_2 = new QSpacerItem(34, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 2, 0, 1, 2);


        retranslateUi(DlgRecoverInvoice);

        QMetaObject::connectSlotsByName(DlgRecoverInvoice);
    } // setupUi

    void retranslateUi(QDialog *DlgRecoverInvoice)
    {
        DlgRecoverInvoice->setWindowTitle(QCoreApplication::translate("DlgRecoverInvoice", "Recover invoice", nullptr));
        label->setText(QCoreApplication::translate("DlgRecoverInvoice", "Invoice", nullptr));
        btnRecover->setText(QCoreApplication::translate("DlgRecoverInvoice", "Recover Invoice", nullptr));
        btnRecoverRestaurant->setText(QCoreApplication::translate("DlgRecoverInvoice", "Recover Restaurant", nullptr));
        btnClose->setText(QCoreApplication::translate("DlgRecoverInvoice", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgRecoverInvoice: public Ui_DlgRecoverInvoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGRECOVERINVOICE_H
