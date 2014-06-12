#include "hud.h"

namespace SSJ{
	Hud::Hud(){
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
		tAmmo.setPosition(10,520);
		DataContainer::window->draw(tAmmo);
		if(DataContainer::MainPlayer != NULL){
			if(!this->isReloading){
				this->bulletHud.getSprite()->setColor(sf::Color(255,255,255,255));
				for(int i = 0, k = 0; i < ammo; i++, k+=5){
					this->bulletHud.getSprite()->setPosition(10+k, 560);
					DataContainer::window->draw(*(this->bulletHud.getSprite()));
				}
				this->reloadedBulletAmount = 1;
				this->allBulletsReloadTime = 0;
			}
			else{
				this->bulletHud.getSprite()->setColor(sf::Color(255,255,255,60));
				for(int i = 0, spriteDistance = 0; i < this->reloadedBulletAmount; i++, spriteDistance += 5){
					this->bulletHud.getSprite()->setPosition(10+spriteDistance, 560);
					DataContainer::window->draw(*(this->bulletHud.getSprite()));
				}				
			}
			
		}

	}

	void Hud::reloadingStarted(){
		if(this->allBulletsReloadTime == 0 && this->isReloading /*&& this->timeBetweenReloadingBullets.asSeconds() == 0*/)
			this->reloadingClock.restart();
	}


	void Hud::update(){
		if(DataContainer::MainPlayer != NULL){
			if(dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->getWeapon1()->getReloading()){
				this->isReloading = true;
				this->reloadingStarted();
				this->timeBetweenReloadingBullets = this->reloadingClock.getElapsedTime();
				int reloadTime = dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->getWeapon1()->getReloadTime();
				int bulletAmount = dynamic_cast<MainPlayer*>(DataContainer::MainPlayer)->getWeapon1()->getAmmoInMag();
				double bulletReloadTime = reloadTime / bulletAmount;
				if(this->timeBetweenReloadingBullets.asSeconds() > allBulletsReloadTime && this->reloadedBulletAmount != bulletAmount){
					this->allBulletsReloadTime = this->reloadedBulletAmount * bulletReloadTime;
					this->reloadedBulletAmount = (this->timeBetweenReloadingBullets.asSeconds() / allBulletsReloadTime) * bulletAmount;
					if(this->reloadedBulletAmount > bulletAmount){
						this->reloadedBulletAmount = bulletAmount;
					}
					cout << reloadedBulletAmount << " " << bulletAmount <<"\n";
				}
			}
			else{
				this->isReloading = false;
			}
			
			

		}
	}

	void Hud::SynchronizationObject(Json::Value){

	}


}