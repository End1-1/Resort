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
    rg->fModel->clearColumns();

    QString select = "select ";
    QString from = "from  ";

    // ищем table.field
    QRegularExpression rw(R"([\s(,][a-zA-Z0-9]*\.)");

    QRegularExpressionMatchIterator it = rw.globalMatch(where);
    while (it.hasNext()) {
        QRegularExpressionMatch m = it.next();

        QString table = m.captured(0);
        table.remove(table.length() - 1, 1).remove(0, 1);

        checkTableName(table, from, rg);
    }

    bool firstSelect = true;
    rg->fModel->clearColumns();

    for (int i = 0, count = rg->fFields.count(); i < count; ++i) {
        if (!rg->fIncludes[rg->fFields.at(i)])
            continue;

        rg->fModel->setColumn(rg->fFieldsWidths.at(i), rg->fFields.at(i), rg->fFieldTitles.at(i));

        if (!firstSelect)
            select += ",";
        else
            firstSelect = false;

        const QString &field = rg->fFields.at(i);

        if (field.contains("concat") || field.contains("count(") || field.contains("sum(")) {
            QRegularExpression re(R"(([(,].+\b))");
            re.setPatternOptions(QRegularExpression::InvertedGreedinessOption);

            QStringList tableNames = extractTableName(re, field);

            for (QString &t : tableNames)
                checkTableName(t.remove(0, 1), from, rg);

        } else if (field.contains("coalesce")) {
            QRegularExpression re(R"(([\+\-][a-z]+\b))");
            re.setPatternOptions(QRegularExpression::InvertedGreedinessOption);

            QStringList tableNames = extractTableName(re, field);

            for (QString &t : tableNames)
                checkTableName(t.remove(0, 1), from, rg);
        } else {
            QRegularExpression re(R"((.+\b))");
            re.setPatternOptions(QRegularExpression::InvertedGreedinessOption);

            QStringList tableNames = extractTableName(re, field);

            for (const QString &t : tableNames)
                checkTableName(t, from, rg);
        }

        select += field;
    }

    rg->fModel->setSqlQuery(select + " " + from + " " + where);
    rg->fModel->apply(rg);
}

QStringList WFilterBase::extractTableName(const QRegularExpression &re, const QString &str)
{
    QRegularExpressionMatch m = re.match(str);
    return m.capturedTexts();
}

void WFilterBase::checkTableName(const QString &alias, QString &from, WReportGrid *rg)
{
    for (int i = 0; i < rg->fTables.count(); ++i) {
        QRegularExpression rt(R"(\s[a-zA-Z]+$)");
        QRegularExpressionMatch match = rt.match(rg->fTables.at(i));

        if (!match.hasMatch())
            continue;

        QString compareTableName = match.captured(0);
        compareTableName.remove(0, 1); // убрать пробел

        if (alias == compareTableName) {
            if (!from.contains(rg->fTables.at(i))) {
                if (i == 0) {
                    from.insert(5, rg->fTables.at(i));
                    from += " ";
                } else {
                    QString joinCond = rg->fJoinConds.at(i);

                    QRegularExpression rjt(R"(=[a-z]+\b)");
                    QStringList joinsTables = extractTableName(rjt, joinCond);

                    for (QString &s : joinsTables)
                        checkTableName(s.remove(0, 1), from, rg);

                    from += rg->fJoins.at(i) + " join " + rg->fTables.at(i) + " on " + joinCond
                            + " ";
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
