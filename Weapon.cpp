#include "Weapon.h"
#include "Bullet.h"
namespace SSJ {

	void Weapon::Shoot(){
		
		this->timeBetweenBullets = this->clock.getElapsedTime();
		this->clock.restart();
		if(timeBetweenBullets.asSeconds() > this->fireRate)
			Bullet* bullet = new Bullet();
	}

	string Weapon::getName(){
		return this->name;
	}
    Weapon::Weapon(){
        this->ammo = maxAmmo;
		this->clock.restart();
    }

    void Weapon::Hit(){

    }

    void Weapon::HitByBlast(){

    }

    int Weapon::getMaxAmmo(){
        return this->maxAmmo;
    }

    int Weapon::getAmmo(){
        return this->ammo;
    }

    void Weapon::setMaxAmmo(int maxAmmo){
        this->maxAmmo = maxAmmo;
    }

    void Weapon::decreaseAmmo(){
        if(this->ammo > 0)
            this->ammo -= 1;
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
}

