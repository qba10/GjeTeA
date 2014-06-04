//============================================================================
// Name        : GjeTeA.cpp
// Author      : Piotr Piórkowski, Mateusz Nojek
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "appwindow.h"




int main()
{
    SSJ::DataContainer::mutex.lock();
    SSJ::DataContainer::ScreenWidth = 800;
    SSJ::DataContainer::ScreenHeight = 600;
    SSJ::DataContainer::ScreenMargin = 64;
    time_t  timev;
    time(&timev);
    ostringstream oss;
    oss << (int)timev;
    SSJ::Config::PlayerId = oss.str();

    SSJ::Point screenPosition;
	screenPosition.x = 0;
	screenPosition.y = 0;
    SSJ::DataContainer::ScreenPosition = screenPosition;

    SSJ::AppWindow *Game  = new SSJ::AppWindow;

    SSJ::GameLayer *pierwsza = new SSJ::GameLayer("pierwsza", true);
    SSJ::GameLayer *druga = new SSJ::GameLayer("druga", true);
	SSJ::GameLayer *trzecia = new SSJ::GameLayer("trzecia", true);
    SSJ::LayerContainer::AddGameLayer(pierwsza);
    SSJ::LayerContainer::AddGameLayer(druga);
    SSJ::LayerContainer::AddGameLayer(trzecia);

  //  SSJ::MainPlayer *obiekt = new SSJ::MainPlayer();
//	obiekt->setMapPosition(100, 200);


	SSJ::Map *mapa = new SSJ::Map;


	/*sf::Texture cursor;
	cursor.loadFromFile("aim.png");
	sf::Sprite sprite(cursor);
	sprite.setPosition(sf::Mouse::getPosition(Game).x, sf::Mouse::getPosition(Game).y);*/
	
    //obiekt->AddAction(sf::Event::MouseButtonPressed, Akcja1);
    //druga->addObject(obiekt);
    pierwsza->addObject(mapa);

    Game->AddLayer(pierwsza);
	Game->AddLayer(druga);
    //Game->AddLayer(trzecia);
    SSJ::DataContainer::window = Game->appWindow;
    //Game->LoadObjects();
    sf::Clock clk;
    float fps = 0;
    Game->LoadObjects();
    SSJ::DataContainer::mutex.unlock();

     while( Game->appWindow->isOpen())
     {
		 //Game->appWindow->clear(sf::Color::Black);
         //cout << "xmap: " << SSJ::Config::ScreenPosition.x << "\tymap: " << SSJ::Config::ScreenPosition.y << "\n";
         SSJ::DataContainer::mutex.lock();
         Game->Events();
         Game->Update();
         Game->Draw();
         Game->appWindow->display();
         SSJ::DataContainer::mutex.unlock();
		 
sf::sleep(sf::milliseconds(10));

         fps = 1/ clk.getElapsedTime().asSeconds();
         clk.restart();


         //cout << "FPS: " << fps << endl;

     }
     return 0;
}
