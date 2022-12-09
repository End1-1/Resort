/********************************************************************************
** Form generated from reading UI file 'dlgnewvaucheroption.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGNEWVAUCHEROPTION_H
#define UI_DLGNEWVAUCHEROPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgNewVaucherOption
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *btnRV;
    QPushButton *btnPostCharge;
    QPushButton *btnManual;
    QPushButton *btnCancel;

    void setupUi(QDialog *DlgNewVaucherOption)
    {
        if (DlgNewVaucherOption->objectName().isEmpty())
            DlgNewVaucherOption->setObjectName(QString::fromUtf8("DlgNewVaucherOption"));
        DlgNewVaucherOption->resize(400, 236);
        verticalLayout = new QVBoxLayout(DlgNewVaucherOption);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnRV = new QPushButton(DlgNewVaucherOption);
        btnRV->setObjectName(QString::fromUtf8("btnRV"));
        btnRV->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(btnRV);

        btnPostCharge = new QPushButton(DlgNewVaucherOption);
        btnPostCharge->setObjectName(QString::fromUtf8("btnPostCharge"));
        btnPostCharge->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(btnPostCharge);

        btnManual = new QPushButton(DlgNewVaucherOption);
        btnManual->setObjectName(QString::fromUtf8("btnManual"));
        btnManual->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(btnManual);

        btnCancel = new QPushButton(DlgNewVaucherOption);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(btnCancel);


        retranslateUi(DlgNewVaucherOption);

        QMetaObject::connectSlotsByName(DlgNewVaucherOption);
    } // setupUi

    void retranslateUi(QDialog *DlgNewVaucherOption)
    {
        DlgNewVaucherOption->setWindowTitle(QCoreApplication::translate("DlgNewVaucherOption", "New voucher option", nullptr));
        btnRV->setText(QCoreApplication::translate("DlgNewVaucherOption", "Receipt voucher", nullptr));
        btnPostCharge->setText(QCoreApplication::translate("DlgNewVaucherOption", "Post charge", nullptr));
        btnManual->setText(QCoreApplication::translate("DlgNewVaucherOption", "Manual voucher", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgNewVaucherOption", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgNewVaucherOption: public Ui_DlgNewVaucherOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGNEWVAUCHEROPTION_H
