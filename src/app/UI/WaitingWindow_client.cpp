#include <QVBoxLayout>
#include <QMessageBox>
#include <iostream>

#include "UI/WaitingWindow_client.h"


WaitingWindowClient::WaitingWindowClient(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);


    // Create the welcome text
    m_welcomeLabel = new QLabel("Connecting to server...", this);
    layout->addWidget(m_welcomeLabel);


}

