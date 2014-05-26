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
    SSJ::DataContainer::ScreenWidth = 800;
    SSJ::DataContainer::ScreenHeight = 600;
    SSJ::DataContainer::ScreenMargin = 64;

    SSJ::Point screenPosition;
	screenPosition.x = 0;
	screenPosition.y = 0;
    SSJ::DataContainer::ScreenPosition = screenPosition;

    SSJ::AppWindow *Game  = new SSJ::AppWindow;
    Game->appWindow->setKeyRepeatEnabled(false);
	SSJ::GameLayer *trzecia = new SSJ::GameLayer("trzecia", true);
	SSJ::LayerContainer::warstwa3 = trzecia;
    SSJ::GameLayer *druga = new SSJ::GameLayer("druga", true);
    SSJ::MainPlayer *obiekt = new SSJ::MainPlayer();
	obiekt->setMapPosition(100, 200);

	SSJ::GameLayer *pierwsza = new SSJ::GameLayer("pierwsza", true);
	SSJ::Map *mapa = new SSJ::Map;


	/*sf::Texture cursor;
	cursor.loadFromFile("aim.png");
	sf::Sprite sprite(cursor);
	sprite.setPosition(sf::Mouse::getPosition(Game).x, sf::Mouse::getPosition(Game).y);*/
	
    //obiekt->AddAction(sf::Event::MouseButtonPressed, Akcja1);
    pierwsza->addObject(mapa);
	druga->addObject(obiekt);
    Game->AddLayer(pierwsza);
	Game->AddLayer(druga);
	Game->AddLayer(trzecia);
    SSJ::DataContainer::window = Game->appWindow;


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
