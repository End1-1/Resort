/********************************************************************************
** Form generated from reading UI file 'dlgperemovereason.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGPEREMOVEREASON_H
#define UI_DLGPEREMOVEREASON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DlgPERemoveReason
{
public:
    QGridLayout *gridLayout;
    QPushButton *btnMistake;
    QPushButton *btnVoid;
    QPushButton *btnCancel;

    void setupUi(QDialog *DlgPERemoveReason)
    {
        if (DlgPERemoveReason->objectName().isEmpty())
            DlgPERemoveReason->setObjectName(QString::fromUtf8("DlgPERemoveReason"));
        DlgPERemoveReason->resize(255, 77);
        gridLayout = new QGridLayout(DlgPERemoveReason);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnMistake = new QPushButton(DlgPERemoveReason);
        btnMistake->setObjectName(QString::fromUtf8("btnMistake"));

        gridLayout->addWidget(btnMistake, 0, 0, 1, 1);

        btnVoid = new QPushButton(DlgPERemoveReason);
        btnVoid->setObjectName(QString::fromUtf8("btnVoid"));

        gridLayout->addWidget(btnVoid, 0, 1, 1, 1);

        btnCancel = new QPushButton(DlgPERemoveReason);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        gridLayout->addWidget(btnCancel, 1, 0, 1, 2);


        retranslateUi(DlgPERemoveReason);

        QMetaObject::connectSlotsByName(DlgPERemoveReason);
    } // setupUi

    void retranslateUi(QDialog *DlgPERemoveReason)
    {
        DlgPERemoveReason->setWindowTitle(QCoreApplication::translate("DlgPERemoveReason", "Reason", nullptr));
        btnMistake->setText(QCoreApplication::translate("DlgPERemoveReason", "MISTAKE", nullptr));
        btnVoid->setText(QCoreApplication::translate("DlgPERemoveReason", "VOID", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgPERemoveReason", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgPERemoveReason: public Ui_DlgPERemoveReason {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGPEREMOVEREASON_H
