//
//  241.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/14.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Different Ways to Add Parentheses
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void analyseInput(string &input, vector<int> &nums, vector<char> &ops) {
        int current = 0;
        for (char ch: input) {
            if (ch == '+' || ch == '-' || ch == '*') {
                ops.push_back(ch);
                nums.push_back(current);
                current = 0;
            }
            else {
                current = current * 10 + ch - '0';
            }
        }
        nums.push_back(current);
    }
    
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<char> ops;
        analyseInput(input, nums, ops);
        int length = (int) nums.size();
        vector<vector<vector<int>>> result(length, vector<vector<int>>(length, vector<int>()));
        for (int i = 0; i < length; i++) {
            result[0][i].push_back(nums[i]);
        }
        for (int i = 1; i < length; i++) {
            for (int j = 0; j < length - i; j++) {
                for (int p = 0; p < i; p++) {
                    for (int num1: result[p][j]) {
                        for (int num2: result[i-p-1][j+p+1]) {
                            int current = 0;
                            switch (ops[p+j]) {
                                case '+':
                                    current = num1 + num2;
                                    break;
                                case '-':
                                    current = num1 - num2;
                                    break;
                                case '*':
                                    current = num1 * num2;
                                    break;
                                default:
                                    break;
                            }
                            result[i][j].push_back(current);
                        }
                    }
                }
            }
        }
        return result.back()[0];
    }
};

class Test {
public:
    void sample() {
        string input("5+6*2-3+6");
        Solution solution;
        vector<int> result = solution.diffWaysToCompute(input);
        for (int num: result) {
            cout << num << endl;
        }
    }
};