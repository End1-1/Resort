/********************************************************************************
** Form generated from reading UI file 'rerestprinter.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RERESTPRINTER_H
#define UI_RERESTPRINTER_H

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

class Ui_RERestPrinter
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    EQLineEdit *leCode;
    EQLineEdit *leName;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *RERestPrinter)
    {
        if (RERestPrinter->objectName().isEmpty())
            RERestPrinter->setObjectName(QString::fromUtf8("RERestPrinter"));
        RERestPrinter->resize(283, 113);
        horizontalLayout = new QHBoxLayout(RERestPrinter);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(RERestPrinter);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(RERestPrinter);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leCode = new EQLineEdit(RERestPrinter);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setFocusPolicy(Qt::NoFocus);
        leCode->setReadOnly(true);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        leName = new EQLineEdit(RERestPrinter);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 1, 1, 1, 1);

        widget = new QWidget(RERestPrinter);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(35, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout_2->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_2->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(36, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 2, 0, 1, 2);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(RERestPrinter);

        QMetaObject::connectSlotsByName(RERestPrinter);
    } // setupUi

    void retranslateUi(QDialog *RERestPrinter)
    {
        RERestPrinter->setWindowTitle(QCoreApplication::translate("RERestPrinter", "Printer", nullptr));
        label->setText(QCoreApplication::translate("RERestPrinter", "Code", nullptr));
        label_2->setText(QCoreApplication::translate("RERestPrinter", "Name", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("RERestPrinter", "f_id", nullptr)));
        leName->setProperty("Field", QVariant(QCoreApplication::translate("RERestPrinter", "f_name", nullptr)));
        btnOk->setText(QCoreApplication::translate("RERestPrinter", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("RERestPrinter", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RERestPrinter: public Ui_RERestPrinter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RERESTPRINTER_H
