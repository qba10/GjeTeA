#include "gamelayer.h"

namespace SSJ{
    string GameLayer::getName() const
    {
        return name;
    }

    void GameLayer::setName( string value)
    {
        name = value;
    }


    bool GameLayer::isDynamic() const
    {
        return dynamic;
    }

    void GameLayer::setDynamic(bool value)
    {
        dynamic = value;
    }
    GameLayer::GameLayer(string name)
    {
        this->name = name;
        this->dynamic = false;
    }

    GameLayer::GameLayer(string name, bool dynamic)
    {
        this->name = name;
        this->dynamic = dynamic;
    }

    void GameLayer::addObject(Object *object){
        this->objects.push_back(object);
    }



    bool GameLayer::isEmpty() const{
        return this->objects.empty();

    }

    void GameLayer::UpdateLayer(){
        for(size_t i = 0 ; i < this->objects.size() ; i++ ){
            if(this->objects.at(i)->isActive())
                this->objects.at(i)->update();
        }
    }

    void GameLayer::DrawLayer(){
        for(size_t i = 0 ; i < this->objects.size() ; i++ ){
            this->objects.at(i)->draw();
        }
    }

    size_t GameLayer::AmountOfObjects(){
        return this->objects.size();
    }
}
