#include "pprintstoredoc.h"
#include "pprintpreview.h"
#include "pprintscene.h"
#include "ptextrect.h"
#include "cacheinvoiceitem.h"
#include "pimage.h"
#include "cachestoredoc.h"
#include "cachedish.h"
#include "cachereststore.h"
#include <QApplication>
#include <QMessageBox>

PPrintStoreDoc::PPrintStoreDoc(QWidget *parent) :
    BaseWidget(parent)
{

}

void PPrintStoreDoc::print(const QString &id)
{
    PPrintStoreDoc p;
    p.fDocId = id;
    p.printDoc();
}

void PPrintStoreDoc::printDoc()
{
    DoubleDatabase dr1;
    dr1[":f_id"] = fDocId;
    dr1.exec("select * from r_docs where f_id=:f_id");
    if (!dr1.nextRow()) {
        QMessageBox::critical(fPreferences.getDefaultParentForMessage(), tr("Error"), tr("Document number is not exists"));
        return;
    }

    int rowHeight = 80;
    int top = 5;
    PPrintPreview *pp = new PPrintPreview();
    PPrintScene *ps = pp->addScene(0,QPageLayout::Portrait);
    QString invHeader = tr("Store document #") + fDocId;
    PTextRect *trHeader = new PTextRect(20, 20, 2100, 200, invHeader, 0, QFont(qApp->font().family(), 50));
    trHeader->setBorders(false, false, false, false);
    trHeader->setTextAlignment(Qt::AlignHCenter);
    top += ps->addTextRect(trHeader)->textHeight();
    PTextRect trAll;
    trAll.setBorders(false, false, false, false);
    trAll.setFont(QFont(qApp->font().family(), 30));
    ps->addTextRect(10, top, 600, rowHeight, tr("Date"), &trAll);
    top += ps->addTextRect(610, top, 400, rowHeight, dr1.getValue("f_date").toDate().toString(def_date_format), &trAll)->textHeight();
    CacheStoreDocType csdt;
    csdt.get(dr1.getValue("f_type").toString());
    top += ps->addTextRect(10, top, 600, rowHeight, csdt.fName(), &trAll)->textHeight();

    DoubleDatabase dr2;
    dr2[":f_doc"] = fDocId;
    dr2.exec("select * from r_body where f_doc=:f_doc and f_sign=1");
    if (dr1.getValue("f_type").toInt() == 3) {
        dr2[":f_doc"] = fDocId;
        dr2.exec("select * from r_body where f_doc=:f_doc");
    }

    if (dr2.rowCount() > 0) {
        QString storage = tr("Storage, input");
        if (dr1.getValue("f_type").toInt() == 3) {
            storage = tr("Storage, output");
        }
        ps->addTextRect(10, top, 460, rowHeight, storage, &trAll);
        CacheRestStore crs;
        crs.get(dr2.getValue("f_store").toString());
        top += ps->addTextRect(610, top, 400, rowHeight, crs.fName(), &trAll)->textHeight();
        if (dr1.getValue("f_type").toInt() == 2) {
            DoubleDatabase dr3;
            dr3[":f_doc"] = fDocId;
            dr3.exec("select * from r_body where f_doc=:f_doc and f_sign=-1");
            ps->addTextRect(10, top, 600, rowHeight, tr("Storage, output"), &trAll);
            crs.get(dr2.getValue("f_store").toString());
            top += ps->addTextRect(610, top, 400, rowHeight, crs.fName(), &trAll)->textHeight();
        }
    }

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
        cd.get(dr2.getValue(i, "f_material").toString());
        val << cd.fName()
            << float_str(dr2.getValue(i, "f_qty").toDouble(), 2)
            << float_str(dr2.getValue(i, "f_price").toDouble(), 2)
            << float_str(dr2.getValue(i, "f_total").toDouble(), 2);
        ps->addTableRow(top, rowHeight, col, val, &trAll);
    }
    top += 10;
    ps->addTextRect(10, top, 800, rowHeight, tr("Total"), &trAll);
    ps->addTextRect(810, top, 300, rowHeight, float_str(dr1.getValue("f_amount").toDouble(), 2), &trAll);
    pp->exec();
    delete pp;
}
