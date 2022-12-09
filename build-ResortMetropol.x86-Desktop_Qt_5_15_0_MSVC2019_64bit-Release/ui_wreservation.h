/********************************************************************************
** Form generated from reading UI file 'wreservation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WRESERVATION_H
#define UI_WRESERVATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_WReservation
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnCopyLast;
    QPushButton *btnSave;
    QPushButton *btnCheckIn;
    QPushButton *btnInvoice;
    QPushButton *btnPrint;
    QPushButton *btnSendConfirmation;
    QPushButton *btnCancelation;
    QPushButton *btnRecheckin;
    QPushButton *btnRevive;
    QLabel *lbGroup;
    EQLineEdit *leGroup;
    QLineEdit *leGroupName;
    QPushButton *btnSetGroupParams;
    QPushButton *btnAddRemoveGroup;
    QPushButton *btnCancelGroup;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnTracking;
    QPushButton *btnHelp;
    QTabWidget *tab;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *lbAuthor;
    QSpacerItem *horizontalSpacer;
    QLabel *lbLastModify;

    void setupUi(QWidget *WReservation)
    {
        if (WReservation->objectName().isEmpty())
            WReservation->setObjectName(QString::fromUtf8("WReservation"));
        WReservation->resize(1310, 607);
        WReservation->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(WReservation);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(-1, -1, -1, 0);
        widget_3 = new QWidget(WReservation);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(0, 0));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(2, 2, 2, 2);
        btnCopyLast = new QPushButton(widget_3);
        btnCopyLast->setObjectName(QString::fromUtf8("btnCopyLast"));
        btnCopyLast->setMinimumSize(QSize(0, 28));
        btnCopyLast->setMaximumSize(QSize(222, 28));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCopyLast->setIcon(icon);
        btnCopyLast->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(btnCopyLast);

        btnSave = new QPushButton(widget_3);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setMinimumSize(QSize(0, 28));
        btnSave->setMaximumSize(QSize(222, 28));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSave->setIcon(icon1);
        btnSave->setIconSize(QSize(20, 20));
        btnSave->setFlat(false);

        horizontalLayout_3->addWidget(btnSave);

        btnCheckIn = new QPushButton(widget_3);
        btnCheckIn->setObjectName(QString::fromUtf8("btnCheckIn"));
        btnCheckIn->setMinimumSize(QSize(0, 28));
        btnCheckIn->setMaximumSize(QSize(222, 28));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/checkin.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCheckIn->setIcon(icon2);
        btnCheckIn->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(btnCheckIn);

        btnInvoice = new QPushButton(widget_3);
        btnInvoice->setObjectName(QString::fromUtf8("btnInvoice"));
        btnInvoice->setMaximumSize(QSize(2222, 2222));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/invoice.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnInvoice->setIcon(icon3);

        horizontalLayout_3->addWidget(btnInvoice);

        btnPrint = new QPushButton(widget_3);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));
        btnPrint->setMinimumSize(QSize(0, 28));
        btnPrint->setMaximumSize(QSize(222, 28));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrint->setIcon(icon4);
        btnPrint->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(btnPrint);

        btnSendConfirmation = new QPushButton(widget_3);
        btnSendConfirmation->setObjectName(QString::fromUtf8("btnSendConfirmation"));
        btnSendConfirmation->setMinimumSize(QSize(0, 28));
        btnSendConfirmation->setMaximumSize(QSize(222, 28));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/email.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSendConfirmation->setIcon(icon5);
        btnSendConfirmation->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(btnSendConfirmation);

        btnCancelation = new QPushButton(widget_3);
        btnCancelation->setObjectName(QString::fromUtf8("btnCancelation"));
        btnCancelation->setMinimumSize(QSize(0, 28));
        btnCancelation->setMaximumSize(QSize(222, 28));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/garbage.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancelation->setIcon(icon6);
        btnCancelation->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(btnCancelation);

        btnRecheckin = new QPushButton(widget_3);
        btnRecheckin->setObjectName(QString::fromUtf8("btnRecheckin"));
        btnRecheckin->setMinimumSize(QSize(0, 28));
        btnRecheckin->setMaximumSize(QSize(16777215, 28));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/goto.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRecheckin->setIcon(icon7);

        horizontalLayout_3->addWidget(btnRecheckin);

        btnRevive = new QPushButton(widget_3);
        btnRevive->setObjectName(QString::fromUtf8("btnRevive"));
        btnRevive->setMaximumSize(QSize(2222, 2222));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/heart-pulses.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRevive->setIcon(icon8);

        horizontalLayout_3->addWidget(btnRevive);

        lbGroup = new QLabel(widget_3);
        lbGroup->setObjectName(QString::fromUtf8("lbGroup"));

        horizontalLayout_3->addWidget(lbGroup);

        leGroup = new EQLineEdit(widget_3);
        leGroup->setObjectName(QString::fromUtf8("leGroup"));
        leGroup->setMaximumSize(QSize(70, 16777215));
        leGroup->setReadOnly(true);

        horizontalLayout_3->addWidget(leGroup);

        leGroupName = new QLineEdit(widget_3);
        leGroupName->setObjectName(QString::fromUtf8("leGroupName"));
        leGroupName->setEnabled(true);
        leGroupName->setMinimumSize(QSize(150, 0));
        leGroupName->setMaximumSize(QSize(150, 16777215));
        leGroupName->setReadOnly(true);

        horizontalLayout_3->addWidget(leGroupName);

        btnSetGroupParams = new QPushButton(widget_3);
        btnSetGroupParams->setObjectName(QString::fromUtf8("btnSetGroupParams"));
        btnSetGroupParams->setMaximumSize(QSize(222, 222));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSetGroupParams->setIcon(icon9);

        horizontalLayout_3->addWidget(btnSetGroupParams);

        btnAddRemoveGroup = new QPushButton(widget_3);
        btnAddRemoveGroup->setObjectName(QString::fromUtf8("btnAddRemoveGroup"));
        btnAddRemoveGroup->setMaximumSize(QSize(222, 222));
        btnAddRemoveGroup->setIcon(icon9);

        horizontalLayout_3->addWidget(btnAddRemoveGroup);

        btnCancelGroup = new QPushButton(widget_3);
        btnCancelGroup->setObjectName(QString::fromUtf8("btnCancelGroup"));
        btnCancelGroup->setMaximumSize(QSize(222, 222));
        btnCancelGroup->setIcon(icon6);

        horizontalLayout_3->addWidget(btnCancelGroup);

        horizontalSpacer_2 = new QSpacerItem(531, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        btnTracking = new QPushButton(widget_3);
        btnTracking->setObjectName(QString::fromUtf8("btnTracking"));
        btnTracking->setMinimumSize(QSize(24, 28));
        btnTracking->setMaximumSize(QSize(32, 24));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/tracking.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTracking->setIcon(icon10);
        btnTracking->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(btnTracking);

        btnHelp = new QPushButton(widget_3);
        btnHelp->setObjectName(QString::fromUtf8("btnHelp"));
        btnHelp->setMinimumSize(QSize(24, 28));
        btnHelp->setMaximumSize(QSize(32, 24));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHelp->setIcon(icon11);
        btnHelp->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(btnHelp);


        gridLayout->addWidget(widget_3, 0, 0, 1, 2);

        tab = new QTabWidget(WReservation);
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setTabsClosable(true);

        gridLayout->addWidget(tab, 1, 0, 1, 1);

        widget = new QWidget(WReservation);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 20));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lbAuthor = new QLabel(widget);
        lbAuthor->setObjectName(QString::fromUtf8("lbAuthor"));

        horizontalLayout->addWidget(lbAuthor);

        horizontalSpacer = new QSpacerItem(646, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lbLastModify = new QLabel(widget);
        lbLastModify->setObjectName(QString::fromUtf8("lbLastModify"));

        horizontalLayout->addWidget(lbLastModify);


        gridLayout->addWidget(widget, 2, 0, 1, 2);


        retranslateUi(WReservation);

        tab->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(WReservation);
    } // setupUi

    void retranslateUi(QWidget *WReservation)
    {
        WReservation->setWindowTitle(QCoreApplication::translate("WReservation", "Form", nullptr));
#if QT_CONFIG(tooltip)
        btnCopyLast->setToolTip(QCoreApplication::translate("WReservation", "Copy last reservation", nullptr));
#endif // QT_CONFIG(tooltip)
        btnCopyLast->setText(QCoreApplication::translate("WReservation", "Copy last", nullptr));
#if QT_CONFIG(tooltip)
        btnSave->setToolTip(QCoreApplication::translate("WReservation", "Save", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSave->setText(QCoreApplication::translate("WReservation", "Save", nullptr));
#if QT_CONFIG(tooltip)
        btnCheckIn->setToolTip(QCoreApplication::translate("WReservation", "Checkin", nullptr));
#endif // QT_CONFIG(tooltip)
        btnCheckIn->setText(QCoreApplication::translate("WReservation", "Checkin", nullptr));
        btnInvoice->setText(QCoreApplication::translate("WReservation", "Invoice", nullptr));
#if QT_CONFIG(tooltip)
        btnPrint->setToolTip(QCoreApplication::translate("WReservation", "Print", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPrint->setText(QCoreApplication::translate("WReservation", "Print", nullptr));
#if QT_CONFIG(tooltip)
        btnSendConfirmation->setToolTip(QCoreApplication::translate("WReservation", "Print", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSendConfirmation->setText(QCoreApplication::translate("WReservation", "Email confirmation", nullptr));
#if QT_CONFIG(tooltip)
        btnCancelation->setToolTip(QCoreApplication::translate("WReservation", "Cancel reservation", nullptr));
#endif // QT_CONFIG(tooltip)
        btnCancelation->setText(QCoreApplication::translate("WReservation", "Cancel", nullptr));
        btnRecheckin->setText(QCoreApplication::translate("WReservation", "Re-checkin", nullptr));
        btnRevive->setText(QCoreApplication::translate("WReservation", "Revive", nullptr));
        lbGroup->setText(QCoreApplication::translate("WReservation", "Group #", nullptr));
        btnSetGroupParams->setText(QCoreApplication::translate("WReservation", "Group params", nullptr));
        btnAddRemoveGroup->setText(QCoreApplication::translate("WReservation", "Add/Remove from group", nullptr));
        btnCancelGroup->setText(QCoreApplication::translate("WReservation", "Cancel Group", nullptr));
        btnTracking->setText(QString());
        btnHelp->setText(QString());
        lbAuthor->setText(QCoreApplication::translate("WReservation", "Author:", nullptr));
        lbLastModify->setText(QCoreApplication::translate("WReservation", "Last modify:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WReservation: public Ui_WReservation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WRESERVATION_H
