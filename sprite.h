#ifndef SPRITE_H
#define SPRITE_H
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>
#include "animation.h"
using namespace std;

namespace SSJ{
    class Sprite
    {
    private:
        
      public:  map <string, sf::Texture *> textures;
        map <string, Animation *> animations;
        sf::Sprite *sprite;
        string defaultTexture;
        string activeTexture;
        bool smooth;
        sf::Color alphaMaks;
        bool alphaMaksSet;
       public: string activeAnimation;
        
        bool AnyTextureActive;
    public:
        static void updateAllSprites();
        void AddTexture(string key, string path);
		void AddTexture(string key, sf::Texture* texture, sf::IntRect clip); // To implement
        void AddAnimation(Animation *);
        void ActiveAnimation(string);
        void DeactivateAnimation();
        void setTexture(string);
        bool isAnyTextureActive();
		static vector <Sprite *> allSprites;
        Animation* getAnimation(string);
        Sprite();
		void Update();

        sf::Sprite *getSprite() ;
		void		setSprite(sf::Sprite sprite);
        bool getSmooth() const;
        void setSmooth(bool value);
        sf::Color getAlphaMaks() const;
        void setAlphaMaks(const sf::Color &value);
    };
}
#endif // SPRITE_H
