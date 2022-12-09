/********************************************************************************
** Form generated from reading UI file 'dlgreserveconfirmstatus.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGRESERVECONFIRMSTATUS_H
#define UI_DLGRESERVECONFIRMSTATUS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgReserveConfirmStatus
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *btnConfirmed;
    QPushButton *btnGuaranted;
    QPushButton *btnTentative;
    QPushButton *btnWaiting;
    QPushButton *btnBlock;
    QPushButton *btnCancel;

    void setupUi(QDialog *DlgReserveConfirmStatus)
    {
        if (DlgReserveConfirmStatus->objectName().isEmpty())
            DlgReserveConfirmStatus->setObjectName(QString::fromUtf8("DlgReserveConfirmStatus"));
        DlgReserveConfirmStatus->resize(216, 311);
        verticalLayout = new QVBoxLayout(DlgReserveConfirmStatus);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnConfirmed = new QPushButton(DlgReserveConfirmStatus);
        btnConfirmed->setObjectName(QString::fromUtf8("btnConfirmed"));
        btnConfirmed->setMaximumSize(QSize(222, 222));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/ball-green.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnConfirmed->setIcon(icon);

        verticalLayout->addWidget(btnConfirmed);

        btnGuaranted = new QPushButton(DlgReserveConfirmStatus);
        btnGuaranted->setObjectName(QString::fromUtf8("btnGuaranted"));
        btnGuaranted->setMaximumSize(QSize(222, 222));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/ball-yellow.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGuaranted->setIcon(icon1);

        verticalLayout->addWidget(btnGuaranted);

        btnTentative = new QPushButton(DlgReserveConfirmStatus);
        btnTentative->setObjectName(QString::fromUtf8("btnTentative"));
        btnTentative->setMaximumSize(QSize(222, 222));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/ball-gray.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTentative->setIcon(icon2);

        verticalLayout->addWidget(btnTentative);

        btnWaiting = new QPushButton(DlgReserveConfirmStatus);
        btnWaiting->setObjectName(QString::fromUtf8("btnWaiting"));
        btnWaiting->setMaximumSize(QSize(222, 222));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/ball-red.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnWaiting->setIcon(icon3);

        verticalLayout->addWidget(btnWaiting);

        btnBlock = new QPushButton(DlgReserveConfirmStatus);
        btnBlock->setObjectName(QString::fromUtf8("btnBlock"));
        btnBlock->setMaximumSize(QSize(222, 222));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/ball-blue.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnBlock->setIcon(icon4);

        verticalLayout->addWidget(btnBlock);

        btnCancel = new QPushButton(DlgReserveConfirmStatus);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMaximumSize(QSize(222, 222));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancel->setIcon(icon5);

        verticalLayout->addWidget(btnCancel);


        retranslateUi(DlgReserveConfirmStatus);

        QMetaObject::connectSlotsByName(DlgReserveConfirmStatus);
    } // setupUi

    void retranslateUi(QDialog *DlgReserveConfirmStatus)
    {
        DlgReserveConfirmStatus->setWindowTitle(QCoreApplication::translate("DlgReserveConfirmStatus", "Confirmation", nullptr));
        btnConfirmed->setText(QCoreApplication::translate("DlgReserveConfirmStatus", "Confirmed", nullptr));
        btnGuaranted->setText(QCoreApplication::translate("DlgReserveConfirmStatus", "Guaranted", nullptr));
        btnTentative->setText(QCoreApplication::translate("DlgReserveConfirmStatus", "Tentative", nullptr));
        btnWaiting->setText(QCoreApplication::translate("DlgReserveConfirmStatus", "Waiting", nullptr));
        btnBlock->setText(QCoreApplication::translate("DlgReserveConfirmStatus", "Block", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgReserveConfirmStatus", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgReserveConfirmStatus: public Ui_DlgReserveConfirmStatus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGRESERVECONFIRMSTATUS_H
