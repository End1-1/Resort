/********************************************************************************
** Form generated from reading UI file 'dwmaindeskhint.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DWMAINDESKHINT_H
#define UI_DWMAINDESKHINT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <tableview.h>

QT_BEGIN_NAMESPACE

class Ui_DWMainDeskHint
{
public:
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QPushButton *btnCheckIn;
    QSpacerItem *horizontalSpacer;
    TableView *tbl;

    void setupUi(QDockWidget *DWMainDeskHint)
    {
        if (DWMainDeskHint->objectName().isEmpty())
            DWMainDeskHint->setObjectName(QString::fromUtf8("DWMainDeskHint"));
        DWMainDeskHint->resize(1000, 500);
        DWMainDeskHint->setMinimumSize(QSize(1000, 500));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/funnel.png"), QSize(), QIcon::Normal, QIcon::Off);
        DWMainDeskHint->setWindowIcon(icon);
        DWMainDeskHint->setFloating(true);
        DWMainDeskHint->setAllowedAreas(Qt::NoDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnCheckIn = new QPushButton(dockWidgetContents);
        btnCheckIn->setObjectName(QString::fromUtf8("btnCheckIn"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/checkin.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCheckIn->setIcon(icon1);

        gridLayout->addWidget(btnCheckIn, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        tbl = new TableView(dockWidgetContents);
        tbl->setObjectName(QString::fromUtf8("tbl"));
        tbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbl->setSelectionMode(QAbstractItemView::NoSelection);
        tbl->setWordWrap(false);
        tbl->verticalHeader()->setDefaultSectionSize(26);

        gridLayout->addWidget(tbl, 0, 0, 1, 2);

        DWMainDeskHint->setWidget(dockWidgetContents);

        retranslateUi(DWMainDeskHint);

        QMetaObject::connectSlotsByName(DWMainDeskHint);
    } // setupUi

    void retranslateUi(QDockWidget *DWMainDeskHint)
    {
        DWMainDeskHint->setWindowTitle(QCoreApplication::translate("DWMainDeskHint", "Search for", nullptr));
        btnCheckIn->setText(QCoreApplication::translate("DWMainDeskHint", "New reservation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DWMainDeskHint: public Ui_DWMainDeskHint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DWMAINDESKHINT_H
