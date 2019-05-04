#ifndef EQLINEEDIT_H
#define EQLINEEDIT_H

#include <QLineEdit>
#include <QToolButton>
#include <QResizeEvent>
#include <QMouseEvent>


class QTableWidget;
class DWSelector;
class Base;
class CacheInstance;

class EQLineEdit : public QLineEdit
{
    Q_OBJECT
    Q_PROPERTY (bool ShowButton READ getShowButton WRITE setShowButtonOnFocus)
    Q_PROPERTY (bool AlwaysUpper READ getAlwaysUpper WRITE setAlwaysUpper)
    Q_PROPERTY (QString Field READ getField WRITE setField)
    Q_PROPERTY (bool PrimaryKey READ getPrimaryKey WRITE setPrimaryKey)
    Q_PROPERTY (bool EnableHiddenText READ getHiddenTextEnabled WRITE setHiddenTextEnabled)
    Q_PROPERTY (QString HiddenTextValidator READ getHiddenTextValidator WRITE setHiddenTextValidator)
public:
    EQLineEdit(QWidget *parent = nullptr);
    ~EQLineEdit();
    void setText(const QString &text);
    QString text();
    void setInt(int val);
    void setUInt(uint val);
    void setDouble(double val);
    void setBgColor(const QColor &color);
    void setMultipleOfDouble(const QString &val1, const QString &val2, int prec = 0);
    void setMultipleOfDouble(double val1, double val2, int prec = 0);
    void setDevideOfDouble(double val1, double val2, int prec = 0);
    void addDouble(double value);
    void setSumOfDouble(double val1, double val2, int prec = 0);
    bool getShowButton();
    void setShowButtonOnFocus(bool value);
    QString getField();
    void setField(const QString &name);
    bool getPrimaryKey();
    void setPrimaryKey(bool value);
    bool getHiddenTextEnabled();
    void setHiddenTextEnabled(bool v);
    bool getAlwaysUpper();
    void setAlwaysUpper(bool v);
    QString getHiddenTextValidator();
    void setHiddenTextValidator(const QString &v);
    int asInt();
    quint32 asUInt();
    double asDouble();
    QString fHiddenText;
    QString fShowText;
    bool fClickBool;
    int fRow;
    int fColumn;
    double fMax;
    int fTag;
    QTableWidget *fTable;

    inline int len() {return text().length();}
    inline bool isEmpty() {return text().isEmpty();}
    inline bool notEmpty() {return !text().isEmpty();}

    Base *fBase;
    bool fSelectorMultiCheck;
    CacheInstance *fCacheInstance;
    QLineEdit *fNameEdit;
    int fHint;
    QStringList fCodeFilter;
    QStringList fCommonFilter;
    QMap<QString, QStringList> fFieldFilter;
    QStringList fCodeExcludeFilter;
    void clearSelector();
    void setSelector(Base *base, CacheInstance *cacheInstance, QLineEdit *nameEdit, int hint = 0);
    void setInitialValue(const QString &value);
    void setInitialValue(int value);
    void doubleClickEvent();

signals:
    void customButtonClicked(bool value);
    void focusIn();
    void focusOut();
protected:
    virtual void resizeEvent(QResizeEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    virtual void leaveEvent(QEvent *event);
    virtual bool eventFilter(QObject *watched, QEvent *event);
private:
    QToolButton *fButton;
    bool fShowButtonOnFocus;
    bool fAlwaysUpper;
    QString fField;
    bool fPrimaryKey;
    bool fEnableHiddenText;
    QString fHiddenTextValidator;
private slots:
    void buttonClicked(bool value);
    void correctButtonPosition();
    void hiddenTextChanged(const QString &text);
};

#endif // EQLINEEDIT_H
