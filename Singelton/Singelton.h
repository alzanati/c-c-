#ifndef SINGELTON
#define SINGELTON
#include "Utility.h"
#include "Exceptions.h"
#include <iostream>
#include <mutex>

namespace DesignPatterns {

namespace Singelton {

class Policy {

public :
    Policy() {

    }

    // only called once across all threads also object is static so created once
    static void initPolicy() {
        _policy = new Policy();
    }

    static Policy* GetInstance() {
        std::call_once(_policyFlag, initPolicy);
        return _policy;
    }

private:
    static Policy* _policy;

    static std::once_flag _policyFlag;
};

Policy* Policy::_policy;

std::once_flag Policy::_policyFlag;

}

}

#endif
