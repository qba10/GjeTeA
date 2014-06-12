#ifndef HUD_H
#define HUD_H
#include "Loader.h"
#include "mainplayer.h"

namespace SSJ{
	class Hud : public Object{
		sf::Font consola;
		Sprite bulletHud;
		bool isReloading;
		sf::Clock reloadingClock;
		sf::Time timeBetweenReloadingBullets;
		int reloadedBulletAmount;
        float allBulletsReloadTime;
	public:
		Hud();
		~Hud();
		void draw();
		void update();
		void SynchronizationObject(Json::Value);
		void reloadingStarted();
	};
}
#endif HUD_H
