#include "hud.h"

namespace SSJ{

	Hud::Hud() : Object(){

		if(!this->consola.loadFromFile("./visitor1.ttf"))
			std::cout << "Nie ma czcionki" << std::endl;
		this->isReloading = false;
		this->bulletHud.AddTexture("bulletHud", "./bulletHud.png");
		this->reloadedBulletAmount = 1;
		this->allBulletsReloadTime = 0;
	}

	Hud::~Hud(){

	}

	void Hud::draw(){
		int ammo, allAmmo;
		if(DataContainer::MainPlayer != NULL){
			ammo = dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->getWeapon1()->getAmmo();
			allAmmo = dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->getWeapon1()->getAllAmmo();
		}
		else{
			ammo = 0;
			allAmmo = 0;
		}
		std::string sAmmo = intToString(ammo) + "/" + intToString(allAmmo);
		sf::Text tAmmo(sAmmo, consola);
		tAmmo.setCharacterSize(30);
		tAmmo.setColor(sf::Color::Cyan);
		tAmmo.setPosition(10,DataContainer::ScreenHeight-80);
		DataContainer::window->draw(tAmmo);
		if(DataContainer::MainPlayer != NULL){
			/**********************************
					RELOADING ANIMATION
			**********************************/
			if(!this->isReloading){
				this->bulletHud.getSprite()->setColor(sf::Color(255,255,255,255));
				for(int i = 0, k = 0; i < ammo; i++, k+=5){
					this->bulletHud.getSprite()->setPosition(10+k, DataContainer::ScreenHeight-40);
					DataContainer::window->draw(*(this->bulletHud.getSprite()));
				}
				this->reloadedBulletAmount = 1;
				this->allBulletsReloadTime = 0;
			}
			else{
				this->bulletHud.getSprite()->setColor(sf::Color(255,255,255,60));
				for(int i = 0, spriteDistance = 0; i < this->reloadedBulletAmount; i++, spriteDistance += 5){
					this->bulletHud.getSprite()->setPosition(10+spriteDistance, DataContainer::ScreenHeight-40);
					DataContainer::window->draw(*(this->bulletHud.getSprite()));
				}				
			}
			/**********************************
					ACTIVE WEAPON DRAWING
			**********************************/
			std::string sWeaponPP = dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->getSelectedWeapon(-2)->getName();
			sf::Text tWeaponPP(sWeaponPP, consola);
			tWeaponPP.setCharacterSize(13);
			tWeaponPP.setColor(sf::Color(153,217,234,80));
			tWeaponPP.setPosition(10,DataContainer::ScreenHeight-147);
			DataContainer::window->draw(tWeaponPP);

			std::string sWeaponP = dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->getSelectedWeapon(-1)->getName();
			sf::Text tWeaponP(sWeaponP, consola);
			tWeaponP.setCharacterSize(20);
			tWeaponP.setColor(sf::Color(153,217,234,120));
			tWeaponP.setPosition(10,DataContainer::ScreenHeight-140);
			DataContainer::window->draw(tWeaponP);

			std::string sWeapon1 = dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->getSelectedWeapon(0)->getName();
			sf::Text tWeapon1(sWeapon1, consola);
			tWeapon1.setCharacterSize(30);
			tWeapon1.setColor(sf::Color::Cyan);
			tWeapon1.setPosition(10,DataContainer::ScreenHeight-130);
			DataContainer::window->draw(tWeapon1);

			std::string sWeaponN = dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->getSelectedWeapon(1)->getName();
			sf::Text tWeaponN(sWeaponN, consola);
			tWeaponN.setCharacterSize(20);
			tWeaponN.setColor(sf::Color(153,217,234,120));
			tWeaponN.setPosition(10,DataContainer::ScreenHeight-105);
			DataContainer::window->draw(tWeaponN);

			std::string sWeaponNN = dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->getSelectedWeapon(2)->getName();
			sf::Text tWeaponNN(sWeaponNN, consola);
			tWeaponNN.setCharacterSize(13);
			tWeaponNN.setColor(sf::Color(153,217,234,80));
			tWeaponNN.setPosition(10,DataContainer::ScreenHeight-87);
			DataContainer::window->draw(tWeaponNN);

			// WEAPON RANGE
			sf::CircleShape weaponRange((float)this->currentRadius, 100);
			weaponRange.setOutlineColor(sf::Color(153,217,234,120));
			weaponRange.setOutlineThickness(3);
			weaponRange.setPosition(dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->getScreenPosition().x - (double)this->currentRadius, 
									dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->getScreenPosition().y - (double)this->currentRadius);
			weaponRange.setFillColor(sf::Color::Transparent);
			DataContainer::window->draw(weaponRange);

			// LIFE
			sf::RectangleShape hpFrame(sf::Vector2f(100,20));
			hpFrame.setFillColor(sf::Color::Transparent);
			hpFrame.setOutlineColor(sf::Color(153,217,234,120));
			hpFrame.setOutlineThickness(4);
			hpFrame.setPosition(DataContainer::ScreenWidth-150, DataContainer::ScreenHeight-30);
			DataContainer::window->draw(hpFrame);

			int hp = dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->getHP();
			int lackHp = dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->getMaxHP() - hp;

			sf::RectangleShape rHp(sf::Vector2f(hp, 20));
			rHp.setFillColor(sf::Color(153,217,234));
			rHp.setPosition(DataContainer::ScreenWidth-150, DataContainer::ScreenHeight-30);
			DataContainer::window->draw(rHp);


			sf::RectangleShape rLackHp(sf::Vector2f(lackHp, 20));
			rLackHp.setFillColor(sf::Color(153,217,60));
			rLackHp.setPosition(DataContainer::ScreenWidth-150+hp, DataContainer::ScreenHeight-28);
			DataContainer::window->draw(rLackHp);

		}

	}

	void Hud::update(){
		if(DataContainer::MainPlayer != NULL){
			if(dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->getWeapon1()->getReloading()){
				this->isReloading = true;
				this->timeBetweenReloadingBullets =  dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->getWeapon1()->getReloadClockElapsedTime();
				int reloadTime = dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->getWeapon1()->getReloadTime();
				int bulletAmount = dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->getWeapon1()->getAmmoInMag();

                float bulletReloadTime = (float)reloadTime / (float)bulletAmount;

				if(this->timeBetweenReloadingBullets.asSeconds() > allBulletsReloadTime && this->reloadedBulletAmount != bulletAmount){
                    this->allBulletsReloadTime = (double)this->reloadedBulletAmount * (double)bulletReloadTime;
					this->reloadedBulletAmount = (this->timeBetweenReloadingBullets.asSeconds() / reloadTime) * bulletAmount;
					if(this->reloadedBulletAmount == 0) reloadedBulletAmount = 1;
					if(this->reloadedBulletAmount > bulletAmount){
						this->reloadedBulletAmount = bulletAmount;
					}
				}
			}
			else{
				this->isReloading = false;
				this->reloadedBulletAmount = 1;
				this->allBulletsReloadTime = 0;
			}
			
			this->currentRadius = dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->getWeapon1()->getRange();

		}
	}

	void Hud::SynchronizationObject(Json::Value){

	}
}
