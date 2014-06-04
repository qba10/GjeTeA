#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include "Loader.h"
#include "object.h"
#include "gamelayer.h"
#include "staticobject.h"
#include "mainplayer.h"
#include "map.h"
#include "serverconnectapi.h"
namespace SSJ {

    class ObjectManager
    {
    public:
        static void CreateMainPlayer(Json::Value object);
        static void CreatePlayer(Json::Value object);
    };
}
#endif // OBJECTMANAGER_H
