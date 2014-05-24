#include "Weapon.h"
namespace SSJ {


    Weapon::Weapon(){
        this->ammo = maxAmmo;
    }

    void Weapon::Hit(){

    }

    void Weapon::HitByBlast(){

    }

    int Weapon::getMaxAmmo(){
        return maxAmmo;
    }

    int Weapon::getAmmo(){
        return ammo;
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
}

