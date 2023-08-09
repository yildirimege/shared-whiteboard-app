#include <iostream>

#include "Managers/WindowManager.h"
#include "Engine/Engine.h"

WindowManager::WindowManager()
{

}

WindowManager::~WindowManager()
{
    delete m_loginWindow;
    delete m_stackedWidget;
    delete m_waitingWindowClient;
    delete m_waitingWindowServer;
}

void WindowManager::setStackedWidget(QStackedWidget *stackedWidget)
{
    m_stackedWidget = stackedWidget;

}


void WindowManager::showLoginWindow() {
    if (!m_loginWindow) {
        this->m_loginWindow = new LoginWindow();
        connect(m_loginWindow->getLoginButton(), &QPushButton::clicked, this, &WindowManager::handleLoginClicked);    }

    if (m_stackedWidget) {
        qDebug() << "Showing Login Window.";
        m_stackedWidget->addWidget(m_loginWindow);
        m_stackedWidget->setCurrentWidget(m_loginWindow);
    }
}

void WindowManager::handleLoginClicked()
{
    if(m_loginWindow->isClientChecked())
    {
        this->showWaitingWindowClient();
        Engine::instance()->getCommunicationManager()->startClient(); // TODO: Guard if server hasnt been started yet.
        if(!m_drawingCanvas)
        {
            m_drawingCanvas = new DrawingCanvas();
        }
        m_drawingCanvas->show();

    }

    if (m_loginWindow->isServerChecked()) {
        m_loginWindow->close();
        m_waitingWindowServer = new WaitingWindowServer();
        m_waitingWindowServer->show();

        // Start the CommunicationManager as a server and provide a callback
        Engine::instance()->getCommunicationManager()->startServer(); // TODO: Implement a method to wait until client connects.

        if(!m_drawingCanvas)
        {
            m_drawingCanvas = new DrawingCanvas();
        }
        m_drawingCanvas->show();

    }
}

void WindowManager::showWaitingWindowClient()
{
    if(!m_waitingWindowClient)
    {
        m_waitingWindowClient = new WaitingWindowClient;
    }

    if(m_stackedWidget)
    {
        m_stackedWidget->addWidget(m_waitingWindowClient);
        m_stackedWidget->setCurrentWidget(m_waitingWindowClient);
    }
}



void WindowManager::showDrawingWindow()
{
    if(!m_drawingCanvas)
    {
        m_drawingCanvas = new DrawingCanvas;
    }

    if(m_stackedWidget)
    {
        m_stackedWidget->addWidget(m_drawingCanvas);
        m_stackedWidget->setCurrentWidget(m_drawingCanvas);
    }
}


