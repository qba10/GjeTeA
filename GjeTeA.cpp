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

	SSJ::Map *mapa = new SSJ::Map("mapa.txt");
    SSJ::GameLayer *pierwsza = mapa;
    SSJ::GameLayer *druga = new SSJ::GameLayer("druga", true);
	SSJ::GameLayer *trzecia = new SSJ::GameLayer("trzecia", true);
    SSJ::LayerContainer::AddGameLayer(pierwsza);
    SSJ::LayerContainer::AddGameLayer(druga);
    SSJ::LayerContainer::AddGameLayer(trzecia);

    SSJ::MainPlayer *obiekt = new SSJ::MainPlayer();
	obiekt->setMapPosition(0, 0);


	


	/*sf::Texture cursor;
	cursor.loadFromFile("aim.png");
	sf::Sprite sprite(cursor);
	sprite.setPosition(sf::Mouse::getPosition(Game).x, sf::Mouse::getPosition(Game).y);*/
	
    //obiekt->AddAction(sf::Event::MouseButtonPressed, Akcja1);
    
	druga->addObject(obiekt);
    Game->AddLayer(pierwsza);
	Game->AddLayer(druga);
    //Game->AddLayer(trzecia);
    SSJ::DataContainer::window = Game->appWindow;
    //Game->LoadObjects();
    sf::Clock clk;
    float fps = 0;

     while( Game->appWindow->isOpen())
     {
		 //Game->appWindow->clear(sf::Color::Black);
         //cout << "xmap: " << SSJ::Config::ScreenPosition.x << "\tymap: " << SSJ::Config::ScreenPosition.y << "\n";
         Game->Events();
         Game->Update();
         Game->Draw();
		 /*
		 sf::Texture tekstura;
		 tekstura.loadFromFile("gta2tiles.jpg");
		 sf::Sprite sprite;
		 sprite.setTexture(tekstura);
		 sf::IntRect rect(0,0, 64,64);
		 sprite.setTextureRect(rect);
		 SSJ::DataContainer::window->draw(sprite);*/

         Game->appWindow->display();
		 


         fps = 1/ clk.getElapsedTime().asSeconds();
         clk.restart();


         //cout << "FPS: " << fps << endl;

     }
     return 0;
}
