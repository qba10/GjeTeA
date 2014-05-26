#ifndef WEAPONFACTORY_H
#define WEAPONFACTORY_H
#include "Weapon.h"
namespace SSJ {

    class WeaponFactory{
	private:
		static DynamicObject* owner;
	public:
		static void setOwner(DynamicObject* owner);
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
#endif