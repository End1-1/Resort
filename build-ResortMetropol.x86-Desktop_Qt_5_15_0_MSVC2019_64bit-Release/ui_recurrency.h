/********************************************************************************
** Form generated from reading UI file 'recurrency.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECURRENCY_H
#define UI_RECURRENCY_H

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
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_RECurrency
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    EQLineEdit *leDescription;
    EQLineEdit *leRate;
    EQLineEdit *leShort;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    EQLineEdit *leCode;
    QLabel *label_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *RECurrency)
    {
        if (RECurrency->objectName().isEmpty())
            RECurrency->setObjectName(QString::fromUtf8("RECurrency"));
        RECurrency->resize(272, 165);
        verticalLayout = new QVBoxLayout(RECurrency);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leDescription = new EQLineEdit(RECurrency);
        leDescription->setObjectName(QString::fromUtf8("leDescription"));

        gridLayout->addWidget(leDescription, 2, 1, 1, 1);

        leRate = new EQLineEdit(RECurrency);
        leRate->setObjectName(QString::fromUtf8("leRate"));

        gridLayout->addWidget(leRate, 3, 1, 1, 1);

        leShort = new EQLineEdit(RECurrency);
        leShort->setObjectName(QString::fromUtf8("leShort"));

        gridLayout->addWidget(leShort, 1, 1, 1, 1);

        label_3 = new QLabel(RECurrency);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(RECurrency);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label = new QLabel(RECurrency);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leCode = new EQLineEdit(RECurrency);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setFocusPolicy(Qt::NoFocus);
        leCode->setReadOnly(true);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        label_2 = new QLabel(RECurrency);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        widget = new QWidget(RECurrency);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 4, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);

        QWidget::setTabOrder(leShort, leDescription);
        QWidget::setTabOrder(leDescription, leRate);
        QWidget::setTabOrder(leRate, btnOk);
        QWidget::setTabOrder(btnOk, btnCancel);

        retranslateUi(RECurrency);

        QMetaObject::connectSlotsByName(RECurrency);
    } // setupUi

    void retranslateUi(QDialog *RECurrency)
    {
        RECurrency->setWindowTitle(QCoreApplication::translate("RECurrency", "Currency", nullptr));
        leDescription->setProperty("Field", QVariant(QCoreApplication::translate("RECurrency", "f_name", nullptr)));
        leRate->setProperty("Field", QVariant(QCoreApplication::translate("RECurrency", "f_rate", nullptr)));
        leShort->setProperty("Field", QVariant(QCoreApplication::translate("RECurrency", "f_short", nullptr)));
        label_3->setText(QCoreApplication::translate("RECurrency", "Description", nullptr));
        label_4->setText(QCoreApplication::translate("RECurrency", "Current rate", nullptr));
        label->setText(QCoreApplication::translate("RECurrency", "Code", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("RECurrency", "f_id", nullptr)));
        label_2->setText(QCoreApplication::translate("RECurrency", "Short", nullptr));
        btnOk->setText(QCoreApplication::translate("RECurrency", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("RECurrency", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RECurrency: public Ui_RECurrency {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECURRENCY_H
