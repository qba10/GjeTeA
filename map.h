#ifndef MAP
#define MAP
#include "staticobject.h"
#include <vector>
using namespace std;
namespace SSJ{
	class Map : public StaticObject{
	public:
		Map();
	private:
		vector<Object*> obiekty;
		Sprite podloga;	
		void draw();
	};
}
#endif