/********************************************************************************
** Form generated from reading UI file 'dlgexport.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGEXPORT_H
#define UI_DLGEXPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgExport
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *leHost;
    QLabel *label_2;
    QLineEdit *leDatabase;
    QLabel *label_3;
    QLineEdit *leUsername;
    QLabel *label_4;
    QLineEdit *lePassword;
    QPushButton *btnStart;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QCheckBox *chUsersGroups;
    QCheckBox *chUsers;
    QCheckBox *chReservationGuest;
    QCheckBox *chRoomstates;
    QCheckBox *chTable;
    QCheckBox *chWorkingDate;
    QCheckBox *chVouchers;
    QCheckBox *chRoomRestaurant;
    QCheckBox *chCL;
    QCheckBox *chGuests;
    QCheckBox *chCheckinReserve;
    QCheckBox *chCardex;
    QCheckBox *chCardexCounter;
    QCheckBox *chNationality;
    QCheckBox *chReserveGroups;
    QCheckBox *chOnlineRestaurant;
    QCheckBox *chMenu;
    QCheckBox *chHall;
    QCheckBox *chOutOfOrder;
    QCheckBox *chSettings;
    QCheckBox *chFinal;
    QPlainTextEdit *ptLog;

    void setupUi(QDialog *DlgExport)
    {
        if (DlgExport->objectName().isEmpty())
            DlgExport->setObjectName(QString::fromUtf8("DlgExport"));
        DlgExport->resize(1060, 778);
        verticalLayout = new QVBoxLayout(DlgExport);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(DlgExport);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leHost = new QLineEdit(groupBox);
        leHost->setObjectName(QString::fromUtf8("leHost"));

        gridLayout->addWidget(leHost, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leDatabase = new QLineEdit(groupBox);
        leDatabase->setObjectName(QString::fromUtf8("leDatabase"));

        gridLayout->addWidget(leDatabase, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        leUsername = new QLineEdit(groupBox);
        leUsername->setObjectName(QString::fromUtf8("leUsername"));

        gridLayout->addWidget(leUsername, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lePassword = new QLineEdit(groupBox);
        lePassword->setObjectName(QString::fromUtf8("lePassword"));

        gridLayout->addWidget(lePassword, 3, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        btnStart = new QPushButton(DlgExport);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));

        verticalLayout->addWidget(btnStart);

        groupBox_2 = new QGroupBox(DlgExport);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        chUsersGroups = new QCheckBox(groupBox_2);
        chUsersGroups->setObjectName(QString::fromUtf8("chUsersGroups"));
        chUsersGroups->setEnabled(false);

        gridLayout_2->addWidget(chUsersGroups, 7, 1, 1, 1);

        chUsers = new QCheckBox(groupBox_2);
        chUsers->setObjectName(QString::fromUtf8("chUsers"));
        chUsers->setEnabled(false);

        gridLayout_2->addWidget(chUsers, 8, 1, 1, 1);

        chReservationGuest = new QCheckBox(groupBox_2);
        chReservationGuest->setObjectName(QString::fromUtf8("chReservationGuest"));
        chReservationGuest->setEnabled(false);

        gridLayout_2->addWidget(chReservationGuest, 6, 0, 1, 1);

        chRoomstates = new QCheckBox(groupBox_2);
        chRoomstates->setObjectName(QString::fromUtf8("chRoomstates"));
        chRoomstates->setEnabled(false);

        gridLayout_2->addWidget(chRoomstates, 7, 0, 1, 1);

        chTable = new QCheckBox(groupBox_2);
        chTable->setObjectName(QString::fromUtf8("chTable"));
        chTable->setEnabled(false);

        gridLayout_2->addWidget(chTable, 6, 1, 1, 1);

        chWorkingDate = new QCheckBox(groupBox_2);
        chWorkingDate->setObjectName(QString::fromUtf8("chWorkingDate"));
        chWorkingDate->setEnabled(false);

        gridLayout_2->addWidget(chWorkingDate, 0, 0, 1, 1);

        chVouchers = new QCheckBox(groupBox_2);
        chVouchers->setObjectName(QString::fromUtf8("chVouchers"));
        chVouchers->setEnabled(false);

        gridLayout_2->addWidget(chVouchers, 3, 0, 1, 1);

        chRoomRestaurant = new QCheckBox(groupBox_2);
        chRoomRestaurant->setObjectName(QString::fromUtf8("chRoomRestaurant"));
        chRoomRestaurant->setEnabled(false);

        gridLayout_2->addWidget(chRoomRestaurant, 4, 0, 1, 1);

        chCL = new QCheckBox(groupBox_2);
        chCL->setObjectName(QString::fromUtf8("chCL"));
        chCL->setEnabled(false);

        gridLayout_2->addWidget(chCL, 1, 1, 1, 1);

        chGuests = new QCheckBox(groupBox_2);
        chGuests->setObjectName(QString::fromUtf8("chGuests"));
        chGuests->setEnabled(false);

        gridLayout_2->addWidget(chGuests, 5, 0, 1, 1);

        chCheckinReserve = new QCheckBox(groupBox_2);
        chCheckinReserve->setObjectName(QString::fromUtf8("chCheckinReserve"));
        chCheckinReserve->setEnabled(false);

        gridLayout_2->addWidget(chCheckinReserve, 1, 0, 1, 1);

        chCardex = new QCheckBox(groupBox_2);
        chCardex->setObjectName(QString::fromUtf8("chCardex"));
        chCardex->setEnabled(false);

        gridLayout_2->addWidget(chCardex, 0, 1, 1, 1);

        chCardexCounter = new QCheckBox(groupBox_2);
        chCardexCounter->setObjectName(QString::fromUtf8("chCardexCounter"));
        chCardexCounter->setEnabled(false);

        gridLayout_2->addWidget(chCardexCounter, 3, 1, 1, 1);

        chNationality = new QCheckBox(groupBox_2);
        chNationality->setObjectName(QString::fromUtf8("chNationality"));
        chNationality->setEnabled(false);

        gridLayout_2->addWidget(chNationality, 9, 1, 1, 1);

        chReserveGroups = new QCheckBox(groupBox_2);
        chReserveGroups->setObjectName(QString::fromUtf8("chReserveGroups"));
        chReserveGroups->setEnabled(false);

        gridLayout_2->addWidget(chReserveGroups, 4, 1, 1, 1);

        chOnlineRestaurant = new QCheckBox(groupBox_2);
        chOnlineRestaurant->setObjectName(QString::fromUtf8("chOnlineRestaurant"));
        chOnlineRestaurant->setEnabled(false);

        gridLayout_2->addWidget(chOnlineRestaurant, 8, 0, 1, 1);

        chMenu = new QCheckBox(groupBox_2);
        chMenu->setObjectName(QString::fromUtf8("chMenu"));
        chMenu->setEnabled(false);

        gridLayout_2->addWidget(chMenu, 9, 0, 1, 1);

        chHall = new QCheckBox(groupBox_2);
        chHall->setObjectName(QString::fromUtf8("chHall"));
        chHall->setEnabled(false);

        gridLayout_2->addWidget(chHall, 5, 1, 1, 1);

        chOutOfOrder = new QCheckBox(groupBox_2);
        chOutOfOrder->setObjectName(QString::fromUtf8("chOutOfOrder"));
        chOutOfOrder->setEnabled(false);

        gridLayout_2->addWidget(chOutOfOrder, 1, 2, 1, 1);

        chSettings = new QCheckBox(groupBox_2);
        chSettings->setObjectName(QString::fromUtf8("chSettings"));
        chSettings->setEnabled(false);

        gridLayout_2->addWidget(chSettings, 0, 2, 1, 1);

        chFinal = new QCheckBox(groupBox_2);
        chFinal->setObjectName(QString::fromUtf8("chFinal"));
        chFinal->setEnabled(false);

        gridLayout_2->addWidget(chFinal, 3, 2, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        ptLog = new QPlainTextEdit(DlgExport);
        ptLog->setObjectName(QString::fromUtf8("ptLog"));

        verticalLayout->addWidget(ptLog);


        retranslateUi(DlgExport);

        QMetaObject::connectSlotsByName(DlgExport);
    } // setupUi

    void retranslateUi(QDialog *DlgExport)
    {
        DlgExport->setWindowTitle(QCoreApplication::translate("DlgExport", "Export data", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DlgExport", "Destination", nullptr));
        label->setText(QCoreApplication::translate("DlgExport", "Host", nullptr));
        label_2->setText(QCoreApplication::translate("DlgExport", "Database", nullptr));
        label_3->setText(QCoreApplication::translate("DlgExport", "Username", nullptr));
        label_4->setText(QCoreApplication::translate("DlgExport", "Password", nullptr));
        btnStart->setText(QCoreApplication::translate("DlgExport", "Start!", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DlgExport", "Progress", nullptr));
        chUsersGroups->setText(QCoreApplication::translate("DlgExport", "Users groups", nullptr));
        chUsers->setText(QCoreApplication::translate("DlgExport", "Users", nullptr));
        chReservationGuest->setText(QCoreApplication::translate("DlgExport", "Reservation guest", nullptr));
        chRoomstates->setText(QCoreApplication::translate("DlgExport", "Room states", nullptr));
        chTable->setText(QCoreApplication::translate("DlgExport", "Tables", nullptr));
        chWorkingDate->setText(QCoreApplication::translate("DlgExport", "Working date", nullptr));
        chVouchers->setText(QCoreApplication::translate("DlgExport", "Vochers", nullptr));
        chRoomRestaurant->setText(QCoreApplication::translate("DlgExport", "Restaurant vouchers for invoices", nullptr));
        chCL->setText(QCoreApplication::translate("DlgExport", "Citi ledger", nullptr));
        chGuests->setText(QCoreApplication::translate("DlgExport", "Guests", nullptr));
        chCheckinReserve->setText(QCoreApplication::translate("DlgExport", "Checkin and reservations", nullptr));
        chCardex->setText(QCoreApplication::translate("DlgExport", "Cardex", nullptr));
        chCardexCounter->setText(QCoreApplication::translate("DlgExport", "Cardex counters", nullptr));
        chNationality->setText(QCoreApplication::translate("DlgExport", "Nationality file", nullptr));
        chReserveGroups->setText(QCoreApplication::translate("DlgExport", "Reservation groups", nullptr));
        chOnlineRestaurant->setText(QCoreApplication::translate("DlgExport", "Online restaurant and events", nullptr));
        chMenu->setText(QCoreApplication::translate("DlgExport", "Menu", nullptr));
        chHall->setText(QCoreApplication::translate("DlgExport", "Hall", nullptr));
        chOutOfOrder->setText(QCoreApplication::translate("DlgExport", "Out of order and draft reservations", nullptr));
        chSettings->setText(QCoreApplication::translate("DlgExport", "Settings", nullptr));
        chFinal->setText(QCoreApplication::translate("DlgExport", "Fix inserted id", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgExport: public Ui_DlgExport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGEXPORT_H
