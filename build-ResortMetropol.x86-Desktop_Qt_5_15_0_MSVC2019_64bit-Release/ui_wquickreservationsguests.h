/********************************************************************************
** Form generated from reading UI file 'wquickreservationsguests.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WQUICKRESERVATIONSGUESTS_H
#define UI_WQUICKRESERVATIONSGUESTS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
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

class Ui_WQuickReservationsGuests
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lbRoom;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAddGuest;
    QPushButton *btnRemoveGuest;
    QPushButton *btnFullInfo;
    QPushButton *btnChangeGuest;
    QSpacerItem *horizontalSpacer;
    QCheckBox *chSameNations;
    EQTableWidget *tbl;

    void setupUi(QDialog *WQuickReservationsGuests)
    {
        if (WQuickReservationsGuests->objectName().isEmpty())
            WQuickReservationsGuests->setObjectName(QString::fromUtf8("WQuickReservationsGuests"));
        WQuickReservationsGuests->resize(962, 358);
        verticalLayout = new QVBoxLayout(WQuickReservationsGuests);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lbRoom = new QLabel(WQuickReservationsGuests);
        lbRoom->setObjectName(QString::fromUtf8("lbRoom"));
        lbRoom->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lbRoom);

        widget = new QWidget(WQuickReservationsGuests);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 30));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnAddGuest = new QPushButton(widget);
        btnAddGuest->setObjectName(QString::fromUtf8("btnAddGuest"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddGuest->setIcon(icon);

        horizontalLayout->addWidget(btnAddGuest);

        btnRemoveGuest = new QPushButton(widget);
        btnRemoveGuest->setObjectName(QString::fromUtf8("btnRemoveGuest"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRemoveGuest->setIcon(icon1);

        horizontalLayout->addWidget(btnRemoveGuest);

        btnFullInfo = new QPushButton(widget);
        btnFullInfo->setObjectName(QString::fromUtf8("btnFullInfo"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnFullInfo->setIcon(icon2);

        horizontalLayout->addWidget(btnFullInfo);

        btnChangeGuest = new QPushButton(widget);
        btnChangeGuest->setObjectName(QString::fromUtf8("btnChangeGuest"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/change.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnChangeGuest->setIcon(icon3);

        horizontalLayout->addWidget(btnChangeGuest);

        horizontalSpacer = new QSpacerItem(444, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        chSameNations = new QCheckBox(widget);
        chSameNations->setObjectName(QString::fromUtf8("chSameNations"));
        chSameNations->setChecked(true);

        horizontalLayout->addWidget(chSameNations);


        verticalLayout->addWidget(widget);

        tbl = new EQTableWidget(WQuickReservationsGuests);
        if (tbl->columnCount() < 6)
            tbl->setColumnCount(6);
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
        tbl->setObjectName(QString::fromUtf8("tbl"));
        tbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbl->setSelectionMode(QAbstractItemView::NoSelection);
        tbl->setWordWrap(false);

        verticalLayout->addWidget(tbl);


        retranslateUi(WQuickReservationsGuests);

        QMetaObject::connectSlotsByName(WQuickReservationsGuests);
    } // setupUi

    void retranslateUi(QDialog *WQuickReservationsGuests)
    {
        WQuickReservationsGuests->setWindowTitle(QCoreApplication::translate("WQuickReservationsGuests", "Guest", nullptr));
        lbRoom->setText(QCoreApplication::translate("WQuickReservationsGuests", "ROOM", nullptr));
        btnAddGuest->setText(QCoreApplication::translate("WQuickReservationsGuests", "Append guest", nullptr));
        btnRemoveGuest->setText(QCoreApplication::translate("WQuickReservationsGuests", "Remove guest", nullptr));
        btnFullInfo->setText(QCoreApplication::translate("WQuickReservationsGuests", "Full info", nullptr));
        btnChangeGuest->setText(QCoreApplication::translate("WQuickReservationsGuests", "Change guest", nullptr));
        chSameNations->setText(QCoreApplication::translate("WQuickReservationsGuests", "Same nations", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tbl->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WQuickReservationsGuests", "Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tbl->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("WQuickReservationsGuests", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tbl->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("WQuickReservationsGuests", "First name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tbl->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("WQuickReservationsGuests", "Last name", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tbl->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("WQuickReservationsGuests", "Nation", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tbl->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("WQuickReservationsGuests", "Nation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WQuickReservationsGuests: public Ui_WQuickReservationsGuests {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WQUICKRESERVATIONSGUESTS_H
