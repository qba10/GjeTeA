#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H
#include "interactiveobject.h"
namespace SSJ {


    class DynamicObject : public InteractiveObject
    {
    private:
        SSJ::Degrees angle;
        SSJ::Degrees targetAngle;
	protected:
		size_t velocity; // px per second
    public:
        void MoveForward();
        void MoveBackward();
        void MoveLeft();
        void MoveRight();
        void RotateLeft();
        void RotateRight();
        Point CalcNewPosition( SSJ::Degrees);
        DynamicObject();

    };
}
#endif // DYNAMICOBJECT_H
