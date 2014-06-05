#ifndef HUD_H
#define HUD_H
#include "Loader.h"
#include "mainplayer.h"

namespace SSJ{
	class Hud{
		sf::Font consola;
	public:
		Hud();
		~Hud();
		void draw();

	};
}
#endif HUD_H