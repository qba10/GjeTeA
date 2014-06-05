#ifndef WEAPON_H
#define WEAPON_H
#include "dynamicobject.h"
#include <string>
#include "BulletFactory.h"
namespace SSJ{
    class Weapon : public DynamicObject{
    public:
		WeaponType type;
		string name;
        int range; // zasięg broni
        int bulletSpeed; // prędkość pocisku
        int fireRate; // szybkostrzelność
        int damage; // ilość obrażeń zadawanych przez 1 pocisk
        int reloadTime; // czas przeładowania
        int maxAmmo; // maksymalna ilość amunicji
        int ammo; // aktualna ilośc amunicji
        bool blastFire; // czy broń zadaje obrażenia obszarowe
		bool repeatFire; // czy broń jest jednostrzałowa czy ma strzał powtarzalny
		Sprite sprite;
		sf::Clock clock;
		sf::Time timeBetweenBullets;
		DynamicObject* owner;

    public:
		static Bullet* CreateBullet(Point ownerPosition, SSJ::Degrees ownerAngle, WeaponType type);
		WeaponType getName();
        void Hit(); // dla zwykłych broni
        void HitByBlast(); // dla broni obszarowych
        int getMaxAmmo();
        int getAmmo();
		void Shoot();
        void setMaxAmmo(int maxAmmo);
        void decreaseAmmo(); // zmniejsz ilość pocisków po strzale
        void setAmmo(int ammo);
        void setReloadTime(int reloadTime);
        void setDamage(int damage);
        void setFireRate(int fireRate);
		void draw();
		void update();
        void SynchronizationObject(Json::Value);
		Weapon();
        ~Weapon();
    };
}
#endif
