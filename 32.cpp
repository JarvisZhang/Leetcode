//
//  32.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/18.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Longest Valid Parentheses
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0, count = 0, start = 0, end = (int) s.size() - 1;
        for (int i = 0; i < end; i++) {
            if (s[i] == '(') {
                count++;
            }
            else {
                count--;
                if (count == 0) {
                    result = max(i - start + 1, result);
                }
                else if (count < 0) {
                    count = 0;
                    start = i + 1;
                }
            }
        }
        start = 0; count = 0;
        for (int j = end; j >= 0; j--) {
            if (s[j] == ')') {
                count++;
            }
            else {
                count--;
                if (count == 0) {
                    result = max(end - j + 1, result);
                }
                else if (count < 0) {
                    count = 0;
                    end = j - 1;
                }
            }
        }
        return result;
    }
    
    int longestValidParenthesesDP(string s) {
        stack<int> leftLoc;
        int result = 0;
        leftLoc.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                leftLoc.push(i);
            }
            else if (leftLoc.top() != -1 && s[leftLoc.top()] == '(') {
                leftLoc.pop();
                int current = i - leftLoc.top();
                result = max(result, current);
            }
            else {
                leftLoc.push(i);
            }
        }
        return result;
    }
};