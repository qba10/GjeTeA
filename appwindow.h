#ifndef APPWINDOW_H
#define APPWINDOW_H
#include "objectmanager.h"
#include "serverapi.h"
#include "hud.h"
namespace SSJ {
    class AppWindow
    {
    private:
       vector <GameLayer*> GameLayers;
        sf::Thread *ServerConnectThread;
		Hud* hud;
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
