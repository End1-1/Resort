/********************************************************************************
** Form generated from reading UI file 'rerestdish.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RERESTDISH_H
#define UI_RERESTDISH_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <ecolorlineedit.h>
#include <eqlineedit.h>
#include <eqtablewidget.h>
#include <eqtextedit.h>

QT_BEGIN_NAMESPACE

class Ui_RERestDish
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabPage;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    EQLineEdit *leNameRu;
    EQLineEdit *leQueue;
    EColorLineEdit *leBgColor;
    EQTextEdit *teEn;
    EQTextEdit *teAm;
    EQTextEdit *teRu;
    QLabel *label_13;
    QLabel *label_14;
    EQLineEdit *leLastPrice;
    EQLineEdit *leArmSoft;
    QLabel *label_15;
    EQLineEdit *leADGT;
    EQLineEdit *leTypeCode;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *label_11;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_12;
    QLabel *label_10;
    EQLineEdit *leCode;
    QPushButton *btnTextColor;
    EQLineEdit *lePart;
    EQLineEdit *leNameEn;
    EQLineEdit *leTypeName;
    QPushButton *btnBgColor;
    EQLineEdit *leNameAm;
    EColorLineEdit *leTextColor;
    QLabel *label_16;
    QCheckBox *chAutoPrintTax;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tblMenu;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnAddModifier;
    QTableWidget *tblModifier;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btnLoadImage;
    QLabel *lbImage;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *btnAppendRecipe;
    QToolButton *btnRemoveRecipeRow;
    QToolButton *btnClearRecipe;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *chContainItself;
    EQTableWidget *tblRecipe;
    QWidget *tab_6;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    EQLineEdit *leReadScancode;
    QListWidget *lstScancodes;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *btnTrack;

    void setupUi(QDialog *RERestDish)
    {
        if (RERestDish->objectName().isEmpty())
            RERestDish->setObjectName(QString::fromUtf8("RERestDish"));
        RERestDish->resize(643, 624);
        verticalLayout = new QVBoxLayout(RERestDish);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabPage = new QTabWidget(RERestDish);
        tabPage->setObjectName(QString::fromUtf8("tabPage"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leNameRu = new EQLineEdit(tab);
        leNameRu->setObjectName(QString::fromUtf8("leNameRu"));

        gridLayout->addWidget(leNameRu, 5, 2, 1, 3);

        leQueue = new EQLineEdit(tab);
        leQueue->setObjectName(QString::fromUtf8("leQueue"));

        gridLayout->addWidget(leQueue, 11, 2, 1, 3);

        leBgColor = new EColorLineEdit(tab);
        leBgColor->setObjectName(QString::fromUtf8("leBgColor"));
        leBgColor->setReadOnly(true);

        gridLayout->addWidget(leBgColor, 9, 2, 1, 2);

        teEn = new EQTextEdit(tab);
        teEn->setObjectName(QString::fromUtf8("teEn"));
        teEn->setMaximumSize(QSize(16777215, 40));

        gridLayout->addWidget(teEn, 7, 2, 1, 3);

        teAm = new EQTextEdit(tab);
        teAm->setObjectName(QString::fromUtf8("teAm"));
        teAm->setMaximumSize(QSize(16777215, 40));

        gridLayout->addWidget(teAm, 6, 2, 1, 3);

        teRu = new EQTextEdit(tab);
        teRu->setObjectName(QString::fromUtf8("teRu"));
        teRu->setMaximumSize(QSize(16777215, 40));

        gridLayout->addWidget(teRu, 8, 2, 1, 3);

        label_13 = new QLabel(tab);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 12, 0, 1, 1);

        label_14 = new QLabel(tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 13, 0, 1, 1);

        leLastPrice = new EQLineEdit(tab);
        leLastPrice->setObjectName(QString::fromUtf8("leLastPrice"));

        gridLayout->addWidget(leLastPrice, 14, 2, 1, 3);

        leArmSoft = new EQLineEdit(tab);
        leArmSoft->setObjectName(QString::fromUtf8("leArmSoft"));

        gridLayout->addWidget(leArmSoft, 13, 2, 1, 3);

        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout->addWidget(label_15, 14, 0, 1, 1);

        leADGT = new EQLineEdit(tab);
        leADGT->setObjectName(QString::fromUtf8("leADGT"));

        gridLayout->addWidget(leADGT, 12, 2, 1, 3);

        leTypeCode = new EQLineEdit(tab);
        leTypeCode->setObjectName(QString::fromUtf8("leTypeCode"));
        leTypeCode->setMaximumSize(QSize(70, 16777215));
        leTypeCode->setProperty("ShowButton", QVariant(true));

        gridLayout->addWidget(leTypeCode, 2, 2, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 8, 0, 1, 1);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 10, 0, 1, 1);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 7, 0, 1, 1);

        label_12 = new QLabel(tab);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 11, 0, 1, 1);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 9, 0, 1, 1);

        leCode = new EQLineEdit(tab);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setFocusPolicy(Qt::NoFocus);
        leCode->setReadOnly(true);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 2, 1, 3);

        btnTextColor = new QPushButton(tab);
        btnTextColor->setObjectName(QString::fromUtf8("btnTextColor"));
        btnTextColor->setMinimumSize(QSize(25, 25));
        btnTextColor->setMaximumSize(QSize(25, 25));
        btnTextColor->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/selection.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTextColor->setIcon(icon);

        gridLayout->addWidget(btnTextColor, 10, 4, 1, 1);

        lePart = new EQLineEdit(tab);
        lePart->setObjectName(QString::fromUtf8("lePart"));
        lePart->setFocusPolicy(Qt::NoFocus);
        lePart->setReadOnly(true);

        gridLayout->addWidget(lePart, 1, 2, 1, 3);

        leNameEn = new EQLineEdit(tab);
        leNameEn->setObjectName(QString::fromUtf8("leNameEn"));

        gridLayout->addWidget(leNameEn, 4, 2, 1, 3);

        leTypeName = new EQLineEdit(tab);
        leTypeName->setObjectName(QString::fromUtf8("leTypeName"));
        leTypeName->setFocusPolicy(Qt::NoFocus);
        leTypeName->setReadOnly(true);

        gridLayout->addWidget(leTypeName, 2, 3, 1, 2);

        btnBgColor = new QPushButton(tab);
        btnBgColor->setObjectName(QString::fromUtf8("btnBgColor"));
        btnBgColor->setMinimumSize(QSize(25, 25));
        btnBgColor->setMaximumSize(QSize(25, 25));
        btnBgColor->setFocusPolicy(Qt::NoFocus);
        btnBgColor->setIcon(icon);

        gridLayout->addWidget(btnBgColor, 9, 4, 1, 1);

        leNameAm = new EQLineEdit(tab);
        leNameAm->setObjectName(QString::fromUtf8("leNameAm"));

        gridLayout->addWidget(leNameAm, 3, 2, 1, 3);

        leTextColor = new EColorLineEdit(tab);
        leTextColor->setObjectName(QString::fromUtf8("leTextColor"));
        leTextColor->setReadOnly(true);

        gridLayout->addWidget(leTextColor, 10, 2, 1, 2);

        label_16 = new QLabel(tab);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 15, 0, 1, 1);

        chAutoPrintTax = new QCheckBox(tab);
        chAutoPrintTax->setObjectName(QString::fromUtf8("chAutoPrintTax"));

        gridLayout->addWidget(chAutoPrintTax, 15, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        tabPage->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_2 = new QHBoxLayout(tab_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tblMenu = new QTableWidget(tab_2);
        if (tblMenu->columnCount() < 10)
            tblMenu->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblMenu->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblMenu->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblMenu->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblMenu->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblMenu->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblMenu->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblMenu->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblMenu->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblMenu->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tblMenu->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        tblMenu->setObjectName(QString::fromUtf8("tblMenu"));
        tblMenu->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblMenu->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblMenu->setSelectionMode(QAbstractItemView::NoSelection);
        tblMenu->verticalHeader()->setVisible(false);
        tblMenu->verticalHeader()->setDefaultSectionSize(25);

        horizontalLayout_2->addWidget(tblMenu);

        tabPage->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        btnAddModifier = new QPushButton(tab_3);
        btnAddModifier->setObjectName(QString::fromUtf8("btnAddModifier"));
        btnAddModifier->setMinimumSize(QSize(25, 25));
        btnAddModifier->setMaximumSize(QSize(25, 25));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddModifier->setIcon(icon1);

        verticalLayout_3->addWidget(btnAddModifier);

        tblModifier = new QTableWidget(tab_3);
        if (tblModifier->columnCount() < 4)
            tblModifier->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblModifier->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tblModifier->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tblModifier->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tblModifier->setHorizontalHeaderItem(3, __qtablewidgetitem13);
        tblModifier->setObjectName(QString::fromUtf8("tblModifier"));
        tblModifier->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblModifier->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblModifier->setSelectionMode(QAbstractItemView::NoSelection);

        verticalLayout_3->addWidget(tblModifier);

        tabPage->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_4 = new QVBoxLayout(tab_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        btnLoadImage = new QPushButton(tab_4);
        btnLoadImage->setObjectName(QString::fromUtf8("btnLoadImage"));
        btnLoadImage->setMinimumSize(QSize(25, 25));
        btnLoadImage->setMaximumSize(QSize(25, 25));
        btnLoadImage->setIcon(icon1);

        verticalLayout_4->addWidget(btnLoadImage);

        lbImage = new QLabel(tab_4);
        lbImage->setObjectName(QString::fromUtf8("lbImage"));
        lbImage->setPixmap(QPixmap(QString::fromUtf8(":/images/cancel.png")));
        lbImage->setScaledContents(true);
        lbImage->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lbImage);

        tabPage->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        verticalLayout_5 = new QVBoxLayout(tab_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        widget = new QWidget(tab_5);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        btnAppendRecipe = new QToolButton(widget);
        btnAppendRecipe->setObjectName(QString::fromUtf8("btnAppendRecipe"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAppendRecipe->setIcon(icon2);

        horizontalLayout_3->addWidget(btnAppendRecipe);

        btnRemoveRecipeRow = new QToolButton(widget);
        btnRemoveRecipeRow->setObjectName(QString::fromUtf8("btnRemoveRecipeRow"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRemoveRecipeRow->setIcon(icon3);

        horizontalLayout_3->addWidget(btnRemoveRecipeRow);

        btnClearRecipe = new QToolButton(widget);
        btnClearRecipe->setObjectName(QString::fromUtf8("btnClearRecipe"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/garbage.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClearRecipe->setIcon(icon4);

        horizontalLayout_3->addWidget(btnClearRecipe);

        horizontalSpacer_3 = new QSpacerItem(414, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        chContainItself = new QCheckBox(widget);
        chContainItself->setObjectName(QString::fromUtf8("chContainItself"));

        horizontalLayout_3->addWidget(chContainItself);


        verticalLayout_5->addWidget(widget);

        tblRecipe = new EQTableWidget(tab_5);
        if (tblRecipe->columnCount() < 3)
            tblRecipe->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tblRecipe->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tblRecipe->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tblRecipe->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        tblRecipe->setObjectName(QString::fromUtf8("tblRecipe"));
        tblRecipe->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblRecipe->setSelectionMode(QAbstractItemView::SingleSelection);
        tblRecipe->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_5->addWidget(tblRecipe);

        tabPage->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        verticalLayout_6 = new QVBoxLayout(tab_6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        widget_2 = new QWidget(tab_6);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        leReadScancode = new EQLineEdit(widget_2);
        leReadScancode->setObjectName(QString::fromUtf8("leReadScancode"));

        horizontalLayout_4->addWidget(leReadScancode);


        verticalLayout_6->addWidget(widget_2);

        lstScancodes = new QListWidget(tab_6);
        lstScancodes->setObjectName(QString::fromUtf8("lstScancodes"));

        verticalLayout_6->addWidget(lstScancodes);

        tabPage->addTab(tab_6, QString());

        verticalLayout->addWidget(tabPage);

        frame = new QFrame(RERestDish);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(91, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(frame);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(frame);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(90, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnTrack = new QToolButton(frame);
        btnTrack->setObjectName(QString::fromUtf8("btnTrack"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/tracking.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTrack->setIcon(icon5);

        horizontalLayout->addWidget(btnTrack);


        verticalLayout->addWidget(frame);

        QWidget::setTabOrder(lePart, leTypeCode);
        QWidget::setTabOrder(leTypeCode, leNameAm);
        QWidget::setTabOrder(leNameAm, leNameEn);
        QWidget::setTabOrder(leNameEn, leNameRu);
        QWidget::setTabOrder(leNameRu, teAm);
        QWidget::setTabOrder(teAm, teEn);
        QWidget::setTabOrder(teEn, teRu);
        QWidget::setTabOrder(teRu, leBgColor);
        QWidget::setTabOrder(leBgColor, leTextColor);
        QWidget::setTabOrder(leTextColor, leQueue);
        QWidget::setTabOrder(leQueue, btnBgColor);
        QWidget::setTabOrder(btnBgColor, leTypeName);
        QWidget::setTabOrder(leTypeName, btnCancel);
        QWidget::setTabOrder(btnCancel, btnOk);
        QWidget::setTabOrder(btnOk, btnTextColor);
        QWidget::setTabOrder(btnTextColor, leCode);
        QWidget::setTabOrder(leCode, tabPage);
        QWidget::setTabOrder(tabPage, tblMenu);
        QWidget::setTabOrder(tblMenu, tblModifier);
        QWidget::setTabOrder(tblModifier, btnAddModifier);
        QWidget::setTabOrder(btnAddModifier, btnLoadImage);

        retranslateUi(RERestDish);

        tabPage->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RERestDish);
    } // setupUi

    void retranslateUi(QDialog *RERestDish)
    {
        RERestDish->setWindowTitle(QCoreApplication::translate("RERestDish", "Dish", nullptr));
        leNameRu->setProperty("Field", QVariant(QCoreApplication::translate("RERestDish", "f_ru", nullptr)));
        leQueue->setProperty("Field", QVariant(QCoreApplication::translate("RERestDish", "f_queue", nullptr)));
        leBgColor->setProperty("Field", QVariant(QCoreApplication::translate("RERestDish", "f_bgColor", nullptr)));
        teEn->setProperty("Field", QVariant(QCoreApplication::translate("RERestDish", "f_text_en", nullptr)));
        teAm->setProperty("Field", QVariant(QCoreApplication::translate("RERestDish", "f_text_am", nullptr)));
        teRu->setProperty("Field", QVariant(QCoreApplication::translate("RERestDish", "f_text_ru", nullptr)));
        label_13->setText(QCoreApplication::translate("RERestDish", "ADGT", nullptr));
        label_14->setText(QCoreApplication::translate("RERestDish", "ArmSoft code", nullptr));
        leArmSoft->setProperty("Field", QVariant(QCoreApplication::translate("RERestDish", "f_as", nullptr)));
        label_15->setText(QCoreApplication::translate("RERestDish", "Last input price", nullptr));
        leADGT->setProperty("Field", QVariant(QCoreApplication::translate("RERestDish", "f_adgt", nullptr)));
        leTypeCode->setProperty("Field", QVariant(QCoreApplication::translate("RERestDish", "f_type", nullptr)));
        label_2->setText(QCoreApplication::translate("RERestDish", "Part", nullptr));
        label->setText(QCoreApplication::translate("RERestDish", "Code", nullptr));
        label_3->setText(QCoreApplication::translate("RERestDish", "Type", nullptr));
        label_5->setText(QCoreApplication::translate("RERestDish", "Name, en", nullptr));
        label_4->setText(QCoreApplication::translate("RERestDish", "Name, am", nullptr));
        label_9->setText(QCoreApplication::translate("RERestDish", "Description, ru", nullptr));
        label_6->setText(QCoreApplication::translate("RERestDish", "Name, ru", nullptr));
        label_11->setText(QCoreApplication::translate("RERestDish", "Text color", nullptr));
        label_7->setText(QCoreApplication::translate("RERestDish", "Description, am", nullptr));
        label_8->setText(QCoreApplication::translate("RERestDish", "Description, en", nullptr));
        label_12->setText(QCoreApplication::translate("RERestDish", "Queue", nullptr));
        label_10->setText(QCoreApplication::translate("RERestDish", "Background color", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("RERestDish", "f_id", nullptr)));
        btnTextColor->setText(QString());
        leNameEn->setProperty("Field", QVariant(QCoreApplication::translate("RERestDish", "f_en", nullptr)));
        btnBgColor->setText(QString());
        leNameAm->setProperty("Field", QVariant(QCoreApplication::translate("RERestDish", "f_am", nullptr)));
        leTextColor->setProperty("Field", QVariant(QCoreApplication::translate("RERestDish", "f_textColor", nullptr)));
        label_16->setText(QCoreApplication::translate("RERestDish", "Automaticaly print tax", nullptr));
        chAutoPrintTax->setText(QString());
        tabPage->setTabText(tabPage->indexOf(tab), QCoreApplication::translate("RERestDish", "Main", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblMenu->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QCoreApplication::translate("RERestDish", "MenuRecID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblMenu->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("RERestDish", "MenuId", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblMenu->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("RERestDish", "Menu", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblMenu->horizontalHeaderItem(4);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("RERestDish", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblMenu->horizontalHeaderItem(5);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("RERestDish", "Print 1", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblMenu->horizontalHeaderItem(6);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("RERestDish", "Print 2", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblMenu->horizontalHeaderItem(7);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("RERestDish", "StoreId", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblMenu->horizontalHeaderItem(8);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("RERestDish", "Store", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblMenu->horizontalHeaderItem(9);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("RERestDish", "Complex", nullptr));
        tabPage->setTabText(tabPage->indexOf(tab_2), QCoreApplication::translate("RERestDish", "Menu", nullptr));
        btnAddModifier->setText(QString());
        QTableWidgetItem *___qtablewidgetitem9 = tblModifier->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("RERestDish", "RecId", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblModifier->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("RERestDish", "Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblModifier->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("RERestDish", "Name", nullptr));
        tabPage->setTabText(tabPage->indexOf(tab_3), QCoreApplication::translate("RERestDish", "Required modifiers", nullptr));
        btnLoadImage->setText(QString());
        lbImage->setText(QString());
        tabPage->setTabText(tabPage->indexOf(tab_4), QCoreApplication::translate("RERestDish", "Image", nullptr));
        btnAppendRecipe->setText(QCoreApplication::translate("RERestDish", "...", nullptr));
        btnRemoveRecipeRow->setText(QCoreApplication::translate("RERestDish", "...", nullptr));
        btnClearRecipe->setText(QCoreApplication::translate("RERestDish", "...", nullptr));
        chContainItself->setText(QCoreApplication::translate("RERestDish", "Contains itself", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblRecipe->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("RERestDish", "Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tblRecipe->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("RERestDish", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tblRecipe->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("RERestDish", "Qty", nullptr));
        tabPage->setTabText(tabPage->indexOf(tab_5), QCoreApplication::translate("RERestDish", "Recipe", nullptr));
        tabPage->setTabText(tabPage->indexOf(tab_6), QCoreApplication::translate("RERestDish", "Scancode", nullptr));
        btnOk->setText(QCoreApplication::translate("RERestDish", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("RERestDish", "Cancel", nullptr));
        btnTrack->setText(QCoreApplication::translate("RERestDish", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RERestDish: public Ui_RERestDish {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RERESTDISH_H
