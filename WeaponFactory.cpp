#include "WeaponFactory.h"
namespace SSJ {
	DynamicObject* WeaponFactory::owner = NULL;

	void WeaponFactory::setOwner(DynamicObject* owner){
		WeaponFactory::owner = owner;
	}


    Weapon* WeaponFactory::CreateGlockObject(){
        Weapon *GlockObject = new Weapon();
		GlockObject->setType(		Glock);
		GlockObject->setName(		"Glock");
        GlockObject->setRange( 		200);
		GlockObject->setFireRate( 	0.01);
		GlockObject->setDamage( 	5);
		GlockObject->setReloadTime( 2);
        GlockObject->setMaxAmmo( 	85);
		GlockObject->setAmmoInMag(	17);
		GlockObject->setAmmo(		17);
		GlockObject->setAllAmmo(	3*17);
        GlockObject->setBlastFire( 	false);
		GlockObject->setRepeatFire(	false);
		GlockObject->setOwner(		WeaponFactory::owner);
        return GlockObject;
    }

    Weapon* WeaponFactory::CreateUziObject(){
        Weapon *UziObject = new Weapon();
		UziObject->setType(			Uzi);
		UziObject->setName(			"Uzi");
        UziObject->setRange( 		250);
        UziObject->setFireRate( 	0.1);
        UziObject->setDamage( 		4);
        UziObject->setReloadTime( 	2);
		UziObject->setMaxAmmo( 		200);
		UziObject->setAmmoInMag(	40);
		UziObject->setAmmo(			40);
		UziObject->setAllAmmo(		3*40);
        UziObject->setBlastFire( 	false);
		UziObject->setRepeatFire(	true);
		UziObject->setOwner(		WeaponFactory::owner);
        return UziObject;
    }

    Weapon* WeaponFactory::CreateAk47Object(){
        Weapon *Ak47Object = new Weapon();
		Ak47Object->setType(		Ak47);
		Ak47Object->setName(		"Ak-47");
        Ak47Object->setRange( 		400);
        Ak47Object->setFireRate( 	0.2);
        Ak47Object->setDamage( 		7);
        Ak47Object->setReloadTime( 	3);
        Ak47Object->setMaxAmmo( 	150);
		Ak47Object->setAmmoInMag(	30);
		Ak47Object->setAmmo(		30);
		Ak47Object->setAllAmmo(		3*30);
        Ak47Object->setBlastFire( 	false);
		Ak47Object->setRepeatFire(	true);
		Ak47Object->setOwner(		WeaponFactory::owner);
        return Ak47Object;
    }

    Weapon* WeaponFactory::CreateM16Object(){
        Weapon *M16Object = new Weapon();
		M16Object->setType(			M16);
		M16Object->setName(			"M-16");
        M16Object->setRange( 		450);
        M16Object->setFireRate( 	0.08);
        M16Object->setDamage( 		6);
        M16Object->setReloadTime( 	3);
        M16Object->setMaxAmmo( 		150);
		M16Object->setAmmoInMag(	30);
		M16Object->setAmmo(			30);
		M16Object->setAllAmmo(		3*30);
        M16Object->setBlastFire( 	false);
		M16Object->setRepeatFire(	true);
		M16Object->setOwner(		WeaponFactory::owner);
        return M16Object;
    }

    Weapon* WeaponFactory::CreateShotgunObject(){
        Weapon *ShotgunObject = new Weapon();
		ShotgunObject->setType(			Shotgun);
		ShotgunObject->setName(			"Shotgun");
        ShotgunObject->setRange( 		150);
        ShotgunObject->setFireRate( 	0.5);
        ShotgunObject->setDamage( 		8);
        ShotgunObject->setReloadTime( 	4);
        ShotgunObject->setMaxAmmo( 		150);
		ShotgunObject->setAmmoInMag(	30);
		ShotgunObject->setAmmo(			30);
		ShotgunObject->setAllAmmo(		3*30);
        ShotgunObject->setBlastFire( 	false);
		ShotgunObject->setRepeatFire(	false);
		ShotgunObject->setOwner(		WeaponFactory::owner);
        return ShotgunObject;
    }

    Weapon* WeaponFactory::CreateSniperRifleObject(){
        Weapon *SniperRifleObject = new Weapon();
		SniperRifleObject->setType(			SniperRifle);
		SniperRifleObject->setName(			"Sniper rifle");
        SniperRifleObject->setRange( 		500);
		SniperRifleObject->setFireRate( 	4);
        SniperRifleObject->setDamage( 		10);
        SniperRifleObject->setReloadTime( 	5);
        SniperRifleObject->setMaxAmmo( 		25);
		SniperRifleObject->setAmmoInMag(	5);
		SniperRifleObject->setAmmo(			5);
		SniperRifleObject->setAllAmmo(		3*5);
        SniperRifleObject->setBlastFire(	false);
		SniperRifleObject->setRepeatFire(	false);
		SniperRifleObject->setOwner(		WeaponFactory::owner);
        return SniperRifleObject;
    }

    Weapon* WeaponFactory::CreateBazookaObject(){
        Weapon *BazookaObject = new Weapon();
		BazookaObject->setType(			Bazooka);
		BazookaObject->setName(			"Bazooka");
        BazookaObject->setRange( 		300);
        BazookaObject->setFireRate( 	5);
        BazookaObject->setDamage( 		10);
        BazookaObject->setReloadTime( 	5);
        BazookaObject->setMaxAmmo( 		8);
		BazookaObject->setAmmoInMag(	1);
		BazookaObject->setAmmo(			1);
		BazookaObject->setAllAmmo(		5*1);
        BazookaObject->setBlastFire( 	true);
		BazookaObject->setRepeatFire(	false);
		BazookaObject->setOwner(		WeaponFactory::owner);
        return BazookaObject;
    }

    Weapon* WeaponFactory::CreateGrenadeObject(){
        Weapon *GrenadeObject = new Weapon();
		GrenadeObject->setType(			Grenade);
		GrenadeObject->setName(			"Grenade");
        GrenadeObject->setRange( 		250);
        GrenadeObject->setFireRate( 	1);
        GrenadeObject->setDamage( 		10);
        GrenadeObject->setReloadTime( 	1);
        GrenadeObject->setMaxAmmo( 		5);
		GrenadeObject->setAmmoInMag(	1);
		GrenadeObject->setAmmo(			1);
		GrenadeObject->setAllAmmo(		3*1);
        GrenadeObject->setBlastFire( 	true);
		GrenadeObject->setRepeatFire(	false);
		GrenadeObject->setOwner(		WeaponFactory::owner);
        return GrenadeObject;
    }

    Weapon* WeaponFactory::CreateKnifeObject(){
        Weapon *KnifeObject = new Weapon();
		KnifeObject->setType(			Knife);
		KnifeObject->setName(			"Knife");
        KnifeObject->setRange( 			25);
        KnifeObject->setFireRate( 		0.3);
        KnifeObject->setDamage(			4);
        KnifeObject->setReloadTime( 	0);
        KnifeObject->setMaxAmmo( 		0);
		KnifeObject->setAmmoInMag(		0);
		KnifeObject->setAmmo(			0);
		KnifeObject->setAllAmmo(		0);
        KnifeObject->setBlastFire( 		true);
		KnifeObject->setRepeatFire(		true);
		KnifeObject->setOwner(			WeaponFactory::owner);
        return KnifeObject;
    }
}
