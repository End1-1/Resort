/********************************************************************************
** Form generated from reading UI file 'wroomcharttemprectdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WROOMCHARTTEMPRECTDLG_H
#define UI_WROOMCHARTTEMPRECTDLG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_WRoomChartTempRectDlg
{
public:
    QGridLayout *gridLayout;
    QPushButton *btnSaveDraft_2;
    QPushButton *btnSaveDraft;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    EDateEdit *deEntry;
    EQLineEdit *lineEdit_3;
    EDateEdit *deDeparture;
    QLabel *label_4;
    EQLineEdit *lineEdit_4;
    QPushButton *btnCancel;

    void setupUi(QDialog *WRoomChartTempRectDlg)
    {
        if (WRoomChartTempRectDlg->objectName().isEmpty())
            WRoomChartTempRectDlg->setObjectName(QString::fromUtf8("WRoomChartTempRectDlg"));
        WRoomChartTempRectDlg->resize(363, 130);
        gridLayout = new QGridLayout(WRoomChartTempRectDlg);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnSaveDraft_2 = new QPushButton(WRoomChartTempRectDlg);
        btnSaveDraft_2->setObjectName(QString::fromUtf8("btnSaveDraft_2"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/bedroom.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSaveDraft_2->setIcon(icon);

        gridLayout->addWidget(btnSaveDraft_2, 3, 2, 1, 1);

        btnSaveDraft = new QPushButton(WRoomChartTempRectDlg);
        btnSaveDraft->setObjectName(QString::fromUtf8("btnSaveDraft"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSaveDraft->setIcon(icon1);

        gridLayout->addWidget(btnSaveDraft, 3, 1, 1, 1);

        label_2 = new QLabel(WRoomChartTempRectDlg);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 2, 1, 1);

        label_3 = new QLabel(WRoomChartTempRectDlg);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(WRoomChartTempRectDlg);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        deEntry = new EDateEdit(WRoomChartTempRectDlg);
        deEntry->setObjectName(QString::fromUtf8("deEntry"));
        deEntry->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(deEntry, 1, 1, 1, 1);

        lineEdit_3 = new EQLineEdit(WRoomChartTempRectDlg);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 3);

        deDeparture = new EDateEdit(WRoomChartTempRectDlg);
        deDeparture->setObjectName(QString::fromUtf8("deDeparture"));
        deDeparture->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(deDeparture, 1, 3, 1, 1);

        label_4 = new QLabel(WRoomChartTempRectDlg);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_4 = new EQLineEdit(WRoomChartTempRectDlg);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(lineEdit_4, 0, 1, 1, 1);

        btnCancel = new QPushButton(WRoomChartTempRectDlg);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancel->setIcon(icon2);

        gridLayout->addWidget(btnCancel, 3, 3, 1, 1);


        retranslateUi(WRoomChartTempRectDlg);

        QMetaObject::connectSlotsByName(WRoomChartTempRectDlg);
    } // setupUi

    void retranslateUi(QDialog *WRoomChartTempRectDlg)
    {
        WRoomChartTempRectDlg->setWindowTitle(QCoreApplication::translate("WRoomChartTempRectDlg", "Selected range", nullptr));
        btnSaveDraft_2->setText(QCoreApplication::translate("WRoomChartTempRectDlg", "Create\n"
"reservation", nullptr));
        btnSaveDraft->setText(QCoreApplication::translate("WRoomChartTempRectDlg", "Create\n"
"draft", nullptr));
        label_2->setText(QCoreApplication::translate("WRoomChartTempRectDlg", "Departure", nullptr));
        label_3->setText(QCoreApplication::translate("WRoomChartTempRectDlg", "Guest", nullptr));
        label->setText(QCoreApplication::translate("WRoomChartTempRectDlg", "Entry", nullptr));
        label_4->setText(QCoreApplication::translate("WRoomChartTempRectDlg", "Room", nullptr));
        btnCancel->setText(QCoreApplication::translate("WRoomChartTempRectDlg", "Cancel\n"
"selection", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WRoomChartTempRectDlg: public Ui_WRoomChartTempRectDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WROOMCHARTTEMPRECTDLG_H
