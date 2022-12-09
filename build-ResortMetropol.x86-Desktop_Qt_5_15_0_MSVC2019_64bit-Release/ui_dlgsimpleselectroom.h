/********************************************************************************
** Form generated from reading UI file 'dlgsimpleselectroom.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGSIMPLESELECTROOM_H
#define UI_DLGSIMPLESELECTROOM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgSimpleSelectRoom
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_26;
    QLabel *label_25;
    EQLineEdit *lePrice;
    QTableWidget *tblFloor;
    QPushButton *btnClearRoomFilter;
    QLabel *label_27;
    QLabel *lbCat;
    QTableWidget *tblSmoke;
    QTableWidget *tblCategory;
    EQTableWidget *tblData;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *lbTotal;
    QPushButton *btnMultiSelect;

    void setupUi(QDialog *DlgSimpleSelectRoom)
    {
        if (DlgSimpleSelectRoom->objectName().isEmpty())
            DlgSimpleSelectRoom->setObjectName(QString::fromUtf8("DlgSimpleSelectRoom"));
        DlgSimpleSelectRoom->resize(688, 581);
        verticalLayout = new QVBoxLayout(DlgSimpleSelectRoom);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(DlgSimpleSelectRoom);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 30));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_26 = new QLabel(widget);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout->addWidget(label_26, 2, 0, 1, 1);

        label_25 = new QLabel(widget);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout->addWidget(label_25, 1, 0, 1, 1);

        lePrice = new EQLineEdit(widget);
        lePrice->setObjectName(QString::fromUtf8("lePrice"));
        lePrice->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(lePrice, 1, 2, 1, 1);

        tblFloor = new QTableWidget(widget);
        tblFloor->setObjectName(QString::fromUtf8("tblFloor"));
        tblFloor->setMaximumSize(QSize(16777215, 25));
        tblFloor->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblFloor->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblFloor->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblFloor->setSelectionMode(QAbstractItemView::SingleSelection);
        tblFloor->horizontalHeader()->setVisible(false);
        tblFloor->horizontalHeader()->setDefaultSectionSize(35);
        tblFloor->verticalHeader()->setVisible(false);
        tblFloor->verticalHeader()->setDefaultSectionSize(25);

        gridLayout->addWidget(tblFloor, 2, 1, 1, 5);

        btnClearRoomFilter = new QPushButton(widget);
        btnClearRoomFilter->setObjectName(QString::fromUtf8("btnClearRoomFilter"));
        btnClearRoomFilter->setMinimumSize(QSize(25, 25));
        btnClearRoomFilter->setMaximumSize(QSize(25, 25));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/remove_filter.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClearRoomFilter->setIcon(icon);

        gridLayout->addWidget(btnClearRoomFilter, 1, 5, 1, 1);

        label_27 = new QLabel(widget);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout->addWidget(label_27, 1, 3, 1, 1);

        lbCat = new QLabel(widget);
        lbCat->setObjectName(QString::fromUtf8("lbCat"));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        lbCat->setFont(font);

        gridLayout->addWidget(lbCat, 0, 0, 1, 1);

        tblSmoke = new QTableWidget(widget);
        if (tblSmoke->columnCount() < 3)
            tblSmoke->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblSmoke->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblSmoke->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblSmoke->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tblSmoke->rowCount() < 1)
            tblSmoke->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblSmoke->setVerticalHeaderItem(0, __qtablewidgetitem3);
        tblSmoke->setObjectName(QString::fromUtf8("tblSmoke"));
        tblSmoke->setMaximumSize(QSize(16777215, 25));
        tblSmoke->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblSmoke->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblSmoke->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblSmoke->setSelectionMode(QAbstractItemView::SingleSelection);
        tblSmoke->horizontalHeader()->setVisible(false);
        tblSmoke->horizontalHeader()->setDefaultSectionSize(70);
        tblSmoke->verticalHeader()->setVisible(false);
        tblSmoke->verticalHeader()->setDefaultSectionSize(25);

        gridLayout->addWidget(tblSmoke, 1, 4, 1, 1);

        tblCategory = new QTableWidget(widget);
        if (tblCategory->columnCount() < 8)
            tblCategory->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblCategory->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblCategory->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblCategory->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblCategory->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblCategory->setHorizontalHeaderItem(4, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tblCategory->setHorizontalHeaderItem(5, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblCategory->setHorizontalHeaderItem(6, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tblCategory->setHorizontalHeaderItem(7, __qtablewidgetitem11);
        if (tblCategory->rowCount() < 1)
            tblCategory->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tblCategory->setVerticalHeaderItem(0, __qtablewidgetitem12);
        tblCategory->setObjectName(QString::fromUtf8("tblCategory"));
        tblCategory->setMaximumSize(QSize(16777215, 25));
        tblCategory->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblCategory->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblCategory->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblCategory->setSelectionMode(QAbstractItemView::SingleSelection);
        tblCategory->horizontalHeader()->setVisible(false);
        tblCategory->horizontalHeader()->setDefaultSectionSize(39);
        tblCategory->verticalHeader()->setVisible(false);
        tblCategory->verticalHeader()->setDefaultSectionSize(25);

        gridLayout->addWidget(tblCategory, 0, 3, 1, 2);


        verticalLayout->addWidget(widget);

        tblData = new EQTableWidget(DlgSimpleSelectRoom);
        tblData->setObjectName(QString::fromUtf8("tblData"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(tblData->sizePolicy().hasHeightForWidth());
        tblData->setSizePolicy(sizePolicy);
        tblData->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblData->setSelectionMode(QAbstractItemView::NoSelection);
        tblData->horizontalHeader()->setVisible(false);
        tblData->horizontalHeader()->setDefaultSectionSize(130);
        tblData->horizontalHeader()->setHighlightSections(false);
        tblData->verticalHeader()->setVisible(false);
        tblData->verticalHeader()->setHighlightSections(false);

        verticalLayout->addWidget(tblData);

        widget_2 = new QWidget(DlgSimpleSelectRoom);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lbTotal = new QLabel(widget_2);
        lbTotal->setObjectName(QString::fromUtf8("lbTotal"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        lbTotal->setFont(font1);

        horizontalLayout->addWidget(lbTotal);

        btnMultiSelect = new QPushButton(widget_2);
        btnMultiSelect->setObjectName(QString::fromUtf8("btnMultiSelect"));
        btnMultiSelect->setMinimumSize(QSize(0, 0));
        btnMultiSelect->setMaximumSize(QSize(80, 555));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMultiSelect->setIcon(icon1);

        horizontalLayout->addWidget(btnMultiSelect);


        verticalLayout->addWidget(widget_2);


        retranslateUi(DlgSimpleSelectRoom);

        QMetaObject::connectSlotsByName(DlgSimpleSelectRoom);
    } // setupUi

    void retranslateUi(QDialog *DlgSimpleSelectRoom)
    {
        DlgSimpleSelectRoom->setWindowTitle(QCoreApplication::translate("DlgSimpleSelectRoom", "Room list", nullptr));
        label_26->setText(QCoreApplication::translate("DlgSimpleSelectRoom", "Floor", nullptr));
        label_25->setText(QCoreApplication::translate("DlgSimpleSelectRoom", "Price", nullptr));
        btnClearRoomFilter->setText(QString());
        label_27->setText(QCoreApplication::translate("DlgSimpleSelectRoom", "Smoking rooms", nullptr));
        lbCat->setText(QCoreApplication::translate("DlgSimpleSelectRoom", "lbCat", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblSmoke->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgSimpleSelectRoom", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblSmoke->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgSimpleSelectRoom", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblSmoke->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgSimpleSelectRoom", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblSmoke->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgSimpleSelectRoom", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblCategory->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DlgSimpleSelectRoom", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblCategory->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("DlgSimpleSelectRoom", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblCategory->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("DlgSimpleSelectRoom", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblCategory->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("DlgSimpleSelectRoom", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblCategory->horizontalHeaderItem(4);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("DlgSimpleSelectRoom", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblCategory->horizontalHeaderItem(5);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("DlgSimpleSelectRoom", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblCategory->horizontalHeaderItem(6);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("DlgSimpleSelectRoom", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblCategory->horizontalHeaderItem(7);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("DlgSimpleSelectRoom", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblCategory->verticalHeaderItem(0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("DlgSimpleSelectRoom", "New Row", nullptr));
        lbTotal->setText(QCoreApplication::translate("DlgSimpleSelectRoom", "Total: 0", nullptr));
        btnMultiSelect->setText(QCoreApplication::translate("DlgSimpleSelectRoom", " Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgSimpleSelectRoom: public Ui_DlgSimpleSelectRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGSIMPLESELECTROOM_H
