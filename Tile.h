#include "object.h"
#include <SFML/Graphics.hpp>

namespace SSJ{
	class Tile : public Object
	{
	private:
		int width;
		bool block;
		bool visible;
	public:
		Tile() { }
		Tile(int x, int y, int width, bool block, sf::IntRect clip, sf::Texture* img);
		Tile(int x, int y, int width, bool block);
		
		void draw();
		void update();
		void SynchronizationObject(Json::Value) {  }
	};
};
