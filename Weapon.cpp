#include "Weapon.h"
namespace SSJ {

	Weapon::Weapon(){
		this->firstFiredBullet = true;
		this->activity = true;
		this->isReloading = false;
		this->isGettingUsed = false;
    }

	Weapon::~Weapon(){

	}

	void Weapon::draw(){

	}

	void Weapon::update(){
		if(this->ammo == 0 && this->isGettingUsed)
			Reload();
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




	void Weapon::Shoot(){
		

		this->timeBetweenBullets = this->bulletClock.getElapsedTime();
		if(!isReloading){
			if(getAmmo() > 0){
				if(firstFiredBullet || timeBetweenBullets.asSeconds() > this->fireRate){
					this->bulletClock.restart();
					Request tmp;
                    tmp.action = _createBullet;
                    tmp.parameters[_J(_ownerSyncId)] = this->owner->getSyncId();
                    tmp.parameters[_J(_ownerPositionX)] = this->owner->getMapPosition().x;
                    tmp.parameters[_J(_ownerPositionY)] = this->owner->getMapPosition().y;
                    tmp.parameters[_J(_ownerAngle)] = this->owner->getAngle().getDegrees();
                    tmp.parameters[_J(_weaponType)] = this->type;
					DataContainer::ReqToServer.push(tmp);
                   // LayerContainer::GetGameLayer("trzecia")->addObject(Weapon::CreateBullet(this->owner->getMapPosition(), this->owner->getAngle(), this->type));
					this->decreaseAmmo();
				}
			}
		}
		if(firstFiredBullet)
			firstFiredBullet = false;
	}

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

	void Weapon::decreaseAmmo(){
        if(this->ammo > 0){
            this->ammo -= 1;
			this->allAmmo -= 1;
		}
    }

	void Weapon::Hit(){

    }

    void Weapon::HitByBlast(){

    }

	void Weapon::Reload(){
		if(!isReloading && this->ammo != this->ammoInMag && this->ammo != allAmmo && this->isGettingUsed){
			this->reloadClock.restart();
			this->isReloading = true;
		}
	}


	void Weapon::setType(const WeaponType type){
		this->type = type;
	}

	WeaponType Weapon::getType() const{
		return this->type;
	}

	void Weapon::setName(const std::string name){
		this->name = name;
	}

	std::string Weapon::getName() const{
		return this->name;
	}

	void Weapon::setAllAmmo(const int allAmmo){
        this->allAmmo = allAmmo;
    }

	int Weapon::getAllAmmo() const{
        return this->allAmmo;
    }

	void Weapon::setAmmo(const int ammo){
        this->ammo = ammo;
    }

	int Weapon::getAmmo() const{
        return this->ammo;
    }

	void Weapon::setMaxAmmo(const int maxAmmo){
		this->maxAmmo = maxAmmo;
	}

	int Weapon::getMaxAmmo() const{
		return this->maxAmmo;
	}

	void Weapon::setAmmoInMag(const int ammoInMag){
		this->ammoInMag = ammoInMag;
	}

	int Weapon::getAmmoInMag() const{
		return this->ammoInMag;
	}

	void Weapon::setReloadTime(const int reloadTime){
		this->reloadTime = reloadTime;
	}

	int Weapon::getReloadTime() const{
		return this->reloadTime;
	}

	void Weapon::setReloading(const bool b){
		this->isReloading = b;
	}

	bool Weapon::getReloading() const{
		return this->isReloading;
	}

	void Weapon::setIsGettingUsed(const bool b){
		this->isGettingUsed = b;
	}

	bool Weapon::getIsGettingUsed() const{
		return this->isGettingUsed;
	}

	void Weapon::setRange(const int range){
		this->range = range;
	}

	int Weapon::getRange() const{
		return this->range;
	}

	void Weapon::setDamage(const int damage){
        this->damage = damage;
    }

	void Weapon::setFireRate(const int fireRate){
        this->fireRate = fireRate;
    }

	void Weapon::setBlastFire(const bool blastFire){
		this->blastFire = blastFire;
	}

	void Weapon::setRepeatFire(const bool repeatFire){
		this->repeatFire = repeatFire;
	}

	bool Weapon::getRepeatFire() const{
		return this->repeatFire;
	}

	sf::Time Weapon::getReloadClockElapsedTime() const{
		return this->reloadClock.getElapsedTime();
	}


    void Weapon::SynchronizationObject(Json::Value jsonObject){
		if(jsonObject.isMember("mapPositionX")){
            this->mapPosition.x = jsonObject["mapPositionX"].asFloat();
        }
        if(jsonObject.isMember("mapPositionY")){
            this->mapPosition.y = jsonObject["mapPositionY"].asFloat();
        }
        if(jsonObject.isMember("activity")){
            this->activity = jsonObject["activity"].asBool();
        }
    }

	void Weapon::setOwner(DynamicObject* owner){
		this->owner = owner;
	}


}

