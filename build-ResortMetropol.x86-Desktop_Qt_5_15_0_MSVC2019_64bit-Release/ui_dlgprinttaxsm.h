/********************************************************************************
** Form generated from reading UI file 'dlgprinttaxsm.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGPRINTTAXSM_H
#define UI_DLGPRINTTAXSM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgPrintTaxSM
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QPlainTextEdit *teResult;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnRetry;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgPrintTaxSM)
    {
        if (DlgPrintTaxSM->objectName().isEmpty())
            DlgPrintTaxSM->setObjectName(QString::fromUtf8("DlgPrintTaxSM"));
        DlgPrintTaxSM->resize(741, 482);
        horizontalLayout = new QHBoxLayout(DlgPrintTaxSM);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(DlgPrintTaxSM);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(frame);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        teResult = new QPlainTextEdit(widget_2);
        teResult->setObjectName(QString::fromUtf8("teResult"));

        horizontalLayout_3->addWidget(teResult);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(231, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnRetry = new QPushButton(widget);
        btnRetry->setObjectName(QString::fromUtf8("btnRetry"));
        btnRetry->setEnabled(false);
        btnRetry->setMinimumSize(QSize(100, 50));
        btnRetry->setMaximumSize(QSize(100, 50));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRetry->setIcon(icon);

        horizontalLayout_2->addWidget(btnRetry);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMinimumSize(QSize(100, 50));
        btnCancel->setMaximumSize(QSize(100, 50));

        horizontalLayout_2->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(230, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);


        horizontalLayout->addWidget(frame);


        retranslateUi(DlgPrintTaxSM);

        QMetaObject::connectSlotsByName(DlgPrintTaxSM);
    } // setupUi

    void retranslateUi(QDialog *DlgPrintTaxSM)
    {
        DlgPrintTaxSM->setWindowTitle(QCoreApplication::translate("DlgPrintTaxSM", "Print tax", nullptr));
        btnRetry->setText(QCoreApplication::translate("DlgPrintTaxSM", "Retry", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgPrintTaxSM", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgPrintTaxSM: public Ui_DlgPrintTaxSM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGPRINTTAXSM_H
