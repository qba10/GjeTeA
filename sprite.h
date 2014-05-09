#ifndef SPRITE_H
#define SPRITE_H
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
using namespace std;

namespace SSJ{
    class Sprite
    {
    private:
        map <string, sf::Texture *> textures;
        sf::Sprite sprite;
        string defaultTexture;
    public:
        void AddTexture(string key, string path);
        Sprite();
    };
}
#endif // SPRITE_H
