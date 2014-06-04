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
        static vector <Sprite *> allSprites;
        map <string, sf::Texture *> textures;
        map <string, Animation *> animations;
        sf::Sprite *sprite;
        string defaultTexture;
        string activeTexture;
        bool smooth;
        sf::Color alphaMaks;
        bool alphaMaksSet;
        string activeAnimation;
        void Update();
        bool AnyTextureActive;
    public:
        static void updateAllSprites();
        void AddTexture(string key, string path);
		void AddTexture(string key, sf::Texture* texture, sf::IntRect clip);
        void AddAnimation(Animation *);
        void ActiveAnimation(string);
        void DeactivateAnimation();
        void setTexture(string);
        bool isAnyTextureActive();

        Animation* getAnimation(string);
        Sprite();

        sf::Sprite *getSprite() const;
		void		setSprite(sf::Sprite sprite);
        bool getSmooth() const;
        void setSmooth(bool value);
        sf::Color getAlphaMaks() const;
        void setAlphaMaks(const sf::Color &value);
    };
}
#endif // SPRITE_H
