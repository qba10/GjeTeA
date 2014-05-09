#include "helpers.h"
namespace SSJ {


    Point Helpers::getOnScreenPosition(Point position){
        return Helpers::getOnScreenPosition(position.x, position.y);
    }

    bool Helpers::isInScreen(Point position){
        return Helpers::isInScreen(position.x, position.y);
    }

    Point Helpers::getOnScreenPosition(double x, double y){
        Point objectPosition;
        objectPosition.x = x - Config::ScreenPosition.x;
        objectPosition.y = y - Config::ScreenPosition.y;
        return objectPosition;

    }

    bool Helpers::isInScreen(double x, double y){
        Point virtualScreen;
        virtualScreen.x = Config::ScreenPosition.x - Config::ScreenMargin;
        virtualScreen.y = Config::ScreenPosition.y - Config::ScreenMargin;
        size_t virtualScreenWidth = Config::ScreenWidth + 2 * Config::ScreenMargin;
        size_t virtualScreenHeight = Config::ScreenHeight + 2 * Config::ScreenMargin;


        if(x <= virtualScreen.x && x >= virtualScreen.x+virtualScreenWidth)
            return false;
        if(y <= virtualScreen.y && y >= virtualScreen.y+virtualScreenHeight)
            return false;

        return true;
    }
}
