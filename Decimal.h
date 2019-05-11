
#ifndef UNTITLED1_DECIMAL_H

#include "Math.h"
#include <cstring>

#define UNTITLED1_DECIMAL_H


class Decimal {
    string num;
public:
    Decimal(string a);

    friend ostream &operator<<(ostream &stream, const Decimal &dec);

    friend istream &operator>>(istream &input, Decimal &dec);

    Decimal operator+(const Decimal &other) const;

    Decimal &operator++();

    Decimal operator++(int);

    Decimal operator-(const Decimal &other) const;

    Decimal &operator--();

    Decimal operator--(int);

    Decimal operator*(const Decimal &other) const;

    Decimal &operator*=(const Decimal &other);

    Decimal operator/(const Decimal &other)const;

    Decimal &operator+=(const Decimal &other);

    Decimal operator%(const Decimal &other) const;

    bool operator<(const Decimal &other) const;

    bool operator>(const Decimal &other) const;

    bool operator>=(const Decimal &other) const;

    bool operator<=(const Decimal &other) const;

    bool operator==(const Decimal &other) const;

    string getDecimal() const;
};

#endif //UNTITLED1_DECIMAL_H