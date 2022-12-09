/********************************************************************************
** Form generated from reading UI file 'dlgseachfromdatabase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGSEACHFROMDATABASE_H
#define UI_DLGSEACHFROMDATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <eqlineedit.h>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgSeachFromDatabase
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    EQLineEdit *leSearch;
    QSpacerItem *horizontalSpacer;
    EQTableWidget *tbl;

    void setupUi(QDialog *DlgSeachFromDatabase)
    {
        if (DlgSeachFromDatabase->objectName().isEmpty())
            DlgSeachFromDatabase->setObjectName(QString::fromUtf8("DlgSeachFromDatabase"));
        DlgSeachFromDatabase->resize(800, 434);
        gridLayout = new QGridLayout(DlgSeachFromDatabase);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DlgSeachFromDatabase);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leSearch = new EQLineEdit(DlgSeachFromDatabase);
        leSearch->setObjectName(QString::fromUtf8("leSearch"));

        gridLayout->addWidget(leSearch, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(350, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        tbl = new EQTableWidget(DlgSeachFromDatabase);
        tbl->setObjectName(QString::fromUtf8("tbl"));
        tbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbl->setWordWrap(false);

        gridLayout->addWidget(tbl, 1, 0, 1, 3);


        retranslateUi(DlgSeachFromDatabase);

        QMetaObject::connectSlotsByName(DlgSeachFromDatabase);
    } // setupUi

    void retranslateUi(QDialog *DlgSeachFromDatabase)
    {
        DlgSeachFromDatabase->setWindowTitle(QCoreApplication::translate("DlgSeachFromDatabase", "Search", nullptr));
        label->setText(QCoreApplication::translate("DlgSeachFromDatabase", "Search string", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgSeachFromDatabase: public Ui_DlgSeachFromDatabase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGSEACHFROMDATABASE_H
