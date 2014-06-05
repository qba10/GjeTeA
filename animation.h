#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
namespace SSJ {


    class Animation
    {
    private:
        sf::Time defaultFrameBreakTime;
        vector <sf::Texture*> frames;
        vector <sf::Time> framesBreakTime;
        string animationName;
        int defaultFrame;
        bool smooth;
        sf::Color alphaMask;
        bool alphaMaskSet;
        int currentFrame;
        sf::Clock clock;
        sf::Time stopTime;
        bool stopAnimation;
		bool animateOnce;
    private:
        int getNextFrameIndex();
    public:
        static map <string, Animation*> AnimationContainer;
        static  Animation * getAnimation(string name);
        static void UpdateAllAnimation();
        static void addAnimationToContainer(string, Animation *);
    public:
        Animation(string);
        void AddFrame(const char *, sf::Time = sf::Time::Zero );
		void AddFrame(string path, sf::IntRect clip, sf::Time = sf::Time::Zero );
        sf::Time getDefaultFrameBreakTime() const;
        void setDefaultFrameBreakTime( sf::Time value);
        bool getSmooth() const;
        void setSmooth(bool value);
        sf::Color getAlphaMask() const;
        void setAlphaMask(sf::Color value);
        bool isAlphaMaskSet() ;
        void disableAlphaMask();
        void setDefaultFrame(int);
		void setAnimateOnce(bool);
		bool isAnimateOnce();
    public:
        void start();
        void stop();
        void restart();
        void nextFrame();
        void previousFrame();
        void update();
        sf::Texture* getCurrentFrame();

        string getAnimationName() const;
        void setAnimationName(string value);
    };
}
#endif // ANIMATION_H
