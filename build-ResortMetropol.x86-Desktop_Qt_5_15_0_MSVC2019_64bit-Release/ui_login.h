/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QFormLayout *formLayout;
    QLabel *lbLogo;
    QWidget *widget;
    QGridLayout *gridLayout;
    QWidget *wUsernamePassword;
    QGridLayout *gridLayout_3;
    QLineEdit *lePassword;
    QLabel *label_2;
    QLabel *label;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnLogin;
    QPushButton *btnCancel;
    QLineEdit *leUsername;
    QLabel *lbFullName;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *cbDatabase;
    QWidget *wPin;
    QGridLayout *gridLayout_2;
    QLineEdit *lePin;
    QPushButton *btn9;
    QPushButton *btn8;
    QPushButton *btnCancel2;
    QPushButton *btn1;
    QPushButton *btn7;
    QPushButton *btnLoginPin;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn6;
    QPushButton *btn5;
    QPushButton *btn0;
    QPushButton *btn4;
    QPushButton *btnClearPin;
    QLabel *lbF1;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(460, 433);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Login->sizePolicy().hasHeightForWidth());
        Login->setSizePolicy(sizePolicy);
        formLayout = new QFormLayout(Login);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lbLogo = new QLabel(Login);
        lbLogo->setObjectName(QString::fromUtf8("lbLogo"));
        lbLogo->setMinimumSize(QSize(160, 160));
        lbLogo->setMaximumSize(QSize(160, 160));
        lbLogo->setFrameShape(QFrame::Box);
        lbLogo->setFrameShadow(QFrame::Raised);
        lbLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/app.png")));
        lbLogo->setScaledContents(true);
        lbLogo->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, lbLogo);

        widget = new QWidget(Login);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        wUsernamePassword = new QWidget(widget);
        wUsernamePassword->setObjectName(QString::fromUtf8("wUsernamePassword"));
        gridLayout_3 = new QGridLayout(wUsernamePassword);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lePassword = new QLineEdit(wUsernamePassword);
        lePassword->setObjectName(QString::fromUtf8("lePassword"));
        lePassword->setEchoMode(QLineEdit::Password);

        gridLayout_3->addWidget(lePassword, 1, 1, 1, 1);

        label_2 = new QLabel(wUsernamePassword);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(wUsernamePassword);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        widget_2 = new QWidget(wUsernamePassword);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnLogin = new QPushButton(widget_2);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));

        horizontalLayout_2->addWidget(btnLogin);

        btnCancel = new QPushButton(widget_2);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_2->addWidget(btnCancel);


        gridLayout_3->addWidget(widget_2, 3, 0, 1, 2);

        leUsername = new QLineEdit(wUsernamePassword);
        leUsername->setObjectName(QString::fromUtf8("leUsername"));

        gridLayout_3->addWidget(leUsername, 0, 1, 1, 1);

        lbFullName = new QLabel(wUsernamePassword);
        lbFullName->setObjectName(QString::fromUtf8("lbFullName"));

        gridLayout_3->addWidget(lbFullName, 2, 0, 1, 2);


        gridLayout->addWidget(wUsernamePassword, 2, 0, 1, 1);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(0, 20));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        cbDatabase = new QComboBox(widget_3);
        cbDatabase->setObjectName(QString::fromUtf8("cbDatabase"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cbDatabase->sizePolicy().hasHeightForWidth());
        cbDatabase->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(cbDatabase);


        gridLayout->addWidget(widget_3, 0, 0, 1, 1);

        wPin = new QWidget(widget);
        wPin->setObjectName(QString::fromUtf8("wPin"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(wPin->sizePolicy().hasHeightForWidth());
        wPin->setSizePolicy(sizePolicy2);
        gridLayout_2 = new QGridLayout(wPin);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lePin = new QLineEdit(wPin);
        lePin->setObjectName(QString::fromUtf8("lePin"));
        lePin->setEchoMode(QLineEdit::Password);
        lePin->setReadOnly(true);

        gridLayout_2->addWidget(lePin, 0, 0, 1, 3);

        btn9 = new QPushButton(wPin);
        btn9->setObjectName(QString::fromUtf8("btn9"));
        btn9->setMinimumSize(QSize(60, 60));
        btn9->setMaximumSize(QSize(60, 16777215));

        gridLayout_2->addWidget(btn9, 4, 1, 1, 1);

        btn8 = new QPushButton(wPin);
        btn8->setObjectName(QString::fromUtf8("btn8"));
        btn8->setMinimumSize(QSize(60, 60));
        btn8->setMaximumSize(QSize(60, 16777215));

        gridLayout_2->addWidget(btn8, 2, 3, 1, 1);

        btnCancel2 = new QPushButton(wPin);
        btnCancel2->setObjectName(QString::fromUtf8("btnCancel2"));
        btnCancel2->setMinimumSize(QSize(60, 60));
        btnCancel2->setMaximumSize(QSize(60, 16777215));

        gridLayout_2->addWidget(btnCancel2, 4, 3, 1, 1);

        btn1 = new QPushButton(wPin);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        btn1->setMinimumSize(QSize(60, 60));
        btn1->setMaximumSize(QSize(60, 16777215));

        gridLayout_2->addWidget(btn1, 1, 0, 1, 1);

        btn7 = new QPushButton(wPin);
        btn7->setObjectName(QString::fromUtf8("btn7"));
        btn7->setMinimumSize(QSize(60, 60));
        btn7->setMaximumSize(QSize(60, 16777215));

        gridLayout_2->addWidget(btn7, 2, 2, 1, 1);

        btnLoginPin = new QPushButton(wPin);
        btnLoginPin->setObjectName(QString::fromUtf8("btnLoginPin"));
        btnLoginPin->setMinimumSize(QSize(60, 60));
        btnLoginPin->setMaximumSize(QSize(60, 16777215));

        gridLayout_2->addWidget(btnLoginPin, 4, 0, 1, 1);

        btn2 = new QPushButton(wPin);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        btn2->setMinimumSize(QSize(60, 60));
        btn2->setMaximumSize(QSize(60, 16777215));

        gridLayout_2->addWidget(btn2, 1, 1, 1, 1);

        btn3 = new QPushButton(wPin);
        btn3->setObjectName(QString::fromUtf8("btn3"));
        btn3->setMinimumSize(QSize(60, 60));
        btn3->setMaximumSize(QSize(60, 16777215));

        gridLayout_2->addWidget(btn3, 1, 2, 1, 1);

        btn6 = new QPushButton(wPin);
        btn6->setObjectName(QString::fromUtf8("btn6"));
        btn6->setMinimumSize(QSize(60, 60));
        btn6->setMaximumSize(QSize(60, 16777215));

        gridLayout_2->addWidget(btn6, 2, 1, 1, 1);

        btn5 = new QPushButton(wPin);
        btn5->setObjectName(QString::fromUtf8("btn5"));
        btn5->setMinimumSize(QSize(60, 60));
        btn5->setMaximumSize(QSize(60, 16777215));

        gridLayout_2->addWidget(btn5, 2, 0, 1, 1);

        btn0 = new QPushButton(wPin);
        btn0->setObjectName(QString::fromUtf8("btn0"));
        btn0->setMinimumSize(QSize(60, 60));
        btn0->setMaximumSize(QSize(60, 16777215));

        gridLayout_2->addWidget(btn0, 4, 2, 1, 1);

        btn4 = new QPushButton(wPin);
        btn4->setObjectName(QString::fromUtf8("btn4"));
        btn4->setMinimumSize(QSize(60, 60));
        btn4->setMaximumSize(QSize(60, 16777215));

        gridLayout_2->addWidget(btn4, 1, 3, 1, 1);

        btnClearPin = new QPushButton(wPin);
        btnClearPin->setObjectName(QString::fromUtf8("btnClearPin"));
        btnClearPin->setMinimumSize(QSize(60, 0));
        btnClearPin->setMaximumSize(QSize(60, 16777215));

        gridLayout_2->addWidget(btnClearPin, 0, 3, 1, 1);


        gridLayout->addWidget(wPin, 1, 0, 1, 1);


        formLayout->setWidget(0, QFormLayout::FieldRole, widget);

        lbF1 = new QLabel(Login);
        lbF1->setObjectName(QString::fromUtf8("lbF1"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lbF1->setFont(font);
        lbF1->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 127)"));
        lbF1->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::SpanningRole, lbF1);

        QWidget::setTabOrder(cbDatabase, lePin);
        QWidget::setTabOrder(lePin, btnClearPin);
        QWidget::setTabOrder(btnClearPin, btn1);
        QWidget::setTabOrder(btn1, btn2);
        QWidget::setTabOrder(btn2, btn3);
        QWidget::setTabOrder(btn3, btn4);
        QWidget::setTabOrder(btn4, btn5);
        QWidget::setTabOrder(btn5, btn6);
        QWidget::setTabOrder(btn6, btn7);
        QWidget::setTabOrder(btn7, btn8);
        QWidget::setTabOrder(btn8, btnLoginPin);
        QWidget::setTabOrder(btnLoginPin, btn9);
        QWidget::setTabOrder(btn9, btn0);
        QWidget::setTabOrder(btn0, btnCancel2);
        QWidget::setTabOrder(btnCancel2, leUsername);
        QWidget::setTabOrder(leUsername, lePassword);
        QWidget::setTabOrder(lePassword, btnLogin);
        QWidget::setTabOrder(btnLogin, btnCancel);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        lbLogo->setText(QString());
        label_2->setText(QCoreApplication::translate("Login", "Password", nullptr));
        label->setText(QCoreApplication::translate("Login", "Username", nullptr));
        btnLogin->setText(QCoreApplication::translate("Login", "Login", nullptr));
        btnCancel->setText(QCoreApplication::translate("Login", "Cancel", nullptr));
        lbFullName->setText(QString());
        label_3->setText(QCoreApplication::translate("Login", "Database", nullptr));
        btn9->setText(QCoreApplication::translate("Login", "9", nullptr));
        btn8->setText(QCoreApplication::translate("Login", "8", nullptr));
        btnCancel2->setText(QCoreApplication::translate("Login", "Cancel", nullptr));
        btn1->setText(QCoreApplication::translate("Login", "1", nullptr));
        btn7->setText(QCoreApplication::translate("Login", "7", nullptr));
        btnLoginPin->setText(QCoreApplication::translate("Login", "Login", nullptr));
        btn2->setText(QCoreApplication::translate("Login", "2", nullptr));
        btn3->setText(QCoreApplication::translate("Login", "3", nullptr));
        btn6->setText(QCoreApplication::translate("Login", "6", nullptr));
        btn5->setText(QCoreApplication::translate("Login", "5", nullptr));
        btn0->setText(QCoreApplication::translate("Login", "0", nullptr));
        btn4->setText(QCoreApplication::translate("Login", "4", nullptr));
        btnClearPin->setText(QCoreApplication::translate("Login", "X", nullptr));
        lbF1->setText(QCoreApplication::translate("Login", "Press F1 to  for first setup\n"
"or contact to administrator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
