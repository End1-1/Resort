/********************************************************************************
** Form generated from reading UI file 'fyearlyfinancialreport.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FYEARLYFINANCIALREPORT_H
#define UI_FYEARLYFINANCIALREPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <eyearcombo.h>

QT_BEGIN_NAMESPACE

class Ui_FYearlyFinancialReport
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EYearCombo *cbYear;
    QLabel *label_2;
    QRadioButton *rbAmd;
    QRadioButton *rbUsd;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FYearlyFinancialReport)
    {
        if (FYearlyFinancialReport->objectName().isEmpty())
            FYearlyFinancialReport->setObjectName(QString::fromUtf8("FYearlyFinancialReport"));
        FYearlyFinancialReport->resize(677, 41);
        horizontalLayout = new QHBoxLayout(FYearlyFinancialReport);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FYearlyFinancialReport);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        cbYear = new EYearCombo(FYearlyFinancialReport);
        cbYear->setObjectName(QString::fromUtf8("cbYear"));

        horizontalLayout->addWidget(cbYear);

        label_2 = new QLabel(FYearlyFinancialReport);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        rbAmd = new QRadioButton(FYearlyFinancialReport);
        rbAmd->setObjectName(QString::fromUtf8("rbAmd"));
        rbAmd->setChecked(true);

        horizontalLayout->addWidget(rbAmd);

        rbUsd = new QRadioButton(FYearlyFinancialReport);
        rbUsd->setObjectName(QString::fromUtf8("rbUsd"));

        horizontalLayout->addWidget(rbUsd);

        horizontalSpacer = new QSpacerItem(403, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FYearlyFinancialReport);

        QMetaObject::connectSlotsByName(FYearlyFinancialReport);
    } // setupUi

    void retranslateUi(QWidget *FYearlyFinancialReport)
    {
        FYearlyFinancialReport->setWindowTitle(QCoreApplication::translate("FYearlyFinancialReport", "Form", nullptr));
        label->setText(QCoreApplication::translate("FYearlyFinancialReport", "Year", nullptr));
        label_2->setText(QCoreApplication::translate("FYearlyFinancialReport", "Currency", nullptr));
        rbAmd->setText(QCoreApplication::translate("FYearlyFinancialReport", "AMD", nullptr));
        rbUsd->setText(QCoreApplication::translate("FYearlyFinancialReport", "USD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FYearlyFinancialReport: public Ui_FYearlyFinancialReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FYEARLYFINANCIALREPORT_H
