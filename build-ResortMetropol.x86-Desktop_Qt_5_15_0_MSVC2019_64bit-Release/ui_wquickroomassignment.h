/********************************************************************************
** Form generated from reading UI file 'wquickroomassignment.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WQUICKROOMASSIGNMENT_H
#define UI_WQUICKROOMASSIGNMENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_WQuickRoomAssignment
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EDateEdit *deStart;
    QLabel *label_2;
    EDateEdit *deEnd;
    QRadioButton *rbEntry;
    QRadioButton *rbDeparture;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnRefresh;
    QPushButton *btnSave;
    EQTableWidget *tbl;

    void setupUi(QWidget *WQuickRoomAssignment)
    {
        if (WQuickRoomAssignment->objectName().isEmpty())
            WQuickRoomAssignment->setObjectName(QString::fromUtf8("WQuickRoomAssignment"));
        WQuickRoomAssignment->resize(807, 461);
        verticalLayout = new QVBoxLayout(WQuickRoomAssignment);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(WQuickRoomAssignment);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(9, 9, 9, 9);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        deStart = new EDateEdit(groupBox);
        deStart->setObjectName(QString::fromUtf8("deStart"));
        deStart->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(deStart);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        deEnd = new EDateEdit(groupBox);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));
        deEnd->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(deEnd);

        rbEntry = new QRadioButton(groupBox);
        rbEntry->setObjectName(QString::fromUtf8("rbEntry"));
        rbEntry->setChecked(true);

        horizontalLayout->addWidget(rbEntry);

        rbDeparture = new QRadioButton(groupBox);
        rbDeparture->setObjectName(QString::fromUtf8("rbDeparture"));

        horizontalLayout->addWidget(rbDeparture);

        horizontalSpacer = new QSpacerItem(169, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnRefresh = new QPushButton(groupBox);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnRefresh->sizePolicy().hasHeightForWidth());
        btnRefresh->setSizePolicy(sizePolicy);
        btnRefresh->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon);

        horizontalLayout->addWidget(btnRefresh);

        btnSave = new QPushButton(groupBox);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        sizePolicy.setHeightForWidth(btnSave->sizePolicy().hasHeightForWidth());
        btnSave->setSizePolicy(sizePolicy);
        btnSave->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSave->setIcon(icon1);

        horizontalLayout->addWidget(btnSave);


        verticalLayout->addWidget(groupBox);

        tbl = new EQTableWidget(WQuickRoomAssignment);
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
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(tbl->sizePolicy().hasHeightForWidth());
        tbl->setSizePolicy(sizePolicy1);
        tbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbl->setSelectionMode(QAbstractItemView::NoSelection);

        verticalLayout->addWidget(tbl);


        retranslateUi(WQuickRoomAssignment);

        QMetaObject::connectSlotsByName(WQuickRoomAssignment);
    } // setupUi

    void retranslateUi(QWidget *WQuickRoomAssignment)
    {
        WQuickRoomAssignment->setWindowTitle(QCoreApplication::translate("WQuickRoomAssignment", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("WQuickRoomAssignment", "Search reservation", nullptr));
        label->setText(QCoreApplication::translate("WQuickRoomAssignment", "Start from", nullptr));
        label_2->setText(QCoreApplication::translate("WQuickRoomAssignment", "End", nullptr));
        rbEntry->setText(QCoreApplication::translate("WQuickRoomAssignment", "Search by entry", nullptr));
        rbDeparture->setText(QCoreApplication::translate("WQuickRoomAssignment", "Search by departure", nullptr));
        btnRefresh->setText(QString());
        btnSave->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tbl->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WQuickRoomAssignment", "Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tbl->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("WQuickRoomAssignment", "Room", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tbl->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("WQuickRoomAssignment", "Entry", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tbl->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("WQuickRoomAssignment", "Departure", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tbl->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("WQuickRoomAssignment", "Guest", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tbl->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("WQuickRoomAssignment", "Conflict", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tbl->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("WQuickRoomAssignment", "Invoice", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tbl->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("WQuickRoomAssignment", "Rooms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WQuickRoomAssignment: public Ui_WQuickRoomAssignment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WQUICKROOMASSIGNMENT_H
