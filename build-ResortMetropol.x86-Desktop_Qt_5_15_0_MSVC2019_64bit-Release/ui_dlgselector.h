/********************************************************************************
** Form generated from reading UI file 'dlgselector.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGSELECTOR_H
#define UI_DLGSELECTOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgSelector
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    EQLineEdit *lineEdit;
    QPushButton *btnRefresh;
    EQTableWidget *tblData;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOK;
    QPushButton *btnCacnel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgSelector)
    {
        if (DlgSelector->objectName().isEmpty())
            DlgSelector->setObjectName(QString::fromUtf8("DlgSelector"));
        DlgSelector->resize(871, 519);
        verticalLayout = new QVBoxLayout(DlgSelector);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(9, 9, 9, 9);
        widget = new QWidget(DlgSelector);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new EQLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        btnRefresh = new QPushButton(widget);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));
        btnRefresh->setMinimumSize(QSize(25, 25));
        btnRefresh->setMaximumSize(QSize(100, 25));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/change.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon);

        horizontalLayout->addWidget(btnRefresh);


        verticalLayout->addWidget(widget);

        tblData = new EQTableWidget(DlgSelector);
        tblData->setObjectName(QString::fromUtf8("tblData"));
        tblData->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblData->setSelectionMode(QAbstractItemView::SingleSelection);
        tblData->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblData->setWordWrap(false);

        verticalLayout->addWidget(tblData);

        widget_2 = new QWidget(DlgSelector);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 30));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(331, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnOK = new QPushButton(widget_2);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));

        horizontalLayout_2->addWidget(btnOK);

        btnCacnel = new QPushButton(widget_2);
        btnCacnel->setObjectName(QString::fromUtf8("btnCacnel"));

        horizontalLayout_2->addWidget(btnCacnel);

        horizontalSpacer_2 = new QSpacerItem(330, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_2);

        QWidget::setTabOrder(lineEdit, tblData);
        QWidget::setTabOrder(tblData, btnRefresh);
        QWidget::setTabOrder(btnRefresh, btnOK);
        QWidget::setTabOrder(btnOK, btnCacnel);

        retranslateUi(DlgSelector);

        QMetaObject::connectSlotsByName(DlgSelector);
    } // setupUi

    void retranslateUi(QDialog *DlgSelector)
    {
        DlgSelector->setWindowTitle(QCoreApplication::translate("DlgSelector", "Dialog", nullptr));
        btnRefresh->setText(QCoreApplication::translate("DlgSelector", "Refresh", nullptr));
        btnOK->setText(QCoreApplication::translate("DlgSelector", "OK", nullptr));
        btnCacnel->setText(QCoreApplication::translate("DlgSelector", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgSelector: public Ui_DlgSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGSELECTOR_H
