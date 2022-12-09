/********************************************************************************
** Form generated from reading UI file 'recreditcard.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECREDITCARD_H
#define UI_RECREDITCARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_RECreditCard
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    EQLineEdit *leCode;
    EQLineEdit *leName;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *RECreditCard)
    {
        if (RECreditCard->objectName().isEmpty())
            RECreditCard->setObjectName(QString::fromUtf8("RECreditCard"));
        RECreditCard->resize(256, 113);
        horizontalLayout_2 = new QHBoxLayout(RECreditCard);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(RECreditCard);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        leCode = new EQLineEdit(RECreditCard);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setFocusPolicy(Qt::NoFocus);
        leCode->setReadOnly(true);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        leName = new EQLineEdit(RECreditCard);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 1, 1, 1, 1);

        label = new QLabel(RECreditCard);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        widget = new QWidget(RECreditCard);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(22, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(22, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 2, 0, 1, 2);


        horizontalLayout_2->addLayout(gridLayout);


        retranslateUi(RECreditCard);

        QMetaObject::connectSlotsByName(RECreditCard);
    } // setupUi

    void retranslateUi(QDialog *RECreditCard)
    {
        RECreditCard->setWindowTitle(QCoreApplication::translate("RECreditCard", "Credit card", nullptr));
        label_2->setText(QCoreApplication::translate("RECreditCard", "Code", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("RECreditCard", "f_id", nullptr)));
        leName->setProperty("Field", QVariant(QCoreApplication::translate("RECreditCard", "f_name", nullptr)));
        label->setText(QCoreApplication::translate("RECreditCard", "Name", nullptr));
        btnOk->setText(QCoreApplication::translate("RECreditCard", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("RECreditCard", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RECreditCard: public Ui_RECreditCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECREDITCARD_H
