#include <stdexcept>
#include "BritishMoney.h"

BritishMoney::BritishMoney()
{
    this->pounds = 0;
    this->shillings = 0;
    this->pennies = 0;
}

BritishMoney::BritishMoney(unsigned long long pounds, unsigned char shillings, unsigned char pennies)
{
    if (shillings >= shillingsPerPound || pennies >= penniesPerShilling)
        throw std::out_of_range("BritishMoney constructor: invalid values of shillings or pennies");
    this->pounds = pounds;
    this->shillings = shillings;
    this->pennies = pennies;
}

BritishMoney BritishMoneyFromPennies(unsigned long long pennies)
{
    unsigned char pennies2 = pennies % BritishMoney::penniesPerShilling;
    unsigned long long shillings = pennies / BritishMoney::penniesPerShilling;
    unsigned char shillings2 = shillings % BritishMoney::shillingsPerPound;
    unsigned long long pounds = shillings / BritishMoney::shillingsPerPound;

    return BritishMoney(pounds, shillings2, pennies2);
}

unsigned long long BritishMoneyToPennies(const BritishMoney& money)
{
    unsigned long long pennies = (money.pounds * BritishMoney::shillingsPerPound + money.shillings) * BritishMoney::penniesPerShilling + money.pennies;
    return pennies;
}

BritishMoney operator+(const BritishMoney& money1, const BritishMoney& money2)
{
    unsigned long long pennies1 = BritishMoneyToPennies(money1);
    unsigned long long pennies2 = BritishMoneyToPennies(money2);
    unsigned long long pennies3 = pennies1 + pennies2;
    return BritishMoneyFromPennies(pennies3);
}

BritishMoney operator-(const BritishMoney& money1, const BritishMoney& money2)
{
    unsigned long long pennies1 = BritishMoneyToPennies(money1);
    unsigned long long pennies2 = BritishMoneyToPennies(money2);
    if (pennies1 < pennies2)
        throw std::out_of_range("BritishMoney operator-: money1 less than money2");
    unsigned long long pennies3 = pennies1 - pennies2;
    return BritishMoneyFromPennies(pennies3);
}

BritishMoney operator*(const BritishMoney& money, const double factor)
{
    if (factor < 0.0)
        throw std::out_of_range("BritishMoney operator*: second parameter is less than zero");
    unsigned long long pennies = BritishMoneyToPennies(money);
    unsigned long long pennies2 = (unsigned long long)(pennies * factor);
    return BritishMoneyFromPennies(pennies2);
}

BritishMoney operator*(const double factor, const BritishMoney& money)
{
    if (factor < 0.0)
        throw std::out_of_range("BritishMoney operator*: first parameter is less than zero");
    return money * factor;
}

BritishMoney operator/(const BritishMoney& money, const double factor)
{
    if (factor == 0.0)
        throw std::out_of_range("BritishMoney operator/: second parameter is zero or less");

    unsigned long long pennies = BritishMoneyToPennies(money);
    unsigned long long pennies2 = (unsigned long long)(pennies / factor);
    return BritishMoneyFromPennies(pennies2);
}

double operator/(const BritishMoney& money1, const BritishMoney& money2)
{
    unsigned long long pennies1 = BritishMoneyToPennies(money1);
    unsigned long long pennies2 = BritishMoneyToPennies(money2);
    if (pennies2 == 0)
        throw std::out_of_range("BritishMoney operator-: second parameter is zero");
    double factor = (double)pennies1 / (double)pennies2;
    return factor;
}

bool operator==(const BritishMoney& money1, const BritishMoney& money2)
{
    unsigned long long pennies1 = BritishMoneyToPennies(money1);
    unsigned long long pennies2 = BritishMoneyToPennies(money2);
    bool result = pennies1 == pennies2;
    return result;
}

bool operator!=(const BritishMoney& money1, const BritishMoney& money2)
{
    unsigned long long pennies1 = BritishMoneyToPennies(money1);
    unsigned long long pennies2 = BritishMoneyToPennies(money2);
    bool result = pennies1 != pennies2;
    return result;
}

bool operator>(const BritishMoney& money1, const BritishMoney& money2)
{
    unsigned long long pennies1 = BritishMoneyToPennies(money1);
    unsigned long long pennies2 = BritishMoneyToPennies(money2);
    bool result = pennies1 > pennies2;
    return result;
}

bool operator>=(const BritishMoney& money1, const BritishMoney& money2)
{
    unsigned long long pennies1 = BritishMoneyToPennies(money1);
    unsigned long long pennies2 = BritishMoneyToPennies(money2);
    bool result = pennies1 >= pennies2;
    return result;
}

bool operator<(const BritishMoney& money1, const BritishMoney& money2)
{
    unsigned long long pennies1 = BritishMoneyToPennies(money1);
    unsigned long long pennies2 = BritishMoneyToPennies(money2);
    bool result = pennies1 < pennies2;
    return result;
}

bool operator<=(const BritishMoney& money1, const BritishMoney& money2)
{
    unsigned long long pennies1 = BritishMoneyToPennies(money1);
    unsigned long long pennies2 = BritishMoneyToPennies(money2);
    bool result = pennies1 <= pennies2;
    return result;
}

ostream& operator<<(ostream& stream, const BritishMoney& money)
{
    unsigned long long pounds = money.pounds;
    unsigned int shillings = money.shillings;
    unsigned int pennies = money.pennies;

    stream << "(" << pounds << "," << shillings << "," << pennies << ")";
    return stream;
}

istream& operator>>(istream& stream, BritishMoney& money)
{
    unsigned long long pounds;
    unsigned int shillings;
    unsigned int pennies;
    char leftBracket, rightBracket, comma1, comma2;

    stream >> leftBracket >> pounds >> comma1 >> shillings >> comma2 >> pennies >> rightBracket;
    money.pounds = pounds;
    money.shillings = shillings;
    money.pennies = pennies;

    return stream;
}

BritishMoney operator "" _pound(unsigned long long pounds)
{
    unsigned long long shillings = pounds * BritishMoney::shillingsPerPound;
    unsigned long long pennies = shillings * BritishMoney::penniesPerShilling;
    return BritishMoneyFromPennies(pennies);
}

BritishMoney operator "" _shilling(unsigned long long shillings)
{
    unsigned long long pennies = shillings * BritishMoney::penniesPerShilling;
    return BritishMoneyFromPennies(pennies);
}

BritishMoney operator ""_penny(unsigned long long pennies)
{
    return BritishMoneyFromPennies(pennies);
}
