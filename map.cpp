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
		mapFile.open(file, ios::in);
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
		int x;
		int y;
		int first;
		int last;
		int offset = 5;
		int screenTileHeight = ( DataContainer::ScreenHeight / this->tileWidth ) + 4*offset; 
		
		x = ( ( DataContainer::ScreenPosition.x -  fmod(DataContainer::ScreenPosition.x, tileWidth) )/ 
			this->tileWidth ) - offset; 
		y = ( ( DataContainer::ScreenPosition.y -  fmod(DataContainer::ScreenPosition.y, tileWidth) )/ 
			this->tileWidth ) - offset;
		
		for(int i = 0 ; i <  screenTileHeight; i++ )
		{
			first = y * (this->w) + x + i*w;
			if (first < 0)
				first = 0;
			
			last  = first + ( DataContainer::ScreenWidth / this->tileWidth ) + offset;
			if (last >= this->getObjects()->size())
				last = this->getObjects()->size()-1;

			for( int j = first ; j < last ; ++j)
			{
				this->getObjects()->at(j)->draw();
			}
        }
	}
}
