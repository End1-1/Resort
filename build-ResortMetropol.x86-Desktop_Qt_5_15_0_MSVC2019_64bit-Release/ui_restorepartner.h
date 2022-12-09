/********************************************************************************
** Form generated from reading UI file 'restorepartner.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESTOREPARTNER_H
#define UI_RESTOREPARTNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_REStorePartner
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    EQLineEdit *leCode;
    QLabel *label_2;
    EQLineEdit *leTaxCode;
    QLabel *label_3;
    EQLineEdit *leName;
    QLabel *label_4;
    EQLineEdit *lePhone;
    QLabel *label_5;
    EQLineEdit *leComments;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *REStorePartner)
    {
        if (REStorePartner->objectName().isEmpty())
            REStorePartner->setObjectName(QString::fromUtf8("REStorePartner"));
        REStorePartner->resize(400, 189);
        gridLayout = new QGridLayout(REStorePartner);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(REStorePartner);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leCode = new EQLineEdit(REStorePartner);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setFocusPolicy(Qt::NoFocus);
        leCode->setReadOnly(true);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        label_2 = new QLabel(REStorePartner);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leTaxCode = new EQLineEdit(REStorePartner);
        leTaxCode->setObjectName(QString::fromUtf8("leTaxCode"));

        gridLayout->addWidget(leTaxCode, 1, 1, 1, 1);

        label_3 = new QLabel(REStorePartner);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        leName = new EQLineEdit(REStorePartner);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 2, 1, 1, 1);

        label_4 = new QLabel(REStorePartner);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lePhone = new EQLineEdit(REStorePartner);
        lePhone->setObjectName(QString::fromUtf8("lePhone"));

        gridLayout->addWidget(lePhone, 3, 1, 1, 1);

        label_5 = new QLabel(REStorePartner);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        leComments = new EQLineEdit(REStorePartner);
        leComments->setObjectName(QString::fromUtf8("leComments"));

        gridLayout->addWidget(leComments, 4, 1, 1, 1);

        widget = new QWidget(REStorePartner);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 5, 0, 1, 2);


        retranslateUi(REStorePartner);

        QMetaObject::connectSlotsByName(REStorePartner);
    } // setupUi

    void retranslateUi(QWidget *REStorePartner)
    {
        REStorePartner->setWindowTitle(QCoreApplication::translate("REStorePartner", "Partner", nullptr));
        label->setText(QCoreApplication::translate("REStorePartner", "Code", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("REStorePartner", "f_id", nullptr)));
        label_2->setText(QCoreApplication::translate("REStorePartner", "Tax code", nullptr));
        leTaxCode->setProperty("Field", QVariant(QCoreApplication::translate("REStorePartner", "f_taxcode", nullptr)));
        label_3->setText(QCoreApplication::translate("REStorePartner", "Name", nullptr));
        leName->setProperty("Field", QVariant(QCoreApplication::translate("REStorePartner", "f_name", nullptr)));
        label_4->setText(QCoreApplication::translate("REStorePartner", "Phone", nullptr));
        lePhone->setProperty("Field", QVariant(QCoreApplication::translate("REStorePartner", "f_phone", nullptr)));
        label_5->setText(QCoreApplication::translate("REStorePartner", "Comments", nullptr));
        leComments->setProperty("Field", QVariant(QCoreApplication::translate("REStorePartner", "f_comment", nullptr)));
        btnSave->setText(QCoreApplication::translate("REStorePartner", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("REStorePartner", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class REStorePartner: public Ui_REStorePartner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTOREPARTNER_H
