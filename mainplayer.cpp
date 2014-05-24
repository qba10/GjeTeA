#include "mainplayer.h"
namespace SSJ {
    MainPlayer::MainPlayer(): DynamicObject()
    {

        this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::W,  SLOT(this, MainPlayer::eventMoveForward));
        this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::S, SLOT(this, MainPlayer::eventMoveBackward));
        this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::A, SLOT(this, MainPlayer::eventMoveLeft));
        this->AddActionKeyboard(sf::Event::KeyPressed,sf::Keyboard::D, SLOT(this, MainPlayer::eventMoveRight));
    }

    void MainPlayer::eventMoveForward(sf::Event event){
        //this->MoveForward();
        cout << "Forward" << endl;
    }

    void MainPlayer::eventMoveBackward(sf::Event event){
        this->MoveBackward();
        cout << "Backward" << endl;
    }

    void MainPlayer::eventMoveLeft(sf::Event event){
        this->MoveLeft();
        cout << "Left" << endl;

    }

    void MainPlayer::eventMoveRight(sf::Event event){
        this->MoveRight();
        cout << "Right" << endl;
    }
    void MainPlayer::draw(){

    }

    void MainPlayer::update(){

    }
}

