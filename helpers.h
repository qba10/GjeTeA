#ifndef HELPERS_H
#define HELPERS_H
#include "datacontainer.h"
#include <string>
#include <sstream>
#include <typeinfo>
using namespace  std;


namespace SSJ{
    template <typename T>
    const char * compressData(T data)  {
        cout <<"c: "<< data << endl;
        char * result = new char[sizeof(T)+1];
        result[sizeof(T)] = '\0';
        T* pointerTyep = &data;
        char * charPointer =  (char*) pointerTyep;
        for(int i = 0; i < sizeof(T); i++){
            result[i] += *(charPointer+i);
        }

        return result;

    }
    template <typename T>
    T decompressData(const char * data)  {
        T *result = new T;
        char * pointerType = (char*) result;
        for(int i = 0; i < sizeof(T); i++){
            *(pointerType+i) = data[i] ;
        }
        result = (T*) pointerType;
        return *result;

    }
    class Helpers{
    public:
      static Point getOnScreenPosition(Point);
      static bool isInScreen(Point);
      static Point getOnScreenPosition(float x, float y);
      static bool isInScreen(float x, float y);
      static bool checkCollision(sf::Rect<float> a, sf::Rect<float> b);

    };
}
#endif // HELPERS_H
