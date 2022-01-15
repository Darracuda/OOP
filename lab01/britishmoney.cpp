#include "britishmoney.h"

unsigned char ps_sh = 20;
unsigned char sh_p = 12;

BritishMoney::BritishMoney() {
    pounds = 0;
    shillings = 0;
    pennies = 0;
    std:: cout << "\t\t\t\t~virtual wallet created by default~" << std:: endl;
}

BritishMoney::BritishMoney(unsigned long long pounds, unsigned char shillings, unsigned char pennies)
{
    if (shillings >= 20 || pennies >= 12)
        throw std::out_of_range("BritishMoney");
    this->pounds = pounds;
    this->shillings = shillings;
    this->pennies = pennies;
}

BritishMoney::BritishMoney(std::istream &is) {
    std:: cout << "Please enter your wallet data in order [pounds] [shillings] [pennies]: " << std:: endl;
    is >> pounds >> shillings >> pennies;
    while (pounds < 0 || shillings < 0 || pennies < 0) {
        std:: cout << "Invalind input. Try again." << std:: endl;
        is >> pounds >> shillings >> pennies;
    }
    std:: cout << "\t\t\t\t~virtual wallet created via istream~" << std:: endl;
}


bool Equal(const BritishMoney &money1, const BritishMoney &money2) {
    if (money1.pounds == money2.pounds && money1.shillings == money2.shillings && money1.pennies == money2.pennies)
        return 1;
    return 0;
}

bool NotEqual(const BritishMoney &money1, const BritishMoney &money2) {
    if (money1.pounds != money2.pounds || money1.shillings != money2.shillings || money1.pennies != money2.pennies)
        return 1;
    return 0;
    //return !Equal(money1, money2);
}

bool More(const BritishMoney &money1, const BritishMoney &money2) {
    unsigned long long tmp1 = money1.ToPenny();
    unsigned long long tmp2 = money2.ToPenny();
    if (tmp1 > tmp2)
        return 1;
    return 0;
}

bool LessEqual(const BritishMoney &money1, const BritishMoney &money2) {
    return !More(money1, money2);
}

bool Less(const BritishMoney &money1, const BritishMoney &money2) {
    return More(money2, money1);
}

bool MoreEqual(const BritishMoney &money1, const BritishMoney &money2) {
    return !More(money2, money1);
}

bool BritishMoney::Empty() const {
    if (pounds == 0 && shillings == 0 && pennies == 0)
        return 1;
    return 0;
}


BritishMoney Add(const BritishMoney& money1, const BritishMoney &money2) {
    BritishMoney res;
    res.pennies = (money1.pennies + money2.pennies) % sh_p;
    res.shillings = (money1.shillings + money2.shillings + (money1.pennies + money2.pennies) / sh_p) % ps_sh;
    res.pounds = money1.pounds + money2.pounds + (money1.shillings + money2.shillings + (money1.pennies + money2.pennies) / sh_p) / ps_sh;
    return res;
}

unsigned long long BritishMoney::ToPenny() const {
    unsigned long long res = pounds * ps_sh * sh_p + shillings * sh_p + pennies;
    //std:: cout << res << std:: endl;
    return res;
};

BritishMoney PtoSum(unsigned long long tmp_p) {
    BritishMoney res;
    res.pounds = tmp_p / (ps_sh * sh_p);
    tmp_p %= (ps_sh * sh_p);
    res.shillings = tmp_p / sh_p;
    res.pennies = tmp_p % sh_p;
    return res;
}

BritishMoney Subtract(const BritishMoney &money1, const BritishMoney &money2) {
    if (Less(money1, money2)) {
        std:: cout << "The operation could not be performed. The first sum is less than the second." << std:: endl;
        return BritishMoney(); // возвращение нулевого кошелька
    }
    unsigned long long tmp = money1.ToPenny() - money2.ToPenny();
    return PtoSum(tmp);
}

BritishMoney Divide(BritishMoney &money1, BritishMoney &m2) {
    if (!m2.Empty()) {
        unsigned long long tmp = money1.ToPenny() / m2.ToPenny();
        return PtoSum(tmp);
    }
    std:: cout << "The operation could not be performed. The second sum equals null." << std:: endl;
    return BritishMoney();
}

BritishMoney BritishMoney::Divide_real(double C) { // все функции класса (не friend) обязательно должны иметь [название-е класса]::
    if (C == 0) {
        std:: cout << "The operation could not be performed. The number equals null." << std:: endl;
        return BritishMoney();
    }
    unsigned long long tmp = this->ToPenny() / C;
    return PtoSum(tmp);
} 

BritishMoney BritishMoney::Multiply_real(double C) {
    unsigned long long tmp = ToPenny() * C;
    return PtoSum(tmp);
}

void BritishMoney::Print(std::ostream &os) { 
    os << pounds << " pounds " << shillings << " shillings " << pennies << " pennies " << std::endl;
}

BritishMoney BritishMoney::operator=(const BritishMoney &other)
{
    pounds = other.pounds;
    shillings = other.shillings;
    pennies = other.pennies;
    return *this;
}

void BritishMoney::Translate() {
    if (pennies > sh_p || shillings > ps_sh) {
        shillings += pennies / sh_p;
        pennies %= sh_p;
        pounds += shillings / ps_sh;
        shillings = (shillings % ps_sh) + pennies / sh_p;
    }
}

BritishMoney::~BritishMoney() {
    std:: cout << "\t\t\t\t ~wallet has been deleted~" << std:: endl;
}
