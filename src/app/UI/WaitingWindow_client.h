#ifndef WAITINGWINDOW_CLIENT_H
#define WAITINGWINDOW_CLIENT_H


#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>

class WaitingWindowClient : public QWidget {
Q_OBJECT
public:
    explicit WaitingWindowClient(QWidget* parent = nullptr);
    void connectToServer();



private:
    QLabel* m_welcomeLabel;

};


#endif // WAITINGWINDOW_CLIENT_H
