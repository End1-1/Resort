/********************************************************************************
** Form generated from reading UI file 'dlgraiseuser.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGRAISEUSER_H
#define UI_DLGRAISEUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgRaiseUser
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *leUsername;
    QLineEdit *lePassword;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgRaiseUser)
    {
        if (DlgRaiseUser->objectName().isEmpty())
            DlgRaiseUser->setObjectName(QString::fromUtf8("DlgRaiseUser"));
        DlgRaiseUser->resize(255, 143);
        verticalLayout = new QVBoxLayout(DlgRaiseUser);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(DlgRaiseUser);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        leUsername = new QLineEdit(DlgRaiseUser);
        leUsername->setObjectName(QString::fromUtf8("leUsername"));

        verticalLayout->addWidget(leUsername);

        lePassword = new QLineEdit(DlgRaiseUser);
        lePassword->setObjectName(QString::fromUtf8("lePassword"));
        lePassword->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lePassword);

        widget = new QWidget(DlgRaiseUser);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(22, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(23, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);


        retranslateUi(DlgRaiseUser);

        QMetaObject::connectSlotsByName(DlgRaiseUser);
    } // setupUi

    void retranslateUi(QDialog *DlgRaiseUser)
    {
        DlgRaiseUser->setWindowTitle(QCoreApplication::translate("DlgRaiseUser", "Raise up", nullptr));
        label->setText(QCoreApplication::translate("DlgRaiseUser", "You must raise the privileges\n"
"for this operation", nullptr));
        leUsername->setPlaceholderText(QCoreApplication::translate("DlgRaiseUser", "Username", nullptr));
        lePassword->setPlaceholderText(QCoreApplication::translate("DlgRaiseUser", "Password", nullptr));
        btnOk->setText(QCoreApplication::translate("DlgRaiseUser", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgRaiseUser", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgRaiseUser: public Ui_DlgRaiseUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGRAISEUSER_H
