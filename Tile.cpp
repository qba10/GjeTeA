#include "Tile.h"
#include "sprite.h"
#include "datacontainer.h"

namespace SSJ {

	Tile::Tile(int x, int y, int width, bool block, sf::IntRect clip, sf::Texture* img)
		: Object(x, y)
	{
		this->width = width;
		this->setMapPosition(x, y);

		this->sprite.AddTexture("tileset", img, clip);
		this->block = block;
		visible = true;
	}
	Tile::Tile(int x, int y, int width, bool block)
	{
		this->width = width;
		this->setMapPosition(x, y);
		visible = false;
		this->block = block;
	}
	void Tile::update() { }
	void Tile::draw()
	{
		if( !visible )
			return;
		sf::Rect<double> tRect = sf::Rect<double>( this->getMapPosition().x,
												this->getMapPosition().y,
												this->width,
												this->width);
		sf::Rect<double> camera = sf::Rect<double>( DataContainer::ScreenPosition.x,
												DataContainer::ScreenPosition.y,
												DataContainer::ScreenWidth,
												DataContainer::ScreenHeight);

		if(!Helpers::checkCollision(tRect, camera))
			return;

		double x, y;
		x = this->getScreenPosition().x;
		y = this->getScreenPosition().y;
		(this->getSprite().getSprite())->setPosition(x,y);
		DataContainer::window->draw( *(this->sprite.getSprite()));
	}
};