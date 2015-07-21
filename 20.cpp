//
//  20.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/29.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Valid Parentheses
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> leftParentheses;
        for (auto ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                leftParentheses.push(ch);
            }
            else if (leftParentheses.empty()) {
                return false;
            }
            else if ((ch == ')' && leftParentheses.top() == '(') ||
                     (ch == ']' && leftParentheses.top() == '[') ||
                     (ch == '}' && leftParentheses.top() == '{')) {
                leftParentheses.pop();
            }
            else {
                return false;
            }
        }
        return leftParentheses.empty();
    }
};