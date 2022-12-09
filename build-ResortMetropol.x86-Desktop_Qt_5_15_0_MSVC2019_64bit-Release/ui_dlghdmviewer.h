/********************************************************************************
** Form generated from reading UI file 'dlghdmviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGHDMVIEWER_H
#define UI_DLGHDMVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgHDMViewer
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *leFiscal;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLineEdit *leAmountCash;
    QLabel *label_3;
    QLineEdit *leAmountCard;
    QLabel *label_4;
    QLineEdit *leAmountPrepaid;
    QLabel *label_5;
    QTableWidget *tbl;

    void setupUi(QDialog *DlgHDMViewer)
    {
        if (DlgHDMViewer->objectName().isEmpty())
            DlgHDMViewer->setObjectName(QString::fromUtf8("DlgHDMViewer"));
        DlgHDMViewer->resize(889, 441);
        gridLayout = new QGridLayout(DlgHDMViewer);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DlgHDMViewer);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leFiscal = new QLineEdit(DlgHDMViewer);
        leFiscal->setObjectName(QString::fromUtf8("leFiscal"));
        leFiscal->setReadOnly(true);

        gridLayout->addWidget(leFiscal, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(598, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_2 = new QLabel(DlgHDMViewer);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leAmountCash = new QLineEdit(DlgHDMViewer);
        leAmountCash->setObjectName(QString::fromUtf8("leAmountCash"));
        leAmountCash->setReadOnly(true);

        gridLayout->addWidget(leAmountCash, 1, 1, 1, 1);

        label_3 = new QLabel(DlgHDMViewer);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        leAmountCard = new QLineEdit(DlgHDMViewer);
        leAmountCard->setObjectName(QString::fromUtf8("leAmountCard"));
        leAmountCard->setReadOnly(true);

        gridLayout->addWidget(leAmountCard, 2, 1, 1, 1);

        label_4 = new QLabel(DlgHDMViewer);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        leAmountPrepaid = new QLineEdit(DlgHDMViewer);
        leAmountPrepaid->setObjectName(QString::fromUtf8("leAmountPrepaid"));
        leAmountPrepaid->setReadOnly(true);

        gridLayout->addWidget(leAmountPrepaid, 3, 1, 1, 1);

        label_5 = new QLabel(DlgHDMViewer);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        tbl = new QTableWidget(DlgHDMViewer);
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
        tbl->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout->addWidget(tbl, 5, 0, 1, 3);


        retranslateUi(DlgHDMViewer);

        QMetaObject::connectSlotsByName(DlgHDMViewer);
    } // setupUi

    void retranslateUi(QDialog *DlgHDMViewer)
    {
        DlgHDMViewer->setWindowTitle(QCoreApplication::translate("DlgHDMViewer", "Fiscal viewer", nullptr));
        label->setText(QCoreApplication::translate("DlgHDMViewer", "Fiscal number", nullptr));
        label_2->setText(QCoreApplication::translate("DlgHDMViewer", "Amount total", nullptr));
        label_3->setText(QCoreApplication::translate("DlgHDMViewer", "Amount card", nullptr));
        label_4->setText(QCoreApplication::translate("DlgHDMViewer", "Amount prepaid", nullptr));
        label_5->setText(QCoreApplication::translate("DlgHDMViewer", "Items", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tbl->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgHDMViewer", "Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tbl->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgHDMViewer", "Adgt", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tbl->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgHDMViewer", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tbl->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgHDMViewer", "Qty", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tbl->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DlgHDMViewer", "Unit", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tbl->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("DlgHDMViewer", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tbl->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("DlgHDMViewer", "Total", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tbl->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("DlgHDMViewer", "Dep", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgHDMViewer: public Ui_DlgHDMViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGHDMVIEWER_H
