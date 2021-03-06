#include "appwindow.h"

namespace SSJ{
    AppWindow::AppWindow()
    {
        this->appWindow = new sf::RenderWindow( sf::VideoMode( DataContainer::ScreenWidth, DataContainer::ScreenHeight, 32 ), "GjeTeA" );
        this->appWindow->setVerticalSyncEnabled(true);
        this->appWindow->setFramerateLimit(60);
        this->appWindow->setKeyRepeatEnabled(false);

        this->Clock.restart();

        ServerConnectAPI ServerConnect;

        ServerConnectThread = new sf::Thread(&ServerConnectAPI::ServerListener, &ServerConnect);
        ServerConnectThread->launch();

		this->hud = new Hud;
    }

	void AppWindow::AddLayer(GameLayer *gameLayer){
        this->GameLayers.push_back(gameLayer);
    }

	void AppWindow::LoadObjects(){
        ServerApi::AskToCreateMainPlayer();
    }

	void AppWindow::Events(){
        while(this->appWindow->pollEvent(this->event)){
            if(this->event.type == sf::Event::Closed){
                this->appWindow->close();
            }
            for(size_t i = 0 ; i < DataContainer::EventList.size(); i++){
                if(this->event.type == DataContainer::EventList.at(i).EventType){
                    if(this->event.type == sf::Event::KeyPressed || this->event.type == sf::Event::KeyReleased){
                        if(DataContainer::EventList.at(i).KeyAction != sf::Keyboard::Unknown && DataContainer::EventList.at(i).KeyAction == this->event.key.code)
                            ((DataContainer::EventList.at(i).object)->*(DataContainer::EventList.at(i).ActionFunction))(this->event);
					}
					else{
                            ((DataContainer::EventList.at(i).object)->*(DataContainer::EventList.at(i).ActionFunction))(this->event);
                    }
                }
            }
        }
    }

    void AppWindow::Update(){
        Animation::UpdateAllAnimation();
        Sprite::updateAllSprites();
        this->Delta = this->Clock.getElapsedTime();
		this->Clock.restart();
        DataContainer::DeltaTime = this->Delta;

        for(size_t i = 0 ; i < this->GameLayers.size(); i++){
            if(this->GameLayers.at(i)->isDynamic()){
                this->GameLayers.at(i)->UpdateLayer();
            }
        }
		while(!DataContainer::ReqToServer.empty()){
			switch(DataContainer::ReqToServer.front().action){
            case _createBullet:
				ServerApi::AskToCreateBullet(DataContainer::ReqToServer.front().parameters);
				break;
			}
			DataContainer::ReqToServer.pop();
		}

        ServerApi::AskToSynchronizeMainPlayer();
    }

    void AppWindow::Draw(){
		appWindow->clear(sf::Color::Black);
		
        for(size_t i = 0 ; i < this->GameLayers.size(); i++){
                this->GameLayers.at(i)->DrawLayer();
        }
    }
}
