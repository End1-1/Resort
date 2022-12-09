/********************************************************************************
** Form generated from reading UI file 'wchart.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WCHART_H
#define UI_WCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WChart
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *vl;

    void setupUi(QWidget *WChart)
    {
        if (WChart->objectName().isEmpty())
            WChart->setObjectName(QString::fromUtf8("WChart"));
        WChart->resize(720, 470);
        verticalLayout_2 = new QVBoxLayout(WChart);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        vl = new QVBoxLayout();
        vl->setObjectName(QString::fromUtf8("vl"));

        verticalLayout_2->addLayout(vl);


        retranslateUi(WChart);

        QMetaObject::connectSlotsByName(WChart);
    } // setupUi

    void retranslateUi(QWidget *WChart)
    {
        WChart->setWindowTitle(QCoreApplication::translate("WChart", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WChart: public Ui_WChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WCHART_H
