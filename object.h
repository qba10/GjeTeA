#ifndef OBJECT_H
#define OBJECT_H
#include "Loader.h"
namespace SSJ{


    class Object
    {
    protected:
        Point screenPosition;
		int syncId;		/* Unique number used to identificate objects when synchronizing */
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
        Point getMapPosition() const;
        void setMapPosition(const double x, const double y);
        void setMapPosition(const Point screenPosition);
        Point getScreenPosition() const;

        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void SynchronizationObject(Json::Value) = 0;

        void setActivity(const bool activity);
        bool isActive() const;
        Sprite getSprite() const;
        void setSprite(const Sprite value);

        bool isDesynchronization() const;
        void setDesynchronization(bool value);
		int getSyncId() { return this->syncId; }
    };


}
#endif // OBJECT_H
