#ifndef FACTORYMETHOD
#define FACTORYMETHOD
#include <iostream>
#include <string.h>
#include <exception>

namespace DesignPatterns {

class NoImplementationException : public std::exception{
    const char* what() const throw () {
        return "NoImplementationException";
    }
};

namespace FactoryMethod {

// base utilites
class BaseFactoryObject {

public:
    virtual std::string ToString() = 0;
};


// product
class ISavingsAccount : public BaseFactoryObject {

public:
    virtual void SetBalance(double balance) = 0;

    virtual double GetBalance() = 0;

    virtual std::string ToString() = 0;

protected:
    double Balance;
};


// concrete product
class CitiSavingsAcct : public ISavingsAccount {

public:
    CitiSavingsAcct()
    {
        SetBalance(53255.34);
    }

    void SetBalance(double balance)
    {
        Balance = balance;
    }

    double GetBalance()
    {
        return Balance;
    }

    std::string ToString()
    {
        return "CitiSavingsAcct";
    }
};


// concrete product
class NationalSavingsAcct : public ISavingsAccount {

public:
    NationalSavingsAcct()
    {
        SetBalance(7584.34);
    }

    void SetBalance(double balance)
    {
        Balance = balance;
    }

    double GetBalance()
    {
        return Balance;
    }

    std::string ToString()
    {
        return "NationalSavingsAcct";
    }
};


// creatore
class ICreditUnionFactory {
public:
    virtual ISavingsAccount* GetSavingsAccount(std::string acctNo) = 0;
};

class SavingsAcctFactory : public ICreditUnionFactory {
public:
    ISavingsAccount* GetSavingsAccount (std::string acctNo) {
        if (acctNo == "CITI") {
            return new CitiSavingsAcct();
        }
        else if (acctNo == "NATIONAL") {
            return new NationalSavingsAcct();
        }
        else {
            throw new NoImplementationException();
        }
    }
};

}

}

#endif
