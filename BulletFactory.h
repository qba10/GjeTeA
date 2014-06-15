#ifndef BULLETFACTORY_H
#define BULLETFACTORY_H
#include "Bullet.h"
namespace SSJ {
    class BulletFactory{
	private:
		static Point ownerPosition;
		static SSJ::Degrees ownerAngle;
	public:
		static void setOwnerPosition(const Point ownerPosition);
		static void setOwnerAngle(const SSJ::Degrees ownerAngle);
        static Bullet* CreateGlockBullet();
        static Bullet* CreateUziBullet();
        static Bullet* CreateAk47Bullet();
        static Bullet* CreateM16Bullet();
        static Bullet* CreateShotgunBullet();
        static Bullet* CreateSniperRifleBullet();
        static Bullet* CreateBazookaBullet();
        static Bullet* CreateGrenadeBullet();
        static Bullet* CreateKnifeBullet();
    };
}
#endif