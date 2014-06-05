#include "serverapi.h"
namespace SSJ {

    void ServerApi::CreateRequest(string request, Json::Value parametres)
    {
        Json::Value object;
        object["playerId"] = Config::PlayerId;
        object["ask"] = request;
        object["parametres"] = parametres;
        Json::FastWriter writer;
 
        ServerConnectAPI::SendToServer(writer.write(object));


    }

    void ServerApi::AskToSynchronizeMainPlayer()
    {
        if(DataContainer::MainPlayer != NULL){
            if(DataContainer::MainPlayer->isDesynchronization()){
                 ServerApi::CreateRequest("synchronizeMainPlayer", dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->SerializeMainPlayer());
            }
        }
    }

    void ServerApi::AskToCreateMainPlayer()
    {
        ServerApi::CreateRequest("createMainPlayer");

    }

	void ServerApi::AskToCreateBullet(Json::Value parameters){
		ServerApi::CreateRequest("createBullet", parameters);
		
	}




}
