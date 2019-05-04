#ifndef RERESTDISH_H
#define RERESTDISH_H

#include "roweditordialog.h"

namespace Ui {
class RERestDish;
}

class RERestDish : public RowEditorDialog
{
    Q_OBJECT

public:
    explicit RERestDish(QList<QVariant> &values, QWidget *parent = nullptr);
    ~RERestDish();
    virtual void selector(int number, const QVariant &value);

protected:
    virtual bool isDataCorrect();
    virtual void valuesToWidgets();
    virtual void clearWidgets();
    virtual void save();
    virtual void hide();

private slots:
    void checkComplex(bool v);
    void tabPageIndexChanged(int index);
    void btnRemoveModifier(int row);
    void on_btnTextColor_clicked();
    void on_btnBgColor_clicked();
    void on_btnCancel_clicked();
    void on_btnOk_clicked();
    void on_btnLoadImage_clicked();
    void on_btnRemoveRecipeRow_clicked();
    void on_btnClearRecipe_clicked();
    void on_chContainItself_clicked(bool checked);
    void on_btnTrack_clicked();
    void on_leReadScancode_returnPressed();

private:
    Ui::RERestDish *ui;
    bool fImageChanged;
    bool fImageLoaded;
    QStringList fRemovedModifiers;
    EQLineEdit *createLineEdit(int row, int column);
    QString cellValue(int row, int column);
    double cellDouble(int row, int column);
    void setCellValue(int row, int column, const QString &value);
    void addDishRow(const QString &code, const QString &name, double qty);
    void dishMod(const QString &code);
};

#endif // RERESTDISH_H
