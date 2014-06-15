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
		sf::RectangleShape hpFrame(sf::Vector2f(25,5));
		hpFrame.setFillColor(sf::Color::Transparent);
		hpFrame.setOutlineColor(sf::Color(Cornflower,120));
		hpFrame.setOutlineThickness(2);
		hpFrame.setPosition(this->sprite.getSprite()->getPosition().x-10, this->sprite.getSprite()->getPosition().y-30);
		DataContainer::window->draw(hpFrame);

		int hp = this->getHP() / 4;
		int lackHp = (this->getMaxHP() / 4) - hp;

		sf::RectangleShape rHp(sf::Vector2f(hp, 5));
		rHp.setFillColor(sf::Color(Cornflower));
		rHp.setPosition(this->sprite.getSprite()->getPosition().x-10, this->sprite.getSprite()->getPosition().y-30);
		DataContainer::window->draw(rHp);

		sf::RectangleShape rLackHp(sf::Vector2f(lackHp, 5));
		rLackHp.setFillColor(sf::Color(Cornflower,60));
		rLackHp.setPosition(this->sprite.getSprite()->getPosition().x-10+hp, this->sprite.getSprite()->getPosition().y-30);
		DataContainer::window->draw(rLackHp);

        DataContainer::window->draw(*(this->sprite.getSprite()));
    }

    void Player::update()
    {
        this->getSprite().Update();
        this->sprite.getSprite()->setScale(2.f,2.f);
        this->sprite.getSprite()->setOrigin(this->sprite.getSprite()->getTexture()->getSize().x/2,this->sprite.getSprite()->getTexture()->getSize().y/2 );
        this->sprite.getSprite()->setRotation(this->angle.getDegrees()-180);
        this->sprite.getSprite()->setPosition(this->getScreenPosition().x, this->getScreenPosition().y);
    }

    void Player::SynchronizationObject(Json::Value jsonObject)
    {
        if(jsonObject.isMember(_J(_mapPositionX))){
            this->mapPosition.x = jsonObject[_J(_mapPositionX)].asFloat();
        }
        if(jsonObject.isMember(_J(_mapPositionY))){
            this->mapPosition.y = jsonObject[_J(_mapPositionY)].asFloat();
        }
        if(jsonObject.isMember(_J(_activity))){
            this->activity = jsonObject[_J(_activity)].asBool();
        }
        if(jsonObject.isMember(_J(_hp))){
            this->hp = jsonObject[_J(_hp)].asUInt();
        }
        if(jsonObject.isMember(_J(_maxHP))){
            this->maxHP = jsonObject[_J(_maxHP)].asUInt();
        }
        if(jsonObject.isMember(_J(_velocity))){
            this->velocity = jsonObject[_J(_velocity)].asUInt();
        }
        if(jsonObject.isMember(_J(_angle))){
            this->angle = jsonObject[_J(_angle)].asFloat();
        }
        if(jsonObject.isMember(_J(_targetAngle))){
            this->targetAngle = jsonObject[_J(_targetAngle)].asFloat();
        }
		if(jsonObject.isMember(_J(_syncId))){
			this->syncId = jsonObject[_J(_syncId)].asInt();
        }
    }

}
