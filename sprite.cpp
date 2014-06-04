#include "sprite.h"
namespace SSJ {

    vector <Sprite *> Sprite::allSprites;

    Sprite::Sprite()
    {

        this->defaultTexture = "null";
        this->sprite = new sf::Sprite;
        this->alphaMaksSet = false;
        this->smooth = false;
        activeAnimation = "*";
        this->activeTexture = "*";
        Sprite::allSprites.push_back(this);

    }
    void Sprite::Update(){
        if(activeAnimation != "*"){
            this->sprite->setTexture(*(this->animations.at(this->activeAnimation)->getCurrentFrame()));
        }else if(this->activeTexture != "*"){
            this->sprite->setTexture(*(this->textures.at(this->activeTexture)));
        }

    }



    sf::Sprite* Sprite::getSprite() const
    {
        return sprite;
    }

	void Sprite::setSprite(sf::Sprite sprite)
	{
		this->sprite = new sf::Sprite(sprite);
	}


    bool Sprite::getSmooth() const
    {
        return smooth;
    }

    void Sprite::setSmooth(bool value)
    {
        smooth = value;
    }

    sf::Color Sprite::getAlphaMaks() const
    {
        return alphaMaks;
    }

    void Sprite::setAlphaMaks(const sf::Color &value)
    {
        this->alphaMaksSet = true;
        this->alphaMaks = value;
    }

    void Sprite::updateAllSprites()
    {

        for(int i = 0 ; i < Sprite::allSprites.size(); i++)
                Sprite::allSprites.at(i)->Update();
    }

    void Sprite::AddTexture(string key, string path){
        sf::Texture * tempTexture = new sf::Texture;
        sf::Image img;



        if(!img.loadFromFile(path)){
            cout << "Failed load texture" + path << endl;
        }
        if(this->alphaMaksSet)
            img.createMaskFromColor(this->getAlphaMaks(), 0);


        tempTexture->loadFromImage(img);

        tempTexture->setSmooth(this->smooth);

        this->textures[key] = tempTexture;
        if(this->textures.size() == 1){
            this->sprite->setTexture(*tempTexture);
            this->activeTexture = key;
            this->defaultTexture = key;
            this->AnyTextureActive = true;
        }


    }
	void Sprite::AddTexture(string key, sf::Texture* texture, sf::IntRect clip){

        this->textures[key] = texture;
        if(this->textures.size() == 1){
            this->sprite->setTexture(*texture);
			this->sprite->setTextureRect(clip);
            this->activeTexture = key;
            this->defaultTexture = key;
            this->AnyTextureActive = true;
        }


    }

    void Sprite::AddAnimation(Animation * animation)
    {
        this->animations[animation->getAnimationName()] = animation;
    }

    void Sprite::ActiveAnimation(string name)
    {
        activeAnimation = name;
    }

    void Sprite::setTexture(string name)
    {
        this->AnyTextureActive = true;
        this->activeTexture = name;
        this->sprite->setTexture(*(this->textures.at(name)));
    }

    bool Sprite::isAnyTextureActive()
    {
        return this->AnyTextureActive;
    }

    Animation* Sprite::getAnimation(string name)
    {
        return this -> animations.at(name);
    }
}
