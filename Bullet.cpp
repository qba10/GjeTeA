#include "Bullet.h"
namespace SSJ{



	Bullet::Bullet(){
		this->setMapPosition(ownerPosition);
	}

	Bullet::~Bullet(){

	}

	void Bullet::draw(){

		//if( (pow(bulletPosition.x - ownerPosition.x, 2) + pow(bulletPosition.y - ownerPosition.y, 2)) <= pow(this->range, 2)){
			this->setMapPosition(CalcNewPosition());
			//cout << "x: " << this->getMapPosition().x << "\ty: " << this->getMapPosition().y << endl;
		//}
	}

	void Bullet::update(){
	
	}

	void Bullet::Blast(){

	}

	void Bullet::Hit(){

	}

	Point Bullet::CalcNewPosition(){

		Point newPosition = this->getMapPosition();
        SSJ::Degrees tempDegrees = this->angle;
		double s = this->velocity * DataContainer::DeltaTime.asSeconds();
        double px = sin(tempDegrees.getRadians()) * s;
        double py = cos(tempDegrees.getRadians()) * s;
        newPosition.x += px;
        newPosition.y -= py;
        return newPosition;
	}

	void Bullet::SynchronizationObject(Json::Value jsonObject)
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
        if(jsonObject.isMember(_J(_maxHP))){
            this->angle = jsonObject[_J(_maxHP)].asDouble();
        }
        if(jsonObject.isMember(_J(_targetAngle))){
            this->targetAngle = jsonObject[_J(_targetAngle)].asDouble();
        }

    }
}
