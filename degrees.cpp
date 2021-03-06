#include "degrees.h"
namespace SSJ {

    Degrees::Degrees(){
        this->degrees = 0.0;
    }

    Degrees::Degrees(float degrees){
        this->degrees = fabs(fmod(degrees, 360.0));
    }



    void Degrees::operator= (const float & degrees){
        this->degrees = fabs(fmod(degrees, 360.0));
    }



    void Degrees::operator-= (const float & degrees){
        this->degrees -= degrees;
        this->degrees = fabs(fmod(degrees, 360.0));
    }
    void Degrees::operator-= ( Degrees  degrees){
        this->degrees -= degrees.getDegrees();
        this->degrees = fabs(fmod(this->degrees, 360.0));
    }




    void Degrees::operator+= (const float & degrees){
        this->degrees += degrees;
        this->degrees = fabs(fmod(degrees, 360.0));
    }
    void Degrees::operator+= ( Degrees  degrees){
        this->degrees += degrees.getDegrees();
        this->degrees = fabs(fmod(this->degrees, 360.0));
    }




    bool Degrees::operator== (const float & degrees){
       float temp =   fabs(fmod(degrees, 360.0));
        if(this->degrees == temp)
            return true;
        else
            return false;
    }



    bool Degrees::operator< (const float & degrees){
        float temp =   fabs(fmod(degrees, 360.0));
        if(this->degrees < temp)
            return true;
        else
            return false;
    }


    bool Degrees::operator> (const float & degrees){
        float temp =   fabs(fmod(degrees, 360.0));
        if(this->degrees > temp)
            return true;
        else
            return false;
    }


    bool Degrees::operator>= (const float & degrees){
       float temp =   fabs(fmod(degrees, 360.0));
        if(this->degrees >= temp)
            return true;
        else
            return false;
    }



    bool Degrees::operator<= (const float & degrees){
        float temp =   fabs(fmod(degrees, 360.0));
        if(this->degrees <= temp)
            return true;
        else
            return false;
    }

    Degrees Degrees::operator+ (const float & degrees){
		Degrees temp = *this;
        temp += degrees;
        temp.degrees = fabs(fmod(temp.degrees, 360.0));
        return temp ;
    }


    Degrees & Degrees::operator- (const float & degrees){
        this-> degrees -= degrees;
        this->degrees = fabs(fmod(degrees, 360.0));
        return *this;
    }
    Degrees Degrees::operator+ ( Degrees degrees){

         this-> degrees -= degrees.getDegrees();
        this->degrees = fabs(fmod(this->degrees, 360.0));
        return *this ;
    }

    float Degrees::getDegrees(){
        return this->degrees;
    }

    Degrees & Degrees::operator- ( Degrees  degrees){
        this-> degrees -= degrees.getDegrees();
        this->degrees = fabs(fmod(this->degrees, 360.0));
        return *this;
    }



    float Degrees::getRadians(){
        return this->degrees * PI/180.0;
    }


}
