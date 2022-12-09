/********************************************************************************
** Form generated from reading UI file 'fexpecteddeparturesimple.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEXPECTEDDEPARTURESIMPLE_H
#define UI_FEXPECTEDDEPARTURESIMPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <wdate2.h>

QT_BEGIN_NAMESPACE

class Ui_FExpectedDepartureSimple
{
public:
    QHBoxLayout *horizontalLayout;
    WDate2 *wd;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FExpectedDepartureSimple)
    {
        if (FExpectedDepartureSimple->objectName().isEmpty())
            FExpectedDepartureSimple->setObjectName(QString::fromUtf8("FExpectedDepartureSimple"));
        FExpectedDepartureSimple->resize(802, 17);
        horizontalLayout = new QHBoxLayout(FExpectedDepartureSimple);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        wd = new WDate2(FExpectedDepartureSimple);
        wd->setObjectName(QString::fromUtf8("wd"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(wd->sizePolicy().hasHeightForWidth());
        wd->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(wd);

        horizontalSpacer = new QSpacerItem(783, 14, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FExpectedDepartureSimple);

        QMetaObject::connectSlotsByName(FExpectedDepartureSimple);
    } // setupUi

    void retranslateUi(QWidget *FExpectedDepartureSimple)
    {
        FExpectedDepartureSimple->setWindowTitle(QCoreApplication::translate("FExpectedDepartureSimple", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FExpectedDepartureSimple: public Ui_FExpectedDepartureSimple {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEXPECTEDDEPARTURESIMPLE_H
