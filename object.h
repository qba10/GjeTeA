#ifndef OBJECT_H
#define OBJECT_H
#include "Loader.h"
namespace SSJ{
    class Object
    {
    protected:

        Point mapPosition;
        Sprite sprite;

        /*for synchronization by server*/
        Point screenPosition;
        bool activity;

    public:
        void AddAction(sf::Event::EventType, Object*,  ActionEvent);
        void AddActionKeyboard(sf::Event::EventType, sf::Keyboard::Key, Object* ,ActionEvent);
    public:
        Object();
        Object(double x, double y);
        Object(Point);
        Point getMapPosition();
        void setMapPosition(double x, double y);
        void setMapPosition(Point screenPosition);
        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void SynchronizationObject(Json::Value) = 0;
        void setActivity(bool activity);
        bool isActive();
    };
}
#endif // OBJECT_H
