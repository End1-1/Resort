/********************************************************************************
** Form generated from reading UI file 'databasepasswordchange.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEPASSWORDCHANGE_H
#define UI_DATABASEPASSWORDCHANGE_H

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

class Ui_DatabasePasswordChange
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLineEdit *leOldPassword;
    QLineEdit *leNewPassword;
    QLabel *label;
    QLabel *label_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DatabasePasswordChange)
    {
        if (DatabasePasswordChange->objectName().isEmpty())
            DatabasePasswordChange->setObjectName(QString::fromUtf8("DatabasePasswordChange"));
        DatabasePasswordChange->resize(400, 113);
        horizontalLayout = new QHBoxLayout(DatabasePasswordChange);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leOldPassword = new QLineEdit(DatabasePasswordChange);
        leOldPassword->setObjectName(QString::fromUtf8("leOldPassword"));

        gridLayout->addWidget(leOldPassword, 0, 1, 1, 1);

        leNewPassword = new QLineEdit(DatabasePasswordChange);
        leNewPassword->setObjectName(QString::fromUtf8("leNewPassword"));

        gridLayout->addWidget(leNewPassword, 1, 1, 1, 1);

        label = new QLabel(DatabasePasswordChange);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(DatabasePasswordChange);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        widget = new QWidget(DatabasePasswordChange);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(94, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout_2->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_2->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(94, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 2, 0, 1, 2);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(DatabasePasswordChange);

        QMetaObject::connectSlotsByName(DatabasePasswordChange);
    } // setupUi

    void retranslateUi(QDialog *DatabasePasswordChange)
    {
        DatabasePasswordChange->setWindowTitle(QCoreApplication::translate("DatabasePasswordChange", "Change password", nullptr));
        label->setText(QCoreApplication::translate("DatabasePasswordChange", "Current password", nullptr));
        label_2->setText(QCoreApplication::translate("DatabasePasswordChange", "New password", nullptr));
        btnOk->setText(QCoreApplication::translate("DatabasePasswordChange", "Change", nullptr));
        btnCancel->setText(QCoreApplication::translate("DatabasePasswordChange", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DatabasePasswordChange: public Ui_DatabasePasswordChange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEPASSWORDCHANGE_H
