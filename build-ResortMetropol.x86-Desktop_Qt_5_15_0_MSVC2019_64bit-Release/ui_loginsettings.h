/********************************************************************************
** Form generated from reading UI file 'loginsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINSETTINGS_H
#define UI_LOGINSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginSettings
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lePassword;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *LoginSettings)
    {
        if (LoginSettings->objectName().isEmpty())
            LoginSettings->setObjectName(QString::fromUtf8("LoginSettings"));
        LoginSettings->resize(356, 87);
        gridLayout_2 = new QGridLayout(LoginSettings);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(LoginSettings);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lePassword = new QLineEdit(LoginSettings);
        lePassword->setObjectName(QString::fromUtf8("lePassword"));
        lePassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lePassword, 0, 1, 1, 1);

        widget = new QWidget(LoginSettings);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(72, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(72, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 1, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(LoginSettings);

        QMetaObject::connectSlotsByName(LoginSettings);
    } // setupUi

    void retranslateUi(QDialog *LoginSettings)
    {
        LoginSettings->setWindowTitle(QCoreApplication::translate("LoginSettings", "Password for settings", nullptr));
        label->setText(QCoreApplication::translate("LoginSettings", "Password", nullptr));
        btnOk->setText(QCoreApplication::translate("LoginSettings", "Ok", nullptr));
        btnCancel->setText(QCoreApplication::translate("LoginSettings", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginSettings: public Ui_LoginSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINSETTINGS_H
