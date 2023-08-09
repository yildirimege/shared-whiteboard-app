#include <QMainWindow>

#include "Engine/Engine.h"
#include "Managers/WindowManager.h"
#include "QtWidgets/qapplication.h"


Engine* Engine::m_instance = nullptr;

Engine* Engine::instance()
{
    if(m_instance == nullptr)
    {
        m_instance = new Engine;
    }
    return m_instance;
}

void Engine::init()
{
    m_WindowManager = std::make_unique<WindowManager>();
    m_CommunicationManager = std::make_unique<CommunicationManager>();
}


void Engine::start(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Shared Whiteboard");

    // Create a stacked widget to manage windows
    QStackedWidget* stackedWidget = new QStackedWidget(&mainWindow);
    mainWindow.setCentralWidget(stackedWidget);

    // Set the stacked widget for the WindowManager
    m_WindowManager->setStackedWidget(stackedWidget);

    // Show the initial window (LoginWindow)
    m_WindowManager->showLoginWindow();

    // Show the main window
    mainWindow.show();

    app.exec();
}


CommunicationManager* Engine::getCommunicationManager() const
{
    return m_CommunicationManager.get();
}
