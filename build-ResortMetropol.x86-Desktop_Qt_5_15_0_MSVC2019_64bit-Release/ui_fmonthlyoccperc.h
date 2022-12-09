/********************************************************************************
** Form generated from reading UI file 'fmonthlyoccperc.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FMONTHLYOCCPERC_H
#define UI_FMONTHLYOCCPERC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eyearcombo.h>

QT_BEGIN_NAMESPACE

class Ui_FMonthlyOccPerc
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EYearCombo *cbYear;
    EDateEdit *deDate1;
    EDateEdit *deDate2;
    QCheckBox *chGroupByDays;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FMonthlyOccPerc)
    {
        if (FMonthlyOccPerc->objectName().isEmpty())
            FMonthlyOccPerc->setObjectName(QString::fromUtf8("FMonthlyOccPerc"));
        FMonthlyOccPerc->resize(735, 41);
        horizontalLayout = new QHBoxLayout(FMonthlyOccPerc);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FMonthlyOccPerc);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        cbYear = new EYearCombo(FMonthlyOccPerc);
        cbYear->setObjectName(QString::fromUtf8("cbYear"));

        horizontalLayout->addWidget(cbYear);

        deDate1 = new EDateEdit(FMonthlyOccPerc);
        deDate1->setObjectName(QString::fromUtf8("deDate1"));

        horizontalLayout->addWidget(deDate1);

        deDate2 = new EDateEdit(FMonthlyOccPerc);
        deDate2->setObjectName(QString::fromUtf8("deDate2"));

        horizontalLayout->addWidget(deDate2);

        chGroupByDays = new QCheckBox(FMonthlyOccPerc);
        chGroupByDays->setObjectName(QString::fromUtf8("chGroupByDays"));

        horizontalLayout->addWidget(chGroupByDays);

        horizontalSpacer = new QSpacerItem(611, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FMonthlyOccPerc);

        QMetaObject::connectSlotsByName(FMonthlyOccPerc);
    } // setupUi

    void retranslateUi(QWidget *FMonthlyOccPerc)
    {
        FMonthlyOccPerc->setWindowTitle(QCoreApplication::translate("FMonthlyOccPerc", "Form", nullptr));
        label->setText(QCoreApplication::translate("FMonthlyOccPerc", "Year", nullptr));
        chGroupByDays->setText(QCoreApplication::translate("FMonthlyOccPerc", "Group by days", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FMonthlyOccPerc: public Ui_FMonthlyOccPerc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FMONTHLYOCCPERC_H
