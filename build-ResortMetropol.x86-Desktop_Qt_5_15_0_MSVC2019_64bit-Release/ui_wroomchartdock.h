/********************************************************************************
** Form generated from reading UI file 'wroomchartdock.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WROOMCHARTDOCK_H
#define UI_WROOMCHARTDOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WRoomChartDock
{
public:
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QLabel *lbDepartureDate;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *lbGuestCount_2;
    QLabel *label_2;
    QLabel *lbGuestCount;
    QLabel *lbInvoice;
    QLabel *lbEntryDate;
    QLabel *lbCode;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QCommandLinkButton *btnReserve;
    QCommandLinkButton *btnInvoice;
    QCommandLinkButton *btnGroup;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *lbType;
    QLabel *lbStatus;
    QLabel *lbGuest;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *lbGroup;

    void setupUi(QDockWidget *WRoomChartDock)
    {
        if (WRoomChartDock->objectName().isEmpty())
            WRoomChartDock->setObjectName(QString::fromUtf8("WRoomChartDock"));
        WRoomChartDock->resize(576, 267);
        WRoomChartDock->setFloating(true);
        WRoomChartDock->setFeatures(QDockWidget::AllDockWidgetFeatures);
        WRoomChartDock->setAllowedAreas(Qt::NoDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lbDepartureDate = new QLabel(dockWidgetContents);
        lbDepartureDate->setObjectName(QString::fromUtf8("lbDepartureDate"));

        gridLayout->addWidget(lbDepartureDate, 9, 1, 1, 1);

        label_4 = new QLabel(dockWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(dockWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        lbGuestCount_2 = new QLabel(dockWidgetContents);
        lbGuestCount_2->setObjectName(QString::fromUtf8("lbGuestCount_2"));

        gridLayout->addWidget(lbGuestCount_2, 7, 1, 1, 1);

        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lbGuestCount = new QLabel(dockWidgetContents);
        lbGuestCount->setObjectName(QString::fromUtf8("lbGuestCount"));

        gridLayout->addWidget(lbGuestCount, 7, 0, 1, 1);

        lbInvoice = new QLabel(dockWidgetContents);
        lbInvoice->setObjectName(QString::fromUtf8("lbInvoice"));

        gridLayout->addWidget(lbInvoice, 3, 1, 1, 1);

        lbEntryDate = new QLabel(dockWidgetContents);
        lbEntryDate->setObjectName(QString::fromUtf8("lbEntryDate"));

        gridLayout->addWidget(lbEntryDate, 8, 1, 1, 1);

        lbCode = new QLabel(dockWidgetContents);
        lbCode->setObjectName(QString::fromUtf8("lbCode"));

        gridLayout->addWidget(lbCode, 2, 1, 1, 1);

        widget = new QWidget(dockWidgetContents);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 50));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(6, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnReserve = new QCommandLinkButton(widget);
        btnReserve->setObjectName(QString::fromUtf8("btnReserve"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnReserve->sizePolicy().hasHeightForWidth());
        btnReserve->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(btnReserve);

        btnInvoice = new QCommandLinkButton(widget);
        btnInvoice->setObjectName(QString::fromUtf8("btnInvoice"));
        sizePolicy.setHeightForWidth(btnInvoice->sizePolicy().hasHeightForWidth());
        btnInvoice->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(btnInvoice);

        btnGroup = new QCommandLinkButton(widget);
        btnGroup->setObjectName(QString::fromUtf8("btnGroup"));
        sizePolicy.setHeightForWidth(btnGroup->sizePolicy().hasHeightForWidth());
        btnGroup->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(btnGroup);

        horizontalSpacer_2 = new QSpacerItem(6, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 12, 0, 1, 2);

        label_6 = new QLabel(dockWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        label_7 = new QLabel(dockWidgetContents);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 8, 0, 1, 1);

        lbType = new QLabel(dockWidgetContents);
        lbType->setObjectName(QString::fromUtf8("lbType"));

        gridLayout->addWidget(lbType, 1, 1, 1, 1);

        lbStatus = new QLabel(dockWidgetContents);
        lbStatus->setObjectName(QString::fromUtf8("lbStatus"));

        gridLayout->addWidget(lbStatus, 0, 1, 1, 1);

        lbGuest = new QLabel(dockWidgetContents);
        lbGuest->setObjectName(QString::fromUtf8("lbGuest"));

        gridLayout->addWidget(lbGuest, 6, 1, 1, 1);

        label = new QLabel(dockWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setOpenExternalLinks(true);
        label->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 13, 1, 1, 1);

        label_8 = new QLabel(dockWidgetContents);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 9, 0, 1, 1);

        label_5 = new QLabel(dockWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        lbGroup = new QLabel(dockWidgetContents);
        lbGroup->setObjectName(QString::fromUtf8("lbGroup"));

        gridLayout->addWidget(lbGroup, 4, 1, 1, 1);

        WRoomChartDock->setWidget(dockWidgetContents);

        retranslateUi(WRoomChartDock);

        QMetaObject::connectSlotsByName(WRoomChartDock);
    } // setupUi

    void retranslateUi(QDockWidget *WRoomChartDock)
    {
        WRoomChartDock->setWindowTitle(QCoreApplication::translate("WRoomChartDock", "DockWidget", nullptr));
        lbDepartureDate->setText(QCoreApplication::translate("WRoomChartDock", "Departure", nullptr));
        label_4->setText(QCoreApplication::translate("WRoomChartDock", "Reservation type", nullptr));
        label_3->setText(QCoreApplication::translate("WRoomChartDock", "Invoice number", nullptr));
        lbGuestCount_2->setText(QCoreApplication::translate("WRoomChartDock", "Guest count", nullptr));
        label_2->setText(QCoreApplication::translate("WRoomChartDock", "Status", nullptr));
        lbGuestCount->setText(QCoreApplication::translate("WRoomChartDock", "Guests count", nullptr));
        lbInvoice->setText(QCoreApplication::translate("WRoomChartDock", "Invoice", nullptr));
        lbEntryDate->setText(QCoreApplication::translate("WRoomChartDock", "Entry", nullptr));
        lbCode->setText(QCoreApplication::translate("WRoomChartDock", "Code", nullptr));
        btnReserve->setText(QCoreApplication::translate("WRoomChartDock", "Open reservation", nullptr));
        btnInvoice->setText(QCoreApplication::translate("WRoomChartDock", "OpenInvoice", nullptr));
        btnGroup->setText(QCoreApplication::translate("WRoomChartDock", "Open group", nullptr));
        label_6->setText(QCoreApplication::translate("WRoomChartDock", "Group", nullptr));
        label_7->setText(QCoreApplication::translate("WRoomChartDock", "Entry date", nullptr));
        lbType->setText(QCoreApplication::translate("WRoomChartDock", "Type", nullptr));
        lbStatus->setText(QCoreApplication::translate("WRoomChartDock", "Status", nullptr));
        lbGuest->setText(QCoreApplication::translate("WRoomChartDock", "Guest", nullptr));
        label->setText(QCoreApplication::translate("WRoomChartDock", "Reservation code", nullptr));
        label_8->setText(QCoreApplication::translate("WRoomChartDock", "Departure date", nullptr));
        label_5->setText(QCoreApplication::translate("WRoomChartDock", "Guests", nullptr));
        lbGroup->setText(QCoreApplication::translate("WRoomChartDock", "Group", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WRoomChartDock: public Ui_WRoomChartDock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WROOMCHARTDOCK_H
