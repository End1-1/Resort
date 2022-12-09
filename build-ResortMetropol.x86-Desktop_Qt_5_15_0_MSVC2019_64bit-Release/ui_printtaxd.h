/********************************************************************************
** Form generated from reading UI file 'printtaxd.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTTAXD_H
#define UI_PRINTTAXD_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqcheckbox.h>
#include <eqlineedit.h>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_PrintTaxD
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    EQLineEdit *leAvailablePrepaid;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *tblFilter;
    QPushButton *btnClearFilter;
    QSpacerItem *horizontalSpacer_3;
    EQCheckBox *chCheckUncheckAll;
    EQTableWidget *tblData;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    EQLineEdit *leCard;
    EQLineEdit *leTotal;
    EQLineEdit *leCash;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    EQLineEdit *lePre;
    QLabel *label_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPrint;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *PrintTaxD)
    {
        if (PrintTaxD->objectName().isEmpty())
            PrintTaxD->setObjectName(QString::fromUtf8("PrintTaxD"));
        PrintTaxD->resize(689, 540);
        verticalLayout = new QVBoxLayout(PrintTaxD);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_3 = new QWidget(PrintTaxD);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        leAvailablePrepaid = new EQLineEdit(widget_3);
        leAvailablePrepaid->setObjectName(QString::fromUtf8("leAvailablePrepaid"));
        leAvailablePrepaid->setStyleSheet(QString::fromUtf8("font-size:12pt;\n"
"font-weight:bold;\n"
"color:red;"));
        leAvailablePrepaid->setReadOnly(true);

        horizontalLayout_2->addWidget(leAvailablePrepaid);

        horizontalSpacer_4 = new QSpacerItem(174, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(PrintTaxD);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        tblFilter = new QTableWidget(widget_4);
        if (tblFilter->columnCount() < 7)
            tblFilter->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblFilter->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblFilter->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblFilter->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblFilter->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblFilter->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblFilter->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblFilter->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tblFilter->rowCount() < 1)
            tblFilter->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblFilter->setVerticalHeaderItem(0, __qtablewidgetitem7);
        tblFilter->setObjectName(QString::fromUtf8("tblFilter"));
        tblFilter->setMaximumSize(QSize(16777215, 30));
        tblFilter->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblFilter->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblFilter->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblFilter->setSelectionMode(QAbstractItemView::SingleSelection);
        tblFilter->horizontalHeader()->setVisible(false);
        tblFilter->horizontalHeader()->setDefaultSectionSize(39);
        tblFilter->verticalHeader()->setVisible(false);

        horizontalLayout_3->addWidget(tblFilter);

        btnClearFilter = new QPushButton(widget_4);
        btnClearFilter->setObjectName(QString::fromUtf8("btnClearFilter"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/remove_filter.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClearFilter->setIcon(icon);

        horizontalLayout_3->addWidget(btnClearFilter);

        horizontalSpacer_3 = new QSpacerItem(92, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        chCheckUncheckAll = new EQCheckBox(widget_4);
        chCheckUncheckAll->setObjectName(QString::fromUtf8("chCheckUncheckAll"));

        horizontalLayout_3->addWidget(chCheckUncheckAll);


        verticalLayout->addWidget(widget_4);

        tblData = new EQTableWidget(PrintTaxD);
        if (tblData->columnCount() < 9)
            tblData->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(6, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(7, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(8, __qtablewidgetitem16);
        tblData->setObjectName(QString::fromUtf8("tblData"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(4);
        sizePolicy1.setHeightForWidth(tblData->sizePolicy().hasHeightForWidth());
        tblData->setSizePolicy(sizePolicy1);
        tblData->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(tblData);

        widget_2 = new QWidget(PrintTaxD);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        leCard = new EQLineEdit(widget_2);
        leCard->setObjectName(QString::fromUtf8("leCard"));

        gridLayout->addWidget(leCard, 1, 1, 1, 1);

        leTotal = new EQLineEdit(widget_2);
        leTotal->setObjectName(QString::fromUtf8("leTotal"));
        leTotal->setReadOnly(true);

        gridLayout->addWidget(leTotal, 3, 1, 1, 1);

        leCash = new EQLineEdit(widget_2);
        leCash->setObjectName(QString::fromUtf8("leCash"));

        gridLayout->addWidget(leCash, 1, 0, 1, 1);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 2, 1, 1, 1);

        lePre = new EQLineEdit(widget_2);
        lePre->setObjectName(QString::fromUtf8("lePre"));
        lePre->setStyleSheet(QString::fromUtf8("font-size:12pt;\n"
"font-weight:bold;\n"
"color:red;"));
        lePre->setReadOnly(false);

        gridLayout->addWidget(lePre, 3, 0, 1, 1);

        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(PrintTaxD);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnPrint = new QPushButton(widget);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(10);
        sizePolicy2.setHeightForWidth(btnPrint->sizePolicy().hasHeightForWidth());
        btnPrint->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(btnPrint);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        sizePolicy2.setHeightForWidth(btnCancel->sizePolicy().hasHeightForWidth());
        btnCancel->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);


        retranslateUi(PrintTaxD);

        QMetaObject::connectSlotsByName(PrintTaxD);
    } // setupUi

    void retranslateUi(QDialog *PrintTaxD)
    {
        PrintTaxD->setWindowTitle(QCoreApplication::translate("PrintTaxD", "Print tax", nullptr));
        label_5->setText(QCoreApplication::translate("PrintTaxD", "Available prepaid amount", nullptr));
        leAvailablePrepaid->setText(QCoreApplication::translate("PrintTaxD", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblFilter->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("PrintTaxD", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblFilter->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("PrintTaxD", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblFilter->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("PrintTaxD", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblFilter->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("PrintTaxD", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblFilter->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("PrintTaxD", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblFilter->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("PrintTaxD", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblFilter->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("PrintTaxD", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblFilter->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("PrintTaxD", "New Row", nullptr));
        btnClearFilter->setText(QString());
        chCheckUncheckAll->setText(QCoreApplication::translate("PrintTaxD", "Check/Uncheck all", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblData->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("PrintTaxD", "RecId", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblData->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("PrintTaxD", "Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblData->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("PrintTaxD", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblData->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("PrintTaxD", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblData->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("PrintTaxD", "Print", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tblData->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("PrintTaxD", "Adgt", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tblData->horizontalHeaderItem(6);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("PrintTaxD", "Source", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tblData->horizontalHeaderItem(7);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("PrintTaxD", "Qty", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tblData->horizontalHeaderItem(8);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("PrintTaxD", "Total", nullptr));
        leCard->setInputMask(QString());
        leCash->setInputMask(QString());
        label_3->setText(QCoreApplication::translate("PrintTaxD", "Card", nullptr));
        label_2->setText(QCoreApplication::translate("PrintTaxD", "Cash", nullptr));
        label->setText(QCoreApplication::translate("PrintTaxD", "Total", nullptr));
        lePre->setInputMask(QString());
        lePre->setText(QCoreApplication::translate("PrintTaxD", "0", nullptr));
        label_4->setText(QCoreApplication::translate("PrintTaxD", "Prepaid", nullptr));
        btnPrint->setText(QCoreApplication::translate("PrintTaxD", "Print", nullptr));
        btnCancel->setText(QCoreApplication::translate("PrintTaxD", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PrintTaxD: public Ui_PrintTaxD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTTAXD_H
