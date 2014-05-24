#ifndef INTERACTIVEOBJECT_H
#define INTERACTIVEOBJECT_H
#include "object.h"
namespace SSJ{
    class InteractiveObject : public Object
    {
    public:
        InteractiveObject();
    protected:
        /*for synchronization by server*/
        size_t hp;
        size_t maxHP;
    public:
        void setHP(size_t hp);
        void setMaxHP(size_t hp);
        void addHP(size_t hp);
        void subHP(size_t hp);
        size_t getHP();
        size_t getMaxHP();
        bool isDead();
        /**
         * JSON:
         * {
         *      mapPositionX: "",
         *      mapPositionY: "",
         *      activity: "",
         *      hp: "",
         *      maxHP: ""
         * }
         */
        void SynchronizationObject(Json::Value);
    };
}

#endif // INTERACTIVEOBJECT_H
