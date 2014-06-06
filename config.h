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
#include <sstream>
#define SLOT(object, method) object, (ActionEvent)(&method)
#define _J(enum) intToString(enum)
#define PI 3.14159265
namespace SSJ {
    string intToString(int);

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
    enum RequestName{
        _synchronizeMainPlayer,
        _createMainPlayer,
        _createBullet,
        _createWeapon

    };

    enum JsonOption{
        _mapPositionX,
        _mapPositionY,
        _activity,
        _hp,
        _maxHP,
        _velocity,
        _angle,
        _targetAngle,
        _playerId,
        _ask,
        _parameters,
        _objectName,
        _name,
        _ownerPositionX,
        _ownerPositionY,
        _ownerAngle,
        _weaponType,
        _objectAmount,
        _synchronize,
		_syncId

    };
    enum ObjectType{
        _Object,
        _InteractiveObject,
        _StaticObject,
        _DynamicObject,
        _MainPlayer,
        _Player,
		_Bullet,
		_Weapon
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



	struct Request{
        RequestName action;
		Json::Value parameters;
	};

    class Config{
    public:
        static string PlayerId;
        static size_t RotationSpeed;

    };
}
#endif // CONFIG_H
