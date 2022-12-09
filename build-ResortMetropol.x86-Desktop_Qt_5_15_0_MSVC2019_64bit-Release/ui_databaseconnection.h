/********************************************************************************
** Form generated from reading UI file 'databaseconnection.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASECONNECTION_H
#define UI_DATABASECONNECTION_H

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

class Ui_DatabaseConnection
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLineEdit *leMainHost;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *leMainPassword;
    QLineEdit *leName;
    QLineEdit *leMainDb;
    QLineEdit *leMainUser;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnTest;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DatabaseConnection)
    {
        if (DatabaseConnection->objectName().isEmpty())
            DatabaseConnection->setObjectName(QString::fromUtf8("DatabaseConnection"));
        DatabaseConnection->resize(386, 197);
        horizontalLayout = new QHBoxLayout(DatabaseConnection);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leMainHost = new QLineEdit(DatabaseConnection);
        leMainHost->setObjectName(QString::fromUtf8("leMainHost"));

        gridLayout->addWidget(leMainHost, 1, 1, 1, 1);

        label = new QLabel(DatabaseConnection);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(DatabaseConnection);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_5 = new QLabel(DatabaseConnection);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_3 = new QLabel(DatabaseConnection);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(DatabaseConnection);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        leMainPassword = new QLineEdit(DatabaseConnection);
        leMainPassword->setObjectName(QString::fromUtf8("leMainPassword"));
        leMainPassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(leMainPassword, 4, 1, 1, 1);

        leName = new QLineEdit(DatabaseConnection);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 0, 1, 1, 1);

        leMainDb = new QLineEdit(DatabaseConnection);
        leMainDb->setObjectName(QString::fromUtf8("leMainDb"));

        gridLayout->addWidget(leMainDb, 2, 1, 1, 1);

        leMainUser = new QLineEdit(DatabaseConnection);
        leMainUser->setObjectName(QString::fromUtf8("leMainUser"));

        gridLayout->addWidget(leMainUser, 3, 1, 1, 1);

        widget = new QWidget(DatabaseConnection);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(47, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout_2->addWidget(btnOk);

        btnTest = new QPushButton(widget);
        btnTest->setObjectName(QString::fromUtf8("btnTest"));

        horizontalLayout_2->addWidget(btnTest);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_2->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(46, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 5, 0, 1, 2);


        horizontalLayout->addLayout(gridLayout);

        QWidget::setTabOrder(leName, leMainHost);
        QWidget::setTabOrder(leMainHost, leMainDb);
        QWidget::setTabOrder(leMainDb, leMainUser);
        QWidget::setTabOrder(leMainUser, leMainPassword);
        QWidget::setTabOrder(leMainPassword, btnOk);
        QWidget::setTabOrder(btnOk, btnTest);
        QWidget::setTabOrder(btnTest, btnCancel);

        retranslateUi(DatabaseConnection);

        QMetaObject::connectSlotsByName(DatabaseConnection);
    } // setupUi

    void retranslateUi(QDialog *DatabaseConnection)
    {
        DatabaseConnection->setWindowTitle(QCoreApplication::translate("DatabaseConnection", "Database connection", nullptr));
        label->setText(QCoreApplication::translate("DatabaseConnection", "Host", nullptr));
        label_2->setText(QCoreApplication::translate("DatabaseConnection", "Connection\n"
"name", nullptr));
        label_5->setText(QCoreApplication::translate("DatabaseConnection", "Password", nullptr));
        label_3->setText(QCoreApplication::translate("DatabaseConnection", "Schema", nullptr));
        label_4->setText(QCoreApplication::translate("DatabaseConnection", "Username", nullptr));
        btnOk->setText(QCoreApplication::translate("DatabaseConnection", "Ok", nullptr));
        btnTest->setText(QCoreApplication::translate("DatabaseConnection", "Test", nullptr));
        btnCancel->setText(QCoreApplication::translate("DatabaseConnection", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DatabaseConnection: public Ui_DatabaseConnection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASECONNECTION_H
