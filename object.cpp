#include "object.h"
namespace SSJ {
	

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

	Object::Object(){
        this->mapPosition.x = 0;
        this->mapPosition.y = 0;
        this->desynchronization = false;
		syncId = -1;
        this->activity = true;

    }

    Object::Object(double x, double y){
        this->mapPosition.x = x;
        this->mapPosition.y = y;
        this->desynchronization = false;
		syncId = -1;
        this->activity = true;
    }

    Object::Object(Point position){
        this->mapPosition = position;
        this->desynchronization = false;
		syncId = -1;
        this->activity = true;
    }

    

    Point Object::getMapPosition() const{
        return mapPosition;
    }

    void Object::setMapPosition(const double x, const double y){
        this->mapPosition.x = x;
        this->mapPosition.y = y;
    }

    void Object::setMapPosition(const Point position){
        this->mapPosition = position;
    }

    Point Object::getScreenPosition() const
    {
        return Helpers::getOnScreenPosition(this->mapPosition);
    }


	void Object::setActivity(const bool activity){
        this->activity = activity;
    }

    bool Object::isActive() const{
        return activity;
    }

    Sprite Object::getSprite() const
    {
        return sprite;
    }

    void Object::setSprite(const Sprite value)
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
