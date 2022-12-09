/********************************************************************************
** Form generated from reading UI file 'rereststore.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RERESTSTORE_H
#define UI_RERESTSTORE_H

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

class Ui_RERestStore
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    EQLineEdit *leCode;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QLabel *label_2;
    EQLineEdit *leName;

    void setupUi(QDialog *RERestStore)
    {
        if (RERestStore->objectName().isEmpty())
            RERestStore->setObjectName(QString::fromUtf8("RERestStore"));
        RERestStore->resize(314, 113);
        verticalLayout = new QVBoxLayout(RERestStore);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leCode = new EQLineEdit(RERestStore);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setFocusPolicy(Qt::NoFocus);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        widget = new QWidget(RERestStore);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(51, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(51, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 2, 0, 1, 2);

        label = new QLabel(RERestStore);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(RERestStore);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leName = new EQLineEdit(RERestStore);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(RERestStore);

        QMetaObject::connectSlotsByName(RERestStore);
    } // setupUi

    void retranslateUi(QDialog *RERestStore)
    {
        RERestStore->setWindowTitle(QCoreApplication::translate("RERestStore", "Store", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("RERestStore", "f_id", nullptr)));
        btnOk->setText(QCoreApplication::translate("RERestStore", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("RERestStore", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("RERestStore", "Code", nullptr));
        label_2->setText(QCoreApplication::translate("RERestStore", "Name", nullptr));
        leName->setProperty("Field", QVariant(QCoreApplication::translate("RERestStore", "f_name", nullptr)));
    } // retranslateUi

};

namespace Ui {
    class RERestStore: public Ui_RERestStore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RERESTSTORE_H
