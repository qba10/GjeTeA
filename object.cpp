#include "object.h"
namespace SSJ {
	

    Object::Object(double x, double y){
        this->mapPosition.x = x;
        this->mapPosition.y = y;
        this->desynchronization = false;
		syncId = -1;
    }

    Object::Object(Point position){
        this->mapPosition = position;
        this->desynchronization = false;
		syncId = -1;
    }

    Object::Object(){
        this->mapPosition.x = 0;
        this->mapPosition.y = 0;
        this->desynchronization = false;
		syncId = -1;

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
		if(jsonObject.isMember(_J(_activity))){
            this->activity = jsonObject[_J(_activity)].asBool();
        }
		if(activity)
		{
			if(jsonObject.isMember(_J(_mapPositionX))){
				this->mapPosition.x = jsonObject[_J(_mapPositionX)].asDouble();
			}
			if(jsonObject.isMember(_J(_mapPositionY))){
				this->mapPosition.y = jsonObject[_J(_mapPositionY)].asDouble();
			}
        
		}
    }
}
