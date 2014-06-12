#include "Weapon.h"
namespace SSJ {

	Bullet* Weapon::CreateBullet(Point ownerPosition, SSJ::Degrees ownerAngle, WeaponType type){
		BulletFactory::setOwnerPosition(ownerPosition);
		BulletFactory::setOwnerAngle(ownerAngle);
		switch(type){
		case Glock:
			return BulletFactory::CreateGlockBullet();
			break;
		case Uzi:
			return BulletFactory::CreateUziBullet();
			break;
		case Ak47:
			return BulletFactory::CreateAk47Bullet();
			break;
		case M16:
			return BulletFactory::CreateM16Bullet();
			break;
		case Shotgun:
			return BulletFactory::CreateShotgunBullet();
			break;
		case SniperRifle:
			return BulletFactory::CreateSniperRifleBullet();
			break;
		case Bazooka:
			return BulletFactory::CreateBazookaBullet();
			break;
		case Grenade:
			return BulletFactory::CreateGrenadeBullet();
			break;
		case Knife:
			return BulletFactory::CreateKnifeBullet();
			break;
		}
        return NULL;
	}

	void Weapon::Shoot(){
		

		this->timeBetweenBullets = this->bulletClock.getElapsedTime();
		if(!isReloading){
			if(getAmmo() > 0){
				if(firstFiredBullet || timeBetweenBullets.asSeconds() > this->fireRate){
					this->bulletClock.restart();
					Request tmp;
                    tmp.action = _createBullet;
                    tmp.parameters[_J(_ownerPositionX)] = this->owner->getMapPosition().x;
                    tmp.parameters[_J(_ownerPositionY)] = this->owner->getMapPosition().y;
                    tmp.parameters[_J(_angle)] = this->owner->getAngle().getDegrees();
                    tmp.parameters[_J(_weaponType)] = this->type;
					DataContainer::ReqToServer.push(tmp);
					LayerContainer::GetGameLayer("trzecia")->addObject(Weapon::CreateBullet(this->owner->getMapPosition(), this->owner->getAngle(), this->type));
					this->decreaseAmmo();
				}
			}
		}
		if(firstFiredBullet)
			firstFiredBullet = false;
	}


	void Weapon::Reload(){
		if(!isReloading && this->ammo != this->ammoInMag && this->ammo != allAmmo){
			this->reloadClock.restart();
			isReloading = true;
		}
	}

	bool Weapon::getReloading(){
		return this->isReloading;
	}


	WeaponType Weapon::getName(){
		return this->type;
	}

	int Weapon::getReloadTime(){
		return this->reloadTime;
	}



	Weapon::Weapon(){
		this->firstFiredBullet = true;
		this->activity = true;
		this->isReloading = false;
    }

    void Weapon::Hit(){

    }

    void Weapon::HitByBlast(){

    }

    int Weapon::getAllAmmo(){
        return this->allAmmo;
    }

    int Weapon::getAmmo(){
        return this->ammo;
    }

	int Weapon::getMaxAmmo(){
		return this->maxAmmo;
	}

	int Weapon::getAmmoInMag(){
		return this->ammoInMag;
	}


    void Weapon::setAllAmmo(int allAmmo){
        this->allAmmo = allAmmo;
    }

    void Weapon::decreaseAmmo(){
        if(this->ammo > 0){
            this->ammo -= 1;
			this->allAmmo -= 1;
		}

    }

    void Weapon::setAmmo(int ammo){
        this->ammo = ammo;
    }

    void Weapon::setReloadTime(int reloadTime){
        this->reloadTime = reloadTime;
    }

    void Weapon::setDamage(int damage){
        this->damage = damage;
    }

    void Weapon::setFireRate(int fireRate){
        this->fireRate = fireRate;
    }

	Weapon::~Weapon(){

	}

	void Weapon::draw(){

	}

	void Weapon::update(){
		if(this->ammo == 0)
			Reload();
		//cout << "ammo: " << this->ammo << "\tallAmmo: " << this->allAmmo << endl;
		if(isReloading){
			this->timeBetweenReloads = this->reloadClock.getElapsedTime();
			if(timeBetweenReloads.asSeconds() > reloadTime){
				int ammoSub = this->ammoInMag - this->ammo;
				if(this->allAmmo > this->ammo && this->allAmmo > (this->ammo + ammoSub))
					this->ammo += ammoSub;
				else
					this->ammo += (this->allAmmo - this->ammo);
				isReloading = false;
			}

		}

	}

    void Weapon::SynchronizationObject(Json::Value jsonObject){
		if(jsonObject.isMember("mapPositionX")){
            this->mapPosition.x = jsonObject["mapPositionX"].asDouble();
        }
        if(jsonObject.isMember("mapPositionY")){
            this->mapPosition.y = jsonObject["mapPositionY"].asDouble();
        }
        if(jsonObject.isMember("activity")){
            this->activity = jsonObject["activity"].asBool();
        }
    }

}

