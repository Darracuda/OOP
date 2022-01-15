#pragma once
#include <iostream>

using namespace std;

class BritishMoney
{
private:
	unsigned long long pounds;
	unsigned char shillings;
	unsigned char pennies;

	static const unsigned char penniesPerShilling = 12;
	static const unsigned char shillingsPerPound = 20;

public:
	BritishMoney();
	BritishMoney(unsigned long long pounds, unsigned char shillings, unsigned char pennies);

	friend BritishMoney BritishMoneyFromPennies(unsigned long long pennies);
	friend unsigned long long BritishMoneyToPennies(const BritishMoney& money);

	friend BritishMoney Add(const BritishMoney& money1, const BritishMoney& money2);
	friend BritishMoney Subtract(const BritishMoney& money1, const BritishMoney& money2);
	friend BritishMoney Multiply(const BritishMoney& money, const double factor);
	friend BritishMoney Multiply(const double factor, const BritishMoney& money);
	friend BritishMoney Divide(const BritishMoney& money, const double factor);
	friend double Divide(const BritishMoney& money1, const BritishMoney& money2);

	friend bool Equal(const BritishMoney& money1, const BritishMoney& money2);
	friend bool NotEqual(const BritishMoney& money1, const BritishMoney& money2);
	friend bool Greater(const BritishMoney& money1, const BritishMoney& money2);
	friend bool GreaterOrEqual(const BritishMoney& money1, const BritishMoney& money2);
	friend bool Less(const BritishMoney& money1, const BritishMoney& money2);
	friend bool LessOrEqual(const BritishMoney& money1, const BritishMoney& money2);

	friend void WriteToStream(ostream& stream, const BritishMoney& money);
	friend void ReadFromStream(istream& stream, BritishMoney& money);
};
