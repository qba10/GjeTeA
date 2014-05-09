#include "sprite.h"
namespace SSJ {

    Sprite::Sprite()
    {
        this->defaultTexture = "null";
    }


    void Sprite::AddTexture(string key, string path){
        sf::Texture * tempTexture = new sf::Texture;
        if(!tempTexture->loadFromFile(path)){
            throw "File " + path + " doesn't exist";
        }
        this->textures[key] = tempTexture;
        if(this->textures.size() == 1){
            this->sprite.setTexture(*tempTexture);
            this->defaultTexture = key;
        }

    }
}
