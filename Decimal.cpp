#include "Decimal.h"

// Constructor
Decimal::Decimal(string a) : num(a) {
}

/**
 * Plus function
 * @param other
 * @return the addition of other and this
 */
Decimal Decimal::operator+(const Decimal &other) const {
    return Decimal(Math::addDecimal(&this->num, &other.num));
}

/**
 * increments this in 1
 * prefix
 * @return ++this
 */
Decimal &Decimal::operator++() {
    *this += Decimal("1");
    return *this;
}


/**
 * add 1 to this
 * postfix
 * @return this++
 */
Decimal Decimal::operator++(int) {
    Decimal d = *this;
    ++(*this);
    return d;
}

/**
 * Minus function
 * @param other
 * @return the substract of this and other
 */
Decimal Decimal::operator-(const Decimal &other) const {
    return Decimal(Math::substractDecimal(&this->num, &other.num));
}

/**
 * substract this in 1
 * prefix
 * @return --this
 */
Decimal &Decimal::operator--() {
    *this = *this - Decimal("1");
    return *this;
}

/**
 * substract this in 1
 * postfix
 * @return this--
 */
Decimal Decimal::operator--(int) {
    Decimal d = *this;
    --(*this);
    return *this;
}

/**
 * Multiply this and other
 * @return this * other
 */
Decimal Decimal::operator*(const Decimal &other) const {
    return Decimal(Math::multiplyDecimal(&this->num, &other.num));
}

/**
 * Multiply other to this and assign
 * @return this *= other
 */
Decimal &Decimal::operator*=(const Decimal &other) {
    string a = other.getDecimal();
    num = Math::multiplyDecimal(&num, &a);
    return *this;
}

/**
 * Division this and other
 * @return this / other
 */
Decimal Decimal::operator/(const Decimal &other) const {
    basic_string<char> remainder;
    return Decimal(Math::longDivision(&this->num, &other.num, &remainder));
}

/**
 * Reminder this and other
 * @return this % other
 */
Decimal Decimal::operator%(const Decimal &other) const {
    basic_string<char> remainder;
    Math::longDivision(&this->num, &other.num, &remainder);
    return Decimal(remainder);
}

/**
 * Add other to this and assign
 * @return this += other
 */
Decimal &Decimal::operator+=(const Decimal &other) {
    string a = other.getDecimal();
    num = Math::addDecimal(&num, &a);
    return *this;
}

/**
 *check if this < other
 * @return 1- if true else 0
 */
bool Decimal::operator<(const Decimal &other) const {
    return Math::smallerThanOperator(&this->num, &other.num);
}

/**
 *check if this > other
 * @return 1- if true else 0
 */
bool Decimal::operator>(const Decimal &other) const {
    return Math::biggerThanOperator(&this->num, &other.num);
}

/**
 *check if this >= other
 * @return 1- if true else 0
 */
bool Decimal::operator>=(const Decimal &other) const {
    return !Math::smallerThanOperator(&this->num, &other.num);
}

/**
 *check if this <= other
 * @return 1- if true else 0
 */
bool Decimal::operator<=(const Decimal &other) const {
    return !Math::biggerThanOperator(&this->num, &other.num);
}

/**
 *check if this equals other
 * @return 1- if true else 0
 */
bool Decimal::operator==(const Decimal &other) const {
    if (this->getDecimal().compare(other.num) == 0) {
        return true;
    }
    return false;
}

/**
 * Print to stream
 * @param stream
 * @param inf the number
 * @return the stream
 */
ostream &operator<<(ostream &stream, const Decimal &dec) {
    stream << dec.getDecimal();
    return stream;
}

/**
 * Read from stream
 * @param input
 * @param dec
 * @return the steam
 */
istream &operator>>(istream &input, Decimal &dec) {
    input >> dec.num;
    return input;
}

/**
 *
 * @return the decimal value
 */
string Decimal::getDecimal() const {
    return this->num;
}

