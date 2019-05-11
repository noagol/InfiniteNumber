//
// Created by noa on 02/11/2018.
//

#include "Binary.h"

// Constructor
Binary::Binary(const string n) : num(n) {
}

/**
 *  Compute logical operation on a string of bits
 * @param x the bimary number
 * @param f the sign
 * @return the binary number result
 */
Binary Binary::operatorFunc(const Binary &x, bool (*f)(bool, bool))  {
    unsigned long int i;
    unsigned long int str;
    unsigned long int len;
    string operate;
    char c;
    string s;
    string num1;
    // check if this<other
    if ((this->num).size() < (x.num).size()) {
        len = (x.num).size();
        str = (x.num).size() - (this->num).size();
        c = this->num.at(0);
        s += c;
        num1 = num;
        for (i = 0; i < str; i++) {
            num1.insert(0, s);
        }
        operate = x.getValue();
        // goes all the number and check the logical sign
        for (i = 0; i < len; i++) {
            // change the result
            if (f(num1.at(i) == '1', x.num.at(i) == '1')) {
                operate.at(i) = '1';
            } else {
                operate.at(i) = '0';
            }
        }
        // check if this>other
    } else {
        len = (this->num).size();
        str = (this->num).size() - (x.num).size();
        operate = this->num;
        c = x.num.at(0);
        s += c;
        num1 = x.getValue();
        for (i = 0; i < str; i++) {
            num1.insert(0, s);
        }
        // goes all the number and check the logical sign
        for (i = 0; i < len; i++) {
            // change the result
            if (f(this->num.at(i) == '1', num1.at(i) == '1')) {
                operate.at(i) = '1';
            } else {
                operate.at(i) = '0';
            }
        }
    }
    return Binary(operate);
}
/**
 * @return x^y
 */
static bool xor_operator(const bool x, const bool y) {
    return (x || y) && !(x && y);
}

/**
 * @return x|y
 */
static bool or_operator(const bool x, const bool y) {
    return (x || y);
}

/**
 * @return x&y
 */
static bool and_operator(bool x, bool y) {
    return (x && y);
}

/**
 * @param other binary num
 * @return the result of logical and this&other
 */
Binary Binary::operator&(const Binary &x)  {
    return operatorFunc(x, and_operator);
}

/**
 * @param other binary num
 * @return the result of logical or this|other
 */
Binary Binary::operator|(const Binary &x)  {
    return operatorFunc(x, or_operator);
}

/**
 * @param other binary num
 * @return the result of logical xor this^other
 */
Binary Binary::operator^(const Binary &x)  {
    return operatorFunc(x, xor_operator);
}

/**
 * return other & this and assign
 * @return the result of this &= other
 */
Binary &Binary::operator&=(const Binary &x) {
    *this = *this & x;
    return *this;
}

/**
 * @param x int num
 * @return the number of
 * logical shift left this<<other
 */
Binary Binary::operator<<(int x) const {
    int i;
    string result = num;
    for (i = 0; i < x; i++) {
        result += "0";
    }
    unsigned long int size;
    char c = result.at(0);
    string num;
    num += c;
    size = result.size();
    for (i = 0; i < 8 - (size % 8); i++) {
        result.insert(0, num);
    }
    return Binary(result);
}

/**
 * @param x int num
 * @return the number of
 * logical shift right this>>other
 */
Binary Binary::operator>>(int x) const {
    int i;
    string result = num;
    char c = result.at(0);
    string number;
    number += c;
    for (i = 0; i < x; i++) {
        result.insert(0, number);
    }
    return Binary(result.substr(0, result.size() - x));
}

/**
 * do logical shift and assign
 * @param x binary num
 * @return the logical shift right this>>other
 */
Binary Binary::operator>>=(unsigned long int x) {
    *this = *this >> x;
    return *this;
}

/**
 *
 * @return the binary value
 */
string Binary::getValue() const {
    return num;
}


