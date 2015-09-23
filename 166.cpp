//
//  166.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/14.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Fraction to Recurring Decimal
//

#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!denominator) {
            return "";
        }
        if (!numerator) {
            return "0";
        }
        stringstream integer, decimal;
        long dividend = numerator, divisor = denominator;
        bool positive = true;
        if (dividend < 0) {
            dividend = -dividend;
            positive = !positive;
        }
        if (denominator < 0) {
            divisor = -divisor;
            positive = !positive;
        }
        if (!positive ) {
            integer << "-";
        }
        integer << (dividend / divisor);
        dividend %= divisor;
        if (dividend) {
            integer << ".";
        }
        unordered_map<long, long> repeat;
        int loc = 0;
        while (dividend) {
            if (repeat.find(dividend) != repeat.end()) {
                return integer.str() + decimal.str().substr(0, repeat[dividend]) + "(" + decimal.str().substr(repeat[dividend]) + ")";
            }
            else {
                repeat[dividend] = loc++;
                dividend *= 10;
                decimal << (dividend / divisor);
                dividend %= divisor;
            }
        }
        return integer.str() + decimal.str();
    }
};

class Test {
public:
    void sample() {
        int n = -1, d = -2147483648;
        Solution solution;
        cout << solution.fractionToDecimal(n, d);
    }
};