#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <exception>

namespace Exceptions {

class NoImplementationException : public std::exception{

public:
    virtual const char* what() const throw () {
        return "No Implementation Exception";
    }
};
    
}

#endif