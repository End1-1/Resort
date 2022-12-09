/********************************************************************************
** Form generated from reading UI file 'wreportgrid.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WREPORTGRID_H
#define UI_WREPORTGRID_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_WReportGrid
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *wToolbar;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *btnNew;
    QToolButton *btnPrint;
    QToolButton *btnPrint2;
    QToolButton *btnConfigGrid;
    QToolButton *btnExcel;
    QToolButton *btnRefresh;
    QToolButton *btnHelp;
    QHBoxLayout *hlToolbar;
    QWidget *wPrint;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnFirst;
    QPushButton *btnBack;
    QLabel *lbPage;
    QPushButton *btnNext;
    QPushButton *btnLast;
    QPushButton *btnZoomOut;
    QPushButton *btnZoopIn;
    QComboBox *cbZoom;
    QLabel *label_2;
    QComboBox *cbPrintSelection;
    QLineEdit *lePages;
    QComboBox *cbPrinters;
    QSpacerItem *spacer;
    QLabel *label;
    QLineEdit *leQuickSearch;
    QPushButton *btnClearQuickSearch;
    QHBoxLayout *hl;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGraphicsView *gv;
    QTableView *tblMain;
    EQTableWidget *tblTotals;

    void setupUi(QWidget *WReportGrid)
    {
        if (WReportGrid->objectName().isEmpty())
            WReportGrid->setObjectName(QString::fromUtf8("WReportGrid"));
        WReportGrid->resize(1819, 538);
        WReportGrid->setMinimumSize(QSize(0, 0));
        WReportGrid->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(WReportGrid);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wToolbar = new QWidget(WReportGrid);
        wToolbar->setObjectName(QString::fromUtf8("wToolbar"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(wToolbar->sizePolicy().hasHeightForWidth());
        wToolbar->setSizePolicy(sizePolicy);
        wToolbar->setMinimumSize(QSize(0, 0));
        wToolbar->setMaximumSize(QSize(16777215, 2222));
        horizontalLayout_2 = new QHBoxLayout(wToolbar);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnNew = new QToolButton(wToolbar);
        btnNew->setObjectName(QString::fromUtf8("btnNew"));
        btnNew->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNew->setIcon(icon);
        btnNew->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(btnNew);

        btnPrint = new QToolButton(wToolbar);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));
        btnPrint->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrint->setIcon(icon1);
        btnPrint->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(btnPrint);

        btnPrint2 = new QToolButton(wToolbar);
        btnPrint2->setObjectName(QString::fromUtf8("btnPrint2"));
        btnPrint2->setFocusPolicy(Qt::NoFocus);
        btnPrint2->setIcon(icon1);
        btnPrint2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(btnPrint2);

        btnConfigGrid = new QToolButton(wToolbar);
        btnConfigGrid->setObjectName(QString::fromUtf8("btnConfigGrid"));
        btnConfigGrid->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnConfigGrid->setIcon(icon2);
        btnConfigGrid->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(btnConfigGrid);

        btnExcel = new QToolButton(wToolbar);
        btnExcel->setObjectName(QString::fromUtf8("btnExcel"));
        btnExcel->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/excel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExcel->setIcon(icon3);
        btnExcel->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(btnExcel);

        btnRefresh = new QToolButton(wToolbar);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));
        btnRefresh->setFocusPolicy(Qt::ClickFocus);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon4);
        btnRefresh->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(btnRefresh);

        btnHelp = new QToolButton(wToolbar);
        btnHelp->setObjectName(QString::fromUtf8("btnHelp"));
        btnHelp->setFocusPolicy(Qt::NoFocus);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/question.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHelp->setIcon(icon5);
        btnHelp->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(btnHelp);

        hlToolbar = new QHBoxLayout();
        hlToolbar->setSpacing(2);
        hlToolbar->setObjectName(QString::fromUtf8("hlToolbar"));

        horizontalLayout_2->addLayout(hlToolbar);

        wPrint = new QWidget(wToolbar);
        wPrint->setObjectName(QString::fromUtf8("wPrint"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(wPrint->sizePolicy().hasHeightForWidth());
        wPrint->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(wPrint);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnFirst = new QPushButton(wPrint);
        btnFirst->setObjectName(QString::fromUtf8("btnFirst"));
        btnFirst->setMinimumSize(QSize(30, 30));
        btnFirst->setMaximumSize(QSize(30, 30));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/double-left.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnFirst->setIcon(icon6);
        btnFirst->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(btnFirst);

        btnBack = new QPushButton(wPrint);
        btnBack->setObjectName(QString::fromUtf8("btnBack"));
        btnBack->setMinimumSize(QSize(30, 30));
        btnBack->setMaximumSize(QSize(30, 30));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/left-arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnBack->setIcon(icon7);
        btnBack->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(btnBack);

        lbPage = new QLabel(wPrint);
        lbPage->setObjectName(QString::fromUtf8("lbPage"));

        horizontalLayout->addWidget(lbPage);

        btnNext = new QPushButton(wPrint);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        btnNext->setMinimumSize(QSize(30, 30));
        btnNext->setMaximumSize(QSize(30, 30));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/right-arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNext->setIcon(icon8);
        btnNext->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(btnNext);

        btnLast = new QPushButton(wPrint);
        btnLast->setObjectName(QString::fromUtf8("btnLast"));
        btnLast->setMinimumSize(QSize(30, 30));
        btnLast->setMaximumSize(QSize(30, 30));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/double-right.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLast->setIcon(icon9);
        btnLast->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(btnLast);

        btnZoomOut = new QPushButton(wPrint);
        btnZoomOut->setObjectName(QString::fromUtf8("btnZoomOut"));
        btnZoomOut->setMinimumSize(QSize(30, 30));
        btnZoomOut->setMaximumSize(QSize(30, 30));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/zoom-out.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnZoomOut->setIcon(icon10);
        btnZoomOut->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(btnZoomOut);

        btnZoopIn = new QPushButton(wPrint);
        btnZoopIn->setObjectName(QString::fromUtf8("btnZoopIn"));
        btnZoopIn->setMinimumSize(QSize(30, 30));
        btnZoopIn->setMaximumSize(QSize(30, 30));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/zoom-in.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnZoopIn->setIcon(icon11);
        btnZoopIn->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(btnZoopIn);

        cbZoom = new QComboBox(wPrint);
        cbZoom->addItem(QString());
        cbZoom->addItem(QString());
        cbZoom->addItem(QString());
        cbZoom->addItem(QString());
        cbZoom->addItem(QString());
        cbZoom->addItem(QString());
        cbZoom->addItem(QString());
        cbZoom->addItem(QString());
        cbZoom->setObjectName(QString::fromUtf8("cbZoom"));

        horizontalLayout->addWidget(cbZoom);

        label_2 = new QLabel(wPrint);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        cbPrintSelection = new QComboBox(wPrint);
        cbPrintSelection->addItem(QString());
        cbPrintSelection->addItem(QString());
        cbPrintSelection->addItem(QString());
        cbPrintSelection->setObjectName(QString::fromUtf8("cbPrintSelection"));

        horizontalLayout->addWidget(cbPrintSelection);

        lePages = new QLineEdit(wPrint);
        lePages->setObjectName(QString::fromUtf8("lePages"));
        lePages->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(lePages);

        cbPrinters = new QComboBox(wPrint);
        cbPrinters->setObjectName(QString::fromUtf8("cbPrinters"));
        cbPrinters->setMinimumSize(QSize(200, 0));

        horizontalLayout->addWidget(cbPrinters);


        horizontalLayout_2->addWidget(wPrint);

        spacer = new QSpacerItem(986, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(spacer);

        label = new QLabel(wToolbar);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        leQuickSearch = new QLineEdit(wToolbar);
        leQuickSearch->setObjectName(QString::fromUtf8("leQuickSearch"));
        leQuickSearch->setMinimumSize(QSize(200, 0));
        leQuickSearch->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_2->addWidget(leQuickSearch);

        btnClearQuickSearch = new QPushButton(wToolbar);
        btnClearQuickSearch->setObjectName(QString::fromUtf8("btnClearQuickSearch"));
        btnClearQuickSearch->setMinimumSize(QSize(22, 22));
        btnClearQuickSearch->setMaximumSize(QSize(22, 22));
        btnClearQuickSearch->setFocusPolicy(Qt::NoFocus);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/remove_filter.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClearQuickSearch->setIcon(icon12);
        btnClearQuickSearch->setIconSize(QSize(12, 12));

        horizontalLayout_2->addWidget(btnClearQuickSearch);


        verticalLayout->addWidget(wToolbar);

        hl = new QHBoxLayout();
        hl->setObjectName(QString::fromUtf8("hl"));
        hl->setSizeConstraint(QLayout::SetFixedSize);
        hl->setContentsMargins(-1, 8, -1, -1);

        verticalLayout->addLayout(hl);

        scrollArea = new QScrollArea(WReportGrid);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1817, 69));
        gv = new QGraphicsView(scrollAreaWidgetContents);
        gv->setObjectName(QString::fromUtf8("gv"));
        gv->setGeometry(QRect(240, 30, 256, 192));
        gv->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        gv->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        tblMain = new QTableView(WReportGrid);
        tblMain->setObjectName(QString::fromUtf8("tblMain"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(tblMain->sizePolicy().hasHeightForWidth());
        tblMain->setSizePolicy(sizePolicy2);
        tblMain->setFocusPolicy(Qt::ClickFocus);
        tblMain->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tblMain->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblMain->setWordWrap(false);
        tblMain->verticalHeader()->setMinimumSectionSize(10);
        tblMain->verticalHeader()->setDefaultSectionSize(21);

        verticalLayout->addWidget(tblMain);

        tblTotals = new EQTableWidget(WReportGrid);
        if (tblTotals->rowCount() < 1)
            tblTotals->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblTotals->setVerticalHeaderItem(0, __qtablewidgetitem);
        tblTotals->setObjectName(QString::fromUtf8("tblTotals"));
        sizePolicy2.setHeightForWidth(tblTotals->sizePolicy().hasHeightForWidth());
        tblTotals->setSizePolicy(sizePolicy2);
        tblTotals->setMaximumSize(QSize(16777215, 50));
        tblTotals->setFocusPolicy(Qt::NoFocus);
        tblTotals->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tblTotals->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tblTotals->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblTotals->horizontalHeader()->setVisible(false);

        verticalLayout->addWidget(tblTotals);


        retranslateUi(WReportGrid);

        cbZoom->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(WReportGrid);
    } // setupUi

    void retranslateUi(QWidget *WReportGrid)
    {
        WReportGrid->setWindowTitle(QCoreApplication::translate("WReportGrid", "Form", nullptr));
        btnNew->setText(QCoreApplication::translate("WReportGrid", "New", nullptr));
        btnPrint->setText(QCoreApplication::translate("WReportGrid", "Print", nullptr));
        btnPrint2->setText(QCoreApplication::translate("WReportGrid", "Print", nullptr));
        btnConfigGrid->setText(QCoreApplication::translate("WReportGrid", "Options", nullptr));
        btnExcel->setText(QCoreApplication::translate("WReportGrid", "Excel", nullptr));
        btnRefresh->setText(QCoreApplication::translate("WReportGrid", "Refresh", nullptr));
        btnHelp->setText(QCoreApplication::translate("WReportGrid", "Help", nullptr));
        btnFirst->setText(QString());
        btnBack->setText(QString());
        lbPage->setText(QCoreApplication::translate("WReportGrid", "Page 1 of 1", nullptr));
        btnNext->setText(QString());
        btnLast->setText(QString());
        btnZoomOut->setText(QString());
        btnZoopIn->setText(QString());
        cbZoom->setItemText(0, QCoreApplication::translate("WReportGrid", "200%", nullptr));
        cbZoom->setItemText(1, QCoreApplication::translate("WReportGrid", "175%", nullptr));
        cbZoom->setItemText(2, QCoreApplication::translate("WReportGrid", "150%", nullptr));
        cbZoom->setItemText(3, QCoreApplication::translate("WReportGrid", "125%", nullptr));
        cbZoom->setItemText(4, QCoreApplication::translate("WReportGrid", "100%", nullptr));
        cbZoom->setItemText(5, QCoreApplication::translate("WReportGrid", "75%", nullptr));
        cbZoom->setItemText(6, QCoreApplication::translate("WReportGrid", "50%", nullptr));
        cbZoom->setItemText(7, QCoreApplication::translate("WReportGrid", "25%", nullptr));

        label_2->setText(QCoreApplication::translate("WReportGrid", "Print", nullptr));
        cbPrintSelection->setItemText(0, QCoreApplication::translate("WReportGrid", "All pages", nullptr));
        cbPrintSelection->setItemText(1, QCoreApplication::translate("WReportGrid", "Current page", nullptr));
        cbPrintSelection->setItemText(2, QCoreApplication::translate("WReportGrid", "Custom", nullptr));

        label->setText(QCoreApplication::translate("WReportGrid", "Quick search", nullptr));
        btnClearQuickSearch->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tblTotals->verticalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WReportGrid", "New Row", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WReportGrid: public Ui_WReportGrid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WREPORTGRID_H
