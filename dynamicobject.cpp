#include "dynamicobject.h"
namespace SSJ{
    DynamicObject::DynamicObject(): InteractiveObject()
    {
        this->velocity = 0.0;
        this->angle = 0.0;
        this->targetAngle = 0.0;
    }

    void DynamicObject::MoveForward(){
        this->desynchronization = true;
        this->setMapPosition(CalcNewPosition(this->angle+0));
    }

    void DynamicObject::MoveBackward(){
        this->desynchronization = true;
        this->setMapPosition(CalcNewPosition(this->angle+180));
    }

    void DynamicObject::MoveLeft(){
        this->desynchronization = true;
        this->setMapPosition(CalcNewPosition(this->angle+270));
    }

    void DynamicObject::MoveRight(){
        this->desynchronization = true;
        this->setMapPosition(CalcNewPosition(this->angle+90));
    }

    void DynamicObject::RotateLeft(){
        double deltaAngle = Config::RotationSpeed * DataContainer::DeltaTime.asSeconds();
        bool a;
        if(this->targetAngle.getDegrees() - this->angle.getDegrees() < 0)
            a = true;
        else
            a = false;

        /** czy przeszło przez zero by Łysy**/
        if(this->angle.getDegrees() * (this->angle.getDegrees() - deltaAngle) < 0){
            a = !a;
        }

        if(((this->targetAngle.getDegrees() - this->angle.getDegrees()- deltaAngle ) < 0 ) != a)
            this->angle = this->targetAngle;
        else
            this->angle -= deltaAngle;
    }

    void DynamicObject::RotateRight(){
        double deltaAngle = Config::RotationSpeed * DataContainer::DeltaTime.asSeconds();
        bool a;
        if(this->targetAngle.getDegrees() - this->angle.getDegrees() < 0)
            a = true;
        else
            a = false;

        /** czy przeszło przez zero by Łysy**/
        if(this->angle.getDegrees() * (this->angle.getDegrees() + deltaAngle) < 0){
            a = !a;
        }

        if(((this->targetAngle.getDegrees() - this->angle.getDegrees() + deltaAngle ) < 0 ) != a)
            this->angle = this->targetAngle;
        else
            this->angle += deltaAngle;
    }

    Point DynamicObject::CalcNewPosition(SSJ::Degrees addAngle){

        Point newPosition = this->getMapPosition();
        SSJ::Degrees tempDegrees = this->angle;
        tempDegrees += addAngle;
        double s = this->velocity * DataContainer::DeltaTime.asSeconds();
        double px = sin(tempDegrees.getRadians()) * s;
        double py = cos(tempDegrees.getRadians()) * s;
        newPosition.x += px;
        newPosition.y -= py;
        return newPosition;
    }


	Degrees DynamicObject::getAngle() const{
		return this->angle;
	}

	void DynamicObject::setAngle(const Degrees angle){
		this->angle = angle;
	}

	int DynamicObject::getVelocity() const{
		return this->velocity;
	}

	void DynamicObject::setVelocity(const int velocity){
		this->velocity = velocity;
	}


	void DynamicObject::SynchronizationObject(Json::Value jsonObject)
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
        if(jsonObject.isMember(_J(_velocity))){
            this->velocity = jsonObject[_J(_velocity)].asUInt();
        }
        if(jsonObject.isMember(_J(_angle))){
            this->angle = jsonObject[_J(_angle)].asDouble();
        }
        if(jsonObject.isMember(_J(_targetAngle))){
            this->targetAngle = jsonObject[_J(_targetAngle)].asDouble();
        }
    }
}
