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
        Bullet* Temp ;
        switch(static_cast<JsonOption>(object[_J(_weaponType)].asInt())){
        case Uzi:
           Temp = BulletFactory::CreateUziBullet();
           break;
        case Ak47:
            Temp = BulletFactory::CreateAk47Bullet();
            break;
        case Bazooka:
            Temp = BulletFactory::CreateBazookaBullet();
            break;
        case Glock:
            Temp = BulletFactory::CreateGlockBullet();
            break;
        case SniperRifle:
            Temp = BulletFactory::CreateSniperRifleBullet();
            break;
        case M16:
            Temp = BulletFactory::CreateM16Bullet();
            break;
        case Knife:
            Temp = BulletFactory::CreateKnifeBullet();
            break;
        case Shotgun:
            Temp = BulletFactory::CreateShotgunBullet();
            break;
        case Grenade:
            Temp = BulletFactory::CreateGrenadeBullet();
            break;
        }
		Temp->SynchronizationObject(object);
		if(indeks == -1)
			DataContainer::ObjectLists.push_back(Temp);
		else
			DataContainer::ObjectLists[indeks] = Temp;
		LayerContainer::GetGameLayer("trzecia")->addObject(Temp);
	}

	void ObjectManager::CreateWeapon(Json::Value object){
		Weapon* Temp = new Weapon;
		Temp->SynchronizationObject(object);
		DataContainer::ObjectLists.push_back(Temp);
		LayerContainer::GetGameLayer("trzecia")->addObject(Temp);
	}
}
