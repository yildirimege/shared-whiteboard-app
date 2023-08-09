#include "CommunicationManager.h"
#include <iostream>

CommunicationManager::CommunicationManager()
{

}

client *CommunicationManager::getClient()
{
    return m_client;
}

server *CommunicationManager::getServer()
{
    return m_server;
}

void CommunicationManager::startClient()
{
    m_client = new client("127.0.0.1", 12345);
}

void CommunicationManager::startServer()
{
    m_server = new server("127.0.0.1", 12345, 1);
}
