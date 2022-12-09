/********************************************************************************
** Form generated from reading UI file 'fcityledgerdetailedbalance.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCITYLEDGERDETAILEDBALANCE_H
#define UI_FCITYLEDGERDETAILEDBALANCE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_FCityLedgerDetailedBalance
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QToolButton *btnPrevDate;
    EDateEdit *deFrom;
    QLabel *label;
    EDateEdit *deTo;
    QToolButton *btnNextDate;
    QFrame *line;
    QLabel *label_3;
    EQLineEdit *leCLCode;
    EQLineEdit *leCL;
    QToolButton *btnChangeCityLedger;
    QLabel *label_4;
    EQLineEdit *leCardex;
    EQLineEdit *leCardexName;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FCityLedgerDetailedBalance)
    {
        if (FCityLedgerDetailedBalance->objectName().isEmpty())
            FCityLedgerDetailedBalance->setObjectName(QString::fromUtf8("FCityLedgerDetailedBalance"));
        FCityLedgerDetailedBalance->resize(757, 24);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FCityLedgerDetailedBalance->sizePolicy().hasHeightForWidth());
        FCityLedgerDetailedBalance->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(FCityLedgerDetailedBalance);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(FCityLedgerDetailedBalance);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        btnPrevDate = new QToolButton(FCityLedgerDetailedBalance);
        btnPrevDate->setObjectName(QString::fromUtf8("btnPrevDate"));
        btnPrevDate->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrevDate->setIcon(icon);

        horizontalLayout->addWidget(btnPrevDate);

        deFrom = new EDateEdit(FCityLedgerDetailedBalance);
        deFrom->setObjectName(QString::fromUtf8("deFrom"));

        horizontalLayout->addWidget(deFrom);

        label = new QLabel(FCityLedgerDetailedBalance);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        deTo = new EDateEdit(FCityLedgerDetailedBalance);
        deTo->setObjectName(QString::fromUtf8("deTo"));

        horizontalLayout->addWidget(deTo);

        btnNextDate = new QToolButton(FCityLedgerDetailedBalance);
        btnNextDate->setObjectName(QString::fromUtf8("btnNextDate"));
        btnNextDate->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNextDate->setIcon(icon1);

        horizontalLayout->addWidget(btnNextDate);

        line = new QFrame(FCityLedgerDetailedBalance);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        label_3 = new QLabel(FCityLedgerDetailedBalance);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        leCLCode = new EQLineEdit(FCityLedgerDetailedBalance);
        leCLCode->setObjectName(QString::fromUtf8("leCLCode"));
        leCLCode->setMaximumSize(QSize(90, 16777215));
        leCLCode->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout->addWidget(leCLCode);

        leCL = new EQLineEdit(FCityLedgerDetailedBalance);
        leCL->setObjectName(QString::fromUtf8("leCL"));
        leCL->setFocusPolicy(Qt::ClickFocus);
        leCL->setReadOnly(true);
        leCL->setProperty("EnableHiddenText", QVariant(false));

        horizontalLayout->addWidget(leCL);

        btnChangeCityLedger = new QToolButton(FCityLedgerDetailedBalance);
        btnChangeCityLedger->setObjectName(QString::fromUtf8("btnChangeCityLedger"));
        btnChangeCityLedger->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/draft.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnChangeCityLedger->setIcon(icon2);

        horizontalLayout->addWidget(btnChangeCityLedger);

        label_4 = new QLabel(FCityLedgerDetailedBalance);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        leCardex = new EQLineEdit(FCityLedgerDetailedBalance);
        leCardex->setObjectName(QString::fromUtf8("leCardex"));
        leCardex->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(leCardex);

        leCardexName = new EQLineEdit(FCityLedgerDetailedBalance);
        leCardexName->setObjectName(QString::fromUtf8("leCardexName"));
        leCardexName->setReadOnly(true);

        horizontalLayout->addWidget(leCardexName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FCityLedgerDetailedBalance);

        QMetaObject::connectSlotsByName(FCityLedgerDetailedBalance);
    } // setupUi

    void retranslateUi(QWidget *FCityLedgerDetailedBalance)
    {
        FCityLedgerDetailedBalance->setWindowTitle(QCoreApplication::translate("FCityLedgerDetailedBalance", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("FCityLedgerDetailedBalance", "From", nullptr));
        btnPrevDate->setText(QCoreApplication::translate("FCityLedgerDetailedBalance", "...", nullptr));
        label->setText(QCoreApplication::translate("FCityLedgerDetailedBalance", "To", nullptr));
        btnNextDate->setText(QCoreApplication::translate("FCityLedgerDetailedBalance", "...", nullptr));
        label_3->setText(QCoreApplication::translate("FCityLedgerDetailedBalance", "City ledger", nullptr));
        btnChangeCityLedger->setText(QCoreApplication::translate("FCityLedgerDetailedBalance", "...", nullptr));
        label_4->setText(QCoreApplication::translate("FCityLedgerDetailedBalance", "Cardex", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FCityLedgerDetailedBalance: public Ui_FCityLedgerDetailedBalance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCITYLEDGERDETAILEDBALANCE_H
