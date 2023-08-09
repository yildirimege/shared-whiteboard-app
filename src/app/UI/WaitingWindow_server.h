#ifndef WAITINGWINDOW_SERVER_H
#define WAITINGWINDOW_SERVER_H

#include <QtWidgets>
#include <QtCore>


class WaitingWindowServer : public QWidget {
    Q_OBJECT
public:
    explicit WaitingWindowServer(QWidget* parent = nullptr);




private:
    QLabel* m_welcomeLabel;
    QMovie* m_spinnerAnim;

};

#endif // WAITINGWINDOW_SERVER_H
