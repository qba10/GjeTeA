#include "objectmanager.h"
namespace SSJ {
	int ObjectManager::nextId = 0;

    void ObjectManager::CreateMainPlayer(Json::Value object, int indeks)
    {
		MainPlayer* Temp = new MainPlayer();
        Temp->SynchronizationObject(object);
		if(indeks == -1)
			DataContainer::ObjectLists.push_back(Temp);
		else
			DataContainer::ObjectLists[indeks] = Temp;
        DataContainer::MainPlayer = Temp;
        LayerContainer::GetGameLayer("druga")->addObject(Temp);
    }

    void ObjectManager::CreatePlayer(Json::Value object, int indeks)
    {
        Player* Temp = new Player();
        Temp->SynchronizationObject(object);
        if(indeks == -1)
			DataContainer::ObjectLists.push_back(Temp);
		else
			DataContainer::ObjectLists[indeks] = Temp;
        LayerContainer::GetGameLayer("trzecia")->addObject(Temp);
    }

	void ObjectManager::CreateBullet(Json::Value object, int indeks){
		Bullet* Temp = new Bullet();
		Temp->SynchronizationObject(object);
		if(indeks == -1)
			DataContainer::ObjectLists.push_back(Temp);
		else
			DataContainer::ObjectLists[indeks] = Temp;
		LayerContainer::GetGameLayer("trzecia")->addObject(Temp);
	}



}
