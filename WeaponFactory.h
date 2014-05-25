#include "Weapon.h"
namespace SSJ {

    class WeaponFactory{
        static Weapon* CreateGlockObject();
        static Weapon* CreateUziObject();
        static Weapon* CreateAk47Object();
        static Weapon* CreateM16Object();
        static Weapon* CreateShotgunObject();
        static Weapon* CreateSniperRifleObject();
        static Weapon* CreateBazookaObject();
        static Weapon* CreateGrenadeObject();
        static Weapon* CreateKnifeObject();
    };
 }
