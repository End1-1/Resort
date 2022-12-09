/********************************************************************************
** Form generated from reading UI file 'fnousedadvance.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FNOUSEDADVANCE_H
#define UI_FNOUSEDADVANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FNoUsedAdvance
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *FNoUsedAdvance)
    {
        if (FNoUsedAdvance->objectName().isEmpty())
            FNoUsedAdvance->setObjectName(QString::fromUtf8("FNoUsedAdvance"));
        FNoUsedAdvance->resize(801, 16);
        horizontalLayout = new QHBoxLayout(FNoUsedAdvance);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);

        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(FNoUsedAdvance);

        QMetaObject::connectSlotsByName(FNoUsedAdvance);
    } // setupUi

    void retranslateUi(QWidget *FNoUsedAdvance)
    {
        FNoUsedAdvance->setWindowTitle(QCoreApplication::translate("FNoUsedAdvance", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FNoUsedAdvance: public Ui_FNoUsedAdvance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FNOUSEDADVANCE_H
