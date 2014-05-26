#ifndef MAINPLAYER_H
#define MAINPLAYER_H
#include "dynamicobject.h"
namespace SSJ{
    class MainPlayer : public DynamicObject
    {
    private:
        bool moveLeft;
        bool moveRight;
        bool moveForward;
        bool moveBackward;
    public:
        MainPlayer();
		void eventMouseMoved(sf::Event event);
        void eventStartMoveForward(sf::Event event);
        void eventStartMoveBackward(sf::Event event);
        void eventStartMoveLeft(sf::Event event);
        void eventStartMoveRight(sf::Event event);
        void eventStopMoveForward(sf::Event event);
        void eventStopMoveBackward(sf::Event event);
        void eventStopMoveLeft(sf::Event event);
        void eventStopMoveRight(sf::Event event);
        void draw();
        void update();
        bool getMoveLeft() const;
        void setMoveLeft(bool value);
        bool getMoveRight() const;
        void setMoveRight(bool value);
        bool getMoveForward() const;
        void setMoveForward(bool value);
        bool getMoveBackward() const;
        void setMoveBackward(bool value);
        /**
         * JSON:
         * {
         *      mapPositionX: "",
         *      mapPositionY: "",
         *      activity: "",
         *      hp: "",
         *      maxHP: "",
         *      angle: "",
         *      targetAngle: "",
         *      velocity: ""
         *
         * }
         */
        void SynchronizationObject(Json::Value);
    };
}

#endif // MAINPLAYER_H
