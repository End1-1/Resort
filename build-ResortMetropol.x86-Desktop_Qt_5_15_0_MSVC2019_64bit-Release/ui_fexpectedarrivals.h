/********************************************************************************
** Form generated from reading UI file 'fexpectedarrivals.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEXPECTEDARRIVALS_H
#define UI_FEXPECTEDARRIVALS_H

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

class Ui_FExpectedArrivals
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

    void setupUi(QWidget *FExpectedArrivals)
    {
        if (FExpectedArrivals->objectName().isEmpty())
            FExpectedArrivals->setObjectName(QString::fromUtf8("FExpectedArrivals"));
        FExpectedArrivals->resize(576, 41);
        horizontalLayout_2 = new QHBoxLayout(FExpectedArrivals);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        wd = new WDate2(FExpectedArrivals);
        wd->setObjectName(QString::fromUtf8("wd"));

        horizontalLayout_2->addWidget(wd);

        widget = new QWidget(FExpectedArrivals);
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

        chWithoutRates = new QCheckBox(FExpectedArrivals);
        chWithoutRates->setObjectName(QString::fromUtf8("chWithoutRates"));

        horizontalLayout_2->addWidget(chWithoutRates);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_3 = new QLabel(FExpectedArrivals);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        leCardexCode = new EQLineEdit(FExpectedArrivals);
        leCardexCode->setObjectName(QString::fromUtf8("leCardexCode"));
        leCardexCode->setMaximumSize(QSize(80, 16777215));
        leCardexCode->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_2->addWidget(leCardexCode);

        leCardexName = new EQLineEdit(FExpectedArrivals);
        leCardexName->setObjectName(QString::fromUtf8("leCardexName"));
        leCardexName->setEnabled(false);

        horizontalLayout_2->addWidget(leCardexName);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        retranslateUi(FExpectedArrivals);

        QMetaObject::connectSlotsByName(FExpectedArrivals);
    } // setupUi

    void retranslateUi(QWidget *FExpectedArrivals)
    {
        FExpectedArrivals->setWindowTitle(QCoreApplication::translate("FExpectedArrivals", "Form", nullptr));
        rbEntry->setText(QCoreApplication::translate("FExpectedArrivals", "Entry", nullptr));
        rbDeparture->setText(QCoreApplication::translate("FExpectedArrivals", "Departure", nullptr));
        rgBoth->setText(QCoreApplication::translate("FExpectedArrivals", "Both", nullptr));
        chWithoutRates->setText(QCoreApplication::translate("FExpectedArrivals", "No rates", nullptr));
        label_3->setText(QCoreApplication::translate("FExpectedArrivals", "Cardex", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FExpectedArrivals: public Ui_FExpectedArrivals {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEXPECTEDARRIVALS_H
