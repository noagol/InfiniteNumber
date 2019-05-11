
#include <sstream>
#include "Math.h"

/***************************************************************************************************
 Function Name: increase
 Function input: srr - the array to change
                 old size, new size - the sizes to change the array.
 Function Action: the function change the length of the araay and add 0 to
                  the beginning .
 Function output: the new array
 **************************************************************************************************/
string Math::increase(string *arr, unsigned long int oldSize,
                      unsigned long int newSize) {
    unsigned long int i;
    // add 0 to increase the array.
    for (i = 0; i < newSize - oldSize; i++) {
        arr->insert(0, "0");
    }
    return *arr;
}

/***************************************************************************************************
 Function Name: deleteZero
 Function input: srr - the array to change
 Function Action: the function delete zero from the beginning
                  of the array.
 Function output: the new array
 **************************************************************************************************/
string Math::deleteZero(string *arr) {
    // check if there are zero and delete it
    while (arr->size() > 0 && arr->at(0) == '0') {
        arr->erase(arr->begin());
    }
    if (*arr == "") {
        return "0";
    }
    // return the new arr
    return *arr;
}


/**
 * the function compare between the lenth
 * of the two numbers.
 * take the bigger size and increase the smaller number.
 *
 * @param num1 the first num
 * @param num2 the second num
 * @param newNum1 the new num1
 * @param newNum2 the new num2
 */
void Math::size(const string *num1, const string *num2,
                string *newNum1, string *newNum2) {
    string num1_cpy = *num1;
    string num2_cpy = *num2;
    // if the first len is bigger
    if (num1->size() > num2->size()) {
        // update the len of the second num
        *newNum1 = increase(&num1_cpy, num1->size() + 1, num1->size() + 1);
        *newNum2 = increase(&num2_cpy, num2->size() + 1, num1->size() + 1);
        // if the second len is bigger
    } else if (num1->size() < num2->size()) {
        // update the len of the first num
        *newNum1 = increase(&num1_cpy, num1->size() + 1, num2->size() + 1);
        *newNum2 = increase(&num2_cpy, num2->size() + 1, num2->size() + 1);
        // if the len equals -> copy the numbers
    } else {
        *newNum1 = increase(&num1_cpy, num1->size() + 1, num1->size() + 1);
        *newNum2 = increase(&num2_cpy, num2->size() + 1, num2->size() + 1);
    }
}

/***************************************************************************************************
 Function Name: addMinusSign
 Function input: srr - the string to change
 Function Action: the function add a minus sign -
                  change the num to neg.
 Function output: the new string
 **************************************************************************************************/
string Math::addMinusSign(string arr) {
    return arr.insert(0, "-");
}

/***************************************************************************************************
 Function Name: notBinary
 Function input: num - the binary num
 Function Action: the function change every 0->1 , 1->0
 Function output: the not num
 **************************************************************************************************/
string Math::notBinary(string *num) {
    unsigned long int i;
    string notNum = "";
    // goes all the num
    for (i = 0; i < num->size(); i++) {
        // change 0->1 , 1->0
        if (num->at(i) == '0') {
            notNum += '1';
        } else {
            notNum += '0';
        }
    }
    //return the new num
    return (notNum);
}

/***************************************************************************************************
 Function Name: addBinary
 Function input: num1, num2 - the binary numbers
 Function Action: the function do binary addition.
 Function output: the result of the addition.
 **************************************************************************************************/
string Math::addBinary(string *num1, string *num2) {
    int num = 0;
    int i;
    string result = "";
    unsigned long int sizeNum1 = num1->size() - 1;
    unsigned long int sizeNum2 = num2->size() - 1;
    while ((num1->size() - 1 >= sizeNum1 && sizeNum1 >= 0) ||
           (num2->size() - 1 >= sizeNum2 && sizeNum2 >= 0) || num == 1) {
        if (num1->size() - 1 >= sizeNum1 && sizeNum1 >= 0) {
            num += num1->at(sizeNum1) - '0';
        }
        if (num2->size() - 1 >= sizeNum2 && sizeNum2 >= 0) {
            num += num2->at(sizeNum2) - '0';
        }
        result = char(num % 2 + '0') + result;
        // Compute carry
        num /= 2;
        // Move to next digits
        sizeNum1--;
        sizeNum2--;
    }
    // change to 8 bits
    if (result.size() % 8 != 0) {
        char c = result.at(0);
        for (i = 0; i < result.size() % 8; i++) {
            string d = "";
            d += c;
            result.insert(0, d);
        }
    }
    return result;
}

/**
 *
 * @param num1
 * @param num2
 * @param remainder
 * @return add the two numbers ans return them,
 * and change the remainder.
 */
string Math::addTwoNumbers(basic_string<char> num1, basic_string<char> num2,
                           basic_string<char> *remainder) {
    // add the numbers
    int result = (*num1.c_str() - '0') + (*num2.c_str() - '0') + *remainder->c_str();
    // update the remainder
    *remainder = (char) (result / 10);
    char a = (char) (result % 10) + '0';
    // return the result
    return (string) &a;
}

/**
 * implementation of plus operation
 * @param num1
 * @param num2
 * @return the addition num
 */
string Math::addDecimal(const string *num1, const string *num2) {
    unsigned long int i;
    string remainder = "";
    // new string for the result
    string result;
    string newResult;
    string num;
    string newNum1;
    string newNum2;
    string num1s = num1->substr(1);
    string num2s = num2->substr(1);
    // check if the first number negative and the second positive
    if (num1->at(0) == '-' && num2->at(0) != '-') {
        if (smallerThanOperator(&num1s, num2)) {
            return substractDecimal(num2, &num1s);
        } else {
            result = substractDecimal(&num1s, num2);
            if (result[0] == '0') {
                return result;
            }
            if (result.compare("0") == 0) {
                return result;
            }
            newResult = addMinusSign(result);
            return newResult;
        }
        // check if the first number positive and the second negative
    } else if (num1->at(0) != '-' && num2->at(0) == '-') {
        if (smallerThanOperator(&num2s, num1)) {
            return substractDecimal(num1, &num2s);
        } else {
            result = substractDecimal(&num2s, num1);
            if (result.compare("0") == 0) {
                return result;
            }
            newResult = addMinusSign(result);
            return newResult;
        }
        // check if both numbers negative
    } else if (num1->at(0) == '-' && num2->at(0) == '-') {
        result = addDecimal(&num1s, &num2s);
        if (result.compare("0") == 0) {
            return result;
        }
        newResult = addMinusSign(result);
        return newResult;
    }
    // change the size of the numbers to be the same
    size(num1, num2, &newNum1, &newNum2);
    // goes all the number and add every digit
    for (i = newNum1.size() - 1; newNum1.size() - 1 >= i && i >= 0; i--) {
        num = addTwoNumbers(&(newNum1.at(i)), &(newNum2.at(i)), &remainder);
        result.insert(0, num);
    }
    // add the reminder
    if (*remainder.c_str() > 0) {
        char a = remainder.at(0) + '0';
        string c = "";
        c = c + a;
        result.insert(0, c);
    }
    return result;
}

/**
 *
 * @param num1
 * @param num2
 * @param remainder
 * @return substract the two numbers return them,
 * and change the remainder.
 */
string Math::substractTwoNumbers(string num1, string num2, string *remainder) {
    // substract the two numbers
    int result = (int) (*num1.c_str() - '0') - (*num2.c_str() - '0') - *remainder->c_str();
    // update carry
    if (result < 0) {
        *remainder = 1;
        char a = (char) (10 + result + '0');
        return (string) &a;
    }
    *remainder = (char) 0;
    // save and return the result
    char a = (char) (result + '0');
    return (string) &a;
}

/**
 * implementation of minus operation
 * @param num1
 * @param num2
 * @return the minus num
 */
string Math::substractDecimal(const string *num1, const string *num2) {
    unsigned long int i;
    string num;
    string remainder = "";
    // string for the result
    string result;
    string newResult;
    string newNum1;
    string newNum2;
    // save the num without the minus
    string num1s = num1->substr(1);
    string num2s = num2->substr(1);
    // check if the first number negative and the second positive
    if (num1->at(0) == '-' && num2->at(0) != '-') {
        result = addDecimal(&num1s, num2);
        if (result.compare("0") == 0) {
            return result;
        }
        return addMinusSign(result);
        // check if the first number positive and the second negative
    } else if (num1->at(0) != '-' && num2->at(0) == '-') {
        return addDecimal(num1, &num2s);
        // check if both numbers negative
    } else if (num1->at(0) == '-' && num2->at(0) == '-') {
        if (smallerThanOperator(&num1s, &num2s)) {
            return (substractDecimal(&num2s, &num1s));
        }
        result = substractDecimal(&num1s, &num2s);
        if (result.at(0) == '0') {
            return result;
        }
        return (addMinusSign(result));
        // check if num1<num2
    } else if (smallerThanOperator(num1, num2)) {
        result = substractDecimal(num2, num1);
        if (result.compare("0") == 0) {
            return result;
        }
        return addMinusSign(result);
    }
    // change the size of the numbers to be the same
    size(num1, num2, &newNum1, &newNum2);
    // goes all the number and substract every digit
    for (i = newNum1.size() - 1; newNum1.size() - 1 >= i && i >= 0; i--) {
        num = substractTwoNumbers(&(newNum1.at(i)), &(newNum2.at(i)), &remainder);
        result.insert(0, num);
    }
    // update the remainder
    if (*remainder.c_str() > 0) {
        char a = remainder.at(0) + '0';
        string c = "";
        c = c + a;
        newResult.insert(0, c);
        return deleteZero(&newResult);

    }
    // return the result
    result = deleteZero(&result);
    return result;
}

/**
 * the function calculate long multiply
 * @param num1
 * @param num2
 * @return the multiply between num1 and num2
 */
string Math::multiplyDecimal(const string *num1, const string *num2) {
    string res;
    string num1s = num1->substr(1);
    string num2s = num2->substr(1);
    // check if both numbers are 0
    if (num1->at(0) == '0' || num2->at(0) == '0') {
        return "0";
        // check if the first number negative and the second positive
    } else if (num1->at(0) == '-' && num2->at(0) != '-') {
        res = multiplyDecimal(&num1s, num2);
        if (res.compare("0") == 0) {
            return res;
        }
        return addMinusSign(res);
        // check if the first number positive and the second negative
    } else if (num1->at(0) != '-' && num2->at(0) == '-') {
        res = multiplyDecimal(num1, &num2s);
        if (res.compare("0") == 0) {
            return res;
        }
        return addMinusSign(res);
        // check if both numbers are neg
    } else if (num1->at(0) == '-' && num2->at(0) == '-') {
        res = multiplyDecimal(&num1s, &num2s);
        return (res);
    }

    int n1 = num1->size();
    int n2 = num2->size();

    vector<int> result(n1 + n2, 0);

    int i;
    int index1 = 0;
    int index2 = 0;
    // multiply each digit of n1
    for (i = n1 - 1; i >= 0; i--) {
        int carry = 0;
        int n1 = num1->at(i) - '0';
        index2 = 0;
        // multiply the digit with each digit in n2
        for (int j = n2 - 1; j >= 0; j--) {
            int n2 = num2->at(j) - '0';

            int sum = n1 * n2 + result[index1 + index2] + carry;
            carry = sum / 10;
            result[index1 + index2] = sum % 10;
            index2++;
        }
        // check uf there is a carry
        if (carry > 0) {
            result[index1 + index2] += carry;
        }
        index1++;
    }

    // Skip zeroes from the left
    i = (int) result.size() - 1;
    while (i >= 0 && result[i] == 0) {
        i--;
    }
    if (i == -1) {
        return "0";
    }

    string str = "";
    while (i >= 0) {
        str += toString(result[i--]);
    }
    // return the multiply result
    return str;
}

/**
 *
 * @param num1 the number
 * @param num2 the power
 * @return the power of num1 in power of num2
 */
string Math::powerDecimal(const string *num1, const string *num2) {
    string num;
    // check if the number is 0 and the power is 1
    if (num2->at(0) == '0' && num2->size() == 1) {
        return "1";
    }
    string i = "1";
    num = *num1;
    // goes all the numbers between 1-num2
    while (i.compare(*num2) != 0) {
        // multiply the num
        num = multiplyDecimal(&num, num1);
        string one = "1";
        // increase i
        i = addDecimal(&i, &one);
    }
    return num;
}

/**
 * @param num1
 * @param num2
 * @return check if the first number is smaller then the second
 *  if so return 1 else 0
 */
bool Math::smallerThanOperator(const string *num1, const string *num2) {
    int i;
    // check if the first number negative and the second positive
    if (num1->at(0) == '-' && num2->at(0) != '-') {
        return true;
        // check if the first number positive and the second negative
    } else if (num1->at(0) != '-' && num2->at(0) == '-') {
        return false;
        // check if both numbers positive
    } else if (num1->at(0) != '-' && num2->at(0) != '-') {
        // check if size n1<n2
        if (num1->size() < num2->size()) {
            return true;
            // check if size n1=n2
        } else if (num1->size() == num2->size()) {
            // compare between every digit
            for (i = 0; i < num1->size(); i++) {
                if (num1->at(i) < num2->at(i)) {
                    return true;
                } else if (num1->at(i) > num2->at(i)) {
                    return false;
                }
            }
            return false;
        } else {
            return false;
        }
        // check if both numbers negative
    } else {
        string num1_sub = num1->substr(1);
        string num2_sub = num2->substr(1);
        return !smallerThanOperator(&num1_sub, &num2_sub);
    }
}

/**
 * @param num1
 * @param num2
 * @return check if the first number is bigger then the second
 *  if so return 1 else 0
 */
bool Math::biggerThanOperator(const string *num1, const string *num2) {
    int i;
    // check if the first number negative and the second positive
    if (num1->at(0) == '-' && num2->at(0) != '-') {
        return false;
        // check if the first number positive and the second negative
    } else if (num1->at(0) != '-' && num2->at(0) == '-') {
        return true;
        // check if both numbers positive
    } else if (num1->at(0) != '-' && num2->at(0) != '-') {
        // check if size n1>n2
        if (num1->size() > num2->size()) {
            return true;
            // check if size n1=n2
        } else if (num1->size() == num2->size()) {
            // compare between every digit
            for (i = 0; i < num1->size(); i++) {
                if (num1->at(i) > num2->at(i)) {
                    return true;
                } else if (num1->at(i) < num2->at(i)) {
                    return false;
                }
            }
            return false;
        } else {
            return false;
        }
        // check if both numbers negative
    } else {
        string num1_sub = num1->substr(1);
        string num2_sub = num2->substr(1);
        return !biggerThanOperator(&num1_sub, &num2_sub);
    }
}

/**
 *
 * @param num1
 * @param num2
 * @param rem the remainder
 * @return the division result
 */
string Math::divisionDecimal(const string *num1, const string *num2, string *rem) {
    string result;
    string num1s = num1->substr(1);
    string num2s = num2->substr(1);
    // check if the second number is 0
    if (num2->at(0) == '0') {
        throw overflow_error("Divide by zero");
        // if the first num is 0
    } else if (num1->at(0) == '0') {
        return "0";
        // check if the first number negative and the second positive
    } else if (num1->at(0) == '-' && num2->at(0) != '-') {
        result = divisionDecimal(&num1s, num2, rem);
        return addMinusSign(result);
        // check if the first number positive and the second negative
    } else if (num1->at(0) != '-' && num2->at(0) == '-') {
        result = divisionDecimal(num1, &num2s, rem);
        return addMinusSign(result);
        // check if both numbers negative
    } else if (num1->at(0) == '-' && num2->at(0) == '-') {
        result = divisionDecimal(&num1s, &num2s, rem);
        return (result);
    }
    string num = *num1;
    string i = "0";
    string one = "1";
    // substract the numbers
    while (num.at(0) != '-') {
        num = substractDecimal(&num, num2);
        i = addDecimal(&i, &one);
    }
    // update the rem
    *rem = addDecimal(&num, num2);
    return substractDecimal(&i, &one);
}

/**
 * the function compute long division algorytem.
 * @param num1
 * @param num2
 * @param rem the remainder
 * @return the division result
 */
string Math::longDivision(const string *number, const string *divisor, string *rem) {
    string result = "";
    string num = number->substr(1);
    string div = divisor->substr(1);
    // check if the second number is 0
    if (divisor->at(0) == '0') {
        throw overflow_error("Divide by zero");
        // if the first num is 0
    } else if (number->at(0) == '0') {
        *rem = "0";
        return "0";
        // check if the first number negative and the second positive
    } else if (number->at(0) == '-' && divisor->at(0) != '-') {
        result = longDivision(&num, divisor, rem);
        *rem = addMinusSign(*rem);
        // check id the result is zero
        if (result.compare("0") == 0) {
            return result;
        }
        return addMinusSign(result);
        // check if the first number positive and the second negative
    } else if (number->at(0) != '-' && divisor->at(0) == '-') {
        result = longDivision(number, &div, rem);
        //*rem = substractDecimal(rem, &div);
        if (result.compare("0") == 0) {
            return result;
        }
        return addMinusSign(result);
        // check if both numbers negative
    } else if (number->at(0) == '-' && divisor->at(0) == '-') {
        result = longDivision(&num, &div, rem);
        *rem = addMinusSign(*rem);
        return (result);
        // check if n1<n2
    } else if (smallerThanOperator(number, divisor)) {
        *rem = *number;
        return "0";
    }
    // first division
    long int i = 0;
    string mul;
    string temp = "";
    temp += number->at(i);
    string ten = "10";
    // calculate long division
    while (smallerThanOperator(&temp, divisor)) {
        mul = multiplyDecimal(&temp, &ten);
        temp = "";
        temp += number->at(++i);
        temp = addDecimal(&mul, &temp);
    }
    // calculate long division
    div = "";
    while (number->size() > i) {
        div = divisionDecimal(&temp, divisor, rem);
        result += div;
        mul = multiplyDecimal(rem, &ten);
        if (i < number->size() - 1) {
            temp = "";
            temp += number->at(++i);
            temp = addDecimal(&mul, &temp);
        } else {
            ++i;
        }
    }
    // if the number is empty->return 0
    if (number->size() == 0) {
        return "0";
    }
    return result;
}

/**
 * the function convert a decimal number
 * to binary number by thr two complete
 * @param arr
 * @return the binary number
 */
string Math::decimalToBinary(const string *arr) {
    // check if the num is 0 -> 00000000
    if (!arr->empty() && arr->at(0) == '0') {
        return "00000000";
    }

    // negative number
    if (arr->at(0) == '-') {
        string one = "1";
        string a = arr->substr(1);
        string binaryNum = decimalToBinary(&a);
        string notB = notBinary(&binaryNum);
        string result = addBinary(&notB, &one);
        return result;
    }

    string rem;
    string result = "";
    string num = *arr;
    unsigned long int i = 0;
    string two = "2";
    // divided the number in 2 until get 0
    while (num.at(0) != '0') {
        /* if the left bit is 1, and we dont have more space,
          oper new 8 bits*/
        if (i == 1 && (num.compare("1") != 0)) {
            result = increase(&result, result.size(), result.size() + 8);
            i += 8;
        }
        num = longDivision(&num, &two, &rem);
        // fill to the next multipl of 8
        if (i == 0) {
            result = increase(&result, result.size(), result.size() + 8);
            i = 8;
        }
        result.replace(--i, 1, rem);
    }
    // fill to the next multipl of 8
    if (result.at(0) == '1') {
        increase(&result, result.size(), result.size() + 8);
    }
    // return the binary number
    return result;
}

/**
 * the function convert a decimal number
 * to binary number by thr two complete
 * @param arr
 * @return the binary number
 */
string Math::decimalToBinary(const string arr) {
    return Math::decimalToBinary(&arr);
}

/**
 * the function convert a binary number
 * to decimal number by thr two complete
 * @param arr
 * @return the binary number
 */
string Math::binaryToDecimal(const string *arr) {
    unsigned long int i;
    string result = "0";
    string index = "";
    string two = "2";
    string p;
    // add all the power of two where there is 1
    for (int i = 1; i < arr->size(); i++) {
        if (arr->at(i) == '1') {
            index = toString(arr->size() - 1 - i);
            p = powerDecimal(&two, &index);
            // compute the number
            result = addDecimal(&result, &p);
        }
    }
    index = toString(arr->size() - 1);
    string sub;
    // if the number is neg
    if (arr->at(0) == '1') {
        // compute the power
        p = powerDecimal(&two, &index);
        // substrct this number from the result and return iy
        sub = substractDecimal(&result, &p);
        return sub;
    }
    // return the result
    return result;
}

/**
 * the function convert a binary number
 * to decimal number by thr two complete
 * @param arr
 * @return the binary number
 */
string Math::binaryToDecimal(const string arr) {
    return Math::binaryToDecimal(&arr);
}

/**************************************************
 Function Name: toString
 Function input: x - the num to convert
 Function Action: the function convert int to
 string and return the string
 *************************************************/
string Math::toString(const long int x) {
    ostringstream convert;
    convert << x;
    return convert.str();
}

/**************************************************
 Function Name: toInt
 Function input: x - the num to convert
 Function Action: the function convert string to
 int and return the int number
 *************************************************/
int Math::toInt(const string str) {
    int i = 0;
    istringstream(str) >> i;
    return i;
}



