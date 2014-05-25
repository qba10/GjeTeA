#include "BulletFactory.h"
namespace SSJ{
	Bullet* BulletFactory::CreateGlockBullet(){
		Bullet* GlockBullet = new Bullet();
		GlockBullet->name =				"Glock";
		GlockBullet->range =			400;
		GlockBullet->bulletSpeed =		5;
		GlockBullet->damage =			25;
		GlockBullet->blastFire =		false;
		GlockBullet->blastRange =		NULL; 
		return GlockBullet;
	}
	Bullet* BulletFactory::CreateUziBullet(){
		Bullet* UziBullet = new Bullet();
		UziBullet->name =				"Uzi";
		UziBullet->range =				500;
		UziBullet->bulletSpeed =		6;
		UziBullet->damage =				10;
		UziBullet->blastFire =			false;
		UziBullet->blastRange =			NULL;
		return UziBullet;
	}
	Bullet* BulletFactory::CreateAk47Bullet(){
		Bullet* Ak47Bullet = new Bullet();
		Ak47Bullet->name =				"Ak-47";
		Ak47Bullet->range =				800;
		Ak47Bullet->bulletSpeed =		9;
		Ak47Bullet->damage =			15;
		Ak47Bullet->blastFire =			false;
		Ak47Bullet->blastRange =		NULL;
		return Ak47Bullet;
	}
	Bullet* BulletFactory::CreateM16Bullet(){
		Bullet* M16Bullet = new Bullet();
		M16Bullet->name =				"M-16";
		M16Bullet->range =				800;
		M16Bullet->bulletSpeed =		9;
		M16Bullet->damage =				12;
		M16Bullet->blastFire =			false;
		M16Bullet->blastRange =			NULL;
		return M16Bullet;
	}
	Bullet* BulletFactory::CreateShotgunBullet(){
		Bullet* ShotgunBullet = new Bullet();
		ShotgunBullet->name =			"Shotgun";
		ShotgunBullet->range =			300;
		ShotgunBullet->bulletSpeed =	7;
		ShotgunBullet->damage =			50;
		ShotgunBullet->blastFire =		true;
		ShotgunBullet->blastRange =		20;
		return ShotgunBullet;
	}
	Bullet* BulletFactory::CreateSniperRifleBullet(){
		Bullet* SniperRifleBullet = new Bullet();
		SniperRifleBullet->name =		"Sniper rifle";
		SniperRifleBullet->range =		1000;
		SniperRifleBullet->bulletSpeed = 8;
		SniperRifleBullet->damage =		100;
		SniperRifleBullet->blastFire =	false;
		SniperRifleBullet->blastRange =	NULL;
		return SniperRifleBullet;
	}
	Bullet* BulletFactory::CreateBazookaBullet(){
		Bullet* BazookaBullet = new Bullet();
		BazookaBullet->name =			"Bazooka";
		BazookaBullet->range =			600;
		BazookaBullet->bulletSpeed =	2;
		BazookaBullet->damage =			100;
		BazookaBullet->blastFire =		true;
		BazookaBullet->blastRange =		100;
		return BazookaBullet;
	}
	Bullet* BulletFactory::CreateGrenadeBullet(){
		Bullet* GrenadeBullet = new Bullet();
		GrenadeBullet->name =			"Grenade";
		GrenadeBullet->range =			500;
		GrenadeBullet->bulletSpeed =	3;
		GrenadeBullet->damage =			100;
		GrenadeBullet->blastFire =		true;
		GrenadeBullet->blastRange =		70;
		return GrenadeBullet;
	}
	Bullet* BulletFactory::CreateKnifeBullet(){
		Bullet* KnifeBullet = new Bullet();
		KnifeBullet->name =				"Knife";
		KnifeBullet->range =			50;
		KnifeBullet->bulletSpeed =		NULL;
		KnifeBullet->damage =			35;
		KnifeBullet->blastFire =		false;
		KnifeBullet->blastRange =		NULL;
		return KnifeBullet;
	}

}