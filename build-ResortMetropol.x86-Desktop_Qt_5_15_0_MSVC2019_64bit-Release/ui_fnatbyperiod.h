/********************************************************************************
** Form generated from reading UI file 'fnatbyperiod.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FNATBYPERIOD_H
#define UI_FNATBYPERIOD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <eqcombobox.h>
#include <eyearcombo.h>

QT_BEGIN_NAMESPACE

class Ui_FNatByPeriod
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EYearCombo *cbYear1;
    EQComboBox *cbMonth1;
    QLabel *label_2;
    EYearCombo *cbYear2;
    EQComboBox *cbMonth2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FNatByPeriod)
    {
        if (FNatByPeriod->objectName().isEmpty())
            FNatByPeriod->setObjectName(QString::fromUtf8("FNatByPeriod"));
        FNatByPeriod->resize(871, 41);
        horizontalLayout = new QHBoxLayout(FNatByPeriod);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FNatByPeriod);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        cbYear1 = new EYearCombo(FNatByPeriod);
        cbYear1->setObjectName(QString::fromUtf8("cbYear1"));

        horizontalLayout->addWidget(cbYear1);

        cbMonth1 = new EQComboBox(FNatByPeriod);
        cbMonth1->addItem(QString());
        cbMonth1->addItem(QString());
        cbMonth1->addItem(QString());
        cbMonth1->addItem(QString());
        cbMonth1->addItem(QString());
        cbMonth1->addItem(QString());
        cbMonth1->addItem(QString());
        cbMonth1->addItem(QString());
        cbMonth1->addItem(QString());
        cbMonth1->addItem(QString());
        cbMonth1->addItem(QString());
        cbMonth1->addItem(QString());
        cbMonth1->setObjectName(QString::fromUtf8("cbMonth1"));

        horizontalLayout->addWidget(cbMonth1);

        label_2 = new QLabel(FNatByPeriod);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        cbYear2 = new EYearCombo(FNatByPeriod);
        cbYear2->setObjectName(QString::fromUtf8("cbYear2"));

        horizontalLayout->addWidget(cbYear2);

        cbMonth2 = new EQComboBox(FNatByPeriod);
        cbMonth2->addItem(QString());
        cbMonth2->addItem(QString());
        cbMonth2->addItem(QString());
        cbMonth2->addItem(QString());
        cbMonth2->addItem(QString());
        cbMonth2->addItem(QString());
        cbMonth2->addItem(QString());
        cbMonth2->addItem(QString());
        cbMonth2->addItem(QString());
        cbMonth2->addItem(QString());
        cbMonth2->addItem(QString());
        cbMonth2->addItem(QString());
        cbMonth2->setObjectName(QString::fromUtf8("cbMonth2"));

        horizontalLayout->addWidget(cbMonth2);

        horizontalSpacer = new QSpacerItem(393, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FNatByPeriod);

        QMetaObject::connectSlotsByName(FNatByPeriod);
    } // setupUi

    void retranslateUi(QWidget *FNatByPeriod)
    {
        FNatByPeriod->setWindowTitle(QCoreApplication::translate("FNatByPeriod", "Form", nullptr));
        label->setText(QCoreApplication::translate("FNatByPeriod", "Period start from", nullptr));
        cbMonth1->setItemText(0, QCoreApplication::translate("FNatByPeriod", "January", nullptr));
        cbMonth1->setItemText(1, QCoreApplication::translate("FNatByPeriod", "February", nullptr));
        cbMonth1->setItemText(2, QCoreApplication::translate("FNatByPeriod", "Mart", nullptr));
        cbMonth1->setItemText(3, QCoreApplication::translate("FNatByPeriod", "April", nullptr));
        cbMonth1->setItemText(4, QCoreApplication::translate("FNatByPeriod", "May", nullptr));
        cbMonth1->setItemText(5, QCoreApplication::translate("FNatByPeriod", "June", nullptr));
        cbMonth1->setItemText(6, QCoreApplication::translate("FNatByPeriod", "July", nullptr));
        cbMonth1->setItemText(7, QCoreApplication::translate("FNatByPeriod", "August", nullptr));
        cbMonth1->setItemText(8, QCoreApplication::translate("FNatByPeriod", "September", nullptr));
        cbMonth1->setItemText(9, QCoreApplication::translate("FNatByPeriod", "October", nullptr));
        cbMonth1->setItemText(10, QCoreApplication::translate("FNatByPeriod", "November", nullptr));
        cbMonth1->setItemText(11, QCoreApplication::translate("FNatByPeriod", "December", nullptr));

        label_2->setText(QCoreApplication::translate("FNatByPeriod", "End of period", nullptr));
        cbMonth2->setItemText(0, QCoreApplication::translate("FNatByPeriod", "January", nullptr));
        cbMonth2->setItemText(1, QCoreApplication::translate("FNatByPeriod", "February", nullptr));
        cbMonth2->setItemText(2, QCoreApplication::translate("FNatByPeriod", "Mart", nullptr));
        cbMonth2->setItemText(3, QCoreApplication::translate("FNatByPeriod", "April", nullptr));
        cbMonth2->setItemText(4, QCoreApplication::translate("FNatByPeriod", "May", nullptr));
        cbMonth2->setItemText(5, QCoreApplication::translate("FNatByPeriod", "June", nullptr));
        cbMonth2->setItemText(6, QCoreApplication::translate("FNatByPeriod", "July", nullptr));
        cbMonth2->setItemText(7, QCoreApplication::translate("FNatByPeriod", "August", nullptr));
        cbMonth2->setItemText(8, QCoreApplication::translate("FNatByPeriod", "September", nullptr));
        cbMonth2->setItemText(9, QCoreApplication::translate("FNatByPeriod", "October", nullptr));
        cbMonth2->setItemText(10, QCoreApplication::translate("FNatByPeriod", "November", nullptr));
        cbMonth2->setItemText(11, QCoreApplication::translate("FNatByPeriod", "December", nullptr));

    } // retranslateUi

};

namespace Ui {
    class FNatByPeriod: public Ui_FNatByPeriod {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FNATBYPERIOD_H
