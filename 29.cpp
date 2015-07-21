//
//  29.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/19.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Divide Two Integers
//

#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned int dividend_u = dividend, divisor_u = divisor;
        int sign = 1;;
        if (!divisor_u || dividend > INT_MAX) {
            return INT_MAX;
        }
        if (dividend < 0) {
            dividend_u = -dividend;
            sign = -sign;
        }
        if (divisor < 0) {
            divisor_u = - divisor;
            sign = -sign;
        }
        long currentDivisor = divisor_u;
        unsigned int step = 0, result_u = 0;
        while (currentDivisor <= dividend_u) {
            currentDivisor <<= 1;
            step++;
        }
        currentDivisor = currentDivisor >> 1;
        while (step) {
            if (currentDivisor <= dividend_u) {
                dividend_u -= currentDivisor;
                result_u += (1 << (step - 1));
            }
            currentDivisor >>= 1;
            step--;
        }
        if (result_u > INT_MAX && sign == 1) {
            return INT_MAX;
        }
        int result = result_u;
        if (sign == -1) {
            result = -result;
        }
        return result;
    }
};

class Test {
private:
    void runTest(int dividend, int divisor) {
        Solution solution;
        int result = solution.divide(dividend, divisor);
        cout << result << endl;
    }
    
public:
    void sample() {
        int dividend1 = 0, divisor1 = 1;
        int dividend2 = 5, divisor2 = 2;
        int dividend3 = -5, divisor3 = 2;
        int dividend4 = -2147483648, divisor4 = -1;
        int dividend5 = -2147483648, divisor5 = 1;
        int dividend6 = 2147483647, divisor6 = 3;
        runTest(dividend1, divisor1);
        runTest(dividend2, divisor2);
        runTest(dividend3, divisor3);
        runTest(dividend4, divisor4);
        runTest(dividend5, divisor5);
        runTest(dividend6, divisor6);
    }
};
