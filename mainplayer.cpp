#include "mainplayer.h"
namespace SSJ {


    MainPlayer::MainPlayer(): DynamicObject()
    {
        this->setActivity(true);
		this->setMaxHP(100);
        this->velocity = 100.0;
		this->setHP(this->getMaxHP());

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
		

		Config::window->draw(shape);

		Config::ScreenPosition.x = this->getMapPosition().x - Config::ScreenWidth/2;
		Config::ScreenPosition.y = this->getMapPosition().y - Config::ScreenHeight/2;
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
    }
}

