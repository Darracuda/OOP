#include <iostream>
#include "britishmoney.h"

int main(void) {

    double arg;

    BMoney a1(1, 2, 3);
    BMoney a2(std::cin);
    a2.Translate();
    std::cin >> arg;
    a1.Print(std::cout);
    a2.Print(std::cout);
    std::cout << "a1 < a2 = " << (a1 < a2) << std::endl;
    std::cout << "a1 > a2 = " << (a1 > a2) << std::endl;
    std::cout << "a1 <= a2 = " << (a1 <= a2) << std::endl;
    std::cout << "a1 >= a2 = " << (a1 >= a2) << std::endl;
    std::cout << "a1 == a2 = " << (a1 == a2) << std::endl;
    std::cout << "a1 != a2 = " << (a1 != a2) << std::endl;
    BMoney a3 = a1 + a2;
    std::cout << "a1 + a2 = " << std::endl;
    a3.Print(std::cout);
    BMoney a4 = a2 - 15_p;
    std::cout << "a2 - 15 pennies = " << std::endl;
    a4.Print(std::cout);
    BMoney a5 = a2 / a1;
    std::cout << "a2 / a1 = " << std::endl;
    a5.Print(std::cout);
    BMoney a6 = a1 * arg;
    std::cout << "a1 * C = " << std::endl;
    a6.Print(std::cout);
    BMoney a7 = a1 / arg;
    std::cout << "a1 / C = " << std::endl;
    a7.Print(std::cout);
    
    return 0;
}