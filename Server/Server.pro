#-------------------------------------------------
#
# Project created by QtCreator 2017-07-31T21:22:54
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server
TEMPLATE = app

RC_FILE = res.rc

SOURCES += main.cpp\
        dlgmain.cpp \
    ../Base/defines.cpp \
    ../Base/command.cpp \
    ../Base/preferences.cpp \
    ../Base/doubledatabase.cpp \
    ../Base/baseuid.cpp \
    qtcppushbutton.cpp

HEADERS  += dlgmain.h \
    ../Base/defines.h \
    ../Base/command.h \
    ../Base/preferences.h \
    ../Base/doubledatabase.h \
    ../Base/baseuid.h \
    qtcppushbutton.h

FORMS    += dlgmain.ui

RESOURCES += \
    res.qrc

INCLUDEPATH += $$PWD/../Base
INCLUDEPATH += $$PWD/../Controls

DEFINES += _ORGANIZATION_=\\\"SmartHotel\\\"
DEFINES += _APPLICATION_=\\\"Server\\\"
DEFINES += _DBDRIVER_=\\\"QMYSQL\\\"
