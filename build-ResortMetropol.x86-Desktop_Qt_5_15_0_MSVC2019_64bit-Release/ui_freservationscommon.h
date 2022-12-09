/********************************************************************************
** Form generated from reading UI file 'freservationscommon.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRESERVATIONSCOMMON_H
#define UI_FRESERVATIONSCOMMON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_FReservationsCommon
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QRadioButton *rbArrival;
    QRadioButton *rbDeparture;
    QRadioButton *rbCreated;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_4;
    EQLineEdit *leState;
    QLabel *label_3;
    EQLineEdit *leRoom;
    QLabel *label_2;
    QLabel *label_7;
    EQLineEdit *leStatus;
    EQLineEdit *leCardex;
    EDateEdit *deStart;
    EDateEdit *deEnd;
    EQLineEdit *leGroupNum;
    QCheckBox *chOnlyWithCardex;
    EQLineEdit *leArrangement;
    QLabel *label_9;
    QCheckBox *chOnlyGroup;
    QLabel *label_10;
    EQLineEdit *leBooking;
    QCheckBox *chExtraBed;

    void setupUi(QWidget *FReservationsCommon)
    {
        if (FReservationsCommon->objectName().isEmpty())
            FReservationsCommon->setObjectName(QString::fromUtf8("FReservationsCommon"));
        FReservationsCommon->resize(826, 92);
        verticalLayout = new QVBoxLayout(FReservationsCommon);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 10, 1, 1);

        widget = new QWidget(FReservationsCommon);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout->addWidget(label_8);

        rbArrival = new QRadioButton(widget);
        rbArrival->setObjectName(QString::fromUtf8("rbArrival"));
        rbArrival->setFocusPolicy(Qt::ClickFocus);
        rbArrival->setChecked(true);

        horizontalLayout->addWidget(rbArrival);

        rbDeparture = new QRadioButton(widget);
        rbDeparture->setObjectName(QString::fromUtf8("rbDeparture"));
        rbDeparture->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(rbDeparture);

        rbCreated = new QRadioButton(widget);
        rbCreated->setObjectName(QString::fromUtf8("rbCreated"));

        horizontalLayout->addWidget(rbCreated);


        gridLayout->addWidget(widget, 1, 0, 1, 4);

        label = new QLabel(FReservationsCommon);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_6 = new QLabel(FReservationsCommon);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 6, 1, 1);

        label_5 = new QLabel(FReservationsCommon);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 4, 1, 1);

        label_4 = new QLabel(FReservationsCommon);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 6, 1, 1);

        leState = new EQLineEdit(FReservationsCommon);
        leState->setObjectName(QString::fromUtf8("leState"));
        leState->setFocusPolicy(Qt::ClickFocus);
        leState->setProperty("ShowButton", QVariant(true));
        leState->setProperty("EnableHiddenText", QVariant(true));

        gridLayout->addWidget(leState, 0, 5, 1, 1);

        label_3 = new QLabel(FReservationsCommon);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 4, 1, 1);

        leRoom = new EQLineEdit(FReservationsCommon);
        leRoom->setObjectName(QString::fromUtf8("leRoom"));
        leRoom->setFocusPolicy(Qt::ClickFocus);
        leRoom->setProperty("ShowButton", QVariant(true));
        leRoom->setProperty("EnableHiddenText", QVariant(true));

        gridLayout->addWidget(leRoom, 1, 5, 1, 1);

        label_2 = new QLabel(FReservationsCommon);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label_7 = new QLabel(FReservationsCommon);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        leStatus = new EQLineEdit(FReservationsCommon);
        leStatus->setObjectName(QString::fromUtf8("leStatus"));
        leStatus->setFocusPolicy(Qt::ClickFocus);
        leStatus->setProperty("ShowButton", QVariant(true));
        leStatus->setProperty("EnableHiddenText", QVariant(true));

        gridLayout->addWidget(leStatus, 0, 7, 1, 1);

        leCardex = new EQLineEdit(FReservationsCommon);
        leCardex->setObjectName(QString::fromUtf8("leCardex"));
        leCardex->setFocusPolicy(Qt::ClickFocus);
        leCardex->setProperty("ShowButton", QVariant(true));
        leCardex->setProperty("EnableHiddenText", QVariant(true));

        gridLayout->addWidget(leCardex, 2, 1, 1, 6);

        deStart = new EDateEdit(FReservationsCommon);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        gridLayout->addWidget(deStart, 0, 1, 1, 1);

        deEnd = new EDateEdit(FReservationsCommon);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        gridLayout->addWidget(deEnd, 0, 3, 1, 1);

        leGroupNum = new EQLineEdit(FReservationsCommon);
        leGroupNum->setObjectName(QString::fromUtf8("leGroupNum"));
        leGroupNum->setFocusPolicy(Qt::ClickFocus);
        leGroupNum->setProperty("EnableHiddenText", QVariant(true));

        gridLayout->addWidget(leGroupNum, 0, 9, 1, 1);

        chOnlyWithCardex = new QCheckBox(FReservationsCommon);
        chOnlyWithCardex->setObjectName(QString::fromUtf8("chOnlyWithCardex"));
        chOnlyWithCardex->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(chOnlyWithCardex, 2, 7, 1, 1);

        leArrangement = new EQLineEdit(FReservationsCommon);
        leArrangement->setObjectName(QString::fromUtf8("leArrangement"));
        leArrangement->setFocusPolicy(Qt::ClickFocus);
        leArrangement->setProperty("ShowButton", QVariant(true));
        leArrangement->setProperty("EnableHiddenText", QVariant(true));

        gridLayout->addWidget(leArrangement, 1, 7, 1, 1);

        label_9 = new QLabel(FReservationsCommon);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(label_9, 0, 8, 1, 1);

        chOnlyGroup = new QCheckBox(FReservationsCommon);
        chOnlyGroup->setObjectName(QString::fromUtf8("chOnlyGroup"));
        chOnlyGroup->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(chOnlyGroup, 1, 9, 1, 1);

        label_10 = new QLabel(FReservationsCommon);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 2, 8, 1, 1);

        leBooking = new EQLineEdit(FReservationsCommon);
        leBooking->setObjectName(QString::fromUtf8("leBooking"));
        leBooking->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(leBooking, 2, 9, 1, 1);

        chExtraBed = new QCheckBox(FReservationsCommon);
        chExtraBed->setObjectName(QString::fromUtf8("chExtraBed"));

        gridLayout->addWidget(chExtraBed, 1, 8, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(FReservationsCommon);

        QMetaObject::connectSlotsByName(FReservationsCommon);
    } // setupUi

    void retranslateUi(QWidget *FReservationsCommon)
    {
        FReservationsCommon->setWindowTitle(QCoreApplication::translate("FReservationsCommon", "Form", nullptr));
        label_8->setText(QCoreApplication::translate("FReservationsCommon", "Search by", nullptr));
        rbArrival->setText(QCoreApplication::translate("FReservationsCommon", "Arrival", nullptr));
        rbDeparture->setText(QCoreApplication::translate("FReservationsCommon", "Departure", nullptr));
        rbCreated->setText(QCoreApplication::translate("FReservationsCommon", "Created", nullptr));
        label->setText(QCoreApplication::translate("FReservationsCommon", "Arrival starting", nullptr));
        label_6->setText(QCoreApplication::translate("FReservationsCommon", "Arrangement", nullptr));
        label_5->setText(QCoreApplication::translate("FReservationsCommon", "Room", nullptr));
        label_4->setText(QCoreApplication::translate("FReservationsCommon", "Status", nullptr));
        label_3->setText(QCoreApplication::translate("FReservationsCommon", "State", nullptr));
        label_2->setText(QCoreApplication::translate("FReservationsCommon", "Ending", nullptr));
        label_7->setText(QCoreApplication::translate("FReservationsCommon", "Cardex", nullptr));
        chOnlyWithCardex->setText(QCoreApplication::translate("FReservationsCommon", "With cardex only", nullptr));
        label_9->setText(QCoreApplication::translate("FReservationsCommon", "Group #", nullptr));
        chOnlyGroup->setText(QCoreApplication::translate("FReservationsCommon", "Groups only", nullptr));
        label_10->setText(QCoreApplication::translate("FReservationsCommon", "Booking", nullptr));
        chExtraBed->setText(QCoreApplication::translate("FReservationsCommon", "Extra bed", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FReservationsCommon: public Ui_FReservationsCommon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRESERVATIONSCOMMON_H
