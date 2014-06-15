#ifndef WEAPON_H
#define WEAPON_H
#include "dynamicobject.h"
#include <string>
#include "BulletFactory.h"
namespace SSJ{
    class Weapon : public DynamicObject{
	private:
		WeaponType type;
		string name;
		Sprite sprite;
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
		bool firstFiredBullet; // czy pierwszy nabój został już wystrzelony
		bool isGettingUsed; // czy broń jest właśnie używana
		sf::Clock bulletClock;
		sf::Time timeBetweenBullets;
		sf::Clock reloadClock;
		sf::Time timeBetweenReloads;
		DynamicObject* owner;

    public:
		Weapon();
        ~Weapon();
		void draw();
		void update();
        void SynchronizationObject(Json::Value);

		void Shoot();
		static Bullet* CreateBullet(Point ownerPosition, SSJ::Degrees ownerAngle, WeaponType type);
		void decreaseAmmo(); // zmniejsz ilość pocisków po strzale
        void Hit(); // dla zwykłych broni
        void HitByBlast(); // dla broni obszarowych
		void Reload();

		void setType(const WeaponType);
		WeaponType getType() const;
		void setName(const std::string);
		std::string getName() const;
		void setAllAmmo(const int allAmmo);
        int getAllAmmo() const;
		void setAmmo(const int ammo);
        int getAmmo() const;
		void setMaxAmmo(const int maxAmmo);
		int getMaxAmmo() const;
		void setAmmoInMag(const int ammoInMag);
		int getAmmoInMag() const;
		void setReloadTime(const int reloadTime);
		int getReloadTime() const;
		void setReloading(const bool);
		bool getReloading() const;
		void setIsGettingUsed(const bool);
		bool getIsGettingUsed() const;
		void setRange(const int range);
		int getRange() const;
		void setDamage(const int damage);
		void setFireRate(const int fireRate);
		void setBlastFire(const bool);
		void setRepeatFire(const bool);
		bool getRepeatFire() const;
		sf::Time getReloadClockElapsedTime() const;	
		void setOwner(DynamicObject*);
    };
}
#endif
