/********************************************************************************
** Form generated from reading UI file 'froomarrangement.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FROOMARRANGEMENT_H
#define UI_FROOMARRANGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <eqcheckbox.h>
#include <eyearcombo.h>

QT_BEGIN_NAMESPACE

class Ui_FRoomArrangement
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    EYearCombo *cbYear;
    EQCheckBox *ch1;
    EQCheckBox *ch2;
    EQCheckBox *ch3;
    EQCheckBox *ch4;
    EQCheckBox *ch5;
    EQCheckBox *ch6;
    EQCheckBox *ch7;
    EQCheckBox *ch8;
    EQCheckBox *ch9;
    EQCheckBox *ch10;
    EQCheckBox *ch11;
    EQCheckBox *ch12;

    void setupUi(QWidget *FRoomArrangement)
    {
        if (FRoomArrangement->objectName().isEmpty())
            FRoomArrangement->setObjectName(QString::fromUtf8("FRoomArrangement"));
        FRoomArrangement->resize(939, 61);
        gridLayout = new QGridLayout(FRoomArrangement);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(FRoomArrangement);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        cbYear = new EYearCombo(FRoomArrangement);
        cbYear->setObjectName(QString::fromUtf8("cbYear"));

        gridLayout->addWidget(cbYear, 0, 1, 1, 1);

        ch1 = new EQCheckBox(FRoomArrangement);
        ch1->setObjectName(QString::fromUtf8("ch1"));
        ch1->setProperty("Tag", QVariant(0));

        gridLayout->addWidget(ch1, 0, 2, 1, 1);

        ch2 = new EQCheckBox(FRoomArrangement);
        ch2->setObjectName(QString::fromUtf8("ch2"));
        ch2->setProperty("Tag", QVariant(0));

        gridLayout->addWidget(ch2, 0, 3, 1, 1);

        ch3 = new EQCheckBox(FRoomArrangement);
        ch3->setObjectName(QString::fromUtf8("ch3"));
        ch3->setProperty("Tag", QVariant(0));

        gridLayout->addWidget(ch3, 0, 4, 1, 1);

        ch4 = new EQCheckBox(FRoomArrangement);
        ch4->setObjectName(QString::fromUtf8("ch4"));
        ch4->setProperty("Tag", QVariant(0));

        gridLayout->addWidget(ch4, 0, 5, 1, 1);

        ch5 = new EQCheckBox(FRoomArrangement);
        ch5->setObjectName(QString::fromUtf8("ch5"));
        ch5->setProperty("Tag", QVariant(0));

        gridLayout->addWidget(ch5, 0, 6, 1, 1);

        ch6 = new EQCheckBox(FRoomArrangement);
        ch6->setObjectName(QString::fromUtf8("ch6"));
        ch6->setProperty("Tag", QVariant(0));

        gridLayout->addWidget(ch6, 0, 7, 1, 1);

        ch7 = new EQCheckBox(FRoomArrangement);
        ch7->setObjectName(QString::fromUtf8("ch7"));
        ch7->setProperty("Tag", QVariant(0));

        gridLayout->addWidget(ch7, 1, 2, 1, 1);

        ch8 = new EQCheckBox(FRoomArrangement);
        ch8->setObjectName(QString::fromUtf8("ch8"));
        ch8->setProperty("Tag", QVariant(0));

        gridLayout->addWidget(ch8, 1, 3, 1, 1);

        ch9 = new EQCheckBox(FRoomArrangement);
        ch9->setObjectName(QString::fromUtf8("ch9"));
        ch9->setProperty("Tag", QVariant(0));

        gridLayout->addWidget(ch9, 1, 4, 1, 1);

        ch10 = new EQCheckBox(FRoomArrangement);
        ch10->setObjectName(QString::fromUtf8("ch10"));
        ch10->setProperty("Tag", QVariant(0));

        gridLayout->addWidget(ch10, 1, 5, 1, 1);

        ch11 = new EQCheckBox(FRoomArrangement);
        ch11->setObjectName(QString::fromUtf8("ch11"));
        ch11->setProperty("Tag", QVariant(0));

        gridLayout->addWidget(ch11, 1, 6, 1, 1);

        ch12 = new EQCheckBox(FRoomArrangement);
        ch12->setObjectName(QString::fromUtf8("ch12"));
        ch12->setProperty("Tag", QVariant(0));

        gridLayout->addWidget(ch12, 1, 7, 1, 1);


        retranslateUi(FRoomArrangement);

        QMetaObject::connectSlotsByName(FRoomArrangement);
    } // setupUi

    void retranslateUi(QWidget *FRoomArrangement)
    {
        FRoomArrangement->setWindowTitle(QCoreApplication::translate("FRoomArrangement", "Form", nullptr));
        label->setText(QCoreApplication::translate("FRoomArrangement", "Year", nullptr));
        ch1->setText(QCoreApplication::translate("FRoomArrangement", "January", nullptr));
        ch2->setText(QCoreApplication::translate("FRoomArrangement", "February", nullptr));
        ch3->setText(QCoreApplication::translate("FRoomArrangement", "Mart", nullptr));
        ch4->setText(QCoreApplication::translate("FRoomArrangement", "April", nullptr));
        ch5->setText(QCoreApplication::translate("FRoomArrangement", "May", nullptr));
        ch6->setText(QCoreApplication::translate("FRoomArrangement", "June", nullptr));
        ch7->setText(QCoreApplication::translate("FRoomArrangement", "July", nullptr));
        ch8->setText(QCoreApplication::translate("FRoomArrangement", "August", nullptr));
        ch9->setText(QCoreApplication::translate("FRoomArrangement", "September", nullptr));
        ch10->setText(QCoreApplication::translate("FRoomArrangement", "October", nullptr));
        ch11->setText(QCoreApplication::translate("FRoomArrangement", "November", nullptr));
        ch12->setText(QCoreApplication::translate("FRoomArrangement", "December", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FRoomArrangement: public Ui_FRoomArrangement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FROOMARRANGEMENT_H
