/********************************************************************************
** Form generated from reading UI file 'dlgquickadvanceaction.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGQUICKADVANCEACTION_H
#define UI_DLGQUICKADVANCEACTION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edoubleedit.h>
#include <eqlineedit.h>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgQuickAdvanceAction
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    EQLineEdit *leItemCode;
    QLabel *label_2;
    EQLineEdit *leItemName;
    QLabel *label_7;
    EQLineEdit *leAdg;
    QLabel *label_3;
    EQLineEdit *leDep;
    QLabel *label_4;
    EDoubleEdit *leQty;
    QLabel *label_5;
    EDoubleEdit *lePrice;
    QLabel *label_6;
    EDoubleEdit *leTotal;
    QToolButton *btnPlus;
    EQTableWidget *tbl;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    EDoubleEdit *leGrandTotal;
    QLabel *label_9;
    EDoubleEdit *leGrandCash;
    QLabel *label_10;
    EDoubleEdit *leGrandCard;
    QSpacerItem *horizontalSpacer_3;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_13;
    EDoubleEdit *leaCash;
    QLabel *label_14;
    EDoubleEdit *leaCard;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QPlainTextEdit *ptComment;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_11;
    EQLineEdit *leTaxNumber;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPrint;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgQuickAdvanceAction)
    {
        if (DlgQuickAdvanceAction->objectName().isEmpty())
            DlgQuickAdvanceAction->setObjectName(QString::fromUtf8("DlgQuickAdvanceAction"));
        DlgQuickAdvanceAction->resize(978, 561);
        verticalLayout = new QVBoxLayout(DlgQuickAdvanceAction);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(DlgQuickAdvanceAction);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setFocusPolicy(Qt::NoFocus);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_2 = new QWidget(tab);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        leItemCode = new EQLineEdit(widget_2);
        leItemCode->setObjectName(QString::fromUtf8("leItemCode"));
        leItemCode->setMaximumSize(QSize(50, 16777215));
        leItemCode->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_2->addWidget(leItemCode);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        leItemName = new EQLineEdit(widget_2);
        leItemName->setObjectName(QString::fromUtf8("leItemName"));
        leItemName->setFocusPolicy(Qt::NoFocus);
        leItemName->setReadOnly(true);

        horizontalLayout_2->addWidget(leItemName);

        label_7 = new QLabel(widget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_2->addWidget(label_7);

        leAdg = new EQLineEdit(widget_2);
        leAdg->setObjectName(QString::fromUtf8("leAdg"));
        leAdg->setMaximumSize(QSize(50, 16777215));
        leAdg->setFocusPolicy(Qt::NoFocus);
        leAdg->setReadOnly(true);

        horizontalLayout_2->addWidget(leAdg);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        leDep = new EQLineEdit(widget_2);
        leDep->setObjectName(QString::fromUtf8("leDep"));
        leDep->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_2->addWidget(leDep);

        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        leQty = new EDoubleEdit(widget_2);
        leQty->setObjectName(QString::fromUtf8("leQty"));
        leQty->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_2->addWidget(leQty);

        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lePrice = new EDoubleEdit(widget_2);
        lePrice->setObjectName(QString::fromUtf8("lePrice"));
        lePrice->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(lePrice);

        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        leTotal = new EDoubleEdit(widget_2);
        leTotal->setObjectName(QString::fromUtf8("leTotal"));
        leTotal->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(leTotal);

        btnPlus = new QToolButton(widget_2);
        btnPlus->setObjectName(QString::fromUtf8("btnPlus"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPlus->setIcon(icon);

        horizontalLayout_2->addWidget(btnPlus);


        verticalLayout_2->addWidget(widget_2);

        tbl = new EQTableWidget(tab);
        if (tbl->columnCount() < 8)
            tbl->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tbl->setObjectName(QString::fromUtf8("tbl"));
        tbl->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(tbl);

        widget_3 = new QWidget(tab);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_8 = new QLabel(widget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_3->addWidget(label_8);

        leGrandTotal = new EDoubleEdit(widget_3);
        leGrandTotal->setObjectName(QString::fromUtf8("leGrandTotal"));
        leGrandTotal->setMaximumSize(QSize(100, 16777215));
        leGrandTotal->setFocusPolicy(Qt::NoFocus);
        leGrandTotal->setReadOnly(true);

        horizontalLayout_3->addWidget(leGrandTotal);

        label_9 = new QLabel(widget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_3->addWidget(label_9);

        leGrandCash = new EDoubleEdit(widget_3);
        leGrandCash->setObjectName(QString::fromUtf8("leGrandCash"));
        leGrandCash->setMaximumSize(QSize(100, 16777215));
        leGrandCash->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_3->addWidget(leGrandCash);

        label_10 = new QLabel(widget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_3->addWidget(label_10);

        leGrandCard = new EDoubleEdit(widget_3);
        leGrandCard->setObjectName(QString::fromUtf8("leGrandCard"));
        leGrandCard->setMaximumSize(QSize(100, 16777215));
        leGrandCard->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_3->addWidget(leGrandCard);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_2->addWidget(widget_3);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_4 = new QWidget(tab_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_13 = new QLabel(widget_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_4->addWidget(label_13);

        leaCash = new EDoubleEdit(widget_4);
        leaCash->setObjectName(QString::fromUtf8("leaCash"));
        leaCash->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(leaCash);

        label_14 = new QLabel(widget_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_4->addWidget(label_14);

        leaCard = new EDoubleEdit(widget_4);
        leaCard->setObjectName(QString::fromUtf8("leaCard"));
        leaCard->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(leaCard);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_3->addWidget(widget_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        ptComment = new QPlainTextEdit(DlgQuickAdvanceAction);
        ptComment->setObjectName(QString::fromUtf8("ptComment"));
        ptComment->setMaximumSize(QSize(16777215, 50));
        ptComment->setFocusPolicy(Qt::ClickFocus);

        verticalLayout->addWidget(ptComment);

        widget = new QWidget(DlgQuickAdvanceAction);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_11 = new QLabel(widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout->addWidget(label_11);

        leTaxNumber = new EQLineEdit(widget);
        leTaxNumber->setObjectName(QString::fromUtf8("leTaxNumber"));
        leTaxNumber->setMaximumSize(QSize(100, 16777215));
        leTaxNumber->setFocusPolicy(Qt::NoFocus);
        leTaxNumber->setReadOnly(true);

        horizontalLayout->addWidget(leTaxNumber);

        horizontalSpacer = new QSpacerItem(340, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnPrint = new QPushButton(widget);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));
        btnPrint->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(btnPrint);

        horizontalSpacer_2 = new QSpacerItem(340, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        QWidget::setTabOrder(leItemCode, leDep);
        QWidget::setTabOrder(leDep, leQty);
        QWidget::setTabOrder(leQty, lePrice);
        QWidget::setTabOrder(lePrice, leTotal);
        QWidget::setTabOrder(leTotal, btnPlus);
        QWidget::setTabOrder(btnPlus, leGrandTotal);
        QWidget::setTabOrder(leGrandTotal, leGrandCash);
        QWidget::setTabOrder(leGrandCash, leGrandCard);
        QWidget::setTabOrder(leGrandCard, leTaxNumber);
        QWidget::setTabOrder(leTaxNumber, leaCash);
        QWidget::setTabOrder(leaCash, leaCard);

        retranslateUi(DlgQuickAdvanceAction);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DlgQuickAdvanceAction);
    } // setupUi

    void retranslateUi(QDialog *DlgQuickAdvanceAction)
    {
        DlgQuickAdvanceAction->setWindowTitle(QCoreApplication::translate("DlgQuickAdvanceAction", "Temporary tax", nullptr));
        label->setText(QCoreApplication::translate("DlgQuickAdvanceAction", "Item code", nullptr));
        label_2->setText(QCoreApplication::translate("DlgQuickAdvanceAction", "Item name", nullptr));
        label_7->setText(QCoreApplication::translate("DlgQuickAdvanceAction", "Adg", nullptr));
        label_3->setText(QCoreApplication::translate("DlgQuickAdvanceAction", "Dept", nullptr));
        label_4->setText(QCoreApplication::translate("DlgQuickAdvanceAction", "Qty", nullptr));
        label_5->setText(QCoreApplication::translate("DlgQuickAdvanceAction", "Price", nullptr));
        label_6->setText(QCoreApplication::translate("DlgQuickAdvanceAction", "Total", nullptr));
        btnPlus->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tbl->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgQuickAdvanceAction", "Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tbl->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgQuickAdvanceAction", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tbl->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgQuickAdvanceAction", "Adg", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tbl->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgQuickAdvanceAction", "Dept", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tbl->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DlgQuickAdvanceAction", "Qty", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tbl->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("DlgQuickAdvanceAction", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tbl->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("DlgQuickAdvanceAction", "Total", nullptr));
        label_8->setText(QCoreApplication::translate("DlgQuickAdvanceAction", "Grand total", nullptr));
        label_9->setText(QCoreApplication::translate("DlgQuickAdvanceAction", "Cash", nullptr));
        label_10->setText(QCoreApplication::translate("DlgQuickAdvanceAction", "Card", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("DlgQuickAdvanceAction", "Receipt", nullptr));
        label_13->setText(QCoreApplication::translate("DlgQuickAdvanceAction", "Cash", nullptr));
        label_14->setText(QCoreApplication::translate("DlgQuickAdvanceAction", "Card", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("DlgQuickAdvanceAction", "Advance", nullptr));
        ptComment->setPlaceholderText(QCoreApplication::translate("DlgQuickAdvanceAction", "Remarks", nullptr));
        label_11->setText(QCoreApplication::translate("DlgQuickAdvanceAction", "Tax number", nullptr));
        btnPrint->setText(QCoreApplication::translate("DlgQuickAdvanceAction", "Print", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgQuickAdvanceAction: public Ui_DlgQuickAdvanceAction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGQUICKADVANCEACTION_H
