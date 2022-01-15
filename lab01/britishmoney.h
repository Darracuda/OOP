#ifndef BRITMONEY_H
#define BRITMONEY_H
#include <iostream>


class BMoney {
    // дружественным функциям есть доступ к приватным полям и функциям класса
    friend BMoney Add(const BMoney &money1, const BMoney &money2);
    friend BMoney Subtract(const BMoney &money1, const BMoney &money2);
    friend BMoney Divide(BMoney &money1, BMoney &money2);
    friend bool Equal(const BMoney &money1, const BMoney &money2);
    friend bool NotEqual(const BMoney &money1, const BMoney &money2);
    friend bool More(const BMoney &money1, const BMoney &money2);
    friend bool Less(const BMoney &money1, const BMoney &money2);
    friend bool MoreEqual(const BMoney &money1, const BMoney &money2);
    friend bool LessEqual(const BMoney &money1, const BMoney &money2);
    friend BMoney PtoSum(unsigned long long tmp_p);

    public:
        BMoney(); // явный конструктор по умолчанию (все равно 0)
        BMoney(unsigned long long a, uint16_t b, uint16_t c); // конструктор с параметрами, инициализация напрямую в коде
        BMoney(std::istream &is); // конструктор из istream
        BMoney Divide_real(double C);
        BMoney Multiply_real(double C);
        void Print(std::ostream &os);
        ~BMoney(); // деструктор

        unsigned long long ToPenny() const;
        BMoney operator=(const BMoney &other);
        void Translate();
        bool Empty() const;

    private:
        unsigned long long ps;
        uint16_t sh;
        uint16_t p;

};
#endif
