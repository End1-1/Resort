/********************************************************************************
** Form generated from reading UI file 'dlgquickadvance.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGQUICKADVANCE_H
#define UI_DLGQUICKADVANCE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>
#include <eqtablewidget.h>
#include <wdate2.h>

QT_BEGIN_NAMESPACE

class Ui_DlgQuickAdvance
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    WDate2 *wDate;
    QToolButton *btnRefresh;
    QPushButton *btnNew;
    QSpacerItem *horizontalSpacer;
    EQTableWidget *tbl;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    EQLineEdit *leTotalCash;
    QLabel *label_5;
    EQLineEdit *leTotalCard;
    QLabel *label_7;
    EQLineEdit *leGrandTotal;

    void setupUi(QWidget *DlgQuickAdvance)
    {
        if (DlgQuickAdvance->objectName().isEmpty())
            DlgQuickAdvance->setObjectName(QString::fromUtf8("DlgQuickAdvance"));
        DlgQuickAdvance->resize(1131, 566);
        DlgQuickAdvance->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(DlgQuickAdvance);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(DlgQuickAdvance);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        wDate = new WDate2(widget);
        wDate->setObjectName(QString::fromUtf8("wDate"));

        horizontalLayout->addWidget(wDate);

        btnRefresh = new QToolButton(widget);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/goto.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon);

        horizontalLayout->addWidget(btnRefresh);

        btnNew = new QPushButton(widget);
        btnNew->setObjectName(QString::fromUtf8("btnNew"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNew->setIcon(icon1);

        horizontalLayout->addWidget(btnNew);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);

        tbl = new EQTableWidget(DlgQuickAdvance);
        if (tbl->columnCount() < 10)
            tbl->setColumnCount(10);
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
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        tbl->setObjectName(QString::fromUtf8("tbl"));
        tbl->setFocusPolicy(Qt::ClickFocus);
        tbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbl->setSelectionMode(QAbstractItemView::SingleSelection);
        tbl->setSelectionBehavior(QAbstractItemView::SelectRows);
        tbl->setWordWrap(false);

        verticalLayout->addWidget(tbl);

        widget_2 = new QWidget(DlgQuickAdvance);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 20));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(605, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        leTotalCash = new EQLineEdit(widget_2);
        leTotalCash->setObjectName(QString::fromUtf8("leTotalCash"));
        leTotalCash->setMaximumSize(QSize(100, 16777215));
        leTotalCash->setFocusPolicy(Qt::ClickFocus);
        leTotalCash->setReadOnly(true);

        horizontalLayout_2->addWidget(leTotalCash);

        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        leTotalCard = new EQLineEdit(widget_2);
        leTotalCard->setObjectName(QString::fromUtf8("leTotalCard"));
        leTotalCard->setMaximumSize(QSize(100, 16777215));
        leTotalCard->setFocusPolicy(Qt::ClickFocus);
        leTotalCard->setReadOnly(true);

        horizontalLayout_2->addWidget(leTotalCard);

        label_7 = new QLabel(widget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_2->addWidget(label_7);

        leGrandTotal = new EQLineEdit(widget_2);
        leGrandTotal->setObjectName(QString::fromUtf8("leGrandTotal"));
        leGrandTotal->setMaximumSize(QSize(100, 16777215));
        leGrandTotal->setFocusPolicy(Qt::ClickFocus);
        leGrandTotal->setReadOnly(true);

        horizontalLayout_2->addWidget(leGrandTotal);


        verticalLayout->addWidget(widget_2);


        retranslateUi(DlgQuickAdvance);

        QMetaObject::connectSlotsByName(DlgQuickAdvance);
    } // setupUi

    void retranslateUi(QWidget *DlgQuickAdvance)
    {
        DlgQuickAdvance->setWindowTitle(QCoreApplication::translate("DlgQuickAdvance", "Quick advance", nullptr));
        btnRefresh->setText(QString());
        btnNew->setText(QCoreApplication::translate("DlgQuickAdvance", "New", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tbl->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgQuickAdvance", "Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tbl->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgQuickAdvance", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tbl->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgQuickAdvance", "Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tbl->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgQuickAdvance", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tbl->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DlgQuickAdvance", "Operator", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tbl->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("DlgQuickAdvance", "Amount cash", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tbl->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("DlgQuickAdvance", "Amount card", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tbl->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("DlgQuickAdvance", "Tax", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tbl->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("DlgQuickAdvance", "Json", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tbl->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("DlgQuickAdvance", "Remarks", nullptr));
        label_2->setText(QCoreApplication::translate("DlgQuickAdvance", "Total cash", nullptr));
        label_5->setText(QCoreApplication::translate("DlgQuickAdvance", "Total card", nullptr));
        label_7->setText(QCoreApplication::translate("DlgQuickAdvance", "Grand total", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgQuickAdvance: public Ui_DlgQuickAdvance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGQUICKADVANCE_H
