#include "sprite.h"
namespace SSJ {

    Sprite::Sprite()
    {
        this->defaultTexture = "null";
        this->sprite = new sf::Sprite;
    }



    sf::Sprite* Sprite::getSprite() const
    {
        return sprite;
    }


    void Sprite::AddTexture(string key, string path){
        sf::Texture * tempTexture = new sf::Texture;
        sf::Image img;



        if(!img.loadFromFile(path)){
            throw "File " + path + " doesn't exist";
            cout << "Failed load texture" + path << endl;
        }
        img.createMaskFromColor(sf::Color::Black, 0);
        tempTexture->loadFromImage(img);

        this->textures[key] = tempTexture;
        if(this->textures.size() == 1){
            this->sprite->setTexture(*tempTexture);

            this->defaultTexture = key;
        }


    }
}
