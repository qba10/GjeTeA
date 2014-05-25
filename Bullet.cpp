#include "Bullet.h"
namespace SSJ{

	Bullet::Bullet(){

	}

	Bullet::~Bullet(){

	}

	void Bullet::draw(){
		/*Point firePosition;
		firePosition.x = mainPlayer->getMapPosition().x;
		firePosition.y = mainPlayer->getMapPosition().y;
		Point bulletPosition;
		bulletPosition = firePosition;

		if( (pow(bulletPosition.x - firePosition.x, 2) + pow(bulletPosition.y - firePosition.y, 2)) <= pow(this->range, 2)){
			this->setMapPosition(CalcNewPosition(this->angle));
		}
		else{
			delete Bullet();
		}*/
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
        double s = this->bulletSpeed * DataContainer::DeltaTime.asSeconds();
        double px = sin(tempDegrees.getRadians()) * s;
        double py = cos(tempDegrees.getRadians()) * s;
        newPosition.x += px;
        newPosition.y -= py;
        return newPosition;
	}


}