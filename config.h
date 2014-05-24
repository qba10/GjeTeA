#ifndef CONFIG_H
#define CONFIG_H
#include "point.h"
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
        static Point ScreenPosition;
        static size_t ScreenHeight;
        static size_t ScreenWidth;
        static size_t ScreenMargin;
        static vector <Event> EventList;
        static sf::Time DeltaTime;
        static size_t RotationSpeed;
		static sf::RenderWindow *window;
    };
}
#endif // CONFIG_H
