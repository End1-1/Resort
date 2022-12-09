/********************************************************************************
** Form generated from reading UI file 'roomstate.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMSTATE_H
#define UI_ROOMSTATE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_RoomState
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    EQLineEdit *leCurrentStateName;
    EQLineEdit *leNewState;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    EQLineEdit *leRoomCode;
    EQLineEdit *leCurrentState;
    EQLineEdit *leRoomName;
    EQLineEdit *leNewStateName;
    QLabel *label_3;
    QWidget *wdtOut;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *lbOO;
    QLabel *label_6;
    EDateEdit *deEnd;
    EDateEdit *deStart;
    QPlainTextEdit *teRemarks;
    QLabel *lbStatus;
    QToolButton *btnSticky;
    QPushButton *btnWhy;

    void setupUi(QDialog *RoomState)
    {
        if (RoomState->objectName().isEmpty())
            RoomState->setObjectName(QString::fromUtf8("RoomState"));
        RoomState->resize(325, 326);
        horizontalLayout_2 = new QHBoxLayout(RoomState);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leCurrentStateName = new EQLineEdit(RoomState);
        leCurrentStateName->setObjectName(QString::fromUtf8("leCurrentStateName"));
        leCurrentStateName->setFocusPolicy(Qt::NoFocus);
        leCurrentStateName->setReadOnly(true);

        gridLayout->addWidget(leCurrentStateName, 1, 2, 1, 1);

        leNewState = new EQLineEdit(RoomState);
        leNewState->setObjectName(QString::fromUtf8("leNewState"));
        leNewState->setMaximumSize(QSize(40, 16777215));

        gridLayout->addWidget(leNewState, 2, 1, 1, 1);

        label = new QLabel(RoomState);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        widget = new QWidget(RoomState);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(57, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(56, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 4, 0, 1, 3);

        label_2 = new QLabel(RoomState);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        leRoomCode = new EQLineEdit(RoomState);
        leRoomCode->setObjectName(QString::fromUtf8("leRoomCode"));
        leRoomCode->setMaximumSize(QSize(40, 16777215));
        leRoomCode->setFocusPolicy(Qt::NoFocus);
        leRoomCode->setContextMenuPolicy(Qt::NoContextMenu);
        leRoomCode->setReadOnly(false);

        gridLayout->addWidget(leRoomCode, 0, 1, 1, 1);

        leCurrentState = new EQLineEdit(RoomState);
        leCurrentState->setObjectName(QString::fromUtf8("leCurrentState"));
        leCurrentState->setMaximumSize(QSize(40, 16777215));
        leCurrentState->setFocusPolicy(Qt::NoFocus);
        leCurrentState->setReadOnly(true);

        gridLayout->addWidget(leCurrentState, 1, 1, 1, 1);

        leRoomName = new EQLineEdit(RoomState);
        leRoomName->setObjectName(QString::fromUtf8("leRoomName"));
        leRoomName->setFocusPolicy(Qt::NoFocus);
        leRoomName->setReadOnly(true);

        gridLayout->addWidget(leRoomName, 0, 2, 1, 1);

        leNewStateName = new EQLineEdit(RoomState);
        leNewStateName->setObjectName(QString::fromUtf8("leNewStateName"));
        leNewStateName->setFocusPolicy(Qt::NoFocus);
        leNewStateName->setReadOnly(true);

        gridLayout->addWidget(leNewStateName, 2, 2, 1, 1);

        label_3 = new QLabel(RoomState);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        wdtOut = new QWidget(RoomState);
        wdtOut->setObjectName(QString::fromUtf8("wdtOut"));
        gridLayout_2 = new QGridLayout(wdtOut);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_4 = new QLabel(wdtOut);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(wdtOut);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        lbOO = new QLabel(wdtOut);
        lbOO->setObjectName(QString::fromUtf8("lbOO"));

        gridLayout_2->addWidget(lbOO, 2, 1, 1, 1);

        label_6 = new QLabel(wdtOut);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        deEnd = new EDateEdit(wdtOut);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        gridLayout_2->addWidget(deEnd, 1, 1, 1, 2);

        deStart = new EDateEdit(wdtOut);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        gridLayout_2->addWidget(deStart, 0, 1, 1, 2);

        teRemarks = new QPlainTextEdit(wdtOut);
        teRemarks->setObjectName(QString::fromUtf8("teRemarks"));

        gridLayout_2->addWidget(teRemarks, 3, 1, 1, 2);


        gridLayout->addWidget(wdtOut, 3, 0, 1, 3);

        lbStatus = new QLabel(RoomState);
        lbStatus->setObjectName(QString::fromUtf8("lbStatus"));
        lbStatus->setCursor(QCursor(Qt::PointingHandCursor));
        lbStatus->setPixmap(QPixmap(QString::fromUtf8(":/images/ball-green.png")));

        gridLayout->addWidget(lbStatus, 1, 3, 1, 1);

        btnSticky = new QToolButton(RoomState);
        btnSticky->setObjectName(QString::fromUtf8("btnSticky"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/sticky.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSticky->setIcon(icon);
        btnSticky->setCheckable(true);
        btnSticky->setChecked(false);

        gridLayout->addWidget(btnSticky, 0, 3, 1, 1);

        btnWhy = new QPushButton(RoomState);
        btnWhy->setObjectName(QString::fromUtf8("btnWhy"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnWhy->sizePolicy().hasHeightForWidth());
        btnWhy->setSizePolicy(sizePolicy);
        btnWhy->setMaximumSize(QSize(40, 40));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/question.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnWhy->setIcon(icon1);

        gridLayout->addWidget(btnWhy, 2, 3, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        QWidget::setTabOrder(leNewState, deStart);
        QWidget::setTabOrder(deStart, deEnd);
        QWidget::setTabOrder(deEnd, teRemarks);
        QWidget::setTabOrder(teRemarks, btnOk);
        QWidget::setTabOrder(btnOk, btnCancel);

        retranslateUi(RoomState);

        QMetaObject::connectSlotsByName(RoomState);
    } // setupUi

    void retranslateUi(QDialog *RoomState)
    {
        RoomState->setWindowTitle(QCoreApplication::translate("RoomState", "Room state", nullptr));
        label->setText(QCoreApplication::translate("RoomState", "Current state", nullptr));
        btnOk->setText(QCoreApplication::translate("RoomState", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("RoomState", "Cancel", nullptr));
        label_2->setText(QCoreApplication::translate("RoomState", "New state", nullptr));
        label_3->setText(QCoreApplication::translate("RoomState", "Room", nullptr));
        label_4->setText(QCoreApplication::translate("RoomState", "From", nullptr));
        label_5->setText(QCoreApplication::translate("RoomState", "To", nullptr));
        lbOO->setText(QCoreApplication::translate("RoomState", "OK", nullptr));
        label_6->setText(QCoreApplication::translate("RoomState", "State", nullptr));
        teRemarks->setPlaceholderText(QCoreApplication::translate("RoomState", "Remarks", nullptr));
        lbStatus->setText(QString());
        btnSticky->setText(QString());
        btnWhy->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RoomState: public Ui_RoomState {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMSTATE_H
