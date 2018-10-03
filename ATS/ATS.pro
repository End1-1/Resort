#-------------------------------------------------
#
# Project created by QtCreator 2017-09-07T09:35:44
#
#-------------------------------------------------

QT       += core gui serialport serialbus sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ATS
TEMPLATE = app
RC_FILE = res.rc

INCLUDEPATH += $$PWD/../Base
INCLUDEPATH += $$PWD/../Controls

SOURCES += main.cpp\
        dlgmain.cpp \
    ../Base/utils.cpp \
    ../Base/defines.cpp \
    ../Base/preferences.cpp \
    ../Base/baseuid.cpp \
    ../Base/doubledatabase.cpp

HEADERS  += dlgmain.h \
    ../Base/utils.h \
    ../Base/defines.h \
    ../Base/preferences.h \
    rc.h \
    res.rc \
    ../Base/baseuid.h \
    ../Base/doubledatabase.h

FORMS    += dlgmain.ui

LIBS += -lVersion

RESOURCES += \
    images.qrc

DEFINES += _ORGANIZATION_=\\\"SmartHotel\\\"
DEFINES += _APPLICATION_=\\\"ATS\\\"
DEFINES += _DBDRIVER_=\\\"QMYSQL\\\"
