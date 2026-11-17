#ifndef CENTERHELPER_H
#define CENTERHELPER_H

#include <QMessageBox>
#include <QWidget>
#include <QScreen>
#include <QGuiApplication>
#include <QRect>

inline void centerOnScreen(QWidget *widget) {
    if (!widget) return;
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        QRect screenGeometry = screen->geometry();
        int x = screenGeometry.x() + (screenGeometry.width() - widget->width()) / 2;
        int y = screenGeometry.y() + (screenGeometry.height() - widget->height()) / 2;
        widget->move(x, y);
    }
}

inline QMessageBox::StandardButton showCenteredMessage(QWidget *parent,
                                                      QMessageBox::Icon icon,
                                                      const QString &title,
                                                      const QString &text,
                                                      QMessageBox::StandardButtons buttons = QMessageBox::Ok)
{
    QMessageBox msgBox(icon, title, text, buttons, parent);
    msgBox.setWindowFlags((msgBox.windowFlags() & ~Qt::Sheet) | Qt::Dialog);
    msgBox.setWindowModality(Qt::ApplicationModal);
    msgBox.adjustSize();

    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        QRect screenGeometry = screen->geometry();
        int x = screenGeometry.x() + (screenGeometry.width() - msgBox.sizeHint().width()) / 2;
        int y = screenGeometry.y() + (screenGeometry.height() - msgBox.sizeHint().height()) / 2;
        msgBox.move(x, y);
    }
    return static_cast<QMessageBox::StandardButton>(msgBox.exec());
}

inline QMessageBox::StandardButton showCenteredWarning(QWidget *parent, const QString &title, const QString &text) {
    return showCenteredMessage(parent, QMessageBox::Warning, title, text);
}

inline QMessageBox::StandardButton showCenteredInfo(QWidget *parent, const QString &title, const QString &text) {
    return showCenteredMessage(parent, QMessageBox::Information, title, text);
}

#endif // CENTERHELPER_H
