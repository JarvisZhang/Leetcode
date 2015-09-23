//
//  43.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/12.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty() || num1 == "0" || num2 == "0") {
            return "0";
        }
        int len1 = (int) num1.size(), len2 = (int) num2.size();
        string result(len1 + len2, '0');
        for (int i = len1 - 1; i >= 0 ; i--) {
            int digit1 = num1[i] - '0', carry = 0;
            for (int j = len2 - 1; j >= 0; j--) {
                int digit2 = num2[j] - '0', loc = len1 + len2 - i - j - 2;
                int current = digit1 * digit2 + carry + (result[loc] - '0');
                result[loc] = '0' + current % 10;
                carry = current / 10;
            }
            result[len1 - 1 - i + num2.size()] = '0' + carry;
        }
        int zeroLoc = (int) result.size();
        while (result[--zeroLoc] == '0') ;
        result.erase(zeroLoc + 1);
        reverse(result.begin(), result.end());
        return result;
    }
};

class Test {
public:
    void sample() {
        string num1("98"), num2("9");
        Solution solution;
        cout << solution.multiply(num1, num2) << endl;
    }
};