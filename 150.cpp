//
//  150.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/30.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Evaluate Reverse Polish Notation
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    static pair<int, int> getNumberPair(stack<int> &numbers) {
        int second = numbers.top();
        numbers.pop();
        int first = numbers.top();
        numbers.pop();
        return make_pair(first, second);
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for (string str : tokens) {
            if (!str.compare("+")) {
                pair<int, int> numberPair = getNumberPair(numbers);
                numbers.push(numberPair.first + numberPair.second);
            }
            else if (!str.compare("-")) {
                pair<int, int> numberPair = getNumberPair(numbers);
                numbers.push(numberPair.first - numberPair.second);
            }
            else if (!str.compare("*")) {
                pair<int, int> numberPair = getNumberPair(numbers);
                numbers.push(numberPair.first * numberPair.second);
            }
            else if (!str.compare("/")) {
                pair<int, int> numberPair = getNumberPair(numbers);
                numbers.push(numberPair.first / numberPair.second);
            }
            else {
                numbers.push(stoi(str));
            }
        }
        return numbers.top();
    }
};