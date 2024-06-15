#-------------------------------------------------
#
# Project created by QtCreator 2017-07-31T21:22:54
#
#-------------------------------------------------

QT       += core gui network sql xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server
TEMPLATE = app

RC_FILE = res.rc

SOURCES += main.cpp\
    ../Base/appconfig.cpp \
    ../Base/base.cpp \
    ../Base/broadcast1.cpp \
    ../Base/dlgselector.cpp \
    ../Base/stringutils.cpp \
    ../Base/travellineconfig.cpp \
    ../Base/utils.cpp \
    ../Cache/cacheactivegroup.cpp \
    ../Cache/cacheactiveroom.cpp \
    ../Cache/cachebasestruct.cpp \
    ../Cache/cachebed.cpp \
    ../Cache/cachecar.cpp \
    ../Cache/cachecardex.cpp \
    ../Cache/cachecardexgroup.cpp \
    ../Cache/cachecashdesk.cpp \
    ../Cache/cachecashdoc.cpp \
    ../Cache/cachecheckoutinvoice.cpp \
    ../Cache/cachecityledger.cpp \
    ../Cache/cachecladvance.cpp \
    ../Cache/cachecouponseria.cpp \
    ../Cache/cachecoupontype.cpp \
    ../Cache/cachecreditcard.cpp \
    ../Cache/cachecurrencies.cpp \
    ../Cache/cachedebtcostumer.cpp \
    ../Cache/cachedish.cpp \
    ../Cache/cachedishstate.cpp \
    ../Cache/cachedocpayment.cpp \
    ../Cache/cachefiscalmachine.cpp \
    ../Cache/cachegroupreservations.cpp \
    ../Cache/cacheguest.cpp \
    ../Cache/cacheguesttitle.cpp \
    ../Cache/cacheinstance.cpp \
    ../Cache/cacheinvoiceitem.cpp \
    ../Cache/cacheinvoiceitemgroup.cpp \
    ../Cache/cachemenudishes.cpp \
    ../Cache/cachenation.cpp \
    ../Cache/cacheone.cpp \
    ../Cache/cacheorderstate.cpp \
    ../Cache/cachepaymentmode.cpp \
    ../Cache/cacheredreservation.cpp \
    ../Cache/cachereminderstate.cpp \
    ../Cache/cachereservation.cpp \
    ../Cache/cachereservationcardex.cpp \
    ../Cache/cachereservegroup.cpp \
    ../Cache/cachereservestate.cpp \
    ../Cache/cachereservestatus.cpp \
    ../Cache/cacherestdebtholder.cpp \
    ../Cache/cacherestdishmod.cpp \
    ../Cache/cacherestdishpart.cpp \
    ../Cache/cacherestdishtype.cpp \
    ../Cache/cacherestfullmenu.cpp \
    ../Cache/cacheresthall.cpp \
    ../Cache/cacherestmenu.cpp \
    ../Cache/cacherestprinters.cpp \
    ../Cache/cachereststore.cpp \
    ../Cache/cacheresttable.cpp \
    ../Cache/cacherights.cpp \
    ../Cache/cacheroom.cpp \
    ../Cache/cacheroomarrangment.cpp \
    ../Cache/cacheroomcategory.cpp \
    ../Cache/cacheroomextra.cpp \
    ../Cache/cacheroominventory.cpp \
    ../Cache/cacheroominventorystate.cpp \
    ../Cache/cacheroomstate.cpp \
    ../Cache/cacheroomview.cpp \
    ../Cache/cachesex.cpp \
    ../Cache/cachestoredoc.cpp \
    ../Cache/cachestoredocstate.cpp \
    ../Cache/cachestorepartners.cpp \
    ../Cache/cachetaxmap.cpp \
    ../Cache/cachetrackingtables.cpp \
    ../Cache/cachetransferfromcl.cpp \
    ../Cache/cacheusers.cpp \
    ../Cache/cacheusersgroups.cpp \
    ../Cache/cacheusersstate.cpp \
    ../Cache/cachevatmode.cpp \
    ../Cache/cachevaucher.cpp \
    ../Cache/cacheyear.cpp \
    ../Controls/ecolorlineedit.cpp \
    ../Controls/ecomboboxcompleter.cpp \
    ../Controls/ecombomonth.cpp \
    ../Controls/edateedit.cpp \
    ../Controls/edoubleedit.cpp \
    ../Controls/efilterlineedit.cpp \
    ../Controls/epushbutton.cpp \
    ../Controls/eqcheckbox.cpp \
    ../Controls/eqcombobox.cpp \
    ../Controls/eqdateedit.cpp \
    ../Controls/eqdoubleedit.cpp \
    ../Controls/eqlineedit.cpp \
    ../Controls/eqspinbox.cpp \
    ../Controls/eqtablewidget.cpp \
    ../Controls/eqtextedit.cpp \
    ../Controls/eqtimeedit.cpp \
    ../Controls/eradiobutton.cpp \
    ../Controls/etoolbarbutton.cpp \
    ../Controls/eyearcombo.cpp \
    ../Controls/radiogroupwidget.cpp \
    ../Controls/tableview.cpp \
    ../Controls/trackcontrol.cpp \
    ../Threads/broadcastthread.cpp \
    ../Threads/objectthread.cpp \
        dlgmain.cpp \
    ../Base/defines.cpp \
    ../Base/command.cpp \
    ../Base/preferences.cpp \
    ../Base/doubledatabase.cpp \
    ../Base/baseuid.cpp \
    qtcppushbutton.cpp \
    ../Base/logging.cpp \
    traveline.cpp

HEADERS  += dlgmain.h \
    ../Base/appconfig.h \
    ../Base/base.h \
    ../Base/broadcast1.h \
    ../Base/defines.h \
    ../Base/command.h \
    ../Base/dlgselector.h \
    ../Base/preferences.h \
    ../Base/doubledatabase.h \
    ../Base/baseuid.h \
    ../Base/stringutils.h \
    ../Base/travellineconfig.h \
    ../Base/utils.h \
    ../Cache/cacheactivegroup.h \
    ../Cache/cacheactiveroom.h \
    ../Cache/cachebasestruct.h \
    ../Cache/cachebed.h \
    ../Cache/cachecar.h \
    ../Cache/cachecardex.h \
    ../Cache/cachecardexgroup.h \
    ../Cache/cachecashdesk.h \
    ../Cache/cachecashdoc.h \
    ../Cache/cachecheckoutinvoice.h \
    ../Cache/cachecityledger.h \
    ../Cache/cachecladvance.h \
    ../Cache/cachecouponseria.h \
    ../Cache/cachecoupontype.h \
    ../Cache/cachecreditcard.h \
    ../Cache/cachecurrencies.h \
    ../Cache/cachedebtcostumer.h \
    ../Cache/cachedish.h \
    ../Cache/cachedishstate.h \
    ../Cache/cachedocpayment.h \
    ../Cache/cachefiscalmachine.h \
    ../Cache/cachegroupreservations.h \
    ../Cache/cacheguest.h \
    ../Cache/cacheguesttitle.h \
    ../Cache/cacheinstance.h \
    ../Cache/cacheinvoiceitem.h \
    ../Cache/cacheinvoiceitemgroup.h \
    ../Cache/cachemenudishes.h \
    ../Cache/cachenation.h \
    ../Cache/cacheone.h \
    ../Cache/cacheorderstate.h \
    ../Cache/cachepaymentmode.h \
    ../Cache/cacheredreservation.h \
    ../Cache/cachereminderstate.h \
    ../Cache/cachereservation.h \
    ../Cache/cachereservationcardex.h \
    ../Cache/cachereservegroup.h \
    ../Cache/cachereservestate.h \
    ../Cache/cachereservestatus.h \
    ../Cache/cacherestdebtholder.h \
    ../Cache/cacherestdishmod.h \
    ../Cache/cacherestdishpart.h \
    ../Cache/cacherestdishtype.h \
    ../Cache/cacherestfullmenu.h \
    ../Cache/cacheresthall.h \
    ../Cache/cacherestmenu.h \
    ../Cache/cacherestprinters.h \
    ../Cache/cachereststore.h \
    ../Cache/cacheresttable.h \
    ../Cache/cacherights.h \
    ../Cache/cacheroom.h \
    ../Cache/cacheroomarrangment.h \
    ../Cache/cacheroomcategory.h \
    ../Cache/cacheroomextra.h \
    ../Cache/cacheroominventory.h \
    ../Cache/cacheroominventorystate.h \
    ../Cache/cacheroomstate.h \
    ../Cache/cacheroomview.h \
    ../Cache/cachesex.h \
    ../Cache/cachestoredoc.h \
    ../Cache/cachestoredocstate.h \
    ../Cache/cachestorepartners.h \
    ../Cache/cachetaxmap.h \
    ../Cache/cachetrackingtables.h \
    ../Cache/cachetransferfromcl.h \
    ../Cache/cacheusers.h \
    ../Cache/cacheusersgroups.h \
    ../Cache/cacheusersstate.h \
    ../Cache/cachevatmode.h \
    ../Cache/cachevaucher.h \
    ../Cache/cacheyear.h \
    ../Controls/ecolorlineedit.h \
    ../Controls/ecomboboxcompleter.h \
    ../Controls/ecombomonth.h \
    ../Controls/edateedit.h \
    ../Controls/edoubleedit.h \
    ../Controls/efilterlineedit.h \
    ../Controls/epushbutton.h \
    ../Controls/eqcheckbox.h \
    ../Controls/eqcombobox.h \
    ../Controls/eqdateedit.h \
    ../Controls/eqdoubleedit.h \
    ../Controls/eqlineedit.h \
    ../Controls/eqspinbox.h \
    ../Controls/eqtablewidget.h \
    ../Controls/eqtextedit.h \
    ../Controls/eqtimeedit.h \
    ../Controls/eradiobutton.h \
    ../Controls/etoolbarbutton.h \
    ../Controls/eyearcombo.h \
    ../Controls/radiogroupwidget.h \
    ../Controls/tableview.h \
    ../Controls/trackcontrol.h \
    ../Threads/broadcastthread.h \
    ../Threads/objectthread.h \
    qtcppushbutton.h \
    ../Base/logging.h \
    traveline.h

FORMS    += dlgmain.ui \
    ../Base/dlgselector.ui \
    ../Controls/efilterlineedit.ui

RESOURCES += \
    res.qrc

INCLUDEPATH += $$PWD/../Base
INCLUDEPATH += $$PWD/../Controls
INCLUDEPATH += $$PWD/../Threads
INCLUDEPATH += $$PWD/../Cache

DEFINES += _ORGANIZATION_=\\\"SmartHotel\\\"
DEFINES += _APPLICATION_=\\\"Server\\\"
DEFINES += _DBDRIVER_=\\\"QMYSQL\\\"
DEFINES += RESORT_SERVER

LIBS += -lVersion
