#include "mainplayer.h"
namespace SSJ {
    MainPlayer::MainPlayer(): DynamicObject()
    {

        this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::W,  SLOT(this, MainPlayer::eventMoveForward));
       // this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::S, this->eventMoveBackward);
       // this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::A, this->eventMoveLeft);
       // this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::D, this->eventMoveRight);
    }

    void MainPlayer::eventMoveForward(sf::Event event){
        //this->MoveForward();
        cout << "hej" << endl;
    }

    void MainPlayer::eventMoveBackward(sf::Event event){
        this->MoveBackward();
    }

    void MainPlayer::eventMoveLeft(sf::Event event){
        this->MoveLeft();
    }

    void MainPlayer::eventMoveRight(sf::Event event){
        this->MoveRight();
    }
    void MainPlayer::draw(){

    }

    void MainPlayer::update(){

    }
}

