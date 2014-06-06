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
        int fireRate; // szybkostrzelność
        int damage; // ilość obrażeń zadawanych przez 1 pocisk
        int reloadTime; // czas przeładowania
		bool isReloading;
		int ammoInMag; // maksymalna ilość amunicji w magazynku
        int maxAmmo; // maksumalna ilość amunicji dla broni
        int ammo; // aktualna ilośc amunicji
		int allAmmo; // wszytskie pocisnki w broni aktualnie
        bool blastFire; // czy broń zadaje obrażenia obszarowe
		bool repeatFire; // czy broń jest jednostrzałowa czy ma strzał powtarzalny
		bool firstFiredBullet;
		Sprite sprite;
		sf::Clock bulletClock;
		sf::Time timeBetweenBullets;
		sf::Clock reloadClock;
		sf::Time timeBetweenReloads;
		DynamicObject* owner;

    public:
		static Bullet* CreateBullet(Point ownerPosition, SSJ::Degrees ownerAngle, WeaponType type);
		WeaponType getName();
        void Hit(); // dla zwykłych broni
        void HitByBlast(); // dla broni obszarowych
        int getAllAmmo();
        int getAmmo();
		void Shoot();
        void setAllAmmo(int allAmmo);
        void decreaseAmmo(); // zmniejsz ilość pocisków po strzale
        void setAmmo(int ammo);
        void setReloadTime(int reloadTime);
        void setDamage(int damage);
        void setFireRate(int fireRate);
		void Reload();
		void draw();
		void update();
        void SynchronizationObject(Json::Value);
		Weapon();
        ~Weapon();
    };
}
#endif
