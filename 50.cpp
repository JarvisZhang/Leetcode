//
//  50.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/21.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Pow(x, n)
//

#include <iostream>

using namespace std;

class Solution {
private:
    static double doPow(double x, int n) {
        if (!n) {
            return 1;
        }
        double result = doPow(x, n / 2);
        result *= result;
        if (n % 2) {
            result *= x;
        }
        return result;
    }

public:
    double myPow(double x, int n) {
        if (n < 0) {
            return 1 / doPow(x, -n);
        }
        else {
            return doPow(x, n);
        }
    }
};