/********************************************************************************
** Form generated from reading UI file 'reroombed.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REROOMBED_H
#define UI_REROOMBED_H

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

class Ui_RERoomBed
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    EQLineEdit *leName;
    EQLineEdit *leCode;
    QLabel *label_2;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *RERoomBed)
    {
        if (RERoomBed->objectName().isEmpty())
            RERoomBed->setObjectName(QString::fromUtf8("RERoomBed"));
        RERoomBed->resize(251, 113);
        horizontalLayout = new QHBoxLayout(RERoomBed);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leName = new EQLineEdit(RERoomBed);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 1, 1, 1, 1);

        leCode = new EQLineEdit(RERoomBed);
        leCode->setObjectName(QString::fromUtf8("leCode"));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        label_2 = new QLabel(RERoomBed);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(RERoomBed);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        widget = new QWidget(RERoomBed);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(19, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout_2->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_2->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 2, 0, 1, 2);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(RERoomBed);

        QMetaObject::connectSlotsByName(RERoomBed);
    } // setupUi

    void retranslateUi(QDialog *RERoomBed)
    {
        RERoomBed->setWindowTitle(QCoreApplication::translate("RERoomBed", "Type of bed", nullptr));
        label_2->setText(QCoreApplication::translate("RERoomBed", "Name", nullptr));
        label->setText(QCoreApplication::translate("RERoomBed", "Code", nullptr));
        btnOk->setText(QCoreApplication::translate("RERoomBed", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("RERoomBed", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RERoomBed: public Ui_RERoomBed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REROOMBED_H
