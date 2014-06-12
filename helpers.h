#ifndef HELPERS_H
#define HELPERS_H
#include "datacontainer.h"
#include <string>
#include <sstream>
#include <typeinfo>
using namespace  std;


namespace SSJ{
    class Helpers{
    public:
      static Point getOnScreenPosition(Point);
      static bool isInScreen(Point);
      static Point getOnScreenPosition(float x, float y);
      static bool isInScreen(float x, float y);
      static bool checkCollision(sf::Rect<float> a, sf::Rect<float> b);
      template <typename T>
      char * compressData(T data);
      template <typename T>
      T decompressData(char * data);
    };
}
#endif // HELPERS_H
