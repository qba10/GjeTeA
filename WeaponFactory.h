#include "Weapon.h"

class WeaponFactory{
	Weapon* Glock();
	Weapon* Uzi();
	Weapon* Ak47();
	Weapon* M16();
	Weapon* Shotgun();
	Weapon* SniperRifle();
	Weapon* Bazooka();
	Weapon* Grenade();
	Weapon* Knife();
};

Weapon* WeaponFactory::Glock(){
	Weapon *Glock = new Weapon();
	Glock->range = 			4;
	Glock->bulletSpeed = 	5;
	Glock->fireRate = 		5;
	Glock->damage = 		5;
	Glock->reloadTime = 	9;
	Glock->maxAmmo = 		3*17;
	Glock->blastFire = 		false;
	return Glock;
}

Weapon* WeaponFactory::Uzi(){
	Weapon *Uzi = new Weapon();
	Uzi->range = 			5;
	Uzi->bulletSpeed = 		6;
	Uzi->fireRate = 		9;
	Uzi->damage = 			4;
	Uzi->reloadTime = 		8;
	Uzi->maxAmmo = 			3*40;
	Uzi->blastFire = 		false;
	return Uzi;
}

Weapon* WeaponFactory::Ak47(){
	Weapon *Ak47 = new Weapon();
	Ak47->range = 			7;
	Ak47->bulletSpeed = 	8;
	Ak47->fireRate = 		7;
	Ak47->damage = 			7;
	Ak47->reloadTime = 		5;
	Ak47->maxAmmo = 		3*30;
	Ak47->blastFire = 		false;
	return Ak47;
}

Weapon* WeaponFactory::M16(){
	Weapon *M16 = new Weapon();
	M16->range = 			8;
	M16->bulletSpeed = 		9;
	M16->fireRate = 		7;
	M16->damage = 			6;
	M16->reloadTime = 		5;
	M16->maxAmmo = 			3*30;
	M16->blastFire = 		false;
	return M16;
}

Weapon* WeaponFactory::Shotgun(){
	Weapon *Shotgun = new Weapon();
	Shotgun->range = 			3;
	Shotgun->bulletSpeed = 		7;
	Shotgun->fireRate = 		3;
	Shotgun->damage = 			8;
	Shotgun->reloadTime = 		4;
	Shotgun->maxAmmo = 			3*30;
	Shotgun->blastFire = 		false;
	return Shotgun;
}

Weapon* WeaponFactory::SniperRifle(){
	Weapon *SniperRifle = new Weapon();
	SniperRifle->range = 		10;
	SniperRifle->bulletSpeed = 	8;
	SniperRifle->fireRate = 	1;
	SniperRifle->damage = 		10;
	SniperRifle->reloadTime = 	9;
	SniperRifle->maxAmmo = 		3*5;
	SniperRifle->blastFire = 	false;
	return SniperRifle;
}

Weapon* WeaponFactory::Bazooka(){
	Weapon *Bazooka = new Weapon();
	Bazooka->range = 			6;
	Bazooka->bulletSpeed =	 	2;
	Bazooka->fireRate = 		3;
	Bazooka->damage = 			10;
	Bazooka->reloadTime = 		8;
	Bazooka->maxAmmo = 			5*1;
	Bazooka->blastFire = 		true;
	return Bazooka;
}

Weapon* WeaponFactory::Grenade(){
	Weapon *Grenade = new Weapon();
	Grenade->range = 			5;
	Grenade->bulletSpeed = 		3;
	Grenade->fireRate = 		7;
	Grenade->damage = 			10;
	Grenade->reloadTime = 		5;
	Grenade->maxAmmo = 			3*1;
	Grenade->blastFire = 		true;
	return Grenade;
}

Weapon* WeaponFactory::Knife(){
	Weapon *Knife = new Weapon();
	Knife->range = 				1;
	Knife->bulletSpeed = 		10;
	Knife->fireRate = 			6;
	Knife->damage = 			4;
	Knife->reloadTime = 		10;
	Knife->maxAmmo = 			0;
	Knife->blastFire = 			true;
	return Knife;
}