/********************************************************************************
** Form generated from reading UI file 'fcashreport.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCASHREPORT_H
#define UI_FCASHREPORT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_FCashReport
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QToolButton *toolButton;
    EDateEdit *deFrom;
    QLabel *label_2;
    EDateEdit *deTo;
    QToolButton *toolButton_2;
    QCheckBox *chHotel;
    QCheckBox *chRestaurant;
    EQLineEdit *lePayments;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    EQLineEdit *leOperator;
    EQLineEdit *leOperatorName;

    void setupUi(QWidget *FCashReport)
    {
        if (FCashReport->objectName().isEmpty())
            FCashReport->setObjectName(QString::fromUtf8("FCashReport"));
        FCashReport->resize(1014, 42);
        horizontalLayout_2 = new QHBoxLayout(FCashReport);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FCashReport);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        toolButton = new QToolButton(FCashReport);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);

        horizontalLayout->addWidget(toolButton);

        deFrom = new EDateEdit(FCashReport);
        deFrom->setObjectName(QString::fromUtf8("deFrom"));

        horizontalLayout->addWidget(deFrom);

        label_2 = new QLabel(FCashReport);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        deTo = new EDateEdit(FCashReport);
        deTo->setObjectName(QString::fromUtf8("deTo"));

        horizontalLayout->addWidget(deTo);

        toolButton_2 = new QToolButton(FCashReport);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);

        horizontalLayout->addWidget(toolButton_2);

        chHotel = new QCheckBox(FCashReport);
        chHotel->setObjectName(QString::fromUtf8("chHotel"));
        chHotel->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(chHotel);

        chRestaurant = new QCheckBox(FCashReport);
        chRestaurant->setObjectName(QString::fromUtf8("chRestaurant"));
        chRestaurant->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(chRestaurant);

        lePayments = new EQLineEdit(FCashReport);
        lePayments->setObjectName(QString::fromUtf8("lePayments"));

        horizontalLayout->addWidget(lePayments);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(FCashReport);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        leOperator = new EQLineEdit(FCashReport);
        leOperator->setObjectName(QString::fromUtf8("leOperator"));
        leOperator->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(leOperator);

        leOperatorName = new EQLineEdit(FCashReport);
        leOperatorName->setObjectName(QString::fromUtf8("leOperatorName"));
        leOperatorName->setReadOnly(true);

        horizontalLayout->addWidget(leOperatorName);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(FCashReport);

        QMetaObject::connectSlotsByName(FCashReport);
    } // setupUi

    void retranslateUi(QWidget *FCashReport)
    {
        FCashReport->setWindowTitle(QCoreApplication::translate("FCashReport", "Form", nullptr));
        label->setText(QCoreApplication::translate("FCashReport", "From", nullptr));
        toolButton->setText(QCoreApplication::translate("FCashReport", "...", nullptr));
        label_2->setText(QCoreApplication::translate("FCashReport", "To", nullptr));
        toolButton_2->setText(QCoreApplication::translate("FCashReport", "...", nullptr));
        chHotel->setText(QCoreApplication::translate("FCashReport", "Hotel", nullptr));
        chRestaurant->setText(QCoreApplication::translate("FCashReport", "Restaurant", nullptr));
        label_3->setText(QCoreApplication::translate("FCashReport", "Operator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FCashReport: public Ui_FCashReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCASHREPORT_H
