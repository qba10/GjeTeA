#ifndef INTERACTIVEOBJECT_H
#define INTERACTIVEOBJECT_H
#include "object.h"
namespace SSJ{
    class InteractiveObject : public Object
    {
    public:
        InteractiveObject();
    private:
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
    };
}

#endif // INTERACTIVEOBJECT_H
