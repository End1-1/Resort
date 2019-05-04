#ifndef CHARDEFAULTS_H
#define CHARDEFAULTS_H

#include <QColor>
#include <QDate>
#include <QSettings>

static QSettings  __ss("SmartHotel", "SmartHotel");

static const int COLUMN_WIDTH = 25;
static const int ROW_HEIGHT = 22;

static QColor ROOM_RECT_BACKGROUND[][2] = {
    {Qt::white, Qt::white},
    {static_cast<QColor>(__ss.value("checkincolor", -16733441).toInt()), QColor::fromRgb(70, 170, 255)},
    {QColor::fromRgb(255, 255, 0), QColor::fromRgb(255, 255, 150)},
    {QColor::fromRgb(88, 88, 88), QColor::fromRgb(170, 170, 170)}, // o/o
    {Qt::white, Qt::white},
    {Qt::white, Qt::white},
    {Qt::white, Qt::white}, // o/i
    {Qt::white, Qt::white},
    {Qt::white, Qt::white},
    {Qt::white, Qt::white}
};


static const QColor LIGHT_GRAY = QColor::fromRgb(72, 72, 72);
static const QColor VSELECTION_COLOR = QColor::fromRgb(0, 255, 0, 100);
static const QColor HSELECTION_COLOR = QColor::fromRgb(255, 0, 0, 200);
extern QDate ChartStartDate;

QDate dateFromX(int x);
int xFromDate(const QDate &date);
int rowFromY(int y);

#endif // CHARDEFAULTS_H
