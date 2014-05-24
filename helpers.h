#ifndef HELPERS_H
#define HELPERS_H
#include "datacontainer.h"
namespace SSJ{
    class Helpers{
    public:
      static Point getOnScreenPosition(Point);
      static bool isInScreen(Point);
      static Point getOnScreenPosition(double x, double y);
      static bool isInScreen(double x, double y);
    };
}
#endif // HELPERS_H
