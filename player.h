#ifndef PLAYER_H
#define PLAYER_H
#include "dynamicobject.h"
namespace SSJ{
    class Player : public DynamicObject
    {
    protected:
        bool isFiring;
    public:
        Player();
        void draw();
        void update();
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
#endif // PLAYER_H
