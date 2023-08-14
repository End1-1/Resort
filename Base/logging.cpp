#include "logging.h"

#include <QFile>
#include <QDateTime>
#include <QDir>
#include <QDebug>
#include <QMessageBox>

bool logEnabled = false;
QElapsedTimer timer;

logging::logging()
{

}

void logging::justLog(const QString &text)
{
    qDebug() << text;
    QDir d;
    QString logFile = d.homePath() + "/" + _APPLICATION_ + "/log.txt";
    QFile f(logFile);
    if (f.open(QIODevice::Append)) {
        QString fullText = QString("%1: %3\r\n").arg(QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss")).arg(text);
        f.write(fullText.toUtf8());
        f.close();
    } else {
        QMessageBox::critical(0, "Error", "Cannot write log");
    }
}


void logging::writeLog(const QString &text)
{
    if (!logEnabled) {
        return;
    }
    quint64 e = timer.elapsed();
    timer.restart();
    qDebug() << e << text;
    QDir d;
    QString logFile = d.homePath() + "/" + _APPLICATION_ + "/log.txt";
    QFile f(logFile);
    if (f.open(QIODevice::Append)) {
        QString fullText = QString("%1 %2: %3\r\n").arg(e).arg(QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss")).arg(text);
        f.write(fullText.toUtf8());
        f.close();
    } else {
        QMessageBox::critical(0, "Error", "Cannot write log");
    }
}

void logging::writeLog(const QString &text, QElapsedTimer &t)
{
    if (!logEnabled) {
        return;
    }
    quint64 e = t.elapsed();
    t.restart();
    qDebug() << e << text;
    timer.restart();
    QDir d;
    QString logFile = d.homePath() + "/" + _APPLICATION_ + "/log.txt";
    QFile f(logFile);
    if (f.open(QIODevice::Append)) {
        QString fullText = QString("%1 %2: %3\r\n").arg(e).arg(QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss")).arg(text);
        f.write(fullText.toUtf8());
        f.close();
    } else {
        QMessageBox::critical(0, "Error", "Cannot write log");
    }
}

void logging::writeTravelLineLog(const QString &text, const QString &title)
{
#ifdef QT_DEBUG
    qDebug() << title << text;
#endif
    QDir d;
    QString logFile = d.homePath() + "/" + _APPLICATION_ + QString("/travelline_%1.txt").arg(QDate::currentDate().toString("ddMMyyyy"));
    QFile f(logFile);
    if (f.open(QIODevice::Append)) {
        QString fullText = QString("%1 %2\r\n%3\r\n").arg(QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss"), title, text);
        f.write(fullText.toUtf8());
        f.close();
    }
}
