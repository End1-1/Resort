/********************************************************************************
** Form generated from reading UI file 'reroomcategoryrate.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REROOMCATEGORYRATE_H
#define UI_REROOMCATEGORYRATE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_RERoomCategoryRate
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EQLineEdit *leCategory;
    EQLineEdit *leCategoryName;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnAddRate;
    QPushButton *btnEditRate;
    QPushButton *btnRemoveRate;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tblData;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *RERoomCategoryRate)
    {
        if (RERoomCategoryRate->objectName().isEmpty())
            RERoomCategoryRate->setObjectName(QString::fromUtf8("RERoomCategoryRate"));
        RERoomCategoryRate->resize(640, 470);
        verticalLayout = new QVBoxLayout(RERoomCategoryRate);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(RERoomCategoryRate);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        leCategory = new EQLineEdit(widget_2);
        leCategory->setObjectName(QString::fromUtf8("leCategory"));
        leCategory->setMaximumSize(QSize(60, 16777215));
        leCategory->setReadOnly(true);

        horizontalLayout->addWidget(leCategory);

        leCategoryName = new EQLineEdit(widget_2);
        leCategoryName->setObjectName(QString::fromUtf8("leCategoryName"));
        leCategoryName->setReadOnly(true);

        horizontalLayout->addWidget(leCategoryName);

        horizontalSpacer = new QSpacerItem(177, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(RERoomCategoryRate);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnAddRate = new QPushButton(widget);
        btnAddRate->setObjectName(QString::fromUtf8("btnAddRate"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddRate->setIcon(icon);

        horizontalLayout_2->addWidget(btnAddRate);

        btnEditRate = new QPushButton(widget);
        btnEditRate->setObjectName(QString::fromUtf8("btnEditRate"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnEditRate->setIcon(icon1);

        horizontalLayout_2->addWidget(btnEditRate);

        btnRemoveRate = new QPushButton(widget);
        btnRemoveRate->setObjectName(QString::fromUtf8("btnRemoveRate"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/garbage.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRemoveRate->setIcon(icon2);

        horizontalLayout_2->addWidget(btnRemoveRate);

        horizontalSpacer_2 = new QSpacerItem(482, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        tblData = new QTableWidget(RERoomCategoryRate);
        if (tblData->columnCount() < 8)
            tblData->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tblData->setObjectName(QString::fromUtf8("tblData"));
        tblData->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblData->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblData->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblData->setSelectionMode(QAbstractItemView::SingleSelection);
        tblData->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblData->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tblData);

        widget_3 = new QWidget(RERoomCategoryRate);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(215, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        btnOk = new QPushButton(widget_3);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout_3->addWidget(btnOk);

        btnCancel = new QPushButton(widget_3);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_3->addWidget(btnCancel);

        horizontalSpacer_4 = new QSpacerItem(215, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_3);


        retranslateUi(RERoomCategoryRate);

        QMetaObject::connectSlotsByName(RERoomCategoryRate);
    } // setupUi

    void retranslateUi(QDialog *RERoomCategoryRate)
    {
        RERoomCategoryRate->setWindowTitle(QCoreApplication::translate("RERoomCategoryRate", "Category Rates", nullptr));
        label->setText(QCoreApplication::translate("RERoomCategoryRate", "Category", nullptr));
        btnAddRate->setText(QString());
        btnEditRate->setText(QString());
        btnRemoveRate->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tblData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("RERoomCategoryRate", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("RERoomCategoryRate", "Month", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("RERoomCategoryRate", "Day", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("RERoomCategoryRate", "Month", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblData->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("RERoomCategoryRate", "Day", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblData->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("RERoomCategoryRate", "Bed", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblData->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("RERoomCategoryRate", "Bed", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblData->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("RERoomCategoryRate", "Rate", nullptr));
        btnOk->setText(QCoreApplication::translate("RERoomCategoryRate", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("RERoomCategoryRate", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RERoomCategoryRate: public Ui_RERoomCategoryRate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REROOMCATEGORYRATE_H
