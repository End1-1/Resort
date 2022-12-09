/********************************************************************************
** Form generated from reading UI file 'fcladvance.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCLADVANCE_H
#define UI_FCLADVANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FCLAdvance
{
public:
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *FCLAdvance)
    {
        if (FCLAdvance->objectName().isEmpty())
            FCLAdvance->setObjectName(QString::fromUtf8("FCLAdvance"));
        FCLAdvance->resize(705, 18);
        horizontalLayout = new QHBoxLayout(FCLAdvance);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        retranslateUi(FCLAdvance);

        QMetaObject::connectSlotsByName(FCLAdvance);
    } // setupUi

    void retranslateUi(QWidget *FCLAdvance)
    {
        FCLAdvance->setWindowTitle(QCoreApplication::translate("FCLAdvance", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FCLAdvance: public Ui_FCLAdvance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCLADVANCE_H
