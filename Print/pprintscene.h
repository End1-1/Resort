#ifndef PPRINTSCENE_H
#define PPRINTSCENE_H

#include <QGraphicsScene>
#include <QPageLayout>

class PTextRect;
class PImage;

class PPrintScene : public QGraphicsScene
{
public:
    PPrintScene(QPageLayout::Orientation po, QObject *parent = nullptr);
    PPrintScene(QObject *parent = nullptr);
    PTextRect *addTextRect(PTextRect *t);
    PTextRect *addTextRect(qreal x, qreal y, qreal w, qreal h, const QString &text, PTextRect *tmpl);
    QPageLayout::Orientation fPageLayout;
    int addTableRow(int &top, int height, QList<int> &col, QStringList &values, PTextRect *tmpl);
private:

};

#endif // PPRINTSCENE_H
