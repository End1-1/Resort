#-------------------------------------------------
#
# Project created by QtCreator 2017-07-15T15:15:16
#
#-------------------------------------------------

QT       += core gui sql network xml printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Restaurant
TEMPLATE = app

RC_FILE = res.rc

INCLUDEPATH += $$PWD/../Base
INCLUDEPATH += $$PWD/../Controls
INCLUDEPATH += $$PWD/../Cache
INCLUDEPATH += $$PWD/../Print
INCLUDEPATH += $$PWD/../Server2
INCLUDEPATH += $$PWD/../Selector
INCLUDEPATH += $$PWD/../Threads
INCLUDEPATH += C:/projects/NewTax/Src
INCLUDEPATH += C:/Soft/OpenSSL-Win32/include
INCLUDEPATH += C:/Soft/OpenSSL-Win32/include/openssl

DEFINES += _DBDRIVER_=\\\"QMYSQL\\\"
DEFINES += _APPLICATION_=\\\"Restaurant\\\"
DEFINES += _RESTAURANT_

SOURCES += main.cpp\
    ../Base/dlgexitbyversion.cpp \
    ../Base/dlgselector.cpp \
    ../Base/doubleutils.cpp \
    ../Base/stringutils.cpp \
    ../Cache/cacheactivegroup.cpp \
    ../Cache/cachefiscalmachine.cpp \
    ../Cache/cachetransferfromcl.cpp \
    ../Cache/cacheyear.cpp \
    ../Threads/broadcastthread.cpp \
    ../Threads/objectthread.cpp \
    baseextendeddialogr.cpp \
    rface.cpp \
    rlogin.cpp \
    rmessage.cpp \
    ../Base/utils.cpp \
    ../Base/base.cpp \
    ../Base/basedialog.cpp \
    ../Base/defines.cpp \
    ../Base/preferences.cpp \
    ../Base/user.cpp \
    hall.cpp \
    rdesk.cpp \
    dishestable.cpp \
    splash.cpp \
    rchangelanguage.cpp \
    rchangemenu.cpp \
    rpaymenttype.cpp \
    rselecttable.cpp \
    rchangehall.cpp \
    rkeyboard.cpp \
    rdishcomment.cpp \
    dlgsmile.cpp \
    rtools.cpp \
    rnumbers.cpp \
    rmodifiers.cpp \
    ../Controls/ecolorlineedit.cpp \
    ../Controls/eqcheckbox.cpp \
    ../Controls/eqdateedit.cpp \
    ../Controls/eqlineedit.cpp \
    ../Controls/eqtextedit.cpp \
    ../Controls/eqtimeedit.cpp \
    ../Controls/trackcontrol.cpp \
    dlgreservation.cpp \
    ../Cache/cacheactiveroom.cpp \
    ../Cache/cachecardex.cpp \
    ../Cache/cachecreditcard.cpp \
    ../Cache/cacheguest.cpp \
    ../Cache/cacheguesttitle.cpp \
    ../Cache/cacheinvoiceitem.cpp \
    ../Cache/cacheone.cpp \
    ../Cache/cachepaymentmode.cpp \
    ../Cache/cacheredreservation.cpp \
    ../Cache/cachereservation.cpp \
    ../Cache/cachereservestatus.cpp \
    ../Cache/cacherestdishmod.cpp \
    ../Cache/cacherestdishpart.cpp \
    ../Cache/cacherestdishtype.cpp \
    ../Cache/cacheresthall.cpp \
    ../Cache/cacherestmenu.cpp \
    ../Cache/cacherestprinters.cpp \
    ../Cache/cachereststore.cpp \
    ../Cache/cacheresttable.cpp \
    ../Cache/cacherights.cpp \
    ../Cache/cacheroom.cpp \
    ../Cache/cacheroomarrangment.cpp \
    ../Cache/cachetrackingtables.cpp \
    ../Cache/cacheusers.cpp \
    ../Cache/cacheusersgroups.cpp \
    ../Cache/cacheusersstate.cpp \
    ../Cache/cachevatmode.cpp \
    ../Controls/eqspinbox.cpp \
    ../Controls/eqtablewidget.cpp \
    dlgcomplexdish.cpp \
    ../Controls/epushbutton.cpp \
    ../Print/pimage.cpp \
    ../Print/pprintpreview.cpp \
    ../Print/pprintscene.cpp \
    ../Print/ptextrect.cpp \
    ../Base/logging.cpp \
    reportprint.cpp \
    ../Controls/eqcombobox.cpp \
    ../Cache/cachesex.cpp \
    ../Cache/cachereminderstate.cpp \
    dlgselecttaxcashmode.cpp \
    dlgbreakfast.cpp \
    ../Base/command.cpp \
    dlgbanket.cpp \
    dlgbanketitems.cpp \
    dlglist.cpp \
    dlgdate.cpp \
    ../Controls/edateedit.cpp \
    dlgvoidback.cpp \
    ../Print/pprintreceipt.cpp \
    dlgorders.cpp \
    dlgonebreakfasat.cpp \
    ../Base/baseuid.cpp \
    dlggettext.cpp \
    dlgconnecttoserver.cpp \
    ../Cache/cachebed.cpp \
    ../Cache/cacheroomcategory.cpp \
    ../Cache/cachecoupontype.cpp \
    ../Cache/cachetaxmap.cpp \
    ../Cache/cachedocpayment.cpp \
    dlgprinttax.cpp \
    ../../NewTax/Src/printtaxn.cpp \
    ../Cache/cachedish.cpp \
    ../Base/paymentmode.cpp \
    ../Base/appconfig.cpp \
    ../Cache/cacheroominventory.cpp \
    ../Cache/cacheroominventorystate.cpp \
    ../Cache/cacheroomstate.cpp \
    ../Base/defrest.cpp \
    ../Base/doubledatabase.cpp \
    ../Cache/cacheinstance.cpp \
    ../Cache/cachebasestruct.cpp \
    ../Cache/cachecar.cpp \
    ../Cache/cachecashdoc.cpp \
    ../Cache/cachecityledger.cpp \
    ../Cache/cachecladvance.cpp \
    ../Cache/cachecouponseria.cpp \
    ../Cache/cachecardexgroup.cpp \
    ../Cache/cachecashdesk.cpp \
    ../Cache/cachecheckoutinvoice.cpp \
    ../Cache/cachedebtcostumer.cpp \
    ../Cache/cachedishstate.cpp \
    ../Cache/cachegroupreservations.cpp \
    ../Cache/cacheinvoiceitemgroup.cpp \
    ../Cache/cachemenudishes.cpp \
    ../Cache/cachenation.cpp \
    ../Cache/cacheorderstate.cpp \
    ../Cache/cacherestdebtholder.cpp \
    ../Cache/cacheroomview.cpp \
    ../Cache/cachestoredocstate.cpp \
    ../Cache/cachestorepartners.cpp \
    ../Cache/cachereservestate.cpp \
    ../Cache/cachecurrencies.cpp \
    ../Cache/cachereservationcardex.cpp \
    ../Cache/cacherestfullmenu.cpp \
    ../Cache/cachevaucher.cpp \
    ../Cache/cachereservegroup.cpp \
    ../Cache/cachestoredoc.cpp


HEADERS  += rface.h \
    ../Base/dlgexitbyversion.h \
    ../Base/dlgselector.h \
    ../Base/doubleutils.h \
    ../Base/stringutils.h \
    ../Cache/cacheactivegroup.h \
    ../Cache/cachefiscalmachine.h \
    ../Cache/cachetransferfromcl.h \
    ../Cache/cacheyear.h \
    ../Threads/broadcastthread.h \
    ../Threads/objectthread.h \
    baseextendeddialogr.h \
    rlogin.h \
    rmessage.h \
    ../Base/base.h \
    ../Base/basedialog.h \
    ../Base/defines.h \
    ../Base/preferences.h \
    ../Base/utils.h \
    ../Base/user.h \
    hall.h \
    rdesk.h \
    dishestable.h \
    splash.h \
    rchangelanguage.h \
    rchangemenu.h \
    rpaymenttype.h \
    rselecttable.h \
    rchangehall.h \
    rkeyboard.h \
    rdishcomment.h \
    dlgsmile.h \
    rtools.h \
    rnumbers.h \
    rmodifiers.h \
    ../Controls/ecolorlineedit.h \
    ../Controls/eqcheckbox.h \
    ../Controls/eqdateedit.h \
    ../Controls/eqlineedit.h \
    ../Controls/eqtextedit.h \
    ../Controls/eqtimeedit.h \
    ../Controls/trackcontrol.h \
    dlgreservation.h \
    ../Cache/cachecreditcard.h \
    ../Cache/cacheguest.h \
    ../Cache/cacheguesttitle.h \
    ../Cache/cacheinvoiceitem.h \
    ../Cache/cacheone.h \
    ../Cache/cachepaymentmode.h \
    ../Cache/cacheredreservation.h \
    ../Cache/cachereservation.h \
    ../Cache/cachereservestate.h \
    ../Cache/cachereservestatus.h \
    ../Cache/cacherestdishmod.h \
    ../Cache/cacherestdishpart.h \
    ../Cache/cacherestdishtype.h \
    ../Cache/cacheresthall.h \
    ../Cache/cacherestmenu.h \
    ../Cache/cacherestprinters.h \
    ../Cache/cachereststore.h \
    ../Cache/cacheresttable.h \
    ../Cache/cacherights.h \
    ../Cache/cacheroom.h \
    ../Cache/cacheroomarrangment.h \
    ../Cache/cachetrackingtables.h \
    ../Cache/cacheusers.h \
    ../Cache/cacheusersgroups.h \
    ../Cache/cacheusersstate.h \
    ../Cache/cachevatmode.h \
    ../Controls/eqspinbox.h \
    ../Controls/eqtablewidget.h \
    dlgcomplexdish.h \
    ../Controls/epushbutton.h \
    ../Print/pdefaults.h \
    ../Print/pimage.h \
    ../Print/pprintpreview.h \
    ../Print/pprintscene.h \
    ../Print/ptextrect.h \
    ../Base/logging.h \
    reportprint.h \
    ../Controls/eqcombobox.h \
    ../Cache/cachesex.h \
    ../Cache/cachereminderstate.h \
    dlgselecttaxcashmode.h \
    dlgbreakfast.h \
    ../Base/command.h \
    dlgbanket.h \
    dlgbanketitems.h \
    ../Base/vauchers.h \
    dlglist.h \
    dlgdate.h \
    ../Controls/edateedit.h \
    dlgvoidback.h \
    ../Print/pprintreceipt.h \
    dlgorders.h \
    dlgonebreakfasat.h \
    ../Base/baseuid.h \
    dlggettext.h \
    dlgconnecttoserver.h \
    ../Cache/cacheroomcategory.h \
    ../Cache/cachetaxmap.h \
    ../Cache/cachedocpayment.h \
    dlgprinttax.h \
    ../../NewTax/Src/printtaxn.h \
    ../Cache/cachedish.h \
    ../Base/paymentmode.h \
    ../Base/appconfig.h \
    ../Cache/cacheroominventory.h \
    ../Cache/cacheroominventorystate.h \
    ../Cache/cacheroomstate.h \
    ../Base/defrest.h \
    ../Base/doubledatabase.h \
    ../Cache/cacheinstance.h \
    ../Cache/cachecheckoutinvoice.h \
    ../Cache/cachedebtcostumer.h \
    ../Cache/cachedishstate.h \
    ../Cache/cachegroupreservations.h \
    ../Cache/cacheinvoiceitemgroup.h \
    ../Cache/cachemenudishes.h \
    ../Cache/cachenation.h \
    ../Cache/cacheorderstate.h \
    ../Cache/cachereservegroup.h \
    ../Cache/cacherestdebtholder.h \
    ../Cache/cacheroomview.h \
    ../Cache/cachestoredocstate.h \
    ../Cache/cachestorepartners.h \
    ../Cache/cachecurrencies.h \
    ../Cache/cachereservationcardex.h \
    ../Cache/cacherestfullmenu.h \
    ../Cache/cachevaucher.h \
    ../Cache/cachereservegroup.h \
    ../Cache/cachestoredoc.h

FORMS    += rface.ui \
    ../Base/dlgexitbyversion.ui \
    ../Base/dlgselector.ui \
    rlogin.ui \
    rmessage.ui \
    rdesk.ui \
    splash.ui \
    rchangelanguage.ui \
    rchangemenu.ui \
    rpaymenttype.ui \
    rselecttable.ui \
    rchangehall.ui \
    rkeyboard.ui \
    rdishcomment.ui \
    dlgsmile.ui \
    rtools.ui \
    rnumbers.ui \
    rmodifiers.ui \
    dlgreservation.ui \
    dlgcomplexdish.ui \
    ../Print/pprintpreview.ui \
    dlgselecttaxcashmode.ui \
    dlgbreakfast.ui \
    dlgbanket.ui \
    dlgbanketitems.ui \
    dlglist.ui \
    dlgdate.ui \
    dlgvoidback.ui \
    dlgorders.ui \
    dlgonebreakfasat.ui \
    dlggettext.ui \
    dlgconnecttoserver.ui \
    dlgprinttax.ui


LIBS += -LC:/Soft/OpenSSL-Win32/lib
LIBS += -lVersion -lwsock32 -lopenssl
LIBS += -llibcrypto

RESOURCES += \
    res.qrc

DISTFILES += \
    stylesheet.qss

