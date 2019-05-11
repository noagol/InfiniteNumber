
#include "LargeIntegers.h"
#include "Decimal.h"
#include "Binary.h"

// In my program i use the 2 complete method

/**
 *
 * @param str
 * @return the str if it valid
 */
string checkValidate(const string str) {
    string newStr = str;
    unsigned long int i;
    if (newStr.size() > 1 && newStr.at(0) == '-') {
        string num1s = str.substr(1);
        newStr = Math::deleteZero(&num1s);
        newStr = Math::addMinusSign(num1s);
        for (i = 1; i < newStr.size(); i++) {
            if (!('0' <= newStr.at(i) && newStr.at(i) <= '9')) {
                throw invalid_argument((string) "Invalid character: " += newStr.at(i));
            }
        }
    } else if (newStr.size() >= 1) {
        newStr = Math::deleteZero(&newStr);
        for (i = 0; i < newStr.size(); i++) {
            if (!('0' <= newStr.at(i) && newStr.at(i) <= '9')) {
                throw invalid_argument((string) "Invalid character: " += newStr.at(i));
            }
        }
    } else if (newStr.size() == 0) {
        throw invalid_argument((string) "empty string");
    }
    return newStr;
}

/**
 * Constructors
 * @param num
 */
InfInt::InfInt(const string num) : decimalNum(checkValidate(num)),
                                   binaryNum((Math::decimalToBinary(checkValidate(num)))) {}

InfInt::InfInt(const char *num) : decimalNum(checkValidate(num)),
                                  binaryNum((Math::decimalToBinary(checkValidate(num)))) {}

InfInt::InfInt() : decimalNum("0"), binaryNum("00000000") {}

InfInt::InfInt(const long int num) : decimalNum(Math::toString(num)),
                                     binaryNum(Math::decimalToBinary(Math::toString(num))) {}

InfInt::InfInt(const int num) : decimalNum(Math::toString(num)),
                                binaryNum(Math::decimalToBinary(Math::toString(num))) {}

InfInt::InfInt(const Binary b) : decimalNum(Math::binaryToDecimal(b.getValue())),
                                 binaryNum(b.getValue()) {}

/**
 * Convert InfInt to int
 * @return the int number
 */
InfInt::operator int() const {
    string binary = this->getBinary();
    if (binary.size() > 32) {
        binary = binary.substr(binary.size() - 32, binary.size());
        Decimal decimal = Math::binaryToDecimal(binary);
        return Math::toInt(decimal.getDecimal());
    } else {
        return Math::toInt(decimalNum.getDecimal());
    }
}

/**
 * Plus function
 * @param other
 * @return the addition of other and this
 */
InfInt InfInt::operator+(const InfInt &other) const {
    Decimal d = decimalNum + other.decimalNum;
    return InfInt(d.getDecimal());
}

/**
 * increments this in 1
 * prefix
 * @return ++this
 */
InfInt InfInt::operator++() {
    ++decimalNum;
    string d = decimalNum.getDecimal();
    binaryNum = Math::decimalToBinary(&d);
    return *this;
}

/**
 * add 1 to this
 * postfix
 * @return this++
 */
InfInt InfInt::operator++(int) {
    InfInt num = *this;
    ++decimalNum;
    string d = decimalNum.getDecimal();
    binaryNum = Math::decimalToBinary(&d);
    return num;
}

/**
 * Minus function
 * @param other
 * @return the substract of this and other
 */
InfInt InfInt::operator-(const InfInt &other) const {
    Decimal d = decimalNum - other.decimalNum;
    return InfInt(d.getDecimal());
}

/**
 * substract this in 1
 * prefix
 * @return --this
 */
InfInt InfInt::operator--() {
    --decimalNum;
    string d = decimalNum.getDecimal();
    binaryNum = Math::decimalToBinary(&d);
    return *this;
}

/**
 * substract this in 1
 * postfix
 * @return this--
 */
InfInt InfInt::operator--(int) {
    InfInt num = *this;
    --decimalNum;
    string d = decimalNum.getDecimal();
    binaryNum = Math::decimalToBinary(&d);
    return num;
}

/**
 * Multiply this and other
 * @return this * other
 */
InfInt InfInt::operator*(const InfInt &other) const {
    Decimal d = (decimalNum) * (other.decimalNum);
    return InfInt(d.getDecimal());
}

/**
 * Division this and other
 * @return this / other
 */
InfInt InfInt::operator/(const InfInt &other) const {
    Decimal d = (decimalNum) / (other.decimalNum);
    return InfInt(d.getDecimal());
}

/**
 * Reminder this and other
 * @return this % other
 */
InfInt InfInt::operator%(const InfInt &other) const {
    Decimal d = (decimalNum) % (other.decimalNum);
    return InfInt(d.getDecimal());
}

/**
 * Add other to this and assign
 * @return this += other
 */
InfInt &InfInt::operator+=(const InfInt &other) {
    decimalNum += other.decimalNum;
    string d = decimalNum.getDecimal();
    binaryNum = Math::decimalToBinary(&d);
    return *this;
}

/**
 * return other & this and assign
 * @return this &= other
 */
InfInt &InfInt::operator&=(const InfInt &other) {
    this->binaryNum &= other.binaryNum;
    string d = binaryNum.getValue();
    decimalNum = Math::binaryToDecimal(&d);
    return *this;
}

/**
 * Multiply other to this and assign
 * @return this *= other
 */
InfInt &InfInt::operator*=(const InfInt &other) {
    decimalNum *= other.decimalNum;
    string d = decimalNum.getDecimal();
    binaryNum = Math::decimalToBinary(&d);
    return *this;
}

/**
 *check if this < other
 * @return 1- if true else 0
 */
bool InfInt::operator<(const InfInt &other) const {
    bool d = (decimalNum) < (other.decimalNum);
    return d;
}

/**
 *check if this > other
 * @return 1- if true else 0
 */
bool InfInt::operator>(const InfInt &other) const {
    bool d = (decimalNum) > (other.decimalNum);
    return d;
}

/**
 *check if this >= other
 * @return 1- if true else 0
 */
bool InfInt::operator>=(const InfInt &other) const {
    bool d = (decimalNum) >= (other.decimalNum);
    return d;
}

/**
 *check if this <= other
 * @return 1- if true else 0
 */
bool InfInt::operator<=(const InfInt &other) const {
    bool d = (decimalNum) <= (other.decimalNum);
    return d;
}

/**
 *check if this == other
 * @return 1- if true else 0
 */
bool InfInt::operator==(const InfInt &other) const {
    bool d = (decimalNum) == (other.decimalNum);
    return d;
}


/**
 * @param other binary num
 * @return the logical or this|other
 */
InfInt InfInt::operator|(const InfInt &other) {
    Binary d = (binaryNum) | (other.binaryNum);
    return InfInt(d);
}

/**
 * @param other binary num
 * @return the logical and this&other
 */
InfInt InfInt::operator&(const InfInt &other) {
    Binary d = (binaryNum) & (other.binaryNum);
    return InfInt(d);
}

/**
 * @param other binary num
 * @return the logical xor this^other
 */
InfInt InfInt::operator^(const InfInt &other) {
    Binary d = (binaryNum) ^(other.binaryNum);
    return InfInt(d);
}

/**
 * Print to stream
 * @param stream
 * @param inf the number
 * @return the stream
 */
ostream &operator<<(ostream &stream, const InfInt &inf) {
    stream << inf.getDecimal();
    return stream;
}

/**
 * Read from stream
 * @param input
 * @param dec
 * @return the steam
 */
istream &operator>>(istream &input, InfInt &dec) {
    input >> dec.decimalNum;
    string d = dec.decimalNum.getDecimal();
    dec.binaryNum = Math::decimalToBinary(&d);
    return input;
}

/**
 * @param other binary num
 * @return the logical shift left this<<other
 */
InfInt InfInt::operator<<(int x) const {
    if (x < 0) {
        throw invalid_argument((string) "negative number");
    }
    Binary d = (binaryNum) << x;
    return InfInt(d);
}

/**
 * @param other binary num
 * @return the logical shift right this>>other
 */
InfInt InfInt::operator>>(int x) const {
    if (x < 0) {
        throw invalid_argument((string) "negative number");
    }
    Binary d = (binaryNum) >> x;
    return InfInt(d);
}

/**
 * do logical shift and assign
 * @param other binary num
 * @return the logical shift right this>>other
 */
InfInt InfInt::operator>>=(unsigned long int x) {
    this->binaryNum >>= x;
    string d = binaryNum.getValue();
    decimalNum = Math::binaryToDecimal(&d);
    return *this;
}

/**
 *
 * @return the decimal value
 */
string InfInt::getDecimal() const {
    return this->decimalNum.getDecimal();
}

/**
 *
 * @return the binary value
 */
string InfInt::getBinary() const {
    return this->binaryNum.getValue();
}

