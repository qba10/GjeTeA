#ifndef STATICOBJECT_H
#define STATICOBJECT_H
#include "gamelayer.h"
namespace SSJ{
    class StaticObject : public Object
    {
    public:
        StaticObject();
        void draw();
        void update();
        void SynchronizationObject(Json::Value);
    };
}
#endif // STATICOBJECT_H
