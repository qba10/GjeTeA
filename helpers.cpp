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
        objectPosition.x = x - DataContainer::ScreenPosition.x;
        objectPosition.y = y - DataContainer::ScreenPosition.y;
        return objectPosition;
    }

    bool Helpers::isInScreen(double x, double y){
        Point virtualScreen;
        virtualScreen.x = DataContainer::ScreenPosition.x - DataContainer::ScreenMargin;
        virtualScreen.y = DataContainer::ScreenPosition.y - DataContainer::ScreenMargin;
        size_t virtualScreenWidth = DataContainer::ScreenWidth + 2 * DataContainer::ScreenMargin;
        size_t virtualScreenHeight = DataContainer::ScreenHeight + 2 * DataContainer::ScreenMargin;

        if(x <= virtualScreen.x && x >= virtualScreen.x+virtualScreenWidth)
            return false;
        if(y <= virtualScreen.y && y >= virtualScreen.y+virtualScreenHeight)
            return false;

        return true;
    }

	bool Helpers::checkCollision(sf::Rect<double> a, sf::Rect<double> b)
	{
		if(a.left + a.width < b.left)
			return false;
		if(a.top + a.height < b.top )
			return false;
		if(a.left > b.left + b.width)
			return false;
		if(a.top > b.top + b.height)
			return false;
        return true;
    }


}
