//============================================================================
// Name        : GjeTeA.cpp
// Author      : Piotr Piórkowski, Mateusz Nojek
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "appwindow.h"

void Akcja1(sf::Event event){
    cout << event.key.code << endl;
}


int main()
{
    Json::Value root;
    SSJ::Config::ScreenWidth = 800;
    SSJ::Config::ScreenHeight = 600;
    SSJ::Config::ScreenMargin = 64;

    SSJ::AppWindow *Game  = new SSJ::AppWindow;

    SSJ::GameLayer *pierwsza = new SSJ::GameLayer("pierwszy", true);
    SSJ::MainPlayer *obiekt = new SSJ::MainPlayer();
   // obiekt->AddAction(sf::Event::MouseButtonPressed, Akcja1);
    pierwsza->addObject(obiekt);
    Game->AddLayer(pierwsza);


    Game->LoadObjects();
     while( Game->appWindow->isOpen())
     {
         Game->Events();
         Game->Update();
         Game->Draw();
         Game->appWindow->display();


     }
     return 0;
}
