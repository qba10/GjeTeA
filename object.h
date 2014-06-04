#ifndef OBJECT_H
#define OBJECT_H
#include "Loader.h"
namespace SSJ{


    class Object
    {
    protected:
        Point screenPosition;

        Sprite sprite;

        /*for synchronization by server*/

        Point mapPosition;
        bool activity;
        bool desynchronization;

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
        Point getScreenPosition();
        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void SynchronizationObject(Json::Value) = 0;
        void setActivity(bool activity);
        bool isActive();
        Sprite getSprite() ;
        void setSprite( Sprite value);
        bool isDesynchronization() const;
        void setDesynchronization(bool value);
    };


}
#endif // OBJECT_H
