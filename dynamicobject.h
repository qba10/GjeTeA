#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H
#include "interactiveobject.h"
namespace SSJ {


    class DynamicObject : public InteractiveObject
    {
    private:
	protected:
		size_t velocity; // px per second
		Degrees angle;
		Degrees targetAngle;
    public:
        void MoveForward();
        void MoveBackward();
        void MoveLeft();
        void MoveRight();
        void RotateLeft();
        void RotateRight();
        Point CalcNewPosition( SSJ::Degrees);
		Degrees getAngle();
        DynamicObject();

    };
}
#endif // DYNAMICOBJECT_H
