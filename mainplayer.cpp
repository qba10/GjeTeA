#include "mainplayer.h"
namespace SSJ {


    MainPlayer::MainPlayer() : Player()
    {
        this->setActivity(true);
		this->setMaxHP(100);
        this->velocity = 200.0;
		this->setHP(this->getMaxHP());
		this->isFiring = false;

        this->moveBackward = false;
        this->moveForward = false;
        this->moveLeft = false;
        this->moveRight = false;

		this->currentWeaponIndex = 0;
        this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::W,  SLOT(this, MainPlayer::eventStartMoveForward));
        this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::S,  SLOT(this, MainPlayer::eventStartMoveBackward));
        this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::A,  SLOT(this, MainPlayer::eventStartMoveLeft));
        this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::D,  SLOT(this, MainPlayer::eventStartMoveRight));
        this->AddActionKeyboard(sf::Event::KeyReleased,sf::Keyboard::W,  SLOT(this, MainPlayer::eventStopMoveForward));
        this->AddActionKeyboard(sf::Event::KeyReleased,sf::Keyboard::S,  SLOT(this, MainPlayer::eventStopMoveBackward));
        this->AddActionKeyboard(sf::Event::KeyReleased,sf::Keyboard::A,  SLOT(this, MainPlayer::eventStopMoveLeft));
        this->AddActionKeyboard(sf::Event::KeyReleased,sf::Keyboard::D,  SLOT(this, MainPlayer::eventStopMoveRight));
		this->AddAction(sf::Event::MouseWheelMoved, SLOT(this, MainPlayer::eventMouseWheel));
        this->AddAction(sf::Event::MouseMoved, SLOT(this, MainPlayer::eventMouseMoved));
        this->AddAction(sf::Event::MouseButtonPressed, SLOT(this, MainPlayer::eventMouseButtonPressed));
        this->AddAction(sf::Event::MouseButtonReleased, SLOT(this, MainPlayer::eventMouseButtonReleased));
		this->AddActionKeyboard(sf::Event::KeyPressed, sf::Keyboard::R, SLOT(this, MainPlayer::eventReload));

		WeaponFactory::setOwner(this);
		this->equipWeapon.push_back(WeaponFactory::CreateGlockObject());
		this->equipWeapon.push_back(WeaponFactory::CreateUziObject());
		this->equipWeapon.push_back(WeaponFactory::CreateShotgunObject());
		this->equipWeapon.push_back(WeaponFactory::CreateAk47Object());
		this->equipWeapon.push_back(WeaponFactory::CreateM16Object());
		this->equipWeapon.push_back(WeaponFactory::CreateSniperRifleObject());
		this->equipWeapon.push_back(WeaponFactory::CreateBazookaObject());
				
		this->weapon1 = equipWeapon.at(this->currentWeaponIndex);
		this->weapon1->setIsGettingUsed(true);
		
		for(int i = 0; i < equipWeapon.size(); i++){
			LayerContainer::GetGameLayer("trzecia")->addObject(equipWeapon.at(i));
		}
    }

	void MainPlayer::eventMouseButtonPressed(sf::Event event){
		
        if(event.mouseButton.button == sf::Mouse::Left){
			isFiring = true;
		}
		//else if(event.mouseButton.button == sf::Mouse::Button::Right)
			//cout << "prawy" << endl;
	}

	void MainPlayer::eventMouseButtonReleased(sf::Event event){
		isFiring = false;
	}

	void MainPlayer::eventMouseMoved(sf::Event event){

        float x = (float)(event.mouseMove.x - (float)(DataContainer::ScreenWidth/2));
        float y = (float)(event.mouseMove.y - (float)(DataContainer::ScreenHeight/2));
        float tg = 0.0;
        SSJ::Degrees tanAng = 0.f;
		
		if(x > 0.0 && y > 0.0){
			tg = atan(y / x);
			tanAng = tg * 180.0 / PI;
            this->angle = (float)(90.0 + tanAng.getDegrees());
		}
		else if(x > 0.0 && y < 0.0){
			tg = atan(abs(x) / abs(y));
			tanAng = tg * 180.0 / PI;
			this->angle = tanAng;
		}
		else if(x < 0.0 && y < 0.0){
			tg = atan(abs(y) / abs(x));
			tanAng = tg * 180.0 / PI;
            this->angle = (float)(270.0 + tanAng.getDegrees());
		}
		else if(x < 0.0 && y > 0.0){
			tg = atan(abs(x) / abs(y));
			tanAng = tg * 180.0 / PI;
            this->angle = (float)(180.0 + tanAng.getDegrees());
		}
		else if(x >= 0.0 && y == 0.0)
			this->angle = 90.0;
		else if(x < 0.0 && y == 0.0)
			this->angle = 270.0;
		else if(x == 0.0 && y >= 0.0)
			this->angle = 180.0;
		else if(x == 0 && y < 0.0)
			this->angle = 0.0;
        this->desynchronization = true;

	}

    void MainPlayer::eventStartMoveForward(sf::Event event){
        this->getSprite()->getAnimation("chodzenie")->start();
        this->setMoveForward(true);
    }

    void MainPlayer::eventStartMoveBackward(sf::Event event){
        this->getSprite()->getAnimation("chodzenie")->start();
        this->setMoveBackward(true);
    }

    void MainPlayer::eventStartMoveLeft(sf::Event event){
        this->getSprite()->getAnimation("chodzenie")->start();
        this->setMoveLeft(true);
    }

    void MainPlayer::eventStartMoveRight(sf::Event event){
        this->getSprite()->getAnimation("chodzenie")->start();
        this->setMoveRight(true);
    }

    void MainPlayer::eventStopMoveForward(sf::Event event){
        this->getSprite()->getAnimation("chodzenie")->stop();
        this->setMoveForward(false);
    }

    void MainPlayer::eventStopMoveBackward(sf::Event event){
        this->getSprite()->getAnimation("chodzenie")->stop();
        this->setMoveBackward(false);
    }

    void MainPlayer::eventStopMoveLeft(sf::Event event){
        this->getSprite()->getAnimation("chodzenie")->stop();
        this->setMoveLeft(false);
    }

    void MainPlayer::eventStopMoveRight(sf::Event event){
       this->getSprite()->getAnimation("chodzenie")->stop();
        this->setMoveRight(false);
    }

	void MainPlayer::eventReload(sf::Event event){
		this->weapon1->Reload();
	}

	void MainPlayer::eventMouseWheel(sf::Event event){
		if(this->equipWeapon.size() > 1){
			if(this->equipWeapon.at(this->currentWeaponIndex)->getReloading()){
				this->equipWeapon.at(this->currentWeaponIndex)->setReloading(false);
			}

			this->equipWeapon.at(this->currentWeaponIndex)->setIsGettingUsed(false);

			if(event.mouseWheel.delta > 0){
				if(this->currentWeaponIndex == 0)
					this->currentWeaponIndex = equipWeapon.size() - 1;
				else
					this->currentWeaponIndex--;
			}
			else{
				if(this->currentWeaponIndex == equipWeapon.size() - 1)
					this->currentWeaponIndex = 0;
				else
					this->currentWeaponIndex++;
			}

			this->weapon1 = this->equipWeapon.at(this->currentWeaponIndex);
			this->weapon1->setIsGettingUsed(true);
		}
	}


	bool MainPlayer::getMoveLeft() const
    {
        return moveLeft;
    }

    void MainPlayer::setMoveLeft(const bool value)
    {
        moveLeft = value;
    }

    bool MainPlayer::getMoveRight() const
    {
        return moveRight;
    }

    void MainPlayer::setMoveRight(const bool value)
    {

        moveRight = value;
    }

    bool MainPlayer::getMoveForward() const
    {
        return moveForward;
    }

    void MainPlayer::setMoveForward(const bool value)
    {
        moveForward = value;
    }

    bool MainPlayer::getMoveBackward() const
    {
        return moveBackward;
    }

    void MainPlayer::setMoveBackward(const bool value)
    {
        moveBackward = value;
    }


    void MainPlayer::draw(){
        DataContainer::window->draw(*(this->sprite.getSprite()));
    }

    void MainPlayer::update(){
       // this->setHP(0);
       // if(this->getHP() <= 0 ){
       //  this->getSprite()->activeAnimation = "*";
         // this->getSprite()->setTexture("dead");
        // }
        this->getSprite()->Update();
        this->sprite.getSprite()->setScale(2.f,2.f);

		this->weapon1->setMapPosition(this->getMapPosition());

        if(moveBackward)
            this->MoveBackward();
        if(moveLeft)
            this->MoveLeft();
        if(moveRight)
            this->MoveRight();
        if(moveForward)
            this->MoveForward();
		if(isFiring){
			weapon1->Shoot();	
			if(!weapon1->getRepeatFire()){
				isFiring = false;
			}
		}

       this->sprite.getSprite()->setOrigin(this->sprite.getSprite()->getTexture()->getSize().x/2,this->sprite.getSprite()->getTexture()->getSize().y/2 );
       this->sprite.getSprite()->setRotation(this->angle.getDegrees()-180);

       DataContainer::ScreenPosition.x = this->getMapPosition().x+this->sprite.getSprite()->getOrigin().x - (DataContainer::ScreenWidth)/2;
       DataContainer::ScreenPosition.y = this->getMapPosition().y+this->sprite.getSprite()->getOrigin().y - (DataContainer::ScreenHeight)/2;

       this->sprite.getSprite()->setPosition(this->getScreenPosition().x, this->getScreenPosition().y);
    }

	Weapon* MainPlayer::getWeapon1(){
		return this->weapon1;
	}

	Weapon* MainPlayer::getSelectedWeapon(int number) const{
		int tmp = number;
		
		if(tmp >= 0)
			return this->equipWeapon.at( (this->currentWeaponIndex + tmp) % this->equipWeapon.size() );
		else{
			if((abs(tmp) % this->equipWeapon.size()) <= this->currentWeaponIndex)
				return this->equipWeapon.at(this->currentWeaponIndex + tmp);
			else
				return this->equipWeapon.at( this->equipWeapon.size() - ((abs(tmp) % this->equipWeapon.size()) - this->currentWeaponIndex) );
		}
	}


    void MainPlayer::SynchronizationObject(Json::Value jsonObject)
    {
        if(jsonObject.isMember(_J(_mapPositionX))){
            this->mapPosition.x = jsonObject[_J(_mapPositionX)].asFloat();
        }
        if(jsonObject.isMember(_J(_mapPositionY))){
            this->mapPosition.y = jsonObject[_J(_mapPositionY)].asFloat();
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
            this->angle = jsonObject[_J(_angle)].asFloat();
        }
        if(jsonObject.isMember(_J(_targetAngle))){
            this->targetAngle = jsonObject[_J(_targetAngle)].asFloat();
        }
		if(jsonObject.isMember(_J(_syncId))){
			this->syncId = jsonObject[_J(_syncId)].asInt();
        }

    }

    Json::Value MainPlayer::SerializeMainPlayer()
    {
        Json::Value object;
           object[_J(_mapPositionX)] =  this->getMapPosition().x;
           object[_J(_mapPositionY)] =  this->getMapPosition().y;
           object[_J(_activity)] = this->activity;
           object[_J(_hp)] = (unsigned int)this->getHP();
           object[_J(_maxHP)] = (unsigned int)this->getMaxHP();
           object[_J(_velocity)] = (unsigned int)this->velocity;
           object[_J(_angle)] = this->getAngle().getDegrees();
           object[_J(_targetAngle)] = this->targetAngle.getDegrees();

           this->desynchronization = false;
        return object;
    }

}

