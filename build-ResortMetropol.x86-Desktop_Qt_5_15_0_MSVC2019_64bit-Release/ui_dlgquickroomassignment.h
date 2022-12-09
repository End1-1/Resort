/********************************************************************************
** Form generated from reading UI file 'dlgquickroomassignment.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGQUICKROOMASSIGNMENT_H
#define UI_DLGQUICKROOMASSIGNMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgQuickRoomAssignment
{
public:
    QGridLayout *gridLayout;
    EQLineEdit *letoRoom;
    QLabel *lbto;
    EQLineEdit *letoGuest;
    QLabel *label_3;
    EDateEdit *deEntry;
    EQLineEdit *lefrRoom;
    EDateEdit *deDeparture;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *lbfr;
    EQLineEdit *lefrGuest;
    QLabel *label_5;
    QLineEdit *leReserve;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *leInvoice;

    void setupUi(QDialog *DlgQuickRoomAssignment)
    {
        if (DlgQuickRoomAssignment->objectName().isEmpty())
            DlgQuickRoomAssignment->setObjectName(QString::fromUtf8("DlgQuickRoomAssignment"));
        DlgQuickRoomAssignment->resize(636, 199);
        gridLayout = new QGridLayout(DlgQuickRoomAssignment);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        letoRoom = new EQLineEdit(DlgQuickRoomAssignment);
        letoRoom->setObjectName(QString::fromUtf8("letoRoom"));
        letoRoom->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(letoRoom, 4, 1, 1, 1);

        lbto = new QLabel(DlgQuickRoomAssignment);
        lbto->setObjectName(QString::fromUtf8("lbto"));
        lbto->setMaximumSize(QSize(25, 25));
        lbto->setPixmap(QPixmap(QString::fromUtf8(":/images/remarks.png")));
        lbto->setScaledContents(true);
        lbto->setWordWrap(false);

        gridLayout->addWidget(lbto, 4, 3, 1, 1);

        letoGuest = new EQLineEdit(DlgQuickRoomAssignment);
        letoGuest->setObjectName(QString::fromUtf8("letoGuest"));
        letoGuest->setFocusPolicy(Qt::ClickFocus);
        letoGuest->setReadOnly(true);

        gridLayout->addWidget(letoGuest, 4, 2, 1, 1);

        label_3 = new QLabel(DlgQuickRoomAssignment);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        deEntry = new EDateEdit(DlgQuickRoomAssignment);
        deEntry->setObjectName(QString::fromUtf8("deEntry"));
        deEntry->setMaximumSize(QSize(100, 16777215));
        deEntry->setFocusPolicy(Qt::ClickFocus);
        deEntry->setReadOnly(true);

        gridLayout->addWidget(deEntry, 2, 1, 1, 1);

        lefrRoom = new EQLineEdit(DlgQuickRoomAssignment);
        lefrRoom->setObjectName(QString::fromUtf8("lefrRoom"));
        lefrRoom->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(lefrRoom, 0, 1, 1, 1);

        deDeparture = new EDateEdit(DlgQuickRoomAssignment);
        deDeparture->setObjectName(QString::fromUtf8("deDeparture"));
        deDeparture->setMaximumSize(QSize(100, 16777215));
        deDeparture->setFocusPolicy(Qt::ClickFocus);
        deDeparture->setReadOnly(true);

        gridLayout->addWidget(deDeparture, 3, 1, 1, 1);

        label = new QLabel(DlgQuickRoomAssignment);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(DlgQuickRoomAssignment);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_2 = new QLabel(DlgQuickRoomAssignment);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        lbfr = new QLabel(DlgQuickRoomAssignment);
        lbfr->setObjectName(QString::fromUtf8("lbfr"));
        lbfr->setMaximumSize(QSize(25, 25));
        lbfr->setPixmap(QPixmap(QString::fromUtf8(":/images/remarks.png")));
        lbfr->setScaledContents(true);

        gridLayout->addWidget(lbfr, 0, 3, 1, 1);

        lefrGuest = new EQLineEdit(DlgQuickRoomAssignment);
        lefrGuest->setObjectName(QString::fromUtf8("lefrGuest"));
        lefrGuest->setFocusPolicy(Qt::ClickFocus);
        lefrGuest->setReadOnly(true);

        gridLayout->addWidget(lefrGuest, 0, 2, 1, 1);

        label_5 = new QLabel(DlgQuickRoomAssignment);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFocusPolicy(Qt::StrongFocus);

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        leReserve = new QLineEdit(DlgQuickRoomAssignment);
        leReserve->setObjectName(QString::fromUtf8("leReserve"));
        leReserve->setMaximumSize(QSize(100, 16777215));
        leReserve->setFocusPolicy(Qt::ClickFocus);
        leReserve->setReadOnly(true);

        gridLayout->addWidget(leReserve, 1, 1, 1, 1);

        widget = new QWidget(DlgQuickRoomAssignment);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(213, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(213, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 5, 0, 1, 4);

        leInvoice = new QLineEdit(DlgQuickRoomAssignment);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));
        leInvoice->setFocusPolicy(Qt::ClickFocus);
        leInvoice->setReadOnly(true);

        gridLayout->addWidget(leInvoice, 1, 2, 1, 1);

        QWidget::setTabOrder(lefrRoom, letoRoom);
        QWidget::setTabOrder(letoRoom, btnSave);
        QWidget::setTabOrder(btnSave, btnCancel);

        retranslateUi(DlgQuickRoomAssignment);

        QMetaObject::connectSlotsByName(DlgQuickRoomAssignment);
    } // setupUi

    void retranslateUi(QDialog *DlgQuickRoomAssignment)
    {
        DlgQuickRoomAssignment->setWindowTitle(QCoreApplication::translate("DlgQuickRoomAssignment", "Quick room assignment", nullptr));
        lbto->setText(QString());
        label_3->setText(QCoreApplication::translate("DlgQuickRoomAssignment", "Entry", nullptr));
        label->setText(QCoreApplication::translate("DlgQuickRoomAssignment", "From room", nullptr));
        label_4->setText(QCoreApplication::translate("DlgQuickRoomAssignment", "Departure", nullptr));
        label_2->setText(QCoreApplication::translate("DlgQuickRoomAssignment", "To room", nullptr));
        lbfr->setText(QString());
        label_5->setText(QCoreApplication::translate("DlgQuickRoomAssignment", "Reservatin code", nullptr));
        btnSave->setText(QCoreApplication::translate("DlgQuickRoomAssignment", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgQuickRoomAssignment", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgQuickRoomAssignment: public Ui_DlgQuickRoomAssignment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGQUICKROOMASSIGNMENT_H
