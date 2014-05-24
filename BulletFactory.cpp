#include "BulletFactory.h"
namespace SSJ{
	Bullet* BulletFactory::CreateGlockBullet(){
		Bullet* GlockBullet = new Bullet();

		return GlockBullet;
	}
	Bullet* BulletFactory::CreateUziBullet(){
		Bullet* UziBullet = new Bullet();

		return UziBullet;
	}
	Bullet* BulletFactory::CreateAk47Bullet(){
		Bullet* Ak47Bullet = new Bullet();

		return Ak47Bullet;
	}
	Bullet* BulletFactory::CreateM16Bullet(){
		Bullet* M16Bullet = new Bullet();

		return M16Bullet;
	}
	Bullet* BulletFactory::CreateShotgunBullet(){
		Bullet* ShotgunBullet = new Bullet();

		return ShotgunBullet;
	}
	Bullet* BulletFactory::CreateSniperRifleBullet(){
		Bullet* SniperRifleBullet = new Bullet();

		return SniperRifleBullet;
	}
	Bullet* BulletFactory::CreateBazookaBullet(){
		Bullet* BazookaBullet = new Bullet();

		return BazookaBullet;
	}
	Bullet* BulletFactory::CreateGrenadeBullet(){
		Bullet* GrenadeBullet = new Bullet();

		return GrenadeBullet;
	}
	Bullet* BulletFactory::CreateKnifeBullet(){
		Bullet* KnifeBullet = new Bullet();

		return KnifeBullet;
	}

}