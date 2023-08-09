#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QObject>
#include <QStackedWidget>
#include <QPointer>

#include "UI/WaitingWindow_client.h"
#include "UI/WaitingWindow_server.h"
#include "UI/LoginWindow.h"
#include "UI/DrawingCanvas.h"


class WindowManager : public QObject {
    Q_OBJECT
public:

    WindowManager();
    ~WindowManager();

    void setStackedWidget(QStackedWidget* stackedWidget);

    void showLoginWindow();

    void showWaitingWindowClient();
    void showWaitingWindowServer();

    void showDrawingWindow();

private slots:
    void handleLoginClicked();
private:
    WindowManager(const WindowManager&) = delete;
    WindowManager& operator=(const WindowManager&) = delete;

    QPointer<QStackedWidget> m_stackedWidget;
    QPointer<LoginWindow> m_loginWindow;
    QPointer<DrawingCanvas> m_drawingCanvas;

    QPointer<WaitingWindowClient> m_waitingWindowClient;
    QPointer<WaitingWindowServer> m_waitingWindowServer;


    bool loginMode; // 0 is client, 1 is server.
};


#endif // WINDOWMANAGER_H
