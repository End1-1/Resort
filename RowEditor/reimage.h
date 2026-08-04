#ifndef REIMAGE_H
#define REIMAGE_H

#include "roweditordialog.h"

namespace Ui {
class REImage;
}

class REImage : public RowEditorDialog
{
    Q_OBJECT

public:
    explicit REImage(QList<QVariant> &values, QWidget *parent = nullptr);
    ~REImage();
    virtual void setValues() override;

private slots:
    void on_btnCancel_clicked();
    void on_btnOk_clicked();
    void on_btnLoad_clicked();
    void on_btnRemove_clicked();

private:
    Ui::REImage *ui;
    QByteArray fImageData;
    void showPreview();
    void loadPreviewFromCacheOrDb();
};

#endif // REIMAGE_H
