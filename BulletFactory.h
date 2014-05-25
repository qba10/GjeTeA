#include "Bullet.h"
namespace SSJ {

    class BulletFactory{
	public:
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