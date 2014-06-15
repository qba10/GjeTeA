#include "object.h"
namespace SSJ {
	

<<<<<<< HEAD
    Object::Object(float x, float y){
=======
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
>>>>>>> 0d4e052eb585e50e18f6b6b3f9cef44ca2f25831
        this->mapPosition.x = x;
        this->mapPosition.y = y;
        this->setDefaultVar();
    }

    Object::Object(Point position){
        this->mapPosition = position;
        this->setDefaultVar();

    }

<<<<<<< HEAD
    Object::Object(){
        this->mapPosition.x = 0;
        this->mapPosition.y = 0;
        this->setDefaultVar();


    }
=======
    
>>>>>>> 0d4e052eb585e50e18f6b6b3f9cef44ca2f25831

    Point Object::getMapPosition() const{
        return mapPosition;
    }

<<<<<<< HEAD
    void Object::setMapPosition(float x, float y){
=======
    void Object::setMapPosition(const double x, const double y){
>>>>>>> 0d4e052eb585e50e18f6b6b3f9cef44ca2f25831
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
<<<<<<< HEAD


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

    void Object::setActivity(bool activity){
        this->activity = activity;
    }

    bool Object::isActive(){
        return activity;
    }

=======
    
>>>>>>> 0d4e052eb585e50e18f6b6b3f9cef44ca2f25831
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
