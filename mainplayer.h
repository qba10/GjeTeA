#ifndef MAINPLAYER_H
#define MAINPLAYER_H
#include "dynamicobject.h"
namespace SSJ{
    class MainPlayer : public DynamicObject
    {
    public:
        MainPlayer();
        void eventMoveForward(sf::Event event);
        void eventMoveBackward(sf::Event event);
        void eventMoveLeft(sf::Event event);
        void eventMoveRight(sf::Event event);
        void draw();
        void update();
    };
}

#endif // MAINPLAYER_H
