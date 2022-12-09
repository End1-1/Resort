/********************************************************************************
** Form generated from reading UI file 'dlgposremoveoption.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGPOSREMOVEOPTION_H
#define UI_DLGPOSREMOVEOPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *btnMistake;
    QPushButton *btnVoid;
    QPushButton *btnCancel;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        btnMistake = new QPushButton(Dialog);
        btnMistake->setObjectName(QString::fromUtf8("btnMistake"));
        btnMistake->setGeometry(QRect(30, 100, 75, 23));
        btnVoid = new QPushButton(Dialog);
        btnVoid->setObjectName(QString::fromUtf8("btnVoid"));
        btnVoid->setGeometry(QRect(260, 100, 75, 23));
        btnCancel = new QPushButton(Dialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(160, 180, 75, 23));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        btnMistake->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
        btnVoid->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
        btnCancel->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGPOSREMOVEOPTION_H
