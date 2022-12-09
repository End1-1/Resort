/********************************************************************************
** Form generated from reading UI file 'reusers.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REUSERS_H
#define UI_REUSERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <eqcombobox.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_REUsers
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    EQLineEdit *leGroupName;
    EQLineEdit *leGroupCode;
    EQLineEdit *leCode;
    QLabel *label_6;
    EQLineEdit *leFName;
    EQLineEdit *leLName;
    QLabel *label_4;
    EQLineEdit *leUsername;
    QLabel *label_5;
    EQComboBox *cbState;

    void setupUi(QDialog *REUsers)
    {
        if (REUsers->objectName().isEmpty())
            REUsers->setObjectName(QString::fromUtf8("REUsers"));
        REUsers->resize(346, 219);
        horizontalLayout = new QHBoxLayout(REUsers);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(REUsers);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        label_2 = new QLabel(REUsers);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        widget = new QWidget(REUsers);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(67, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout_2->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_2->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(67, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 8, 0, 1, 3);

        label = new QLabel(REUsers);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 5, 0, 1, 1);

        leGroupName = new EQLineEdit(REUsers);
        leGroupName->setObjectName(QString::fromUtf8("leGroupName"));
        leGroupName->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(leGroupName, 2, 2, 1, 1);

        leGroupCode = new EQLineEdit(REUsers);
        leGroupCode->setObjectName(QString::fromUtf8("leGroupCode"));
        leGroupCode->setMaximumSize(QSize(40, 16777215));
        leGroupCode->setProperty("ShowButton", QVariant(true));

        gridLayout->addWidget(leGroupCode, 2, 1, 1, 1);

        leCode = new EQLineEdit(REUsers);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setReadOnly(true);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 2);

        label_6 = new QLabel(REUsers);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        leFName = new EQLineEdit(REUsers);
        leFName->setObjectName(QString::fromUtf8("leFName"));

        gridLayout->addWidget(leFName, 5, 1, 1, 2);

        leLName = new EQLineEdit(REUsers);
        leLName->setObjectName(QString::fromUtf8("leLName"));

        gridLayout->addWidget(leLName, 6, 1, 1, 2);

        label_4 = new QLabel(REUsers);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        leUsername = new EQLineEdit(REUsers);
        leUsername->setObjectName(QString::fromUtf8("leUsername"));

        gridLayout->addWidget(leUsername, 4, 1, 1, 2);

        label_5 = new QLabel(REUsers);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        cbState = new EQComboBox(REUsers);
        cbState->setObjectName(QString::fromUtf8("cbState"));
        cbState->setProperty("Cache", QVariant(41));

        gridLayout->addWidget(cbState, 1, 1, 1, 2);


        horizontalLayout->addLayout(gridLayout);

        QWidget::setTabOrder(leCode, cbState);
        QWidget::setTabOrder(cbState, leGroupCode);
        QWidget::setTabOrder(leGroupCode, leUsername);
        QWidget::setTabOrder(leUsername, leFName);
        QWidget::setTabOrder(leFName, leLName);
        QWidget::setTabOrder(leLName, btnOk);
        QWidget::setTabOrder(btnOk, btnCancel);
        QWidget::setTabOrder(btnCancel, leGroupName);

        retranslateUi(REUsers);

        QMetaObject::connectSlotsByName(REUsers);
    } // setupUi

    void retranslateUi(QDialog *REUsers)
    {
        REUsers->setWindowTitle(QCoreApplication::translate("REUsers", "User", nullptr));
        label_3->setText(QCoreApplication::translate("REUsers", "Last name", nullptr));
        label_2->setText(QCoreApplication::translate("REUsers", "Code", nullptr));
        btnOk->setText(QCoreApplication::translate("REUsers", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("REUsers", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("REUsers", "First name", nullptr));
        leGroupCode->setProperty("Field", QVariant(QCoreApplication::translate("REUsers", "f_group", nullptr)));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("REUsers", "f_id", nullptr)));
        label_6->setText(QCoreApplication::translate("REUsers", "Group", nullptr));
        leFName->setProperty("Field", QVariant(QCoreApplication::translate("REUsers", "f_firstName", nullptr)));
        leLName->setProperty("Field", QVariant(QCoreApplication::translate("REUsers", "f_lastName", nullptr)));
        label_4->setText(QCoreApplication::translate("REUsers", "Username", nullptr));
        leUsername->setProperty("Field", QVariant(QCoreApplication::translate("REUsers", "f_username", nullptr)));
        label_5->setText(QCoreApplication::translate("REUsers", "State", nullptr));
        cbState->setProperty("Field", QVariant(QCoreApplication::translate("REUsers", "f_state", nullptr)));
    } // retranslateUi

};

namespace Ui {
    class REUsers: public Ui_REUsers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REUSERS_H
