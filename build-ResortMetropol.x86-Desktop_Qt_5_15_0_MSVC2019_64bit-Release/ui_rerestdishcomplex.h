/********************************************************************************
** Form generated from reading UI file 'rerestdishcomplex.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RERESTDISHCOMPLEX_H
#define UI_RERESTDISHCOMPLEX_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqcheckbox.h>
#include <eqlineedit.h>
#include <eqtablewidget.h>
#include <eqtimeedit.h>

QT_BEGIN_NAMESPACE

class Ui_RERestDishComplex
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    EQLineEdit *leNameEn;
    EQLineEdit *leCode;
    EQLineEdit *leNameAm;
    EQLineEdit *lePrice;
    EQTimeEdit *teStart;
    EQTimeEdit *teEnd;
    EQLineEdit *lePriceDeviation;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    EQLineEdit *leNameRu;
    QLabel *label_5;
    EQLineEdit *leAdgt;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label_10;
    EQCheckBox *chEnabled;
    QLabel *label_11;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    EQLineEdit *leMenu;
    EQLineEdit *leMenuCode;
    EQLineEdit *leDishCode;
    EQLineEdit *leDishName;
    QPushButton *btnAdd;
    EQTableWidget *tblDishes;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_9;
    EQLineEdit *leDishesTotal;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *RERestDishComplex)
    {
        if (RERestDishComplex->objectName().isEmpty())
            RERestDishComplex->setObjectName(QString::fromUtf8("RERestDishComplex"));
        RERestDishComplex->resize(468, 369);
        verticalLayout = new QVBoxLayout(RERestDishComplex);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(RERestDishComplex);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leNameEn = new EQLineEdit(tab);
        leNameEn->setObjectName(QString::fromUtf8("leNameEn"));

        gridLayout->addWidget(leNameEn, 2, 1, 1, 1);

        leCode = new EQLineEdit(tab);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setFocusPolicy(Qt::NoFocus);
        leCode->setReadOnly(true);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        leNameAm = new EQLineEdit(tab);
        leNameAm->setObjectName(QString::fromUtf8("leNameAm"));

        gridLayout->addWidget(leNameAm, 1, 1, 1, 1);

        lePrice = new EQLineEdit(tab);
        lePrice->setObjectName(QString::fromUtf8("lePrice"));

        gridLayout->addWidget(lePrice, 6, 1, 1, 1);

        teStart = new EQTimeEdit(tab);
        teStart->setObjectName(QString::fromUtf8("teStart"));

        gridLayout->addWidget(teStart, 4, 1, 1, 1);

        teEnd = new EQTimeEdit(tab);
        teEnd->setObjectName(QString::fromUtf8("teEnd"));

        gridLayout->addWidget(teEnd, 5, 1, 1, 1);

        lePriceDeviation = new EQLineEdit(tab);
        lePriceDeviation->setObjectName(QString::fromUtf8("lePriceDeviation"));

        gridLayout->addWidget(lePriceDeviation, 8, 1, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        leNameRu = new EQLineEdit(tab);
        leNameRu->setObjectName(QString::fromUtf8("leNameRu"));

        gridLayout->addWidget(leNameRu, 3, 1, 1, 1);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        leAdgt = new EQLineEdit(tab);
        leAdgt->setObjectName(QString::fromUtf8("leAdgt"));

        gridLayout->addWidget(leAdgt, 9, 1, 1, 1);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 8, 0, 1, 1);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 9, 0, 1, 1);

        chEnabled = new EQCheckBox(tab);
        chEnabled->setObjectName(QString::fromUtf8("chEnabled"));

        gridLayout->addWidget(chEnabled, 10, 1, 1, 1);

        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 10, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_2 = new QWidget(tab_2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        leMenu = new EQLineEdit(widget_2);
        leMenu->setObjectName(QString::fromUtf8("leMenu"));
        leMenu->setMaximumSize(QSize(150, 16777215));
        leMenu->setReadOnly(true);
        leMenu->setProperty("ShowButton", QVariant(true));

        horizontalLayout_2->addWidget(leMenu);

        leMenuCode = new EQLineEdit(widget_2);
        leMenuCode->setObjectName(QString::fromUtf8("leMenuCode"));

        horizontalLayout_2->addWidget(leMenuCode);

        leDishCode = new EQLineEdit(widget_2);
        leDishCode->setObjectName(QString::fromUtf8("leDishCode"));

        horizontalLayout_2->addWidget(leDishCode);

        leDishName = new EQLineEdit(widget_2);
        leDishName->setObjectName(QString::fromUtf8("leDishName"));
        leDishName->setReadOnly(true);
        leDishName->setProperty("ShowButton", QVariant(true));

        horizontalLayout_2->addWidget(leDishName);

        btnAdd = new QPushButton(widget_2);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdd->setIcon(icon);

        horizontalLayout_2->addWidget(btnAdd);


        verticalLayout_3->addWidget(widget_2);

        tblDishes = new EQTableWidget(tab_2);
        if (tblDishes->columnCount() < 6)
            tblDishes->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblDishes->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblDishes->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblDishes->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblDishes->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblDishes->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblDishes->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tblDishes->setObjectName(QString::fromUtf8("tblDishes"));
        tblDishes->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblDishes->verticalHeader()->setDefaultSectionSize(25);

        verticalLayout_3->addWidget(tblDishes);

        widget_3 = new QWidget(tab_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(354, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label_9 = new QLabel(widget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_3->addWidget(label_9);

        leDishesTotal = new EQLineEdit(widget_3);
        leDishesTotal->setObjectName(QString::fromUtf8("leDishesTotal"));
        leDishesTotal->setMaximumSize(QSize(80, 16777215));
        leDishesTotal->setReadOnly(true);

        horizontalLayout_3->addWidget(leDishesTotal);


        verticalLayout_3->addWidget(widget_3);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        widget = new QWidget(RERestDishComplex);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(86, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOK = new QPushButton(widget);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));

        horizontalLayout->addWidget(btnOK);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(85, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        QWidget::setTabOrder(btnOK, btnCancel);

        retranslateUi(RERestDishComplex);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RERestDishComplex);
    } // setupUi

    void retranslateUi(QDialog *RERestDishComplex)
    {
        RERestDishComplex->setWindowTitle(QCoreApplication::translate("RERestDishComplex", "Complex dish", nullptr));
        leNameEn->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishComplex", "f_en", nullptr)));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishComplex", "f_id", nullptr)));
        leNameAm->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishComplex", "f_am", nullptr)));
        lePrice->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishComplex", "f_price", nullptr)));
        teStart->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishComplex", "f_startTime", nullptr)));
        teEnd->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishComplex", "f_endTime", nullptr)));
        lePriceDeviation->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishComplex", "f_priceDeviation", nullptr)));
        label_2->setText(QCoreApplication::translate("RERestDishComplex", "Name, am", nullptr));
        label_7->setText(QCoreApplication::translate("RERestDishComplex", "Name, en", nullptr));
        label->setText(QCoreApplication::translate("RERestDishComplex", "Code", nullptr));
        label_3->setText(QCoreApplication::translate("RERestDishComplex", "Start time", nullptr));
        label_4->setText(QCoreApplication::translate("RERestDishComplex", "End time", nullptr));
        leNameRu->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishComplex", "f_ru", nullptr)));
        label_5->setText(QCoreApplication::translate("RERestDishComplex", "Price", nullptr));
        leAdgt->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishComplex", "f_adgt", nullptr)));
        label_8->setText(QCoreApplication::translate("RERestDishComplex", "Name, ru", nullptr));
        label_6->setText(QCoreApplication::translate("RERestDishComplex", "Price\n"
"deviation", nullptr));
        label_10->setText(QCoreApplication::translate("RERestDishComplex", "ADGT", nullptr));
        chEnabled->setText(QString());
        chEnabled->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishComplex", "f_enabled", nullptr)));
        label_11->setText(QCoreApplication::translate("RERestDishComplex", "Enabled", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("RERestDishComplex", "Common", nullptr));
        leMenu->setPlaceholderText(QCoreApplication::translate("RERestDishComplex", "Menu", nullptr));
        leDishName->setPlaceholderText(QCoreApplication::translate("RERestDishComplex", "Dish", nullptr));
        btnAdd->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tblDishes->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("RERestDishComplex", "RecId", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblDishes->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("RERestDishComplex", "MenuId", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblDishes->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("RERestDishComplex", "Menu", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblDishes->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("RERestDishComplex", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblDishes->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("RERestDishComplex", "Price", nullptr));
        label_9->setText(QCoreApplication::translate("RERestDishComplex", "Total", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("RERestDishComplex", "List of dishes", nullptr));
        btnOK->setText(QCoreApplication::translate("RERestDishComplex", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("RERestDishComplex", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RERestDishComplex: public Ui_RERestDishComplex {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RERESTDISHCOMPLEX_H
