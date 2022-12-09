/********************************************************************************
** Form generated from reading UI file 'dlgreservequickinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGRESERVEQUICKINFO_H
#define UI_DLGRESERVEQUICKINFO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgReserveQuickInfo
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnOpenReserve;
    QPushButton *btnGroup;
    QPushButton *btnOpenInvoice;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tblData;

    void setupUi(QDialog *DlgReserveQuickInfo)
    {
        if (DlgReserveQuickInfo->objectName().isEmpty())
            DlgReserveQuickInfo->setObjectName(QString::fromUtf8("DlgReserveQuickInfo"));
        DlgReserveQuickInfo->resize(668, 354);
        verticalLayout = new QVBoxLayout(DlgReserveQuickInfo);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(DlgReserveQuickInfo);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 30));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnOpenReserve = new QPushButton(widget);
        btnOpenReserve->setObjectName(QString::fromUtf8("btnOpenReserve"));
        btnOpenReserve->setMinimumSize(QSize(30, 30));
        btnOpenReserve->setMaximumSize(QSize(2222, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/checkin.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnOpenReserve->setIcon(icon);
        btnOpenReserve->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(btnOpenReserve);

        btnGroup = new QPushButton(widget);
        btnGroup->setObjectName(QString::fromUtf8("btnGroup"));
        btnGroup->setMaximumSize(QSize(222, 222));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/groupreservation.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGroup->setIcon(icon1);

        horizontalLayout->addWidget(btnGroup);

        btnOpenInvoice = new QPushButton(widget);
        btnOpenInvoice->setObjectName(QString::fromUtf8("btnOpenInvoice"));
        btnOpenInvoice->setMinimumSize(QSize(30, 30));
        btnOpenInvoice->setMaximumSize(QSize(22222, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/invoice.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnOpenInvoice->setIcon(icon2);
        btnOpenInvoice->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(btnOpenInvoice);

        horizontalSpacer = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);

        tblData = new QTableWidget(DlgReserveQuickInfo);
        if (tblData->columnCount() < 2)
            tblData->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tblData->setObjectName(QString::fromUtf8("tblData"));
        tblData->setMinimumSize(QSize(650, 300));
        tblData->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblData->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblData->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblData->setSelectionMode(QAbstractItemView::NoSelection);
        tblData->horizontalHeader()->setVisible(false);
        tblData->horizontalHeader()->setHighlightSections(false);
        tblData->verticalHeader()->setVisible(false);
        tblData->verticalHeader()->setHighlightSections(true);

        verticalLayout->addWidget(tblData);


        retranslateUi(DlgReserveQuickInfo);

        QMetaObject::connectSlotsByName(DlgReserveQuickInfo);
    } // setupUi

    void retranslateUi(QDialog *DlgReserveQuickInfo)
    {
        DlgReserveQuickInfo->setWindowTitle(QCoreApplication::translate("DlgReserveQuickInfo", "Quick info", nullptr));
#if QT_CONFIG(tooltip)
        btnOpenReserve->setToolTip(QCoreApplication::translate("DlgReserveQuickInfo", "Open reservation", nullptr));
#endif // QT_CONFIG(tooltip)
        btnOpenReserve->setText(QCoreApplication::translate("DlgReserveQuickInfo", "Reservation", nullptr));
        btnGroup->setText(QCoreApplication::translate("DlgReserveQuickInfo", "Group", nullptr));
#if QT_CONFIG(tooltip)
        btnOpenInvoice->setToolTip(QCoreApplication::translate("DlgReserveQuickInfo", "Open invoice", nullptr));
#endif // QT_CONFIG(tooltip)
        btnOpenInvoice->setText(QCoreApplication::translate("DlgReserveQuickInfo", "Invoice", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgReserveQuickInfo", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgReserveQuickInfo", "New Column", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgReserveQuickInfo: public Ui_DlgReserveQuickInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGRESERVEQUICKINFO_H
