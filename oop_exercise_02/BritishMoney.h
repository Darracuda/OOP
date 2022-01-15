#pragma once
#include <iostream>

using namespace std;

class BritishMoney
{
private:
    unsigned long long pounds;
    unsigned char shillings;
    unsigned char pennies;

public:
    static const unsigned char penniesPerShilling = 12;
    static const unsigned char shillingsPerPound = 20;

    BritishMoney();
    BritishMoney(unsigned long long pounds, unsigned char shillings, unsigned char pennies);

    friend BritishMoney BritishMoneyFromPennies(unsigned long long pennies);
    friend unsigned long long BritishMoneyToPennies(const BritishMoney& money);

    friend BritishMoney operator+ (const BritishMoney& money1, const BritishMoney& money2);
    friend BritishMoney operator- (const BritishMoney& money1, const BritishMoney& money2);
    friend BritishMoney operator* (const BritishMoney& money, const double factor);
    friend BritishMoney operator* (const double factor, const BritishMoney& money);
    friend BritishMoney operator/ (const BritishMoney& money, const double factor);
    friend double operator/ (const BritishMoney& money1, const BritishMoney& money2);

    friend bool operator== (const BritishMoney& money1, const BritishMoney& money2);
    friend bool operator!= (const BritishMoney& money1, const BritishMoney& money2);
    friend bool operator> (const BritishMoney& money1, const BritishMoney& money2);
    friend bool operator>= (const BritishMoney& money1, const BritishMoney& money2);
    friend bool operator< (const BritishMoney& money1, const BritishMoney& money2);
    friend bool operator<= (const BritishMoney& money1, const BritishMoney& money2);

    friend ostream& operator<< (ostream& stream, const BritishMoney& money);
    friend istream& operator>> (istream& stream, BritishMoney& money);
};

BritishMoney operator "" _pound(unsigned long long pounds);
BritishMoney operator "" _shilling(unsigned long long shillings);
BritishMoney operator "" _penny(unsigned long long pennies);
