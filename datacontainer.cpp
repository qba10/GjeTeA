#include "datacontainer.h"
namespace SSJ {
    size_t DataContainer::ScreenHeight;
    Point DataContainer::ScreenPosition;
    size_t DataContainer::ScreenWidth;
    size_t DataContainer::ScreenMargin;
    vector <Event> DataContainer::EventList;
    sf::Time DataContainer::DeltaTime;
    sf::RenderWindow* DataContainer::window;
    vector <Object*> DataContainer::ObjectLists;
    sf::Mutex DataContainer::mutex;
    sf::Mutex DataContainer::SendMutex;
    Object * DataContainer::MainPlayer = NULL;



}
