/********************************************************************************
** Form generated from reading UI file 'dlgeditservtax.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGEDITSERVTAX_H
#define UI_DLGEDITSERVTAX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgEditServTax
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *leComp;
    QLabel *label_2;
    QCheckBox *chEnabled;
    QLabel *label_3;
    QLineEdit *leHost;
    QLabel *label_4;
    QLineEdit *lePort;
    QLabel *label_5;
    QLineEdit *lePass;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgEditServTax)
    {
        if (DlgEditServTax->objectName().isEmpty())
            DlgEditServTax->setObjectName(QString::fromUtf8("DlgEditServTax"));
        DlgEditServTax->resize(400, 186);
        gridLayout = new QGridLayout(DlgEditServTax);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DlgEditServTax);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leComp = new QLineEdit(DlgEditServTax);
        leComp->setObjectName(QString::fromUtf8("leComp"));
        leComp->setEnabled(false);

        gridLayout->addWidget(leComp, 0, 1, 1, 1);

        label_2 = new QLabel(DlgEditServTax);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        chEnabled = new QCheckBox(DlgEditServTax);
        chEnabled->setObjectName(QString::fromUtf8("chEnabled"));

        gridLayout->addWidget(chEnabled, 1, 1, 1, 1);

        label_3 = new QLabel(DlgEditServTax);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        leHost = new QLineEdit(DlgEditServTax);
        leHost->setObjectName(QString::fromUtf8("leHost"));

        gridLayout->addWidget(leHost, 2, 1, 1, 1);

        label_4 = new QLabel(DlgEditServTax);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lePort = new QLineEdit(DlgEditServTax);
        lePort->setObjectName(QString::fromUtf8("lePort"));

        gridLayout->addWidget(lePort, 3, 1, 1, 1);

        label_5 = new QLabel(DlgEditServTax);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        lePass = new QLineEdit(DlgEditServTax);
        lePass->setObjectName(QString::fromUtf8("lePass"));

        gridLayout->addWidget(lePass, 4, 1, 1, 1);

        widget = new QWidget(DlgEditServTax);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 5, 0, 1, 2);


        retranslateUi(DlgEditServTax);

        QMetaObject::connectSlotsByName(DlgEditServTax);
    } // setupUi

    void retranslateUi(QDialog *DlgEditServTax)
    {
        DlgEditServTax->setWindowTitle(QCoreApplication::translate("DlgEditServTax", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DlgEditServTax", "Computer", nullptr));
        label_2->setText(QCoreApplication::translate("DlgEditServTax", "Enabled", nullptr));
        chEnabled->setText(QString());
        label_3->setText(QCoreApplication::translate("DlgEditServTax", "Host", nullptr));
        label_4->setText(QCoreApplication::translate("DlgEditServTax", "Port", nullptr));
        label_5->setText(QCoreApplication::translate("DlgEditServTax", "Password", nullptr));
        btnOk->setText(QCoreApplication::translate("DlgEditServTax", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgEditServTax", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgEditServTax: public Ui_DlgEditServTax {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGEDITSERVTAX_H
