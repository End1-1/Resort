/********************************************************************************
** Form generated from reading UI file 'finhouseguest.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINHOUSEGUEST_H
#define UI_FINHOUSEGUEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqcheckbox.h>
#include <wcardex.h>

QT_BEGIN_NAMESPACE

class Ui_FInHouseGuest
{
public:
    QHBoxLayout *horizontalLayout;
    EQCheckBox *chDisplayRate;
    EQCheckBox *chDisplayCardex;
    EQCheckBox *chDisplayName;
    EQCheckBox *chAll;
    QSpacerItem *horizontalSpacer_2;
    WCardex *wCardex;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;
    EDateEdit *deDate;
    QCheckBox *chDate;
    QTimeEdit *teTime;
    QCheckBox *chTime;

    void setupUi(QWidget *FInHouseGuest)
    {
        if (FInHouseGuest->objectName().isEmpty())
            FInHouseGuest->setObjectName(QString::fromUtf8("FInHouseGuest"));
        FInHouseGuest->resize(858, 41);
        horizontalLayout = new QHBoxLayout(FInHouseGuest);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        chDisplayRate = new EQCheckBox(FInHouseGuest);
        chDisplayRate->setObjectName(QString::fromUtf8("chDisplayRate"));
        chDisplayRate->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(chDisplayRate);

        chDisplayCardex = new EQCheckBox(FInHouseGuest);
        chDisplayCardex->setObjectName(QString::fromUtf8("chDisplayCardex"));
        chDisplayCardex->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(chDisplayCardex);

        chDisplayName = new EQCheckBox(FInHouseGuest);
        chDisplayName->setObjectName(QString::fromUtf8("chDisplayName"));
        chDisplayName->setFocusPolicy(Qt::ClickFocus);
        chDisplayName->setChecked(false);

        horizontalLayout->addWidget(chDisplayName);

        chAll = new EQCheckBox(FInHouseGuest);
        chAll->setObjectName(QString::fromUtf8("chAll"));
        chAll->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(chAll);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        wCardex = new WCardex(FInHouseGuest);
        wCardex->setObjectName(QString::fromUtf8("wCardex"));

        horizontalLayout->addWidget(wCardex);

        horizontalSpacer = new QSpacerItem(2, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        deDate = new EDateEdit(FInHouseGuest);
        deDate->setObjectName(QString::fromUtf8("deDate"));
        deDate->setEnabled(false);

        horizontalLayout->addWidget(deDate);

        chDate = new QCheckBox(FInHouseGuest);
        chDate->setObjectName(QString::fromUtf8("chDate"));

        horizontalLayout->addWidget(chDate);

        teTime = new QTimeEdit(FInHouseGuest);
        teTime->setObjectName(QString::fromUtf8("teTime"));
        teTime->setEnabled(false);

        horizontalLayout->addWidget(teTime);

        chTime = new QCheckBox(FInHouseGuest);
        chTime->setObjectName(QString::fromUtf8("chTime"));

        horizontalLayout->addWidget(chTime);


        retranslateUi(FInHouseGuest);
        QObject::connect(chDisplayRate, SIGNAL(clicked(bool)), FInHouseGuest, SLOT(groupCheckClicked(bool)));
        QObject::connect(chDisplayName, SIGNAL(clicked(bool)), FInHouseGuest, SLOT(groupCheckClicked(bool)));
        QObject::connect(chDisplayCardex, SIGNAL(clicked(bool)), FInHouseGuest, SLOT(groupCheckClicked(bool)));
        QObject::connect(chAll, SIGNAL(clicked(bool)), FInHouseGuest, SLOT(groupCheckClicked(bool)));

        QMetaObject::connectSlotsByName(FInHouseGuest);
    } // setupUi

    void retranslateUi(QWidget *FInHouseGuest)
    {
        FInHouseGuest->setWindowTitle(QCoreApplication::translate("FInHouseGuest", "Form", nullptr));
        chDisplayRate->setText(QCoreApplication::translate("FInHouseGuest", "Display rate", nullptr));
        chDisplayRate->setProperty("Field", QVariant(QCoreApplication::translate("FInHouseGuest", "r.f_pricePerNight", nullptr)));
        chDisplayCardex->setText(QCoreApplication::translate("FInHouseGuest", "Display cardex", nullptr));
        chDisplayCardex->setProperty("Field", QVariant(QCoreApplication::translate("FInHouseGuest", "cx.f_name", nullptr)));
        chDisplayName->setText(QCoreApplication::translate("FInHouseGuest", "Display name", nullptr));
        chDisplayName->setProperty("Field", QVariant(QCoreApplication::translate("FInHouseGuest", "concat(g.f_title, ' ', g.f_firstName, ' ', g.f_lastName)", nullptr)));
        chAll->setText(QCoreApplication::translate("FInHouseGuest", "All", nullptr));
        chAll->setProperty("Field", QVariant(QCoreApplication::translate("FInHouseGuest", "r.f_extraBedFee;r.f_mealPrice;v.f_vat", nullptr)));
        chDate->setText(QCoreApplication::translate("FInHouseGuest", "Search by date", nullptr));
        teTime->setDisplayFormat(QCoreApplication::translate("FInHouseGuest", "HH:mm", nullptr));
        chTime->setText(QCoreApplication::translate("FInHouseGuest", "Search by time (less)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FInHouseGuest: public Ui_FInHouseGuest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINHOUSEGUEST_H
