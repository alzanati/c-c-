#include <iostream>
#include "FactoryMethod.h"

using namespace DesignPatterns::FactoryMethod;

int main(int argc, char *argv[])
{
    SavingsAcctFactory* savings = new SavingsAcctFactory();
    try {
        auto account = savings->GetSavingsAccount("CITyI");
        std::cout << account->ToString().c_str() << std::endl;
    } catch (DesignPatterns::NoImplementationException* ex) {
        std::cout << ex->what() << std::endl;
    }


    return 0;
}
