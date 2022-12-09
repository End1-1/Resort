/********************************************************************************
** Form generated from reading UI file 'wroomchart.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WROOMCHART_H
#define UI_WROOMCHART_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WRoomChart
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnReset;
    QPushButton *btnFilter;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *mainView;
    QWidget *wToolbar;
    QHBoxLayout *horizontalLayout_2;
    QWidget *wCat;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *hlCat;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnNewReservation;
    QSpacerItem *horizontalSpacer;
    QScrollArea *scrollRoom;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_2;
    QGraphicsView *roomView;
    QScrollArea *scrollDate;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_3;
    QGraphicsView *dateView;

    void setupUi(QWidget *WRoomChart)
    {
        if (WRoomChart->objectName().isEmpty())
            WRoomChart->setObjectName(QString::fromUtf8("WRoomChart"));
        WRoomChart->resize(954, 552);
        WRoomChart->setMouseTracking(false);
        gridLayout = new QGridLayout(WRoomChart);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(WRoomChart);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(16777215, 52));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnReset = new QPushButton(widget);
        btnReset->setObjectName(QString::fromUtf8("btnReset"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnReset->sizePolicy().hasHeightForWidth());
        btnReset->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(btnReset);

        btnFilter = new QPushButton(widget);
        btnFilter->setObjectName(QString::fromUtf8("btnFilter"));
        sizePolicy.setHeightForWidth(btnFilter->sizePolicy().hasHeightForWidth());
        btnFilter->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(btnFilter);


        gridLayout->addWidget(widget, 1, 0, 1, 1);

        scrollArea = new QScrollArea(WRoomChart);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 862, 459));
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        mainView = new QGraphicsView(scrollAreaWidgetContents);
        mainView->setObjectName(QString::fromUtf8("mainView"));
        mainView->setMouseTracking(true);
        mainView->setStyleSheet(QString::fromUtf8("border: 1px solid green;"));
        mainView->setFrameShape(QFrame::NoFrame);
        mainView->setFrameShadow(QFrame::Plain);
        mainView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        mainView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        mainView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout->addWidget(mainView);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 5, 2, 1, 1);

        wToolbar = new QWidget(WRoomChart);
        wToolbar->setObjectName(QString::fromUtf8("wToolbar"));
        wToolbar->setMinimumSize(QSize(0, 20));
        horizontalLayout_2 = new QHBoxLayout(wToolbar);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        wCat = new QWidget(wToolbar);
        wCat->setObjectName(QString::fromUtf8("wCat"));
        horizontalLayout_3 = new QHBoxLayout(wCat);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        hlCat = new QHBoxLayout();
        hlCat->setSpacing(1);
        hlCat->setObjectName(QString::fromUtf8("hlCat"));

        horizontalLayout_3->addLayout(hlCat);


        horizontalLayout_2->addWidget(wCat);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btnNewReservation = new QPushButton(wToolbar);
        btnNewReservation->setObjectName(QString::fromUtf8("btnNewReservation"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/checkin.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNewReservation->setIcon(icon);

        horizontalLayout_2->addWidget(btnNewReservation);

        horizontalSpacer = new QSpacerItem(943, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addWidget(wToolbar, 0, 0, 1, 3);

        scrollRoom = new QScrollArea(WRoomChart);
        scrollRoom->setObjectName(QString::fromUtf8("scrollRoom"));
        scrollRoom->setMaximumSize(QSize(81, 16777215));
        scrollRoom->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollRoom->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollRoom->setWidgetResizable(true);
        scrollRoom->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 73, 457));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        roomView = new QGraphicsView(scrollAreaWidgetContents_2);
        roomView->setObjectName(QString::fromUtf8("roomView"));
        roomView->setMaximumSize(QSize(80, 16777215));
        roomView->setStyleSheet(QString::fromUtf8("border-top: 1px solid green;\n"
"border-left: 1px solid green;\n"
"border-bottom: 1px solid green;"));
        roomView->setFrameShape(QFrame::StyledPanel);
        roomView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        roomView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        roomView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_2->addWidget(roomView);

        scrollRoom->setWidget(scrollAreaWidgetContents_2);

        gridLayout->addWidget(scrollRoom, 2, 0, 4, 1);

        scrollDate = new QScrollArea(WRoomChart);
        scrollDate->setObjectName(QString::fromUtf8("scrollDate"));
        scrollDate->setMaximumSize(QSize(16777215, 52));
        scrollDate->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollDate->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollDate->setWidgetResizable(true);
        scrollDate->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 860, 50));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        dateView = new QGraphicsView(scrollAreaWidgetContents_3);
        dateView->setObjectName(QString::fromUtf8("dateView"));
        dateView->setMinimumSize(QSize(0, 50));
        dateView->setMaximumSize(QSize(16777215, 50));
        dateView->setStyleSheet(QString::fromUtf8("border-top: 1px solid green;\n"
"border-left: 1px solid green;\n"
"border-right: 1px solid green;"));
        dateView->setFrameShape(QFrame::NoFrame);
        dateView->setFrameShadow(QFrame::Plain);
        dateView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        dateView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        dateView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_3->addWidget(dateView);

        scrollDate->setWidget(scrollAreaWidgetContents_3);

        gridLayout->addWidget(scrollDate, 1, 2, 1, 1);


        retranslateUi(WRoomChart);

        QMetaObject::connectSlotsByName(WRoomChart);
    } // setupUi

    void retranslateUi(QWidget *WRoomChart)
    {
        WRoomChart->setWindowTitle(QCoreApplication::translate("WRoomChart", "Reservation info", nullptr));
        btnReset->setText(QCoreApplication::translate("WRoomChart", "Reset", nullptr));
        btnFilter->setText(QCoreApplication::translate("WRoomChart", "Filter", nullptr));
        btnNewReservation->setText(QCoreApplication::translate("WRoomChart", "New resevation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WRoomChart: public Ui_WRoomChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WROOMCHART_H
