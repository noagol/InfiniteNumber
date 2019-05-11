//
// Created by noa on 02/11/2018.
//

#ifndef UNTITLED1_BINARY_H

#include <string.h>
#include <cstring>
#include "Math.h"

#define UNTITLED1_BINARY_H


class Binary {
    string num;

public:
    Binary(const string n);

    Binary operatorFunc(const Binary &x, bool (*f)(bool, bool));

    // Binary operator~();

    Binary operator&(const Binary &x) ;

    Binary operator|(const Binary &x) ;

    Binary operator^(const Binary &x) ;

    Binary &operator&=(const Binary &x);

    Binary operator<<(int x) const;

    Binary operator>>(int x) const;

    Binary operator>>=(unsigned long int x) ;

    string getValue() const;

};

#endif //UNTITLED1_BINARY_H
