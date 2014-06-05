#include "map.h"
#include "Tile.h"
#include <fstream>

namespace SSJ {
	Map::Map() : GameLayer("Mapa", false)
	{
		
	}
	Map::Map(string file) : GameLayer("Mapa", false)
	{
		this->load(file);
	}

	void Map::load(string file)
	{
        fstream mapFile;
        mapFile.open(file.c_str(), ios::in);
		if(!mapFile.good())
		{
			cout << "Nie znaleziono mapy" << endl;
			return;
		}
		
		int width, height, tileWidth;
		int fileWidth, fileHeight;
		string textures;

		mapFile >> width;
		mapFile >> height;
		mapFile >> textures;
		mapFile >> tileWidth;
		w = width;
		h = height;
		this->tileWidth = tileWidth;
		this->texture.loadFromFile(textures);
		fileWidth = texture.getSize().x;
		fileHeight = texture.getSize().y;

		for(int i = 0 ; i < width ; ++ i )
		{
			for( int j = 0 ; j < height ; ++j)
			{
				int tileCount;
				char block;
				bool bBlock;
				int x, y;
				int xClip = 0, yClip = 0;
				x = i*tileWidth;
				y = j*tileWidth;

				mapFile >> tileCount;
				mapFile >> block;
				if (block == 'x')
					bBlock = true;
				else
					bBlock = false;

				while(tileCount >= fileWidth / tileWidth)
				{
					tileCount -= fileWidth / tileWidth;
					yClip ++;
				}
				xClip = tileCount;
				Tile *tile;
				if(tileCount == -1)
				{
					tile = new Tile(x, y, tileWidth, bBlock);
				}
				else
				{
					sf::IntRect clip;
					clip.left = xClip * tileWidth;
					clip.top = yClip * tileWidth;
					clip.width = tileWidth;
					clip.height = tileWidth;
					tile = new Tile(x, y, tileWidth, bBlock, clip, &this->texture);
				}
				this->addObject(tile);
			}
		}
	}

	void Map::DrawLayer(){
		double x;
		double y;
		//x = 
		for(size_t i = 0 ; i < this->getObjects()->size() ; i++ ){
            this->getObjects()->at(i)->draw();
        }
	}
}
