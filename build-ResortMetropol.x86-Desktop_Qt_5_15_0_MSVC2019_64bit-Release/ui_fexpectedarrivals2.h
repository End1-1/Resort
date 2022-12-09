/********************************************************************************
** Form generated from reading UI file 'fexpectedarrivals2.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEXPECTEDARRIVALS2_H
#define UI_FEXPECTEDARRIVALS2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>
#include <wdate2.h>

QT_BEGIN_NAMESPACE

class Ui_FExpectedArrivals2
{
public:
    QHBoxLayout *horizontalLayout_2;
    WDate2 *wd;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *rbEntry;
    QRadioButton *rbDeparture;
    QRadioButton *rgBoth;
    QCheckBox *chWithoutRates;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    EQLineEdit *leCardexCode;
    EQLineEdit *leCardexName;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FExpectedArrivals2)
    {
        if (FExpectedArrivals2->objectName().isEmpty())
            FExpectedArrivals2->setObjectName(QString::fromUtf8("FExpectedArrivals2"));
        FExpectedArrivals2->resize(576, 41);
        horizontalLayout_2 = new QHBoxLayout(FExpectedArrivals2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        wd = new WDate2(FExpectedArrivals2);
        wd->setObjectName(QString::fromUtf8("wd"));

        horizontalLayout_2->addWidget(wd);

        widget = new QWidget(FExpectedArrivals2);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        rbEntry = new QRadioButton(widget);
        rbEntry->setObjectName(QString::fromUtf8("rbEntry"));
        rbEntry->setFocusPolicy(Qt::ClickFocus);
        rbEntry->setChecked(true);

        horizontalLayout_3->addWidget(rbEntry);

        rbDeparture = new QRadioButton(widget);
        rbDeparture->setObjectName(QString::fromUtf8("rbDeparture"));
        rbDeparture->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_3->addWidget(rbDeparture);

        rgBoth = new QRadioButton(widget);
        rgBoth->setObjectName(QString::fromUtf8("rgBoth"));
        rgBoth->setFocusPolicy(Qt::ClickFocus);
        rgBoth->setChecked(false);

        horizontalLayout_3->addWidget(rgBoth);


        horizontalLayout_2->addWidget(widget);

        chWithoutRates = new QCheckBox(FExpectedArrivals2);
        chWithoutRates->setObjectName(QString::fromUtf8("chWithoutRates"));

        horizontalLayout_2->addWidget(chWithoutRates);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_3 = new QLabel(FExpectedArrivals2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        leCardexCode = new EQLineEdit(FExpectedArrivals2);
        leCardexCode->setObjectName(QString::fromUtf8("leCardexCode"));
        leCardexCode->setMaximumSize(QSize(80, 16777215));
        leCardexCode->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_2->addWidget(leCardexCode);

        leCardexName = new EQLineEdit(FExpectedArrivals2);
        leCardexName->setObjectName(QString::fromUtf8("leCardexName"));
        leCardexName->setEnabled(false);

        horizontalLayout_2->addWidget(leCardexName);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        retranslateUi(FExpectedArrivals2);

        QMetaObject::connectSlotsByName(FExpectedArrivals2);
    } // setupUi

    void retranslateUi(QWidget *FExpectedArrivals2)
    {
        FExpectedArrivals2->setWindowTitle(QCoreApplication::translate("FExpectedArrivals2", "Form", nullptr));
        rbEntry->setText(QCoreApplication::translate("FExpectedArrivals2", "Entry", nullptr));
        rbDeparture->setText(QCoreApplication::translate("FExpectedArrivals2", "Departure", nullptr));
        rgBoth->setText(QCoreApplication::translate("FExpectedArrivals2", "Both", nullptr));
        chWithoutRates->setText(QCoreApplication::translate("FExpectedArrivals2", "No rates", nullptr));
        label_3->setText(QCoreApplication::translate("FExpectedArrivals2", "Cardex", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FExpectedArrivals2: public Ui_FExpectedArrivals2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEXPECTEDARRIVALS2_H
