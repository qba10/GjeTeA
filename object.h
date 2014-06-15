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
    private:
        void setDefaultVar();
    public:
        void AddAction(sf::Event::EventType, Object*,  ActionEvent);
        void AddActionKeyboard(sf::Event::EventType, sf::Keyboard::Key, Object* ,ActionEvent);
    public:
        Object();
        Object(float x, float y);
        Object(Point);

        Point getMapPosition() const;
        void setMapPosition(float x, float y);
        void setMapPosition(Point screenPosition);
        Point getScreenPosition() const;


        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void SynchronizationObject(Json::Value) = 0;

        void setActivity(const bool activity);
        bool isActive() const;
        Sprite *getSprite() ;
        void setSprite(const Sprite value);

        bool isDesynchronization() const;
        void setDesynchronization(bool value);
		int getSyncId() { return this->syncId; }


    };


}
#endif // OBJECT_H
