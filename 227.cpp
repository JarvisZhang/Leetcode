//
//  227.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/6.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Basic Calculator II
//

#include <iostream>

using namespace std;

class Solution {
public:
    int getNum(string &s, int &i) {
        int num = 0;
        while (i < s.size() && (('0' <= s[i] && s[i] <= '9' ) || s[i] == ' ')) {
            if (s[i] != ' ') {
                num = num * 10 + s[i] - '0';
            }
            i++;
        }
        return num;
    }
    
    int multiOrDivide(string &s, int &i) {
        int result = getNum(s, i);
        while (s[i] == '*' || s[i] == '/') {
            if (s[i] == '*') {
                result *= getNum(s, ++i);
            }
            else if (s[i] == '/') {
                result /= getNum(s, ++i);
            }
        }
        return result;
    }
    
    int calculate(string s) {
        int i = 0, result = multiOrDivide(s, i);
        while (i < s.size()) {
            if (s[i] == '+') {
                result += multiOrDivide(s, ++i);
            }
            else if (s[i] == '-') {
                result -= multiOrDivide(s, ++i);
            }
        }
        return result;
    }
    
    int calculateRecur(string &s, int &i) {
        int result = getNum(s, i);
        while (i < s.size()) {
            if (s[i] == '+') {
                return result + calculateRecur(s, ++i);
            }
            else if (s[i] == '-') {
                return result - calculateRecur(s, ++i);
            }
            else if (s[i] == '*') {
                result *= getNum(s, ++i);
            }
            else if (s[i] == '/') {
                result /= getNum(s, ++i);
            }
        }
        return result;
    }
};

class Test {
public:
    void sample() {
        string s(" 1 3 +5 / 2 ");
        Solution solution;
        cout << s << ": " << solution.calculate(s) << endl;
    }
};