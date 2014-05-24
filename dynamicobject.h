#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H
#include "interactiveobject.h"
namespace SSJ {


    class DynamicObject : public InteractiveObject
    {
    protected:
        /*for synchronization by server*/
        SSJ::Degrees angle;
        SSJ::Degrees targetAngle;
	protected:
        /*for synchronization by server*/
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
        /**
         * JSON:
         * {
         *      mapPositionX: "",
         *      mapPositionY: "",
         *      activity: "",
         *      hp: "",
         *      maxHP: "",
         *      angle: "",
         *      targetAngle: "",
         *      velocity: ""
         *
         * }
         */
        void SynchronizationObject(Json::Value);

    };
}
#endif // DYNAMICOBJECT_H
