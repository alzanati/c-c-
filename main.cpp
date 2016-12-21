#include <iostream>
#include "FactoryMethod.h"
#include "Singelton.h"
#include <assert.h>

using namespace DesignPatterns::FactoryMethod;

int main(int argc, char *argv[])
{

    // Test FactoryMethod
    SavingsAcctFactory* savings = new SavingsAcctFactory();
    try {
        auto account = savings->GetSavingsAccount("CITI");
        std::cout << account->ToString().c_str() << std::endl;
    }
    catch (DesignPatterns::NoImplementationException* ex) {
        std::cout << ex->what() << std::endl;
    }

    // Test Singelton Pattern
    auto singlePolicy = DesignPatterns::Singelton::Policy::GetInstance();
    auto singlePolicy1 = DesignPatterns::Singelton::Policy::GetInstance();
    assert(singlePolicy == singlePolicy1);
    return 0;
}
