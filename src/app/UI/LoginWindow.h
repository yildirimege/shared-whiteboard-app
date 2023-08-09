#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>

class LoginWindow : public QWidget {
Q_OBJECT
public:
    LoginWindow();
    ~LoginWindow();

    bool isClientChecked();
    bool isServerChecked();
    void onLogin();

    QPushButton* getLoginButton();
private:
    QLabel* m_welcomeLabel;
    QCheckBox* m_hostCheckbox;
    QCheckBox* m_clientCheckbox;
    QPushButton* m_loginButton;

};

#endif // LOGINWINDOW_H
