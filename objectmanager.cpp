#include "objectmanager.h"
namespace SSJ {

    void ObjectManager::CreateMainPlayer(Json::Value object)
    {
        MainPlayer* Temp = new MainPlayer;
        Temp->SynchronizationObject(object);
        DataContainer::ObjectLists.push_back(Temp);
        DataContainer::MainPlayer = Temp;
        LayerContainer::GetGameLayer("druga")->addObject(Temp);
    }

    void ObjectManager::CreatePlayer(Json::Value object)
    {
        Player* Temp = new Player;
        Temp->SynchronizationObject(object);
        DataContainer::ObjectLists.push_back(Temp);
        LayerContainer::GetGameLayer("druga")->addObject(Temp);
    }




}
