/********************************************************************************
** Form generated from reading UI file 'dlgendofday.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGENDOFDAY_H
#define UI_DLGENDOFDAY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgEndOfDay
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *lbLastDate;
    QSpacerItem *horizontalSpacer;
    QLabel *lbCurrentDate;
    EQTableWidget *tblCharges;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbSemaphore;
    QPushButton *btnRefresh;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *DlgEndOfDay)
    {
        if (DlgEndOfDay->objectName().isEmpty())
            DlgEndOfDay->setObjectName(QString::fromUtf8("DlgEndOfDay"));
        DlgEndOfDay->resize(984, 573);
        verticalLayout = new QVBoxLayout(DlgEndOfDay);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(DlgEndOfDay);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lbLastDate = new QLabel(widget);
        lbLastDate->setObjectName(QString::fromUtf8("lbLastDate"));

        horizontalLayout->addWidget(lbLastDate);

        horizontalSpacer = new QSpacerItem(458, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lbCurrentDate = new QLabel(widget);
        lbCurrentDate->setObjectName(QString::fromUtf8("lbCurrentDate"));

        horizontalLayout->addWidget(lbCurrentDate);


        verticalLayout->addWidget(widget);

        tblCharges = new EQTableWidget(DlgEndOfDay);
        if (tblCharges->columnCount() < 13)
            tblCharges->setColumnCount(13);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblCharges->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblCharges->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblCharges->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblCharges->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblCharges->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblCharges->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblCharges->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblCharges->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblCharges->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tblCharges->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblCharges->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tblCharges->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tblCharges->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        tblCharges->setObjectName(QString::fromUtf8("tblCharges"));
        tblCharges->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblCharges->setSelectionMode(QAbstractItemView::NoSelection);
        tblCharges->setWordWrap(false);

        verticalLayout->addWidget(tblCharges);

        widget_2 = new QWidget(DlgEndOfDay);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lbSemaphore = new QLabel(widget_2);
        lbSemaphore->setObjectName(QString::fromUtf8("lbSemaphore"));
        lbSemaphore->setPixmap(QPixmap(QString::fromUtf8(":/images/ball-green.png")));
        lbSemaphore->setScaledContents(true);

        horizontalLayout_2->addWidget(lbSemaphore);

        btnRefresh = new QPushButton(widget_2);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon);

        horizontalLayout_2->addWidget(btnRefresh);

        horizontalSpacer_2 = new QSpacerItem(239, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btnOk = new QPushButton(widget_2);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout_2->addWidget(btnOk);

        btnCancel = new QPushButton(widget_2);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_2->addWidget(btnCancel);

        horizontalSpacer_3 = new QSpacerItem(239, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget_2);


        retranslateUi(DlgEndOfDay);

        QMetaObject::connectSlotsByName(DlgEndOfDay);
    } // setupUi

    void retranslateUi(QDialog *DlgEndOfDay)
    {
        DlgEndOfDay->setWindowTitle(QCoreApplication::translate("DlgEndOfDay", "Automatic room charge", nullptr));
        lbLastDate->setText(QCoreApplication::translate("DlgEndOfDay", "Last charge date", nullptr));
        lbCurrentDate->setText(QCoreApplication::translate("DlgEndOfDay", "Current charge date", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblCharges->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgEndOfDay", "Invoice", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblCharges->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgEndOfDay", "Vat mode", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblCharges->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgEndOfDay", "Reservation id", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblCharges->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgEndOfDay", "Room", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblCharges->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DlgEndOfDay", "Guest", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblCharges->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("DlgEndOfDay", "Guests", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblCharges->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("DlgEndOfDay", "Arrival", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblCharges->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("DlgEndOfDay", "Departure", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblCharges->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("DlgEndOfDay", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblCharges->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("DlgEndOfDay", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblCharges->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("DlgEndOfDay", "Action", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblCharges->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("DlgEndOfDay", "Arrangement", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblCharges->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("DlgEndOfDay", "Cityledger", nullptr));
        lbSemaphore->setText(QString());
        btnRefresh->setText(QString());
        btnOk->setText(QCoreApplication::translate("DlgEndOfDay", "Proceed", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgEndOfDay", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgEndOfDay: public Ui_DlgEndOfDay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGENDOFDAY_H
