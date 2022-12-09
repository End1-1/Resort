/********************************************************************************
** Form generated from reading UI file 'wcardex.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WCARDEX_H
#define UI_WCARDEX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_WCardex
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EQLineEdit *leCardex;
    EQLineEdit *leCardexName;

    void setupUi(QWidget *WCardex)
    {
        if (WCardex->objectName().isEmpty())
            WCardex->setObjectName(QString::fromUtf8("WCardex"));
        WCardex->resize(447, 20);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WCardex->sizePolicy().hasHeightForWidth());
        WCardex->setSizePolicy(sizePolicy);
        WCardex->setMaximumSize(QSize(450, 16777215));
        horizontalLayout = new QHBoxLayout(WCardex);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(WCardex);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label);

        leCardex = new EQLineEdit(WCardex);
        leCardex->setObjectName(QString::fromUtf8("leCardex"));
        leCardex->setMinimumSize(QSize(100, 0));
        leCardex->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(leCardex);

        leCardexName = new EQLineEdit(WCardex);
        leCardexName->setObjectName(QString::fromUtf8("leCardexName"));
        leCardexName->setMinimumSize(QSize(300, 0));
        leCardexName->setMaximumSize(QSize(300, 16777215));
        leCardexName->setReadOnly(true);

        horizontalLayout->addWidget(leCardexName);


        retranslateUi(WCardex);

        QMetaObject::connectSlotsByName(WCardex);
    } // setupUi

    void retranslateUi(QWidget *WCardex)
    {
        WCardex->setWindowTitle(QCoreApplication::translate("WCardex", "Form", nullptr));
        label->setText(QCoreApplication::translate("WCardex", "Cardex", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WCardex: public Ui_WCardex {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WCARDEX_H
