#include "object.h"
namespace SSJ {
	

    Object::Object(double x, double y){
        this->mapPosition.x = x;
        this->mapPosition.y = y;
        this->desynchronization = false;
    }

    Object::Object(Point position){
        this->mapPosition = position;
        this->desynchronization = false;
    }

    Object::Object(){
        this->mapPosition.x = 0;
        this->mapPosition.y = 0;
        this->desynchronization = false;

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

    Point Object::getScreenPosition()
    {
        return Helpers::getOnScreenPosition(this->mapPosition);
    }


    Sprite Object::getSprite()
    {
        return sprite;
    }

    void Object::setSprite( Sprite value)
    {
        sprite = value;
    }

    bool Object::isDesynchronization() const
    {
        return desynchronization;
    }

    void Object::setDesynchronization(bool value)
    {
        desynchronization = value;
    }
    void Object::AddAction(sf::Event::EventType type,  Object*  object, ActionEvent function){
        Event temp;
        temp.ActionFunction = function;
        temp.EventType = type;
        temp.object = object;
        DataContainer::EventList.push_back(temp);

    }

    void Object::AddActionKeyboard(sf::Event::EventType type, sf::Keyboard::Key key,  Object*  object , ActionEvent function){
        Event temp;
        temp.ActionFunction = function;
        temp.EventType = type;
        temp.KeyAction =  key;
        temp.object = object;
        DataContainer::EventList.push_back(temp);

    }

    void Object::setActivity(bool activity){
        this->activity = activity;
    }

    bool Object::isActive(){
        return activity;
    }

    void Object::SynchronizationObject(Json::Value jsonObject)
    {
        if(jsonObject.isMember("mapPositionX")){
            this->mapPosition.x = jsonObject["mapPositionX"].asDouble();
        }
        if(jsonObject.isMember("mapPositionY")){
            this->mapPosition.y = jsonObject["mapPositionY"].asDouble();
        }
        if(jsonObject.isMember("activity")){
            this->activity = jsonObject["mapPositionX"].asBool();
        }

    }
}
