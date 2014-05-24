#ifndef DEGREES_H
#define DEGREES_H
#include <cmath>
#define PI 3.14159265
namespace SSJ {

    class Degrees {
        double degrees;
    public:
        Degrees();
        Degrees(double);
        Degrees(int);
        double getDegrees();
        void operator= (const double &);
        void operator= (const int &);
        void operator-= (const double &);
        void operator-= ( Degrees );
        void operator+= (const double &);
        void operator+= ( Degrees );
        bool operator== (const double &);
        bool operator== (const int &);
        bool operator< (const double &);
        bool operator> (const double &);
        bool operator>= (const double &);
        bool operator<= (const double &);
        Degrees operator+ (const double &);
        Degrees operator+ ( Degrees );
        Degrees &operator- (const double &);
        Degrees &operator- ( Degrees );
        double getRadians();

    };
}

#endif // DEGREES_H
