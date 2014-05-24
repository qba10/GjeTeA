#include "object.h"
namespace SSJ {


    Object::Object(double x, double y){
        this->mapPosition.x = x;
        this->mapPosition.y = y;
    }

    Object::Object(Point position){
        this->mapPosition = position;
    }

    Object::Object(){
        this->mapPosition.x = 0;
        this->mapPosition.y = 0;

    }

    Point Object::getMapPosition(){
        return mapPosition;
    }

    void Object::setMapPosition(double x, double y){
        this->mapPosition.x = x;
        this->mapPosition.y = y;
		printf("x: %d, y: %d, x: %d, y: %d\n", mapPosition.x, mapPosition.y, x, y);
    }

    void Object::setMapPosition(Point position){
        this->mapPosition = position;
    }

    void Object::AddAction(sf::Event::EventType type, ActionEvent function){
        Event temp;
        temp.ActionFunction = function;
        temp.EventType = type;
        Config::EventList.push_back(temp);

    }

    void Object::AddActionKeyboard(sf::Event::EventType type, sf::Keyboard::Key key,  Object*  object , ActionEvent function){
        Event temp;
        temp.ActionFunction = function;
        temp.EventType = type;
        temp.KeyAction =  key;
        temp.object = object;
        Config::EventList.push_back(temp);

    }

    void Object::setActivity(bool activity){
        this->activity = activity;
    }

    bool Object::isActive(){
        return activity;
    }
}
