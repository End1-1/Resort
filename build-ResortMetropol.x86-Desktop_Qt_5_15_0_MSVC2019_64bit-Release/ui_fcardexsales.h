/********************************************************************************
** Form generated from reading UI file 'fcardexsales.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCARDEXSALES_H
#define UI_FCARDEXSALES_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_FCardexSales
{
public:
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QToolButton *toolButton;
    EDateEdit *deFrom;
    QLabel *label_2;
    EDateEdit *deTo;
    QToolButton *toolButton_2;
    QLabel *label_5;
    QComboBox *cbReportType;
    QLabel *label_4;
    EQLineEdit *leCardex;
    QCheckBox *chGuestPart;
    QCheckBox *chCompanyPart;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QRadioButton *rbAmd;
    QRadioButton *rbUsd;
    QCheckBox *chNoVat;
    QCheckBox *chCheckin;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FCardexSales)
    {
        if (FCardexSales->objectName().isEmpty())
            FCardexSales->setObjectName(QString::fromUtf8("FCardexSales"));
        FCardexSales->resize(1043, 41);
        horizontalLayout_2 = new QHBoxLayout(FCardexSales);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(FCardexSales);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        toolButton = new QToolButton(FCardexSales);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);

        horizontalLayout_2->addWidget(toolButton);

        deFrom = new EDateEdit(FCardexSales);
        deFrom->setObjectName(QString::fromUtf8("deFrom"));
        deFrom->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(deFrom);

        label_2 = new QLabel(FCardexSales);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        deTo = new EDateEdit(FCardexSales);
        deTo->setObjectName(QString::fromUtf8("deTo"));
        deTo->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(deTo);

        toolButton_2 = new QToolButton(FCardexSales);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);

        horizontalLayout_2->addWidget(toolButton_2);

        label_5 = new QLabel(FCardexSales);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        cbReportType = new QComboBox(FCardexSales);
        cbReportType->addItem(QString());
        cbReportType->addItem(QString());
        cbReportType->setObjectName(QString::fromUtf8("cbReportType"));
        cbReportType->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_2->addWidget(cbReportType);

        label_4 = new QLabel(FCardexSales);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        leCardex = new EQLineEdit(FCardexSales);
        leCardex->setObjectName(QString::fromUtf8("leCardex"));
        leCardex->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_2->addWidget(leCardex);

        chGuestPart = new QCheckBox(FCardexSales);
        chGuestPart->setObjectName(QString::fromUtf8("chGuestPart"));
        chGuestPart->setFocusPolicy(Qt::ClickFocus);
        chGuestPart->setChecked(true);

        horizontalLayout_2->addWidget(chGuestPart);

        chCompanyPart = new QCheckBox(FCardexSales);
        chCompanyPart->setObjectName(QString::fromUtf8("chCompanyPart"));
        chCompanyPart->setFocusPolicy(Qt::ClickFocus);
        chCompanyPart->setChecked(true);

        horizontalLayout_2->addWidget(chCompanyPart);

        widget = new QWidget(FCardexSales);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        rbAmd = new QRadioButton(widget);
        rbAmd->setObjectName(QString::fromUtf8("rbAmd"));
        rbAmd->setFocusPolicy(Qt::ClickFocus);
        rbAmd->setChecked(true);

        horizontalLayout->addWidget(rbAmd);

        rbUsd = new QRadioButton(widget);
        rbUsd->setObjectName(QString::fromUtf8("rbUsd"));
        rbUsd->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(rbUsd);

        chNoVat = new QCheckBox(widget);
        chNoVat->setObjectName(QString::fromUtf8("chNoVat"));
        chNoVat->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(chNoVat);

        chCheckin = new QCheckBox(widget);
        chCheckin->setObjectName(QString::fromUtf8("chCheckin"));
        chCheckin->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(chCheckin);


        horizontalLayout_2->addWidget(widget);

        horizontalSpacer = new QSpacerItem(59, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        QWidget::setTabOrder(deFrom, deTo);
        QWidget::setTabOrder(deTo, leCardex);
        QWidget::setTabOrder(leCardex, chGuestPart);
        QWidget::setTabOrder(chGuestPart, chCompanyPart);

        retranslateUi(FCardexSales);

        QMetaObject::connectSlotsByName(FCardexSales);
    } // setupUi

    void retranslateUi(QWidget *FCardexSales)
    {
        FCardexSales->setWindowTitle(QCoreApplication::translate("FCardexSales", "Form", nullptr));
        label->setText(QCoreApplication::translate("FCardexSales", "Date From", nullptr));
        toolButton->setText(QCoreApplication::translate("FCardexSales", "...", nullptr));
        label_2->setText(QCoreApplication::translate("FCardexSales", "DateTo", nullptr));
        toolButton_2->setText(QCoreApplication::translate("FCardexSales", "...", nullptr));
        label_5->setText(QCoreApplication::translate("FCardexSales", "Report", nullptr));
        cbReportType->setItemText(0, QCoreApplication::translate("FCardexSales", "Guest", nullptr));
        cbReportType->setItemText(1, QCoreApplication::translate("FCardexSales", "Cardex", nullptr));

        label_4->setText(QCoreApplication::translate("FCardexSales", "Partner", nullptr));
        chGuestPart->setText(QCoreApplication::translate("FCardexSales", "Guest part", nullptr));
        chCompanyPart->setText(QCoreApplication::translate("FCardexSales", "Companty part", nullptr));
        label_3->setText(QCoreApplication::translate("FCardexSales", "Currency", nullptr));
        rbAmd->setText(QCoreApplication::translate("FCardexSales", "AMD", nullptr));
        rbUsd->setText(QCoreApplication::translate("FCardexSales", "USD", nullptr));
        chNoVat->setText(QCoreApplication::translate("FCardexSales", "No VAT", nullptr));
        chCheckin->setText(QCoreApplication::translate("FCardexSales", "Check in included", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FCardexSales: public Ui_FCardexSales {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCARDEXSALES_H
