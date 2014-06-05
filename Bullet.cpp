#include "Bullet.h"
namespace SSJ{



	Bullet::Bullet(){
		//this->setMapPosition(this->ownerPosition);
		this->sprite.AddTexture("bullet", "./bullet.png");
		/*Animation *pocisk = new Animation("pocisk");
		pocisk->AddFrame("./bullet.png");
		sprite.AddAnimation(pocisk);*/
		/*if(this->blastFire){
			Animation * animation = new Animation("wybuch");
			animation->setAlphaMask(sf::Color::Black);
			//animation->setSmooth(true);
		   // animation->setDefaultFrameBreakTime(sf::milliseconds(300));
			animation->setDefaultFrame(0);
			animation->AddFrame("./sprite/wybuchAnimacja/blast01.png", sf::milliseconds(50));
			animation->AddFrame("./sprite/wybuchAnimacja/blast02.png", sf::milliseconds(50));
			animation->AddFrame("./sprite/wybuchAnimacja/blast03.png", sf::milliseconds(50));
			animation->AddFrame("./sprite/wybuchAnimacja/blast1.png", sf::milliseconds(50));
			animation->AddFrame("./sprite/wybuchAnimacja/blast2.png", sf::milliseconds(50));
			animation->AddFrame("./sprite/wybuchAnimacja/blast3.png", sf::milliseconds(50));
			animation->AddFrame("./sprite/wybuchAnimacja/blast4.png", sf::milliseconds(50));
			animation->AddFrame("./sprite/wybuchAnimacja/blast5.png", sf::milliseconds(50));
			animation->AddFrame("./sprite/wybuchAnimacja/blast6.png", sf::milliseconds(50));
			animation->AddFrame("./sprite/wybuchAnimacja/blast7.png", sf::milliseconds(50));
			animation->AddFrame("./sprite/wybuchAnimacja/blast8.png", sf::milliseconds(50));
			animation->AddFrame("./sprite/wybuchAnimacja/blast9.png", sf::milliseconds(50));
			animation->AddFrame("./sprite/wybuchAnimacja/blast10.png", sf::milliseconds(50));
			animation->AddFrame("./sprite/wybuchAnimacja/blast11.png", sf::milliseconds(50));
			animation->AddFrame("./sprite/wybuchAnimacja/blast12.png", sf::milliseconds(50));
			animation->AddFrame("./sprite/wybuchAnimacja/blast13.png", sf::milliseconds(50));
			animation->setAnimateOnce(true);
			this->sprite.AddAnimation(animation);
			
		}*/
		//this->sprite.ActiveAnimation("pocisk");
	}

	Bullet::~Bullet(){

	}

	void Bullet::draw(){

		this->sprite.getSprite()->setPosition(this->getScreenPosition().x, this->getScreenPosition().y);
		DataContainer::window->draw(*(this->sprite.getSprite()));
	}

	void Bullet::update(){
		
		if( (pow(this->getMapPosition().x - ownerPosition.x, 2) + pow(this->getMapPosition().y - ownerPosition.y, 2)) <= pow(this->range, 2)){

			this->setMapPosition(CalcNewPosition());
			
			this->activity = true;
			cout << "x: " << this->getMapPosition().x << "\ty: " << this->getMapPosition().y << endl;
		}
		else{
			if(this->blastFire){
				//Blast();
				this->blastFire = false;
			}
			this->activity = false;

		}
		this->sprite.getSprite()->setOrigin(this->sprite.getSprite()->getTexture()->getSize().x/2,this->sprite.getSprite()->getTexture()->getSize().y/2 );
		this->sprite.getSprite()->setRotation(this->angle.getDegrees()-180);
		
	}

	void Bullet::Blast(){
		this->sprite.getSprite()->setPosition(this->getScreenPosition().x, this->getScreenPosition().y);
		DataContainer::window->draw(*(this->sprite.getSprite()));
		this->getSprite().getAnimation("wybuch")->start();

	}

	void Bullet::Hit(){

	}

	Point Bullet::CalcNewPosition(){

		Point newPosition = this->getMapPosition();
        SSJ::Degrees tempDegrees = this->angle;
		double s = this->velocity *100 * DataContainer::DeltaTime.asSeconds();
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