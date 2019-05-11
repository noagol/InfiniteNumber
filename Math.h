
#ifndef UNTITLED1_MATH_H

#include <string.h>
#include <iostream>
#include <vector>

#define UNTITLED1_MATH_H

using namespace std;


class Math {
public:
    static string increase(string *arr, unsigned long int oldSize, unsigned long int newSize);

    static string deleteZero(string *arr);

    static string addMinusSign(string arr);

    static string notBinary(string *num);

    static string addBinary(string *num1, string *num2);

    static string addTwoNumbers(basic_string<char> num1, basic_string<char> num2, basic_string<char> *remainder);

    static void size(const string *num1, const string *num2, string *newNum1, string *newNum2);

    static string addDecimal(const string *num1, const string *num2);

    static string substractTwoNumbers(string num1, string num2, string *remainder);

    static string substractDecimal(const string *num1, const string *num2);

    static string multiplyDecimal(const string *num1, const string *num2);

    static string powerDecimal(const string *num1, const string *num2);

    static bool smallerThanOperator(const string *num1, const string *num2);

    static bool biggerThanOperator(const string *num1, const string *num2);

    static string divisionDecimal(const string *num1, const string *num2, string *rem);

    static string longDivision(const string *number, const string *divisor, string *rem);

    static string decimalToBinary(const string *arr);

    static string decimalToBinary(const string arr);


    static string binaryToDecimal(const string *arr);

    static string binaryToDecimal(const string arr);

    static string toString(const long int x) ;

    static int toInt(const string str);


    };
#endif //UNTITLED1_MATH_H
