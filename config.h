#ifndef CONFIG_H
#define CONFIG_H
#include "point.h"
#include "degrees.h"
#include "sprite.h"
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <functional>
#include <queue>
#include <jsoncpp/json/json.h>
#define SLOT(object, method) object, (ActionEvent)(&method)
#define PI 3.14159265
namespace SSJ {

	enum WeaponType{	
		Glock,
		Uzi,
		Ak47,
		M16,
		Shotgun,
		SniperRifle,
		Bazooka,
		Grenade,
		Knife
};


enum ObjectType{
        _Object,
        _InteractiveObject,
        _StaticObject,
        _DynamicObject,
        _MainPlayer,
        _Player,
		_Bullet

};
    class Object;
    using namespace std;
    typedef void(Object::*ActionEvent)(sf::Event);


    struct Event{
        Event(){
             KeyAction = sf::Keyboard::Unknown;
        }
         sf::Event::EventType EventType;
         ActionEvent ActionFunction;
         sf::Keyboard::Key KeyAction;
         Object * object;
    };

	enum RequestType{
		_CreateBullet,
	};

	struct Request{
		RequestType action;
		Json::Value parameters;
	};

    class Config{
    public:
        static string PlayerId;
        static size_t RotationSpeed;

    };
}
#endif // CONFIG_H
