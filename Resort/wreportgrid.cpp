#include "wreportgrid.h"
#include <QClipboard>
#include <QDesktopServices>
#include <QException>
#include <QFileDialog>
#include <QLayout>
#include <QMenu>
#include <QPrinter>
#include <QPrinterInfo>
#include <QScrollBar>
#include <QShortcut>
#include "dlgconfiggrid.h"
#include "dlgfiltervalues.h"
#include "dlghelp.h"
#include "pimage.h"
#include "pprintscene.h"
#include "ptextrect.h"
#include "ui_wreportgrid.h"
#include "wfilterbase.h"
#include <xlsxdocument.h>

QMap<QString, Report> WReportGrid::fReportOptions;
static const int font_size_print_delta = 16;

WReportGrid::WReportGrid(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WReportGrid)
{
    ui->setupUi(this);
    ui->tblTotals->setVisible(false);
    ui->tblMain->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->tblMain->setContextMenuPolicy(Qt::CustomContextMenu);
    fModel = new TableModel(ui->tblMain, ui->tblTotals);
    connect(fModel, SIGNAL(rowCount(int)), this, SLOT(rowCount(int)));
    fModel->fTableView = ui->tblMain;
    fTableView = ui->tblMain;
    fTableTotal = ui->tblTotals;
    fRowEditorDialog = nullptr;
    ui->btnNew->setVisible(false);
    fFilter = nullptr;
    fTitleWidget = nullptr;
    fRgDoubleClick = nullptr;
    ui->tblMain->horizontalHeader()->setContextMenuPolicy(Qt::CustomContextMenu);
    fTableMenu = new QMenu();
    connect(fTableMenu->addAction("Filter on column values"), SIGNAL(triggered(bool)), this,
            SLOT(actionFilterColumn(bool)));
    connect(ui->tblMain->horizontalHeader(), SIGNAL(customContextMenuRequested(QPoint)), this,
            SLOT(tblMainCustomeMenu(QPoint)));
    connect(ui->tblTotals->horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(totalGridHScroll(int)));
    connect(ui->tblMain->horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(tblMainGridHScroll(int)));
    connectHeaderResize();
    connect(ui->tblMain->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(tblMainHeaderClicked(int)));
    fGridMenu = new QMenu();
    connect(fGridMenu->addAction("Copy"), SIGNAL(triggered(bool)), this, SLOT(actionCopyGrid(bool)));
    connect(ui->tblMain, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(tblMaingridCustomMenu(QPoint)));
    fTrackControl = new TrackControl(TRACK_REPORT);
    connect(fModel, SIGNAL(newSum(QList<int>, QList<double>)), this, SLOT(newSum(QList<int>, QList<double>)));
    connect(fModel, SIGNAL(endApply()), this, SLOT(endApply()));
    ui->btnHelp->setVisible(false);
    ui->scrollArea->setVisible(false);
    fPrintOut = false;
    fPrintOutReady = false;
    QShortcut *sregInReports = new QShortcut(QKeySequence("Ctrl+Shift+R"), this);
    connect(sregInReports, SIGNAL(activated()), this, SLOT(registerInReportBuilder()));
    if (fReportOptions.count() == 0) {
        DoubleDatabase dd;
        dd[":f_group"] = WORKING_USERGROUP;
        dd.exec("select * from rp_main where f_group=:f_group");
        while (dd.nextRow()) {
            Report r;
            r.fFontName = dd.getString("f_fontname");
            r.fFontSize = dd.getInt("f_fontsize");
            r.fPrintOnly = dd.getInt("f_printonly");
            r.fFontBold = dd.getInt("f_fontbold");
            r.fRowHeight = dd.getInt("f_rowheight");
            fReportOptions[dd.getString("f_report")] = r;
        }
    }
    ui->gv->horizontalScrollBar()->blockSignals(true);
    ui->gv->verticalScrollBar()->blockSignals(true);
    setPageLayout(QPageLayout::Portrait);
    ui->cbPrinters->addItems(QPrinterInfo::availablePrinterNames());
    ui->cbPrinters->setCurrentIndex(ui->cbPrinters->findText(QPrinterInfo::defaultPrinterName()));
    ui->wPrint->setVisible(false);
    ui->btnPrint2->setVisible(false);
    fPageNumber = 0;
    fScaleFactor = 1.0;
    ui->tblMain->setWordWrap(false);
}

WReportGrid::~WReportGrid()
{
    delete ui;
}

void WReportGrid::getModelData(QList<QList<QVariant> > &out)
{
    out.clear();
}

void WReportGrid::setHelp(const QString &helpFile)
{
    fHelp = helpFile;
    ui->btnHelp->setVisible(!fHelp.isEmpty());
}

void WReportGrid::connectHeaderResize()
{
    connect(ui->tblMain->horizontalHeader(), SIGNAL(sectionResized(int, int, int)), this, SLOT(tblMainHeaderResized(int,
            int, int)));
}

void WReportGrid::disconnectHeaderResize()
{
    disconnect(ui->tblMain->horizontalHeader(), SIGNAL(sectionResized(int, int, int)), this, SLOT(tblMainHeaderResized(int,
               int, int)));
}

void WReportGrid::dontResizeSave(bool v)
{
    fSaveResizedColumn = !v;
}

void WReportGrid::processValues(int row, bool isNew)
{
    if (isNew) {
        fRowValues.clear();
    } else {
        emit doubleClickOnRow(fRowValues);
    }
    if (fRowEditorDialog) {
        fRowEditorDialog->setValues();
        if (fRowEditorDialog->exec() == QDialog::Accepted) {
            if (isNew) {
                for (int i = fRowValues.count(); i < fModel->columnCount(); i++) {
                    fRowValues << QVariant();
                }
                fModel->appendRow(fRowValues);
            } else {
                fModel->updateRowValues(row, fRowValues);
            }
        }
    } else {
        if (isNew) {
            emit newBtn();
        }
    }
}

void WReportGrid::setBtnNewVisible(bool value)
{
    ui->btnNew->setVisible(value);
}

QWidget *WReportGrid::gridOptionWidget()
{
    if (fFilter) {
        return fFilter->gridOptionWidget();
    }
    return nullptr;
}

void WReportGrid::totalGridHScroll(int value)
{
    ui->tblMain->horizontalScrollBar()->setValue(value);
}

void WReportGrid::tblMainGridHScroll(int value)
{
    ui->tblTotals->horizontalScrollBar()->setValue(value);
}

QToolButton *WReportGrid::addToolBarButton(const QString &image, const QString &text, const char *slot,
        QObject *receiver, int pos)
{
    QToolButton *b = new QToolButton(this);
    b->setIcon(QIcon(image));
    b->setText(text);
    b->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    if (!receiver) {
        receiver = this;
    }
    connect(b, SIGNAL(clicked()), receiver, slot);
    if (pos == 1000) {
        pos = 6;
    }
    ui->hlToolbar->insertWidget(pos, b);
    return b;
}

int WReportGrid::fillRowValuesOut(QList<QVariant> &out)
{
    out.clear();
    QModelIndexList sel = ui->tblMain->selectionModel()->selectedIndexes();
    if (sel.count() == 0) {
        return -1;
    }
    for (int i = 0; i < fModel->columnCount(); i++) {
        out << fModel->data(sel.at(0).row(), i, Qt::EditRole);
    }
    return sel.at(0).row();
}

void WReportGrid::setTblTotalData(const QList<int> &columns, const QList<double> &values)
{
    ui->tblTotals->setVisible(true);
    ui->tblMain->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tblTotals->clear();
    for (int i = 0; i < ui->tblTotals->columnCount(); i++) {
        ui->tblTotals->setItem(0, i, new C5TableWidgetItem());
    }
    for (int i = 0, count = columns.count(); i < count; i++) {
        ui->tblTotals->setItemWithValue(0, columns.at(i), values.at(i));
    }
    QStringList l;
    l << QString::number(fModel->rowCount());
    ui->tblTotals->setVerticalHeaderLabels(l);
}

void WReportGrid::setTblNoTotalData()
{
    ui->tblTotals->setVisible(false);
    ui->tblMain->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->tblTotals->clear();
}

void WReportGrid::countToTotal(int col)
{
    ui->tblTotals->setItem(0, col, new C5TableWidgetItem(QString::number(fModel->rowCount())));
}

void WReportGrid::setup()
{
    BaseWidget::setup();
}

void WReportGrid::setupTabTextAndIcon(const QString &name, const QString &image)
{
    fGridClassName = name;
    fTableView->setProperty("wgridclassname", _APPLICATION_ + QString("\\Grid\\") + fGridClassName);
    BaseWidget::setupTabTextAndIcon(name, image);
    if (fReportOptions.contains(fGridClassName)) {
        Report r = fReportOptions[fGridClassName];
        if (r.fPrintOnly) {
            ui->scrollArea->setVisible(true);
            ui->wPrint->setVisible(true);
            ui->tblMain->setVisible(false);
            ui->tblTotals->setVisible(false);
            fPrintOut = true;
            ui->btnPrint->setVisible(false);
            ui->btnPrint2->setVisible(true);
        }
        if (r.fRowHeight < 10) {
            r.fRowHeight = 21;
        }
        ui->tblMain->verticalHeader()->setDefaultSectionSize(r.fRowHeight);
        QFont font(r.fFontName, r.fFontSize);
        font.setBold(r.fFontBold);
        ui->tblMain->setFont(font);
        ui->tblTotals->setFont(font);
    } else {
        ui->tblMain->verticalHeader()->setDefaultSectionSize(21);
    }
}

void WReportGrid::on_leQuickSearch_textChanged(const QString &arg1)
{
    fModel->searchInTable(arg1.trimmed());
}

void WReportGrid::on_btnExcel_clicked()
{
    int colCount = fModel->columnCount();
    int rowCount = fModel->rowCount();
    if (colCount == 0 || rowCount == 0) {
        message_error(tr("Empty report!"));
        return;
    }
    QXlsx::Document d;
    d.addSheet("Sheet1");
    /* HEADER */
    QColor color = QColor::fromRgb(0, 0, 0);
    QFont headerFont(qApp->font());
    headerFont.setBold(true);
    QXlsx::Format formatHeader;
    formatHeader.setFont(headerFont);
    formatHeader.setBorderStyle(QXlsx::Format::BorderThin);
    for (int i = 0; i < colCount; i++) {
        d.write(1, i + 1, fModel->columnTitle(i), formatHeader);
        d.setColumnWidth(i + 1, fModel->columnWidth(i) / 7 );
    }
    /* BODY */
    QFont bodyFont(qApp->font());
    QXlsx::Format formatBody;
    formatBody.setFontColor(color);
    formatBody.setFontSize(bodyFont.pointSize());
    formatBody.setBorderStyle(QXlsx::Format::BorderThin);
    for (int j = 0; j < rowCount; j++) {
        for (int i = 0; i < colCount; i++) {
            QVariant v = fModel->data(j, i, Qt::EditRole);
            d.write(j + 2, i + 1, v, formatBody);
        }
    }
    /* TOTALS ROWS */
    if (ui->tblTotals->isVisible()) {
        for (int i = 0; i < colCount; i++) {
            QVariant v = ui->tblTotals->itemValue(0, i, Qt::EditRole);
            d.write(1 + fModel->rowCount() + 1, i + 1,  v, formatHeader);
        }
    }
    QString filename = QFileDialog::getSaveFileName(this, "", "", "*.xlsx");
    if (filename.isEmpty()) {
        return;
    }
    if (!d.saveAs(filename)) {
        QMessageBox::critical(this, tr("Error"), tr("Excel file not saved"));
        return;
    }
    QDesktopServices::openUrl(filename);
}

void WReportGrid::on_tblMain_doubleClicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    if (fRgDoubleClick) {
        fRgDoubleClick->doubleClick(fModel, index.row());
    } else {
        fillRowValues(index.row());
        processValues(index.row(), false);
    }
    emit tblMainDoubleClick(index);
}

void WReportGrid::on_btnNew_clicked()
{
    processValues(-1, true);
}

void WReportGrid::on_btnRefresh_clicked()
{
    if (fFilter) {
        fFilter->apply(this);
    } else {
        fModel->apply(this);
    }
    if (!ui->leQuickSearch->text().isEmpty()) {
        on_leQuickSearch_textChanged(ui->leQuickSearch->text());
    }
    ui->tblMain->horizontalScrollBar()->setValue(0);
    ui->tblTotals->horizontalScrollBar()->setValue(0);
}

void WReportGrid::fillRowValues(int row)
{
    fRowValues.clear();
    for (int i = 0; i < fModel->columnCount(); i++) {
        fRowValues << fModel->data(row, i, Qt::EditRole);
    }
}

void WReportGrid::setPage()
{
    ui->lbPage->setText(QString("%1 %2 %3 %4")
                        .arg(tr("Page"))
                        .arg(fPageNumber)
                        .arg(tr("of"))
                        .arg(fPrintScene.count()));
    ui->gv->setScene(fPrintScene.at(fPageNumber - 1));
    ui->btnFirst->setEnabled(fPageNumber > 1);
    ui->btnBack->setEnabled(fPageNumber > 1);
    ui->btnLast->setEnabled(fPageNumber < fPrintScene.count());
    ui->btnNext->setEnabled(fPageNumber < fPrintScene.count());
}

PPrintScene *WReportGrid::addScene(int tmpl, QPageLayout::Orientation po)
{
    PPrintScene *ps = nullptr;
    switch (tmpl) {
        case 0:
            ps = new PPrintScene(po, this);
            break;
        case 1:
            ps = new PPrintScene(this);
            break;
    }
    QSize s = po == QPageLayout::Portrait ? sizePortrait : sizeLandscape;
    QSize wSize = s;
    wSize.setWidth(sizePortrait.width() / 3);
    wSize.setHeight(wSize.width());
    QPixmap p = QPixmap("./logo_transp.png");
    QGraphicsPixmapItem *pi = ps->addPixmap(p);
    pi->setPos((s.width() / 2) - (wSize.width() / 2), (s.height() / 2) - (wSize.height() / 2));
    fPrintScene.append(ps);
    return ps;
}

void WReportGrid::setPageLayout(QPageLayout::Orientation po)
{
    QSize s(po == QPageLayout::Portrait ? sizePortrait : sizeLandscape);
    s.setWidth(s.width() * 1.5);
    s.setHeight(s.height() * 1.5);
    ui->gv->setMinimumSize(s);
    ui->gv->setMaximumSize(s);
}

void WReportGrid::printOnPaper()
{
    QString title = "NO TITLE";
    bool official = false;
    if (fFilter) {
        title = fFilter->reportTitle();
        official = fFilter->officialTitle();
    } else if (fTabWidget) {
        title = fTabWidget->tabText(fTabIndex);
    }
    if (fTitleWidget) {
        official = false;
        title = fTitleWidget->title();
    }
    QList<int> printPages;
    switch (ui->cbPrintSelection->currentIndex()) {
        case 0:
            for (int i = 0; i < fPrintScene.count(); i++) {
                printPages << i;
            }
            break;
        case 1:
            printPages << fPageNumber - 1;
            break;
        case 2: {
            QStringList p = ui->lePages->text().replace(" ", "").split(",", Qt::SkipEmptyParts);
            foreach (QString s, p) {
                int page = s.toInt() - 1;
                if (page < 0 || page > fPrintScene.count() - 1) {
                    continue;
                }
                printPages << page;
            }
            break;
        }
    }
    QPrinter prn;
    prn.setPageSize(QPageSize::A4);
    prn.setPrinterName(ui->cbPrinters->currentText());
    prn.setPageOrientation(fPrintScene.at(printPages.at(0))->fPageLayout == QPageLayout::Portrait
                               ? QPageLayout::Portrait
                               : QPageLayout::Landscape);
    QPainter painter( &prn);
    for (int i = 0; i < printPages.count(); i++) {
        if (i > 0) {
            prn.setPageOrientation(fPrintScene.at(printPages.at(i))->fPageLayout);
            prn.newPage();
        }
        fPrintScene.at(printPages.at(i))->render( &painter);
    }
    fTrackControl->insert("Print report", title, "");
}

void WReportGrid::registerInReportBuilder(bool msg)
{
    DoubleDatabase dd;
    dd[":f_report"] = fGridClassName;
    dd[":f_group"] = WORKING_USERGROUP;
    dd.exec("select f_id from rp_main where f_group=:f_group and lower(f_report)=lower(:f_report)");
    if (!dd.nextRow()) {
        dd[":f_report"] = fGridClassName;
        dd[":f_group"] = WORKING_USERGROUP;
        dd[":f_printonly"] = false;
        dd[":f_fontname"] = qApp->font().family();
        dd[":f_fontsize"] = qApp->font().pointSize();
        dd[":f_fontbold"] = 0;
        dd.insert("rp_main", false);
    }
    fReportOptions.clear();
    if (msg) {
        message_info(tr("Registered in report builder"));
    }
}

void WReportGrid::addFilterWidget(WFilterBase *f)
{
    if (!f) {
        return;
    }
    if (f->layout() != nullptr) {
        f->layout()->setSizeConstraint(QLayout::SetMinimumSize);
        f->layout()->setContentsMargins(0, 0, 0, 0);
    }
    fFilter = f;
    ui->hl->addWidget(f);
    if (fFilter->firstElement()) {
        fFilter->firstElement()->setFocus();
    }
    fFilter->installEventFilter(this);
    //adjustSize();
}

void WReportGrid::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_E:
            if (event->modifiers() &Qt::ControlModifier) {
                on_btnExcel_clicked();
            }
            break;
        case Qt::Key_P:
            if (event->modifiers() &Qt::ControlModifier) {
                on_btnPrint_clicked();
            }
            break;
        case Qt::Key_S:
            if (event->modifiers() &Qt::ControlModifier) {
                ui->leQuickSearch->setFocus();
            }
            break;
        case Qt::Key_Enter:
        case Qt::Key_Return:
            if (fFilter) {
                if (focusWidget() == fFilter->lastElement()) {
                    on_btnRefresh_clicked();
                }
            }
            break;
    }
    QWidget::keyPressEvent(event);
}

bool WReportGrid::event(QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *ke = static_cast<QKeyEvent *>(event);
        switch (ke->key()) {
            case Qt::Key_Enter:
            case Qt::Key_Return: {
                QWidget *w = focusWidget();
                focusNextChild();
                if (fFilter) {
                    QWidget *l = fFilter->lastElement();
                    if (w == l) {
                        on_btnRefresh_clicked();
                    }
                }
                return true;
            }
        }
    }
    return BaseWidget::event(event);
}

void WReportGrid::newSum(const QList<int> &columns, const QList<double> &values)
{
    setTblTotalData(columns, values);
}

void WReportGrid::tblMainHeaderClicked(int index)
{
    fModel->sort(index);
}

void WReportGrid::tblMainHeaderResized(int index, int oldSize, int newSize)
{
    Q_UNUSED(oldSize)
    ui->tblTotals->setColumnWidth(index, newSize);
    if (fSaveResizedColumn) {
        QSettings s(_ORGANIZATION_, _APPLICATION_ + QString("\\Grid\\") + fGridClassName);
        QStringList cols;
        for (int i = 0; i < fModel->columnCount(); i++) {
            cols << QString::number(ui->tblMain->columnWidth(i));
        }
        s.setValue("ColumnsWidths", cols.join(","));
    }
}

void WReportGrid::tblMainCustomeMenu(const QPoint &point)
{
    QModelIndexList sel = fTableView->selectionModel()->selectedColumns();
    if (sel.count() == 0) {
        int col = ui->tblMain->horizontalHeader()->logicalIndexAt(point);
        ui->tblMain->selectColumn(col);
    }
    fTableMenu->popup(ui->tblMain->mapToGlobal(point));
}

void WReportGrid::tblMaingridCustomMenu(const QPoint &point)
{
    QModelIndexList sel = fTableView->selectionModel()->selectedIndexes();
    if (sel.count() == 0) {
        return;
    }
    fGridMenu->popup(ui->tblMain->mapToGlobal(point));
}

void WReportGrid::actionCopyGrid(bool v)
{
    Q_UNUSED(v);
    QModelIndexList sel = fTableView->selectionModel()->selectedIndexes();
    if (sel.count() == 0) {
        return;
    }
    QString data;
    int currCol = -1;
    bool first = true;
    foreach (QModelIndex m, sel) {
        if (currCol < 0) {
            currCol = m.row();
        }
        if (currCol != m.row()) {
            currCol = m.row();
            first = true;
            data += "\r\n";
        }
        if (first) {
            first = false;
        } else {
            data += "\t";
        }
        data += m.data(Qt::DisplayRole).toString();
    }
    QClipboard *c = qApp->clipboard();
    c->setText(data);
}

void WReportGrid::actionFilterColumn(bool v)
{
    Q_UNUSED(v)
    QSet<QString> filterValues;
    QModelIndexList sel = fTableView->selectionModel()->selectedColumns();
    if (sel.count() == 0) {
        return;
    }
    fModel->uniqueValuesForColumn(sel.at(0).column(), filterValues);
    QStringList sortedValues = filterValues.values();
    std::sort(sortedValues.begin(), sortedValues.end());
    DlgFilterValues *d = new DlgFilterValues(sortedValues, this);
    if (d->exec() == QDialog::Accepted) {
        QString searchText;
        bool first = true;
        for (QStringList::const_iterator it = sortedValues.begin(); it != sortedValues.end(); it ++) {
            if (first) {
                first = false;
            } else {
                searchText += "|";
            }
            searchText += *it;
        }
        fModel->searchInTable(searchText);
    }
    delete d;
}

void WReportGrid::rowCount(int count)
{
    QStringList h;
    h << QString::number(count);
    ui->tblTotals->setVerticalHeaderLabels(h);
    ui->tblTotals->setColumnCount(fModel->columnCount());
    for (int i = 0; i < fModel->columnCount(); i++) {
        ui->tblTotals->setColumnWidth(i, ui->tblMain->columnWidth(i));
    }
}

void WReportGrid::on_tblMain_clicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        emit clickOnRow(-1);
        return;
    }
    fillRowValues(index.row());
    emit clickOnRow(index.row());
}

void WReportGrid::on_btnClearQuickSearch_clicked()
{
    ui->leQuickSearch->clear();
    ui->tblMain->clearSelection();
}

void WReportGrid::on_btnPrint_clicked()
{
    if (fFilter) {
        if (fFilter->handlePrint()) {
            return;
        }
    }
    if (!ui->tblMain->isVisible()) {
        ui->tblMain->setVisible(true);
    }
    if (fPrintOut) {
        qDeleteAll(fPrintScene);
    }
    fPrintScene.clear();
    int page =  1;
    qreal top = 10;
    int totalWidth = 0;
    QList<qreal> distanceCol;
    distanceCol << 10.000 ;
    for (int i = 0, colCount = fModel->columnCount(); i < colCount; i++) {
        int colw = ui->tblMain->columnWidth(i);
        totalWidth += (colw *resize_factor);
        distanceCol << (distanceCol.at(i) + colw);
    }
    Report rs;
    rs.fValid = false;
    if (fReportOptions.contains(fGridClassName)) {
        rs = fReportOptions[fGridClassName];
        rs.fValid = true;
    } else {
        rs.fRowHeight = ui->tblMain->verticalHeader()->defaultSectionSize();
        rs.fValid = true;
        rs.fFontSize = 8;
        rs.fFontName = "Arial";
    }
    if (fFilter) {
        rs.fFontSize -= fFilter->fDec;
    }
    QBrush b(Qt::white, Qt::SolidPattern);
    PTextRect trFooter;
    trFooter.setBrush(b);
    QFont f(rs.fFontName, rs.fFontSize + font_size_print_delta);
    f.setBold(rs.fFontBold);
    QFont fb(f);
    fb.setBold(true);
    trFooter.setFont(f);
    trFooter.setBorders(false, false, false, false);
    trFooter.setTextAlignment(Qt::AlignLeft);
    QPageLayout::Orientation po = (totalWidth > sizePortrait.width() - 50 ? QPageLayout::Landscape
                                                                          : QPageLayout::Portrait);
    QSize paperSize = (po == QPageLayout::Portrait ? sizePortrait : sizeLandscape);
    int footerTop = paperSize.height() - 50;
    PTextRect prTempl;
    prTempl.setWrapMode(QTextOption::NoWrap);
    prTempl.setFont(f);
    prTempl.setBorders(true, true, true, true);
    QPen pen;
    pen.setWidth(2);
    prTempl.setRectPen(pen);
    PTextRect prHead(prTempl, "");
    prHead.setFont(fb);
    prHead.setBrush(QBrush(QColor::fromRgb(215, 215, 215), Qt::SolidPattern));
    prHead.setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    int rowHeight = rs.fRowHeight;
    int headerHeight = ui->tblMain->horizontalHeader()->height() * resize_factor * 2;
    PPrintScene *ps = addScene(0, po);
    QString title = "NO TITLE";
    bool official = false;
    if (fFilter) {
        title = fFilter->reportTitle();
        official = fFilter->officialTitle();
    } else if (fTabWidget) {
        title = fTabWidget->tabText(fTabIndex);
    }
    if (fTitleWidget) {
        official = false;
        title = fTitleWidget->title();
    }
    int topOffcet = 0;
    if (official) {
        PTextRect *trInfo = new PTextRect(1500, 20, 600, 400, fPreferences.getDb(def_vouchers_right_header).toString(),
                                          nullptr, QFont(rs.fFontName, 25));
        trInfo->setTextAlignment(Qt::AlignTop | Qt::AlignRight);
        trInfo->setBorders(false, false, false, false);
        ps->addItem(trInfo);
        PImage *logo = new PImage("logo_print.png");
        ps->addItem(logo);
        logo->setRect(QRectF(20, 10, 500, 300));
        PTextRect th(prTempl, title);
        QFont f1(rs.fFontName, 30);
        f1.setBold(true);
        th.setFont(f1);
        th.setTextAlignment(Qt::AlignCenter);
        th.setWrapMode(QTextOption::WordWrap);
        th.setBorders(false, false, false, false);
        ps->addTextRect(20, 50, 2100, rowHeight, title, &th);
        topOffcet = 310;
    } else {
        PTextRect *caption = new PTextRect(prTempl, QString("%1")
                                           .arg(title));
        caption->setWrapMode(QTextOption::NoWrap);
        caption->setFont(fb);
        caption->setRect(20, 0, totalWidth, (rowHeight *resize_factor) + 50);
        caption->setBorders(false, false, false, false);
        caption->setTextAlignment(Qt::AlignHCenter);
        ps->addTextRect(caption);
        caption->setBorders(false, false, false, false);
        //caption->adjustRect();
        topOffcet += caption->height();
    }
    prTempl.setWrapMode(QTextOption::NoWrap);
    top += topOffcet;
    for (int i = 0; i < fModel->columnCount(); i++) {
        if (ui->tblMain->columnWidth(i) == 0) {
            continue;
        }
        PTextRect *tr = new PTextRect(distanceCol.at(i) *resize_factor, top,
                                      ui->tblMain->columnWidth(i) *resize_factor, headerHeight,
                                      fModel->columnTitle(i), &prHead);
        ps->addTextRect(tr);
    }
    top += headerHeight;
    for (int i = 0, rowCount = fModel->rowCount(); i < rowCount; i++) {
        rowHeight = rs.fRowHeight;
        for (int j = 0, colCount = fModel->columnCount(); j < colCount; j++) {
            if (ui->tblMain->columnWidth(j) == 0) {
                continue;
            }
            QFont nf = fModel->data(i, j, Qt::FontRole).value<QFont>();
            int n = 0;
            if (fFilter) {
                n = fFilter->fDec;
            }
            nf.setPointSize(nf.pointSize() + font_size_print_delta - n);
            prTempl.setFont(nf);
            QBrush br(fModel->data(i, j, Qt::BackgroundRole).value<QColor>());
            if (br.color() == Qt::white) {
                br.setStyle(Qt::NoBrush);
            }
            prTempl.setBrush(br);
            if (top > paperSize.height()  - 100) {
                /*footer*/
                ps->addTextRect(20, footerTop, 1800, rowHeight * 3, QString("%1: %2 %3")
                                .arg(tr("Printed"))
                                .arg(QDateTime::currentDateTime().toString(def_date_time_format))
                                .arg(WORKING_USERNAME), &trFooter);
                trFooter.setTextAlignment(Qt::AlignRight);
                ps->addTextRect(1800, footerTop, 200, rowHeight * 3, QString("%1 %2 %3")
                                .arg(tr("Page"))
                                .arg(page)
                                .arg(__dd1Database.left(2)), &trFooter);
                trFooter.setTextAlignment(Qt::AlignLeft);
                /*header*/
                rowHeight = rs.fRowHeight;
                top = 5;
                page++;
                ps = addScene(0, po);
                if (official) {
                    PTextRect *trInfo = new PTextRect(1500, 20, 600, 400, fPreferences.getDb(def_vouchers_right_header).toString(),
                                                      nullptr, QFont(rs.fFontName, 25));
                    trInfo->setTextAlignment(Qt::AlignTop | Qt::AlignRight);
                    trInfo->setBorders(false, false, false, false);
                    ps->addItem(trInfo);
                    PImage *logo = new PImage("logo_print.png");
                    ps->addItem(logo);
                    logo->setRect(QRectF(20, 10, 500, 300));
                    PTextRect th(prTempl, title);
                    QFont f1(rs.fFontName, 30);
                    f1.setBold(true);
                    th.setFont(f1);
                    th.setWrapMode(QTextOption::WordWrap);
                    th.setTextAlignment(Qt::AlignCenter);
                    th.setBorders(false, false, false, false);
                    ps->addTextRect(20, 50, 2100, rowHeight, title, &th);
                    topOffcet = 310;
                } else {
                    PTextRect *caption = new PTextRect(prTempl, QString("%1")
                                                       .arg(title));
                    caption->setWrapMode(QTextOption::NoWrap);
                    caption->setFont(fb);
                    caption->setRect(10, 0,  totalWidth, rs.fRowHeight * 3.5 * resize_factor);
                    caption->setBorders(false, false, false, false);
                    caption->setTextAlignment(Qt::AlignHCenter);
                    ps->addTextRect(caption);
                    caption->setBorders(false, false, false, false);
                    topOffcet = caption->height();
                }
                top += topOffcet;
                for (int n = 0; n < fModel->columnCount(); n++) {
                    PTextRect *tr = new PTextRect(distanceCol.at(n) *resize_factor, top,
                                                  ui->tblMain->columnWidth(n) *resize_factor,
                                                  headerHeight,
                                                  fModel->columnTitle(n), &prHead);
                    ps->addTextRect(tr);
                }
                top += headerHeight;
            }
            int colwidth = ui->tblMain->columnWidth(j);
            int span = ui->tblMain->columnSpan(i, j);
            if (span > 1) {
                colwidth = 0;
                for (int k = j, count = j + span; k < count; k++) {
                    colwidth += ui->tblMain->columnWidth(k);
                }
            }
            rowHeight = ui->tblMain->rowHeight(i);
            PTextRect *tr = new PTextRect(distanceCol.at(j) *resize_factor, top,
                                          colwidth *resize_factor, (rowHeight *resize_factor) + 20,
                                          fModel->data(i, j).toString(), &prTempl);
            j += span - 1;
            ps->addTextRect(tr);
        }
        top += (rowHeight *resize_factor) + 20;
    }
    top += rowHeight;
    //TOTAL ROW
    if (ui->tblTotals->isVisible()) {
        prTempl.setFont(fb);
        for (int j = 0, colCount = fModel->columnCount(); j < colCount; j++) {
            if (ui->tblMain->columnWidth(j) == 0) {
                continue;
            }
            if (top > paperSize.height()  - 100) {
                /*footer*/
                ps->addTextRect(20, footerTop, 1800, rowHeight * 3, QString("%1: %2 %3")
                                .arg(tr("Printed"))
                                .arg(QDateTime::currentDateTime().toString(def_date_time_format))
                                .arg(WORKING_USERNAME), &trFooter);
                trFooter.setTextAlignment(Qt::AlignRight);
                ps->addTextRect(1800, footerTop, 200, rowHeight * 3, QString("%1 %2 %3")
                                .arg(tr("Page"))
                                .arg(page)
                                .arg(__dd1Database.left(2)), &trFooter);
                trFooter.setTextAlignment(Qt::AlignLeft);
                /*header*/
                top = 5;
                page++;
                ps = addScene(0, po);
                if (official) {
                    PTextRect *trInfo = new PTextRect(1500, 20, 600, 400, fPreferences.getDb(def_vouchers_right_header).toString(),
                                                      nullptr, QFont(rs.fFontName, 25));
                    trInfo->setTextAlignment(Qt::AlignTop | Qt::AlignRight);
                    trInfo->setBorders(false, false, false, false);
                    ps->addItem(trInfo);
                    PImage *logo = new PImage("logo_print.png");
                    ps->addItem(logo);
                    logo->setRect(QRectF(20, 10, 500, 300));
                    PTextRect th(prTempl, title);
                    QFont f1(rs.fFontName, 30);
                    f1.setBold(true);
                    th.setFont(f1);
                    th.setTextAlignment(Qt::AlignCenter);
                    th.setBorders(false, false, false, false);
                    ps->addTextRect(20, 50, 2100, rowHeight, title, &th);
                    topOffcet = 310;
                } else {
                    PTextRect *caption = new PTextRect(prTempl, QString("%1")
                                                       .arg(title));
                    caption->setWrapMode(QTextOption::NoWrap);
                    caption->setFont(fb);
                    caption->setRect(10, 0, 1200, ui->tblMain->verticalHeader()->defaultSectionSize() * 1.5 * resize_factor);
                    caption->setBorders(false, false, false, false);
                    ps->addTextRect(caption);
                    caption->setTextAlignment(Qt::AlignRight);
                    caption->setBorders(false, false, false, false);
                    topOffcet = caption->height();
                }
                top += topOffcet;
                for (int n = 0; n < fModel->columnCount(); n++) {
                    PTextRect *tr = new PTextRect(distanceCol.at(n) *resize_factor, top,
                                                  ui->tblMain->columnWidth(n) *resize_factor,
                                                  headerHeight,
                                                  fModel->columnTitle(n), &prHead);
                    ps->addTextRect(tr);
                }
                top += headerHeight ;
            }
            int colwidth = ui->tblMain->columnWidth(j);
            int span = ui->tblMain->columnSpan(0, j);
            if (span > 1) {
                colwidth = 0;
                for (int k = j; k < j + span; k++) {
                    colwidth += ui->tblMain->columnWidth(k);
                }
            }
            if (!ui->tblTotals->item(0, j)) {
                ui->tblTotals->setItem(0, j, new C5TableWidgetItem());
            }
            PTextRect *tr = new PTextRect(distanceCol.at(j) *resize_factor, top,
                                          colwidth *resize_factor, (rowHeight *resize_factor) + 20,
                                          ui->tblTotals->toString(0, j), &prTempl);
            j += span - 1;
            ps->addTextRect(tr);
        }
        top += (rowHeight *resize_factor) + 20;
    }
    if (fFilter) {
        fFilter->finalPrint(ps, top);
    }
    ps->addTextRect(20, footerTop, 1800, rowHeight * 3, QString("%1: %2 %3")
                    .arg(tr("Printed"))
                    .arg(QDateTime::currentDateTime().toString(def_date_time_format))
                    .arg(WORKING_USERNAME), &trFooter);
    trFooter.setTextAlignment(Qt::AlignRight);
    ps->addTextRect(1800, footerTop, 200, rowHeight * 3, QString("%1 %2 %3")
                    .arg(tr("Page"))
                    .arg(page)
                    .arg(__dd1Database.left(2)), &trFooter);
    trFooter.setTextAlignment(Qt::AlignLeft);
    if (fPrintOut) {
        ui->tblMain->setVisible(false);
        ui->cbZoom->setCurrentIndex(4);
        on_cbZoom_currentIndexChanged(4);
        bool multiPage = fPrintScene.count() > 1;
        ui->btnBack->setEnabled(multiPage);
        ui->btnLast->setEnabled(multiPage);
        ui->btnFirst->setEnabled(multiPage);
        ui->btnNext->setEnabled(multiPage);
        fPageNumber = 1;
        if (fPrintScene.count() > 0) {
            setPage();
        }
    } else {
        PPrintPreview *pp = new PPrintPreview(this);
        pp->fPrintScene = fPrintScene;
        pp->exec();
        delete pp;
        fTrackControl->insert("Print report", title, "");
    }
}

void WReportGrid::on_btnConfigGrid_clicked()
{
    QString fName = "Arial";
    int fSize = qApp->font().pointSize();
    bool fBold = false;
    bool reset = false;
    bool printOnly = false;
    int rowHeight = ui->tblMain->verticalHeader()->defaultSectionSize();
    registerInReportBuilder(false);
    DoubleDatabase dd;
    dd[":f_report"] = fGridClassName;
    dd[":f_group"] = WORKING_USERGROUP;
    dd.exec("select * from rp_main where f_group=:f_group and lower(f_report)=lower(:f_report)");
    if (dd.nextRow()) {
        fName = dd.getString("f_fontname");
        fSize = dd.getInt("f_fontsize");
        fBold = dd.getInt("f_fontbold") == 0 ? false : true;
        printOnly = dd.getInt("f_printonly") == 0 ? false : true;
        rowHeight = dd.getInt("f_rowheight");
    }
    if (!DlgConfigGrid::config(fName, fSize, fBold, printOnly, reset, rowHeight, this)) {
        return;
    }
    if (reset) {
        fName = "Arial";
        fSize = qApp->font().pointSize();
        fBold = false;
        printOnly = false;
        rowHeight = 21;
        QSettings s(_ORGANIZATION_, _APPLICATION_ + QString("\\Grid\\") + fGridClassName);
        s.remove("ColumnsWidths");
    }
    dd[":f_report"] = fGridClassName;
    dd[":f_group"] = WORKING_USERGROUP;
    dd[":f_printonly"] = printOnly;
    dd[":f_fontname"] = fName;
    dd[":f_fontsize"] = fSize;
    dd[":f_fontbold"] = fBold ? 1 : 0;
    dd[":f_rowheight"] = rowHeight;
    dd.exec("update rp_main set f_printonly=:f_printonly, f_fontname=:f_fontname, f_fontsize=:f_fontsize, f_fontbold=:f_fontbold, "
            "f_rowheight=:f_rowheight where f_group=:f_group and f_report=:f_report");
    Report r;
    r.fValid = true;
    r.fPrintOnly = printOnly;
    r.fFontName = fName;
    r.fFontSize = fSize;
    r.fFontBold = fBold;
    r.fRowHeight = rowHeight;
    fReportOptions[fGridClassName] = r;
    QFont f(fName, fSize);
    f.setBold(fBold);
    ui->tblMain->setFont(f);
    ui->tblTotals->setFont(f);
    ui->tblMain->verticalHeader()->setDefaultSectionSize(rowHeight);
}

void WReportGrid::endApply()
{
    QString settingsName = fTableView->property("wgridclassname").toString();
    QSettings s(_ORGANIZATION_, settingsName);
    QStringList cols = s.value("ColumnsWidths").toString().split(",", Qt::SkipEmptyParts);
    if (cols.count() != fModel->columnCount()) {
        return;
    }
    for (int i = 0; i < cols.count(); i++) {
        ui->tblMain->setColumnWidth(i, cols[i].toInt());
    }
    if (fPrintOut) {
        fPageNumber = 1;
        on_btnPrint_clicked();
        fPrintOutReady = true;
    }
    if (fReportOptions.contains(fGridClassName)) {
        Report r = fReportOptions[fGridClassName];
        if (r.fPrintOnly) {
            ui->scrollArea->setVisible(true);
            ui->wPrint->setVisible(true);
            ui->tblMain->setVisible(false);
            ui->tblTotals->setVisible(false);
            fPrintOut = true;
            ui->btnPrint->setVisible(false);
            ui->btnPrint2->setVisible(true);
        }
        if (r.fRowHeight < 10) {
            r.fRowHeight = 21;
        }
        ui->tblMain->verticalHeader()->setDefaultSectionSize(r.fRowHeight);
        QFont font(r.fFontName, r.fFontSize);
        font.setBold(r.fFontBold);
        ui->tblMain->setFont(font);
        ui->tblTotals->setFont(font);
    } else {
        ui->tblMain->verticalHeader()->setDefaultSectionSize(21);
    }
}

void WReportGrid::on_btnHelp_clicked()
{
    DlgHelp *d = new DlgHelp(fHelp, this);
    d->exec();
    delete d;
}

void WReportGrid::on_btnFirst_clicked()
{
    fPageNumber = 1;
    setPage();
}

void WReportGrid::on_btnBack_clicked()
{
    if (fPageNumber == 1)
        return;
    fPageNumber--;
    setPage();
}

void WReportGrid::on_btnNext_clicked()
{
    if (fPageNumber == fPrintScene.count()) {
        return;
    }
    fPageNumber++;
    setPage();
}

void WReportGrid::on_btnLast_clicked()
{
    fPageNumber = fPrintScene.count();
    setPage();
}

void WReportGrid::on_btnZoomOut_clicked()
{
    if (ui->cbZoom->currentIndex() == ui->cbZoom->count() - 1) {
        return;
    }
    ui->cbZoom->setCurrentIndex(ui->cbZoom->currentIndex() + 1);
}

void WReportGrid::on_btnZoopIn_clicked()
{
    if (ui->cbZoom->currentIndex() == 0) {
        return;
    }
    ui->cbZoom->setCurrentIndex(ui->cbZoom->currentIndex() - 1);
}

void WReportGrid::on_cbZoom_currentIndexChanged(int index)
{
    qreal prevScaleFactor = fScaleFactor;
    fScaleFactor = (index + 1) / 1.5;
    qreal deltaScaleFactor =  prevScaleFactor / fScaleFactor;
    QSize size(fPrintScene.at(fPageNumber - 1)->fPageLayout == QPageLayout::Portrait
                   ? sizePortrait
                   : sizeLandscape);
    size.setWidth((size.width() / fScaleFactor) * 1.500);
    size.setHeight((size.height() / fScaleFactor) * 1.500);
    ui->gv->setMinimumSize(size);
    ui->gv->setMaximumSize(size);
    ui->gv->scale(deltaScaleFactor, deltaScaleFactor);
}

void WReportGrid::on_btnPrint2_clicked()
{
    printOnPaper();
}
