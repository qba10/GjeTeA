#ifndef MAP
#define MAP
#include "gamelayer.h"
using namespace std;
namespace SSJ{
	class Map : public GameLayer{
	public:
		Map();
		Map(string file);
		void load(string file);
	private:
		sf::Texture texture;
		void DrawLayer();
		int tileWidth;
		int w;
		int h;
	};
}
#endif