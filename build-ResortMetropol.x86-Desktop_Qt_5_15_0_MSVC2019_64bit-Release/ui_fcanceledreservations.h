/********************************************************************************
** Form generated from reading UI file 'fcanceledreservations.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCANCELEDRESERVATIONS_H
#define UI_FCANCELEDRESERVATIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_FCanceledReservations
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EDateEdit *deStart;
    QLabel *label_2;
    EDateEdit *deEnd;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QRadioButton *rbCancel;
    QRadioButton *rbEntry;
    QRadioButton *rbDeparture;

    void setupUi(QWidget *FCanceledReservations)
    {
        if (FCanceledReservations->objectName().isEmpty())
            FCanceledReservations->setObjectName(QString::fromUtf8("FCanceledReservations"));
        FCanceledReservations->resize(723, 41);
        horizontalLayout = new QHBoxLayout(FCanceledReservations);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FCanceledReservations);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        deStart = new EDateEdit(FCanceledReservations);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        horizontalLayout->addWidget(deStart);

        label_2 = new QLabel(FCanceledReservations);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        deEnd = new EDateEdit(FCanceledReservations);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        horizontalLayout->addWidget(deEnd);

        horizontalSpacer = new QSpacerItem(196, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(FCanceledReservations);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        rbCancel = new QRadioButton(FCanceledReservations);
        rbCancel->setObjectName(QString::fromUtf8("rbCancel"));
        rbCancel->setChecked(true);

        horizontalLayout->addWidget(rbCancel);

        rbEntry = new QRadioButton(FCanceledReservations);
        rbEntry->setObjectName(QString::fromUtf8("rbEntry"));

        horizontalLayout->addWidget(rbEntry);

        rbDeparture = new QRadioButton(FCanceledReservations);
        rbDeparture->setObjectName(QString::fromUtf8("rbDeparture"));

        horizontalLayout->addWidget(rbDeparture);


        retranslateUi(FCanceledReservations);

        QMetaObject::connectSlotsByName(FCanceledReservations);
    } // setupUi

    void retranslateUi(QWidget *FCanceledReservations)
    {
        FCanceledReservations->setWindowTitle(QCoreApplication::translate("FCanceledReservations", "Form", nullptr));
        label->setText(QCoreApplication::translate("FCanceledReservations", "Date from", nullptr));
        label_2->setText(QCoreApplication::translate("FCanceledReservations", "Date to", nullptr));
        label_3->setText(QCoreApplication::translate("FCanceledReservations", "Search by date of", nullptr));
        rbCancel->setText(QCoreApplication::translate("FCanceledReservations", "Cancel", nullptr));
        rbEntry->setText(QCoreApplication::translate("FCanceledReservations", "Entry", nullptr));
        rbDeparture->setText(QCoreApplication::translate("FCanceledReservations", "Departure", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FCanceledReservations: public Ui_FCanceledReservations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCANCELEDRESERVATIONS_H
