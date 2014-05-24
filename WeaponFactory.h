#include "Weapon.h"
namespace SSJ {

    class WeaponFactory{
        Weapon* CreateGlockObject();
        Weapon* CreateUziObject();
        Weapon* CreateAk47Object();
        Weapon* CreateM16Object();
        Weapon* CreateShotgunObject();
        Weapon* CreateSniperRifleObject();
        Weapon* CreateBazookaObject();
        Weapon* CreateGrenadeObject();
        Weapon* CreateKnifeObject();
    };
 }
