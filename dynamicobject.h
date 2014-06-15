#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H
#include "interactiveobject.h"
namespace SSJ {


    class DynamicObject : public InteractiveObject
    {
	protected:
        /*for synchronization by server*/
		int velocity; // px per second
		Degrees angle;
		Degrees targetAngle;
    public:
		DynamicObject();
        void MoveForward();
        void MoveBackward();
        void MoveLeft();
        void MoveRight();
        void RotateLeft();
        void RotateRight();
        Point CalcNewPosition( SSJ::Degrees);
		
		void setVelocity(const int velocity);
		int getVelocity() const;
		void setAngle(const Degrees angle);
		Degrees getAngle() const;
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
