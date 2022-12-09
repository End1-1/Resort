/********************************************************************************
** Form generated from reading UI file 'dlgpartnerpayment.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGPARTNERPAYMENT_H
#define UI_DLGPARTNERPAYMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgPartnerPayment
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_3;
    QLineEdit *deDate;
    QLineEdit *lePartner;
    QLineEdit *leCode;
    QLabel *label_4;
    QLineEdit *lePartnerName;
    QLabel *label_2;
    QLineEdit *lineEdit_5;
    QLabel *label_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btncancel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    QLineEdit *leCash;
    QLineEdit *leCachName;

    void setupUi(QDialog *DlgPartnerPayment)
    {
        if (DlgPartnerPayment->objectName().isEmpty())
            DlgPartnerPayment->setObjectName(QString::fromUtf8("DlgPartnerPayment"));
        DlgPartnerPayment->resize(550, 215);
        gridLayout = new QGridLayout(DlgPartnerPayment);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DlgPartnerPayment);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(DlgPartnerPayment);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMaximumSize(QSize(80, 80));

        gridLayout->addWidget(comboBox, 4, 1, 1, 1);

        label_3 = new QLabel(DlgPartnerPayment);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        deDate = new QLineEdit(DlgPartnerPayment);
        deDate->setObjectName(QString::fromUtf8("deDate"));
        deDate->setMaximumSize(QSize(80, 80));

        gridLayout->addWidget(deDate, 1, 1, 1, 1);

        lePartner = new QLineEdit(DlgPartnerPayment);
        lePartner->setObjectName(QString::fromUtf8("lePartner"));
        lePartner->setMaximumSize(QSize(80, 80));

        gridLayout->addWidget(lePartner, 3, 1, 1, 1);

        leCode = new QLineEdit(DlgPartnerPayment);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setEnabled(false);
        leCode->setMaximumSize(QSize(80, 80));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        label_4 = new QLabel(DlgPartnerPayment);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        lePartnerName = new QLineEdit(DlgPartnerPayment);
        lePartnerName->setObjectName(QString::fromUtf8("lePartnerName"));
        lePartnerName->setEnabled(false);

        gridLayout->addWidget(lePartnerName, 3, 2, 1, 1);

        label_2 = new QLabel(DlgPartnerPayment);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_5 = new QLineEdit(DlgPartnerPayment);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setMaximumSize(QSize(80, 80));

        gridLayout->addWidget(lineEdit_5, 5, 1, 1, 1);

        label_5 = new QLabel(DlgPartnerPayment);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        widget = new QWidget(DlgPartnerPayment);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(170, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btncancel = new QPushButton(widget);
        btncancel->setObjectName(QString::fromUtf8("btncancel"));

        horizontalLayout->addWidget(btncancel);

        horizontalSpacer_2 = new QSpacerItem(170, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 6, 0, 1, 3);

        label_6 = new QLabel(DlgPartnerPayment);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        leCash = new QLineEdit(DlgPartnerPayment);
        leCash->setObjectName(QString::fromUtf8("leCash"));
        leCash->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leCash, 2, 1, 1, 1);

        leCachName = new QLineEdit(DlgPartnerPayment);
        leCachName->setObjectName(QString::fromUtf8("leCachName"));
        leCachName->setEnabled(false);

        gridLayout->addWidget(leCachName, 2, 2, 1, 1);


        retranslateUi(DlgPartnerPayment);

        QMetaObject::connectSlotsByName(DlgPartnerPayment);
    } // setupUi

    void retranslateUi(QDialog *DlgPartnerPayment)
    {
        DlgPartnerPayment->setWindowTitle(QCoreApplication::translate("DlgPartnerPayment", "Partner payment", nullptr));
        label->setText(QCoreApplication::translate("DlgPartnerPayment", "Code", nullptr));
        label_3->setText(QCoreApplication::translate("DlgPartnerPayment", "Partner", nullptr));
        label_4->setText(QCoreApplication::translate("DlgPartnerPayment", "Payment", nullptr));
        label_2->setText(QCoreApplication::translate("DlgPartnerPayment", "Date", nullptr));
        label_5->setText(QCoreApplication::translate("DlgPartnerPayment", "Amount", nullptr));
        btnOk->setText(QCoreApplication::translate("DlgPartnerPayment", "Save", nullptr));
        btncancel->setText(QCoreApplication::translate("DlgPartnerPayment", "Cancel", nullptr));
        label_6->setText(QCoreApplication::translate("DlgPartnerPayment", "Cashdesk", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgPartnerPayment: public Ui_DlgPartnerPayment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGPARTNERPAYMENT_H
