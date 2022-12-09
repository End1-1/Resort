/********************************************************************************
** Form generated from reading UI file 'storedoc.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOREDOC_H
#define UI_STOREDOC_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqcombobox.h>
#include <eqlineedit.h>
#include <eqtablewidget.h>
#include <wcashentry.h>

QT_BEGIN_NAMESPACE

class Ui_StoreDoc
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QToolButton *btnSaveDoc;
    QToolButton *btnDraftDoc;
    QToolButton *btnPrintDoc;
    QToolButton *btnRemoveDoc;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *wCommon;
    QGridLayout *gridLayout_2;
    EDateEdit *deDate;
    QLabel *lbStoreout;
    QLabel *lbStorein;
    EQLineEdit *leDocNumber;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    EQLineEdit *leAction;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_7;
    EQLineEdit *leComments;
    EQLineEdit *leStore;
    EQLineEdit *leStoreout;
    QLabel *label_10;
    EQComboBox *cbPayment;
    QTabWidget *tabWidget;
    QWidget *tabCommon;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    EDateEdit *deInvoiceDate;
    EQLineEdit *leInvoiceNo;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QLabel *label_4;
    EQLineEdit *lePartnerCode;
    EQLineEdit *lePartnerName;
    QLabel *label_8;
    QWidget *tabMaterials;
    QVBoxLayout *verticalLayout_3;
    QWidget *wGoodsOps;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *btnAddMaterial;
    QToolButton *btnRemoveMaterial;
    QToolButton *btnNewMaterial;
    QSpacerItem *horizontalSpacer_3;
    EQTableWidget *tblGoods;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_9;
    EQLineEdit *leTotal;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_4;
    WCashEntry *wAcc;

    void setupUi(QWidget *StoreDoc)
    {
        if (StoreDoc->objectName().isEmpty())
            StoreDoc->setObjectName(QString::fromUtf8("StoreDoc"));
        StoreDoc->resize(893, 683);
        verticalLayout_2 = new QVBoxLayout(StoreDoc);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_4 = new QWidget(StoreDoc);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnSaveDoc = new QToolButton(widget_4);
        btnSaveDoc->setObjectName(QString::fromUtf8("btnSaveDoc"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSaveDoc->setIcon(icon);
        btnSaveDoc->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(btnSaveDoc);

        btnDraftDoc = new QToolButton(widget_4);
        btnDraftDoc->setObjectName(QString::fromUtf8("btnDraftDoc"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/draft.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDraftDoc->setIcon(icon1);
        btnDraftDoc->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(btnDraftDoc);

        btnPrintDoc = new QToolButton(widget_4);
        btnPrintDoc->setObjectName(QString::fromUtf8("btnPrintDoc"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrintDoc->setIcon(icon2);
        btnPrintDoc->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(btnPrintDoc);

        btnRemoveDoc = new QToolButton(widget_4);
        btnRemoveDoc->setObjectName(QString::fromUtf8("btnRemoveDoc"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/garbage.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRemoveDoc->setIcon(icon3);
        btnRemoveDoc->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(btnRemoveDoc);

        horizontalSpacer_4 = new QSpacerItem(761, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout_2->addWidget(widget_4);

        widget = new QWidget(StoreDoc);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wCommon = new QWidget(widget);
        wCommon->setObjectName(QString::fromUtf8("wCommon"));
        gridLayout_2 = new QGridLayout(wCommon);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, -1, 0, -1);
        deDate = new EDateEdit(wCommon);
        deDate->setObjectName(QString::fromUtf8("deDate"));

        gridLayout_2->addWidget(deDate, 0, 1, 1, 1);

        lbStoreout = new QLabel(wCommon);
        lbStoreout->setObjectName(QString::fromUtf8("lbStoreout"));

        gridLayout_2->addWidget(lbStoreout, 3, 0, 1, 1);

        lbStorein = new QLabel(wCommon);
        lbStorein->setObjectName(QString::fromUtf8("lbStorein"));

        gridLayout_2->addWidget(lbStorein, 2, 0, 1, 1);

        leDocNumber = new EQLineEdit(wCommon);
        leDocNumber->setObjectName(QString::fromUtf8("leDocNumber"));
        leDocNumber->setMaximumSize(QSize(150, 16777215));
        leDocNumber->setReadOnly(true);

        gridLayout_2->addWidget(leDocNumber, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 6, 1, 1);

        label_2 = new QLabel(wCommon);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 2, 1, 1);

        leAction = new EQLineEdit(wCommon);
        leAction->setObjectName(QString::fromUtf8("leAction"));
        leAction->setProperty("EnableHiddenText", QVariant(true));

        gridLayout_2->addWidget(leAction, 1, 1, 1, 1);

        label_3 = new QLabel(wCommon);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        label = new QLabel(wCommon);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_7 = new QLabel(wCommon);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 4, 0, 1, 1);

        leComments = new EQLineEdit(wCommon);
        leComments->setObjectName(QString::fromUtf8("leComments"));

        gridLayout_2->addWidget(leComments, 4, 1, 1, 3);

        leStore = new EQLineEdit(wCommon);
        leStore->setObjectName(QString::fromUtf8("leStore"));
        leStore->setMinimumSize(QSize(200, 0));
        leStore->setProperty("EnableHiddenText", QVariant(true));

        gridLayout_2->addWidget(leStore, 2, 1, 1, 1);

        leStoreout = new EQLineEdit(wCommon);
        leStoreout->setObjectName(QString::fromUtf8("leStoreout"));
        leStoreout->setMinimumSize(QSize(200, 0));
        leStoreout->setProperty("EnableHiddenText", QVariant(true));

        gridLayout_2->addWidget(leStoreout, 3, 1, 1, 1);

        label_10 = new QLabel(wCommon);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 1, 2, 1, 1);

        cbPayment = new EQComboBox(wCommon);
        cbPayment->setObjectName(QString::fromUtf8("cbPayment"));
        cbPayment->setProperty("Cache", QVariant(108));

        gridLayout_2->addWidget(cbPayment, 1, 3, 1, 1);


        verticalLayout->addWidget(wCommon);

        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabCommon = new QWidget();
        tabCommon->setObjectName(QString::fromUtf8("tabCommon"));
        gridLayout = new QGridLayout(tabCommon);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 5, 1, 1);

        label_6 = new QLabel(tabCommon);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        deInvoiceDate = new EDateEdit(tabCommon);
        deInvoiceDate->setObjectName(QString::fromUtf8("deInvoiceDate"));
        deInvoiceDate->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(deInvoiceDate, 3, 1, 1, 1);

        leInvoiceNo = new EQLineEdit(tabCommon);
        leInvoiceNo->setObjectName(QString::fromUtf8("leInvoiceNo"));
        leInvoiceNo->setMinimumSize(QSize(100, 0));
        leInvoiceNo->setMaximumSize(QSize(25552, 16777215));

        gridLayout->addWidget(leInvoiceNo, 2, 1, 1, 1);

        label_5 = new QLabel(tabCommon);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 330, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 1, 1, 1);

        label_4 = new QLabel(tabCommon);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        lePartnerCode = new EQLineEdit(tabCommon);
        lePartnerCode->setObjectName(QString::fromUtf8("lePartnerCode"));
        lePartnerCode->setMinimumSize(QSize(0, 0));
        lePartnerCode->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(lePartnerCode, 0, 1, 1, 1);

        lePartnerName = new EQLineEdit(tabCommon);
        lePartnerName->setObjectName(QString::fromUtf8("lePartnerName"));
        lePartnerName->setMinimumSize(QSize(300, 0));

        gridLayout->addWidget(lePartnerName, 1, 1, 1, 1);

        label_8 = new QLabel(tabCommon);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 1, 0, 1, 1);

        tabWidget->addTab(tabCommon, QString());
        tabMaterials = new QWidget();
        tabMaterials->setObjectName(QString::fromUtf8("tabMaterials"));
        verticalLayout_3 = new QVBoxLayout(tabMaterials);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        wGoodsOps = new QWidget(tabMaterials);
        wGoodsOps->setObjectName(QString::fromUtf8("wGoodsOps"));
        horizontalLayout_2 = new QHBoxLayout(wGoodsOps);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnAddMaterial = new QToolButton(wGoodsOps);
        btnAddMaterial->setObjectName(QString::fromUtf8("btnAddMaterial"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddMaterial->setIcon(icon4);

        horizontalLayout_2->addWidget(btnAddMaterial);

        btnRemoveMaterial = new QToolButton(wGoodsOps);
        btnRemoveMaterial->setObjectName(QString::fromUtf8("btnRemoveMaterial"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRemoveMaterial->setIcon(icon5);

        horizontalLayout_2->addWidget(btnRemoveMaterial);

        btnNewMaterial = new QToolButton(wGoodsOps);
        btnNewMaterial->setObjectName(QString::fromUtf8("btnNewMaterial"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNewMaterial->setIcon(icon6);

        horizontalLayout_2->addWidget(btnNewMaterial);

        horizontalSpacer_3 = new QSpacerItem(761, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_3->addWidget(wGoodsOps);

        tblGoods = new EQTableWidget(tabMaterials);
        if (tblGoods->columnCount() < 6)
            tblGoods->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblGoods->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblGoods->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblGoods->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblGoods->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblGoods->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblGoods->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tblGoods->setObjectName(QString::fromUtf8("tblGoods"));
        tblGoods->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblGoods->setSelectionMode(QAbstractItemView::SingleSelection);
        tblGoods->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_3->addWidget(tblGoods);

        widget_5 = new QWidget(tabMaterials);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_5 = new QSpacerItem(712, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        label_9 = new QLabel(widget_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_3->addWidget(label_9);

        leTotal = new EQLineEdit(widget_5);
        leTotal->setObjectName(QString::fromUtf8("leTotal"));
        leTotal->setMaximumSize(QSize(100, 16777215));
        leTotal->setReadOnly(true);

        horizontalLayout_3->addWidget(leTotal);


        verticalLayout_3->addWidget(widget_5);

        tabWidget->addTab(tabMaterials, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_4 = new QHBoxLayout(tab);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        wAcc = new WCashEntry(tab);
        wAcc->setObjectName(QString::fromUtf8("wAcc"));

        horizontalLayout_4->addWidget(wAcc);

        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);


        verticalLayout_2->addWidget(widget);


        retranslateUi(StoreDoc);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(StoreDoc);
    } // setupUi

    void retranslateUi(QWidget *StoreDoc)
    {
        StoreDoc->setWindowTitle(QCoreApplication::translate("StoreDoc", "Form", nullptr));
        btnSaveDoc->setText(QCoreApplication::translate("StoreDoc", "...", nullptr));
        btnDraftDoc->setText(QCoreApplication::translate("StoreDoc", "...", nullptr));
        btnPrintDoc->setText(QCoreApplication::translate("StoreDoc", "...", nullptr));
        btnRemoveDoc->setText(QCoreApplication::translate("StoreDoc", "...", nullptr));
        lbStoreout->setText(QCoreApplication::translate("StoreDoc", "Store out", nullptr));
        lbStorein->setText(QCoreApplication::translate("StoreDoc", "Store in", nullptr));
        label_2->setText(QCoreApplication::translate("StoreDoc", "Number", nullptr));
        label_3->setText(QCoreApplication::translate("StoreDoc", "Action", nullptr));
        label->setText(QCoreApplication::translate("StoreDoc", "Date", nullptr));
        label_7->setText(QCoreApplication::translate("StoreDoc", "Comments", nullptr));
        label_10->setText(QCoreApplication::translate("StoreDoc", "Payment", nullptr));
        label_6->setText(QCoreApplication::translate("StoreDoc", "Invoice date", nullptr));
        label_5->setText(QCoreApplication::translate("StoreDoc", "Invoice number", nullptr));
        label_4->setText(QCoreApplication::translate("StoreDoc", "Partner code", nullptr));
        label_8->setText(QCoreApplication::translate("StoreDoc", "Partner name", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCommon), QCoreApplication::translate("StoreDoc", "Common", nullptr));
        btnAddMaterial->setText(QCoreApplication::translate("StoreDoc", "...", nullptr));
        btnRemoveMaterial->setText(QCoreApplication::translate("StoreDoc", "...", nullptr));
        btnNewMaterial->setText(QCoreApplication::translate("StoreDoc", "...", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblGoods->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("StoreDoc", "RowId", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblGoods->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("StoreDoc", "Goods Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblGoods->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("StoreDoc", "Goods Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblGoods->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("StoreDoc", "Qty", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblGoods->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("StoreDoc", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblGoods->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("StoreDoc", "Total", nullptr));
        label_9->setText(QCoreApplication::translate("StoreDoc", "Total", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabMaterials), QCoreApplication::translate("StoreDoc", "Materials", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("StoreDoc", "Cashdesk", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StoreDoc: public Ui_StoreDoc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOREDOC_H
