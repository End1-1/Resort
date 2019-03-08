#include "fdishes.h"
#include "ui_fdishes.h"
#include "wreportgrid.h"
#include "cacherestdishtype.h"
#include "rerestdish.h"

FDishes::FDishes(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FDishes)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Dishes"), ":/images/cutlery.png");
    connect(fReportGrid, SIGNAL(doubleClickOnRow(QList<QVariant>)), this, SLOT(doubleClickOnRow(QList<QVariant>)));
    connect(fReportGrid, SIGNAL(newBtn()), this, SLOT(newBtn()));
    ui->leTypeCode->setSelector(this, cache(cid_rest_dish_type), ui->leTypeCode);
    fReportGrid->setBtnNewVisible(true);
    //fReportGrid->fRowEditorDialog = new RERestDish(fReportGrid->fRowValues, this);
}

FDishes::~FDishes()
{
    delete ui;
}

QString FDishes::reportTitle()
{
    return tr("Dishes");
}

QWidget *FDishes::firstElement()
{
    return ui->leTypeCode;
}

void FDishes::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(100, "", tr("Code"))
            .setColumn(120, "", tr("Part"))
            .setColumn(0, "", tr("Type code"))
            .setColumn(120, "", tr("Type"))
            .setColumn(150, "", tr("Name, am"))
            .setColumn(150, "", tr("Name, en"))
            .setColumn(150, "", tr("Name, ru"))
            .setColumn(0, "", tr("Description, am"))
            .setColumn(0, "", tr("Description, en"))
            .setColumn(0, "", tr("Description, ru"))
            .setColumn(0, "", tr("Background"))
            .setColumn(0, "", tr("Text color"))
            .setColumn(0, "", tr("Queue"))
            .setColumn(80, "", tr("ADGT"))
            .setColumn(80, "", tr("ArmSoft code"))
            .setColumn(80, "", tr("Last price"));


    QString query = "select d.f_id, p.f_" + def_lang + ", d.f_type, t.f_" + def_lang +", "
            "d.f_am, d.f_en, d.f_ru, d.f_text_am, d.f_text_en, d.f_text_ru, "
            "d.f_bgColor, d.f_textColor, d.f_queue, d.f_adgt, d.f_as, f_lastPrice "
            "from r_dish d "
            "inner join r_dish_type t on t.f_id=d.f_type "
            "inner join r_dish_part p on p.f_id=t.f_part where d.f_id>0 :cond "
            "order by p.f_" + def_lang + ", t.f_" + def_lang + ", d.f_queue";
    QString where;
    if (ui->leTypeCode->len() > 0) {
        where += " and d.f_type in (" + ui->leTypeCode->text() + ") ";
    }
    rg->fModel->setSqlQuery(query.replace(":cond", where));
    rg->fModel->apply(rg);
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.exec("select f_id, f_en from r_menu_names");
    QStringList titles;
    while (fDD.nextRow()) {
        titles << fDD.getString(1);
    }
    currCols = rg->fModel->columnCount();
    rg->fModel->appendColumns(titles.count(), titles);
    fDD.exec("select d.f_id, mn.f_en, m.f_price \
             from r_menu m \
             inner join r_dish d on m.f_dish=d.f_id \
             inner join r_menu_names mn on mn.f_id=m.f_menu \
             where m.f_state=1 \
             order by d.f_id ");
    QMap<int, int> rows;
    QMap<QString, int> cols;
    for (int i = 0; i < rg->fModel->rowCount(); i++) {
        rows[rg->fModel->data(i, 0).toInt()] = i;
    }
    for (int i = 0; i < titles.count(); i++) {
        cols[titles[i]] = i + currCols;
    }
    while (fDD.nextRow()) {
        rg->fModel->setData(rows[fDD.getInt(0)], cols[fDD.getString(1)], fDD.getDouble(2));
    }
}

void FDishes::doubleClickOnRow(const QList<QVariant> row)
{
    QList<QVariant> vals = row;
    for (int i = vals.count() - 1; i > currCols; i--) {
        vals.removeAt(i);
    }
    RERestDish *d = new RERestDish(vals, this);
    d->setValues();
    d->exec();
    delete d;
}

void FDishes::newBtn()
{
    QList<QVariant> vals;
    RERestDish *d = new RERestDish(vals, this);
    d->setValues();
    d->exec();
    delete d;
}
