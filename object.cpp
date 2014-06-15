#include "object.h"
namespace SSJ {
	

    Object::Object(float x, float y){

        this->mapPosition.x = x;
        this->mapPosition.y = y;
        this->setDefaultVar();
    }

    Object::Object(Point position){
        this->mapPosition = position;
        this->setDefaultVar();

    }


    Object::Object(){
        this->mapPosition.x = 0;
        this->mapPosition.y = 0;
        this->setDefaultVar();


    }


    Point Object::getMapPosition() const{
        return mapPosition;
    }


    void Object::setMapPosition(float x, float y){

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



    void Object::setDefaultVar()
    {
        this->desynchronization = false;
        this->syncId = -1;
        this->activity = true;
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



    void Object::SynchronizationObject(Json::Value jsonObject)
    {
		if(jsonObject.isMember(_J(_activity))){
            this->activity = jsonObject[_J(_activity)].asBool();
        }
		if(activity)
		{
			if(jsonObject.isMember(_J(_mapPositionX))){
                this->mapPosition.x = jsonObject[_J(_mapPositionX)].asFloat();
			}
			if(jsonObject.isMember(_J(_mapPositionY))){
                this->mapPosition.y = jsonObject[_J(_mapPositionY)].asFloat();
			}
		}
    }
}
