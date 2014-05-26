#ifndef CONFIG_H
#define CONFIG_H
#include "point.h"
#include "degrees.h"
#include "sprite.h"
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <functional>
#define SLOT(object, method) object, (ActionEvent)(&method)
#define PI 3.14159265
namespace SSJ {
    class Object;
    using namespace std;
    typedef void(Object::*ActionEvent)(sf::Event);
    //void (Object::*ActionEvent)(sf::Event)  = NULL;
    //typedef function<void(sf::Event)> ActionEvent;

    struct Event{
        Event(){
             KeyAction = sf::Keyboard::Unknown;
        }
         sf::Event::EventType EventType;
         ActionEvent ActionFunction;
         sf::Keyboard::Key KeyAction;
         Object * object;
    };

    class Config{
    public:

        static size_t RotationSpeed;

    };
}
#endif // CONFIG_H
