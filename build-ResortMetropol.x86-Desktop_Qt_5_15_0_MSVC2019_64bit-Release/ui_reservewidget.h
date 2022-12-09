/********************************************************************************
** Form generated from reading UI file 'reservewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESERVEWIDGET_H
#define UI_RESERVEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReserveWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbCaption;
    QPushButton *btnCancel;

    void setupUi(QWidget *ReserveWidget)
    {
        if (ReserveWidget->objectName().isEmpty())
            ReserveWidget->setObjectName(QString::fromUtf8("ReserveWidget"));
        ReserveWidget->setWindowModality(Qt::WindowModal);
        ReserveWidget->resize(94, 23);
        ReserveWidget->setMinimumSize(QSize(0, 23));
        ReserveWidget->setMaximumSize(QSize(16777215, 23));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(204, 204, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        ReserveWidget->setPalette(palette);
        ReserveWidget->setAutoFillBackground(false);
        horizontalLayout = new QHBoxLayout(ReserveWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(ReserveWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lbCaption = new QLabel(frame);
        lbCaption->setObjectName(QString::fromUtf8("lbCaption"));
        lbCaption->setMaximumSize(QSize(5555, 16777215));
        QFont font;
        font.setPointSize(6);
        lbCaption->setFont(font);
        lbCaption->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lbCaption);

        btnCancel = new QPushButton(frame);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMinimumSize(QSize(22, 22));
        btnCancel->setMaximumSize(QSize(22, 22));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancel->setIcon(icon);
        btnCancel->setIconSize(QSize(12, 12));

        horizontalLayout_2->addWidget(btnCancel);


        horizontalLayout->addWidget(frame);


        retranslateUi(ReserveWidget);

        QMetaObject::connectSlotsByName(ReserveWidget);
    } // setupUi

    void retranslateUi(QWidget *ReserveWidget)
    {
        ReserveWidget->setWindowTitle(QCoreApplication::translate("ReserveWidget", "Form", nullptr));
        lbCaption->setText(QCoreApplication::translate("ReserveWidget", "#404\n"
"01,Sun-02,Sat", nullptr));
        btnCancel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ReserveWidget: public Ui_ReserveWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESERVEWIDGET_H
