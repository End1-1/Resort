#include "eqlineedit.h"
#include "utils.h"
#include "cacheinstance.h"
#include "cachebasestruct.h"
#include "base.h"
#include "dlgselector.h"
#include <QStyle>
#include <QRegularExpressionValidator>

EQLineEdit::EQLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
    fButton = new QToolButton(this);
    fButton->setIcon(QIcon(":/images/search.png"));
    connect(fButton, SIGNAL(clicked(bool)), this, SLOT(buttonClicked(bool)));
    fButton->hide();
    fShowButtonOnFocus = false;
    fPrimaryKey = false;
    fField = "";
    fEnableHiddenText = false;
    installEventFilter(this);
    connect(this, SIGNAL(textEdited(QString)), this, SLOT(hiddenTextChanged(QString)));
    fMax = 0.000;
    fAlwaysUpper = true;
    fClickBool = false;
    fBase = nullptr;
    fCacheInstance = nullptr;
    fNameEdit = nullptr;
    fSelectorMultiCheck = false;
}

EQLineEdit::~EQLineEdit()
{

}

void EQLineEdit::setText(const QString &text)
{
    QString t = fAlwaysUpper ? text.toUpper() : text;
    const QValidator *v = validator();
    if (v) {
        if (!strcmp(v->metaObject()->className(), "QDoubleValidator")) {
            QLocale l;
            t.replace(".", l.decimalPoint());
            t.replace(",", l.decimalPoint());
            t.replace("․", l.decimalPoint());
        }
    }
    if (fMax > 0.1) {
        if (t.toDouble() > fMax) {
            setDouble(fMax);
            return;
        }
    }
    QLineEdit::setText(t);
    if (fEnableHiddenText) {
        if (hasFocus()) {
            fHiddenText = t;
        } else {
            fShowText = t;
        }
    }
}

QString EQLineEdit::text()
{
    const QValidator *v = validator();
    if (v) {
        if (!strcmp(v->metaObject()->className(), "QDoubleValidator")) {
            const QDoubleValidator *dv = static_cast<const QDoubleValidator*>(v);
            return float_str(QLineEdit::text().toDouble(), dv->decimals());
        } else if (!strcmp(v->metaObject()->className(), "QIntValidator")) {
            return QString::number(QLineEdit::text().toInt());
        }
    }
    return QLineEdit::text();
}

void EQLineEdit::setInt(int val)
{
    setText(QString::number(val));
}

void EQLineEdit::setUInt(uint val)
{
    setText(QString::number(val));
}

void EQLineEdit::setDouble(double val)
{
    const QValidator *v = validator();
    if (v) {
        if (!strcmp(v->metaObject()->className(), "QDoubleValidator")) {
            const QDoubleValidator *dv = reinterpret_cast<const QDoubleValidator* >(v);
            setText(float_str(val, dv->decimals()));
        } else {
            setText(float_str(val, 2));
        }
    } else {
        setText(float_str(val, 2));
    }
}

void EQLineEdit::setBgColor(const QColor &color)
{
    QPalette palette;
    palette.setColor(QPalette::Base, color);
    setPalette(palette);
}

void EQLineEdit::setMultipleOfDouble(const QString &val1, const QString &val2, int prec)
{
    double result = val1.toDouble() * val2.toDouble();
    setText(QString::number(result, 'f', prec));
}

void EQLineEdit::setMultipleOfDouble(double val1, double val2, int prec)
{
    double result = val1 * val2;
    setText(QString::number(result, 'f', prec));
}

void EQLineEdit::setDevideOfDouble(double val1, double val2, int prec)
{
    double result;
    if (val2 == 0)
        result = 0;
    else
        result = val1 / val2;
    setText(QString::number(result, 'f', prec));
}

void EQLineEdit::addDouble(double value)
{
    setDouble(asDouble() + value);
}

void EQLineEdit::setSumOfDouble(double val1, double val2, int prec)
{
    double result = val1 + val2;
    setText(QString::number(result, 'f', prec));
}

bool EQLineEdit::getShowButton()
{
    return fShowButtonOnFocus;
}

void EQLineEdit::setShowButtonOnFocus(bool value)
{
    fShowButtonOnFocus = value;
    if (value && hasFocus())
        fButton->show();
}

QString EQLineEdit::getField()
{
    return fField;
}

void EQLineEdit::setField(const QString &name)
{
    fField = name;
}

bool EQLineEdit::getPrimaryKey()
{
    return fPrimaryKey;
}

void EQLineEdit::setPrimaryKey(bool value)
{
    fPrimaryKey = value;
}

bool EQLineEdit::getHiddenTextEnabled()
{
    return fEnableHiddenText;
}

void EQLineEdit::setHiddenTextEnabled(bool v)
{
    fEnableHiddenText = v;
}

bool EQLineEdit::getAlwaysUpper()
{
    return fAlwaysUpper;
}

void EQLineEdit::setAlwaysUpper(bool v)
{
    fAlwaysUpper = v;
}

QString EQLineEdit::getHiddenTextValidator()
{
    return fHiddenTextValidator;
}

void EQLineEdit::setHiddenTextValidator(const QString &v)
{
    fHiddenTextValidator = v;
    QRegularExpressionValidator *re = new QRegularExpressionValidator(QRegularExpression(v));
    setValidator(re);
}

int EQLineEdit::asInt()
{
    return text().toInt();
}

quint32 EQLineEdit::asUInt()
{
    return text().toUInt();
}

double EQLineEdit::asDouble()
{
    return QLocale().toDouble(text());
}

void EQLineEdit::clearSelector()
{
    fBase = nullptr;
    fCacheInstance = nullptr;
    fNameEdit = nullptr;
    fHint = 0;
    setReadOnly(true);
}

void EQLineEdit::setSelector(Base *base, CacheInstance *cacheInstance, QLineEdit *nameEdit, int hint)
{
    setReadOnly(false);
    fBase = base;
    fCacheInstance = cacheInstance;
    fNameEdit = nameEdit;
    fHint = hint;
    fShowButtonOnFocus = true;
    if (fNameEdit == this) {
        fEnableHiddenText = true;
    }
}

void EQLineEdit::setInitialValue(const QString &value)
{
    if (!fCacheInstance) {
        return;
    }
    if (fCacheInstance->fStruct->get(value)) {
        if (fNameEdit && (fNameEdit != this)) {
            setText(value);
            fNameEdit->setText(fCacheInstance->fStruct->getString(1));
        } else {
            fHiddenText = value;
            fShowText = fCacheInstance->fStruct->getString(1);
            setText(fCacheInstance->fStruct->getString(1));
        }
    } else {
        clear();
        if (fNameEdit && (fNameEdit != this)) {
            fNameEdit->clear();
        } else {
            fHiddenText = "";
            fShowText = "";
        }
    }
    QString code;
    if (fEnableHiddenText) {
        code = fHiddenText;
    } else {
        code = text();
    }
    if (fCacheInstance->fStruct->get(code)) {
        if (fEnableHiddenText) {
            setText(fCacheInstance->fStruct->getString(1));
        } else {
            if (fNameEdit) {
                fNameEdit->setText(fCacheInstance->fStruct->getString(1));
            }
        }
    } else {
        if (fEnableHiddenText) {
            fHiddenText.clear();
            clear();
        } else {
            clear();
            if (fNameEdit) {
                fNameEdit->clear();
            }
        }
    }
    if (fHint > 0) {
        if (fBase) {
            fBase->callback(fHint, code);
        }
    }
}

void EQLineEdit::setInitialValue(int value)
{
    setInitialValue(QString::number(value));
}

void EQLineEdit::doubleClickEvent()
{
    if (fBase) {
        QStringList codes, names;
        fCacheInstance->fStruct->fSelector->fCodeFilter = fCodeFilter;
        fCacheInstance->fStruct->fSelector->fExcludeCodeFilter = fCodeExcludeFilter;
        for (QMap<QString, QStringList>::const_iterator it = fFieldFilter.constBegin(); it != fFieldFilter.constEnd(); it++) {
            fCacheInstance->fStruct->fSelector->fFieldFilter[fCacheInstance->fColumnNameMap[it.key().toLower()]] = it.value();
        }
        if (!fCacheInstance->selector(codes, names, fSelectorMultiCheck)) {
            return;
        }
        QString code = codes.join(',');
        QString name = names.join(',');

        if (fNameEdit && fNameEdit != this) {
            setText(code);
            fNameEdit->setText(name);
        } else {
            setText(code);
            fHiddenText = code;
            fShowText = name;
        }
        if (fHint > 0) {
            fBase->callback(fHint, code);
        }
    } else {
        emit customButtonClicked(true);
    }
}

void EQLineEdit::resizeEvent(QResizeEvent *event)
{
    correctButtonPosition();
    QLineEdit::resizeEvent(event);
}

void EQLineEdit::focusInEvent(QFocusEvent *event)
{
//    if (fShowButtonOnFocus) {
//        fButton->show();
//        correctButtonPosition();
//    }
    if (fEnableHiddenText) {
        setText(fHiddenText);
    }
    QLineEdit::focusInEvent(event);
    setSelection(0, text().length());
    emit focusIn();
}

void EQLineEdit::focusOutEvent(QFocusEvent *event)
{
    //fButton->hide();
    if (fEnableHiddenText || (fNameEdit == this)) {
        setText(fShowText);
        if (fHiddenText.isEmpty()) {
            clear();
        }
    }
    QString code;
    if (fCacheInstance) {
        if (fEnableHiddenText) {
            code = fHiddenText;
        } else {
            code = text();
        }
        QStringList codes;
        if (fSelectorMultiCheck) {
            codes = code.split(",", Qt::SkipEmptyParts);
        } else {
            codes << code;
        }
        QString names;
        bool first = true;
        foreach (QString s, codes) {
            if (fCacheInstance->fStruct->get(s)) {
                if (first) {
                    first = false;
                } else {
                    names += ",";
                }
                names += fCacheInstance->fStruct->getString(1);
            }
        }
        if (fEnableHiddenText) {
            setText(names);
        } else {
            if (fNameEdit) {
                fNameEdit->setText(names);
            }
        }
        if (names.isEmpty()) {
            if (fEnableHiddenText) {
                fHiddenText.clear();
                clear();
            } else {
                clear();
                if (fNameEdit) {
                    fNameEdit->clear();
                }
            }
        }
    }
    if (fHint > 0) {
        if (fBase) {
            fBase->callback(fHint, code);
        }
    }
    QLineEdit::focusOutEvent(event);
    emit focusOut();
}

void EQLineEdit::mouseMoveEvent(QMouseEvent *event)
{
    /*
    if (event->type() == QMouseEvent::MouseMove) {
        if (fShowButtonOnFocus) {
            if (this->rect().contains(event->pos())) {
                fButton->show();
                correctButtonPosition();
            }
        }
    }
    */
    QLineEdit::mouseMoveEvent(event);
}

void EQLineEdit::mouseDoubleClickEvent(QMouseEvent *event)
{
    QLineEdit::mouseDoubleClickEvent(event);
    doubleClickEvent();
}

void EQLineEdit::leaveEvent(QEvent *event)
{
    //fButton->hide();
    QLineEdit::leaveEvent(event);
}

bool EQLineEdit::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == this) {
        if (event->type() == QEvent::KeyPress) {
            QKeyEvent *k = static_cast<QKeyEvent*>(event);
            switch (k->key()) {
            case Qt::Key_F1:
                if (getShowButton()) {
                    //emit customButtonClicked(true);
                    doubleClickEvent();
                    return true;
                }
                break;
            }
        }
    }
    return QLineEdit::eventFilter(watched, event);
}

void EQLineEdit::buttonClicked(bool value)
{
    emit customButtonClicked(value);
}

void EQLineEdit::correctButtonPosition()
{
    QSize sz = fButton->sizeHint();
    int frameWidth = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
    fButton->move(rect().right() - frameWidth - sz.width(),
                  (rect().bottom() + 1 - sz.height())/2);
}

void EQLineEdit::hiddenTextChanged(const QString &text)
{
    int cursPos = cursorPosition();
    if (fEnableHiddenText) {
        if (hasFocus()) {
            fHiddenText = (fAlwaysUpper ? text.toUpper() : text);
        } else {
            fShowText = (fAlwaysUpper ? text.toUpper() : text);
        }
    } else {

    }
    setText(fAlwaysUpper ? text.toUpper() : text);
    setCursorPosition(cursPos);
}
