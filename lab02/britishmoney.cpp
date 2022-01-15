#include "britishmoney.h"
#include <cmath>

uint16_t ps_sh = 20;
uint16_t sh_p = 12;

BMoney::BMoney() {
    ps = 0;
    sh = 0;
    p = 0;
    std:: cout << "\t\t\t\t~virtual wallet created by default~" << std:: endl;
}

BMoney::BMoney(unsigned long long a, uint16_t b, uint16_t c) {
    if (ps < 0 || sh < 0 || p < 0) {
        std:: cout << "Parameters must be positive or zero integer numbers" << std:: endl;
    }
    else {
        ps = a;
        sh = b;
        p = c;
    }
    std:: cout << "\t\t\t\t~virtual wallet created according to parameters~" << std:: endl;
}

BMoney::BMoney(std::istream &is) {
    std:: cout << "Please enter your wallet data in order [pounds] [shillings] [pennies]: " << std:: endl;
    is >> ps >> sh >> p;
    while (ps < 0 || sh < 0 || p < 0) {
        std:: cout << "Invalind input. Try again." << std:: endl;
        is >> ps >> sh >> p;
    }
    std:: cout << "\t\t\t\t~virtual wallet created via istream~" << std:: endl;
}


bool operator==(const BMoney &m1, const BMoney &m2) {
    if (m1.ps == m2.ps && m1.sh == m2.sh && m1.p == m2.p)
        return 1;
    return 0;
}

bool operator!=(const BMoney &m1, const BMoney &m2) {
    if (m1.ps != m2.ps || m1.sh != m2.sh || m1.p != m2.p)
        return 1;
    return 0;
    //return !Equal(m1, m2);
}

bool operator>(const BMoney &m1, const BMoney &m2) {
    unsigned long long tmp1 = m1.ToPenny();
    unsigned long long tmp2 = m2.ToPenny();
    if (tmp1 > tmp2)
        return 1;
    return 0;
}

bool operator<=(const BMoney &m1, const BMoney &m2) {
    return !(m1 > m2);
}

bool operator<(const BMoney &m1, const BMoney &m2) {
    return m2 > m1;
}

bool operator>=(const BMoney &m1, const BMoney &m2) {
    return !(m2 > m1);
}

bool BMoney::Empty() const {
    if (ps == 0 && sh == 0 && p == 0)
        return 1;
    return 0;
}


BMoney operator+(const BMoney& m1, const BMoney &m2) {
    BMoney res;
    res.p = (m1.p + m2.p) % sh_p;
    res.sh = (m1.sh + m2.sh + (m1.p + m2.p) / sh_p) % ps_sh;
    res.ps = m1.ps + m2.ps + (m1.sh + m2.sh + (m1.p + m2.p) / sh_p) / ps_sh;
    return res;
}

unsigned long long BMoney::ToPenny() const {
    unsigned long long res = ps * ps_sh * sh_p + sh * sh_p + p;
    //std:: cout << res << std:: endl;
    return res;
};

BMoney PtoSum(unsigned long long tmp_p) {
    BMoney res;
    res.ps = tmp_p / (ps_sh * sh_p);
    tmp_p %= (ps_sh * sh_p);
    res.sh = tmp_p / sh_p;
    res.p = tmp_p % sh_p;
    return res;
}

BMoney operator-(const BMoney &m1, const BMoney &m2) {
    if (m1 < m2) {
        std:: cout << "The operation could not be performed. The first sum is less than the second." << std:: endl;
        return BMoney(); // возвращение нулевого кошелька
    }
    unsigned long long tmp = m1.ToPenny() - m2.ToPenny();
    return PtoSum(tmp);
}

BMoney operator/(BMoney &m1, BMoney &m2) {
    if (!m2.Empty()) {
        unsigned long long tmp = m1.ToPenny() / m2.ToPenny();
        return PtoSum(tmp);
    }
    std:: cout << "The operation could not be performed. The second sum equals null." << std:: endl;
    return BMoney();
}

BMoney BMoney::operator/(double C) { // все функции класса (не friend) обязательно должны иметь [назв-е класса]::
    if (C == 0) {
        std:: cout << "The operation could not be performed. The number equals null." << std:: endl;
        return BMoney();
    }
    unsigned long long tmp = this->ToPenny() / C;
    return PtoSum(tmp);
} 

BMoney BMoney::operator*(double C) {
    unsigned long long tmp = ToPenny() * C;
    return PtoSum(tmp);
}

void BMoney::Print(std::ostream &os) { // totally works
    os << ps << " pounds " << sh << " shillings " << p << " pennies " << std::endl;
}

BMoney BMoney::operator=(const BMoney &other)
{
    ps = other.ps;
    sh = other.sh;
    p = other.p;
    return *this;
}

BMoney operator "" _ps(unsigned long long ps)
{
    return BMoney(ps, 0, 0);
}

BMoney operator "" _s(unsigned long long sh)
{
    return BMoney(0, sh, 0);
}

BMoney operator "" _p(unsigned long long p)
{
    return BMoney(0, 0, p);
}

void BMoney::Translate() {
    if (p > sh_p || sh > ps_sh) {
        sh += p / sh_p;
        p %= sh_p;
        ps += sh / ps_sh;
        sh = (sh % ps_sh) + p / sh_p;
    }
}

BMoney::~BMoney() {
    std:: cout << "\t\t\t\t ~wallet has been deleted~" << std:: endl;
}