#ifndef COMMUNICATIONMANAGER_H
#define COMMUNICATIONMANAGER_H

#include <boost/asio.hpp>
#include <functional>

#include "Client/client.h"
#include "Server/server.h"

class CommunicationManager {
public:
    CommunicationManager();
    ~CommunicationManager() = default;

    void startServer();
    void startClient();

    client* getClient();

    server* getServer();
private:
    client* m_client;
    server* m_server;
};

#endif // COMMUNICATIONMANAGER_H
