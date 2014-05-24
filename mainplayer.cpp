#include "mainplayer.h"
namespace SSJ {
    MainPlayer::MainPlayer(): DynamicObject()
    {
		this->setMaxHP(100);
		this->setHP(this->getMaxHP());
        this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::W,  SLOT(this, MainPlayer::eventMoveForward));
		this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::S,  SLOT(this, MainPlayer::eventMoveBackward));
		this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::A,  SLOT(this, MainPlayer::eventMoveLeft));
		this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::D,  SLOT(this, MainPlayer::eventMoveRight));
       // this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::S, this->eventMoveBackward);
       // this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::A, this->eventMoveLeft);
       // this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::D, this->eventMoveRight);
    }

    void MainPlayer::eventMoveForward(sf::Event event){
        this->MoveForward();
        cout << "gora" << endl;
    }

    void MainPlayer::eventMoveBackward(sf::Event event){
        this->MoveBackward();
		cout << "dol" << endl;
    }

    void MainPlayer::eventMoveLeft(sf::Event event){
        this->MoveLeft();
		cout << "lewo" << endl;
    }

    void MainPlayer::eventMoveRight(sf::Event event){
        this->MoveRight();
		cout << "prawo" << endl;
    }
    void MainPlayer::draw(){
		
		Point playerPosition = Helpers::getOnScreenPosition(getMapPosition());
		sf::CircleShape shape(20);
		// set the shape color to green
		shape.setPosition(playerPosition.x, playerPosition.y);
		shape.setFillColor(sf::Color(100, 250, 50));
		
		/*printf("x: %f y: %f, screen_x: %f, screen_y: %f, player x: %f, player y: %f\n", playerPosition.x, 
			playerPosition.y, 
			Config::ScreenPosition.x, 
			Config::ScreenPosition.y,
			getMapPosition().x,
			getMapPosition().y);*/
		Config::window->draw(shape);

		Config::ScreenPosition.x = this->getMapPosition().x - Config::ScreenWidth/2;
		Config::ScreenPosition.y = this->getMapPosition().y - Config::ScreenHeight/2;
    }

    void MainPlayer::update(){

    }
}

