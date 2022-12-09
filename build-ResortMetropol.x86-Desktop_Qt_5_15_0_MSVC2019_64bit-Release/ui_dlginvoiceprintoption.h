/********************************************************************************
** Form generated from reading UI file 'dlginvoiceprintoption.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGINVOICEPRINTOPTION_H
#define UI_DLGINVOICEPRINTOPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgInvoicePrintOption
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *gb;
    QGridLayout *gridLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QLabel *label;
    QPushButton *pushButton;
    QComboBox *cbCurrency;
    QLabel *label_2;
    QComboBox *cbPrintMeal;
    QPushButton *pushButton_2;
    QPushButton *btnCancel;

    void setupUi(QDialog *DlgInvoicePrintOption)
    {
        if (DlgInvoicePrintOption->objectName().isEmpty())
            DlgInvoicePrintOption->setObjectName(QString::fromUtf8("DlgInvoicePrintOption"));
        DlgInvoicePrintOption->resize(403, 179);
        verticalLayout = new QVBoxLayout(DlgInvoicePrintOption);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gb = new QGroupBox(DlgInvoicePrintOption);
        gb->setObjectName(QString::fromUtf8("gb"));
        gridLayout = new QGridLayout(gb);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_4 = new QPushButton(gb);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 40));
        pushButton_4->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(pushButton_4, 1, 2, 1, 2);

        pushButton_3 = new QPushButton(gb);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 40));
        pushButton_3->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(pushButton_3, 1, 0, 1, 2);

        label = new QLabel(gb);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        pushButton = new QPushButton(gb);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 40));
        pushButton->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(pushButton, 0, 0, 1, 2);

        cbCurrency = new QComboBox(gb);
        cbCurrency->setObjectName(QString::fromUtf8("cbCurrency"));

        gridLayout->addWidget(cbCurrency, 2, 1, 1, 1);

        label_2 = new QLabel(gb);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 2, 1, 1);

        cbPrintMeal = new QComboBox(gb);
        cbPrintMeal->addItem(QString());
        cbPrintMeal->addItem(QString());
        cbPrintMeal->setObjectName(QString::fromUtf8("cbPrintMeal"));

        gridLayout->addWidget(cbPrintMeal, 2, 3, 1, 1);

        pushButton_2 = new QPushButton(gb);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 40));
        pushButton_2->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(pushButton_2, 0, 2, 1, 2);

        btnCancel = new QPushButton(gb);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(btnCancel, 3, 1, 1, 2);


        verticalLayout->addWidget(gb);


        retranslateUi(DlgInvoicePrintOption);

        cbPrintMeal->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DlgInvoicePrintOption);
    } // setupUi

    void retranslateUi(QDialog *DlgInvoicePrintOption)
    {
        DlgInvoicePrintOption->setWindowTitle(QCoreApplication::translate("DlgInvoicePrintOption", "Printing options", nullptr));
        gb->setTitle(QString());
        pushButton_4->setText(QCoreApplication::translate("DlgInvoicePrintOption", "Guest and company together", nullptr));
        pushButton_3->setText(QCoreApplication::translate("DlgInvoicePrintOption", "Guest and company separately", nullptr));
        label->setText(QCoreApplication::translate("DlgInvoicePrintOption", "Currency", nullptr));
        pushButton->setText(QCoreApplication::translate("DlgInvoicePrintOption", "Guest side", nullptr));
        label_2->setText(QCoreApplication::translate("DlgInvoicePrintOption", "Print meal plan", nullptr));
        cbPrintMeal->setItemText(0, QCoreApplication::translate("DlgInvoicePrintOption", "Yes", nullptr));
        cbPrintMeal->setItemText(1, QCoreApplication::translate("DlgInvoicePrintOption", "No", nullptr));

        pushButton_2->setText(QCoreApplication::translate("DlgInvoicePrintOption", "Company side", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgInvoicePrintOption", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgInvoicePrintOption: public Ui_DlgInvoicePrintOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGINVOICEPRINTOPTION_H
