/********************************************************************************
** Form generated from reading UI file 'wcustomreports.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WCUSTOMREPORTS_H
#define UI_WCUSTOMREPORTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WCustomReports
{
public:
    QGridLayout *gridLayout;
    QWidget *wdtReport;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *vlReport;
    QWidget *wdtFilter;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *lFilter;
    QWidget *wdtMenu;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *trMenu;
    QPushButton *btnShowMenu;

    void setupUi(QWidget *WCustomReports)
    {
        if (WCustomReports->objectName().isEmpty())
            WCustomReports->setObjectName(QString::fromUtf8("WCustomReports"));
        WCustomReports->resize(741, 581);
        gridLayout = new QGridLayout(WCustomReports);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(9, 9, 9, 9);
        wdtReport = new QWidget(WCustomReports);
        wdtReport->setObjectName(QString::fromUtf8("wdtReport"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(5);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(wdtReport->sizePolicy().hasHeightForWidth());
        wdtReport->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(wdtReport);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        vlReport = new QVBoxLayout();
        vlReport->setObjectName(QString::fromUtf8("vlReport"));

        verticalLayout_2->addLayout(vlReport);


        gridLayout->addWidget(wdtReport, 1, 1, 1, 1);

        wdtFilter = new QWidget(WCustomReports);
        wdtFilter->setObjectName(QString::fromUtf8("wdtFilter"));
        wdtFilter->setMinimumSize(QSize(0, 0));
        horizontalLayout_2 = new QHBoxLayout(wdtFilter);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lFilter = new QHBoxLayout();
        lFilter->setObjectName(QString::fromUtf8("lFilter"));

        horizontalLayout_2->addLayout(lFilter);


        gridLayout->addWidget(wdtFilter, 0, 1, 1, 1);

        wdtMenu = new QWidget(WCustomReports);
        wdtMenu->setObjectName(QString::fromUtf8("wdtMenu"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(wdtMenu->sizePolicy().hasHeightForWidth());
        wdtMenu->setSizePolicy(sizePolicy1);
        wdtMenu->setMaximumSize(QSize(555, 5555));
        horizontalLayout = new QHBoxLayout(wdtMenu);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        trMenu = new QTreeWidget(wdtMenu);
        trMenu->setObjectName(QString::fromUtf8("trMenu"));

        horizontalLayout->addWidget(trMenu);

        btnShowMenu = new QPushButton(wdtMenu);
        btnShowMenu->setObjectName(QString::fromUtf8("btnShowMenu"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnShowMenu->sizePolicy().hasHeightForWidth());
        btnShowMenu->setSizePolicy(sizePolicy2);
        btnShowMenu->setMaximumSize(QSize(15, 16777215));

        horizontalLayout->addWidget(btnShowMenu);


        gridLayout->addWidget(wdtMenu, 0, 0, 2, 1);


        retranslateUi(WCustomReports);

        QMetaObject::connectSlotsByName(WCustomReports);
    } // setupUi

    void retranslateUi(QWidget *WCustomReports)
    {
        WCustomReports->setWindowTitle(QCoreApplication::translate("WCustomReports", "Form", nullptr));
        btnShowMenu->setText(QCoreApplication::translate("WCustomReports", "|", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WCustomReports: public Ui_WCustomReports {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WCUSTOMREPORTS_H
