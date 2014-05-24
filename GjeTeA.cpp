//============================================================================
// Name        : GjeTeA.cpp
// Author      : Piotr Piórkowski, Mateusz Nojek
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "appwindow.h"

void Akcja1(sf::Event event){
    cout << event.key.code << endl;
}


int main()
{
    Json::Value root;
    SSJ::Config::ScreenWidth = 800;
    SSJ::Config::ScreenHeight = 600;
    SSJ::Config::ScreenMargin = 64;

	SSJ::Point screenPosition;
	screenPosition.x = 0;
	screenPosition.y = 0;
	SSJ::Config::ScreenPosition = screenPosition;

    SSJ::AppWindow *Game  = new SSJ::AppWindow;
    Game->appWindow->setKeyRepeatEnabled(false);

    SSJ::GameLayer *druga = new SSJ::GameLayer("druga", true);
    SSJ::MainPlayer *obiekt = new SSJ::MainPlayer();
	obiekt->setMapPosition(100, 200);

	SSJ::GameLayer *pierwsza = new SSJ::GameLayer("pierwsza", true);
	SSJ::Map *mapa = new SSJ::Map;
	
    //obiekt->AddAction(sf::Event::MouseButtonPressed, Akcja1);
    pierwsza->addObject(mapa);
	druga->addObject(obiekt);
    Game->AddLayer(pierwsza);
	Game->AddLayer(druga);
	SSJ::Config::window = Game->appWindow;


    //Game->LoadObjects();
     while( Game->appWindow->isOpen())
     {
		 //Game->appWindow->clear(sf::Color::Black);
         //cout << "xmap: " << SSJ::Config::ScreenPosition.x << "\tymap: " << SSJ::Config::ScreenPosition.y << "\n";
         Game->Events();
         Game->Update();
         Game->Draw();
         Game->appWindow->display();
		 


     }
     return 0;
}
