#include "map.h"

namespace SSJ {
	Map::Map()
	{
		this->setMapPosition(0,0);
		//this->podloga.AddTexture("abc", "mapa.png");
	}
	void Map::draw(){
		sf::CircleShape mapa(500);
        mapa.setPosition(0-DataContainer::ScreenPosition.x, 0-DataContainer::ScreenPosition.y);
		mapa.setFillColor(sf::Color(150, 120, 10));
		//sf::Texture tekstura;
		//tekstura.loadFromFile("mapa.png");
		//sf::Sprite sprite;
		//sprite.setTexture(tekstura);
		//sprite.setPosition(0,0);
		//Config::window->draw(sprite);
        DataContainer::window->draw(mapa);
	}
}
