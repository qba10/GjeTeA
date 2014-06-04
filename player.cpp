#include "player.h"
namespace SSJ {

    Player::Player():DynamicObject()
    {
        this->setActivity(true);
        this->setMaxHP(100);
        this->velocity = 200.0;
        this->setHP(this->getMaxHP());
        this->isFiring = false;

        Animation * animation = new Animation("chodzenie");
        animation->setAlphaMask(sf::Color::Magenta);
        //animation->setSmooth(true);
       // animation->setDefaultFrameBreakTime(sf::milliseconds(300));
        animation->setDefaultFrame(0);
        animation->AddFrame("./sprite/mainPlayerChodzenie/mainChodzenie1.png");
        animation->AddFrame("./sprite/mainPlayerChodzenie/mainChodzenie2.png");
        animation->AddFrame("./sprite/mainPlayerChodzenie/mainChodzenie3.png");
        animation->AddFrame("./sprite/mainPlayerChodzenie/mainChodzenie4.png");
        animation->AddFrame("./sprite/mainPlayerChodzenie/mainChodzenie5.png");
        this->sprite.AddAnimation(animation);
        this->sprite.ActiveAnimation("chodzenie");

    }

    void Player::draw()
    {
        DataContainer::window->draw(*(this->sprite.getSprite()));
    }

    void Player::update()
    {
        this->sprite.getSprite()->setScale(2.f,2.f);
        this->sprite.getSprite()->setOrigin(this->sprite.getSprite()->getTexture()->getSize().x/2,this->sprite.getSprite()->getTexture()->getSize().y/2 );
        this->sprite.getSprite()->setRotation(this->angle.getDegrees()-180);
        this->sprite.getSprite()->setPosition(this->getScreenPosition().x, this->getScreenPosition().y);


    }
    void Player::SynchronizationObject(Json::Value jsonObject)
    {
        if(jsonObject.isMember("mapPositionX")){
            this->mapPosition.x = jsonObject["mapPositionX"].asDouble();
        }
        if(jsonObject.isMember("mapPositionY")){
            this->mapPosition.y = jsonObject["mapPositionY"].asDouble();
        }
        if(jsonObject.isMember("activity")){
            this->activity = jsonObject["activity"].asBool();
        }
        if(jsonObject.isMember("hp")){
            this->hp = jsonObject["hp"].asUInt();
        }
        if(jsonObject.isMember("maxHP")){
            this->maxHP = jsonObject["maxHP"].asUInt();
        }
        if(jsonObject.isMember("velocity")){
            this->velocity = jsonObject["velocity"].asUInt();
        }
        if(jsonObject.isMember("angle")){
            this->angle = jsonObject["angle"].asDouble();
        }
        if(jsonObject.isMember("targetAngle")){
            this->targetAngle = jsonObject["targetAngle"].asDouble();
        }

    }

}
