#include "hud.h"

namespace SSJ{
	Hud::Hud(){
		if(!this->consola.loadFromFile("./consola.ttf"))
			std::cout << "Nie ma czcionki" << std::endl;
	}
	Hud::~Hud(){

	}

	void Hud::draw(){
		int ammo = dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->getWeapon1()->getAmmo();
		int allAmmo = dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->getWeapon1()->getAllAmmo();
		std::string sAmmo = "a";
		sf::Text tAmmo(sAmmo, consola);
		tAmmo.setCharacterSize(20);
		tAmmo.setColor(sf::Color::Cyan);
		tAmmo.setPosition(10,10);
		DataContainer::window->draw(tAmmo);
	}



}