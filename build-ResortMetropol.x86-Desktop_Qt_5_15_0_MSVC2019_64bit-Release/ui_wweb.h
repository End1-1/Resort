/********************************************************************************
** Form generated from reading UI file 'wweb.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WWEB_H
#define UI_WWEB_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WWeb
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *leAddress;
    QPushButton *btnGo;
    QSpacerItem *horizontalSpacer;
    QWidget *wv;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *vl;

    void setupUi(QWidget *WWeb)
    {
        if (WWeb->objectName().isEmpty())
            WWeb->setObjectName(QString::fromUtf8("WWeb"));
        WWeb->resize(1156, 780);
        verticalLayout = new QVBoxLayout(WWeb);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(WWeb);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        leAddress = new QLineEdit(widget);
        leAddress->setObjectName(QString::fromUtf8("leAddress"));

        horizontalLayout->addWidget(leAddress);

        btnGo = new QPushButton(widget);
        btnGo->setObjectName(QString::fromUtf8("btnGo"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/goto.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGo->setIcon(icon);

        horizontalLayout->addWidget(btnGo);

        horizontalSpacer = new QSpacerItem(531, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);

        wv = new QWidget(WWeb);
        wv->setObjectName(QString::fromUtf8("wv"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(wv->sizePolicy().hasHeightForWidth());
        wv->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(wv);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        vl = new QVBoxLayout();
        vl->setObjectName(QString::fromUtf8("vl"));

        horizontalLayout_2->addLayout(vl);


        verticalLayout->addWidget(wv);


        retranslateUi(WWeb);

        QMetaObject::connectSlotsByName(WWeb);
    } // setupUi

    void retranslateUi(QWidget *WWeb)
    {
        WWeb->setWindowTitle(QCoreApplication::translate("WWeb", "WEB", nullptr));
        label->setText(QCoreApplication::translate("WWeb", "Address", nullptr));
        btnGo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WWeb: public Ui_WWeb {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WWEB_H
