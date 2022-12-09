/********************************************************************************
** Form generated from reading UI file 'dlgcl.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCL_H
#define UI_DLGCL_H

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

class Ui_DlgCL
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    EQLineEdit *leCode;
    QLabel *label_2;
    EQLineEdit *leName;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgCL)
    {
        if (DlgCL->objectName().isEmpty())
            DlgCL->setObjectName(QString::fromUtf8("DlgCL"));
        DlgCL->resize(528, 85);
        gridLayout = new QGridLayout(DlgCL);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DlgCL);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leCode = new EQLineEdit(DlgCL);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        label_2 = new QLabel(DlgCL);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        leName = new EQLineEdit(DlgCL);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 0, 3, 1, 1);

        widget = new QWidget(DlgCL);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(159, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(159, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 1, 0, 1, 4);


        retranslateUi(DlgCL);

        QMetaObject::connectSlotsByName(DlgCL);
    } // setupUi

    void retranslateUi(QDialog *DlgCL)
    {
        DlgCL->setWindowTitle(QCoreApplication::translate("DlgCL", "Select City Ledger", nullptr));
        label->setText(QCoreApplication::translate("DlgCL", "Code", nullptr));
        label_2->setText(QCoreApplication::translate("DlgCL", "Name", nullptr));
        btnOk->setText(QCoreApplication::translate("DlgCL", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgCL", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgCL: public Ui_DlgCL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCL_H
