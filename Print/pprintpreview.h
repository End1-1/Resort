#ifndef PPRINTPREVIEW_H
#define PPRINTPREVIEW_H

#include "pprintscene.h"
#include <QDialog>

namespace Ui {
class PPrintPreview;
}

class PPrintPreview : public QDialog
{
    Q_OBJECT

public:
    explicit PPrintPreview(QWidget *parent = nullptr);
    ~PPrintPreview();
    PPrintScene *addScene(int tmpl, PrintOrientation po);
    int exec(bool noPreview = false);
    QList<PPrintScene*> fPrintScene;

protected:
    virtual void showEvent(QShowEvent *e);

private slots:
    void on_btnPrint_clicked();
    void on_btnZoomOut_clicked();
    void on_cbZoom_currentIndexChanged(int index);
    void on_btnZoopIn_clicked();
    void on_btnBack_clicked();
    void on_btnNext_clicked();
    void on_btnFirst_clicked();
    void on_btnLast_clicked();
    void on_cbPrintSelection_currentIndexChanged(int index);
    void on_chCloseAfterPrint_clicked(bool checked);

private:
    Ui::PPrintPreview *ui;
    int fPageNumber;
    float fScaleFactor;
    void setPage();
    void setPrintOrientation(PrintOrientation po);
};

#endif // PPRINTPREVIEW_H
