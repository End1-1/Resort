/********************************************************************************
** Form generated from reading UI file 'faccmonthlyreport.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACCMONTHLYREPORT_H
#define UI_FACCMONTHLYREPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqcombobox.h>
#include <eyearcombo.h>

QT_BEGIN_NAMESPACE

class Ui_FAccMonthlyReport
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    EDateEdit *deStart;
    QLabel *label_2;
    EDateEdit *deEnd;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QRadioButton *rbDay;
    QRadioButton *rbWeek;
    QRadioButton *rbMonth;
    QRadioButton *rbYear;
    QFrame *line;
    QLabel *label_4;
    EYearCombo *cbYear;
    EQComboBox *cbMonth;
    QSpacerItem *horizontalSpacer;
    QCheckBox *chCanceled;

    void setupUi(QWidget *FAccMonthlyReport)
    {
        if (FAccMonthlyReport->objectName().isEmpty())
            FAccMonthlyReport->setObjectName(QString::fromUtf8("FAccMonthlyReport"));
        FAccMonthlyReport->resize(804, 40);
        verticalLayout = new QVBoxLayout(FAccMonthlyReport);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(FAccMonthlyReport);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        deStart = new EDateEdit(FAccMonthlyReport);
        deStart->setObjectName(QString::fromUtf8("deStart"));
        deStart->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(deStart);

        label_2 = new QLabel(FAccMonthlyReport);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        deEnd = new EDateEdit(FAccMonthlyReport);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));
        deEnd->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(deEnd);

        widget = new QWidget(FAccMonthlyReport);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        rbDay = new QRadioButton(widget);
        rbDay->setObjectName(QString::fromUtf8("rbDay"));
        rbDay->setFocusPolicy(Qt::ClickFocus);
        rbDay->setChecked(true);

        horizontalLayout->addWidget(rbDay);

        rbWeek = new QRadioButton(widget);
        rbWeek->setObjectName(QString::fromUtf8("rbWeek"));
        rbWeek->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(rbWeek);

        rbMonth = new QRadioButton(widget);
        rbMonth->setObjectName(QString::fromUtf8("rbMonth"));
        rbMonth->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(rbMonth);

        rbYear = new QRadioButton(widget);
        rbYear->setObjectName(QString::fromUtf8("rbYear"));
        rbYear->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(rbYear);

        line = new QFrame(widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);


        horizontalLayout_2->addWidget(widget);

        label_4 = new QLabel(FAccMonthlyReport);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        cbYear = new EYearCombo(FAccMonthlyReport);
        cbYear->setObjectName(QString::fromUtf8("cbYear"));
        cbYear->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_2->addWidget(cbYear);

        cbMonth = new EQComboBox(FAccMonthlyReport);
        cbMonth->addItem(QString());
        cbMonth->addItem(QString());
        cbMonth->addItem(QString());
        cbMonth->addItem(QString());
        cbMonth->addItem(QString());
        cbMonth->addItem(QString());
        cbMonth->addItem(QString());
        cbMonth->addItem(QString());
        cbMonth->addItem(QString());
        cbMonth->addItem(QString());
        cbMonth->addItem(QString());
        cbMonth->addItem(QString());
        cbMonth->setObjectName(QString::fromUtf8("cbMonth"));
        cbMonth->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_2->addWidget(cbMonth);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        chCanceled = new QCheckBox(FAccMonthlyReport);
        chCanceled->setObjectName(QString::fromUtf8("chCanceled"));
        chCanceled->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_2->addWidget(chCanceled);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(FAccMonthlyReport);

        QMetaObject::connectSlotsByName(FAccMonthlyReport);
    } // setupUi

    void retranslateUi(QWidget *FAccMonthlyReport)
    {
        FAccMonthlyReport->setWindowTitle(QCoreApplication::translate("FAccMonthlyReport", "Form", nullptr));
        label->setText(QCoreApplication::translate("FAccMonthlyReport", "Start", nullptr));
        label_2->setText(QCoreApplication::translate("FAccMonthlyReport", "End", nullptr));
        label_3->setText(QCoreApplication::translate("FAccMonthlyReport", "Group by", nullptr));
        rbDay->setText(QCoreApplication::translate("FAccMonthlyReport", "Day", nullptr));
        rbWeek->setText(QCoreApplication::translate("FAccMonthlyReport", "Week", nullptr));
        rbMonth->setText(QCoreApplication::translate("FAccMonthlyReport", "Month", nullptr));
        rbYear->setText(QCoreApplication::translate("FAccMonthlyReport", "Year", nullptr));
        label_4->setText(QCoreApplication::translate("FAccMonthlyReport", "Set date for", nullptr));
        cbYear->setCurrentText(QString());
        cbMonth->setItemText(0, QCoreApplication::translate("FAccMonthlyReport", "January", nullptr));
        cbMonth->setItemText(1, QCoreApplication::translate("FAccMonthlyReport", "February", nullptr));
        cbMonth->setItemText(2, QCoreApplication::translate("FAccMonthlyReport", "Mart", nullptr));
        cbMonth->setItemText(3, QCoreApplication::translate("FAccMonthlyReport", "April", nullptr));
        cbMonth->setItemText(4, QCoreApplication::translate("FAccMonthlyReport", "May", nullptr));
        cbMonth->setItemText(5, QCoreApplication::translate("FAccMonthlyReport", "June", nullptr));
        cbMonth->setItemText(6, QCoreApplication::translate("FAccMonthlyReport", "July", nullptr));
        cbMonth->setItemText(7, QCoreApplication::translate("FAccMonthlyReport", "August", nullptr));
        cbMonth->setItemText(8, QCoreApplication::translate("FAccMonthlyReport", "September", nullptr));
        cbMonth->setItemText(9, QCoreApplication::translate("FAccMonthlyReport", "October", nullptr));
        cbMonth->setItemText(10, QCoreApplication::translate("FAccMonthlyReport", "November", nullptr));
        cbMonth->setItemText(11, QCoreApplication::translate("FAccMonthlyReport", "December", nullptr));

        chCanceled->setText(QCoreApplication::translate("FAccMonthlyReport", "Canceled", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FAccMonthlyReport: public Ui_FAccMonthlyReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACCMONTHLYREPORT_H
