/********************************************************************************
** Form generated from reading UI file 'fexpectedsimple.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEXPECTEDSIMPLE_H
#define UI_FEXPECTEDSIMPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <wdate2.h>

QT_BEGIN_NAMESPACE

class Ui_FExpectedSimple
{
public:
    QHBoxLayout *horizontalLayout;
    WDate2 *wd;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FExpectedSimple)
    {
        if (FExpectedSimple->objectName().isEmpty())
            FExpectedSimple->setObjectName(QString::fromUtf8("FExpectedSimple"));
        FExpectedSimple->resize(400, 17);
        horizontalLayout = new QHBoxLayout(FExpectedSimple);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        wd = new WDate2(FExpectedSimple);
        wd->setObjectName(QString::fromUtf8("wd"));

        horizontalLayout->addWidget(wd);

        horizontalSpacer = new QSpacerItem(381, 14, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FExpectedSimple);

        QMetaObject::connectSlotsByName(FExpectedSimple);
    } // setupUi

    void retranslateUi(QWidget *FExpectedSimple)
    {
        FExpectedSimple->setWindowTitle(QCoreApplication::translate("FExpectedSimple", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FExpectedSimple: public Ui_FExpectedSimple {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEXPECTEDSIMPLE_H
