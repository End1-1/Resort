/********************************************************************************
** Form generated from reading UI file 'frestauranttotal.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRESTAURANTTOTAL_H
#define UI_FRESTAURANTTOTAL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqcheckbox.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_FRestaurantTotal
{
public:
    QGridLayout *gridLayout;
    EQCheckBox *chOrderNum;
    EQLineEdit *leStore;
    QLabel *label_5;
    EDateEdit *deStart;
    QLabel *label_14;
    EQCheckBox *chDishState;
    QLineEdit *leArmSoft;
    QFrame *line_2;
    QLabel *label_16;
    EQCheckBox *chArmSoft;
    EQLineEdit *leDishState;
    QFrame *line;
    QPushButton *btnOrdersSubtotal;
    QLabel *label_17;
    QLabel *label_15;
    EQLineEdit *lePMComment;
    QLabel *label_10;
    EQCheckBox *chTax;
    EQLineEdit *leTax;
    QLabel *label_4;
    EQLineEdit *leCL;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_6;
    EQCheckBox *chStaff;
    EQCheckBox *chCL;
    EQCheckBox *chTable;
    EQLineEdit *leTable;
    EQLineEdit *leStaff;
    EQCheckBox *chPMComment;
    EQCheckBox *chHall;
    EQCheckBox *chDishType;
    EQLineEdit *leHall;
    EQCheckBox *chPaymentMode;
    QLabel *label_2;
    EQLineEdit *leDish;
    EQLineEdit *leDishType;
    QLabel *label_8;
    EQCheckBox *chStore;
    EQCheckBox *chDish;
    QLabel *label;
    QLabel *label_13;
    EQCheckBox *chDate;
    QLabel *label_3;
    QLabel *label_7;
    EQCheckBox *chState;
    EQCheckBox *chShowOpenClose;
    QLabel *label_12;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rbShowComplex;
    QRadioButton *rbNoShowComplex;
    QRadioButton *rbOnlycomplex;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnPrevDate;
    QPushButton *btnNextDate;
    EQLineEdit *leOrder;
    EDateEdit *deEnd;
    EQLineEdit *leState;
    EQLineEdit *lePaymentMode;
    EQCheckBox *chShowOrderComment;

    void setupUi(QWidget *FRestaurantTotal)
    {
        if (FRestaurantTotal->objectName().isEmpty())
            FRestaurantTotal->setObjectName(QString::fromUtf8("FRestaurantTotal"));
        FRestaurantTotal->resize(907, 210);
        gridLayout = new QGridLayout(FRestaurantTotal);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        chOrderNum = new EQCheckBox(FRestaurantTotal);
        chOrderNum->setObjectName(QString::fromUtf8("chOrderNum"));
        chOrderNum->setFocusPolicy(Qt::ClickFocus);
        chOrderNum->setProperty("Tag", QVariant(13));

        gridLayout->addWidget(chOrderNum, 0, 4, 1, 1);

        leStore = new EQLineEdit(FRestaurantTotal);
        leStore->setObjectName(QString::fromUtf8("leStore"));
        leStore->setFocusPolicy(Qt::ClickFocus);
        leStore->setProperty("ShowButton", QVariant(true));
        leStore->setProperty("EnableHiddenText", QVariant(true));

        gridLayout->addWidget(leStore, 1, 11, 1, 1);

        label_5 = new QLabel(FRestaurantTotal);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 6, 1, 1);

        deStart = new EDateEdit(FRestaurantTotal);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        gridLayout->addWidget(deStart, 1, 2, 1, 1);

        label_14 = new QLabel(FRestaurantTotal);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 0, 0, 1, 1);

        chDishState = new EQCheckBox(FRestaurantTotal);
        chDishState->setObjectName(QString::fromUtf8("chDishState"));
        chDishState->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(chDishState, 0, 12, 1, 1);

        leArmSoft = new QLineEdit(FRestaurantTotal);
        leArmSoft->setObjectName(QString::fromUtf8("leArmSoft"));
        leArmSoft->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(leArmSoft, 6, 11, 1, 1);

        line_2 = new QFrame(FRestaurantTotal);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setMinimumSize(QSize(40, 0));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 0, 9, 7, 1);

        label_16 = new QLabel(FRestaurantTotal);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 6, 10, 1, 1);

        chArmSoft = new EQCheckBox(FRestaurantTotal);
        chArmSoft->setObjectName(QString::fromUtf8("chArmSoft"));
        chArmSoft->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(chArmSoft, 6, 12, 1, 1);

        leDishState = new EQLineEdit(FRestaurantTotal);
        leDishState->setObjectName(QString::fromUtf8("leDishState"));
        leDishState->setFocusPolicy(Qt::ClickFocus);
        leDishState->setProperty("EnableHiddenText", QVariant(true));

        gridLayout->addWidget(leDishState, 0, 11, 1, 1);

        line = new QFrame(FRestaurantTotal);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(40, 0));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 5, 7, 1);

        btnOrdersSubtotal = new QPushButton(FRestaurantTotal);
        btnOrdersSubtotal->setObjectName(QString::fromUtf8("btnOrdersSubtotal"));
        btnOrdersSubtotal->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(btnOrdersSubtotal, 6, 2, 1, 1);

        label_17 = new QLabel(FRestaurantTotal);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(label_17, 6, 6, 1, 1);

        label_15 = new QLabel(FRestaurantTotal);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout->addWidget(label_15, 0, 10, 1, 1);

        lePMComment = new EQLineEdit(FRestaurantTotal);
        lePMComment->setObjectName(QString::fromUtf8("lePMComment"));
        lePMComment->setFocusPolicy(Qt::ClickFocus);
        lePMComment->setProperty("ShowButton", QVariant(true));

        gridLayout->addWidget(lePMComment, 4, 7, 1, 1);

        label_10 = new QLabel(FRestaurantTotal);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 4, 6, 1, 1);

        chTax = new EQCheckBox(FRestaurantTotal);
        chTax->setObjectName(QString::fromUtf8("chTax"));
        chTax->setFocusPolicy(Qt::ClickFocus);
        chTax->setProperty("Tag", QVariant(11));

        gridLayout->addWidget(chTax, 4, 12, 1, 1);

        leTax = new EQLineEdit(FRestaurantTotal);
        leTax->setObjectName(QString::fromUtf8("leTax"));
        leTax->setFocusPolicy(Qt::ClickFocus);
        leTax->setProperty("ShowButton", QVariant(true));

        gridLayout->addWidget(leTax, 4, 11, 1, 1);

        label_4 = new QLabel(FRestaurantTotal);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 6, 1, 1);

        leCL = new EQLineEdit(FRestaurantTotal);
        leCL->setObjectName(QString::fromUtf8("leCL"));
        leCL->setFocusPolicy(Qt::ClickFocus);
        leCL->setProperty("ShowButton", QVariant(true));
        leCL->setProperty("EnableHiddenText", QVariant(true));

        gridLayout->addWidget(leCL, 3, 7, 1, 1);

        label_9 = new QLabel(FRestaurantTotal);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 4, 0, 1, 1);

        label_11 = new QLabel(FRestaurantTotal);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 3, 6, 1, 1);

        label_6 = new QLabel(FRestaurantTotal);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 6, 1, 1);

        chStaff = new EQCheckBox(FRestaurantTotal);
        chStaff->setObjectName(QString::fromUtf8("chStaff"));
        chStaff->setFocusPolicy(Qt::ClickFocus);
        chStaff->setProperty("Tag", QVariant(5));

        gridLayout->addWidget(chStaff, 2, 8, 1, 1);

        chCL = new EQCheckBox(FRestaurantTotal);
        chCL->setObjectName(QString::fromUtf8("chCL"));
        chCL->setFocusPolicy(Qt::ClickFocus);
        chCL->setProperty("Tag", QVariant(12));

        gridLayout->addWidget(chCL, 3, 8, 1, 1);

        chTable = new EQCheckBox(FRestaurantTotal);
        chTable->setObjectName(QString::fromUtf8("chTable"));
        chTable->setFocusPolicy(Qt::ClickFocus);
        chTable->setProperty("Tag", QVariant(4));

        gridLayout->addWidget(chTable, 1, 8, 1, 1);

        leTable = new EQLineEdit(FRestaurantTotal);
        leTable->setObjectName(QString::fromUtf8("leTable"));
        leTable->setFocusPolicy(Qt::ClickFocus);
        leTable->setProperty("ShowButton", QVariant(true));
        leTable->setProperty("EnableHiddenText", QVariant(true));

        gridLayout->addWidget(leTable, 1, 7, 1, 1);

        leStaff = new EQLineEdit(FRestaurantTotal);
        leStaff->setObjectName(QString::fromUtf8("leStaff"));
        leStaff->setFocusPolicy(Qt::ClickFocus);
        leStaff->setProperty("ShowButton", QVariant(true));
        leStaff->setProperty("EnableHiddenText", QVariant(true));

        gridLayout->addWidget(leStaff, 2, 7, 1, 1);

        chPMComment = new EQCheckBox(FRestaurantTotal);
        chPMComment->setObjectName(QString::fromUtf8("chPMComment"));
        chPMComment->setFocusPolicy(Qt::ClickFocus);
        chPMComment->setProperty("Tag", QVariant(10));

        gridLayout->addWidget(chPMComment, 4, 8, 1, 1);

        chHall = new EQCheckBox(FRestaurantTotal);
        chHall->setObjectName(QString::fromUtf8("chHall"));
        chHall->setFocusPolicy(Qt::ClickFocus);
        chHall->setProperty("Tag", QVariant(3));

        gridLayout->addWidget(chHall, 0, 8, 1, 1);

        chDishType = new EQCheckBox(FRestaurantTotal);
        chDishType->setObjectName(QString::fromUtf8("chDishType"));
        chDishType->setFocusPolicy(Qt::ClickFocus);
        chDishType->setProperty("Tag", QVariant(7));
        chDishType->setProperty("RequireLang", QVariant(true));

        gridLayout->addWidget(chDishType, 2, 12, 1, 1);

        leHall = new EQLineEdit(FRestaurantTotal);
        leHall->setObjectName(QString::fromUtf8("leHall"));
        leHall->setFocusPolicy(Qt::ClickFocus);
        leHall->setProperty("ShowButton", QVariant(true));
        leHall->setProperty("EnableHiddenText", QVariant(true));

        gridLayout->addWidget(leHall, 0, 7, 1, 1);

        chPaymentMode = new EQCheckBox(FRestaurantTotal);
        chPaymentMode->setObjectName(QString::fromUtf8("chPaymentMode"));
        chPaymentMode->setFocusPolicy(Qt::ClickFocus);
        chPaymentMode->setProperty("Tag", QVariant(9));
        chPaymentMode->setProperty("RequireLang", QVariant(true));

        gridLayout->addWidget(chPaymentMode, 4, 4, 1, 1);

        label_2 = new QLabel(FRestaurantTotal);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        leDish = new EQLineEdit(FRestaurantTotal);
        leDish->setObjectName(QString::fromUtf8("leDish"));
        leDish->setFocusPolicy(Qt::ClickFocus);
        leDish->setProperty("ShowButton", QVariant(true));
        leDish->setProperty("EnableHiddenText", QVariant(true));
        leDish->setProperty("RequireLang", QVariant(true));

        gridLayout->addWidget(leDish, 3, 11, 1, 1);

        leDishType = new EQLineEdit(FRestaurantTotal);
        leDishType->setObjectName(QString::fromUtf8("leDishType"));
        leDishType->setFocusPolicy(Qt::ClickFocus);
        leDishType->setProperty("ShowButton", QVariant(true));
        leDishType->setProperty("EnableHiddenText", QVariant(true));
        leDishType->setProperty("RequireLang", QVariant(true));

        gridLayout->addWidget(leDishType, 2, 11, 1, 1);

        label_8 = new QLabel(FRestaurantTotal);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 4, 10, 1, 1);

        chStore = new EQCheckBox(FRestaurantTotal);
        chStore->setObjectName(QString::fromUtf8("chStore"));
        chStore->setFocusPolicy(Qt::ClickFocus);
        chStore->setProperty("Tag", QVariant(6));

        gridLayout->addWidget(chStore, 1, 12, 1, 1);

        chDish = new EQCheckBox(FRestaurantTotal);
        chDish->setObjectName(QString::fromUtf8("chDish"));
        chDish->setFocusPolicy(Qt::ClickFocus);
        chDish->setProperty("Tag", QVariant(8));
        chDish->setProperty("RequireLang", QVariant(true));

        gridLayout->addWidget(chDish, 3, 12, 1, 1);

        label = new QLabel(FRestaurantTotal);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_13 = new QLabel(FRestaurantTotal);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 1, 10, 1, 1);

        chDate = new EQCheckBox(FRestaurantTotal);
        chDate->setObjectName(QString::fromUtf8("chDate"));
        chDate->setFocusPolicy(Qt::ClickFocus);
        chDate->setProperty("Tag", QVariant(1));

        gridLayout->addWidget(chDate, 1, 4, 1, 1);

        label_3 = new QLabel(FRestaurantTotal);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_7 = new QLabel(FRestaurantTotal);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 3, 10, 1, 1);

        chState = new EQCheckBox(FRestaurantTotal);
        chState->setObjectName(QString::fromUtf8("chState"));
        chState->setFocusPolicy(Qt::ClickFocus);
        chState->setProperty("Tag", QVariant(2));
        chState->setProperty("RequireLang", QVariant(true));

        gridLayout->addWidget(chState, 3, 4, 1, 1);

        chShowOpenClose = new EQCheckBox(FRestaurantTotal);
        chShowOpenClose->setObjectName(QString::fromUtf8("chShowOpenClose"));
        chShowOpenClose->setFocusPolicy(Qt::ClickFocus);
        chShowOpenClose->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(chShowOpenClose, 5, 2, 1, 3);

        label_12 = new QLabel(FRestaurantTotal);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 2, 10, 1, 1);

        widget = new QWidget(FRestaurantTotal);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        rbShowComplex = new QRadioButton(widget);
        rbShowComplex->setObjectName(QString::fromUtf8("rbShowComplex"));
        rbShowComplex->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(rbShowComplex);

        rbNoShowComplex = new QRadioButton(widget);
        rbNoShowComplex->setObjectName(QString::fromUtf8("rbNoShowComplex"));
        rbNoShowComplex->setFocusPolicy(Qt::ClickFocus);
        rbNoShowComplex->setChecked(true);

        horizontalLayout->addWidget(rbNoShowComplex);

        rbOnlycomplex = new QRadioButton(widget);
        rbOnlycomplex->setObjectName(QString::fromUtf8("rbOnlycomplex"));
        rbOnlycomplex->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(rbOnlycomplex);


        gridLayout->addWidget(widget, 6, 7, 1, 2);

        widget_2 = new QWidget(FRestaurantTotal);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(55, 0));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnPrevDate = new QPushButton(widget_2);
        btnPrevDate->setObjectName(QString::fromUtf8("btnPrevDate"));
        btnPrevDate->setFocusPolicy(Qt::ClickFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrevDate->setIcon(icon);

        horizontalLayout_2->addWidget(btnPrevDate);

        btnNextDate = new QPushButton(widget_2);
        btnNextDate->setObjectName(QString::fromUtf8("btnNextDate"));
        btnNextDate->setFocusPolicy(Qt::ClickFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNextDate->setIcon(icon1);

        horizontalLayout_2->addWidget(btnNextDate);


        gridLayout->addWidget(widget_2, 1, 3, 1, 1);

        leOrder = new EQLineEdit(FRestaurantTotal);
        leOrder->setObjectName(QString::fromUtf8("leOrder"));
        leOrder->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(leOrder, 0, 2, 1, 1);

        deEnd = new EDateEdit(FRestaurantTotal);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        gridLayout->addWidget(deEnd, 2, 2, 1, 1);

        leState = new EQLineEdit(FRestaurantTotal);
        leState->setObjectName(QString::fromUtf8("leState"));
        leState->setFocusPolicy(Qt::ClickFocus);
        leState->setProperty("ShowButton", QVariant(true));
        leState->setProperty("EnableHiddenText", QVariant(true));

        gridLayout->addWidget(leState, 3, 2, 1, 1);

        lePaymentMode = new EQLineEdit(FRestaurantTotal);
        lePaymentMode->setObjectName(QString::fromUtf8("lePaymentMode"));
        lePaymentMode->setFocusPolicy(Qt::ClickFocus);
        lePaymentMode->setProperty("ShowButton", QVariant(true));
        lePaymentMode->setProperty("EnableHiddenText", QVariant(true));
        lePaymentMode->setProperty("RequireLang", QVariant(true));

        gridLayout->addWidget(lePaymentMode, 4, 2, 1, 1);

        chShowOrderComment = new EQCheckBox(FRestaurantTotal);
        chShowOrderComment->setObjectName(QString::fromUtf8("chShowOrderComment"));
        chShowOrderComment->setFocusPolicy(Qt::ClickFocus);
        chShowOrderComment->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(chShowOrderComment, 5, 7, 1, 1);

        QWidget::setTabOrder(leOrder, chOrderNum);
        QWidget::setTabOrder(chOrderNum, deStart);
        QWidget::setTabOrder(deStart, chDate);
        QWidget::setTabOrder(chDate, deEnd);
        QWidget::setTabOrder(deEnd, leState);
        QWidget::setTabOrder(leState, chState);
        QWidget::setTabOrder(chState, lePaymentMode);
        QWidget::setTabOrder(lePaymentMode, chPaymentMode);
        QWidget::setTabOrder(chPaymentMode, leHall);
        QWidget::setTabOrder(leHall, chHall);
        QWidget::setTabOrder(chHall, leTable);
        QWidget::setTabOrder(leTable, chTable);
        QWidget::setTabOrder(chTable, leStaff);
        QWidget::setTabOrder(leStaff, chStaff);
        QWidget::setTabOrder(chStaff, leCL);
        QWidget::setTabOrder(leCL, chCL);
        QWidget::setTabOrder(chCL, lePMComment);
        QWidget::setTabOrder(lePMComment, chPMComment);
        QWidget::setTabOrder(chPMComment, leDishState);
        QWidget::setTabOrder(leDishState, chDishState);
        QWidget::setTabOrder(chDishState, leStore);
        QWidget::setTabOrder(leStore, chStore);
        QWidget::setTabOrder(chStore, leDishType);
        QWidget::setTabOrder(leDishType, chDishType);
        QWidget::setTabOrder(chDishType, leDish);
        QWidget::setTabOrder(leDish, chDish);
        QWidget::setTabOrder(chDish, leTax);
        QWidget::setTabOrder(leTax, chTax);
        QWidget::setTabOrder(chTax, leArmSoft);
        QWidget::setTabOrder(leArmSoft, chArmSoft);

        retranslateUi(FRestaurantTotal);
        QObject::connect(chDate, SIGNAL(clicked(bool)), FRestaurantTotal, SLOT(groupCheckClicked(bool)));
        QObject::connect(chStaff, SIGNAL(clicked(bool)), FRestaurantTotal, SLOT(groupCheckClicked(bool)));
        QObject::connect(chState, SIGNAL(clicked(bool)), FRestaurantTotal, SLOT(groupCheckClicked(bool)));
        QObject::connect(chHall, SIGNAL(clicked(bool)), FRestaurantTotal, SLOT(groupCheckClicked(bool)));
        QObject::connect(chTable, SIGNAL(clicked(bool)), FRestaurantTotal, SLOT(groupCheckClicked(bool)));
        QObject::connect(chCL, SIGNAL(clicked(bool)), FRestaurantTotal, SLOT(groupCheckClicked(bool)));
        QObject::connect(chTax, SIGNAL(clicked(bool)), FRestaurantTotal, SLOT(groupCheckClicked(bool)));
        QObject::connect(chPMComment, SIGNAL(clicked(bool)), FRestaurantTotal, SLOT(groupCheckClicked(bool)));
        QObject::connect(chPaymentMode, SIGNAL(clicked(bool)), FRestaurantTotal, SLOT(groupCheckClicked(bool)));
        QObject::connect(chDish, SIGNAL(clicked(bool)), FRestaurantTotal, SLOT(groupCheckClicked(bool)));
        QObject::connect(chDishType, SIGNAL(clicked(bool)), FRestaurantTotal, SLOT(groupCheckClicked(bool)));
        QObject::connect(chStore, SIGNAL(clicked(bool)), FRestaurantTotal, SLOT(groupCheckClicked(bool)));
        QObject::connect(chOrderNum, SIGNAL(clicked(bool)), FRestaurantTotal, SLOT(groupCheckClicked(bool)));
        QObject::connect(chArmSoft, SIGNAL(clicked(bool)), FRestaurantTotal, SLOT(groupCheckClicked(bool)));
        QObject::connect(chDishState, SIGNAL(clicked(bool)), FRestaurantTotal, SLOT(groupCheckClicked(bool)));
        QObject::connect(chShowOpenClose, SIGNAL(clicked(bool)), FRestaurantTotal, SLOT(groupCheckClicked(bool)));

        QMetaObject::connectSlotsByName(FRestaurantTotal);
    } // setupUi

    void retranslateUi(QWidget *FRestaurantTotal)
    {
        FRestaurantTotal->setWindowTitle(QCoreApplication::translate("FRestaurantTotal", "Form", nullptr));
        chOrderNum->setText(QString());
        chOrderNum->setProperty("Field", QVariant(QCoreApplication::translate("FRestaurantTotal", "oh.f_id", nullptr)));
        label_5->setText(QCoreApplication::translate("FRestaurantTotal", "Table", nullptr));
        label_14->setText(QCoreApplication::translate("FRestaurantTotal", "Order #", nullptr));
        chDishState->setText(QString());
        chDishState->setProperty("Field", QVariant(QCoreApplication::translate("FRestaurantTotal", "od.f_state;ds.f_en", nullptr)));
        label_16->setText(QCoreApplication::translate("FRestaurantTotal", "ArmSoft", nullptr));
        chArmSoft->setText(QString());
        chArmSoft->setProperty("Field", QVariant(QCoreApplication::translate("FRestaurantTotal", "d.f_as", nullptr)));
        btnOrdersSubtotal->setText(QCoreApplication::translate("FRestaurantTotal", "Subtotals", nullptr));
        label_17->setText(QCoreApplication::translate("FRestaurantTotal", "Show complex", nullptr));
        label_15->setText(QCoreApplication::translate("FRestaurantTotal", "Dish state", nullptr));
        label_10->setText(QCoreApplication::translate("FRestaurantTotal", "P/M comment", nullptr));
        chTax->setText(QString());
        chTax->setProperty("Field", QVariant(QCoreApplication::translate("FRestaurantTotal", "oh.f_tax", nullptr)));
        leTax->setProperty("Field", QVariant(QCoreApplication::translate("FRestaurantTotal", "oh.f_tax", nullptr)));
        label_4->setText(QCoreApplication::translate("FRestaurantTotal", "Hall", nullptr));
        leCL->setProperty("Field", QVariant(QCoreApplication::translate("FRestaurantTotal", "oh.f_cityLedger,cl.f_name", nullptr)));
        label_9->setText(QCoreApplication::translate("FRestaurantTotal", "Payment\n"
"mode", nullptr));
        label_11->setText(QCoreApplication::translate("FRestaurantTotal", "City\n"
"ledger", nullptr));
        label_6->setText(QCoreApplication::translate("FRestaurantTotal", "Staff", nullptr));
        chStaff->setText(QString());
        chStaff->setProperty("Field", QVariant(QCoreApplication::translate("FRestaurantTotal", "oh.f_staff;concat(u.f_firstName,' ',u.f_lastName)", nullptr)));
        chCL->setText(QString());
        chCL->setProperty("Field", QVariant(QCoreApplication::translate("FRestaurantTotal", "oh.f_cityLedger;cl.f_name", nullptr)));
        chTable->setText(QString());
        chTable->setProperty("Field", QVariant(QCoreApplication::translate("FRestaurantTotal", "oh.f_table;t.f_name", nullptr)));
        chPMComment->setText(QString());
        chPMComment->setProperty("Field", QVariant(QCoreApplication::translate("FRestaurantTotal", "oh.f_paymentModeComment", nullptr)));
        chHall->setText(QString());
        chHall->setProperty("Field", QVariant(QCoreApplication::translate("FRestaurantTotal", "oh.f_hall;h.f_name", nullptr)));
        chDishType->setText(QString());
        chDishType->setProperty("Field", QVariant(QCoreApplication::translate("FRestaurantTotal", "d.f_type;dt.f_", nullptr)));
        chPaymentMode->setText(QString());
        chPaymentMode->setProperty("Field", QVariant(QCoreApplication::translate("FRestaurantTotal", "oh.f_paymentMode;pm.f_", nullptr)));
        label_2->setText(QCoreApplication::translate("FRestaurantTotal", "Date end", nullptr));
        label_8->setText(QCoreApplication::translate("FRestaurantTotal", "Tax", nullptr));
        chStore->setText(QString());
        chStore->setProperty("Field", QVariant(QCoreApplication::translate("FRestaurantTotal", "od.f_store;s.f_name", nullptr)));
        chDish->setText(QString());
        chDish->setProperty("Field", QVariant(QCoreApplication::translate("FRestaurantTotal", "od.f_dish;d.f_", nullptr)));
        label->setText(QCoreApplication::translate("FRestaurantTotal", "Date start", nullptr));
        label_13->setText(QCoreApplication::translate("FRestaurantTotal", "Store", nullptr));
        chDate->setText(QString());
        chDate->setProperty("Field", QVariant(QCoreApplication::translate("FRestaurantTotal", "oh.f_dateCash", nullptr)));
        label_3->setText(QCoreApplication::translate("FRestaurantTotal", "Order state", nullptr));
        label_7->setText(QCoreApplication::translate("FRestaurantTotal", "Dish", nullptr));
        chState->setText(QString());
        chState->setProperty("Field", QVariant(QCoreApplication::translate("FRestaurantTotal", "oh.f_state;os.f_", nullptr)));
        chShowOpenClose->setText(QCoreApplication::translate("FRestaurantTotal", "Show open and close date", nullptr));
        chShowOpenClose->setProperty("Field", QVariant(QCoreApplication::translate("FRestaurantTotal", "oh.f_dateOpen;oh.f_dateClose;timediff(oh.f_dateclose, oh.f_dateopen)", nullptr)));
        label_12->setText(QCoreApplication::translate("FRestaurantTotal", "Dish type", nullptr));
        rbShowComplex->setText(QCoreApplication::translate("FRestaurantTotal", "Yes", nullptr));
        rbNoShowComplex->setText(QCoreApplication::translate("FRestaurantTotal", "No", nullptr));
        rbOnlycomplex->setText(QCoreApplication::translate("FRestaurantTotal", "Only complex", nullptr));
        btnPrevDate->setText(QString());
        btnNextDate->setText(QString());
        chShowOrderComment->setText(QCoreApplication::translate("FRestaurantTotal", "Order comment", nullptr));
        chShowOrderComment->setProperty("Field", QVariant(QCoreApplication::translate("FRestaurantTotal", "oh.f_comment", nullptr)));
    } // retranslateUi

};

namespace Ui {
    class FRestaurantTotal: public Ui_FRestaurantTotal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRESTAURANTTOTAL_H
