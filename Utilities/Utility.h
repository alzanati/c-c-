#ifndef UTILITY_H
#define UTILITY_H
#include <string.h>

namespace Utility {

// base utilites
class BaseFactoryObject {

public:
    virtual std::string ToString() = 0;
};
    
}

#endif