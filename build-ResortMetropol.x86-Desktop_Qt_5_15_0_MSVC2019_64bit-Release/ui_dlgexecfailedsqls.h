/********************************************************************************
** Form generated from reading UI file 'dlgexecfailedsqls.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGEXECFAILEDSQLS_H
#define UI_DLGEXECFAILEDSQLS_H

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

class Ui_DlgExecFailedSqls
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbView;
    QLabel *lbAdd;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnStart;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgExecFailedSqls)
    {
        if (DlgExecFailedSqls->objectName().isEmpty())
            DlgExecFailedSqls->setObjectName(QString::fromUtf8("DlgExecFailedSqls"));
        DlgExecFailedSqls->resize(400, 300);
        verticalLayout = new QVBoxLayout(DlgExecFailedSqls);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(DlgExecFailedSqls);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lbView = new QLabel(widget_2);
        lbView->setObjectName(QString::fromUtf8("lbView"));
        lbView->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lbView);


        verticalLayout->addWidget(widget_2);

        lbAdd = new QLabel(DlgExecFailedSqls);
        lbAdd->setObjectName(QString::fromUtf8("lbAdd"));

        verticalLayout->addWidget(lbAdd);

        widget = new QWidget(DlgExecFailedSqls);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnStart = new QPushButton(widget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));

        horizontalLayout->addWidget(btnStart);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);


        retranslateUi(DlgExecFailedSqls);

        QMetaObject::connectSlotsByName(DlgExecFailedSqls);
    } // setupUi

    void retranslateUi(QDialog *DlgExecFailedSqls)
    {
        DlgExecFailedSqls->setWindowTitle(QCoreApplication::translate("DlgExecFailedSqls", "Failed sql", nullptr));
        lbView->setText(QCoreApplication::translate("DlgExecFailedSqls", "Info", nullptr));
        lbAdd->setText(QCoreApplication::translate("DlgExecFailedSqls", "...", nullptr));
        btnStart->setText(QCoreApplication::translate("DlgExecFailedSqls", "Start", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgExecFailedSqls", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgExecFailedSqls: public Ui_DlgExecFailedSqls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGEXECFAILEDSQLS_H
