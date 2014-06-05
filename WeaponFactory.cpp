#include "WeaponFactory.h"
namespace SSJ {
	DynamicObject* WeaponFactory::owner = NULL;

	void WeaponFactory::setOwner(DynamicObject* owner){
		WeaponFactory::owner = owner;
	}


    Weapon* WeaponFactory::CreateGlockObject(){
        Weapon *GlockObject = new Weapon();
		GlockObject->type =			Glock;
		GlockObject->name =			"Glock";
        GlockObject->range = 		4;
        GlockObject->fireRate = 	0.01;
        GlockObject->damage = 		5;
        GlockObject->reloadTime = 	9;
        GlockObject->maxAmmo = 		85;
		GlockObject->ammoInMag =	17;
		GlockObject->ammo =			17;
		GlockObject->allAmmo =		3*17;
        GlockObject->blastFire = 	false;
		GlockObject->repeatFire =	false;
		GlockObject->owner =		WeaponFactory::owner;
        return GlockObject;
    }

    Weapon* WeaponFactory::CreateUziObject(){
        Weapon *UziObject = new Weapon();
		UziObject->type =			Uzi;
		UziObject->name =			"Uzi";
        UziObject->range = 			5;
        UziObject->fireRate = 		0.1;
        UziObject->damage = 		4;
        UziObject->reloadTime = 	8;
        UziObject->maxAmmo = 		200;
		UziObject->ammoInMag =		40;
		UziObject->ammo =			40;
		UziObject->allAmmo =		3*40;
        UziObject->blastFire = 		false;
		UziObject->repeatFire =		true;
		UziObject->owner =			WeaponFactory::owner;
        return UziObject;
    }

    Weapon* WeaponFactory::CreateAk47Object(){
        Weapon *Ak47Object = new Weapon();
		Ak47Object->type =			Ak47;
		Ak47Object->name =			"Ak-47";
        Ak47Object->range = 		7;
        Ak47Object->fireRate = 		0.2;
        Ak47Object->damage = 		7;
        Ak47Object->reloadTime = 	5;
        Ak47Object->maxAmmo = 		150;
		Ak47Object->ammoInMag =		30;
		Ak47Object->ammo =			30;
		Ak47Object->allAmmo =		3*30;
        Ak47Object->blastFire = 	false;
		Ak47Object->repeatFire =	true;
		Ak47Object->owner =			WeaponFactory::owner;
        return Ak47Object;
    }

    Weapon* WeaponFactory::CreateM16Object(){
        Weapon *M16Object = new Weapon();
		M16Object->type =			M16;
		M16Object->name =			"M-16";
        M16Object->range = 			8;
        M16Object->fireRate = 		0.08;
        M16Object->damage = 		6;
        M16Object->reloadTime = 	5;
        M16Object->maxAmmo = 		150;
		M16Object->ammoInMag =		30;
		M16Object->ammo =			30;
		M16Object->allAmmo =		3*30;
        M16Object->blastFire = 		false;
		M16Object->repeatFire =		true;
		M16Object->owner =			WeaponFactory::owner;
        return M16Object;
    }

    Weapon* WeaponFactory::CreateShotgunObject(){
        Weapon *ShotgunObject = new Weapon();
		ShotgunObject->type =			Shotgun;
		ShotgunObject->name =			"Shotgun";
        ShotgunObject->range = 			3;
        ShotgunObject->fireRate = 		1;
        ShotgunObject->damage = 		8;
        ShotgunObject->reloadTime = 	4;
        ShotgunObject->maxAmmo = 		150;
		ShotgunObject->ammoInMag =		30;
		ShotgunObject->ammo =			30;
		ShotgunObject->allAmmo =		3*30;
        ShotgunObject->blastFire = 		false;
		ShotgunObject->repeatFire =		false;
		ShotgunObject->owner =			WeaponFactory::owner;
        return ShotgunObject;
    }

    Weapon* WeaponFactory::CreateSniperRifleObject(){
        Weapon *SniperRifleObject = new Weapon();
		SniperRifleObject->type =			SniperRifle;
		SniperRifleObject->name =			"Sniper rifle";
        SniperRifleObject->range = 			10;
		SniperRifleObject->fireRate = 		4;
        SniperRifleObject->damage = 		10;
        SniperRifleObject->reloadTime = 	9;
        SniperRifleObject->maxAmmo = 		25;
		SniperRifleObject->ammoInMag =		5;
		SniperRifleObject->ammo =			5;
		SniperRifleObject->allAmmo =		3*5;
        SniperRifleObject->blastFire =		false;
		SniperRifleObject->repeatFire =		false;
		SniperRifleObject->owner =			WeaponFactory::owner;
        return SniperRifleObject;
    }

    Weapon* WeaponFactory::CreateBazookaObject(){
        Weapon *BazookaObject = new Weapon();
		BazookaObject->type =			Bazooka;
		BazookaObject->name =			"Bazooka";
        BazookaObject->range = 			6;
        BazookaObject->fireRate = 		5;
        BazookaObject->damage = 		10;
        BazookaObject->reloadTime = 	8;
        BazookaObject->maxAmmo = 		8;
		BazookaObject->ammoInMag =		1;
		BazookaObject->ammo =			1;
		BazookaObject->allAmmo =		5*1;
        BazookaObject->blastFire = 		true;
		BazookaObject->repeatFire =		false;
		BazookaObject->owner =			WeaponFactory::owner;
        return BazookaObject;
    }

    Weapon* WeaponFactory::CreateGrenadeObject(){
        Weapon *GrenadeObject = new Weapon();
		GrenadeObject->type =			Grenade;
		GrenadeObject->name =			"Grenade";
        GrenadeObject->range = 			5;
        GrenadeObject->fireRate = 		1;
        GrenadeObject->damage = 		10;
        GrenadeObject->reloadTime = 	5;
        GrenadeObject->maxAmmo = 		5;
		GrenadeObject->ammoInMag =		1;
		GrenadeObject->ammo =			1;
		GrenadeObject->allAmmo =		3*1;
        GrenadeObject->blastFire = 		true;
		GrenadeObject->repeatFire =		false;
		GrenadeObject->owner =			WeaponFactory::owner;
        return GrenadeObject;
    }

    Weapon* WeaponFactory::CreateKnifeObject(){
        Weapon *KnifeObject = new Weapon();
		KnifeObject->type =				Knife;
		KnifeObject->name =				"Knife";
        KnifeObject->range = 			1;
        KnifeObject->fireRate = 		0.3;
        KnifeObject->damage = 			4;
        KnifeObject->reloadTime = 		10;
        KnifeObject->maxAmmo = 			0;
		KnifeObject->ammoInMag =		0;
		KnifeObject->ammo =				0;
		KnifeObject->allAmmo =			0;
        KnifeObject->blastFire = 		true;
		KnifeObject->repeatFire =		true;
		KnifeObject->owner =			WeaponFactory::owner;
        return KnifeObject;
    }
}
