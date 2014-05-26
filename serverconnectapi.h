#ifndef SERVERCONNECTAPI_H
#define SERVERCONNECTAPI_H

#include "Loader.h"
namespace SSJ{
    class ServerConnectAPI
    {
    protected:
          static  sf::TcpSocket* Socket;
            sf::Mutex mutex;
    public:
        ServerConnectAPI();
        void ConnectToServer();
        void ServerListener();
        static void SendToServer(string);
    };
}
#endif // SERVERCONNECTAPI_H
