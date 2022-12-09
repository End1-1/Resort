/********************************************************************************
** Form generated from reading UI file 'dlgreportbuildergroups.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGREPORTBUILDERGROUPS_H
#define UI_DLGREPORTBUILDERGROUPS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgReportBuilderGroups
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnNew;
    QPushButton *btnEdit;
    QPushButton *btnRemove;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnClose;
    QListWidget *lwList;

    void setupUi(QDialog *DlgReportBuilderGroups)
    {
        if (DlgReportBuilderGroups->objectName().isEmpty())
            DlgReportBuilderGroups->setObjectName(QString::fromUtf8("DlgReportBuilderGroups"));
        DlgReportBuilderGroups->resize(616, 594);
        verticalLayout = new QVBoxLayout(DlgReportBuilderGroups);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(DlgReportBuilderGroups);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnNew = new QPushButton(widget);
        btnNew->setObjectName(QString::fromUtf8("btnNew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNew->setIcon(icon);

        horizontalLayout->addWidget(btnNew);

        btnEdit = new QPushButton(widget);
        btnEdit->setObjectName(QString::fromUtf8("btnEdit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnEdit->setIcon(icon1);

        horizontalLayout->addWidget(btnEdit);

        btnRemove = new QPushButton(widget);
        btnRemove->setObjectName(QString::fromUtf8("btnRemove"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/garbage.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRemove->setIcon(icon2);

        horizontalLayout->addWidget(btnRemove);

        horizontalSpacer = new QSpacerItem(377, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnClose = new QPushButton(widget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon3);

        horizontalLayout->addWidget(btnClose);


        verticalLayout->addWidget(widget);

        lwList = new QListWidget(DlgReportBuilderGroups);
        lwList->setObjectName(QString::fromUtf8("lwList"));
        lwList->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(lwList);


        retranslateUi(DlgReportBuilderGroups);

        QMetaObject::connectSlotsByName(DlgReportBuilderGroups);
    } // setupUi

    void retranslateUi(QDialog *DlgReportBuilderGroups)
    {
        DlgReportBuilderGroups->setWindowTitle(QCoreApplication::translate("DlgReportBuilderGroups", "Dialog", nullptr));
        btnNew->setText(QString());
        btnEdit->setText(QString());
        btnRemove->setText(QString());
        btnClose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DlgReportBuilderGroups: public Ui_DlgReportBuilderGroups {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGREPORTBUILDERGROUPS_H
