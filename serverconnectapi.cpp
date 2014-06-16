#include "serverconnectapi.h"

namespace SSJ {
sf::TcpSocket *ServerConnectAPI::Socket = NULL;

bool ServerConnectAPI::isInArray(Json::Value element, Json::Value array)
{
    for(unsigned int index=0; index<array.size(); index++){
        if(array[index] == element)
            return true;
    }
    return false;
}

void ServerConnectAPI::deletePointersToObjectFromGameLayers(Object* pointer)
{
    for( map <string, GameLayer*>::iterator it = LayerContainer::layers.begin() ;
        it != LayerContainer::layers.end();
        it++){
        if(it->second->isDynamic()){
            for(int i =0; i < it->second->getObjects()->size(); i++ ){
                if( it->second->getObjects()->at(i) == pointer ){
                   // cout << it->second->getObjects()->at(i) << endl;
                    it->second->getObjects()->at(i) = NULL;
                    return;
                }
            }
        }

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
                    const Json::Value arrayToDelete = root[_J(_delete)];
                    //cout << root << endl;
                    vector <Object*> toDelete;

                    if(root[_J(_synchronize)] != Json::nullValue ){
                        DataContainer::mutex.lock();
                        /**Synchronize and delte exist object*/
                        for(int i = 0 ; i <  DataContainer::ObjectLists.size(); i++){
                            if(ServerConnectAPI::isInArray(i, arrayToDelete)){
                                ServerConnectAPI::deletePointersToObjectFromGameLayers(DataContainer::ObjectLists.at(i));
                                toDelete.push_back(DataContainer::ObjectLists.at(i));
                            }else{
                                if(static_cast<ObjectType>(root[_J(_synchronize)][i][_J(_objectName)].asInt()) != _Bullet){
									DataContainer::ObjectLists.at(i)->SynchronizationObject(root[_J(_synchronize)][i]);
                                    cout << "sync bullet: " << i << endl;
                                }
                            }

                        }
                        /**Create new Object when it doesn't exist*/
                        for(int i =  DataContainer::ObjectLists.size() ; i <  objectsNumber.asInt(); i++){

                            switch (static_cast<ObjectType>(root[_J(_synchronize)][i][_J(_objectName)].asInt())) {
                            case _MainPlayer:
                                if(root[_J(_synchronize)][i][_J(_playerId)] == Config::PlayerId)
                                    ObjectManager::CreateMainPlayer(root[_J(_synchronize)][i]);
                                else
                                    ObjectManager::CreatePlayer(root[_J(_synchronize)][i]);
                                break;
                            case _Bullet:
                                    ObjectManager::CreateBullet(root[_J(_synchronize)][i]);
                                break;
                            case _Weapon:
                                    ObjectManager::CreateWeapon(root[_J(_synchronize)][i]);
                                break;

                            default:
                                break;
                            }
                        }
                      //  /**Delete pointers eqaul null*/

                        for(vector<Object*>::iterator it=toDelete.begin(); it!=toDelete.end(); it++ )
                        {
                            cout << *it << endl;
                            for(vector<Object*>::iterator it2= DataContainer::ObjectLists.begin(); it2!= DataContainer::ObjectLists.end(); ++it2 ){
                                if(*it2 == *it ){
                                    DataContainer::ObjectLists.erase(it2);
                                    break;
                                }
                            }
                           delete *it;
                       }

                       DataContainer::mutex.unlock();
                    }
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
