#ifndef BRITMONEY_H
#define BRITMONEY_H
#include <iostream>


class BMoney {
    friend BMoney operator+(const BMoney &m1, const BMoney &m2); // друж ф-ям есть доступ к приват полям и ф-ям класса
    friend BMoney operator-(const BMoney &m1, const BMoney &m2);
    friend BMoney operator/(BMoney &m1, BMoney &m2);
    friend bool operator==(const BMoney &m1, const BMoney &m2);
    friend bool operator!=(const BMoney &m1, const BMoney &m2);
    friend bool operator>(const BMoney &m1, const BMoney &m2);
    friend bool operator<(const BMoney &m1, const BMoney &m2);
    friend bool operator>=(const BMoney &m1, const BMoney &m2);
    friend bool operator<=(const BMoney &m1, const BMoney &m2);
    friend BMoney PtoSum(unsigned long long tmp_p);

    public:
        BMoney(); // явный конструктор по умолчанию (все равно 0)
        BMoney(unsigned long long a, uint16_t b, uint16_t c); // конструктор с параметрами, инициализация напрямую в коде
        BMoney(std::istream &is); // конструктор из istream
        BMoney operator/(double C);
        BMoney operator*(double C);
        void operator>>(std::ostream &os);
        ~BMoney(); // деструктор

        unsigned long long ToPenny() const;
        BMoney operator=(const BMoney &other);
        void Translate();
        void Print(std::ostream &os);
        bool Empty() const;

    private:
        unsigned long long ps;
        uint16_t sh;
        uint16_t p;

};

BMoney operator "" _ps(unsigned long long ps);
BMoney operator "" _s(unsigned long long sh);
BMoney operator "" _p(unsigned long long p);

#endif