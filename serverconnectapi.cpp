#include "serverconnectapi.h"

namespace SSJ {
sf::TcpSocket *ServerConnectAPI::Socket = NULL;

	void ServerConnectAPI::CreateObject(Json::Value value, int i, int indeks)
	{
		switch(static_cast<ObjectType>(value[_J(_synchronize)][i][_J(_objectName)].asInt()))
		{
		case _MainPlayer:
            if(value[_J(_synchronize)][i][_J(_playerId)] == Config::PlayerId)
                ObjectManager::CreateMainPlayer(value[_J(_synchronize)][i], indeks);
			else
                ObjectManager::CreatePlayer(value[_J(_synchronize)][i], indeks);
			break;

		case  _Bullet:
            ObjectManager::CreateBullet(value[_J(_synchronize)][i], indeks);
			break;
		default:
			break;
		}
	}

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
						if( DataContainer::ObjectLists.at(i) != NULL &&
							(!root[_J(_synchronize)][i][_J(_activity)].asBool()))
						{
							bool found = false;
							for(int j = 0 ; j < LayerContainer::GetGameLayer("trzecia")->getObjects()->size() ; ++j)
							{
								if(LayerContainer::GetGameLayer("trzecia")->getObjects()->at(j) == DataContainer::ObjectLists.at(i))
								{
									LayerContainer::GetGameLayer("trzecia")->getObjects()->erase(LayerContainer::GetGameLayer("trzecia")->getObjects()->begin()+j);
									found = true;
									break;
								}
							}
							for(int j = 0 ; j < LayerContainer::GetGameLayer("druga")->getObjects()->size() && !found; ++j)
							{
								if(LayerContainer::GetGameLayer("druga")->getObjects()->at(j) == DataContainer::ObjectLists.at(i))
								{
									LayerContainer::GetGameLayer("druga")->getObjects()->erase(LayerContainer::GetGameLayer("druga")->getObjects()->begin()+j);
									
									break;
								}
							}
							delete DataContainer::ObjectLists.at(i);
							DataContainer::ObjectLists.at(i) = NULL;
						}
						else if(DataContainer::ObjectLists.at(i) == NULL && root[_J(_synchronize)][i][_J(_activity)].asBool())
						{
							CreateObject(root, i, i);
						}
						else if(DataContainer::ObjectLists.at(i) != NULL &&
							root[_J(_synchronize)][i][_J(_activity)].asBool() &&
							DataContainer::ObjectLists.at(i)->getSyncId() != root[_J(_synchronize)][i][_J(_syncId)].asInt())
						{
							bool found = false;
							for(int j = 0 ; j < LayerContainer::GetGameLayer("trzecia")->getObjects()->size() ; ++j)
							{
								if(LayerContainer::GetGameLayer("trzecia")->getObjects()->at(j) == DataContainer::ObjectLists.at(i))
								{
									LayerContainer::GetGameLayer("trzecia")->getObjects()->erase(LayerContainer::GetGameLayer("trzecia")->getObjects()->begin()+j);
									found = true;
									break;
								}
							}
							for(int j = 0 ; j < LayerContainer::GetGameLayer("druga")->getObjects()->size() && !found ; ++j)
							{
								if(LayerContainer::GetGameLayer("druga")->getObjects()->at(j) == DataContainer::ObjectLists.at(j))
								{
									LayerContainer::GetGameLayer("druga")->getObjects()->erase(LayerContainer::GetGameLayer("druga")->getObjects()->begin()+j);
									break;
								}
							}
							
							delete DataContainer::ObjectLists.at(i);
							DataContainer::ObjectLists.at(i) = NULL;
							CreateObject(root, i, i);
						}
						else if( DataContainer::ObjectLists.at(i) != NULL)
						{
							DataContainer::ObjectLists.at(i)->SynchronizationObject(root[_J(_synchronize)][i]);
						}
					}
					for(int i =  DataContainer::ObjectLists.size() ; i <  objectsNumber.asInt(); i++){
                        CreateObject(root, i);
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
