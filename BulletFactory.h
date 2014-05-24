#include "Bullet.h"
namespace SSJ {

    class BulletFactory{
        Bullet* CreateGlockBullet();
        Bullet* CreateUziBullet();
        Bullet* CreateAk47Bullet();
        Bullet* CreateM16Bullet();
        Bullet* CreateShotgunBullet();
        Bullet* CreateSniperRifleBullet();
        Bullet* CreateBazookaBullet();
        Bullet* CreateGrenadeBullet();
        Bullet* CreateKnifeBullet();
    };
 }
