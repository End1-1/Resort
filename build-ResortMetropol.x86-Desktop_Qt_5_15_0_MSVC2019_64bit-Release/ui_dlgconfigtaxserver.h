/********************************************************************************
** Form generated from reading UI file 'dlgconfigtaxserver.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCONFIGTAXSERVER_H
#define UI_DLGCONFIGTAXSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_DlgConfigTaxServer
{
public:
    QGridLayout *gridLayout;
    QLineEdit *leAddress;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lePort;
    QLabel *label_3;
    QLineEdit *lePassword;
    QCheckBox *chRemote;
    QLabel *label_4;

    void setupUi(QDialog *DlgConfigTaxServer)
    {
        if (DlgConfigTaxServer->objectName().isEmpty())
            DlgConfigTaxServer->setObjectName(QString::fromUtf8("DlgConfigTaxServer"));
        DlgConfigTaxServer->resize(324, 109);
        gridLayout = new QGridLayout(DlgConfigTaxServer);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leAddress = new QLineEdit(DlgConfigTaxServer);
        leAddress->setObjectName(QString::fromUtf8("leAddress"));

        gridLayout->addWidget(leAddress, 0, 2, 1, 1);

        label = new QLabel(DlgConfigTaxServer);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(DlgConfigTaxServer);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lePort = new QLineEdit(DlgConfigTaxServer);
        lePort->setObjectName(QString::fromUtf8("lePort"));
        lePort->setMaxLength(4);

        gridLayout->addWidget(lePort, 1, 2, 1, 1);

        label_3 = new QLabel(DlgConfigTaxServer);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lePassword = new QLineEdit(DlgConfigTaxServer);
        lePassword->setObjectName(QString::fromUtf8("lePassword"));

        gridLayout->addWidget(lePassword, 2, 2, 1, 1);

        chRemote = new QCheckBox(DlgConfigTaxServer);
        chRemote->setObjectName(QString::fromUtf8("chRemote"));

        gridLayout->addWidget(chRemote, 3, 2, 1, 1);

        label_4 = new QLabel(DlgConfigTaxServer);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);


        retranslateUi(DlgConfigTaxServer);

        QMetaObject::connectSlotsByName(DlgConfigTaxServer);
    } // setupUi

    void retranslateUi(QDialog *DlgConfigTaxServer)
    {
        DlgConfigTaxServer->setWindowTitle(QCoreApplication::translate("DlgConfigTaxServer", "Tax server", nullptr));
        leAddress->setInputMask(QCoreApplication::translate("DlgConfigTaxServer", "###.###.###.###", nullptr));
        label->setText(QCoreApplication::translate("DlgConfigTaxServer", "IPv4 address", nullptr));
        label_2->setText(QCoreApplication::translate("DlgConfigTaxServer", "Port", nullptr));
        lePort->setInputMask(QCoreApplication::translate("DlgConfigTaxServer", "####", nullptr));
        label_3->setText(QCoreApplication::translate("DlgConfigTaxServer", "Password", nullptr));
        chRemote->setText(QString());
        label_4->setText(QCoreApplication::translate("DlgConfigTaxServer", "Remote server", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgConfigTaxServer: public Ui_DlgConfigTaxServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCONFIGTAXSERVER_H
