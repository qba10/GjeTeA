#include "animation.h"
namespace SSJ {

    map <string, Animation*> Animation::AnimationContainer;

    bool Animation::getSmooth() const
    {
        return smooth;
    }

    void Animation::setSmooth(bool value)
    {
        smooth = value;
    }

    sf::Color Animation::getAlphaMask() const
    {
        return alphaMask;
    }

    void Animation::setAlphaMask(sf::Color value)
    {
        this->alphaMaskSet = true;
        alphaMask = value;
    }

    bool Animation::isAlphaMaskSet()
    {
        return alphaMaskSet;
    }

    void Animation::disableAlphaMask()
    {
        alphaMaskSet = false;
    }

    void Animation::setDefaultFrame(int id)
    {
        this->defaultFrame = id;
    }

    void Animation::start()
    {
        this->clock.restart();
       if(!this->stopAnimation)
       {
            this->currentFrame = 0;
       }
       this->stopAnimation = false;



    }

    void Animation::restart(){
        this->clock.restart();
        this->currentFrame = 0;

    }

    void Animation::nextFrame()
    {
        this->currentFrame = this->getNextFrameIndex();
    }

    void Animation::previousFrame()
    {
        if(this->currentFrame == 0 )
            this->currentFrame = this->frames.size()-1;
        else
            this->currentFrame--;
    }

    void Animation::stop()
    {
        this->currentFrame = this->defaultFrame;
        this->stopAnimation = true;
    }

    void Animation::update()
    {
        if(!this->stopAnimation){

           sf::Time checkTime = this->clock.getElapsedTime();
           if(checkTime.asMilliseconds() > this->framesBreakTime.at(this->getNextFrameIndex()).asMilliseconds()){
               this->nextFrame();
               this->clock.restart();

           }
        }
    }

    sf::Texture* Animation::getCurrentFrame()
    {
        return this->frames.at(this->currentFrame);
    }


    string Animation::getAnimationName() const
    {
        return animationName;
    }

    void Animation::setAnimationName(string value)
    {
        animationName = value;
    }
    int Animation::getNextFrameIndex()
    {
        if(this->frames.size()-1 == (unsigned int) this->currentFrame)
            return 0;
        else
            return this->currentFrame+1;

    }

    Animation::Animation(string animtionName)
    {
        Animation::AnimationContainer[animationName] = this;
        this->animationName = animtionName;
        this->stopAnimation = true;
        this->currentFrame = 0;
        this->smooth = false;
        this->alphaMaskSet = false;
        this->defaultFrameBreakTime = sf::milliseconds(100);

    }

    void Animation::AddFrame(const char * path, sf::Time timeBreak  )
    {

        sf::Texture * tempTexture = new sf::Texture;
        sf::Image img;

        if(!img.loadFromFile(path))
            cout << "Failed load texture" << path << endl;

        if(this->alphaMaskSet)
            img.createMaskFromColor(this->getAlphaMask(), 0);

        tempTexture->loadFromImage(img);

        tempTexture->setSmooth(this->smooth);

        this->frames.push_back(tempTexture);

        if(timeBreak == sf::Time::Zero)
            this->framesBreakTime.push_back(this->defaultFrameBreakTime);
        else
            this->framesBreakTime.push_back(timeBreak);

    }

    Animation * Animation::getAnimation(string name)
    {
        return Animation::AnimationContainer[name];
    }

    void Animation::UpdateAllAnimation()
    {
        map<string,Animation*>::iterator it;
        for ( it=Animation::AnimationContainer.begin(); it!=Animation::AnimationContainer.end(); ++it)
          it->second->update();
    }

    void addAnimationToContainer(string name, Animation * animation)
    {
        Animation::AnimationContainer[name] = animation;
    }

    sf::Time Animation::getDefaultFrameBreakTime() const
    {
        return defaultFrameBreakTime;
    }

    void Animation::setDefaultFrameBreakTime(sf::Time value)
    {
        defaultFrameBreakTime = value;
    }

}
