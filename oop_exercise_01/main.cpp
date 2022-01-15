// OOP, Lab 01, variant 9, Diana Kolpakova
// British Money

#include <iostream>
#include "BritishMoney.h"

using namespace std;

int main()
{
	cout << "oop_exercise_01 (c) Diana Kolpakova" << endl;
	cout << "British money format is (pounds,shillings,pennies)." << endl;

	BritishMoney money1;
	BritishMoney money2;
	double factor;

	cout << "Enter money1:";
	ReadFromStream(cin, money1);
	cout << "Enter money2:";
	ReadFromStream(cin, money2);
	cout << "Enter factor:";
	cin >> factor;

	cout << "Results:" << endl;
	cout << "money1 = "; WriteToStream(cout, money1); cout << endl;
	cout << "money2 = "; WriteToStream(cout, money2); cout << endl;
	cout << "factor = " << factor << endl;

	cout << "money1+money2 = "; WriteToStream(cout, Add(money1, money2)); cout << endl;
	cout << "money1-money2 = ";  WriteToStream(cout, Subtract(money1, money2)); cout << endl;
	cout << "money1*factor = ";  WriteToStream(cout, Multiply(money1, factor)); cout << endl;
	cout << "factor*money2 = ";  WriteToStream(cout, Multiply(factor, money2)); cout << endl;
	cout << "money1/money2 = " << Divide(money1, money2) << endl;
	cout << "money1/factor = ";  WriteToStream(cout, Divide(money1, factor)); cout << endl;

	cout << "money1==money2 = " << Equal(money1, money2) << endl;
	cout << "money1!=money2 = " << NotEqual(money1, money2) << endl;
	cout << "money1>money2 = " << Greater(money1, money2) << endl;
	cout << "money1>=money2 = " << GreaterOrEqual(money1, money2) << endl;
	cout << "money1<money2 = " << Less(money1, money2) << endl;
	cout << "money1<=money2 = " << LessOrEqual(money1, money2) << endl;
}
