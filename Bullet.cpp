#include "Bullet.h"
namespace SSJ{



	Bullet::Bullet(){
		this->bulletPosition = ownerPosition;
	}

	Bullet::~Bullet(){

	}

	void Bullet::draw(){

		//if( (pow(bulletPosition.x - ownerPosition.x, 2) + pow(bulletPosition.y - ownerPosition.y, 2)) <= pow(this->range, 2)){
			this->setMapPosition(CalcNewPosition());
			cout << "x: " << this->getMapPosition().x << "\ty: " << this->getMapPosition().y << endl;
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
        double s = this->bulletSpeed * DataContainer::DeltaTime.asSeconds();
        double px = sin(tempDegrees.getRadians()) * s;
        double py = cos(tempDegrees.getRadians()) * s;
        newPosition.x += px;
        newPosition.y -= py;
        return newPosition;
	}


}