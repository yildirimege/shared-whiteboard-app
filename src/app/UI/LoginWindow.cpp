#include <QVBoxLayout>
#include <QMessageBox>
#include <iostream>

#include "LoginWindow.h"


LoginWindow::LoginWindow() : QWidget() {
    qDebug() << "Created a Login Window.";
    QVBoxLayout* layout = new QVBoxLayout(this);

    // Create the welcome text
    m_welcomeLabel = new QLabel("Welcome to Shared Whiteboard! Please verify your identity and login.", this);
    layout->addWidget(m_welcomeLabel);

    // Create the checkboxes for Host and Client
    m_hostCheckbox = new QCheckBox("Login as Server", this);
    m_clientCheckbox = new QCheckBox("Login as Client", this);
    layout->addWidget(m_hostCheckbox);
    layout->addWidget(m_clientCheckbox);

    // Create the Login button
    m_loginButton = new QPushButton("Login", this);
    layout->addWidget(m_loginButton);

    // Connect the Login button's clicked signal to the onLogin slot
    connect(m_loginButton, &QPushButton::clicked, this, &LoginWindow::onLogin);
}

LoginWindow::~LoginWindow()
{
    qDebug() << "Deleted the Login Window.";
    delete m_welcomeLabel;
    delete m_hostCheckbox;
    delete m_clientCheckbox;
    delete m_loginButton;
}

void LoginWindow::onLogin() {
    if (m_hostCheckbox->isChecked()) {
        // Handle login as Host
        // Start the whiteboard server
        QMessageBox::information(this, "Login", "Logged in as Host.");
    } else if (m_clientCheckbox->isChecked()) {
        // Handle login as Client
        // Connect to the whiteboard server

        QMessageBox::information(this, "Login", "Logged in as Client.");

    } else {
        // No checkbox is selected
        QMessageBox::warning(this, "Login", "Please select either 'Login as Host' or 'Login as Client'.");
    }
}

QPushButton *LoginWindow::getLoginButton()
{
    return m_loginButton;
}


bool LoginWindow::isClientChecked()
{
    return this->m_clientCheckbox->isChecked();
}

bool LoginWindow::isServerChecked()
{
    return this->m_hostCheckbox->isChecked();
}
