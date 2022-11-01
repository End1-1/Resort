#-------------------------------------------------
#
# Project created by QtCreator 2017-06-04T01:03:26
#
#-------------------------------------------------

QT       += core gui sql network xml printsupport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartHotel
TEMPLATE = app

RC_FILE = res.rc

DEFINES += _RESORT_
DEFINES += _HOTEL_
DEFINES += _METROPOL_

SOURCES += main.cpp\
    ../../XLSX/src/xlsxborder.cpp \
    ../Base/dlgselector.cpp \
    ../Base/doubleutils.cpp \
    ../Base/monthnames.cpp \
    ../Base/stringutils.cpp \
    ../Cache/cacheactivegroup.cpp \
    ../Cache/cachefiscalmachine.cpp \
    ../Cache/cacheyear.cpp \
    ../Controls/edoubleedit.cpp \
    ../Controls/eyearcombo.cpp \
    ../Controls/tableview.cpp \
    ../Filter/fcashreportbyitem.cpp \
    ../Filter/fexpecteddeparturesimple.cpp \
    ../Filter/fexpectedsimple.cpp \
    ../Filter/fforecastoccupancycategoryreal.cpp \
    ../Filter/finhouseguestfuture.cpp \
    ../Filter/froomstates.cpp \
    ../Filter/ftaxreport.cpp \
    ../Server2/datahandler.cpp \
    ../Server2/listener.cpp \
    ../Server2/socketconnection.cpp \
    ../Threads/broadcastthread.cpp \
    ../Threads/objectthread.cpp \
    databaserow.cpp \
    dbminvoice.cpp \
    dlgconfigtaxserver.cpp \
    dlgexportas.cpp \
    dlghdmviewer.cpp \
    dlghouseitemonoffwidget.cpp \
    dlginvoicepaymentoptions.cpp \
    dlgmovetocl.cpp \
    dlgoptions.cpp \
    dlgprintvoucherasinvoice.cpp \
    dlgquickadvanceaction.cpp \
    dlgrecoverinvoice.cpp \
    dlgseachfromdatabase.cpp \
    dlgselectfiscalmachin.cpp \
    dlgsingleprinttax.cpp \
    dlgtransferlog.cpp \
        mainwindow.cpp \
    login.cpp \
    loginsettings.cpp \
    message.cpp \
    databasesconnections.cpp \
    databaseconnection.cpp \
    databasepasswordchange.cpp \
    taxhelper.cpp \
    wactivegroup.cpp \
    wchart.cpp \
    wcheckboxgroup.cpp \
    wcityledger.cpp \
    wmaindesk.cpp \
    wmaindeskfilterlist.cpp \
    wpaymentdetails.cpp \
    wquickcheckout.cpp \
    wquickcheckoutbalance.cpp \
    wquickcheckoutprocess.cpp \
    wquickreservations.cpp \
    wquickreservationscheckin.cpp \
    wquickreservationsguests.cpp \
    wquickreservationspax.cpp \
    wreservation.cpp \
    wguest.cpp \
    winvoice.cpp \
    wreportgrid.cpp \
    wroomcharttemprectdlg.cpp \
    wtaxattack.cpp \
    wwelcome.cpp \
    wcontacts.cpp \
    tablemodel.cpp \
    wreportroom.cpp \
    dlgcontact.cpp \
    wnotes.cpp \
    roweditordialog.cpp \
    dlgnotes.cpp \
    about.cpp \
    wguests.cpp \
    wreservations.cpp \
    dlgfiltervalues.cpp \
    dlgroom.cpp \
    wreservationroomtab.cpp \
    dlgchartdaterange.cpp \
    basewidget.cpp \
    baseextendeddialog.cpp \
    ../Base/base.cpp \
    ../Base/basedialog.cpp \
    ../Base/defines.cpp \
    ../Base/preferences.cpp \
    ../Base/utils.cpp \
    wusers.cpp \
    wusersgroups.cpp \
    dlgusergroup.cpp \
    wroomview.cpp \
    dlgroomview.cpp \
    dlgendofday.cpp \
    wcardex.cpp \
    dlgcardex.cpp \
    dwmaindeskhint.cpp \
    ../Base/command.cpp \
    ../Cache/cacheinvoiceitem.cpp \
    ../Cache/cacheactiveroom.cpp \
    dlgpaymentsdetails.cpp \
    ../Cache/cachepaymentmode.cpp \
    ../Controls/eqcheckbox.cpp \
    ../Cache/cachevatmode.cpp \
    ../Cache/cacheguesttitle.cpp \
    ../Cache/cachecardex.cpp \
    ../Cache/cachecityledger.cpp \
    ../RowEditor/reresthall.cpp \
    ../Cache/cacheresthall.cpp \
    ../Cache/cacherestmenu.cpp \
    ../RowEditor/reresttable.cpp \
    ../Cache/cacheresttable.cpp \
    ../RowEditor/rerestmenunames.cpp \
    ../RowEditor/rerestmenupart.cpp \
    ../Cache/cacherestdishpart.cpp \
    ../RowEditor/rerestdishtype.cpp \
    ../Controls/ecolorlineedit.cpp \
    ../Cache/cacherestdishtype.cpp \
    ../Controls/eqtextedit.cpp \
    ../RowEditor/rerestdish.cpp \
    ../Cache/cacherestprinters.cpp \
    ../Cache/cachereststore.cpp \
    ../Cache/cacherestdishmod.cpp \
    ../RowEditor/rerestdishmod.cpp \
    ../RowEditor/rereststore.cpp \
    ../RowEditor/rerestprinter.cpp \
    ../RoomChart/roomscene.cpp \
    ../RoomChart/dayitemdelegate.cpp \
    ../RoomChart/monthitemdelegate.cpp \
    ../RoomChart/roomitemdelegate.cpp \
    ../Cache/cacheroom.cpp \
    ../Cache/cacheone.cpp \
    ../RoomChart/reserverect.cpp \
    ../RoomChart/chardefaults.cpp \
    ../RoomChart/reservewidget.cpp \
    ../Cache/cachereservation.cpp \
    ../RoomChart/reservationinfo.cpp \
    ../RoomChart/dlgreservequickinfo.cpp \
    ../Controls/eqlineedit.cpp \
    ../Controls/trackcontrol.cpp \
    ../Controls/eqdateedit.cpp \
    ../Cache/cachereservestate.cpp \
    ../Cache/cachereservestatus.cpp \
    ../Cache/cacheroomarrangment.cpp \
    ../Controls/eqcombobox.cpp \
    ../Filter/wfilterbase.cpp \
    ../Filter/ftrackchanges.cpp \
    ../Controls/eqtimeedit.cpp \
    ../Cache/cachetrackingtables.cpp \
    ../Cache/cacheusers.cpp \
    ../Cache/cacheusersgroups.cpp \
    ../RowEditor/reusers.cpp \
    ../Cache/cacheusersstate.cpp \
    ../Cache/cacherights.cpp \
    ../Print/pprintpreview.cpp \
    ../Print/pprintscene.cpp \
    ../Print/ptextrect.cpp \
    ../Cache/cacheguest.cpp \
    ../Cache/cachecreditcard.cpp \
    ../RowEditor/recreditcard.cpp \
    ../Filter/fcityledgerbalance.cpp \
    dlguserpasswords.cpp \
    dlgadvanceentry.cpp \
    ../Cache/cacheredreservation.cpp \
    ../RoomChart/roomstate.cpp \
    ../Cache/cacheroomstate.cpp \
    ../Controls/eqtablewidget.cpp \
    dlginvoicecancelation.cpp \
    dlgraiseuser.cpp \
    wglobaldbconfig.cpp \
    ../Controls/eqspinbox.cpp \
    dlggposorderinfo.cpp \
    ../RowEditor/rerestdishcomplex.cpp \
    ../RowEditor/reroomcategory.cpp \
    ../RowEditor/reroombed.cpp \
    ../RowEditor/reroomcategoryrate.cpp \
    ../RowEditor/recustomaction.cpp \
    reroomcategoryraterow.cpp \
    dlgtransfer.cpp \
    ../Filter/finvoices.cpp \
    waccinvoice.cpp \
    dlgtracking.cpp \
    ../Cache/cachemenudishes.cpp \
    ../Controls/epushbutton.cpp \
    ../Filter/frestauranttotal.cpp \
    ../Filter/fdailymovement.cpp \
    ../Filter/freservationscommon.cpp \
    ../RoomChart/reservewidgetaction.cpp \
    ../Print/pimage.cpp \
    wgroupreserverect.cpp \
    dlgdiscount.cpp \
    ../Print/pprintinvoice.cpp \
    ../Filter/fcategorytosell.cpp \
    ../Cache/cachecurrencies.cpp \
    ../RowEditor/recurrency.cpp \
    ../Filter/fforecastoccupancycategory.cpp \
    ../Filter/faccmonthlyreport.cpp \
    timerblya.cpp \
    ../Print/dlgprintreservation.cpp \
    ../Cache/cachenation.cpp \
    ../Cache/cacheroomcategory.cpp \
    ../Cache/cacheroomview.cpp \
    ../Cache/cachereminderstate.cpp \
    ../Base/logging.cpp \
    ../Print/pprintheader.cpp \
    dlgtaxprintsetup.cpp \
    dlginvoiceprintoption.cpp \
    ../RowEditor/reinvoiceitem.cpp \
    ../Cache/cacheinvoiceitemgroup.cpp \
    ../Filter/finhouseguest.cpp \
    ../Filter/fexpectedarrivals.cpp \
    ../Controls/edateedit.cpp \
    ../Widgets/wrecheckin.cpp \
    ../Filter/fexpectedarrivalsimple.cpp \
    ../Filter/fcashreportsummary.cpp \
    dlgreceiptvaucher.cpp \
    ../Filter/fcityledgerdetailedbalance.cpp \
    ../RGDoubleClick/rgdoubleclickdelegate.cpp \
    ../RGDoubleClick/rgcityledgerdetailedbalance.cpp \
    ../Filter/fcashreport.cpp \
    ../Cache/cachecardexgroup.cpp \
    ../RowEditor/recityledger.cpp \
    ../Filter/fvauchers.cpp \
    ../Base/vauchers.cpp \
    dlguserrights.cpp \
    ../Cache/cachevaucher.cpp \
    ../Print/pprintvaucher.cpp \
    dlgreservationremarks.cpp \
    ../Filter/fevents.cpp \
    ../Cache/cacheorderstate.cpp \
    ../Cache/cachedish.cpp \
    ../Cache/cachedishstate.cpp \
    dlgpretax.cpp \
    dlgprinttaxsideoption.cpp \
    ../Filter/fdailymovementcommon.cpp \
    ../Charts/chsample.cpp \
    dlgsearchinvoice.cpp \
    ../RowEditor/rebanquetcomment.cpp \
    ../Filter/fcityledgerbalanceextended.cpp \
    ../Filter/fcallhistory.cpp \
    dlgtaxback.cpp \
    ../Filter/fcardexsales.cpp \
    ../Filter/fcommonfilterbydate.cpp \
    dlgprintrandomtax.cpp \
    dlgtaxreference.cpp \
    ../Widgets/wvauchereditor.cpp \
    ../Widgets/wsyncinvoices.cpp \
    ../RowEditor/recomplimentarycomment.cpp \
    dlgexportsinglevaucher.cpp \
    ../Controls/etoolbarbutton.cpp \
    dlgwelcomebuttonconfig.cpp \
    ../Widgets/wreportbuilder.cpp \
    ../Widgets/wremarks.cpp \
    ../Controls/efilterlineedit.cpp \
    ../Print/pprintreceipt.cpp \
    ../Widgets/whotelstatus.cpp \
    dlgclinitialbalance.cpp \
    ../Filter/flistsourcereserve.cpp \
    ../Filter/fyearlyfinancialreport.cpp \
    ../Widgets/wcustomreports.cpp \
    dlgreportbuildergroups.cpp \
    ../Controls/ecomboboxcompleter.cpp \
    ../Widgets/wreportssetold.cpp \
    ../Controls/eradiobutton.cpp \
    ../Controls/ecombomonth.cpp \
    ../Base/baseuid.cpp \
    dlgviewinvoicecorrections.cpp \
    dlgperemovereason.cpp \
    dlgutils.cpp \
    dlgdishhistory.cpp \
    ../Cache/cachecheckoutinvoice.cpp \
    dlgremotinvoices.cpp \
    dlgopengrouporsingle.cpp \
    dlgexportother.cpp \
    dlgreserveconfirmstatus.cpp \
    ../Filter/freservaionremarks.cpp \
    dlgchangeexportvaucher.cpp \
    dlggroupreservationfuck.cpp \
    dlgsimpleselectroom.cpp \
    fnousedadvance.cpp \
    ../RoomChart/dlgooroomprop.cpp \
    fonlinerest.cpp \
    ../Cache/cachereservegroup.cpp \
    ../Filter/freservegroups.cpp \
    ../RowEditor/recardexgroup.cpp \
    ../RowEditor/reguesttitle.cpp \
    ../RowEditor/renationalityfile.cpp \
    dlghelp.cpp \
    ../Filter/froomstate.cpp \
    ../Filter/fcanceledreservations.cpp \
    ../Widgets/wweb.cpp \
    ../Filter/freservebycreate.cpp \
    ../Widgets/storedoc.cpp \
    ../RowEditor/restorepartner.cpp \
    ../Cache/cachestorepartners.cpp \
    ../Cache/cachestoredoc.cpp \
    ../Cache/cachestoredocstate.cpp \
    ../Cache/cachecoupontype.cpp \
    dlgcalculateoutputofrestaurant.cpp \
    ../Base/defrest.cpp \
    fonlinebreakfast.cpp \
    ../Filter/fmonthlyoccperc.cpp \
    fnatbyperiod.cpp \
    dlgcl.cpp \
    dlgpaymentmode.cpp \
    dlgchangeclofvaucher.cpp \
    dlgnoshow.cpp \
    ../Filter/fnoshowcancelationfee.cpp \
    ../Filter/frestsalebystore.cpp \
    dlgcheckadvancebeforecancel.cpp \
    dlgrefundvaucher.cpp \
    dlgeditservtax.cpp \
    ../Cache/cachetaxmap.cpp \
    dlgreserveshortinfo.cpp \
    dlgnewvaucheroption.cpp \
    ../Filter/fallguestindaterange.cpp \
    ../RowEditor/remodelofcars.cpp \
    ../RowEditor/recarclient.cpp \
    ../Cache/cachecar.cpp \
    ../Cache/cacherestdebtholder.cpp \
    ../Filter/freportbypayment.cpp \
    ../Cache/cachedocpayment.cpp \
    fpartnersdebt.cpp \
    dlgcouponsales.cpp \
    ../Cache/cachecouponseria.cpp \
    ../Cache/cachecashdesk.cpp \
    ../Widgets/wcashentry.cpp \
    ../Cache/cachecashdoc.cpp \
    ../Widgets/wstoreentry.cpp \
    dlgpartnerpayment.cpp \
    dlgcashop.cpp \
    ../Filter/fcouponstatistics.cpp \
    ../Cache/cachedebtcostumer.cpp \
    ../Filter/fbreakfast.cpp \
    ../Filter/fsalary.cpp \
    ../../NewTax/Src/printtaxn.cpp \
    dlgprinttaxsm.cpp \
    dlgtaxback2.cpp \
    dlgpostbreakfast.cpp \
    ../Controls/eqdoubleedit.cpp \
    ../Cache/cacherestfullmenu.cpp \
    dlghouseitem.cpp \
    ../Filter/fhouseitems.cpp \
    dlgdebtpay.cpp \
    ../Vouchers/basevoucher.cpp \
    ../Vouchers/voucher_tc.cpp \
    ../Cache/cachecladvance.cpp \
    ../Filter/fcladvance.cpp \
    ../Print/pprintcheckin.cpp \
    ../Filter/fcitytrayledger.cpp \
    ../Filter/finhousedetailbalance.cpp \
    ../Filter/favailablerooms.cpp \
    ../Widgets/wdate2.cpp \
    ../Base/paymentmode.cpp \
    dlgconfiggrid.cpp \
    ../Base/appconfig.cpp \
    ../Cache/cacheroominventory.cpp \
    ../RowEditor/reroominventory.cpp \
    ../RowEditor/reroominventorystate.cpp \
    ../Cache/cacheroominventorystate.cpp \
    ../Print/pexportinvoicetoexcel.cpp \
    dlggroupreserveoption.cpp \
    ../Cache/cachegroupreservations.cpp \
    ../GridOptionWidgets/gowidget.cpp \
    ../GridOptionWidgets/godaily.cpp \
    ../Vouchers/voucher_av.cpp \
    dlgexport.cpp \
    goexpextedarrivals.cpp \
    smtp.cpp \
    dlgemail.cpp \
    ../Print/pprintstoredoc.cpp \
    ../Print/pprintstoreentry.cpp \
    ../Filter/guestcheckin.cpp \
    ../Filter/flengthofstay.cpp \
    ../Filter/fexportreservation.cpp \
    dlgreservationguests.cpp \
    ../Base/doubledatabase.cpp \
    ../Cache2/cache2.cpp \
    ../Cache/cacheinstance.cpp \
    ../Cache/cachebasestruct.cpp \
    ../Cache/cachebed.cpp \
    ../Cache/cachereservationcardex.cpp \
    ../Cache/cachesex.cpp \
    dlgcreategroupreservation.cpp \
    ../Base/dlgexitbyversion.cpp \
    dlgexecfailedsqls.cpp \
    ../Filter/fdishes.cpp \
    ../Filter/froomarrangement.cpp \
    dlgclearlog.cpp \
    ../Filter/fwakeupcall.cpp \
    dlgwakepcalls.cpp \
    ../Filter/fdailytransaction.cpp \
    ../Filter/fhotelhierarchy.cpp \
    wroomchart.cpp \
    ../Filter/fcallrates.cpp \
    ../RowEditor/recallrate.cpp \
    wroomchartclasses.cpp \
    ../Print/printtaxd.cpp \
    wroomcharttime.cpp \
    wroomchartdock.cpp \
    dlgchartcolor.cpp \
    ../Cache/cachetransferfromcl.cpp \
    dbmregister.cpp \
    dlgquickroomassignment.cpp \
    dlgquickadvance.cpp \
    wquickroomassignment.cpp \
    dlgquickadvanceapply.cpp \
    dlggrouprevive.cpp \
    ../../XLSX/src/xlsx.cpp \
    ../../XLSX/src/xlsxcell.cpp \
    ../../XLSX/src/xlsxcontenttype.cpp \
    ../../XLSX/src/xlsxdocpropsapp.cpp \
    ../../XLSX/src/xlsxdocpropscore.cpp \
    ../../XLSX/src/xlsxdocument.cpp \
    ../../XLSX/src/xlsxrels.cpp \
    ../../XLSX/src/xlsxsharedstring.cpp \
    ../../XLSX/src/xlsxsheet.cpp \
    ../../XLSX/src/xlsxstyles.cpp \
    ../../XLSX/src/xlsxtheme.cpp \
    ../../XLSX/src/xlsxworkbook.cpp \
    ../../XLSX/src/xlsxwriter.cpp \
    dlgtransferanyamount.cpp \
    ../Controls/radiogroupwidget.cpp \
    ../Filter/fexpectedarrivals2.cpp \
    ../Filter/fcitytrayledger2.cpp \
    ../Filter/fcitytrayledger2.cpp \
    dlgofferinvoiceextra.cpp \
    dlgpostcharge.cpp \
    wguestinvoice.cpp \
    ../Filter/wcardexlist.cpp

HEADERS  += mainwindow.h \
    ../../XLSX/src/xlsxborder.h \
    ../Base/dlgselector.h \
    ../Base/doubleutils.h \
    ../Base/monthnames.h \
    ../Base/stringutils.h \
    ../Cache/cacheactivegroup.h \
    ../Cache/cachefiscalmachine.h \
    ../Cache/cacheyear.h \
    ../Controls/edoubleedit.h \
    ../Controls/eyearcombo.h \
    ../Controls/tableview.h \
    ../Filter/fcashreportbyitem.h \
    ../Filter/fexpecteddeparturesimple.h \
    ../Filter/fexpectedsimple.h \
    ../Filter/fforecastoccupancycategoryreal.h \
    ../Filter/finhouseguestfuture.h \
    ../Filter/froomstates.h \
    ../Filter/ftaxreport.h \
    ../Server2/datahandler.h \
    ../Server2/listener.h \
    ../Server2/socketconnection.h \
    ../Threads/broadcastthread.h \
    ../Threads/objectthread.h \
    databaserow.h \
    dbminvoice.h \
    dlgconfigtaxserver.h \
    dlgexportas.h \
    dlghdmviewer.h \
    dlghouseitemonoffwidget.h \
    dlginvoicepaymentoptions.h \
    dlgmovetocl.h \
    dlgoptions.h \
    dlgprintvoucherasinvoice.h \
    dlgquickadvanceaction.h \
    dlgrecoverinvoice.h \
    dlgseachfromdatabase.h \
    dlgselectfiscalmachin.h \
    dlgsingleprinttax.h \
    dlgtransferlog.h \
    login.h \
    loginsettings.h \
    message.h \
    databasesconnections.h \
    databaseconnection.h \
    databasepasswordchange.h \
    taxhelper.h \
    wactivegroup.h \
    wchart.h \
    wcheckboxgroup.h \
    wcityledger.h \
    wmaindesk.h \
    wmaindeskfilterlist.h \
    wpaymentdetails.h \
    wquickcheckout.h \
    wquickcheckoutbalance.h \
    wquickcheckoutprocess.h \
    wquickreservations.h \
    wquickreservationscheckin.h \
    wquickreservationsguests.h \
    wquickreservationspax.h \
    wreservation.h \
    wguest.h \
    winvoice.h \
    wreportgrid.h \
    wroomcharttemprectdlg.h \
    wtaxattack.h \
    wwelcome.h \
    wcontacts.h \
    tablemodel.h \
    wreportroom.h \
    dlgcontact.h \
    wnotes.h \
    roweditordialog.h \
    dlgnotes.h \
    about.h \
    rc.h \
    wguests.h \
    wreservations.h \
    dlgfiltervalues.h \
    dlgroom.h \
    wreservationroomtab.h \
    dlgchartdaterange.h \
    basewidget.h \
    baseextendeddialog.h \
    ../Base/base.h \
    ../Base/basedialog.h \
    ../Base/defines.h \
    ../Base/preferences.h \
    ../Base/utils.h \
    wusers.h \
    wusersgroups.h \
    dlgusergroup.h \
    wroomview.h \
    dlgroomview.h \
    dlgendofday.h \
    wcardex.h \
    dlgcardex.h \
    dwmaindeskhint.h \
    ../Base/command.h \
    ../Cache/cacheinvoiceitem.h \
    ../Cache/cacheactiveroom.h \
    dlgpaymentsdetails.h \
    ../Cache/cachepaymentmode.h \
    ../Controls/eqcheckbox.h \
    ../Cache/cachevatmode.h \
    ../Cache/cacheguesttitle.h \
    ../Cache/cachecardex.h \
    ../Cache/cachecityledger.h \
    ../RowEditor/reresthall.h \
    ../Cache/cacheresthall.h \
    ../Cache/cacherestmenu.h \
    ../RowEditor/reresttable.h \
    ../Cache/cacheresttable.h \
    ../RowEditor/rerestmenunames.h \
    ../RowEditor/rerestmenupart.h \
    ../Cache/cacherestdishpart.h \
    ../RowEditor/rerestdishtype.h \
    ../Controls/ecolorlineedit.h \
    ../Cache/cacherestdishtype.h \
    ../Controls/eqtextedit.h \
    ../RowEditor/rerestdish.h \
    ../Cache/cacherestprinters.h \
    ../Cache/cachereststore.h \
    ../Cache/cacherestdishmod.h \
    ../RowEditor/rerestdishmod.h \
    ../RowEditor/rereststore.h \
    ../RowEditor/rerestprinter.h \
    ../RoomChart/roomscene.h \
    ../RoomChart/dayitemdelegate.h \
    ../RoomChart/chardefaults.h \
    ../RoomChart/monthitemdelegate.h \
    ../RoomChart/roomitemdelegate.h \
    ../Cache/cacheroom.h \
    ../Cache/cacheone.h \
    ../RoomChart/reserverect.h \
    ../RoomChart/reservewidget.h \
    ../Cache/cachereservation.h \
    ../RoomChart/reservationinfo.h \
    ../RoomChart/dlgreservequickinfo.h \
    ../Controls/eqlineedit.h \
    ../Controls/trackcontrol.h \
    ../Controls/eqdateedit.h \
    ../Cache/cachereservestate.h \
    ../Cache/cachereservestatus.h \
    ../Cache/cacheroomarrangment.h \
    ../Controls/eqcombobox.h \
    ../Filter/wfilterbase.h \
    ../Filter/ftrackchanges.h \
    ../Controls/eqtimeedit.h \
    ../Cache/cachetrackingtables.h \
    ../Cache/cacheusers.h \
    ../Cache/cacheusersgroups.h \
    ../RowEditor/reusers.h \
    ../Cache/cacheusersstate.h \
    ../Cache/cacherights.h \
    ../Print/pprintpreview.h \
    ../Print/pprintscene.h \
    ../Print/ptextrect.h \
    ../Print/pdefaults.h \
    ../Cache/cacheguest.h \
    ../Cache/cachecreditcard.h \
    ../RowEditor/recreditcard.h \
    ../Filter/fcityledgerbalance.h \
    dlguserpasswords.h \
    dlgadvanceentry.h \
    ../Cache/cacheredreservation.h \
    ../RoomChart/roomstate.h \
    ../Cache/cacheroomstate.h \
    ../Controls/eqtablewidget.h \
    dlginvoicecancelation.h \
    dlgraiseuser.h \
    wglobaldbconfig.h \
    ../Controls/eqspinbox.h \
    dlggposorderinfo.h \
    ../RowEditor/rerestdishcomplex.h \
    ../RowEditor/reroomcategory.h \
    ../RowEditor/reroombed.h \
    ../RowEditor/reroomcategoryrate.h \
    ../RowEditor/recustomaction.h \
    reroomcategoryraterow.h \
    ../Cache/cachebed.h \
    dlgtransfer.h \
    ../Filter/finvoices.h \
    waccinvoice.h \
    dlgtracking.h \
    ../Cache/cachemenudishes.h \
    ../Controls/epushbutton.h \
    ../Filter/frestauranttotal.h \
    ../Filter/fdailymovement.h \
    ../Filter/freservationscommon.h \
    ../RoomChart/reservewidgetaction.h \
    ../Print/pimage.h \
    wgroupreserverect.h \
    dlgdiscount.h \
    ../Print/pprintinvoice.h \
    ../Filter/fcategorytosell.h \
    ../Cache/cachecurrencies.h \
    ../RowEditor/recurrency.h \
    ../Filter/fforecastoccupancycategory.h \
    ../Filter/faccmonthlyreport.h \
    timerblya.h \
    ../Print/dlgprintreservation.h \
    ../Cache/cachenation.h \
    ../Cache/cacheroomcategory.h \
    ../Cache/cacheroomview.h \
    ../Cache/cachereminderstate.h \
    ../Base/logging.h \
    ../Print/pprintheader.h \
    dlgtaxprintsetup.h \
    dlginvoiceprintoption.h \
    ../RowEditor/reinvoiceitem.h \
    ../Cache/cacheinvoiceitemgroup.h \
    ../Filter/finhouseguest.h \
    ../Filter/fexpectedarrivals.h \
    ../Controls/edateedit.h \
    ../Widgets/wrecheckin.h \
    ../Filter/fexpectedarrivalsimple.h \
    ../Filter/fcashreportsummary.h \
    dlgreceiptvaucher.h \
    ../Filter/fcityledgerdetailedbalance.h \
    ../RGDoubleClick/rgdoubleclickdelegate.h \
    ../RGDoubleClick/rgcityledgerdetailedbalance.h \
    ../Filter/fcashreport.h \
    ../Cache/cachecardexgroup.h \
    ../RowEditor/recityledger.h \
    ../Base/vauchers.h \
    ../Filter/fvauchers.h \
    dlguserrights.h \
    ../Cache/cachevaucher.h \
    ../Print/pprintvaucher.h \
    dlgreservationremarks.h \
    ../Filter/fevents.h \
    ../Cache/cacheorderstate.h \
    ../Cache/cachedish.h \
    ../Cache/cachedishstate.h \
    dlgpretax.h \
    dlgprinttaxsideoption.h \
    ../Filter/fdailymovementcommon.h \
    ../Charts/chsample.h \
    dlgsearchinvoice.h \
    ../RowEditor/rebanquetcomment.h \
    ../Filter/fcityledgerbalanceextended.h \
    ../Filter/fcallhistory.h \
    dlgtaxback.h \
    ../Filter/fcardexsales.h \
    ../Filter/fcommonfilterbydate.h \
    dlgprintrandomtax.h \
    dlgtaxreference.h \
    ../Widgets/wvauchereditor.h \
    ../Widgets/wsyncinvoices.h \
    ../RowEditor/recomplimentarycomment.h \
    dlgexportsinglevaucher.h \
    ../Controls/etoolbarbutton.h \
    dlgwelcomebuttonconfig.h \
    ../Widgets/wreportbuilder.h \
    ../Widgets/wremarks.h \
    ../Controls/efilterlineedit.h \
    ../Print/pprintreceipt.h \
    ../Widgets/whotelstatus.h \
    dlgclinitialbalance.h \
    ../Filter/flistsourcereserve.h \
    ../Filter/fyearlyfinancialreport.h \
    ../Widgets/wcustomreports.h \
    dlgreportbuildergroups.h \
    ../Controls/ecomboboxcompleter.h \
    ../Widgets/wreportssetold.h \
    ../Controls/eradiobutton.h \
    ../Controls/ecombomonth.h \
    ../Base/baseuid.h \
    dlgviewinvoicecorrections.h \
    dlgperemovereason.h \
    dlgutils.h \
    dlgdishhistory.h \
    ../Cache/cachecheckoutinvoice.h \
    dlgremotinvoices.h \
    dlgopengrouporsingle.h \
    dlgexportother.h \
    dlgreserveconfirmstatus.h \
    ../Filter/freservaionremarks.h \
    dlgchangeexportvaucher.h \
    dlggroupreservationfuck.h \
    dlgsimpleselectroom.h \
    fnousedadvance.h \
    ../RoomChart/dlgooroomprop.h \
    fonlinerest.h \
    ../Cache/cachereservegroup.h \
    ../Filter/freservegroups.h \
    ../RowEditor/recardexgroup.h \
    ../RowEditor/reguesttitle.h \
    ../RowEditor/renationalityfile.h \
    dlghelp.h \
    ../Filter/froomstate.h \
    ../Filter/fcanceledreservations.h \
    ../Widgets/wweb.h \
    ../Filter/freservebycreate.h \
    ../Widgets/storedoc.h \
    ../RowEditor/restorepartner.h \
    ../Cache/cachestorepartners.h \
    ../Cache/cachestoredoc.h \
    ../Cache/cachestoredocstate.h \
    ../Base/defstore.h \
    ../Cache/cachecoupontype.h \
    dlgcalculateoutputofrestaurant.h \
    ../Base/defrest.h \
    fonlinebreakfast.h \
    ../Filter/fmonthlyoccperc.h \
    fnatbyperiod.h \
    dlgcl.h \
    dlgpaymentmode.h \
    dlgchangeclofvaucher.h \
    dlgnoshow.h \
    ../Filter/fnoshowcancelationfee.h \
    ../Filter/frestsalebystore.h \
    dlgcheckadvancebeforecancel.h \
    dlgrefundvaucher.h \
    dlgeditservtax.h \
    ../Cache/cachetaxmap.h \
    dlgreserveshortinfo.h \
    dlgnewvaucheroption.h \
    ../Filter/fallguestindaterange.h \
    ../RowEditor/remodelofcars.h \
    ../RowEditor/recarclient.h \
    ../Cache/cachecar.h \
    ../Cache/cacherestdebtholder.h \
    ../Filter/freportbypayment.h \
    ../Cache/cachedocpayment.h \
    fpartnersdebt.h \
    dlgcouponsales.h \
    ../Cache/cachecouponseria.h \
    ../Cache/cachecashdesk.h \
    ../Widgets/wcashentry.h \
    ../Cache/cachecashdoc.h \
    ../Widgets/wstoreentry.h \
    dlgpartnerpayment.h \
    dlgcashop.h \
    ../Filter/fcouponstatistics.h \
    ../Cache/cachedebtcostumer.h \
    ../Filter/fbreakfast.h \
    ../Filter/fsalary.h \
    ../../NewTax/Src/printtaxn.h \
    dlgprinttaxsm.h \
    dlgtaxback2.h \
    dlgpostbreakfast.h \
    ../Controls/eqdoubleedit.h \
    ../Cache/cacherestfullmenu.h \
    dlghouseitem.h \
    ../Filter/fhouseitems.h \
    dlgdebtpay.h \
    ../Vouchers/basevoucher.h \
    ../Vouchers/voucher_tc.h \
    ../Cache/cachecladvance.h \
    ../Filter/fcladvance.h \
    ../Print/pprintcheckin.h \
    ../Filter/fcitytrayledger.h \
    ../Filter/finhousedetailbalance.h \
    ../Filter/favailablerooms.h \
    ../Widgets/wdate2.h \
    ../Base/paymentmode.h \
    dlgconfiggrid.h \
    ../Base/appconfig.h \
    ../Cache/cacheroominventory.h \
    ../RowEditor/reroominventory.h \
    ../RowEditor/reroominventorystate.h \
    ../Cache/cacheroominventorystate.h \
    ../Cache/cacheroominventorystate.h \
    ../Print/pexportinvoicetoexcel.h \
    dlggroupreserveoption.h \
    ../Cache/cachegroupreservations.h \
    ../GridOptionWidgets/gowidget.h \
    ../GridOptionWidgets/godaily.h \
    ../Vouchers/voucher_av.h \
    dlgexport.h \
    goexpextedarrivals.h \
    smtp.h \
    dlgemail.h \
    ../Print/pprintstoredoc.h \
    ../Print/pprintstoreentry.h \
    ../Filter/guestcheckin.h \
    ../Filter/flengthofstay.h \
    ../Filter/fexportreservation.h \
    dlgreservationguests.h \
    ../Base/doubledatabase.h \
    ../Cache2/cache2.h \
    ../Cache/cacheinstance.h \
    ../Cache/cachebasestruct.h \
    ../Cache/cachereservationcardex.h \
    ../Cache/cachesex.h \
    dlgcreategroupreservation.h \
    ../Base/dlgexitbyversion.h \
    dlgexecfailedsqls.h \
    ../Filter/fdishes.h \
    ../Filter/froomarrangement.h \
    dlgclearlog.h \
    ../Filter/fwakeupcall.h \
    dlgwakepcalls.h \
    ../Filter/fdailytransaction.h \
    ../Filter/fhotelhierarchy.h \
    wroomchart.h \
    ../Filter/fcallrates.h \
    ../RowEditor/recallrate.h \
    wroomchartclasses.h \
    ../Print/printtaxd.h \
    wroomcharttime.h \
    wroomchartdock.h \
    dlgchartcolor.h \
    ../Cache/cachetransferfromcl.h \
    dbmregister.h \
    dlgquickroomassignment.h \
    dlgquickadvance.h \
    wquickroomassignment.h \
    dlgquickadvanceapply.h \
    dlggrouprevive.h \
    ../../XLSX/src/crs32.h \
    ../../XLSX/src/xlsx.h \
    ../../XLSX/src/xlsxall.h \
    ../../XLSX/src/xlsxcell.h \
    ../../XLSX/src/xlsxcontenttype.h \
    ../../XLSX/src/xlsxdocpropsapp.h \
    ../../XLSX/src/xlsxdocpropscore.h \
    ../../XLSX/src/xlsxdocument.h \
    ../../XLSX/src/xlsxrels.h \
    ../../XLSX/src/xlsxsharedstring.h \
    ../../XLSX/src/xlsxsheet.h \
    ../../XLSX/src/xlsxstyles.h \
    ../../XLSX/src/xlsxtheme.h \
    ../../XLSX/src/xlsxworkbook.h \
    ../../XLSX/src/xlsxwriter.h \
    ../../XLSX/src/zip.h \
    dlgtransferanyamount.h \
    ../Controls/radiogroupwidget.h \
    ../Filter/fexpectedarrivals2.h \
    ../Filter/fcitytrayledger2.h \
    ../Filter/fcitytrayledger2.h \
    dlgofferinvoiceextra.h \
    dlgpostcharge.h \
    wguestinvoice.h \
    ../Filter/wcardexlist.h

FORMS    += mainwindow.ui \
    ../Base/dlgselector.ui \
    ../Filter/fcashreportbyitem.ui \
    ../Filter/fexpecteddeparturesimple.ui \
    ../Filter/fexpectedsimple.ui \
    ../Filter/fforecastoccupancycategoryreal.ui \
    ../Filter/finhouseguestfuture.ui \
    ../Filter/froomstates.ui \
    ../Filter/ftaxreport.ui \
    dlgconfigtaxserver.ui \
    dlgexportas.ui \
    dlghdmviewer.ui \
    dlghouseitemonoffwidget.ui \
    dlginvoicepaymentoptions.ui \
    dlgmovetocl.ui \
    dlgoptions.ui \
    dlgprintvoucherasinvoice.ui \
    dlgquickadvanceaction.ui \
    dlgrecoverinvoice.ui \
    dlgseachfromdatabase.ui \
    dlgselectfiscalmachin.ui \
    dlgsingleprinttax.ui \
    dlgtransferlog.ui \
    login.ui \
    loginsettings.ui \
    message.ui \
    databasesconnections.ui \
    databaseconnection.ui \
    databasepasswordchange.ui \
    wactivegroup.ui \
    wcardex.ui \
    wchart.ui \
    wcityledger.ui \
    wmaindesk.ui \
    wmaindeskfilterlist.ui \
    wpaymentdetails.ui \
    wquickcheckout.ui \
    wquickcheckoutbalance.ui \
    wquickcheckoutprocess.ui \
    wquickreservations.ui \
    wquickreservationscheckin.ui \
    wquickreservationsguests.ui \
    wquickreservationspax.ui \
    wreservation.ui \
    wguest.ui \
    winvoice.ui \
    wreportgrid.ui \
    wroomcharttemprectdlg.ui \
    wtaxattack.ui \
    wwelcome.ui \
    dlgcontact.ui \
    dlgnotes.ui \
    about.ui \
    dlgfiltervalues.ui \
    dlgroom.ui \
    wreservationroomtab.ui \
    dlgchartdaterange.ui \
    dlgusergroup.ui \
    dlgroomview.ui \
    dlgendofday.ui \
    dlgcardex.ui \
    dwmaindeskhint.ui \
    dlgpaymentsdetails.ui \
    ../RowEditor/reresthall.ui \
    ../RowEditor/reresttable.ui \
    ../RowEditor/rerestmenunames.ui \
    ../RowEditor/rerestmenupart.ui \
    ../RowEditor/rerestdishtype.ui \
    ../RowEditor/rerestdish.ui \
    ../RowEditor/rerestdishmod.ui \
    ../RowEditor/rereststore.ui \
    ../RowEditor/rerestprinter.ui \
    ../RoomChart/reservewidget.ui \
    ../RoomChart/dlgreservequickinfo.ui \
    ../Filter/ftrackchanges.ui \
    ../RowEditor/reusers.ui \
    ../Print/pprintpreview.ui \
    ../RowEditor/recreditcard.ui \
    ../Filter/fcityledgerbalance.ui \
    dlguserpasswords.ui \
    dlgadvanceentry.ui \
    ../RoomChart/roomstate.ui \
    dlginvoicecancelation.ui \
    dlgraiseuser.ui \
    wglobaldbconfig.ui \
    dlggposorderinfo.ui \
    ../RowEditor/rerestdishcomplex.ui \
    ../RowEditor/reroomcategory.ui \
    ../RowEditor/reroombed.ui \
    ../RowEditor/reroomcategoryrate.ui \
    reroomcategoryraterow.ui \
    dlgtransfer.ui \
    ../Filter/finvoices.ui \
    waccinvoice.ui \
    dlgtracking.ui \
    ../Filter/frestauranttotal.ui \
    ../Filter/fdailymovement.ui \
    ../Filter/freservationscommon.ui \
    ../RoomChart/reservewidgetaction.ui \
    wgroupreserverect.ui \
    dlgdiscount.ui \
    ../Filter/fcategorytosell.ui \
    ../RowEditor/recurrency.ui \
    ../Filter/fforecastoccupancycategory.ui \
    ../Filter/faccmonthlyreport.ui \
    ../Print/dlgprintreservation.ui \
    dlgtaxprintsetup.ui \
    dlginvoiceprintoption.ui \
    ../RowEditor/reinvoiceitem.ui \
    ../Filter/finhouseguest.ui \
    ../Filter/fexpectedarrivals.ui \
    ../Widgets/wrecheckin.ui \
    ../Filter/fexpectedarrivalsimple.ui \
    ../Filter/fcashreportsummary.ui \
    dlgreceiptvaucher.ui \
    ../Filter/fcityledgerdetailedbalance.ui \
    ../Filter/fcashreport.ui \
    ../RowEditor/recityledger.ui \
    ../Filter/fvauchers.ui \
    dlguserrights.ui \
    dlgreservationremarks.ui \
    ../Filter/fevents.ui \
    dlgpretax.ui \
    dlgprinttaxsideoption.ui \
    ../Filter/fdailymovementcommon.ui \
    ../Charts/chsample.ui \
    dlgsearchinvoice.ui \
    ../RowEditor/rebanquetcomment.ui \
    ../Filter/fcityledgerbalanceextended.ui \
    ../Filter/fcallhistory.ui \
    dlgtaxback.ui \
    ../Filter/fcardexsales.ui \
    ../Filter/fcommonfilterbydate.ui \
    dlgprintrandomtax.ui \
    dlgtaxreference.ui \
    ../Widgets/wvauchereditor.ui \
    ../Widgets/wsyncinvoices.ui \
    ../RowEditor/recomplimentarycomment.ui \
    dlgexportsinglevaucher.ui \
    dlgwelcomebuttonconfig.ui \
    ../Widgets/wreportbuilder.ui \
    ../Controls/efilterlineedit.ui \
    ../Widgets/whotelstatus.ui \
    dlgclinitialbalance.ui \
    ../Filter/flistsourcereserve.ui \
    ../Filter/fyearlyfinancialreport.ui \
    ../Widgets/wcustomreports.ui \
    dlgreportbuildergroups.ui \
    ../Widgets/wreportssetold.ui \
    dlgviewinvoicecorrections.ui \
    dlgposremoveoption.ui \
    dlgperemovereason.ui \
    dlgutils.ui \
    dlgdishhistory.ui \
    dlgremotinvoices.ui \
    dlgopengrouporsingle.ui \
    dlgexportother.ui \
    dlgreserveconfirmstatus.ui \
    ../Filter/freservaionremarks.ui \
    dlgchangeexportvaucher.ui \
    dlggroupreservationfuck.ui \
    dlgsimpleselectroom.ui \
    fnousedadvance.ui \
    ../RoomChart/dlgooroomprop.ui \
    fonlinerest.ui \
    ../Filter/freservegroups.ui \
    ../RowEditor/recardexgroup.ui \
    ../RowEditor/reguesttitle.ui \
    ../RowEditor/renationalityfile.ui \
    dlghelp.ui \
    ../Filter/froomstate.ui \
    ../Filter/fcanceledreservations.ui \
    ../Widgets/wweb.ui \
    ../Filter/freservebycreate.ui \
    ../Widgets/storedoc.ui \
    ../RowEditor/restorepartner.ui \
    ../Filter/fstoremovement.ui \
    dlgcalculateoutputofrestaurant.ui \
    fonlinebreakfast.ui \
    ../Filter/fmonthlyoccperc.ui \
    fnatbyperiod.ui \
    dlgcl.ui \
    dlgpaymentmode.ui \
    dlgchangeclofvaucher.ui \
    dlgnoshow.ui \
    ../Filter/fnoshowcancelationfee.ui \
    ../Filter/frestsalebystore.ui \
    dlgcheckadvancebeforecancel.ui \
    dlgrefundvaucher.ui \
    dlgeditservtax.ui \
    dlgreserveshortinfo.ui \
    dlgnewvaucheroption.ui \
    ../Filter/fallguestindaterange.ui \
    ../RowEditor/remodelofcars.ui \
    ../RowEditor/recarclient.ui \
    ../Filter/freportbypayment.ui \
    fpartnersdebt.ui \
    dlgcouponsales.ui \
    ../Widgets/wcashentry.ui \
    ../Widgets/wstoreentry.ui \
    dlgpartnerpayment.ui \
    dlgcashop.ui \
    ../Filter/fcouponstatistics.ui \
    ../Filter/fbreakfast.ui \
    ../Filter/fsalary.ui \
    ../Filter/fsalesbycar.ui \
    dlgprinttaxsm.ui \
    ../Filter/fdiscounttotal.ui \
    dlgtaxback2.ui \
    dlgpostbreakfast.ui \
    dlghouseitem.ui \
    ../Filter/fhouseitems.ui \
    dlgdebtpay.ui \
    ../Filter/fcladvance.ui \
    ../Filter/fcitytrayledger.ui \
    ../Filter/finhousedetailbalance.ui \
    ../Filter/favailablerooms.ui \
    ../Widgets/wdate2.ui \
    dlgconfiggrid.ui \
    ../RowEditor/reroominventory.ui \
    ../RowEditor/reroominventorystate.ui \
    dlggroupreserveoption.ui \
    ../GridOptionWidgets/godaily.ui \
    dlgexport.ui \
    goexpextedarrivals.ui \
    dlgemail.ui \
    ../Filter/guestcheckin.ui \
    ../Filter/flengthofstay.ui \
    ../Filter/fexportreservation.ui \
    dlgreservationguests.ui \
    dlgcreategroupreservation.ui \
    ../Base/dlgexitbyversion.ui \
    dlgexecfailedsqls.ui \
    ../Filter/fdishes.ui \
    ../Filter/froomarrangement.ui \
    dlgclearlog.ui \
    ../Filter/fwakeupcall.ui \
    dlgwakepcalls.ui \
    ../Filter/fdailytransaction.ui \
    ../Filter/fhotelhierarchy.ui \
    wroomchart.ui \
    ../Filter/fcallrates.ui \
    ../RowEditor/recallrate.ui \
    ../Print/printtaxd.ui \
    wroomchartdock.ui \
    dlgchartcolor.ui \
    dlgquickroomassignment.ui \
    dlgquickadvance.ui \
    wquickroomassignment.ui \
    dlgquickadvanceapply.ui \
    dlggrouprevive.ui \
    dlgtransferanyamount.ui \
    ../Filter/fexpectedarrivals2.ui \
    ../Filter/fcitytrayledger2.ui \
    ../Filter/fcitytrayledger2.ui \
    dlgofferinvoiceextra.ui \
    dlgpostcharge.ui \
    wguestinvoice.ui

RESOURCES += \
    res.qrc

LIBS += -lVersion
LIBS += -LC:/Soft/OpenSSL-Win32/lib
LIBS += -lopenssl
LIBS += -llibcrypto
LIBS +=  -lwsock32

DISTFILES += \
    last_cache.txt

INCLUDEPATH += C:/Projects/Resort/Base
INCLUDEPATH += C:/Projects/Resort/Cache
INCLUDEPATH += C:/Projects/Resort/Cache2
INCLUDEPATH += C:/Projects/Resort/Selector
INCLUDEPATH += C:/Projects/Resort/Controls
INCLUDEPATH += C:/Projects/Resort/RowEditor
INCLUDEPATH += C:/Projects/Resort/RoomChart
INCLUDEPATH += C:/Projects/Resort/Filter
INCLUDEPATH += C:/Projects/Resort/Threads
INCLUDEPATH += C:/Projects/Resort/Print
INCLUDEPATH += C:/Projects/Resort/Widgets
INCLUDEPATH += C:/Projects/Resort/RGDoubleClick
INCLUDEPATH += C:/Projects/Resort/GridOptionWidgets
INCLUDEPATH += C:/Projects/Resort/Vouchers
INCLUDEPATH += C:/Projects/Resort/Server2
INCLUDEPATH += C:/Soft/OpenSSL-Win32/include
INCLUDEPATH += C:/Soft/OpenSSL-Win32/include/openssl
INCLUDEPATH += C:/projects/NewTax/Src
INCLUDEPATH += c:/projects/XLSX/src

DEFINES += _ORGANIZATION_=\\\"SmartHotel\\\"
DEFINES += _APPLICATION_=\\\"SmartHotel\\\"
DEFINES += _DBDRIVER_=\\\"QMYSQL\\\"
