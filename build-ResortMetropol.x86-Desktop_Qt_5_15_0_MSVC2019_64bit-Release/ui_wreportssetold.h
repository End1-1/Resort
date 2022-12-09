/********************************************************************************
** Form generated from reading UI file 'wreportssetold.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WREPORTSSETOLD_H
#define UI_WREPORTSSETOLD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eradiobutton.h>
#include <eyearcombo.h>
#include <wcheckboxgroup.h>

QT_BEGIN_NAMESPACE

class Ui_WReportsSetOld
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    EYearCombo *cbYear;
    QPushButton *btnGo;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QPushButton *btnHelp;
    WCheckBoxGroup *wCh;
    QGridLayout *gridLayout_4;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox;
    QCheckBox *checkBox_11;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_12;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_2;
    QCheckBox *chYear;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QCheckBox *chUseDateRange;
    EDateEdit *deDate1;
    EDateEdit *deDate2;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    ERadioButton *rbrCategory;
    ERadioButton *rbrCategoryYearly;
    ERadioButton *rbrOccupancyCategory;
    QSpacerItem *verticalSpacer;
    QWidget *wdtFilter;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *hlFilter;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    ERadioButton *rbrCardex;
    ERadioButton *rbCardexCategory;
    ERadioButton *rbrCardexYearly;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_6;
    ERadioButton *rbrSalesMan;
    ERadioButton *rbrSalesManYearly;
    QSpacerItem *verticalSpacer_5;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_9;
    ERadioButton *rbrNationality;
    ERadioButton *rbrNatYearly;
    QSpacerItem *verticalSpacer_7;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_8;
    ERadioButton *rbrArrangement;
    ERadioButton *rbrPax;
    QSpacerItem *verticalSpacer_6;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_7;
    ERadioButton *rbrMarketSigment;
    ERadioButton *rbrMarketSigmentYearly;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *WReportsSetOld)
    {
        if (WReportsSetOld->objectName().isEmpty())
            WReportsSetOld->setObjectName(QString::fromUtf8("WReportsSetOld"));
        WReportsSetOld->resize(905, 731);
        verticalLayout = new QVBoxLayout(WReportsSetOld);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(WReportsSetOld);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setFocusPolicy(Qt::NoFocus);
        tabWidget->setTabsClosable(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(tab);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        cbYear = new EYearCombo(widget);
        cbYear->setObjectName(QString::fromUtf8("cbYear"));
        cbYear->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(cbYear, 1, 1, 1, 1);

        btnGo = new QPushButton(widget);
        btnGo->setObjectName(QString::fromUtf8("btnGo"));
        btnGo->setMaximumSize(QSize(39, 40));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/goto.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGo->setIcon(icon);
        btnGo->setIconSize(QSize(32, 32));

        gridLayout->addWidget(btnGo, 1, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        btnHelp = new QPushButton(widget);
        btnHelp->setObjectName(QString::fromUtf8("btnHelp"));
        btnHelp->setMaximumSize(QSize(39, 40));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/question.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHelp->setIcon(icon1);
        btnHelp->setIconSize(QSize(32, 32));

        gridLayout->addWidget(btnHelp, 1, 3, 1, 1);


        verticalLayout_2->addWidget(widget);

        wCh = new WCheckBoxGroup(tab);
        wCh->setObjectName(QString::fromUtf8("wCh"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(wCh->sizePolicy().hasHeightForWidth());
        wCh->setSizePolicy(sizePolicy);
        wCh->setMinimumSize(QSize(0, 0));
        wCh->setStyleSheet(QString::fromUtf8(""));
        gridLayout_4 = new QGridLayout(wCh);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setSizeConstraint(QLayout::SetMinimumSize);
        checkBox_7 = new QCheckBox(wCh);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setProperty("M", QVariant(4));

        gridLayout_4->addWidget(checkBox_7, 1, 4, 1, 1);

        checkBox_9 = new QCheckBox(wCh);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        checkBox_9->setProperty("M", QVariant(8));

        gridLayout_4->addWidget(checkBox_9, 2, 2, 1, 1);

        checkBox = new QCheckBox(wCh);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setProperty("M", QVariant(3));

        gridLayout_4->addWidget(checkBox, 1, 3, 1, 1);

        checkBox_11 = new QCheckBox(wCh);
        checkBox_11->setObjectName(QString::fromUtf8("checkBox_11"));
        checkBox_11->setProperty("M", QVariant(11));

        gridLayout_4->addWidget(checkBox_11, 2, 5, 1, 1);

        checkBox_5 = new QCheckBox(wCh);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setProperty("M", QVariant(6));

        gridLayout_4->addWidget(checkBox_5, 1, 6, 1, 1);

        checkBox_6 = new QCheckBox(wCh);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setProperty("M", QVariant(5));

        gridLayout_4->addWidget(checkBox_6, 1, 5, 1, 1);

        checkBox_10 = new QCheckBox(wCh);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));
        checkBox_10->setProperty("M", QVariant(10));

        gridLayout_4->addWidget(checkBox_10, 2, 4, 1, 1);

        checkBox_3 = new QCheckBox(wCh);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setProperty("M", QVariant(2));

        gridLayout_4->addWidget(checkBox_3, 1, 2, 1, 1);

        checkBox_4 = new QCheckBox(wCh);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setProperty("M", QVariant(1));

        gridLayout_4->addWidget(checkBox_4, 1, 1, 1, 1);

        checkBox_12 = new QCheckBox(wCh);
        checkBox_12->setObjectName(QString::fromUtf8("checkBox_12"));
        checkBox_12->setProperty("M", QVariant(12));

        gridLayout_4->addWidget(checkBox_12, 2, 6, 1, 1);

        checkBox_8 = new QCheckBox(wCh);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        checkBox_8->setProperty("M", QVariant(9));

        gridLayout_4->addWidget(checkBox_8, 2, 3, 1, 1);

        checkBox_2 = new QCheckBox(wCh);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setProperty("M", QVariant(7));

        gridLayout_4->addWidget(checkBox_2, 2, 1, 1, 1);

        chYear = new QCheckBox(wCh);
        chYear->setObjectName(QString::fromUtf8("chYear"));
        chYear->setProperty("M", QVariant(0));

        gridLayout_4->addWidget(chYear, 3, 1, 1, 1);


        verticalLayout_2->addWidget(wCh);

        widget_2 = new QWidget(tab);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        chUseDateRange = new QCheckBox(widget_2);
        chUseDateRange->setObjectName(QString::fromUtf8("chUseDateRange"));

        horizontalLayout->addWidget(chUseDateRange);

        deDate1 = new EDateEdit(widget_2);
        deDate1->setObjectName(QString::fromUtf8("deDate1"));
        deDate1->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(deDate1);

        deDate2 = new EDateEdit(widget_2);
        deDate2->setObjectName(QString::fromUtf8("deDate2"));
        deDate2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(deDate2);

        horizontalSpacer_2 = new QSpacerItem(521, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(tab);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy1);
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(widget_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        rbrCategory = new ERadioButton(groupBox);
        rbrCategory->setObjectName(QString::fromUtf8("rbrCategory"));

        verticalLayout_4->addWidget(rbrCategory);

        rbrCategoryYearly = new ERadioButton(groupBox);
        rbrCategoryYearly->setObjectName(QString::fromUtf8("rbrCategoryYearly"));

        verticalLayout_4->addWidget(rbrCategoryYearly);

        rbrOccupancyCategory = new ERadioButton(groupBox);
        rbrOccupancyCategory->setObjectName(QString::fromUtf8("rbrOccupancyCategory"));

        verticalLayout_4->addWidget(rbrOccupancyCategory);

        verticalSpacer = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        gridLayout_3->addWidget(groupBox, 2, 0, 2, 1);

        wdtFilter = new QWidget(widget_3);
        wdtFilter->setObjectName(QString::fromUtf8("wdtFilter"));
        wdtFilter->setMinimumSize(QSize(0, 30));
        wdtFilter->setMaximumSize(QSize(16777215, 30));
        verticalLayout_10 = new QVBoxLayout(wdtFilter);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        hlFilter = new QHBoxLayout();
        hlFilter->setObjectName(QString::fromUtf8("hlFilter"));

        verticalLayout_10->addLayout(hlFilter);


        gridLayout_3->addWidget(wdtFilter, 0, 0, 1, 3);

        groupBox_3 = new QGroupBox(widget_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        rbrCardex = new ERadioButton(groupBox_3);
        rbrCardex->setObjectName(QString::fromUtf8("rbrCardex"));

        verticalLayout_5->addWidget(rbrCardex);

        rbCardexCategory = new ERadioButton(groupBox_3);
        rbCardexCategory->setObjectName(QString::fromUtf8("rbCardexCategory"));

        verticalLayout_5->addWidget(rbCardexCategory);

        rbrCardexYearly = new ERadioButton(groupBox_3);
        rbrCardexYearly->setObjectName(QString::fromUtf8("rbrCardexYearly"));

        verticalLayout_5->addWidget(rbrCardexYearly);

        verticalSpacer_2 = new QSpacerItem(20, 51, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);


        gridLayout_3->addWidget(groupBox_3, 4, 0, 1, 1);

        groupBox_4 = new QGroupBox(widget_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_6 = new QVBoxLayout(groupBox_4);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        rbrSalesMan = new ERadioButton(groupBox_4);
        rbrSalesMan->setObjectName(QString::fromUtf8("rbrSalesMan"));

        verticalLayout_6->addWidget(rbrSalesMan);

        rbrSalesManYearly = new ERadioButton(groupBox_4);
        rbrSalesManYearly->setObjectName(QString::fromUtf8("rbrSalesManYearly"));

        verticalLayout_6->addWidget(rbrSalesManYearly);

        verticalSpacer_5 = new QSpacerItem(20, 51, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_5);


        gridLayout_3->addWidget(groupBox_4, 4, 1, 1, 1);

        groupBox_2 = new QGroupBox(widget_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_9 = new QVBoxLayout(groupBox_2);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        rbrNationality = new ERadioButton(groupBox_2);
        rbrNationality->setObjectName(QString::fromUtf8("rbrNationality"));

        verticalLayout_9->addWidget(rbrNationality);

        rbrNatYearly = new ERadioButton(groupBox_2);
        rbrNatYearly->setObjectName(QString::fromUtf8("rbrNatYearly"));

        verticalLayout_9->addWidget(rbrNatYearly);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_7);


        gridLayout_3->addWidget(groupBox_2, 2, 1, 2, 1);

        groupBox_6 = new QGroupBox(widget_3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        verticalLayout_8 = new QVBoxLayout(groupBox_6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        rbrArrangement = new ERadioButton(groupBox_6);
        rbrArrangement->setObjectName(QString::fromUtf8("rbrArrangement"));

        verticalLayout_8->addWidget(rbrArrangement);

        rbrPax = new ERadioButton(groupBox_6);
        rbrPax->setObjectName(QString::fromUtf8("rbrPax"));

        verticalLayout_8->addWidget(rbrPax);

        verticalSpacer_6 = new QSpacerItem(20, 51, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_6);


        gridLayout_3->addWidget(groupBox_6, 4, 2, 1, 1);

        groupBox_5 = new QGroupBox(widget_3);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_7 = new QVBoxLayout(groupBox_5);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        rbrMarketSigment = new ERadioButton(groupBox_5);
        rbrMarketSigment->setObjectName(QString::fromUtf8("rbrMarketSigment"));

        verticalLayout_7->addWidget(rbrMarketSigment);

        rbrMarketSigmentYearly = new ERadioButton(groupBox_5);
        rbrMarketSigmentYearly->setObjectName(QString::fromUtf8("rbrMarketSigmentYearly"));

        verticalLayout_7->addWidget(rbrMarketSigmentYearly);

        verticalSpacer_4 = new QSpacerItem(20, 63, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_4);


        gridLayout_3->addWidget(groupBox_5, 2, 2, 2, 1);


        verticalLayout_2->addWidget(widget_3);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);

        QWidget::setTabOrder(cbYear, checkBox_4);
        QWidget::setTabOrder(checkBox_4, checkBox_3);
        QWidget::setTabOrder(checkBox_3, checkBox);
        QWidget::setTabOrder(checkBox, checkBox_7);
        QWidget::setTabOrder(checkBox_7, checkBox_6);
        QWidget::setTabOrder(checkBox_6, checkBox_5);
        QWidget::setTabOrder(checkBox_5, checkBox_2);
        QWidget::setTabOrder(checkBox_2, checkBox_9);
        QWidget::setTabOrder(checkBox_9, checkBox_8);
        QWidget::setTabOrder(checkBox_8, checkBox_10);
        QWidget::setTabOrder(checkBox_10, checkBox_11);
        QWidget::setTabOrder(checkBox_11, checkBox_12);
        QWidget::setTabOrder(checkBox_12, chYear);
        QWidget::setTabOrder(chYear, rbrCategory);
        QWidget::setTabOrder(rbrCategory, rbrCategoryYearly);
        QWidget::setTabOrder(rbrCategoryYearly, rbrOccupancyCategory);
        QWidget::setTabOrder(rbrOccupancyCategory, rbrNationality);
        QWidget::setTabOrder(rbrNationality, rbrNatYearly);
        QWidget::setTabOrder(rbrNatYearly, rbrMarketSigment);
        QWidget::setTabOrder(rbrMarketSigment, rbrMarketSigmentYearly);
        QWidget::setTabOrder(rbrMarketSigmentYearly, rbrCardex);
        QWidget::setTabOrder(rbrCardex, rbrCardexYearly);
        QWidget::setTabOrder(rbrCardexYearly, rbrSalesMan);
        QWidget::setTabOrder(rbrSalesMan, rbrSalesManYearly);
        QWidget::setTabOrder(rbrSalesManYearly, rbrArrangement);
        QWidget::setTabOrder(rbrArrangement, rbrPax);
        QWidget::setTabOrder(rbrPax, btnGo);
        QWidget::setTabOrder(btnGo, tabWidget);

        retranslateUi(WReportsSetOld);
        QObject::connect(rbrCategory, SIGNAL(clicked()), WReportsSetOld, SLOT(rbClicked()));
        QObject::connect(rbrCategoryYearly, SIGNAL(clicked()), WReportsSetOld, SLOT(rbClicked()));
        QObject::connect(rbrOccupancyCategory, SIGNAL(clicked()), WReportsSetOld, SLOT(rbClicked()));
        QObject::connect(rbrNationality, SIGNAL(clicked()), WReportsSetOld, SLOT(rbClicked()));
        QObject::connect(rbrNatYearly, SIGNAL(clicked()), WReportsSetOld, SLOT(rbClicked()));
        QObject::connect(rbrCardex, SIGNAL(clicked()), WReportsSetOld, SLOT(rbClicked()));
        QObject::connect(rbrCardexYearly, SIGNAL(clicked()), WReportsSetOld, SLOT(rbClicked()));
        QObject::connect(rbrSalesMan, SIGNAL(clicked()), WReportsSetOld, SLOT(rbClicked()));
        QObject::connect(rbrSalesManYearly, SIGNAL(clicked()), WReportsSetOld, SLOT(rbClicked()));
        QObject::connect(rbrMarketSigment, SIGNAL(clicked()), WReportsSetOld, SLOT(rbClicked()));
        QObject::connect(rbrMarketSigmentYearly, SIGNAL(clicked()), WReportsSetOld, SLOT(rbClicked()));
        QObject::connect(rbrArrangement, SIGNAL(clicked()), WReportsSetOld, SLOT(rbClicked()));
        QObject::connect(rbrPax, SIGNAL(clicked()), WReportsSetOld, SLOT(rbClicked()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WReportsSetOld);
    } // setupUi

    void retranslateUi(QWidget *WReportsSetOld)
    {
        WReportsSetOld->setWindowTitle(QCoreApplication::translate("WReportsSetOld", "Form", nullptr));
        btnGo->setText(QString());
        label->setText(QCoreApplication::translate("WReportsSetOld", "Year", nullptr));
        btnHelp->setText(QString());
        checkBox_7->setText(QCoreApplication::translate("WReportsSetOld", "April", nullptr));
        checkBox_9->setText(QCoreApplication::translate("WReportsSetOld", "August", nullptr));
        checkBox->setText(QCoreApplication::translate("WReportsSetOld", "March", nullptr));
        checkBox_11->setText(QCoreApplication::translate("WReportsSetOld", "November", nullptr));
        checkBox_5->setText(QCoreApplication::translate("WReportsSetOld", "June", nullptr));
        checkBox_6->setText(QCoreApplication::translate("WReportsSetOld", "May", nullptr));
        checkBox_10->setText(QCoreApplication::translate("WReportsSetOld", "October", nullptr));
        checkBox_3->setText(QCoreApplication::translate("WReportsSetOld", "February", nullptr));
        checkBox_4->setText(QCoreApplication::translate("WReportsSetOld", "January", nullptr));
        checkBox_12->setText(QCoreApplication::translate("WReportsSetOld", "December", nullptr));
        checkBox_8->setText(QCoreApplication::translate("WReportsSetOld", "September", nullptr));
        checkBox_2->setText(QCoreApplication::translate("WReportsSetOld", "July", nullptr));
        chYear->setText(QCoreApplication::translate("WReportsSetOld", "Year", nullptr));
        chUseDateRange->setText(QCoreApplication::translate("WReportsSetOld", "Use date range*", nullptr));
        groupBox->setTitle(QCoreApplication::translate("WReportsSetOld", "Category", nullptr));
        rbrCategory->setText(QCoreApplication::translate("WReportsSetOld", "Category*", nullptr));
        rbrCategoryYearly->setText(QCoreApplication::translate("WReportsSetOld", "Category/Yearly", nullptr));
        rbrOccupancyCategory->setText(QCoreApplication::translate("WReportsSetOld", "Occupancy/Category", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("WReportsSetOld", "Cardex", nullptr));
        rbrCardex->setText(QCoreApplication::translate("WReportsSetOld", "Cardex*", nullptr));
        rbCardexCategory->setText(QCoreApplication::translate("WReportsSetOld", "Cardex group / Category**", nullptr));
        rbrCardexYearly->setText(QCoreApplication::translate("WReportsSetOld", "Cardex / Yearly", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("WReportsSetOld", "Salesman", nullptr));
        rbrSalesMan->setText(QCoreApplication::translate("WReportsSetOld", "Saleman", nullptr));
        rbrSalesManYearly->setText(QCoreApplication::translate("WReportsSetOld", "Salesman / Yearly", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("WReportsSetOld", "Nationality", nullptr));
        rbrNationality->setText(QCoreApplication::translate("WReportsSetOld", "Nationality*", nullptr));
        rbrNatYearly->setText(QCoreApplication::translate("WReportsSetOld", "Nationality Yearly", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("WReportsSetOld", "Other", nullptr));
        rbrArrangement->setText(QCoreApplication::translate("WReportsSetOld", "Arrangement*", nullptr));
        rbrPax->setText(QCoreApplication::translate("WReportsSetOld", "Pax", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("WReportsSetOld", "Market sigment", nullptr));
        rbrMarketSigment->setText(QCoreApplication::translate("WReportsSetOld", "Market Sigment*", nullptr));
        rbrMarketSigmentYearly->setText(QCoreApplication::translate("WReportsSetOld", "Market sigment / Yearly", nullptr));
        label_2->setText(QCoreApplication::translate("WReportsSetOld", "<html><head/><body><p>* - &quot;Use date range&quot; filter available for this options</p><p>** - &quot;Available only with 'Use date range' option</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("WReportsSetOld", "Reports List", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WReportsSetOld: public Ui_WReportsSetOld {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WREPORTSSETOLD_H
