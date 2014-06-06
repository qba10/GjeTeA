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
		static int  nextId;
        static void CreateMainPlayer(Json::Value object, int indeks=-1);
        static void CreatePlayer(Json::Value object, int indeks=-1);
		static void CreateBullet(Json::Value object, int indeks=-1);
    };
}
#endif // OBJECTMANAGER_H
