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
        LayerContainer::GetGameLayer("trzecia")->addObject(Temp);
    }

	void ObjectManager::CreateBullet(Json::Value object){
		Bullet* Temp = new Bullet;
		Temp->SynchronizationObject(object);
		DataContainer::ObjectLists.push_back(Temp);
		LayerContainer::GetGameLayer("trzecia")->addObject(Temp);
	}

	void ObjectManager::CreateWeapon(Json::Value object){
		Weapon* Temp = new Weapon;
		Temp->SynchronizationObject(object);
		DataContainer::ObjectLists.push_back(Temp);
		LayerContainer::GetGameLayer("trzecia")->addObject(Temp);
	}


}
