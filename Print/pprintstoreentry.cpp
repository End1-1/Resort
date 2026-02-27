#include "pprintstoreentry.h"
#include "pprintpreview.h"
#include "pprintscene.h"
#include "ptextrect.h"
#include "cacheinvoiceitem.h"
#include "pimage.h"
#include "cachedish.h"
#include "cachestoredoc.h"
#include "cachereststore.h"
#include <QApplication>
#include <QMessageBox>

PPrintStoreEntry::PPrintStoreEntry(QWidget *parent) :
    BaseWidget(parent)
{

}

void PPrintStoreEntry::print(const QString &id)
{
    PPrintStoreEntry p;
    p.fDockId = id;
    p.printDoc();
}

void PPrintStoreEntry::printDoc()
{
    DoubleDatabase dr1;
    dr1.open();
    dr1[":f_id"] = fDockId;
    dr1.exec("select * from st_header where f_id=:f_id");
    if (dr1.rowCount() == 0) {
        QMessageBox::critical(fPreferences.getDefaultParentForMessage(), tr("Error"), tr("Document number is not exists"));
        return;
    }

    int rowHeight = 80;
    int top = 5;
    PPrintPreview *pp = new PPrintPreview();
    PPrintScene *ps = pp->addScene(0,QPageLayout::Portrait);
    QString invHeader = tr("Store document") + " #" + fDockId;
    PTextRect *trHeader = new PTextRect(20, 20, 2100, 200, invHeader, 0, QFont(qApp->font().family(), 50));
    trHeader->setBorders(false, false, false, false);
    trHeader->setTextAlignment(Qt::AlignHCenter);
    top += ps->addTextRect(trHeader)->textHeight();
    PTextRect trAll;
    trAll.setBorders(false, false, false, false);
    trAll.setFont(QFont(qApp->font().family(), 30));
    ps->addTextRect(10, top, 600, rowHeight, tr("Date"), &trAll);
    top += ps->addTextRect(610, top, 400, rowHeight, dr1.getValue("f_date").toDate().toString(def_date_format), &trAll)->textHeight();
    ps->addTextRect(10, top, 600, rowHeight, tr("Storage"), &trAll);
    CacheRestStore crs;
    crs.get(dr1.getValue("f_store").toString());
    top += ps->addTextRect(610, top, 400, rowHeight, crs.fName(), &trAll)->textHeight();

    DoubleDatabase dr2;
    DoubleDatabase fDD;
    dr2.open();
    fDD[":f_doc"] = fDockId;
    dr2.exec("select * from st_body where f_doc=:f_doc");

    trAll.setBorders(true, true, true, true);
    for (int i = 0; i < dr2.rowCount(); i++) {
        if (top > sizePortrait.height()) {
            top = 5;
            ps = pp->addScene(0,QPageLayout::Portrait);
        }
        QList<int> col;
        col << 10 << 800 << 250 << 250 << 250;
        QStringList val;
        CacheDish cd;
        cd.get(dr2.getValue(i, "f_goods").toString());
        val << cd.fName()
            << float_str(dr2.getValue(i, "f_qty").toDouble(), 2)
            << float_str(dr2.getValue(i, "f_amount").toDouble(), 2);
        ps->addTableRow(top, rowHeight, col, val, &trAll);
    }
    top += 10;
    ps->addTextRect(10, top, 800, rowHeight, tr("Total"), &trAll);
    ps->addTextRect(810, top, 300, rowHeight, float_str(dr1.getValue("f_amount").toDouble(), 2), &trAll);
    pp->exec();
    delete pp;
}
