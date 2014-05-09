#ifndef STATICOBJECT_H
#define STATICOBJECT_H
#include "object.h"
namespace SSJ{
    class StaticObject : public Object
    {
    public:
        StaticObject();
        void draw();
        void update();

    };
}
#endif // STATICOBJECT_H
