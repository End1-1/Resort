/********************************************************************************
** Form generated from reading UI file 'dlghouseitem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGHOUSEITEM_H
#define UI_DLGHOUSEITEM_H

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
#include <eqlineedit.h>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgHouseItem
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    EQLineEdit *leRoomCode;
    EQLineEdit *leRoomName;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAddItem;
    QPushButton *btnRemoveItem;
    QPushButton *btnCopy;
    QPushButton *btnPaste;
    QPushButton *btnSave;
    QPushButton *btnDontDisturbe;
    QSpacerItem *horizontalSpacer;
    QLabel *lbStatus;
    QPushButton *btnSaveStates;
    EQTableWidget *tblMain;

    void setupUi(QDialog *DlgHouseItem)
    {
        if (DlgHouseItem->objectName().isEmpty())
            DlgHouseItem->setObjectName(QString::fromUtf8("DlgHouseItem"));
        DlgHouseItem->resize(980, 600);
        verticalLayout = new QVBoxLayout(DlgHouseItem);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(9, 9, 9, 9);
        widget_2 = new QWidget(DlgHouseItem);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        leRoomCode = new EQLineEdit(widget_2);
        leRoomCode->setObjectName(QString::fromUtf8("leRoomCode"));
        leRoomCode->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(leRoomCode);

        leRoomName = new EQLineEdit(widget_2);
        leRoomName->setObjectName(QString::fromUtf8("leRoomName"));
        leRoomName->setEnabled(false);

        horizontalLayout_2->addWidget(leRoomName);

        horizontalSpacer_2 = new QSpacerItem(304, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(DlgHouseItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnAddItem = new QPushButton(widget);
        btnAddItem->setObjectName(QString::fromUtf8("btnAddItem"));
        btnAddItem->setMinimumSize(QSize(30, 30));
        btnAddItem->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddItem->setIcon(icon);

        horizontalLayout->addWidget(btnAddItem);

        btnRemoveItem = new QPushButton(widget);
        btnRemoveItem->setObjectName(QString::fromUtf8("btnRemoveItem"));
        btnRemoveItem->setMinimumSize(QSize(30, 30));
        btnRemoveItem->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/garbage.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRemoveItem->setIcon(icon1);

        horizontalLayout->addWidget(btnRemoveItem);

        btnCopy = new QPushButton(widget);
        btnCopy->setObjectName(QString::fromUtf8("btnCopy"));
        btnCopy->setMinimumSize(QSize(30, 30));
        btnCopy->setMaximumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCopy->setIcon(icon2);

        horizontalLayout->addWidget(btnCopy);

        btnPaste = new QPushButton(widget);
        btnPaste->setObjectName(QString::fromUtf8("btnPaste"));
        btnPaste->setMinimumSize(QSize(30, 30));
        btnPaste->setMaximumSize(QSize(30, 30));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPaste->setIcon(icon3);

        horizontalLayout->addWidget(btnPaste);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setMinimumSize(QSize(30, 30));
        btnSave->setMaximumSize(QSize(30, 30));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSave->setIcon(icon4);

        horizontalLayout->addWidget(btnSave);

        btnDontDisturbe = new QPushButton(widget);
        btnDontDisturbe->setObjectName(QString::fromUtf8("btnDontDisturbe"));
        btnDontDisturbe->setMinimumSize(QSize(30, 30));
        btnDontDisturbe->setMaximumSize(QSize(30, 30));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/do-not-disturbe.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDontDisturbe->setIcon(icon5);
        btnDontDisturbe->setCheckable(true);

        horizontalLayout->addWidget(btnDontDisturbe);

        horizontalSpacer = new QSpacerItem(598, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lbStatus = new QLabel(widget);
        lbStatus->setObjectName(QString::fromUtf8("lbStatus"));
        lbStatus->setPixmap(QPixmap(QString::fromUtf8(":/images/ball-green.png")));

        horizontalLayout->addWidget(lbStatus);

        btnSaveStates = new QPushButton(widget);
        btnSaveStates->setObjectName(QString::fromUtf8("btnSaveStates"));
        btnSaveStates->setMinimumSize(QSize(30, 30));
        btnSaveStates->setMaximumSize(QSize(1677715, 30));
        btnSaveStates->setIcon(icon4);

        horizontalLayout->addWidget(btnSaveStates);


        verticalLayout->addWidget(widget);

        tblMain = new EQTableWidget(DlgHouseItem);
        if (tblMain->columnCount() < 5)
            tblMain->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblMain->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblMain->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblMain->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblMain->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblMain->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tblMain->setObjectName(QString::fromUtf8("tblMain"));
        tblMain->setStyleSheet(QString::fromUtf8("padding: 3px;"));
        tblMain->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(tblMain);


        retranslateUi(DlgHouseItem);

        QMetaObject::connectSlotsByName(DlgHouseItem);
    } // setupUi

    void retranslateUi(QDialog *DlgHouseItem)
    {
        DlgHouseItem->setWindowTitle(QCoreApplication::translate("DlgHouseItem", "House item", nullptr));
        label_2->setText(QCoreApplication::translate("DlgHouseItem", "Room", nullptr));
        btnAddItem->setText(QString());
        btnAddItem->setProperty("touchscreen", QVariant(QCoreApplication::translate("DlgHouseItem", "1", nullptr)));
        btnRemoveItem->setText(QString());
        btnRemoveItem->setProperty("touchscreen", QVariant(QCoreApplication::translate("DlgHouseItem", "1", nullptr)));
        btnCopy->setText(QString());
        btnCopy->setProperty("touchscreen", QVariant(QCoreApplication::translate("DlgHouseItem", "1", nullptr)));
        btnPaste->setText(QString());
        btnPaste->setProperty("touchscreen", QVariant(QCoreApplication::translate("DlgHouseItem", "1", nullptr)));
        btnSave->setText(QString());
        btnSave->setProperty("touchscreen", QVariant(QCoreApplication::translate("DlgHouseItem", "1", nullptr)));
        btnDontDisturbe->setText(QString());
        btnDontDisturbe->setProperty("touchscreen", QVariant(QCoreApplication::translate("DlgHouseItem", "1", nullptr)));
        lbStatus->setText(QString());
        btnSaveStates->setText(QCoreApplication::translate("DlgHouseItem", "Save states", nullptr));
        btnSaveStates->setProperty("touchscreen", QVariant(QCoreApplication::translate("DlgHouseItem", "1", nullptr)));
        QTableWidgetItem *___qtablewidgetitem = tblMain->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgHouseItem", "Rec code", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblMain->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgHouseItem", "Item name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblMain->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgHouseItem", "State", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblMain->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgHouseItem", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblMain->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DlgHouseItem", "Comment", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgHouseItem: public Ui_DlgHouseItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGHOUSEITEM_H
