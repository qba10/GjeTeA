#ifndef BULLET_H
#define BULLET_H
#include "dynamicobject.h"

namespace SSJ{
    class Bullet : public DynamicObject{
    public:
		
		Bullet();
		~Bullet();
		void draw();
		void update();
		void Blast();
		void Hit();
		Point CalcNewPosition();

		Point ownerPosition;
		Point bulletPosition;
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
