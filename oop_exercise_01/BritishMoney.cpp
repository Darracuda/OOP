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

BritishMoney Add(const BritishMoney& money1, const BritishMoney& money2)
{
	unsigned long long pennies1 = BritishMoneyToPennies(money1);
	unsigned long long pennies2 = BritishMoneyToPennies(money2);
	unsigned long long pennies3 = pennies1 + pennies2;
	return BritishMoneyFromPennies(pennies3);
}

BritishMoney Subtract(const BritishMoney& money1, const BritishMoney& money2)
{
	unsigned long long pennies1 = BritishMoneyToPennies(money1);
	unsigned long long pennies2 = BritishMoneyToPennies(money2);
	if (pennies1 < pennies2)
		throw std::out_of_range("BritishMoney Subtract: money1 less than money2");
	unsigned long long pennies3 = pennies1 - pennies2;
	return BritishMoneyFromPennies(pennies3);
}

BritishMoney Multiply(const BritishMoney& money, const double factor)
{
	if (factor < 0.0)
		throw std::out_of_range("BritishMoney Multiply: second parameter less than zero");
	unsigned long long pennies = BritishMoneyToPennies(money);
	unsigned long long pennies2 = (unsigned long long)(pennies * factor);
	return BritishMoneyFromPennies(pennies2);
}

BritishMoney Multiply(const double factor, const BritishMoney& money)
{
	if (factor < 0.0)
		throw std::out_of_range("BritishMoney Multiply: first parameter less than zero");
	return Multiply(money, factor);
}

BritishMoney Divide(const BritishMoney& money, const double factor)
{
	if (factor == 0.0)
		throw std::out_of_range("BritishMoney Divide: second parameter is zero or less");

	unsigned long long pennies = BritishMoneyToPennies(money);
	unsigned long long pennies2 = (unsigned long long)(pennies / factor);
	return BritishMoneyFromPennies(pennies2);
}

double Divide(const BritishMoney& money1, const BritishMoney& money2)
{
	unsigned long long pennies1 = BritishMoneyToPennies(money1);
	unsigned long long pennies2 = BritishMoneyToPennies(money2);
	if (pennies2 == 0)
		throw std::out_of_range("BritishMoney Divide: second parameter is zero");
	double factor = (double)pennies1 / (double)pennies2;
	return factor;
}

bool Equal(const BritishMoney& money1, const BritishMoney& money2)
{
	unsigned long long pennies1 = BritishMoneyToPennies(money1);
	unsigned long long pennies2 = BritishMoneyToPennies(money2);
	bool result = pennies1 == pennies2;
	return result;
}

bool NotEqual(const BritishMoney& money1, const BritishMoney& money2)
{
	unsigned long long pennies1 = BritishMoneyToPennies(money1);
	unsigned long long pennies2 = BritishMoneyToPennies(money2);
	bool result = pennies1 != pennies2;
	return result;
}

bool Greater(const BritishMoney& money1, const BritishMoney& money2)
{
	unsigned long long pennies1 = BritishMoneyToPennies(money1);
	unsigned long long pennies2 = BritishMoneyToPennies(money2);
	bool result = pennies1 > pennies2;
	return result;
}

bool GreaterOrEqual(const BritishMoney& money1, const BritishMoney& money2)
{
	unsigned long long pennies1 = BritishMoneyToPennies(money1);
	unsigned long long pennies2 = BritishMoneyToPennies(money2);
	bool result = pennies1 >= pennies2;
	return result;
}

bool Less(const BritishMoney& money1, const BritishMoney& money2)
{
	unsigned long long pennies1 = BritishMoneyToPennies(money1);
	unsigned long long pennies2 = BritishMoneyToPennies(money2);
	bool result = pennies1 < pennies2;
	return result;
}

bool LessOrEqual(const BritishMoney& money1, const BritishMoney& money2)
{
	unsigned long long pennies1 = BritishMoneyToPennies(money1);
	unsigned long long pennies2 = BritishMoneyToPennies(money2);
	bool result = pennies1 <= pennies2;
	return result;
}

void WriteToStream(ostream& stream, const BritishMoney& money)
{
	unsigned long long pounds = money.pounds;
	unsigned int shillings = money.shillings;
	unsigned int pennies = money.pennies;

	stream << "(" << pounds << "," << shillings << "," << pennies << ")";
}

void ReadFromStream(istream& stream, BritishMoney& money)
{
	unsigned long long pounds;
	unsigned int shillings;
	unsigned int pennies;
	char leftBracket, rightBracket, comma1, comma2;

	stream >> leftBracket >> pounds >> comma1 >> shillings >> comma2 >> pennies >> rightBracket;
	money.pounds = pounds;
	money.shillings = shillings;
	money.pennies = pennies;
}
