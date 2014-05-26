#include "mainplayer.h"
namespace SSJ {


    MainPlayer::MainPlayer(): DynamicObject()
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

		WeaponFactory::setOwner(this);
		this->weapon1 = WeaponFactory::CreateAk47Object();

    }

	void MainPlayer::eventMouseButtonPressed(sf::Event event){
		
		if(event.mouseButton.button == sf::Mouse::Button::Left){
			isFiring = true;
		}
		//else if(event.mouseButton.button == sf::Mouse::Button::Right)
			//cout << "prawy" << endl;
	}

	void MainPlayer::eventMouseButtonReleased(sf::Event event){
		isFiring = false;
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
	}

    void MainPlayer::eventStartMoveForward(sf::Event event){
        this->setMoveForward(true);
    }

    void MainPlayer::eventStartMoveBackward(sf::Event event){
        this->setMoveBackward(true);
    }

    void MainPlayer::eventStartMoveLeft(sf::Event event){
        this->setMoveLeft(true);
    }

    void MainPlayer::eventStartMoveRight(sf::Event event){
        this->setMoveRight(true);
    }

    void MainPlayer::eventStopMoveForward(sf::Event event){
        this->setMoveForward(false);
    }

    void MainPlayer::eventStopMoveBackward(sf::Event event){
        this->setMoveBackward(false);
    }

    void MainPlayer::eventStopMoveLeft(sf::Event event){
        this->setMoveLeft(false);
    }

    void MainPlayer::eventStopMoveRight(sf::Event event){
        this->setMoveRight(false);
    }

    void MainPlayer::draw(){
		
		Point playerPosition = Helpers::getOnScreenPosition(getMapPosition());
		sf::CircleShape shape(20);
		// set the shape color to green
		shape.setPosition(playerPosition.x, playerPosition.y);
		shape.setFillColor(sf::Color(100, 250, 50));
		//sf::Texture* teksture = new sf::Texture;
		//teksture->loadFromFile("texture.jpg");
		//shape.setTexture(teksture, true);
        DataContainer::window->draw(shape);

		// dodać wyśrodkowanie gracza na środku ekranu na podstawie grafiki
        DataContainer::ScreenPosition.x = this->getMapPosition().x - DataContainer::ScreenWidth/2;
        DataContainer::ScreenPosition.y = this->getMapPosition().y - DataContainer::ScreenHeight/2;
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
    }
}

