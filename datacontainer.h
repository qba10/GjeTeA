#ifndef DATACONTAINER_H
#define DATACONTAINER_H
#include "config.h"

namespace SSJ {


    class DataContainer
    {
    public:
        static Point ScreenPosition;
        static size_t ScreenHeight;
        static size_t ScreenWidth;
        static size_t ScreenMargin;
        static vector <Event> EventList;
        static vector <Object*> ObjectLists;
        static sf::Time DeltaTime;
        static sf::RenderWindow *window;
    };
}
#endif // DATACONTAINER_H
