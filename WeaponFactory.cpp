#pragma once
#include "WeaponFactory.h"
namespace SSJ {
    Weapon* WeaponFactory::CreateGlockObject(){
        Weapon *Glock = new Weapon();
		Glock->name =			"Glock";
        Glock->range = 			4;
        Glock->bulletSpeed = 	5;
        Glock->fireRate = 		5;
        Glock->damage = 		5;
        Glock->reloadTime = 	9;
        Glock->maxAmmo = 		3*17;
        Glock->blastFire = 		false;
		Glock->repeatFire =		false;
        return Glock;
    }

    Weapon* WeaponFactory::CreateUziObject(){
        Weapon *Uzi = new Weapon();
		Uzi->name =				"Uzi";
        Uzi->range = 			5;
        Uzi->bulletSpeed = 		6;
        Uzi->fireRate = 		9;
        Uzi->damage = 			4;
        Uzi->reloadTime = 		8;
        Uzi->maxAmmo = 			3*40;
        Uzi->blastFire = 		false;
		Uzi->repeatFire =		true;
        return Uzi;
    }

    Weapon* WeaponFactory::CreateAk47Object(){
        Weapon *Ak47 = new Weapon();
		Ak47->name =			"Ak-47";
        Ak47->range = 			7;
        Ak47->bulletSpeed = 	8;
        Ak47->fireRate = 		7;
        Ak47->damage = 			7;
        Ak47->reloadTime = 		5;
        Ak47->maxAmmo = 		3*30;
        Ak47->blastFire = 		false;
		Ak47->repeatFire =		true;
        return Ak47;
    }

    Weapon* WeaponFactory::CreateM16Object(){
        Weapon *M16 = new Weapon();
		M16->name =				"M-16";
        M16->range = 			8;
        M16->bulletSpeed = 		9;
        M16->fireRate = 		7;
        M16->damage = 			6;
        M16->reloadTime = 		5;
        M16->maxAmmo = 			3*30;
        M16->blastFire = 		false;
		M16->repeatFire =		true;
        return M16;
    }

    Weapon* WeaponFactory::CreateShotgunObject(){
        Weapon *Shotgun = new Weapon();
		Shotgun->name =				"Shotgun";
        Shotgun->range = 			3;
        Shotgun->bulletSpeed = 		7;
        Shotgun->fireRate = 		3;
        Shotgun->damage = 			8;
        Shotgun->reloadTime = 		4;
        Shotgun->maxAmmo = 			3*30;
        Shotgun->blastFire = 		false;
		Shotgun->repeatFire =		false;
        return Shotgun;
    }

    Weapon* WeaponFactory::CreateSniperRifleObject(){
        Weapon *SniperRifle = new Weapon();
		SniperRifle->name =			"Sniper rifle";
        SniperRifle->range = 		10;
        SniperRifle->bulletSpeed = 	8;
        SniperRifle->fireRate = 	1;
        SniperRifle->damage = 		10;
        SniperRifle->reloadTime = 	9;
        SniperRifle->maxAmmo = 		3*5;
        SniperRifle->blastFire = 	false;
		SniperRifle->repeatFire =	false;
        return SniperRifle;
    }

    Weapon* WeaponFactory::CreateBazookaObject(){
        Weapon *Bazooka = new Weapon();
		Bazooka->name =				"Bazooka";
        Bazooka->range = 			6;
        Bazooka->bulletSpeed =	 	2;
        Bazooka->fireRate = 		3;
        Bazooka->damage = 			10;
        Bazooka->reloadTime = 		8;
        Bazooka->maxAmmo = 			5*1;
        Bazooka->blastFire = 		true;
		Bazooka->repeatFire =		false;
        return Bazooka;
    }

    Weapon* WeaponFactory::CreateGrenadeObject(){
        Weapon *Grenade = new Weapon();
		Grenade->name =				"Grenade";
        Grenade->range = 			5;
        Grenade->bulletSpeed = 		3;
        Grenade->fireRate = 		7;
        Grenade->damage = 			10;
        Grenade->reloadTime = 		5;
        Grenade->maxAmmo = 			3*1;
        Grenade->blastFire = 		true;
		Grenade->repeatFire =		false;
        return Grenade;
    }

    Weapon* WeaponFactory::CreateKnifeObject(){
        Weapon *Knife = new Weapon();
		Knife->name =				"Knife";
        Knife->range = 				1;
        Knife->bulletSpeed = 		10;
        Knife->fireRate = 			6;
        Knife->damage = 			4;
        Knife->reloadTime = 		10;
        Knife->maxAmmo = 			0;
        Knife->blastFire = 			true;
		Knife->repeatFire =			true;
        return Knife;
    }
}
