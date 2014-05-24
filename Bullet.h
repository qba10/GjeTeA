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

	};
}
#endif