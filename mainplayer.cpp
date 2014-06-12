#include "mainplayer.h"
namespace SSJ {


    MainPlayer::MainPlayer(): Player()
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


        Animation * animation = new Animation("chodzenie");
        animation->setAlphaMask(sf::Color::Magenta);
        //animation->setSmooth(true);
       // animation->setDefaultFrameBreakTime(sf::milliseconds(300));
        animation->setDefaultFrame(0);
        animation->AddFrame("./sprite/mainPlayerChodzenie/mainChodzenie1.png");
        animation->AddFrame("./sprite/mainPlayerChodzenie/mainChodzenie2.png");
        animation->AddFrame("./sprite/mainPlayerChodzenie/mainChodzenie3.png");
        animation->AddFrame("./sprite/mainPlayerChodzenie/mainChodzenie4.png");
        animation->AddFrame("./sprite/mainPlayerChodzenie/mainChodzenie5.png");
		animation->AddFrame("./sprite/mainPlayerChodzenie/mainChodzenie2.png");
		animation->setAnimateOnce(false);
        this->sprite.AddAnimation(animation);
        this->sprite.ActiveAnimation("chodzenie");

        
        //this->sprite.setSmooth(true);
        //this->sprite.setAlphaMaks(sf::Color::Black);
       //



        this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::W,  SLOT(this, MainPlayer::eventStartMoveForward));
        this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::S,  SLOT(this, MainPlayer::eventStartMoveBackward));
        this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::A,  SLOT(this, MainPlayer::eventStartMoveLeft));
        this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::D,  SLOT(this, MainPlayer::eventStartMoveRight));
        this->AddActionKeyboard(sf::Event::KeyReleased,sf::Keyboard::W,  SLOT(this, MainPlayer::eventStopMoveForward));
        this->AddActionKeyboard(sf::Event::KeyReleased,sf::Keyboard::S,  SLOT(this, MainPlayer::eventStopMoveBackward));
        this->AddActionKeyboard(sf::Event::KeyReleased,sf::Keyboard::A,  SLOT(this, MainPlayer::eventStopMoveLeft));
        this->AddActionKeyboard(sf::Event::KeyReleased,sf::Keyboard::D,  SLOT(this, MainPlayer::eventStopMoveRight));
        this->AddAction(sf::Event::MouseMoved, SLOT(this, MainPlayer::eventMouseMoved));
        this->AddAction(sf::Event::MouseButtonPressed, SLOT(this, MainPlayer::eventMouseButtonPressed));
        this->AddAction(sf::Event::MouseButtonReleased, SLOT(this, MainPlayer::eventMouseButtonReleased));
		this->AddActionKeyboard(sf::Event::KeyPressed, sf::Keyboard::R, SLOT(this, MainPlayer::eventReload));

		WeaponFactory::setOwner(this);
		this->weapon1 = WeaponFactory::CreateUziObject();
		LayerContainer::GetGameLayer("trzecia")->addObject(weapon1);
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

	void MainPlayer::eventReload(sf::Event event){
		this->weapon1->Reload();
	}


	void MainPlayer::eventMouseMoved(sf::Event event){

		double x = (double)(event.mouseMove.x - (double)(DataContainer::ScreenWidth/2));
		double y = (double)(event.mouseMove.y - (double)(DataContainer::ScreenHeight/2));
		double tg = 0.0;
		SSJ::Degrees tanAng = 0.0;
		
		if(x > 0.0 && y > 0.0){
			tg = atan(y / x);
			tanAng = tg * 180.0 / PI;
			this->angle = (double)(90.0 + tanAng.getDegrees());
		}
		else if(x > 0.0 && y < 0.0){
			tg = atan(abs(x) / abs(y));
			tanAng = tg * 180.0 / PI;
			this->angle = tanAng;
		}
		else if(x < 0.0 && y < 0.0){
			tg = atan(abs(y) / abs(x));
			tanAng = tg * 180.0 / PI;
			this->angle = (double)(270.0 + tanAng.getDegrees());
		}
		else if(x < 0.0 && y > 0.0){
			tg = atan(abs(x) / abs(y));
			tanAng = tg * 180.0 / PI;
			this->angle = (double)(180.0 + tanAng.getDegrees());
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
        this->getSprite().getAnimation("chodzenie")->start();
        this->setMoveForward(true);
    }

    void MainPlayer::eventStartMoveBackward(sf::Event event){
        this->getSprite().getAnimation("chodzenie")->start();
        this->setMoveBackward(true);
    }

    void MainPlayer::eventStartMoveLeft(sf::Event event){
        this->getSprite().getAnimation("chodzenie")->start();
        this->setMoveLeft(true);
    }

    void MainPlayer::eventStartMoveRight(sf::Event event){
        this->getSprite().getAnimation("chodzenie")->start();
        this->setMoveRight(true);
    }

    void MainPlayer::eventStopMoveForward(sf::Event event){
        this->getSprite().getAnimation("chodzenie")->stop();
        this->setMoveForward(false);
    }

    void MainPlayer::eventStopMoveBackward(sf::Event event){
        this->getSprite().getAnimation("chodzenie")->stop();
        this->setMoveBackward(false);
    }

    void MainPlayer::eventStopMoveLeft(sf::Event event){
        this->getSprite().getAnimation("chodzenie")->stop();
        this->setMoveLeft(false);
    }

    void MainPlayer::eventStopMoveRight(sf::Event event){
       this->getSprite().getAnimation("chodzenie")->stop();
        this->setMoveRight(false);
    }

	Weapon* MainPlayer::getWeapon1(){
		return this->weapon1;
	}


    void MainPlayer::draw(){



        DataContainer::window->draw(*(this->sprite.getSprite()));
    }

    bool MainPlayer::getMoveLeft() const
    {
        return moveLeft;
    }

    void MainPlayer::setMoveLeft(bool value)
    {
        moveLeft = value;
    }

    bool MainPlayer::getMoveRight() const
    {
        return moveRight;
    }

    void MainPlayer::setMoveRight(bool value)
    {

        moveRight = value;
    }

    bool MainPlayer::getMoveForward() const
    {
        return moveForward;
    }

    void MainPlayer::setMoveForward(bool value)
    {
        moveForward = value;
    }

    bool MainPlayer::getMoveBackward() const
    {
        return moveBackward;
    }

    void MainPlayer::setMoveBackward(bool value)
    {
        moveBackward = value;
    }

    void MainPlayer::update(){
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
			if(!weapon1->repeatFire){
				isFiring = false;
			}
		}

       this->sprite.getSprite()->setOrigin(this->sprite.getSprite()->getTexture()->getSize().x/2,this->sprite.getSprite()->getTexture()->getSize().y/2 );
       this->sprite.getSprite()->setRotation(this->angle.getDegrees()-180);

        DataContainer::ScreenPosition.x = this->getMapPosition().x+this->sprite.getSprite()->getOrigin().x - (DataContainer::ScreenWidth)/2;
        DataContainer::ScreenPosition.y = this->getMapPosition().y+this->sprite.getSprite()->getOrigin().y - (DataContainer::ScreenHeight)/2;

        this->sprite.getSprite()->setPosition(this->getScreenPosition().x, this->getScreenPosition().y);


    }
    void MainPlayer::SynchronizationObject(Json::Value jsonObject)
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

