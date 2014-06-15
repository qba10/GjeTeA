#include "BulletFactory.h"
namespace SSJ{
	Point BulletFactory::ownerPosition;

	void BulletFactory::setOwnerPosition(const Point ownerPosition){
		BulletFactory::ownerPosition = ownerPosition;
	}

	SSJ::Degrees BulletFactory::ownerAngle;

	void BulletFactory::setOwnerAngle(const SSJ::Degrees ownerAngle){
		BulletFactory::ownerAngle = ownerAngle;
	}

	Bullet* BulletFactory::CreateGlockBullet(){
		Bullet* GlockBullet = new Bullet();
		GlockBullet->setName(			"Glock");
        GlockBullet->setType(           Glock);
		GlockBullet->setRange(			200);
		GlockBullet->setVelocity(		10);
		GlockBullet->setDamage(			25);
		GlockBullet->setBlastFire(		false);
		GlockBullet->setBlastRange(		0);
		GlockBullet->setOwnerPosition(	BulletFactory::ownerPosition);
		GlockBullet->setMapPosition(	BulletFactory::ownerPosition);
		GlockBullet->setAngle(			BulletFactory::ownerAngle);
		return GlockBullet;
	}
	Bullet* BulletFactory::CreateUziBullet(){
		Bullet* UziBullet = new Bullet();
		UziBullet->setName(				"Uzi");
        UziBullet->setType(             Uzi);
		UziBullet->setRange(			250);
		UziBullet->setVelocity(			12);
		UziBullet->setDamage(			10);
		UziBullet->setBlastFire(		false);
        UziBullet->setBlastRange(		0);
		UziBullet->setOwnerPosition(	BulletFactory::ownerPosition);
		UziBullet->setMapPosition(		BulletFactory::ownerPosition);
		UziBullet->setAngle(			BulletFactory::ownerAngle);
		return UziBullet;
	}
	Bullet* BulletFactory::CreateAk47Bullet(){
		Bullet* Ak47Bullet = new Bullet();
		Ak47Bullet->setName(			"Ak-47");
        Ak47Bullet->setType(            Ak47);
		Ak47Bullet->setRange(			400);
		Ak47Bullet->setVelocity(		18);
		Ak47Bullet->setDamage(			15);
		Ak47Bullet->setBlastFire(		false);
        Ak47Bullet->setBlastRange(		0);
		//Ak47Bullet->setOwnerPosition(	BulletFactory::ownerPosition);
		Ak47Bullet->setMapPosition(		BulletFactory::ownerPosition);
		Ak47Bullet->setAngle(			BulletFactory::ownerAngle);
		return Ak47Bullet;
	}
	Bullet* BulletFactory::CreateM16Bullet(){
		Bullet* M16Bullet = new Bullet();
		M16Bullet->setName(				"M-16");
        M16Bullet->setType(             M16);
		M16Bullet->setRange(			400);
		M16Bullet->setVelocity(			18);
		M16Bullet->setDamage(			12);
		M16Bullet->setBlastFire(		false);
        M16Bullet->setBlastRange(		0);
		//M16Bullet->setOwnerPosition(	BulletFactory::ownerPosition);
		M16Bullet->setMapPosition(		BulletFactory::ownerPosition);
		M16Bullet->setAngle(			BulletFactory::ownerAngle);
		return M16Bullet;
	}
	Bullet* BulletFactory::CreateShotgunBullet(){
		Bullet* ShotgunBullet = new Bullet();
		ShotgunBullet->setName(			"Shotgun");
        ShotgunBullet->setType(         Shotgun);
		ShotgunBullet->setRange(		150);
		ShotgunBullet->setVelocity(		14);
		ShotgunBullet->setDamage(		50);
		ShotgunBullet->setBlastFire(	true);
		ShotgunBullet->setBlastRange(	20);
		//ShotgunBullet->setOwnerPosition(BulletFactory::ownerPosition);
		ShotgunBullet->setMapPosition(	BulletFactory::ownerPosition);
		ShotgunBullet->setAngle(		BulletFactory::ownerAngle);
		return ShotgunBullet;
	}
	Bullet* BulletFactory::CreateSniperRifleBullet(){
		Bullet* SniperRifleBullet = new Bullet();
		SniperRifleBullet->setName(			"Sniper rifle");
        SniperRifleBullet->setType(			SniperRifle);
		SniperRifleBullet->setRange(		500);
		SniperRifleBullet->setVelocity(		16);
		SniperRifleBullet->setDamage(		100);
		SniperRifleBullet->setBlastFire(	false);
        SniperRifleBullet->setBlastRange(	0);
		//SniperRifleBullet->setOwnerPosition(BulletFactory::ownerPosition);
		SniperRifleBullet->setMapPosition(	BulletFactory::ownerPosition);
		SniperRifleBullet->setAngle(		BulletFactory::ownerAngle);
		return SniperRifleBullet;
	}
	Bullet* BulletFactory::CreateBazookaBullet(){
		Bullet* BazookaBullet = new Bullet();
		BazookaBullet->setName(			"Bazooka");
        BazookaBullet->setType(         Bazooka);
		BazookaBullet->setRange(		300);
		BazookaBullet->setVelocity(		4);
		BazookaBullet->setDamage(		100);
		BazookaBullet->setBlastFire(	true);
		BazookaBullet->setBlastRange(	100);
		//BazookaBullet->setOwnerPosition(BulletFactory::ownerPosition);
		BazookaBullet->setMapPosition(	BulletFactory::ownerPosition);
		BazookaBullet->setAngle(		BulletFactory::ownerAngle);
		return BazookaBullet;
	}
	Bullet* BulletFactory::CreateGrenadeBullet(){
		Bullet* GrenadeBullet = new Bullet();
		GrenadeBullet->setName(			"Grenade");
        GrenadeBullet->setType(         Grenade);
		GrenadeBullet->setRange(		250);
		GrenadeBullet->setVelocity(		6);
		GrenadeBullet->setDamage(		100);
		GrenadeBullet->setBlastFire(	true);
		GrenadeBullet->setBlastRange(		70);
		//GrenadeBullet->setOwnerPosition(BulletFactory::ownerPosition);
		GrenadeBullet->setMapPosition(	BulletFactory::ownerPosition);
		GrenadeBullet->setAngle(		BulletFactory::ownerAngle);
		return GrenadeBullet;
	}
	Bullet* BulletFactory::CreateKnifeBullet(){
		Bullet* KnifeBullet = new Bullet();
		KnifeBullet->setName(			"Knife");
        KnifeBullet->setType(           Knife);
		KnifeBullet->setRange(			25);
        KnifeBullet->setVelocity(		0);
		KnifeBullet->setDamage(			35);
		KnifeBullet->setBlastFire(		false);
        KnifeBullet->setBlastRange(		0);
		//KnifeBullet->setOwnerPosition(	BulletFactory::ownerPosition);
		KnifeBullet->setMapPosition(	BulletFactory::ownerPosition);
		KnifeBullet->setAngle(			BulletFactory::ownerAngle);
		return KnifeBullet;
	}
}
