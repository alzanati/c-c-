#include <iostream>
#include "FactoryMethod.h"

using namespace DesignPatterns::FactoryMethod;

int main(int argc, char *argv[])
{
    SavingsAcctFactory* savings = new SavingsAcctFactory();
    auto account = savings->GetSavingsAccount("CITI");
    std::cout << account->ToString().c_str() << std::endl;
    return 0;
}
