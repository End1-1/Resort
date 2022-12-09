/********************************************************************************
** Form generated from reading UI file 'favailablerooms.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAVAILABLEROOMS_H
#define UI_FAVAILABLEROOMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <wdate2.h>

QT_BEGIN_NAMESPACE

class Ui_FAvailableRooms
{
public:
    QHBoxLayout *horizontalLayout;
    WDate2 *wd;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FAvailableRooms)
    {
        if (FAvailableRooms->objectName().isEmpty())
            FAvailableRooms->setObjectName(QString::fromUtf8("FAvailableRooms"));
        FAvailableRooms->resize(834, 41);
        horizontalLayout = new QHBoxLayout(FAvailableRooms);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        wd = new WDate2(FAvailableRooms);
        wd->setObjectName(QString::fromUtf8("wd"));

        horizontalLayout->addWidget(wd);

        horizontalSpacer = new QSpacerItem(797, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FAvailableRooms);

        QMetaObject::connectSlotsByName(FAvailableRooms);
    } // setupUi

    void retranslateUi(QWidget *FAvailableRooms)
    {
        FAvailableRooms->setWindowTitle(QCoreApplication::translate("FAvailableRooms", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FAvailableRooms: public Ui_FAvailableRooms {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAVAILABLEROOMS_H
