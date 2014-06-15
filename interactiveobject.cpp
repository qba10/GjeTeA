#include "interactiveobject.h"

namespace  SSJ {

    InteractiveObject::InteractiveObject() : Object()
    {
        this->maxHP = 100;
        this->hp = 100;
    }

    void InteractiveObject::setHP(const int hp)
    {
        if(this->maxHP <= hp && hp >= 0)
            this->hp = hp;
    }

    void InteractiveObject::setMaxHP(const int hp)
    {
        this->maxHP = hp;
    }

    void InteractiveObject::addHP(int hp)
    {
     if(this->maxHP <= this->hp+hp && this->hp+hp >= 0)
         this->hp += hp;
    }

    void InteractiveObject::subHP(int hp)
    {
        if(this->maxHP <= this->hp-hp && this->hp-hp >= 0)
            this->hp -= hp;
    }

    int InteractiveObject::getHP() const
    {
        return this->hp;
    }

    int InteractiveObject::getMaxHP() const
    {
        return this->maxHP;
    }

    bool InteractiveObject::isDead() const{
        if(this->hp == 0)
            return true;
        else
            return false;
    }

    void InteractiveObject::SynchronizationObject(Json::Value jsonObject)
    {
        if(jsonObject.isMember(_J(_mapPositionX))){
            this->mapPosition.x = jsonObject[_J(_mapPositionX)].asDouble();
        }
        if(jsonObject.isMember(_J(_mapPositionY))){
            this->mapPosition.y = jsonObject[_J(_mapPositionY)].asDouble();
        }
        if(jsonObject.isMember(_J(_activity))){
            this->activity = jsonObject[_J(_activity)].asBool();
        }
        if(jsonObject.isMember(_J(_hp))){
            this->hp = jsonObject[_J(_hp)].asUInt();
        }
        if(jsonObject.isMember(_J(_maxHP))){
            this->maxHP = jsonObject[_J(_maxHP)].asUInt();
        }
    }
}
