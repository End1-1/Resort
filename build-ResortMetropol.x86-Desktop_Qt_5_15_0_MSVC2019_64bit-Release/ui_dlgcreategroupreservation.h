/********************************************************************************
** Form generated from reading UI file 'dlgcreategroupreservation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCREATEGROUPRESERVATION_H
#define UI_DLGCREATEGROUPRESERVATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgCreateGroupReservation
{
public:
    QGridLayout *gridLayout_3;
    QTableWidget *tblData;
    QPushButton *btnCreate;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    EDateEdit *deArrival;
    QLabel *label_5;
    EDateEdit *deDeparture;
    QLabel *label_24;
    QTableWidget *tblCategory;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_6;
    QGridLayout *gridLayout;
    QTableWidget *tblBed;
    QLabel *label_26;
    QLabel *label_25;
    QTableWidget *tblFloor;
    QLabel *label_27;
    QTableWidget *tblSmoke;
    QPushButton *btnClearRoomFilter;

    void setupUi(QDialog *DlgCreateGroupReservation)
    {
        if (DlgCreateGroupReservation->objectName().isEmpty())
            DlgCreateGroupReservation->setObjectName(QString::fromUtf8("DlgCreateGroupReservation"));
        DlgCreateGroupReservation->resize(893, 546);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DlgCreateGroupReservation->sizePolicy().hasHeightForWidth());
        DlgCreateGroupReservation->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(DlgCreateGroupReservation);
        gridLayout_3->setSpacing(1);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tblData = new QTableWidget(DlgCreateGroupReservation);
        if (tblData->columnCount() < 10)
            tblData->setColumnCount(10);
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
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        tblData->setObjectName(QString::fromUtf8("tblData"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(tblData->sizePolicy().hasHeightForWidth());
        tblData->setSizePolicy(sizePolicy1);
        tblData->setMinimumSize(QSize(0, 0));
        tblData->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblData->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblData->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblData->setSelectionMode(QAbstractItemView::NoSelection);
        tblData->horizontalHeader()->setDefaultSectionSize(80);
        tblData->verticalHeader()->setDefaultSectionSize(40);

        gridLayout_3->addWidget(tblData, 5, 0, 1, 3);

        btnCreate = new QPushButton(DlgCreateGroupReservation);
        btnCreate->setObjectName(QString::fromUtf8("btnCreate"));

        gridLayout_3->addWidget(btnCreate, 6, 0, 1, 3);

        widget_5 = new QWidget(DlgCreateGroupReservation);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setMinimumSize(QSize(0, 0));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        deArrival = new EDateEdit(widget_5);
        deArrival->setObjectName(QString::fromUtf8("deArrival"));
        deArrival->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(deArrival);

        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        deDeparture = new EDateEdit(widget_5);
        deDeparture->setObjectName(QString::fromUtf8("deDeparture"));
        deDeparture->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(deDeparture);

        label_24 = new QLabel(widget_5);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_3->addWidget(label_24);

        tblCategory = new QTableWidget(widget_5);
        tblCategory->setObjectName(QString::fromUtf8("tblCategory"));
        tblCategory->setMaximumSize(QSize(16777215, 25));
        tblCategory->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblCategory->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblCategory->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblCategory->horizontalHeader()->setVisible(false);
        tblCategory->horizontalHeader()->setDefaultSectionSize(35);
        tblCategory->verticalHeader()->setVisible(false);
        tblCategory->verticalHeader()->setDefaultSectionSize(25);

        horizontalLayout_3->addWidget(tblCategory);

        horizontalSpacer = new QSpacerItem(326, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        gridLayout_3->addWidget(widget_5, 1, 0, 1, 1);

        widget_6 = new QWidget(DlgCreateGroupReservation);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        gridLayout = new QGridLayout(widget_6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tblBed = new QTableWidget(widget_6);
        tblBed->setObjectName(QString::fromUtf8("tblBed"));
        tblBed->setMaximumSize(QSize(16777215, 25));
        tblBed->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblBed->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblBed->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblBed->horizontalHeader()->setVisible(false);
        tblBed->horizontalHeader()->setDefaultSectionSize(35);
        tblBed->verticalHeader()->setVisible(false);
        tblBed->verticalHeader()->setDefaultSectionSize(25);

        gridLayout->addWidget(tblBed, 0, 5, 1, 1);

        label_26 = new QLabel(widget_6);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout->addWidget(label_26, 0, 0, 1, 1);

        label_25 = new QLabel(widget_6);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout->addWidget(label_25, 0, 3, 1, 1);

        tblFloor = new QTableWidget(widget_6);
        tblFloor->setObjectName(QString::fromUtf8("tblFloor"));
        tblFloor->setMaximumSize(QSize(16777215, 25));
        tblFloor->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblFloor->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblFloor->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblFloor->horizontalHeader()->setVisible(false);
        tblFloor->horizontalHeader()->setDefaultSectionSize(35);
        tblFloor->verticalHeader()->setVisible(false);
        tblFloor->verticalHeader()->setDefaultSectionSize(25);

        gridLayout->addWidget(tblFloor, 0, 2, 1, 1);

        label_27 = new QLabel(widget_6);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout->addWidget(label_27, 0, 6, 1, 1);

        tblSmoke = new QTableWidget(widget_6);
        if (tblSmoke->columnCount() < 3)
            tblSmoke->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblSmoke->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tblSmoke->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tblSmoke->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        if (tblSmoke->rowCount() < 1)
            tblSmoke->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tblSmoke->setVerticalHeaderItem(0, __qtablewidgetitem13);
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

        gridLayout->addWidget(tblSmoke, 0, 7, 1, 1);

        btnClearRoomFilter = new QPushButton(widget_6);
        btnClearRoomFilter->setObjectName(QString::fromUtf8("btnClearRoomFilter"));
        btnClearRoomFilter->setMinimumSize(QSize(25, 25));
        btnClearRoomFilter->setMaximumSize(QSize(25, 25));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/remove_filter.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClearRoomFilter->setIcon(icon);

        gridLayout->addWidget(btnClearRoomFilter, 0, 8, 1, 1);


        gridLayout_3->addWidget(widget_6, 4, 0, 1, 1);


        retranslateUi(DlgCreateGroupReservation);

        QMetaObject::connectSlotsByName(DlgCreateGroupReservation);
    } // setupUi

    void retranslateUi(QDialog *DlgCreateGroupReservation)
    {
        DlgCreateGroupReservation->setWindowTitle(QCoreApplication::translate("DlgCreateGroupReservation", "Group reservation", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgCreateGroupReservation", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgCreateGroupReservation", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgCreateGroupReservation", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgCreateGroupReservation", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblData->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DlgCreateGroupReservation", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblData->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("DlgCreateGroupReservation", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblData->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("DlgCreateGroupReservation", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblData->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("DlgCreateGroupReservation", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblData->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("DlgCreateGroupReservation", "9", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblData->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("DlgCreateGroupReservation", "10", nullptr));
        btnCreate->setText(QCoreApplication::translate("DlgCreateGroupReservation", "Create", nullptr));
        label_4->setText(QCoreApplication::translate("DlgCreateGroupReservation", "Arrival date", nullptr));
        label_5->setText(QCoreApplication::translate("DlgCreateGroupReservation", "Departure date", nullptr));
        label_24->setText(QCoreApplication::translate("DlgCreateGroupReservation", "Category", nullptr));
        label_26->setText(QCoreApplication::translate("DlgCreateGroupReservation", "Floor", nullptr));
        label_25->setText(QCoreApplication::translate("DlgCreateGroupReservation", "Bed", nullptr));
        label_27->setText(QCoreApplication::translate("DlgCreateGroupReservation", "Smoking\n"
"rooms", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblSmoke->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("DlgCreateGroupReservation", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblSmoke->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("DlgCreateGroupReservation", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblSmoke->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("DlgCreateGroupReservation", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tblSmoke->verticalHeaderItem(0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("DlgCreateGroupReservation", "New Row", nullptr));
        btnClearRoomFilter->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DlgCreateGroupReservation: public Ui_DlgCreateGroupReservation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCREATEGROUPRESERVATION_H
