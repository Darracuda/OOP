// OOP, Lab 02, variant 9, Diana Kolpakova
// British Money

#include <iostream>
#include "BritishMoney.h"

using namespace std;

int main()
{
	cout << "oop_exercise_02 (c) Diana Kolpakova" << endl;
	cout << "British money format is (pounds,shillings,pennies)." << endl;

	BritishMoney money1;
	BritishMoney money2 = 15_shilling;
	double factor;

	cout << "Enter money1:";
	cin >> money1;
	cout << "Enter factor:";
	cin >> factor;

	cout << "Results:" << endl;
	cout << "money1 = " << money1 << endl;
	cout << "money2 = " << money2 << endl;
	cout << "factor = " << factor << endl;

	cout << "money1+money2 = " << (money1 + money2) << endl;
	cout << "money1-money2 = " << (money1 - money2) << endl;
	cout << "money1*factor = " << (money1 * factor) << endl;
	cout << "factor*money2 = " << (factor * money2) << endl;
	cout << "money1/money2 = " << (money1 / money2) << endl;
	cout << "money1/factor = " << (money1 / factor) << endl;

	cout << "money1==money2 = " << (money1 == money2) << endl;
	cout << "money1!=money2 = " << (money1 != money2) << endl;
	cout << "money1>money2 = " << (money1 > money2) << endl;
	cout << "money1>=money2 = " << (money1 >= money2) << endl;
	cout << "money1<money2 = " << (money1 < money2) << endl;
	cout << "money1<=money2 = " << (money1 <= money2) << endl;
}
