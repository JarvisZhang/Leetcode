//
//  8.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/5/31.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: String to Integer (atoi)
//

#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, i = 0;
        long number = 0;
        while (i < str.length() && str[i] == ' ') {
            i++;
        }
        if (str[i] == '-') {
            sign = -1;
            i++;
        }
        else if (str[i] == '+') {
            i++;
        }
        for (; i < str.length(); i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                number = number * 10 + (str[i] - '0');
            }
            else {
                break;
            }
            if (number * sign >= INT_MAX) {
                return INT_MAX;
            }
            else if (number * sign <= INT_MIN) {
                return INT_MIN;
            }
        }
        return (int) number * sign;
    }
};

class Test {
private:
    void runTest(string str) {
        Solution solution;
        int result = solution.myAtoi(str);
        cout << str << ": " << result << endl;
    }
    
public:
    void sample() {
        string s1("");
        string s2("-2147483647");
        string s3("2147483647");
        string s4("-2147483648");
        string s5("2147483648");
        string s6("-2147483649");
        runTest(s1);
        runTest(s2);
        runTest(s3);
        runTest(s4);
        runTest(s5);
        runTest(s6);
    }
};
