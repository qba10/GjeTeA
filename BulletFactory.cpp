#include "BulletFactory.h"
namespace SSJ{
	Bullet* BulletFactory::CreateGlockBullet(){
		Bullet* GlockBullet = new Bullet();
		GlockBullet->name = "Glock";
		GlockBullet->range = GlockBullet->weapon.range;
		GlockBullet->bulletSpeed = GlockBullet->weapon.bulletSpeed;
		GlockBullet->damage = GlockBullet->weapon.damage;
		GlockBullet->blastFire = GlockBullet->weapon.blastFire;
		GlockBullet->blastRange = NULL; 
		return GlockBullet;
	}
	Bullet* BulletFactory::CreateUziBullet(){
		Bullet* UziBullet = new Bullet();
		UziBullet->name = "Uzi";
		return UziBullet;
	}
	Bullet* BulletFactory::CreateAk47Bullet(){
		Bullet* Ak47Bullet = new Bullet();
		Ak47Bullet->name = "Ak-47";
		return Ak47Bullet;
	}
	Bullet* BulletFactory::CreateM16Bullet(){
		Bullet* M16Bullet = new Bullet();
		M16Bullet->name = "M-16";
		return M16Bullet;
	}
	Bullet* BulletFactory::CreateShotgunBullet(){
		Bullet* ShotgunBullet = new Bullet();
		ShotgunBullet->name = "Shotgun";
		return ShotgunBullet;
	}
	Bullet* BulletFactory::CreateSniperRifleBullet(){
		Bullet* SniperRifleBullet = new Bullet();
		SniperRifleBullet->name = "Sniper rifle";
		return SniperRifleBullet;
	}
	Bullet* BulletFactory::CreateBazookaBullet(){
		Bullet* BazookaBullet = new Bullet();
		BazookaBullet->name = "Bazooka";
		return BazookaBullet;
	}
	Bullet* BulletFactory::CreateGrenadeBullet(){
		Bullet* GrenadeBullet = new Bullet();
		GrenadeBullet->name = "Grenade";
		return GrenadeBullet;
	}
	Bullet* BulletFactory::CreateKnifeBullet(){
		Bullet* KnifeBullet = new Bullet();
		KnifeBullet->name = "Knife";
		return KnifeBullet;
	}

}