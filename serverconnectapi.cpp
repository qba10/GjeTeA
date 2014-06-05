#include "serverconnectapi.h"

namespace SSJ {
sf::TcpSocket *ServerConnectAPI::Socket = NULL;

    void ServerConnectAPI::ServerListener(){
        DataContainer::SendMutex.lock();
        sf::TcpSocket socket;
        sf::IpAddress ip =  sf::IpAddress("127.0.0.1");
        socket.connect(ip, 2005);
        sf::Packet packet;
        packet << Config::PlayerId;
        socket.send(packet);
        socket.setBlocking(false);
        ServerConnectAPI::Socket = &socket;
        DataContainer::SendMutex.unlock();
        while(true)
        {
          // DataContainer::SendMutex.lock();
           if(ServerConnectAPI::Socket->receive(packet) == sf::Socket::Done){
                std::string temptext;
                if(packet >> temptext)
                {
                    Json::Value root;
                    Json::Reader reader;
                    reader.parse(temptext, root, false);
                    Json::Value objectsNumber = root[_J(_objectAmount)];
                    // cout << temptext << endl;

					DataContainer::mutex.lock();
					for(int i = 0 ; i <  DataContainer::ObjectLists.size(); i++){
                        DataContainer::ObjectLists.at(i)->SynchronizationObject(root[_J(_synchronize)][i]);
					}
					for(int i =  DataContainer::ObjectLists.size() ; i <  objectsNumber.asInt(); i++){
                        if(static_cast<ObjectType>(root[_J(_synchronize)][i][_J(_objectName)].asInt()) == _MainPlayer){
                            if(root[_J(_synchronize)][i][_J(_playerId)] == Config::PlayerId)
                                ObjectManager::CreateMainPlayer(root[_J(_synchronize)][i]);
							else
                                ObjectManager::CreatePlayer(root[_J(_synchronize)][i]);


						}
                        else if(static_cast<ObjectType>(root[_J(_synchronize)][i][_J(_objectName)].asInt()) == _Bullet){
                            ObjectManager::CreateBullet(root[_J(_synchronize)][i]);
						}

					}


                   DataContainer::mutex.unlock();
                }
           }
        }
    }

    void ServerConnectAPI::SendToServer(string json){

        sf::Packet packet;
        packet << json;
        DataContainer::SendMutex.lock();
        ServerConnectAPI::Socket->send(packet);
        DataContainer::SendMutex.unlock();

    }
}
