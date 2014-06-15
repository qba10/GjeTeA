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

		for(int i = 0 ; i < height ; ++ i )
		{
			for( int j = 0 ; j < width ; ++j)
			{
				int tileCount;
				char block;
				bool bBlock;
				int x, y;
				int xClip = 0, yClip = 0;
				x = j*tileWidth;
				y = i*tileWidth;

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
		int offset = 3;
		int screenTileHeight = ( DataContainer::ScreenHeight / this->tileWidth ) + 2*offset; 
		
		x = ( ( DataContainer::ScreenPosition.x -  fmod(DataContainer::ScreenPosition.x, tileWidth) )/ 
			this->tileWidth ) - offset; 
		y = ( ( DataContainer::ScreenPosition.y -  fmod(DataContainer::ScreenPosition.y, tileWidth) )/ 
			this->tileWidth ) - offset;
		if( x < 0 )
			x = 0;
		if( y < 0 )
			y = 0;

		int tempFirst;
		for(int i = 0 ; i <  screenTileHeight; i++ )
		{
			first = y * (this->w) + x + i*w;;
			if(i==0)
				tempFirst=first;
			last  = first + ( DataContainer::ScreenWidth / this->tileWidth ) + offset*2;
			
			if (last >= (y+i+1) * this->w)
				last = (y+i) * this->w-1;
			if( last >= this->getObjects()->size() )
				last = this->getObjects()->size() -1;
			for( int j = first ; j < last ; ++j)
			{
				this->getObjects()->at(j)->draw();			
			}
        }		
	}
}
