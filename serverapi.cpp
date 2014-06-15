#include "serverapi.h"
namespace SSJ {

    void ServerApi::CreateRequest(RequestName request, Json::Value parametres)
    {
        Json::Value object;
        object[_J(_playerId)] = Config::PlayerId;
        object[_J(_ask)] = request;
        object[_J(_parameters)] = parametres;
        Json::FastWriter writer;
 
        ServerConnectAPI::SendToServer(writer.write(object));
    }

    void ServerApi::AskToSynchronizeMainPlayer()
    {
        if(DataContainer::MainPlayer != NULL){
            if(DataContainer::MainPlayer->isDesynchronization()){
                 ServerApi::CreateRequest(_synchronizeMainPlayer, dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->SerializeMainPlayer());
            }
        }
    }

    void ServerApi::AskToCreateMainPlayer()
    {
        ServerApi::CreateRequest(_createMainPlayer);

    }

	void ServerApi::AskToCreateBullet(Json::Value parameters){
        ServerApi::CreateRequest(_createBullet, parameters);
	}

	void ServerApi::AskToCreateWeapon(Json::Value parameters){
        ServerApi::CreateRequest(_createWeapon, parameters);
	}

}
