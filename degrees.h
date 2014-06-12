#ifndef DEGREES_H
#define DEGREES_H
#include <cmath>
#define PI 3.14159265
namespace SSJ {

    class Degrees {
        float degrees;
    public:
        Degrees();
        Degrees(float);
        Degrees(int);
        float getDegrees();
        void operator= (const float &);
        void operator-= (const float &);
        void operator-= ( Degrees );
        void operator+= (const float &);
        void operator+= ( Degrees );
        bool operator== (const float &);
        bool operator== (const int &);
        bool operator< (const float &);
        bool operator> (const float &);
        bool operator>= (const float &);
        bool operator<= (const float &);
        Degrees operator+ (const float &);
        Degrees operator+ ( Degrees );
        Degrees &operator- (const float &);
        Degrees &operator- ( Degrees );
        float getRadians();

    };
}

#endif // DEGREES_H
