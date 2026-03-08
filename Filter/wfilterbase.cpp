#include "wfilterbase.h"
#include "wreportgrid.h"
#include "eqcheckbox.h"

WFilterBase::WFilterBase(QWidget *parent) :
    BaseWidget(parent)
{
    fReportGrid = static_cast<WReportGrid*>(parent);
    fTrackControl = new TrackControl(TRACK_REPORT);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    fDec =0;
}

WFilterBase::~WFilterBase()
{
}

QString WFilterBase::reportTitle()
{
    return tr("Report title");
}

bool WFilterBase::officialTitle()
{
    return false;
}

bool WFilterBase::handlePrint()
{
    return false;
}

void WFilterBase::finalPrint(PPrintScene *ps, int top)
{
    Q_UNUSED(ps);
    Q_UNUSED(top);
}

void WFilterBase::buildQuery(WReportGrid *rg, const QString &where)
{
    QString select = "select ";
    QString from = "from ";
    rg->fModel->clearColumns();

    // 1. Ищем алиасы в WHERE (например, r в "r.f_id")
    // Ищем: слово, после которого идет точка
    QRegularExpression reAlias(R"([a-z0-9_]+(?=\.))", QRegularExpression::CaseInsensitiveOption);

    QStringList whereAliases = extractTableName(reAlias, where);
    for (const QString &a : whereAliases)
        checkTableName(a, from, rg);

    bool firstSelect = true;
    for (int i = 0; i < rg->fFields.count(); i++) {
        if (!rg->fIncludes[rg->fFields.at(i)])
            continue;

        QString field = rg->fFields.at(i);
        rg->fModel->setColumn(rg->fFieldsWidths.at(i), field, rg->fFieldTitles.at(i));

        if (!firstSelect)
            select += ",";
        firstSelect = false;

        // 2. Ищем все алиасы в поле (будь то coalesce, concat или просто r.field)
        // Логика та же: всё, что перед точкой — это алиас таблицы
        QStringList fieldAliases = extractTableName(reAlias, field);
        for (const QString &a : fieldAliases) {
            checkTableName(a, from, rg);
        }

        select += field;
    }

    rg->fModel->setSqlQuery(select + " " + from + " " + where);
    rg->fModel->apply(rg);
}

QStringList WFilterBase::extractTableName(const QRegularExpression &re, const QString &str)
{
    QStringList result;
    QRegularExpressionMatchIterator i = re.globalMatch(str);
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        // Берем только текст совпадения без захвата лишних скобок внутри регекса
        result << match.captured(0);
    }
    return result;
}

void WFilterBase::checkTableName(const QString &alias, QString &from, WReportGrid *rg)
{
    if (alias.isEmpty())
        return;

    for (int i = 0; i < rg->fTables.count(); i++) {
        QString tableDef = rg->fTables.at(i).trimmed();

        static QRegularExpression reLastWord(R"(\b[a-z0-9_]+$)", QRegularExpression::CaseInsensitiveOption);
        QRegularExpressionMatch m = reLastWord.match(tableDef);

        if (m.hasMatch() && m.captured(0).toLower() == alias.toLower()) {
            // КРИТИЧЕСКИ ВАЖНО: сначала проверяем, нет ли уже этого определения в запросе
            if (from.contains(tableDef)) {
                return;
            }

            // Чтобы избежать бесконечной рекурсии, сначала "резервируем" таблицу в строке from
            // (или используем временный список добавленных алиасов)

            if (i == 0) {
                from.insert(5, tableDef + " ");
            } else {
                // Вытаскиваем все зависимости из условия JOIN
                QRegularExpression reJoinAlias(R"([a-z0-9_]+(?=\.))");
                QStringList joinAliases = extractTableName(reJoinAlias, rg->fJoinConds.at(i));

                for (const QString &ja : joinAliases) {
                    // Чтобы не вызывать рекурсию для самой себя (например, r.f_id = r.f_parent)
                    if (ja.toLower() != alias.toLower()) {
                        checkTableName(ja, from, rg);
                    }
                }

                // Проверяем еще раз перед добавлением (рекурсия могла уже добавить её)
                if (!from.contains(tableDef)) {
                    from += " " + rg->fJoins.at(i) + " join " + tableDef + " on " + rg->fJoinConds.at(i) + " ";
                }
            }
            return;
        }
    }
}
QWidget *WFilterBase::gridOptionWidget()
{
    return nullptr;
}

void WFilterBase::groupCheckClicked(bool value)
{
    EQCheckBox *check = static_cast<EQCheckBox*>(sender());
    QStringList groupFields = check->getField().split(";", Qt::SkipEmptyParts);
    foreach (QString s, groupFields) {
        if (check->getRequireLang()) {
            s += def_lang;
        }
        fReportGrid->fIncludes[s] = value;
    }
}

bool WFilterBase::event(QEvent *e)
{
    return QWidget::event(e);
}
