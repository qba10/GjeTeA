#ifndef INTERACTIVEOBJECT_H
#define INTERACTIVEOBJECT_H
#include "gamelayer.h"
namespace SSJ{
    class InteractiveObject : public Object
    {
    public:
        InteractiveObject();
    protected:
        /*for synchronization by server*/
        int hp;
        int maxHP;
    public:
        void setHP(const int hp);
        void setMaxHP(const int hp);
        void addHP(int hp);
        void subHP(int hp);
        int getHP() const;
        int getMaxHP() const;
        bool isDead() const;
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
