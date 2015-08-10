//
//  224.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/3.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Basic Calculator
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    void calcuStack(stack<char> &opStack, stack<int> &nums) {
        if (nums.size() < 1 || opStack.empty() || opStack.top() == '(') {
            return;
        }
        if (opStack.top() == '+') {
            opStack.pop();
            int temp = nums.top();
            nums.pop();
            nums.top() += temp;
        }
        else if (opStack.top() == '-') {
            opStack.pop();
            int temp = nums.top();
            nums.pop();
            nums.top() -= temp;
        }
        else if (opStack.top() == ')') {
            opStack.pop();
            opStack.pop();
            calcuStack(opStack, nums);
        }
    }
    
    int calculate(string s) {
        stack<char> opStack;
        stack<int> nums;
        int current = -1;
        for (int i = 0; i < s.size(); i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                current = current == -1 ? s[i] - '0' : current * 10 + s[i] - '0';
            }
            else if (s[i] == ' ') {
                continue;
            }
            else {
                if (current != -1) {
                    nums.push(current);
                }
                current = -1;
                if (s[i] != '(') {
                    calcuStack(opStack, nums);
                }
                opStack.push(s[i]);
            }
        }
        if (current != -1) {
            nums.push(current);
        }
        calcuStack(opStack, nums);
        return nums.top();
    }
};

class Test {
public:
    void runTest(string s) {
        Solution solution;
        cout << s << ": " << solution.calculate(s) << endl;
    }
    
    void sample() {
        string s1("((1+( 4+5 +2)-3)+(6+8) - (10 + 3))");
        runTest(s1);
    }
};