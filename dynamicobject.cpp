#include "dynamicobject.h"
namespace SSJ{
    DynamicObject::DynamicObject(): InteractiveObject()
    {
        this->velocity = 0.0;
        this->angle = 0.0;
        this->targetAngle = 0.0;
    }

    void DynamicObject::MoveForward(){
        this->setMapPosition(CalcNewPosition(this->angle+0));
    }

    void DynamicObject::MoveBackward(){
        this->setMapPosition(CalcNewPosition(this->angle+180));
    }

    void DynamicObject::MoveLeft(){
        this->setMapPosition(CalcNewPosition(this->angle+270));
    }

    void DynamicObject::MoveRight(){
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

	Degrees DynamicObject::getAngle(){
		return this->angle;
	}

}
