#ifndef SERVERCONNECTAPI_H
#define SERVERCONNECTAPI_H

#include "Loader.h"
#include "objectmanager.h"
#include "mainplayer.h"
namespace SSJ{
    class ServerConnectAPI
    {
    protected:
          static  sf::TcpSocket* Socket;
            sf::Mutex mutex;
    public:
        void ServerListener();
        static void SendToServer(string);
    };
}
#endif // SERVERCONNECTAPI_H
