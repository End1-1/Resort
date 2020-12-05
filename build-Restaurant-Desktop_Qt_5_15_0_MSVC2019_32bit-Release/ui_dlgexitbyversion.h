/********************************************************************************
** Form generated from reading UI file 'dlgexitbyversion.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGEXITBYVERSION_H
#define UI_DLGEXITBYVERSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgExitByVersion
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lbMessage;
    QLabel *lbTime;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnClose;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgExitByVersion)
    {
        if (DlgExitByVersion->objectName().isEmpty())
            DlgExitByVersion->setObjectName(QString::fromUtf8("DlgExitByVersion"));
        DlgExitByVersion->resize(400, 300);
        verticalLayout = new QVBoxLayout(DlgExitByVersion);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lbMessage = new QLabel(DlgExitByVersion);
        lbMessage->setObjectName(QString::fromUtf8("lbMessage"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(lbMessage->sizePolicy().hasHeightForWidth());
        lbMessage->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        lbMessage->setFont(font);
        lbMessage->setStyleSheet(QString::fromUtf8("color:red;"));
        lbMessage->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lbMessage);

        lbTime = new QLabel(DlgExitByVersion);
        lbTime->setObjectName(QString::fromUtf8("lbTime"));
        lbTime->setFont(font);
        lbTime->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lbTime);

        widget = new QWidget(DlgExitByVersion);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(136, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnClose = new QPushButton(widget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        horizontalLayout->addWidget(btnClose);

        horizontalSpacer_2 = new QSpacerItem(135, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);


        retranslateUi(DlgExitByVersion);

        QMetaObject::connectSlotsByName(DlgExitByVersion);
    } // setupUi

    void retranslateUi(QDialog *DlgExitByVersion)
    {
        DlgExitByVersion->setWindowTitle(QCoreApplication::translate("DlgExitByVersion", "Exit", nullptr));
        lbMessage->setText(QCoreApplication::translate("DlgExitByVersion", "Message", nullptr));
        lbTime->setText(QCoreApplication::translate("DlgExitByVersion", "Time", nullptr));
        btnClose->setText(QCoreApplication::translate("DlgExitByVersion", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgExitByVersion: public Ui_DlgExitByVersion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGEXITBYVERSION_H
