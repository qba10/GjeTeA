#ifndef OBJECT_H
#define OBJECT_H
#include "Loader.h"
namespace SSJ{
    class Object
    {
    private:
        Point screenPosition;
        Point mapPosition;
        Sprite sprite;
        Object(double x, double y);
        Object(Point);
        bool activity;
    public:
        void AddAction(sf::Event::EventType ,Object*, ActionEvent);
        void AddActionKeyboard(sf::Event::EventType, sf::Keyboard::Key, Object* ,ActionEvent);
    public:
        Object();
        Point getMapPosition();
        void setMapPosition(double x, double y);
        void setMapPosition(Point screenPosition);
        virtual void draw() = 0;
        virtual void update() = 0;
        void setActivity(bool activity);
        bool isActive();
    };
}
#endif // OBJECT_H
