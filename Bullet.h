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
		string name;
		int range;
		int damage;
		bool blastFire;
		int blastRange;
		void SynchronizationObject(Json::Value);
	};
}
#endif
