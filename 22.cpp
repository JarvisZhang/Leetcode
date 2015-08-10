//
//  22.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/26.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Generate Parentheses
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current("");
        generateParenthesisRecur(current, result, n, n);
        return result;
    }
    
    void generateParenthesisRecur(string &current, vector<string> &result, int leftNum, int rightNum) {
        if (leftNum == 0 && rightNum == 0) {
            result.push_back(current);
            return;
        }
        if (leftNum > 0) {
            current.push_back('(');
            generateParenthesisRecur(current, result, leftNum - 1, rightNum);
            current.pop_back();
        }
        if (rightNum > leftNum) {
            current.push_back(')');
            generateParenthesisRecur(current, result, leftNum, rightNum - 1);
            current.pop_back();
        }
        return;
    }
};