#ifndef BRITMONEY_H
#define BRITMONEY_H
#include <iostream>


class BritishMoney {
    // дружественным функциям есть доступ к приватным полям и функциям класса
    friend BritishMoney Add(const BritishMoney &money1, const BritishMoney &money2);
    friend BritishMoney Subtract(const BritishMoney &money1, const BritishMoney &money2);
    friend BritishMoney Divide(BritishMoney &money1, BritishMoney &m2);
    friend bool Equal(const BritishMoney &money1, const BritishMoney &money2);
    friend bool NotEqual(const BritishMoney &money1, const BritishMoney &money2);
    friend bool More(const BritishMoney &money1, const BritishMoney &money2);
    friend bool Less(const BritishMoney &money1, const BritishMoney &money2);
    friend bool MoreEqual(const BritishMoney &money1, const BritishMoney &money2);
    friend bool LessEqual(const BritishMoney &money1, const BritishMoney &money2);
    friend BritishMoney PtoSum(unsigned long long tmp_p);

    public:
        BritishMoney(); // явный конструктор по умолчанию (все равно 0)
        BritishMoney(unsigned long long a, unsigned char b, unsigned char c); // конструктор с параметрами, инициализация напрямую в коде
        BritishMoney(std::istream &is); // конструктор из istream
        BritishMoney Divide_real(double C);
        BritishMoney Multiply_real(double C);
        void Print(std::ostream &os);
        ~BritishMoney(); // деструктор

        unsigned long long ToPenny() const;
        BritishMoney operator=(const BritishMoney &other);
        void Translate();
        bool Empty() const;

    private:
        unsigned long long pounds;
        unsigned char shillings;
        unsigned char pennies;

};
#endif
