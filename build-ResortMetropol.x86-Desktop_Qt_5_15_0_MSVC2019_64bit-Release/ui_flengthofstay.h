/********************************************************************************
** Form generated from reading UI file 'flengthofstay.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLENGTHOFSTAY_H
#define UI_FLENGTHOFSTAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include <wdate2.h>

QT_BEGIN_NAMESPACE

class Ui_FLengthOfStay
{
public:
    QHBoxLayout *horizontalLayout;
    WDate2 *wd;
    QRadioButton *rbDates;
    QRadioButton *rbRooming;
    QLabel *label;
    QSpinBox *sp1;
    QLabel *label_2;
    QSpinBox *sp2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FLengthOfStay)
    {
        if (FLengthOfStay->objectName().isEmpty())
            FLengthOfStay->setObjectName(QString::fromUtf8("FLengthOfStay"));
        FLengthOfStay->resize(826, 41);
        horizontalLayout = new QHBoxLayout(FLengthOfStay);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        wd = new WDate2(FLengthOfStay);
        wd->setObjectName(QString::fromUtf8("wd"));

        horizontalLayout->addWidget(wd);

        rbDates = new QRadioButton(FLengthOfStay);
        rbDates->setObjectName(QString::fromUtf8("rbDates"));
        rbDates->setFocusPolicy(Qt::ClickFocus);
        rbDates->setChecked(true);

        horizontalLayout->addWidget(rbDates);

        rbRooming = new QRadioButton(FLengthOfStay);
        rbRooming->setObjectName(QString::fromUtf8("rbRooming"));
        rbRooming->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(rbRooming);

        label = new QLabel(FLengthOfStay);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(label);

        sp1 = new QSpinBox(FLengthOfStay);
        sp1->setObjectName(QString::fromUtf8("sp1"));
        sp1->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(sp1);

        label_2 = new QLabel(FLengthOfStay);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        sp2 = new QSpinBox(FLengthOfStay);
        sp2->setObjectName(QString::fromUtf8("sp2"));
        sp2->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(sp2);

        horizontalSpacer = new QSpacerItem(478, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FLengthOfStay);

        QMetaObject::connectSlotsByName(FLengthOfStay);
    } // setupUi

    void retranslateUi(QWidget *FLengthOfStay)
    {
        FLengthOfStay->setWindowTitle(QCoreApplication::translate("FLengthOfStay", "Form", nullptr));
        rbDates->setText(QCoreApplication::translate("FLengthOfStay", "By date", nullptr));
        rbRooming->setText(QCoreApplication::translate("FLengthOfStay", "By rooming", nullptr));
        label->setText(QCoreApplication::translate("FLengthOfStay", "Nigths range", nullptr));
        label_2->setText(QCoreApplication::translate("FLengthOfStay", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FLengthOfStay: public Ui_FLengthOfStay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLENGTHOFSTAY_H
