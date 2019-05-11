
#ifndef UNTITLED1_INFINT_H

#include "Binary.h"
#include "Decimal.h"

#define UNTITLED1_INFINT_H


class InfInt {
    Decimal decimalNum;
    Binary binaryNum;

public:

    InfInt(const char *num);

    InfInt(const string num);

    InfInt();

    InfInt(const long int num);

    InfInt(const int num);


    InfInt(const Binary binary);

    operator int()const;

    InfInt operator+(const InfInt &other)const;

    InfInt operator++();

    InfInt operator++(int);

    InfInt operator-(const InfInt &other)const;

    InfInt operator--();

    InfInt operator--(int);

    InfInt operator*(const InfInt &other)const;

    InfInt operator/(const InfInt &other)const;

    InfInt operator%(const InfInt &other)const;

    InfInt &operator+=(const InfInt &other);

    InfInt &operator&=(const InfInt &other);

    InfInt &operator*=(const InfInt &other);

    bool operator<(const InfInt &other)const;

    bool operator>(const InfInt &other)const;

    bool operator>=(const InfInt &other)const;

    bool operator<=(const InfInt &other)const;

    bool operator==(const InfInt &other)const;

    InfInt operator|(const InfInt &other);

    InfInt operator&(const InfInt &other);

    InfInt operator^(const InfInt &other);

    friend ostream &operator<<(ostream &stream, const InfInt &inf);

    friend istream &operator>>(istream &input, InfInt &dec);

    InfInt operator<<(int x)const;

    InfInt operator>>( int x)const;

    InfInt operator>>=(unsigned long int x);

    string getDecimal() const;

    string getBinary() const;

};

#endif //UNTITLED1_INFINT_H
