/********************************************************************************
** Form generated from reading UI file 'rdesk.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RDESK_H
#define UI_RDESK_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RDesk
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *wInfo;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lbStaff;
    QSpacerItem *horizontalSpacer_5;
    QLabel *lbRoom;
    QFrame *frame;
    QGridLayout *gridLayout;
    QWidget *wLeft;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnMenu;
    QTableWidget *tblPart;
    QTableWidget *tblType;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnTypeUp;
    QPushButton *btnTypeDown;
    QSpacerItem *horizontalSpacer_2;
    QWidget *wCenter;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tblDish;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnDishUp;
    QPushButton *btnDishDown;
    QSpacerItem *horizontalSpacer_3;
    QWidget *wRight;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QPushButton *btnTransfer;
    QPushButton *btnPrint;
    QPushButton *btn1;
    QPushButton *btn3;
    QPushButton *btnHalfPlush;
    QPushButton *btn7;
    QPushButton *btn6;
    QPushButton *btnPlusTen;
    QPushButton *btn9;
    QPushButton *btn4;
    QPushButton *btnHalfMinus;
    QPushButton *btnTrash;
    QPushButton *btn2;
    QPushButton *btn5;
    QPushButton *btn8;
    QTableWidget *tblOrder;
    QTableWidget *tblComplex;
    QTableWidget *tblTotal;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnOrdUp;
    QPushButton *btnOrdDown;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnSetRoom;
    QPushButton *btnCheckout;
    QPushButton *btnPayment;
    QWidget *wBottom;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnLanguage;
    QPushButton *btnTable;
    QPushButton *btnComplex;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnGuests;
    QPushButton *btnTools;
    QPushButton *btnExit;

    void setupUi(QDialog *RDesk)
    {
        if (RDesk->objectName().isEmpty())
            RDesk->setObjectName(QString::fromUtf8("RDesk"));
        RDesk->resize(910, 631);
        verticalLayout = new QVBoxLayout(RDesk);
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        wInfo = new QWidget(RDesk);
        wInfo->setObjectName(QString::fromUtf8("wInfo"));
        horizontalLayout_5 = new QHBoxLayout(wInfo);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(wInfo);

        widget_4 = new QWidget(RDesk);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_6 = new QHBoxLayout(widget_4);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        lbStaff = new QLabel(widget_4);
        lbStaff->setObjectName(QString::fromUtf8("lbStaff"));

        horizontalLayout_6->addWidget(lbStaff);

        horizontalSpacer_5 = new QSpacerItem(688, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        lbRoom = new QLabel(widget_4);
        lbRoom->setObjectName(QString::fromUtf8("lbRoom"));

        horizontalLayout_6->addWidget(lbRoom);


        verticalLayout->addWidget(widget_4);

        frame = new QFrame(RDesk);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        wLeft = new QWidget(frame);
        wLeft->setObjectName(QString::fromUtf8("wLeft"));
        wLeft->setMinimumSize(QSize(330, 0));
        wLeft->setMaximumSize(QSize(330, 16777215));
        verticalLayout_2 = new QVBoxLayout(wLeft);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnMenu = new QPushButton(wLeft);
        btnMenu->setObjectName(QString::fromUtf8("btnMenu"));
        btnMenu->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(btnMenu);

        tblPart = new QTableWidget(wLeft);
        if (tblPart->columnCount() < 3)
            tblPart->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblPart->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblPart->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblPart->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tblPart->rowCount() < 2)
            tblPart->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblPart->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblPart->setVerticalHeaderItem(1, __qtablewidgetitem4);
        tblPart->setObjectName(QString::fromUtf8("tblPart"));
        tblPart->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblPart->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblPart->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblPart->setSelectionMode(QAbstractItemView::SingleSelection);
        tblPart->horizontalHeader()->setVisible(false);
        tblPart->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(tblPart);

        tblType = new QTableWidget(wLeft);
        if (tblType->columnCount() < 2)
            tblType->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblType->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblType->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        tblType->setObjectName(QString::fromUtf8("tblType"));
        tblType->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblType->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblType->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblType->setSelectionMode(QAbstractItemView::SingleSelection);
        tblType->horizontalHeader()->setVisible(false);
        tblType->verticalHeader()->setVisible(false);
        tblType->verticalHeader()->setDefaultSectionSize(50);

        verticalLayout_2->addWidget(tblType);

        widget_3 = new QWidget(wLeft);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMaximumSize(QSize(16777215, 55));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnTypeUp = new QPushButton(widget_3);
        btnTypeUp->setObjectName(QString::fromUtf8("btnTypeUp"));
        btnTypeUp->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTypeUp->setIcon(icon);

        horizontalLayout_2->addWidget(btnTypeUp);

        btnTypeDown = new QPushButton(widget_3);
        btnTypeDown->setObjectName(QString::fromUtf8("btnTypeDown"));
        btnTypeDown->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTypeDown->setIcon(icon1);

        horizontalLayout_2->addWidget(btnTypeDown);

        horizontalSpacer_2 = new QSpacerItem(147, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget_3);


        gridLayout->addWidget(wLeft, 0, 0, 1, 1);

        wCenter = new QWidget(frame);
        wCenter->setObjectName(QString::fromUtf8("wCenter"));
        verticalLayout_3 = new QVBoxLayout(wCenter);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        tblDish = new QTableWidget(wCenter);
        tblDish->setObjectName(QString::fromUtf8("tblDish"));
        tblDish->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblDish->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblDish->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblDish->setSelectionMode(QAbstractItemView::SingleSelection);
        tblDish->horizontalHeader()->setVisible(false);
        tblDish->horizontalHeader()->setDefaultSectionSize(150);
        tblDish->verticalHeader()->setVisible(false);
        tblDish->verticalHeader()->setDefaultSectionSize(60);

        verticalLayout_3->addWidget(tblDish);

        widget_5 = new QWidget(wCenter);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setMaximumSize(QSize(16777215, 55));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        btnDishUp = new QPushButton(widget_5);
        btnDishUp->setObjectName(QString::fromUtf8("btnDishUp"));
        btnDishUp->setFocusPolicy(Qt::NoFocus);
        btnDishUp->setIcon(icon);

        horizontalLayout_3->addWidget(btnDishUp);

        btnDishDown = new QPushButton(widget_5);
        btnDishDown->setObjectName(QString::fromUtf8("btnDishDown"));
        btnDishDown->setFocusPolicy(Qt::NoFocus);
        btnDishDown->setIcon(icon1);

        horizontalLayout_3->addWidget(btnDishDown);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_3->addWidget(widget_5);


        gridLayout->addWidget(wCenter, 0, 1, 1, 1);

        wRight = new QWidget(frame);
        wRight->setObjectName(QString::fromUtf8("wRight"));
        wRight->setMinimumSize(QSize(0, 0));
        wRight->setMaximumSize(QSize(280, 16777215));
        verticalLayout_4 = new QVBoxLayout(wRight);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 2, 0);
        widget = new QWidget(wRight);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        btnTransfer = new QPushButton(widget);
        btnTransfer->setObjectName(QString::fromUtf8("btnTransfer"));
        btnTransfer->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/transfer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTransfer->setIcon(icon2);

        gridLayout_2->addWidget(btnTransfer, 1, 4, 1, 1);

        btnPrint = new QPushButton(widget);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));
        btnPrint->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrint->setIcon(icon3);

        gridLayout_2->addWidget(btnPrint, 2, 4, 1, 1);

        btn1 = new QPushButton(widget);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        btn1->setMinimumSize(QSize(50, 0));
        btn1->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btn1, 0, 0, 1, 1);

        btn3 = new QPushButton(widget);
        btn3->setObjectName(QString::fromUtf8("btn3"));
        btn3->setMinimumSize(QSize(50, 0));
        btn3->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btn3, 0, 2, 1, 1);

        btnHalfPlush = new QPushButton(widget);
        btnHalfPlush->setObjectName(QString::fromUtf8("btnHalfPlush"));
        btnHalfPlush->setMinimumSize(QSize(50, 0));
        btnHalfPlush->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnHalfPlush, 0, 3, 1, 1);

        btn7 = new QPushButton(widget);
        btn7->setObjectName(QString::fromUtf8("btn7"));
        btn7->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btn7, 2, 0, 1, 1);

        btn6 = new QPushButton(widget);
        btn6->setObjectName(QString::fromUtf8("btn6"));
        btn6->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btn6, 1, 2, 1, 1);

        btnPlusTen = new QPushButton(widget);
        btnPlusTen->setObjectName(QString::fromUtf8("btnPlusTen"));
        btnPlusTen->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnPlusTen, 1, 3, 1, 1);

        btn9 = new QPushButton(widget);
        btn9->setObjectName(QString::fromUtf8("btn9"));
        btn9->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btn9, 2, 2, 1, 1);

        btn4 = new QPushButton(widget);
        btn4->setObjectName(QString::fromUtf8("btn4"));
        btn4->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btn4, 1, 0, 1, 1);

        btnHalfMinus = new QPushButton(widget);
        btnHalfMinus->setObjectName(QString::fromUtf8("btnHalfMinus"));
        btnHalfMinus->setMinimumSize(QSize(50, 0));
        btnHalfMinus->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnHalfMinus, 0, 4, 1, 1);

        btnTrash = new QPushButton(widget);
        btnTrash->setObjectName(QString::fromUtf8("btnTrash"));
        btnTrash->setFocusPolicy(Qt::NoFocus);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/garbage.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTrash->setIcon(icon4);

        gridLayout_2->addWidget(btnTrash, 2, 3, 1, 1);

        btn2 = new QPushButton(widget);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        btn2->setMinimumSize(QSize(50, 0));
        btn2->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btn2, 0, 1, 1, 1);

        btn5 = new QPushButton(widget);
        btn5->setObjectName(QString::fromUtf8("btn5"));
        btn5->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btn5, 1, 1, 1, 1);

        btn8 = new QPushButton(widget);
        btn8->setObjectName(QString::fromUtf8("btn8"));
        btn8->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btn8, 2, 1, 1, 1);


        verticalLayout_4->addWidget(widget);

        tblOrder = new QTableWidget(wRight);
        if (tblOrder->columnCount() < 3)
            tblOrder->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblOrder->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblOrder->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tblOrder->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        tblOrder->setObjectName(QString::fromUtf8("tblOrder"));
        tblOrder->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblOrder->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblOrder->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblOrder->setSelectionMode(QAbstractItemView::SingleSelection);
        tblOrder->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblOrder->verticalHeader()->setVisible(false);
        tblOrder->verticalHeader()->setDefaultSectionSize(50);

        verticalLayout_4->addWidget(tblOrder);

        tblComplex = new QTableWidget(wRight);
        if (tblComplex->columnCount() < 4)
            tblComplex->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblComplex->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tblComplex->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tblComplex->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tblComplex->setHorizontalHeaderItem(3, __qtablewidgetitem13);
        tblComplex->setObjectName(QString::fromUtf8("tblComplex"));

        verticalLayout_4->addWidget(tblComplex);

        tblTotal = new QTableWidget(wRight);
        if (tblTotal->columnCount() < 2)
            tblTotal->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        if (tblTotal->rowCount() < 2)
            tblTotal->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tblTotal->setVerticalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tblTotal->setVerticalHeaderItem(1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tblTotal->setItem(0, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tblTotal->setItem(0, 1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tblTotal->setItem(1, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tblTotal->setItem(1, 1, __qtablewidgetitem21);
        tblTotal->setObjectName(QString::fromUtf8("tblTotal"));
        tblTotal->setMaximumSize(QSize(16777215, 55));
        tblTotal->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblTotal->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblTotal->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblTotal->setSelectionMode(QAbstractItemView::NoSelection);
        tblTotal->horizontalHeader()->setVisible(false);
        tblTotal->verticalHeader()->setVisible(false);
        tblTotal->verticalHeader()->setDefaultSectionSize(25);

        verticalLayout_4->addWidget(tblTotal);

        widget_2 = new QWidget(wRight);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMaximumSize(QSize(16777215, 55));
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        btnOrdUp = new QPushButton(widget_2);
        btnOrdUp->setObjectName(QString::fromUtf8("btnOrdUp"));
        btnOrdUp->setFocusPolicy(Qt::NoFocus);
        btnOrdUp->setIcon(icon);

        horizontalLayout_4->addWidget(btnOrdUp);

        btnOrdDown = new QPushButton(widget_2);
        btnOrdDown->setObjectName(QString::fromUtf8("btnOrdDown"));
        btnOrdDown->setFocusPolicy(Qt::NoFocus);
        btnOrdDown->setIcon(icon1);

        horizontalLayout_4->addWidget(btnOrdDown);

        horizontalSpacer_4 = new QSpacerItem(195, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        btnSetRoom = new QPushButton(widget_2);
        btnSetRoom->setObjectName(QString::fromUtf8("btnSetRoom"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/window.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSetRoom->setIcon(icon5);

        horizontalLayout_4->addWidget(btnSetRoom);

        btnCheckout = new QPushButton(widget_2);
        btnCheckout->setObjectName(QString::fromUtf8("btnCheckout"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/invoice.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCheckout->setIcon(icon6);

        horizontalLayout_4->addWidget(btnCheckout);

        btnPayment = new QPushButton(widget_2);
        btnPayment->setObjectName(QString::fromUtf8("btnPayment"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/wallet-with-money.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPayment->setIcon(icon7);

        horizontalLayout_4->addWidget(btnPayment);


        verticalLayout_4->addWidget(widget_2);


        gridLayout->addWidget(wRight, 0, 2, 1, 1);

        wBottom = new QWidget(frame);
        wBottom->setObjectName(QString::fromUtf8("wBottom"));
        horizontalLayout = new QHBoxLayout(wBottom);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 0, 2, 2);
        btnLanguage = new QPushButton(wBottom);
        btnLanguage->setObjectName(QString::fromUtf8("btnLanguage"));
        btnLanguage->setFocusPolicy(Qt::NoFocus);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/armenia.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLanguage->setIcon(icon8);

        horizontalLayout->addWidget(btnLanguage);

        btnTable = new QPushButton(wBottom);
        btnTable->setObjectName(QString::fromUtf8("btnTable"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/table.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTable->setIcon(icon9);

        horizontalLayout->addWidget(btnTable);

        btnComplex = new QPushButton(wBottom);
        btnComplex->setObjectName(QString::fromUtf8("btnComplex"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/dinner.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnComplex->setIcon(icon10);

        horizontalLayout->addWidget(btnComplex);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnGuests = new QPushButton(wBottom);
        btnGuests->setObjectName(QString::fromUtf8("btnGuests"));
        btnGuests->setMinimumSize(QSize(0, 0));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/guests.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGuests->setIcon(icon11);

        horizontalLayout->addWidget(btnGuests);

        btnTools = new QPushButton(wBottom);
        btnTools->setObjectName(QString::fromUtf8("btnTools"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTools->setIcon(icon12);

        horizontalLayout->addWidget(btnTools);

        btnExit = new QPushButton(wBottom);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setFocusPolicy(Qt::NoFocus);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExit->setIcon(icon13);

        horizontalLayout->addWidget(btnExit);


        gridLayout->addWidget(wBottom, 1, 0, 1, 3);


        verticalLayout->addWidget(frame);


        retranslateUi(RDesk);
        QObject::connect(btn1, SIGNAL(clicked()), RDesk, SLOT(onBtnQtyClicked()));
        QObject::connect(btn2, SIGNAL(clicked()), RDesk, SLOT(onBtnQtyClicked()));
        QObject::connect(btn3, SIGNAL(clicked()), RDesk, SLOT(onBtnQtyClicked()));
        QObject::connect(btn4, SIGNAL(clicked()), RDesk, SLOT(onBtnQtyClicked()));
        QObject::connect(btn5, SIGNAL(clicked()), RDesk, SLOT(onBtnQtyClicked()));
        QObject::connect(btn6, SIGNAL(clicked()), RDesk, SLOT(onBtnQtyClicked()));
        QObject::connect(btn7, SIGNAL(clicked()), RDesk, SLOT(onBtnQtyClicked()));
        QObject::connect(btn8, SIGNAL(clicked()), RDesk, SLOT(onBtnQtyClicked()));
        QObject::connect(btn9, SIGNAL(clicked()), RDesk, SLOT(onBtnQtyClicked()));
        QObject::connect(btnHalfMinus, SIGNAL(clicked()), RDesk, SLOT(onBtnQtyClicked()));
        QObject::connect(btnHalfPlush, SIGNAL(clicked()), RDesk, SLOT(onBtnQtyClicked()));
        QObject::connect(btnTransfer, SIGNAL(clicked()), RDesk, SLOT(onBtnQtyClicked()));
        QObject::connect(btnPlusTen, SIGNAL(clicked()), RDesk, SLOT(onBtnQtyClicked()));

        QMetaObject::connectSlotsByName(RDesk);
    } // setupUi

    void retranslateUi(QDialog *RDesk)
    {
        RDesk->setWindowTitle(QCoreApplication::translate("RDesk", "Desk", nullptr));
        lbStaff->setText(QCoreApplication::translate("RDesk", "Staff", nullptr));
        lbRoom->setText(QCoreApplication::translate("RDesk", "Room #", nullptr));
        btnMenu->setText(QCoreApplication::translate("RDesk", "Menu: default", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblPart->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("RDesk", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblPart->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("RDesk", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblPart->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("RDesk", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblPart->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("RDesk", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblPart->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("RDesk", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblType->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("RDesk", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblType->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("RDesk", "New Column", nullptr));
        btnTypeUp->setText(QString());
        btnTypeDown->setText(QString());
        btnDishUp->setText(QString());
        btnDishDown->setText(QString());
        btnTransfer->setText(QString());
        btnPrint->setText(QString());
        btn1->setText(QCoreApplication::translate("RDesk", "1", nullptr));
        btn3->setText(QCoreApplication::translate("RDesk", "3", nullptr));
        btnHalfPlush->setText(QCoreApplication::translate("RDesk", "+0.5", nullptr));
        btn7->setText(QCoreApplication::translate("RDesk", "7", nullptr));
        btn6->setText(QCoreApplication::translate("RDesk", "6", nullptr));
        btnPlusTen->setText(QCoreApplication::translate("RDesk", "+10", nullptr));
        btn9->setText(QCoreApplication::translate("RDesk", "9", nullptr));
        btn4->setText(QCoreApplication::translate("RDesk", "4", nullptr));
        btnHalfMinus->setText(QCoreApplication::translate("RDesk", "-0.5", nullptr));
        btnTrash->setText(QString());
        btn2->setText(QCoreApplication::translate("RDesk", "2", nullptr));
        btn5->setText(QCoreApplication::translate("RDesk", "5", nullptr));
        btn8->setText(QCoreApplication::translate("RDesk", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblOrder->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("RDesk", "Item name", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblOrder->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("RDesk", "Qty", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblOrder->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("RDesk", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblComplex->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("RDesk", "ItemCode", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblComplex->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("RDesk", "ItemName", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblComplex->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("RDesk", "Qty", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tblComplex->horizontalHeaderItem(3);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("RDesk", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tblTotal->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("RDesk", "Key", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tblTotal->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("RDesk", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tblTotal->verticalHeaderItem(0);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("RDesk", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tblTotal->verticalHeaderItem(1);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("RDesk", "New Row", nullptr));

        const bool __sortingEnabled = tblTotal->isSortingEnabled();
        tblTotal->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem18 = tblTotal->item(0, 0);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("RDesk", "Table", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tblTotal->item(0, 1);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("RDesk", "Seghan1", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tblTotal->item(1, 0);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("RDesk", "Total", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tblTotal->item(1, 1);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("RDesk", "0", nullptr));
        tblTotal->setSortingEnabled(__sortingEnabled);

        btnOrdUp->setText(QString());
        btnOrdDown->setText(QString());
        btnSetRoom->setText(QString());
        btnCheckout->setText(QString());
        btnPayment->setText(QString());
        btnLanguage->setText(QString());
        btnTable->setText(QCoreApplication::translate("RDesk", "Table", nullptr));
        btnComplex->setText(QCoreApplication::translate("RDesk", "Complex", nullptr));
        btnGuests->setText(QCoreApplication::translate("RDesk", "Guest", nullptr));
        btnTools->setText(QCoreApplication::translate("RDesk", "Tools", nullptr));
        btnExit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RDesk: public Ui_RDesk {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RDESK_H
