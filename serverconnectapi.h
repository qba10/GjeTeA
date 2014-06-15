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
            static bool isInArray(Json::Value element, Json::Value array);
            static void deletePointersToObjectFromGameLayers(Object* pointer);
    public:
        void ServerListener();
        static void SendToServer(string);
		static void CreateObject(Json::Value value, int i, int indeks=-1);
    };
}
#endif // SERVERCONNECTAPI_H
