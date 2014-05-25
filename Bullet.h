#ifndef BULLET_H
#define BULLET_H
#include "dynamicobject.h"
#include "Weapon.h"
namespace SSJ{
    class Bullet : public DynamicObject{
    public:

		Bullet();
		~Bullet();
		void draw();
		void update();

		Weapon weapon;
		Sprite sprite;
		string name;
		SSJ::Degrees angle;
		int range;
		int bulletSpeed;
		int damage;
		bool blastFire;
		int blastRange;
	};
}
#endif