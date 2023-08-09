#include <QVBoxLayout>
#include <QMessageBox>
#include <iostream>

#include "UI/WaitingWindow_server.h"


WaitingWindowServer::WaitingWindowServer(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);
    QMovie* spinner = new QMovie("200.gif");

    // Create the welcome text
    m_welcomeLabel = new QLabel("Welcome to the Shared Whiteboard Server!", this);
    m_welcomeLabel->setMovie(spinner);
    layout->addWidget(m_welcomeLabel);

}

