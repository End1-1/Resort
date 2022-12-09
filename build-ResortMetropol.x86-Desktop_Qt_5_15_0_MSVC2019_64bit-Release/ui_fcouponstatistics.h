/********************************************************************************
** Form generated from reading UI file 'fcouponstatistics.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCOUPONSTATISTICS_H
#define UI_FCOUPONSTATISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FCouponStatistics
{
public:

    void setupUi(QWidget *FCouponStatistics)
    {
        if (FCouponStatistics->objectName().isEmpty())
            FCouponStatistics->setObjectName(QString::fromUtf8("FCouponStatistics"));
        FCouponStatistics->resize(400, 300);

        retranslateUi(FCouponStatistics);

        QMetaObject::connectSlotsByName(FCouponStatistics);
    } // setupUi

    void retranslateUi(QWidget *FCouponStatistics)
    {
        FCouponStatistics->setWindowTitle(QCoreApplication::translate("FCouponStatistics", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FCouponStatistics: public Ui_FCouponStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCOUPONSTATISTICS_H
