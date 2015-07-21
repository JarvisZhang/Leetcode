//
//  155.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/12.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Ttile: Min Stack
//

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    stack<long> myStack;
    long minimum = INT_MAX;
    
    void push(int x) {
        long val = x - minimum;
        this -> myStack.push(val);
        if (val < 0) {
            this -> minimum = x;
        }
    }
    
    void pop() {
        long val = this -> myStack.top();
        this -> myStack.pop();
        if (val < 0) {
            this -> minimum = this -> minimum - val;
        }
    }
    
    int top() {
        long val = this -> myStack.top();
        if (val < 0) {
            return (int) this -> minimum;
        }
        else {
            return (int) (this -> minimum + myStack.top());
        }
    }
    
    int getMin() {
        return (int) this -> minimum;
    }
};