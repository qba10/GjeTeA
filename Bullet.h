#ifndef BULLET_H
#define BULLET_H
#include "dynamicobject.h"

namespace SSJ{
    class Bullet : public DynamicObject{
	protected:
		Point ownerPosition;
		string name;
        WeaponType type;
		Sprite blastSprite;
		int range;
		int damage;
		bool blastFire;
		int blastRange;
        bool wasFirst;

    public:
		Bullet();
		~Bullet();
		void draw();
		void update();

		void Blast();
		void Hit();
		Point CalcNewPosition();

		void setOwnerPosition(const Point);
		void setRange(const int);
		void setName(const string);
		void setDamage(const int);
		void setBlastFire(const bool);
		void setBlastRange(const int);
		WeaponType getType() const;
        void setType(const WeaponType &value);

		void SynchronizationObject(Json::Value);
    };
}
#endif
