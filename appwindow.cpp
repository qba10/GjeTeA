#include "appwindow.h"

namespace SSJ{
    AppWindow::AppWindow()
    {
        this->appWindow = new sf::RenderWindow( sf::VideoMode( Config::ScreenWidth, Config::ScreenHeight, 32 ), "GjeTeA" );
        this->Clock.restart();


    }
    void AppWindow::Update(){
        this->Delta = this->Clock.getElapsedTime();
		this->Clock.restart();
        Config::DeltaTime = this->Delta;

        for(size_t i = 0 ; i < this->GameLayers.size(); i++){
            if(this->GameLayers.at(i)->isDynamic()){
                this->GameLayers.at(i)->UpdateLayer();
            }
        }
    }

    void AppWindow::Draw(){
		appWindow->clear(sf::Color::Black);
		//sf::RectangleShape rectangle(sf::Vector2f(120, 50));

        for(size_t i = 0 ; i < this->GameLayers.size(); i++){
                this->GameLayers.at(i)->DrawLayer();
        }
    }


    void AppWindow::Events(){
        while(this->appWindow->pollEvent(this->event)){
            if(this->event.type == sf::Event::Closed){
                this->appWindow->close();
            }
            for(size_t i = 0 ; i < Config::EventList.size(); i++){
                if(this->event.type == Config::EventList.at(i).EventType){
					if(this->event.type == sf::Event::KeyPressed || this->event.type == sf::Event::KeyReleased){
						if(Config::EventList.at(i).KeyAction != sf::Keyboard::Unknown && Config::EventList.at(i).KeyAction == this->event.key.code)
							((Config::EventList.at(i).object)->*(Config::EventList.at(i).ActionFunction))(this->event);
					}else{
						    ((Config::EventList.at(i).object)->*(Config::EventList.at(i).ActionFunction))(this->event);
					}
						

                }
            }

        }
    }

    void AppWindow::LoadObjects(){

    }

    void AppWindow::AddLayer(GameLayer *gameLayer){
        this->GameLayers.push_back(gameLayer);
    }
}
