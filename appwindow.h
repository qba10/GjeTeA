#ifndef APPWINDOW_H
#define APPWINDOW_H
#include "Loader.h"
#include "object.h"
#include "gamelayer.h"
#include "staticobject.h"
#include "mainplayer.h"
#include "map.h"
#include "serverconnectapi.h"
namespace SSJ {

    class AppWindow
    {
    private:
       vector <GameLayer*> GameLayers;
        sf::Thread *thread;
    public:
       void AddLayer(GameLayer*);

    public:
        AppWindow();
        void LoadObjects();
        void Events();
        void Update();
        void Draw();
        sf::Time Delta;


        sf::RenderWindow *appWindow;
        sf::Event event;
        sf::Clock Clock;
    };
}
#endif // APPWINDOW_H
