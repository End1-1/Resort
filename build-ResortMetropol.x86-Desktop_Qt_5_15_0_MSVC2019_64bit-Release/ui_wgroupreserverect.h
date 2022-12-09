/********************************************************************************
** Form generated from reading UI file 'wgroupreserverect.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGROUPRESERVERECT_H
#define UI_WGROUPRESERVERECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WGroupReserveRect
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *chSelected;
    QLabel *lbRoom;

    void setupUi(QWidget *WGroupReserveRect)
    {
        if (WGroupReserveRect->objectName().isEmpty())
            WGroupReserveRect->setObjectName(QString::fromUtf8("WGroupReserveRect"));
        WGroupReserveRect->resize(80, 36);
        WGroupReserveRect->setMinimumSize(QSize(80, 35));
        WGroupReserveRect->setMaximumSize(QSize(80, 37));
        QFont font;
        font.setPointSize(8);
        WGroupReserveRect->setFont(font);
        WGroupReserveRect->setAutoFillBackground(true);
        horizontalLayout = new QHBoxLayout(WGroupReserveRect);
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(WGroupReserveRect);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("QFrame#frame {border: 1px solid gray;}"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(2, 0, 2, 0);
        chSelected = new QCheckBox(frame);
        chSelected->setObjectName(QString::fromUtf8("chSelected"));

        horizontalLayout_2->addWidget(chSelected);

        lbRoom = new QLabel(frame);
        lbRoom->setObjectName(QString::fromUtf8("lbRoom"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbRoom->sizePolicy().hasHeightForWidth());
        lbRoom->setSizePolicy(sizePolicy);
        lbRoom->setMinimumSize(QSize(0, 0));
        lbRoom->setMaximumSize(QSize(100000, 100000));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        lbRoom->setFont(font1);
        lbRoom->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lbRoom);


        horizontalLayout->addWidget(frame);


        retranslateUi(WGroupReserveRect);

        QMetaObject::connectSlotsByName(WGroupReserveRect);
    } // setupUi

    void retranslateUi(QWidget *WGroupReserveRect)
    {
        WGroupReserveRect->setWindowTitle(QCoreApplication::translate("WGroupReserveRect", "Form", nullptr));
        chSelected->setText(QString());
        lbRoom->setText(QCoreApplication::translate("WGroupReserveRect", "#101\n"
"CS CV L", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WGroupReserveRect: public Ui_WGroupReserveRect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGROUPRESERVERECT_H
