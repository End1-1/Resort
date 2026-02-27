#include "basewidget.h"
#include <QApplication>
MainWindow *fMainWindow;

BaseWidget::BaseWidget(QWidget *parent) :
    QWidget(parent),
    Base()
{
    fTrackControl = nullptr;
    fTabWidget = nullptr;
    setMinimumSize(100, 100);
}

BaseWidget::~BaseWidget()
{
    if (fTrackControl) {
        delete fTrackControl;
    }
}

void BaseWidget::setTab(QTabWidget *tabWidget, int index)
{
    fTabWidget = tabWidget;
    fTabIndex = index;
    setupTab();
}

void BaseWidget::setup()
{

}

QString BaseWidget::title()
{
    return "NO TITLE";
}

bool BaseWidget::canClose()
{
    if (fTrackControl == nullptr) {
        return true;
    }
    return !fTrackControl->hasChanges();
}

void BaseWidget::closeEvent(QCloseEvent *event)
{
    if (!canClose()) {
        event->ignore();
        return;
    }
    QWidget::closeEvent(event);
}

void BaseWidget::handleBroadcast(const QMap<QString, QVariant> &data)
{
    Q_UNUSED(data);
}

bool BaseWidget::event(QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *ke = static_cast<QKeyEvent*>(event);
        switch (ke->key()) {
        case Qt::Key_Enter:
        case Qt::Key_Return:
            focusNextChild();
            break;
        }
    }
    return QWidget::event(event);
}

void BaseWidget::setupTab()
{

}

void BaseWidget::finalPrint(PPrintScene *ps, int top)
{
    Q_UNUSED(ps)
    Q_UNUSED(top)
}

void BaseWidget::setupTabTextAndIcon(const QString &text, const QString &iconName)
{
    if (!fTabWidget) {
        return;
    }
    fTabWidget->setTabIcon(fTabIndex, QIcon(iconName));
    fTabWidget->setTabText(fTabIndex, text);
}

QString BaseWidget::valueForWidget(const QString &name)
{
    if (fTrackControl) {
        return fTrackControl->newValue(name);
    } else {
        return "TrackControl is null";
    }
}

void BaseWidget::removeFromTabWidget()
{
    for (int i = 0; i < fTabWidget->count(); i++) {
        if (fTabWidget->widget(i) == this) {
            fTabWidget->removeTab(i);
            deleteLater();
        }
    }
}
