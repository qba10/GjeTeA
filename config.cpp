#include "config.h"
namespace SSJ {
    size_t Config::RotationSpeed = 360;
    string Config::PlayerId;
    string intToString(int value)
    {
        ostringstream ss;
        ss << value;
        return ss.str();
    }

}

