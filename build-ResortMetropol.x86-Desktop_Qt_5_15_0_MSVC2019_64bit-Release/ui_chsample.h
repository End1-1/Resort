/********************************************************************************
** Form generated from reading UI file 'chsample.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHSAMPLE_H
#define UI_CHSAMPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChSample
{
public:

    void setupUi(QWidget *ChSample)
    {
        if (ChSample->objectName().isEmpty())
            ChSample->setObjectName(QString::fromUtf8("ChSample"));
        ChSample->resize(649, 378);

        retranslateUi(ChSample);

        QMetaObject::connectSlotsByName(ChSample);
    } // setupUi

    void retranslateUi(QWidget *ChSample)
    {
        ChSample->setWindowTitle(QCoreApplication::translate("ChSample", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChSample: public Ui_ChSample {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHSAMPLE_H
