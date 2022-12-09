/********************************************************************************
** Form generated from reading UI file 'wsyncinvoices.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WSYNCINVOICES_H
#define UI_WSYNCINVOICES_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_WSyncInvoices
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    EQLineEdit *leInvoice;
    QPushButton *btnSearchInvoice;
    QSpacerItem *horizontalSpacer;
    QCheckBox *chOverrideDuplicate;
    QPushButton *btnSaveCopy;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_5;
    QTableWidget *tblPMain;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *chPFinance;
    QCheckBox *chPNoFinance;
    QSpacerItem *horizontalSpacer_3;
    QLabel *lbSemaphore;
    EQTableWidget *tblPData;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    EQTableWidget *tblMain;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QCheckBox *chFinance;
    QCheckBox *chNoFinance;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnExportSingleVaucher;
    EQTableWidget *tblData;
    QWidget *wdtSearch;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QPushButton *btnPrevDate;
    EDateEdit *deDate;
    QPushButton *btnNextDate;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *chDontHideSearch;
    QPushButton *btnExcel;
    QPushButton *btnCloseSearch;
    EQTableWidget *tblSearch;

    void setupUi(QWidget *WSyncInvoices)
    {
        if (WSyncInvoices->objectName().isEmpty())
            WSyncInvoices->setObjectName(QString::fromUtf8("WSyncInvoices"));
        WSyncInvoices->resize(1193, 559);
        WSyncInvoices->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(WSyncInvoices);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_3 = new QWidget(WSyncInvoices);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(0, 0));
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        leInvoice = new EQLineEdit(widget_3);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));
        leInvoice->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_4->addWidget(leInvoice);

        btnSearchInvoice = new QPushButton(widget_3);
        btnSearchInvoice->setObjectName(QString::fromUtf8("btnSearchInvoice"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSearchInvoice->setIcon(icon);

        horizontalLayout_4->addWidget(btnSearchInvoice);

        horizontalSpacer = new QSpacerItem(366, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        chOverrideDuplicate = new QCheckBox(widget_3);
        chOverrideDuplicate->setObjectName(QString::fromUtf8("chOverrideDuplicate"));

        horizontalLayout_4->addWidget(chOverrideDuplicate);

        btnSaveCopy = new QPushButton(widget_3);
        btnSaveCopy->setObjectName(QString::fromUtf8("btnSaveCopy"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSaveCopy->setIcon(icon1);

        horizontalLayout_4->addWidget(btnSaveCopy);


        gridLayout->addWidget(widget_3, 0, 1, 1, 2);

        widget_2 = new QWidget(WSyncInvoices);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        groupBox_4 = new QGroupBox(widget_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        horizontalLayout_5 = new QHBoxLayout(groupBox_4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        tblPMain = new QTableWidget(groupBox_4);
        if (tblPMain->columnCount() < 5)
            tblPMain->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblPMain->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblPMain->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblPMain->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblPMain->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblPMain->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (tblPMain->rowCount() < 6)
            tblPMain->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblPMain->setVerticalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblPMain->setVerticalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblPMain->setVerticalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblPMain->setVerticalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tblPMain->setVerticalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblPMain->setVerticalHeaderItem(5, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tblPMain->setItem(0, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tblPMain->setItem(0, 1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tblPMain->setItem(1, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tblPMain->setItem(1, 1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tblPMain->setItem(2, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tblPMain->setItem(2, 1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tblPMain->setItem(3, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tblPMain->setItem(3, 1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tblPMain->setItem(4, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tblPMain->setItem(4, 1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tblPMain->setItem(5, 0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tblPMain->setItem(5, 1, __qtablewidgetitem22);
        tblPMain->setObjectName(QString::fromUtf8("tblPMain"));
        tblPMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblPMain->horizontalHeader()->setVisible(false);
        tblPMain->verticalHeader()->setVisible(false);

        horizontalLayout_5->addWidget(tblPMain);


        verticalLayout_2->addWidget(groupBox_4);

        groupBox_2 = new QGroupBox(widget_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_5 = new QWidget(groupBox_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_6 = new QHBoxLayout(widget_5);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        chPFinance = new QCheckBox(widget_5);
        chPFinance->setObjectName(QString::fromUtf8("chPFinance"));

        horizontalLayout_6->addWidget(chPFinance);

        chPNoFinance = new QCheckBox(widget_5);
        chPNoFinance->setObjectName(QString::fromUtf8("chPNoFinance"));

        horizontalLayout_6->addWidget(chPNoFinance);

        horizontalSpacer_3 = new QSpacerItem(279, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        lbSemaphore = new QLabel(widget_5);
        lbSemaphore->setObjectName(QString::fromUtf8("lbSemaphore"));
        lbSemaphore->setPixmap(QPixmap(QString::fromUtf8(":/images/ball-red.png")));

        horizontalLayout_6->addWidget(lbSemaphore);


        verticalLayout_4->addWidget(widget_5);

        tblPData = new EQTableWidget(groupBox_2);
        if (tblPData->columnCount() < 7)
            tblPData->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tblPData->setHorizontalHeaderItem(0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tblPData->setHorizontalHeaderItem(1, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tblPData->setHorizontalHeaderItem(2, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tblPData->setHorizontalHeaderItem(3, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tblPData->setHorizontalHeaderItem(4, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tblPData->setHorizontalHeaderItem(5, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tblPData->setHorizontalHeaderItem(6, __qtablewidgetitem29);
        tblPData->setObjectName(QString::fromUtf8("tblPData"));
        tblPData->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_4->addWidget(tblPData);


        verticalLayout_2->addWidget(groupBox_2);


        gridLayout->addWidget(widget_2, 1, 2, 1, 1);

        widget = new QWidget(WSyncInvoices);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        tblMain = new EQTableWidget(groupBox_3);
        if (tblMain->columnCount() < 5)
            tblMain->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tblMain->setHorizontalHeaderItem(0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tblMain->setHorizontalHeaderItem(1, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tblMain->setHorizontalHeaderItem(2, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tblMain->setHorizontalHeaderItem(3, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tblMain->setHorizontalHeaderItem(4, __qtablewidgetitem34);
        tblMain->setObjectName(QString::fromUtf8("tblMain"));
        tblMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblMain->horizontalHeader()->setVisible(false);
        tblMain->verticalHeader()->setVisible(false);

        horizontalLayout_3->addWidget(tblMain);


        verticalLayout->addWidget(groupBox_3);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_4 = new QWidget(groupBox);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        chFinance = new QCheckBox(widget_4);
        chFinance->setObjectName(QString::fromUtf8("chFinance"));

        horizontalLayout->addWidget(chFinance);

        chNoFinance = new QCheckBox(widget_4);
        chNoFinance->setObjectName(QString::fromUtf8("chNoFinance"));

        horizontalLayout->addWidget(chNoFinance);

        horizontalSpacer_2 = new QSpacerItem(46, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnExportSingleVaucher = new QPushButton(widget_4);
        btnExportSingleVaucher->setObjectName(QString::fromUtf8("btnExportSingleVaucher"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/goto.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExportSingleVaucher->setIcon(icon2);

        horizontalLayout->addWidget(btnExportSingleVaucher);


        verticalLayout_3->addWidget(widget_4);

        tblData = new EQTableWidget(groupBox);
        if (tblData->columnCount() < 6)
            tblData->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(0, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(1, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(2, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(3, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(4, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(5, __qtablewidgetitem40);
        tblData->setObjectName(QString::fromUtf8("tblData"));
        tblData->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblData->setSelectionMode(QAbstractItemView::SingleSelection);
        tblData->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_3->addWidget(tblData);

        tblData->raise();
        widget_4->raise();

        verticalLayout->addWidget(groupBox);


        gridLayout->addWidget(widget, 1, 1, 1, 1);

        wdtSearch = new QWidget(WSyncInvoices);
        wdtSearch->setObjectName(QString::fromUtf8("wdtSearch"));
        wdtSearch->setMinimumSize(QSize(470, 0));
        wdtSearch->setMaximumSize(QSize(470, 16777215));
        verticalLayout_5 = new QVBoxLayout(wdtSearch);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        widget_7 = new QWidget(wdtSearch);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_2 = new QHBoxLayout(widget_7);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget_7);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        btnPrevDate = new QPushButton(widget_7);
        btnPrevDate->setObjectName(QString::fromUtf8("btnPrevDate"));
        btnPrevDate->setMaximumSize(QSize(25, 25));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrevDate->setIcon(icon3);

        horizontalLayout_2->addWidget(btnPrevDate);

        deDate = new EDateEdit(widget_7);
        deDate->setObjectName(QString::fromUtf8("deDate"));

        horizontalLayout_2->addWidget(deDate);

        btnNextDate = new QPushButton(widget_7);
        btnNextDate->setObjectName(QString::fromUtf8("btnNextDate"));
        btnNextDate->setMaximumSize(QSize(25, 25));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNextDate->setIcon(icon4);

        horizontalLayout_2->addWidget(btnNextDate);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_5->addWidget(widget_7);

        widget_6 = new QWidget(wdtSearch);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_7 = new QHBoxLayout(widget_6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        chDontHideSearch = new QCheckBox(widget_6);
        chDontHideSearch->setObjectName(QString::fromUtf8("chDontHideSearch"));
        chDontHideSearch->setChecked(true);

        horizontalLayout_7->addWidget(chDontHideSearch);

        btnExcel = new QPushButton(widget_6);
        btnExcel->setObjectName(QString::fromUtf8("btnExcel"));
        btnExcel->setMaximumSize(QSize(25, 25));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/excel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExcel->setIcon(icon5);
        btnExcel->setIconSize(QSize(12, 12));

        horizontalLayout_7->addWidget(btnExcel);

        btnCloseSearch = new QPushButton(widget_6);
        btnCloseSearch->setObjectName(QString::fromUtf8("btnCloseSearch"));
        btnCloseSearch->setMaximumSize(QSize(20, 20));

        horizontalLayout_7->addWidget(btnCloseSearch);


        verticalLayout_5->addWidget(widget_6);

        tblSearch = new EQTableWidget(wdtSearch);
        if (tblSearch->columnCount() < 5)
            tblSearch->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tblSearch->setHorizontalHeaderItem(0, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tblSearch->setHorizontalHeaderItem(1, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tblSearch->setHorizontalHeaderItem(2, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tblSearch->setHorizontalHeaderItem(3, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tblSearch->setHorizontalHeaderItem(4, __qtablewidgetitem45);
        tblSearch->setObjectName(QString::fromUtf8("tblSearch"));
        tblSearch->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblSearch->setSelectionMode(QAbstractItemView::NoSelection);
        tblSearch->verticalHeader()->setVisible(false);

        verticalLayout_5->addWidget(tblSearch);


        gridLayout->addWidget(wdtSearch, 0, 0, 2, 1);


        retranslateUi(WSyncInvoices);

        QMetaObject::connectSlotsByName(WSyncInvoices);
    } // setupUi

    void retranslateUi(QWidget *WSyncInvoices)
    {
        WSyncInvoices->setWindowTitle(QCoreApplication::translate("WSyncInvoices", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("WSyncInvoices", "Invoice #", nullptr));
        btnSearchInvoice->setText(QString());
        chOverrideDuplicate->setText(QCoreApplication::translate("WSyncInvoices", "Override duplicates", nullptr));
        btnSaveCopy->setText(QCoreApplication::translate("WSyncInvoices", "Export", nullptr));
        label_2->setText(QCoreApplication::translate("WSyncInvoices", "Copy", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("WSyncInvoices", "Reservation", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblPMain->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WSyncInvoices", "Key", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblPMain->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("WSyncInvoices", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblPMain->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("WSyncInvoices", "Separator", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblPMain->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("WSyncInvoices", "Key", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblPMain->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("WSyncInvoices", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblPMain->verticalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("WSyncInvoices", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblPMain->verticalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("WSyncInvoices", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblPMain->verticalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("WSyncInvoices", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblPMain->verticalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("WSyncInvoices", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblPMain->verticalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("WSyncInvoices", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblPMain->verticalHeaderItem(5);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("WSyncInvoices", "New Row", nullptr));

        const bool __sortingEnabled = tblPMain->isSortingEnabled();
        tblPMain->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem11 = tblPMain->item(0, 0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("WSyncInvoices", "RESERVE NUM", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblPMain->item(0, 1);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("WSyncInvoices", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tblPMain->item(1, 0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("WSyncInvoices", "GUEST", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tblPMain->item(1, 1);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("WSyncInvoices", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tblPMain->item(2, 0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("WSyncInvoices", "ENTRY", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tblPMain->item(2, 1);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("WSyncInvoices", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tblPMain->item(3, 0);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("WSyncInvoices", "DEPARTURE", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tblPMain->item(3, 1);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("WSyncInvoices", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tblPMain->item(4, 0);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("WSyncInvoices", "INVOICE NUM", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tblPMain->item(4, 1);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("WSyncInvoices", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tblPMain->item(5, 0);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("WSyncInvoices", "BALANCE", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tblPMain->item(5, 1);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("WSyncInvoices", "-", nullptr));
        tblPMain->setSortingEnabled(__sortingEnabled);

        groupBox_2->setTitle(QCoreApplication::translate("WSyncInvoices", "Vouchers", nullptr));
        chPFinance->setText(QCoreApplication::translate("WSyncInvoices", "Financial", nullptr));
        chPNoFinance->setText(QCoreApplication::translate("WSyncInvoices", "Info", nullptr));
        lbSemaphore->setText(QString());
        QTableWidgetItem *___qtablewidgetitem23 = tblPData->horizontalHeaderItem(0);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("WSyncInvoices", "*", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tblPData->horizontalHeaderItem(1);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("WSyncInvoices", "Src", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tblPData->horizontalHeaderItem(2);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("WSyncInvoices", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tblPData->horizontalHeaderItem(3);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("WSyncInvoices", "ItemName", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tblPData->horizontalHeaderItem(4);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("WSyncInvoices", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tblPData->horizontalHeaderItem(5);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("WSyncInvoices", "Tax", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tblPData->horizontalHeaderItem(6);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("WSyncInvoices", "Fin", nullptr));
        label->setText(QCoreApplication::translate("WSyncInvoices", "Original", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("WSyncInvoices", "Reservation", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tblMain->horizontalHeaderItem(0);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("WSyncInvoices", "Key", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tblMain->horizontalHeaderItem(1);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("WSyncInvoices", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tblMain->horizontalHeaderItem(2);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("WSyncInvoices", "Separator", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tblMain->horizontalHeaderItem(3);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("WSyncInvoices", "Key", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tblMain->horizontalHeaderItem(4);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("WSyncInvoices", "Value", nullptr));
        groupBox->setTitle(QCoreApplication::translate("WSyncInvoices", "Vouchers", nullptr));
        chFinance->setText(QCoreApplication::translate("WSyncInvoices", "Financial", nullptr));
        chNoFinance->setText(QCoreApplication::translate("WSyncInvoices", "Info", nullptr));
        btnExportSingleVaucher->setText(QString());
        QTableWidgetItem *___qtablewidgetitem35 = tblData->horizontalHeaderItem(0);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("WSyncInvoices", "*", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tblData->horizontalHeaderItem(1);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("WSyncInvoices", "Src", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tblData->horizontalHeaderItem(2);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("WSyncInvoices", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tblData->horizontalHeaderItem(3);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("WSyncInvoices", "ItemName", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tblData->horizontalHeaderItem(4);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("WSyncInvoices", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tblData->horizontalHeaderItem(5);
        ___qtablewidgetitem40->setText(QCoreApplication::translate("WSyncInvoices", "Tax", nullptr));
        label_4->setText(QCoreApplication::translate("WSyncInvoices", "Date", nullptr));
        btnPrevDate->setText(QString());
        btnNextDate->setText(QString());
        chDontHideSearch->setText(QCoreApplication::translate("WSyncInvoices", "Do not hide search panel", nullptr));
        btnExcel->setText(QString());
        btnCloseSearch->setText(QCoreApplication::translate("WSyncInvoices", "x", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tblSearch->horizontalHeaderItem(0);
        ___qtablewidgetitem41->setText(QCoreApplication::translate("WSyncInvoices", "#", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tblSearch->horizontalHeaderItem(1);
        ___qtablewidgetitem42->setText(QCoreApplication::translate("WSyncInvoices", "Room", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tblSearch->horizontalHeaderItem(2);
        ___qtablewidgetitem43->setText(QCoreApplication::translate("WSyncInvoices", "Guest", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = tblSearch->horizontalHeaderItem(3);
        ___qtablewidgetitem44->setText(QCoreApplication::translate("WSyncInvoices", "f", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = tblSearch->horizontalHeaderItem(4);
        ___qtablewidgetitem45->setText(QCoreApplication::translate("WSyncInvoices", "Balance", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WSyncInvoices: public Ui_WSyncInvoices {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WSYNCINVOICES_H
