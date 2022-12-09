/********************************************************************************
** Form generated from reading UI file 'wrecheckin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WRECHECKIN_H
#define UI_WRECHECKIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WReCheckIn
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnRefresh;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tblData;

    void setupUi(QWidget *WReCheckIn)
    {
        if (WReCheckIn->objectName().isEmpty())
            WReCheckIn->setObjectName(QString::fromUtf8("WReCheckIn"));
        WReCheckIn->resize(814, 551);
        verticalLayout = new QVBoxLayout(WReCheckIn);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(WReCheckIn);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnRefresh = new QPushButton(widget);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon);

        horizontalLayout->addWidget(btnRefresh);

        horizontalSpacer = new QSpacerItem(737, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);

        tblData = new QTableWidget(WReCheckIn);
        if (tblData->columnCount() < 4)
            tblData->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tblData->setObjectName(QString::fromUtf8("tblData"));
        tblData->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblData->setSelectionMode(QAbstractItemView::NoSelection);

        verticalLayout->addWidget(tblData);


        retranslateUi(WReCheckIn);

        QMetaObject::connectSlotsByName(WReCheckIn);
    } // setupUi

    void retranslateUi(QWidget *WReCheckIn)
    {
        WReCheckIn->setWindowTitle(QCoreApplication::translate("WReCheckIn", "Form", nullptr));
        btnRefresh->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tblData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WReCheckIn", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("WReCheckIn", "Room", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("WReCheckIn", "Guest", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WReCheckIn: public Ui_WReCheckIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WRECHECKIN_H
