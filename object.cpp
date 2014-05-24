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

    }

    void Object::setMapPosition(Point position){
        this->mapPosition = position;
    }

    void Object::AddAction(sf::Event::EventType type, Object*  object , ActionEvent method){
        Event temp;
        temp.ActionFunction = method;
        temp.EventType = type;
        temp.object = object;
        Config::EventList.push_back(temp);

    }

    void Object::AddActionKeyboard(sf::Event::EventType type, sf::Keyboard::Key key,  Object*  object , ActionEvent method){
        Event temp;
        temp.ActionFunction = method;
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
