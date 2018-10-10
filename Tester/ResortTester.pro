#-------------------------------------------------
#
# Project created by QtCreator 2018-09-27T21:13:53
#
#-------------------------------------------------

QT       += core gui network sql printsupport xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ResortTester
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    ../Resort/broadcastthread.cpp \
    ../Base/base.cpp \
    ../Base/baseuid.cpp \
    ../Base/defines.cpp \
    ../Base/doubledatabase.cpp \
    ../Base/preferences.cpp \
    ../Base/utils.cpp \
    ../Base/appconfig.cpp \
    ../Base/logging.cpp \
    ../Controls/edateedit.cpp \
    qsockettextthread.cpp

HEADERS += \
        mainwindow.h \
    ../Resort/broadcastthread.h \
    ../Base/base.h \
    ../Base/baseuid.h \
    ../Base/defines.h \
    ../Base/doubledatabase.h \
    ../Base/preferences.h \
    ../Base/utils.h \
    ../Base/appconfig.h \
    ../Base/logging.h \
    ../Controls/edateedit.h \
    qsockettextthread.h

FORMS += \
        mainwindow.ui

INCLUDEPATH += $$PWD/../Base
INCLUDEPATH += $$PWD/../Cache
INCLUDEPATH += $$PWD/../Cache2
INCLUDEPATH += $$PWD/../Selector
INCLUDEPATH += $$PWD/../Controls
INCLUDEPATH += $$PWD/../RowEditor
INCLUDEPATH += $$PWD/../Resort
INCLUDEPATH += $$PWD/../RoomChart
INCLUDEPATH += $$PWD/../Filter
INCLUDEPATH += $$PWD/../Print
INCLUDEPATH += $$PWD/../Widgets
INCLUDEPATH += $$PWD/../RGDoubleClick
INCLUDEPATH += $$PWD/../GridOptionWidgets
INCLUDEPATH += $$PWD/../Vouchers
INCLUDEPATH += /OpenSSL-Win32.0/include
INCLUDEPATH += /OpenSSL-Win32.0/include/openssl
INCLUDEPATH += /Qt/projects/NewTax

LIBS += -lVersion
LIBS += -LC:/OpenSSL-Win32/lib
LIBS += -lopenssl
LIBS += -llibcrypto
LIBS +=  -lwsock32

DEFINES += _ORGANIZATION_=\\\"SmartHotel\\\"
DEFINES += _APPLICATION_=\\\"Tester\\\"
DEFINES += _DBDRIVER_=\\\"QMYSQL\\\"
