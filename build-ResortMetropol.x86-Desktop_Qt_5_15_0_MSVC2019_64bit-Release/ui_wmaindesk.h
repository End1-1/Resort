/********************************************************************************
** Form generated from reading UI file 'wmaindesk.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WMAINDESK_H
#define UI_WMAINDESK_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WMainDesk
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnFilterCategory;
    QWidget *wCatButtons;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *hlCatButtons;
    QPushButton *btnBuilding;
    QPushButton *btnBedFilter;
    QPushButton *btnSmokeFilter;
    QPushButton *btnRoomStateFilter;
    QLabel *lbRoomsCount;
    QLineEdit *leFilterGuest;
    QPushButton *btnShowDockHint;
    QPushButton *btnStatus;
    QPushButton *btnFilterCardex;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnRefreshChart;
    QPushButton *btnClearFilter;
    QPushButton *btnClearSelection;
    QWidget *wContainer;
    QGridLayout *gridLayout_3;
    QScrollArea *saDate;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tblMonth;
    QTableWidget *tblDay;
    QScrollArea *saMain;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout;
    QGraphicsView *g;
    QWidget *wRoom;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *saRoom;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tblRoom;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnJumpToDate;
    QLineEdit *leJumpToRoom;
    QGridLayout *gridLayout;
    QPushButton *btnScrollLeft;
    QToolButton *btnCheckin;
    QSpacerItem *verticalSpacer;
    QToolButton *btnTransferRoom;
    QPushButton *btnScrollUp;
    QToolButton *btnCheckIn;
    QToolButton *btnColors;
    QToolButton *btnCheckoutFilter;
    QToolButton *btnAirReserve;
    QPushButton *btnScrollRight;
    QToolButton *btnEndOfDay;
    QPushButton *btnScrollDown;
    QSpacerItem *verticalSpacer_2;
    QToolButton *btnPostCharge;
    QToolButton *btnInvoice;
    QToolButton *btnGroupReservation;

    void setupUi(QWidget *WMainDesk)
    {
        if (WMainDesk->objectName().isEmpty())
            WMainDesk->setObjectName(QString::fromUtf8("WMainDesk"));
        WMainDesk->resize(1166, 652);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WMainDesk->sizePolicy().hasHeightForWidth());
        WMainDesk->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(WMainDesk);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(2);
        gridLayout_2->setVerticalSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(WMainDesk);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMaximumSize(QSize(16777215, 31));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setSpacing(4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        btnFilterCategory = new QPushButton(widget_3);
        btnFilterCategory->setObjectName(QString::fromUtf8("btnFilterCategory"));
        btnFilterCategory->setStyleSheet(QString::fromUtf8("QPushButton:checked{background-color:rgb(178, 250, 184);}"));
        btnFilterCategory->setCheckable(false);
        btnFilterCategory->setChecked(false);

        horizontalLayout_3->addWidget(btnFilterCategory);

        wCatButtons = new QWidget(widget_3);
        wCatButtons->setObjectName(QString::fromUtf8("wCatButtons"));
        horizontalLayout_4 = new QHBoxLayout(wCatButtons);
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        hlCatButtons = new QHBoxLayout();
        hlCatButtons->setObjectName(QString::fromUtf8("hlCatButtons"));

        horizontalLayout_4->addLayout(hlCatButtons);


        horizontalLayout_3->addWidget(wCatButtons);

        btnBuilding = new QPushButton(widget_3);
        btnBuilding->setObjectName(QString::fromUtf8("btnBuilding"));

        horizontalLayout_3->addWidget(btnBuilding);

        btnBedFilter = new QPushButton(widget_3);
        btnBedFilter->setObjectName(QString::fromUtf8("btnBedFilter"));

        horizontalLayout_3->addWidget(btnBedFilter);

        btnSmokeFilter = new QPushButton(widget_3);
        btnSmokeFilter->setObjectName(QString::fromUtf8("btnSmokeFilter"));

        horizontalLayout_3->addWidget(btnSmokeFilter);

        btnRoomStateFilter = new QPushButton(widget_3);
        btnRoomStateFilter->setObjectName(QString::fromUtf8("btnRoomStateFilter"));

        horizontalLayout_3->addWidget(btnRoomStateFilter);

        lbRoomsCount = new QLabel(widget_3);
        lbRoomsCount->setObjectName(QString::fromUtf8("lbRoomsCount"));

        horizontalLayout_3->addWidget(lbRoomsCount);

        leFilterGuest = new QLineEdit(widget_3);
        leFilterGuest->setObjectName(QString::fromUtf8("leFilterGuest"));

        horizontalLayout_3->addWidget(leFilterGuest);

        btnShowDockHint = new QPushButton(widget_3);
        btnShowDockHint->setObjectName(QString::fromUtf8("btnShowDockHint"));
        btnShowDockHint->setMinimumSize(QSize(25, 25));
        btnShowDockHint->setMaximumSize(QSize(25, 25));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/funnel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnShowDockHint->setIcon(icon);

        horizontalLayout_3->addWidget(btnShowDockHint);

        btnStatus = new QPushButton(widget_3);
        btnStatus->setObjectName(QString::fromUtf8("btnStatus"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/ball-green.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStatus->setIcon(icon1);

        horizontalLayout_3->addWidget(btnStatus);

        btnFilterCardex = new QPushButton(widget_3);
        btnFilterCardex->setObjectName(QString::fromUtf8("btnFilterCardex"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/partner.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnFilterCardex->setIcon(icon2);
        btnFilterCardex->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(btnFilterCardex);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        btnRefreshChart = new QPushButton(widget_3);
        btnRefreshChart->setObjectName(QString::fromUtf8("btnRefreshChart"));
        btnRefreshChart->setMinimumSize(QSize(25, 25));
        btnRefreshChart->setMaximumSize(QSize(25, 25));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefreshChart->setIcon(icon3);
        btnRefreshChart->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(btnRefreshChart);

        btnClearFilter = new QPushButton(widget_3);
        btnClearFilter->setObjectName(QString::fromUtf8("btnClearFilter"));
        btnClearFilter->setMinimumSize(QSize(25, 25));
        btnClearFilter->setMaximumSize(QSize(25, 25));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/remove_filter.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClearFilter->setIcon(icon4);
        btnClearFilter->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(btnClearFilter);

        btnClearSelection = new QPushButton(widget_3);
        btnClearSelection->setObjectName(QString::fromUtf8("btnClearSelection"));
        btnClearSelection->setMinimumSize(QSize(25, 25));
        btnClearSelection->setMaximumSize(QSize(25, 25));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/eraser.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClearSelection->setIcon(icon5);
        btnClearSelection->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(btnClearSelection);


        gridLayout_2->addWidget(widget_3, 0, 0, 1, 1);

        wContainer = new QWidget(WMainDesk);
        wContainer->setObjectName(QString::fromUtf8("wContainer"));
        wContainer->setMinimumSize(QSize(0, 0));
        gridLayout_3 = new QGridLayout(wContainer);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(0);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        saDate = new QScrollArea(wContainer);
        saDate->setObjectName(QString::fromUtf8("saDate"));
        saDate->setMinimumSize(QSize(0, 0));
        saDate->setMaximumSize(QSize(16777215, 57));
        saDate->setFrameShape(QFrame::Box);
        saDate->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        saDate->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        saDate->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 539, 55));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tblMonth = new QTableWidget(scrollAreaWidgetContents_2);
        tblMonth->setObjectName(QString::fromUtf8("tblMonth"));
        tblMonth->setMinimumSize(QSize(0, 25));
        tblMonth->setMaximumSize(QSize(222222, 25));
        tblMonth->setFocusPolicy(Qt::NoFocus);
        tblMonth->setFrameShape(QFrame::NoFrame);
        tblMonth->setFrameShadow(QFrame::Raised);
        tblMonth->setLineWidth(1);
        tblMonth->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblMonth->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblMonth->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblMonth->horizontalHeader()->setVisible(false);
        tblMonth->horizontalHeader()->setMinimumSectionSize(20);
        tblMonth->horizontalHeader()->setDefaultSectionSize(35);
        tblMonth->verticalHeader()->setVisible(false);
        tblMonth->verticalHeader()->setMinimumSectionSize(20);
        tblMonth->verticalHeader()->setDefaultSectionSize(25);
        tblMonth->verticalHeader()->setHighlightSections(false);

        verticalLayout_2->addWidget(tblMonth);

        tblDay = new QTableWidget(scrollAreaWidgetContents_2);
        tblDay->setObjectName(QString::fromUtf8("tblDay"));
        tblDay->setMinimumSize(QSize(0, 30));
        tblDay->setMaximumSize(QSize(222222, 30));
        tblDay->setFocusPolicy(Qt::NoFocus);
        tblDay->setFrameShape(QFrame::NoFrame);
        tblDay->setFrameShadow(QFrame::Raised);
        tblDay->setLineWidth(1);
        tblDay->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblDay->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblDay->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblDay->horizontalHeader()->setVisible(false);
        tblDay->horizontalHeader()->setMinimumSectionSize(20);
        tblDay->horizontalHeader()->setDefaultSectionSize(35);
        tblDay->verticalHeader()->setVisible(false);
        tblDay->verticalHeader()->setMinimumSectionSize(20);
        tblDay->verticalHeader()->setHighlightSections(false);

        verticalLayout_2->addWidget(tblDay);

        saDate->setWidget(scrollAreaWidgetContents_2);

        gridLayout_3->addWidget(saDate, 0, 1, 1, 1);

        saMain = new QScrollArea(wContainer);
        saMain->setObjectName(QString::fromUtf8("saMain"));
        saMain->setFrameShape(QFrame::Box);
        saMain->setFrameShadow(QFrame::Sunken);
        saMain->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        saMain->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        saMain->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 539, 557));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        g = new QGraphicsView(scrollAreaWidgetContents_3);
        g->setObjectName(QString::fromUtf8("g"));
        g->setMouseTracking(true);
        g->setFocusPolicy(Qt::NoFocus);
        g->setFrameShape(QFrame::NoFrame);
        g->setFrameShadow(QFrame::Raised);
        g->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        g->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        g->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(g);

        saMain->setWidget(scrollAreaWidgetContents_3);

        gridLayout_3->addWidget(saMain, 1, 1, 1, 1);

        wRoom = new QWidget(wContainer);
        wRoom->setObjectName(QString::fromUtf8("wRoom"));
        wRoom->setMinimumSize(QSize(0, 0));
        verticalLayout_4 = new QVBoxLayout(wRoom);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        saRoom = new QScrollArea(wRoom);
        saRoom->setObjectName(QString::fromUtf8("saRoom"));
        saRoom->setMaximumSize(QSize(16777215, 16777215));
        saRoom->setFrameShape(QFrame::Box);
        saRoom->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        saRoom->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        saRoom->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 539, 557));
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        tblRoom = new QTableWidget(scrollAreaWidgetContents);
        tblRoom->setObjectName(QString::fromUtf8("tblRoom"));
        tblRoom->setFocusPolicy(Qt::NoFocus);
        tblRoom->setFrameShape(QFrame::NoFrame);
        tblRoom->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblRoom->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblRoom->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblRoom->horizontalHeader()->setVisible(false);
        tblRoom->horizontalHeader()->setDefaultSectionSize(250);
        tblRoom->verticalHeader()->setVisible(false);
        tblRoom->verticalHeader()->setDefaultSectionSize(25);
        tblRoom->verticalHeader()->setHighlightSections(false);

        horizontalLayout->addWidget(tblRoom);

        saRoom->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(saRoom);


        gridLayout_3->addWidget(wRoom, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, -1, 2);
        btnJumpToDate = new QPushButton(wContainer);
        btnJumpToDate->setObjectName(QString::fromUtf8("btnJumpToDate"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnJumpToDate->sizePolicy().hasHeightForWidth());
        btnJumpToDate->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(btnJumpToDate);

        leJumpToRoom = new QLineEdit(wContainer);
        leJumpToRoom->setObjectName(QString::fromUtf8("leJumpToRoom"));
        sizePolicy1.setHeightForWidth(leJumpToRoom->sizePolicy().hasHeightForWidth());
        leJumpToRoom->setSizePolicy(sizePolicy1);
        leJumpToRoom->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_3->addWidget(leJumpToRoom);


        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);


        gridLayout_2->addWidget(wContainer, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        btnScrollLeft = new QPushButton(WMainDesk);
        btnScrollLeft->setObjectName(QString::fromUtf8("btnScrollLeft"));
        btnScrollLeft->setMinimumSize(QSize(36, 36));
        btnScrollLeft->setMaximumSize(QSize(36, 36));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnScrollLeft->setIcon(icon6);
        btnScrollLeft->setIconSize(QSize(32, 32));

        gridLayout->addWidget(btnScrollLeft, 0, 0, 1, 1);

        btnCheckin = new QToolButton(WMainDesk);
        btnCheckin->setObjectName(QString::fromUtf8("btnCheckin"));
        btnCheckin->setMinimumSize(QSize(0, 0));
        btnCheckin->setMaximumSize(QSize(555, 555));
        btnCheckin->setSizeIncrement(QSize(1, 0));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/checkin2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCheckin->setIcon(icon7);
        btnCheckin->setIconSize(QSize(24, 24));
        btnCheckin->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnCheckin, 5, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 13, 0, 1, 1);

        btnTransferRoom = new QToolButton(WMainDesk);
        btnTransferRoom->setObjectName(QString::fromUtf8("btnTransferRoom"));
        btnTransferRoom->setMinimumSize(QSize(0, 0));
        btnTransferRoom->setMaximumSize(QSize(555, 555));
        btnTransferRoom->setSizeIncrement(QSize(1, 0));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/transfer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTransferRoom->setIcon(icon8);
        btnTransferRoom->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnTransferRoom, 10, 0, 1, 2);

        btnScrollUp = new QPushButton(WMainDesk);
        btnScrollUp->setObjectName(QString::fromUtf8("btnScrollUp"));
        btnScrollUp->setMinimumSize(QSize(36, 36));
        btnScrollUp->setMaximumSize(QSize(36, 36));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnScrollUp->setIcon(icon9);
        btnScrollUp->setIconSize(QSize(32, 32));

        gridLayout->addWidget(btnScrollUp, 1, 1, 1, 1);

        btnCheckIn = new QToolButton(WMainDesk);
        btnCheckIn->setObjectName(QString::fromUtf8("btnCheckIn"));
        btnCheckIn->setMinimumSize(QSize(0, 0));
        btnCheckIn->setMaximumSize(QSize(555, 555));
        btnCheckIn->setSizeIncrement(QSize(1, 0));
        QFont font;
        font.setStrikeOut(false);
        btnCheckIn->setFont(font);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/checkin.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCheckIn->setIcon(icon10);
        btnCheckIn->setIconSize(QSize(24, 24));
        btnCheckIn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnCheckIn, 3, 0, 1, 2);

        btnColors = new QToolButton(WMainDesk);
        btnColors->setObjectName(QString::fromUtf8("btnColors"));
        btnColors->setMinimumSize(QSize(0, 0));
        btnColors->setMaximumSize(QSize(555, 555));
        btnColors->setSizeIncrement(QSize(1, 0));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnColors->setIcon(icon11);
        btnColors->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnColors, 11, 0, 1, 2);

        btnCheckoutFilter = new QToolButton(WMainDesk);
        btnCheckoutFilter->setObjectName(QString::fromUtf8("btnCheckoutFilter"));
        btnCheckoutFilter->setMinimumSize(QSize(0, 0));
        btnCheckoutFilter->setMaximumSize(QSize(555, 555));
        btnCheckoutFilter->setSizeIncrement(QSize(1, 0));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/departure.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCheckoutFilter->setIcon(icon12);
        btnCheckoutFilter->setIconSize(QSize(24, 24));
        btnCheckoutFilter->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnCheckoutFilter, 6, 0, 1, 2);

        btnAirReserve = new QToolButton(WMainDesk);
        btnAirReserve->setObjectName(QString::fromUtf8("btnAirReserve"));
        btnAirReserve->setMaximumSize(QSize(555, 555));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/ari.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAirReserve->setIcon(icon13);
        btnAirReserve->setIconSize(QSize(24, 24));
        btnAirReserve->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnAirReserve, 7, 0, 1, 2);

        btnScrollRight = new QPushButton(WMainDesk);
        btnScrollRight->setObjectName(QString::fromUtf8("btnScrollRight"));
        btnScrollRight->setMinimumSize(QSize(36, 36));
        btnScrollRight->setMaximumSize(QSize(36, 36));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnScrollRight->setIcon(icon14);
        btnScrollRight->setIconSize(QSize(32, 32));

        gridLayout->addWidget(btnScrollRight, 0, 1, 1, 1);

        btnEndOfDay = new QToolButton(WMainDesk);
        btnEndOfDay->setObjectName(QString::fromUtf8("btnEndOfDay"));
        btnEndOfDay->setEnabled(true);
        btnEndOfDay->setMinimumSize(QSize(0, 0));
        btnEndOfDay->setMaximumSize(QSize(555, 555));
        btnEndOfDay->setSizeIncrement(QSize(1, 0));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/moon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnEndOfDay->setIcon(icon15);
        btnEndOfDay->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnEndOfDay, 12, 0, 1, 2);

        btnScrollDown = new QPushButton(WMainDesk);
        btnScrollDown->setObjectName(QString::fromUtf8("btnScrollDown"));
        btnScrollDown->setMinimumSize(QSize(36, 36));
        btnScrollDown->setMaximumSize(QSize(36, 36));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/images/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnScrollDown->setIcon(icon16);
        btnScrollDown->setIconSize(QSize(32, 32));

        gridLayout->addWidget(btnScrollDown, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 1);

        btnPostCharge = new QToolButton(WMainDesk);
        btnPostCharge->setObjectName(QString::fromUtf8("btnPostCharge"));
        btnPostCharge->setMinimumSize(QSize(0, 0));
        btnPostCharge->setMaximumSize(QSize(555, 555));
        btnPostCharge->setSizeIncrement(QSize(1, 0));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/images/charge.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPostCharge->setIcon(icon17);
        btnPostCharge->setIconSize(QSize(20, 20));
        btnPostCharge->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnPostCharge, 9, 0, 1, 2);

        btnInvoice = new QToolButton(WMainDesk);
        btnInvoice->setObjectName(QString::fromUtf8("btnInvoice"));
        btnInvoice->setMinimumSize(QSize(0, 0));
        btnInvoice->setMaximumSize(QSize(555, 555));
        btnInvoice->setSizeIncrement(QSize(1, 0));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/images/invoice.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnInvoice->setIcon(icon18);
        btnInvoice->setIconSize(QSize(24, 24));
        btnInvoice->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnInvoice, 8, 0, 1, 2);

        btnGroupReservation = new QToolButton(WMainDesk);
        btnGroupReservation->setObjectName(QString::fromUtf8("btnGroupReservation"));
        btnGroupReservation->setMinimumSize(QSize(0, 0));
        btnGroupReservation->setMaximumSize(QSize(555, 555));
        btnGroupReservation->setSizeIncrement(QSize(1, 0));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/images/groupreservation.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGroupReservation->setIcon(icon19);
        btnGroupReservation->setIconSize(QSize(20, 20));
        btnGroupReservation->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnGroupReservation->setAutoRaise(false);
        btnGroupReservation->setArrowType(Qt::NoArrow);

        gridLayout->addWidget(btnGroupReservation, 4, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 1, 3, 1);


        retranslateUi(WMainDesk);

        QMetaObject::connectSlotsByName(WMainDesk);
    } // setupUi

    void retranslateUi(QWidget *WMainDesk)
    {
        WMainDesk->setWindowTitle(QCoreApplication::translate("WMainDesk", "Form", nullptr));
        btnFilterCategory->setText(QCoreApplication::translate("WMainDesk", "Category: All", nullptr));
        btnBuilding->setText(QCoreApplication::translate("WMainDesk", "Building: All", nullptr));
        btnBedFilter->setText(QCoreApplication::translate("WMainDesk", "Bed filter: All", nullptr));
        btnSmokeFilter->setText(QCoreApplication::translate("WMainDesk", "Smoke filter: All", nullptr));
        btnRoomStateFilter->setText(QCoreApplication::translate("WMainDesk", "Room state filter: All", nullptr));
        lbRoomsCount->setText(QCoreApplication::translate("WMainDesk", "Rooms: 0", nullptr));
        leFilterGuest->setPlaceholderText(QCoreApplication::translate("WMainDesk", "Search in reservation", nullptr));
        btnShowDockHint->setText(QString());
#if QT_CONFIG(tooltip)
        btnStatus->setToolTip(QCoreApplication::translate("WMainDesk", "Confirmed reservation", nullptr));
#endif // QT_CONFIG(tooltip)
        btnStatus->setText(QCoreApplication::translate("WMainDesk", "Status", nullptr));
        btnFilterCardex->setText(QCoreApplication::translate("WMainDesk", "Cardex", nullptr));
#if QT_CONFIG(tooltip)
        btnRefreshChart->setToolTip(QCoreApplication::translate("WMainDesk", "Refresh chart", nullptr));
#endif // QT_CONFIG(tooltip)
        btnRefreshChart->setText(QString());
#if QT_CONFIG(tooltip)
        btnClearFilter->setToolTip(QCoreApplication::translate("WMainDesk", "Clear all filters", nullptr));
#endif // QT_CONFIG(tooltip)
        btnClearFilter->setText(QString());
#if QT_CONFIG(statustip)
        btnClearSelection->setStatusTip(QCoreApplication::translate("WMainDesk", "Clear draft reservations (not locked)", nullptr));
#endif // QT_CONFIG(statustip)
        btnClearSelection->setText(QString());
        btnJumpToDate->setText(QCoreApplication::translate("WMainDesk", "Jump to date", nullptr));
        leJumpToRoom->setPlaceholderText(QCoreApplication::translate("WMainDesk", "Room num list", nullptr));
        btnScrollLeft->setText(QString());
        btnCheckin->setText(QCoreApplication::translate("WMainDesk", "Checkin", nullptr));
        btnTransferRoom->setText(QCoreApplication::translate("WMainDesk", "Transfer\n"
"amount", nullptr));
        btnScrollUp->setText(QString());
        btnCheckIn->setText(QCoreApplication::translate("WMainDesk", "Reservation", nullptr));
        btnColors->setText(QCoreApplication::translate("WMainDesk", "Colors", nullptr));
        btnCheckoutFilter->setText(QCoreApplication::translate("WMainDesk", "Checkout", nullptr));
        btnAirReserve->setText(QCoreApplication::translate("WMainDesk", "Air\n"
"reservation", nullptr));
        btnScrollRight->setText(QString());
        btnEndOfDay->setText(QCoreApplication::translate("WMainDesk", "End\n"
"Of Day", nullptr));
        btnScrollDown->setText(QString());
        btnPostCharge->setText(QCoreApplication::translate("WMainDesk", "Post charge", nullptr));
        btnInvoice->setText(QCoreApplication::translate("WMainDesk", "Invoice", nullptr));
        btnGroupReservation->setText(QCoreApplication::translate("WMainDesk", "Group\n"
"reservation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WMainDesk: public Ui_WMainDesk {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WMAINDESK_H
