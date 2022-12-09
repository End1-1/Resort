/********************************************************************************
** Form generated from reading UI file 'databasesconnections.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASESCONNECTIONS_H
#define UI_DATABASESCONNECTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabasesConnections
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAdd;
    QPushButton *btnEdit;
    QPushButton *btnRemove;
    QSpacerItem *horizontalSpacer;
    QCheckBox *chDirectConnection;
    QPushButton *btnChangePassword;
    QWidget *wBroadcast;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *leBroadcast;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableDb;

    void setupUi(QDialog *DatabasesConnections)
    {
        if (DatabasesConnections->objectName().isEmpty())
            DatabasesConnections->setObjectName(QString::fromUtf8("DatabasesConnections"));
        DatabasesConnections->resize(686, 531);
        verticalLayout = new QVBoxLayout(DatabasesConnections);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(DatabasesConnections);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnAdd = new QPushButton(widget);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setMinimumSize(QSize(25, 25));
        btnAdd->setMaximumSize(QSize(25, 25));

        horizontalLayout->addWidget(btnAdd);

        btnEdit = new QPushButton(widget);
        btnEdit->setObjectName(QString::fromUtf8("btnEdit"));
        btnEdit->setMinimumSize(QSize(25, 25));
        btnEdit->setMaximumSize(QSize(25, 25));

        horizontalLayout->addWidget(btnEdit);

        btnRemove = new QPushButton(widget);
        btnRemove->setObjectName(QString::fromUtf8("btnRemove"));
        btnRemove->setMinimumSize(QSize(25, 25));
        btnRemove->setMaximumSize(QSize(25, 25));

        horizontalLayout->addWidget(btnRemove);

        horizontalSpacer = new QSpacerItem(554, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        chDirectConnection = new QCheckBox(widget);
        chDirectConnection->setObjectName(QString::fromUtf8("chDirectConnection"));

        horizontalLayout->addWidget(chDirectConnection);

        btnChangePassword = new QPushButton(widget);
        btnChangePassword->setObjectName(QString::fromUtf8("btnChangePassword"));

        horizontalLayout->addWidget(btnChangePassword);


        verticalLayout->addWidget(widget);

        wBroadcast = new QWidget(DatabasesConnections);
        wBroadcast->setObjectName(QString::fromUtf8("wBroadcast"));
        horizontalLayout_2 = new QHBoxLayout(wBroadcast);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(wBroadcast);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        leBroadcast = new QLineEdit(wBroadcast);
        leBroadcast->setObjectName(QString::fromUtf8("leBroadcast"));
        leBroadcast->setMinimumSize(QSize(200, 0));
        leBroadcast->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_2->addWidget(leBroadcast);

        horizontalSpacer_2 = new QSpacerItem(353, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(wBroadcast);

        tableDb = new QTableWidget(DatabasesConnections);
        if (tableDb->columnCount() < 5)
            tableDb->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableDb->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableDb->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableDb->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableDb->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableDb->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableDb->setObjectName(QString::fromUtf8("tableDb"));
        tableDb->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableDb->setSelectionMode(QAbstractItemView::SingleSelection);
        tableDb->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(tableDb);


        retranslateUi(DatabasesConnections);

        QMetaObject::connectSlotsByName(DatabasesConnections);
    } // setupUi

    void retranslateUi(QDialog *DatabasesConnections)
    {
        DatabasesConnections->setWindowTitle(QCoreApplication::translate("DatabasesConnections", "Databases connections", nullptr));
        btnAdd->setText(QCoreApplication::translate("DatabasesConnections", "+", nullptr));
        btnEdit->setText(QCoreApplication::translate("DatabasesConnections", "...", nullptr));
        btnRemove->setText(QCoreApplication::translate("DatabasesConnections", "-", nullptr));
        chDirectConnection->setText(QCoreApplication::translate("DatabasesConnections", "Use direct connection", nullptr));
        btnChangePassword->setText(QCoreApplication::translate("DatabasesConnections", "Change password", nullptr));
        label->setText(QCoreApplication::translate("DatabasesConnections", "Broadcast server", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableDb->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DatabasesConnections", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableDb->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DatabasesConnections", "Host", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableDb->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DatabasesConnections", "Database", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableDb->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DatabasesConnections", "Username", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableDb->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DatabasesConnections", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DatabasesConnections: public Ui_DatabasesConnections {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASESCONNECTIONS_H
