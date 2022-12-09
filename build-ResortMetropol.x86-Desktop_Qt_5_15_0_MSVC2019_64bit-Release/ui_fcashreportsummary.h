/********************************************************************************
** Form generated from reading UI file 'fcashreportsummary.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCASHREPORTSUMMARY_H
#define UI_FCASHREPORTSUMMARY_H

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

class Ui_FCashReportSummary
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QToolButton *btnBack;
    EDateEdit *deStart;
    QLabel *label_2;
    EDateEdit *deEnd;
    QToolButton *btnForward;
    QCheckBox *chHotel;
    QCheckBox *chRestaurant;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    EQLineEdit *leOperator;
    EQLineEdit *leOperatorName;

    void setupUi(QWidget *FCashReportSummary)
    {
        if (FCashReportSummary->objectName().isEmpty())
            FCashReportSummary->setObjectName(QString::fromUtf8("FCashReportSummary"));
        FCashReportSummary->resize(868, 40);
        horizontalLayout = new QHBoxLayout(FCashReportSummary);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FCashReportSummary);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        btnBack = new QToolButton(FCashReportSummary);
        btnBack->setObjectName(QString::fromUtf8("btnBack"));
        btnBack->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnBack->setIcon(icon);

        horizontalLayout->addWidget(btnBack);

        deStart = new EDateEdit(FCashReportSummary);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        horizontalLayout->addWidget(deStart);

        label_2 = new QLabel(FCashReportSummary);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        deEnd = new EDateEdit(FCashReportSummary);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        horizontalLayout->addWidget(deEnd);

        btnForward = new QToolButton(FCashReportSummary);
        btnForward->setObjectName(QString::fromUtf8("btnForward"));
        btnForward->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnForward->setIcon(icon1);

        horizontalLayout->addWidget(btnForward);

        chHotel = new QCheckBox(FCashReportSummary);
        chHotel->setObjectName(QString::fromUtf8("chHotel"));
        chHotel->setFocusPolicy(Qt::ClickFocus);
        chHotel->setChecked(true);

        horizontalLayout->addWidget(chHotel);

        chRestaurant = new QCheckBox(FCashReportSummary);
        chRestaurant->setObjectName(QString::fromUtf8("chRestaurant"));
        chRestaurant->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(chRestaurant);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(FCashReportSummary);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        leOperator = new EQLineEdit(FCashReportSummary);
        leOperator->setObjectName(QString::fromUtf8("leOperator"));
        leOperator->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(leOperator);

        leOperatorName = new EQLineEdit(FCashReportSummary);
        leOperatorName->setObjectName(QString::fromUtf8("leOperatorName"));
        leOperatorName->setReadOnly(true);

        horizontalLayout->addWidget(leOperatorName);


        retranslateUi(FCashReportSummary);

        QMetaObject::connectSlotsByName(FCashReportSummary);
    } // setupUi

    void retranslateUi(QWidget *FCashReportSummary)
    {
        FCashReportSummary->setWindowTitle(QCoreApplication::translate("FCashReportSummary", "Form", nullptr));
        label->setText(QCoreApplication::translate("FCashReportSummary", "From", nullptr));
        btnBack->setText(QCoreApplication::translate("FCashReportSummary", "...", nullptr));
        label_2->setText(QCoreApplication::translate("FCashReportSummary", "To", nullptr));
        btnForward->setText(QCoreApplication::translate("FCashReportSummary", "...", nullptr));
        chHotel->setText(QCoreApplication::translate("FCashReportSummary", "Hotel", nullptr));
        chRestaurant->setText(QCoreApplication::translate("FCashReportSummary", "Restaurant", nullptr));
        label_3->setText(QCoreApplication::translate("FCashReportSummary", "Operator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FCashReportSummary: public Ui_FCashReportSummary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCASHREPORTSUMMARY_H
