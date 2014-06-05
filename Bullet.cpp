#include "Bullet.h"
namespace SSJ{



	Bullet::Bullet(){
		this->setMapPosition(ownerPosition);
		this->sprite.AddTexture("bullet", "./bullet.png");
	}

	Bullet::~Bullet(){

	}

	void Bullet::draw(){

		if( (pow(this->getMapPosition().x - ownerPosition.x, 2) + pow(this->getMapPosition().y - ownerPosition.y, 2)) <= pow(this->range, 2)){

			this->setMapPosition(CalcNewPosition());
			DataContainer::window->draw(*(this->sprite.getSprite()));
			this->activity = true;
			cout << "x: " << this->getMapPosition().x << "\ty: " << this->getMapPosition().y << endl;
		}
		else
			this->activity = false;
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
        if(jsonObject.isMember("mapPositionX")){
            this->mapPosition.x = jsonObject["mapPositionX"].asDouble();
        }
        if(jsonObject.isMember("mapPositionY")){
            this->mapPosition.y = jsonObject["mapPositionY"].asDouble();
        }
        if(jsonObject.isMember("activity")){
            this->activity = jsonObject["activity"].asBool();
        }
        if(jsonObject.isMember("angle")){
            this->angle = jsonObject["angle"].asDouble();
        }
        if(jsonObject.isMember("targetAngle")){
            this->targetAngle = jsonObject["targetAngle"].asDouble();
        }

    }
}