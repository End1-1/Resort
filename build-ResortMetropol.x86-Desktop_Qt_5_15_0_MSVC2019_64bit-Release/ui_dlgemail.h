/********************************************************************************
** Form generated from reading UI file 'dlgemail.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGEMAIL_H
#define UI_DLGEMAIL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_DlgEmail
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label;
    QComboBox *cbFrom;
    QLabel *label_2;
    QLineEdit *leTo;
    QLineEdit *leSubject;
    QToolButton *btnSend;
    QPlainTextEdit *ptBody;

    void setupUi(QDialog *DlgEmail)
    {
        if (DlgEmail->objectName().isEmpty())
            DlgEmail->setObjectName(QString::fromUtf8("DlgEmail"));
        DlgEmail->resize(702, 532);
        gridLayout = new QGridLayout(DlgEmail);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(DlgEmail);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label = new QLabel(DlgEmail);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        cbFrom = new QComboBox(DlgEmail);
        cbFrom->setObjectName(QString::fromUtf8("cbFrom"));

        gridLayout->addWidget(cbFrom, 0, 1, 1, 1);

        label_2 = new QLabel(DlgEmail);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        leTo = new QLineEdit(DlgEmail);
        leTo->setObjectName(QString::fromUtf8("leTo"));

        gridLayout->addWidget(leTo, 1, 1, 1, 1);

        leSubject = new QLineEdit(DlgEmail);
        leSubject->setObjectName(QString::fromUtf8("leSubject"));

        gridLayout->addWidget(leSubject, 2, 1, 1, 1);

        btnSend = new QToolButton(DlgEmail);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnSend->sizePolicy().hasHeightForWidth());
        btnSend->setSizePolicy(sizePolicy);
        btnSend->setMinimumSize(QSize(50, 50));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/paper-plane.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSend->setIcon(icon);
        btnSend->setIconSize(QSize(32, 32));
        btnSend->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnSend, 0, 2, 3, 1);

        ptBody = new QPlainTextEdit(DlgEmail);
        ptBody->setObjectName(QString::fromUtf8("ptBody"));

        gridLayout->addWidget(ptBody, 3, 0, 1, 3);


        retranslateUi(DlgEmail);

        QMetaObject::connectSlotsByName(DlgEmail);
    } // setupUi

    void retranslateUi(QDialog *DlgEmail)
    {
        DlgEmail->setWindowTitle(QCoreApplication::translate("DlgEmail", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("DlgEmail", "From", nullptr));
        label->setText(QCoreApplication::translate("DlgEmail", "To", nullptr));
        label_2->setText(QCoreApplication::translate("DlgEmail", "Subject", nullptr));
        btnSend->setText(QCoreApplication::translate("DlgEmail", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgEmail: public Ui_DlgEmail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGEMAIL_H
