/********************************************************************************
** Form generated from reading UI file 'recityledger.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECITYLEDGER_H
#define UI_RECITYLEDGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <eqcheckbox.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_RECityLedger
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    EQLineEdit *leCode;
    EQLineEdit *leExtra2;
    EQLineEdit *leEmail;
    EQLineEdit *leName;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnInitialBalance;
    QPushButton *btnRemove;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QLabel *label_4;
    EQLineEdit *lePhone;
    QLabel *label_2;
    EQLineEdit *leAddress;
    EQLineEdit *leExtra1;
    QLabel *label_7;
    EQCheckBox *chAlwaysInvoice;
    QLabel *label_8;

    void setupUi(QDialog *RECityLedger)
    {
        if (RECityLedger->objectName().isEmpty())
            RECityLedger->setObjectName(QString::fromUtf8("RECityLedger"));
        RECityLedger->resize(446, 264);
        gridLayout = new QGridLayout(RECityLedger);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(RECityLedger);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_5 = new QLabel(RECityLedger);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_6 = new QLabel(RECityLedger);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        leCode = new EQLineEdit(RECityLedger);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setReadOnly(true);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        leExtra2 = new EQLineEdit(RECityLedger);
        leExtra2->setObjectName(QString::fromUtf8("leExtra2"));

        gridLayout->addWidget(leExtra2, 6, 1, 1, 1);

        leEmail = new EQLineEdit(RECityLedger);
        leEmail->setObjectName(QString::fromUtf8("leEmail"));

        gridLayout->addWidget(leEmail, 4, 1, 1, 1);

        leName = new EQLineEdit(RECityLedger);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 1, 1, 1, 1);

        widget = new QWidget(RECityLedger);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnInitialBalance = new QPushButton(widget);
        btnInitialBalance->setObjectName(QString::fromUtf8("btnInitialBalance"));

        horizontalLayout->addWidget(btnInitialBalance);

        btnRemove = new QPushButton(widget);
        btnRemove->setObjectName(QString::fromUtf8("btnRemove"));

        horizontalLayout->addWidget(btnRemove);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 8, 0, 1, 2);

        label = new QLabel(RECityLedger);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(RECityLedger);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lePhone = new EQLineEdit(RECityLedger);
        lePhone->setObjectName(QString::fromUtf8("lePhone"));

        gridLayout->addWidget(lePhone, 3, 1, 1, 1);

        label_2 = new QLabel(RECityLedger);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leAddress = new EQLineEdit(RECityLedger);
        leAddress->setObjectName(QString::fromUtf8("leAddress"));

        gridLayout->addWidget(leAddress, 2, 1, 1, 1);

        leExtra1 = new EQLineEdit(RECityLedger);
        leExtra1->setObjectName(QString::fromUtf8("leExtra1"));

        gridLayout->addWidget(leExtra1, 5, 1, 1, 1);

        label_7 = new QLabel(RECityLedger);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        chAlwaysInvoice = new EQCheckBox(RECityLedger);
        chAlwaysInvoice->setObjectName(QString::fromUtf8("chAlwaysInvoice"));

        gridLayout->addWidget(chAlwaysInvoice, 7, 1, 1, 1);

        label_8 = new QLabel(RECityLedger);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 7, 0, 1, 1);


        retranslateUi(RECityLedger);

        QMetaObject::connectSlotsByName(RECityLedger);
    } // setupUi

    void retranslateUi(QDialog *RECityLedger)
    {
        RECityLedger->setWindowTitle(QCoreApplication::translate("RECityLedger", "City ledger", nullptr));
        label_3->setText(QCoreApplication::translate("RECityLedger", "Address", nullptr));
        label_5->setText(QCoreApplication::translate("RECityLedger", "Email", nullptr));
        label_6->setText(QCoreApplication::translate("RECityLedger", "Extra1", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("RECityLedger", "f_id", nullptr)));
        leExtra2->setProperty("Field", QVariant(QCoreApplication::translate("RECityLedger", "f_extra2", nullptr)));
        leEmail->setProperty("Field", QVariant(QCoreApplication::translate("RECityLedger", "f_email", nullptr)));
        leName->setProperty("Field", QVariant(QCoreApplication::translate("RECityLedger", "f_name", nullptr)));
        btnInitialBalance->setText(QCoreApplication::translate("RECityLedger", "Initial balance", nullptr));
        btnRemove->setText(QCoreApplication::translate("RECityLedger", "Remove", nullptr));
        btnOk->setText(QCoreApplication::translate("RECityLedger", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("RECityLedger", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("RECityLedger", "Code", nullptr));
        label_4->setText(QCoreApplication::translate("RECityLedger", "Phone", nullptr));
        lePhone->setProperty("Field", QVariant(QCoreApplication::translate("RECityLedger", "f_phone", nullptr)));
        label_2->setText(QCoreApplication::translate("RECityLedger", "Name", nullptr));
        leAddress->setProperty("Field", QVariant(QCoreApplication::translate("RECityLedger", "f_address", nullptr)));
        leExtra1->setProperty("Field", QVariant(QCoreApplication::translate("RECityLedger", "f_extra1", nullptr)));
        label_7->setText(QCoreApplication::translate("RECityLedger", "Extra2", nullptr));
        chAlwaysInvoice->setText(QString());
        chAlwaysInvoice->setProperty("Field", QVariant(QCoreApplication::translate("RECityLedger", "f_alwaysinvoice", nullptr)));
        label_8->setText(QCoreApplication::translate("RECityLedger", "Always invoice", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RECityLedger: public Ui_RECityLedger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECITYLEDGER_H
