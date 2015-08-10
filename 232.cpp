//
//  232.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/25.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Implement Queue using Stacks
//

#include <iostream>
#include <vector>

using namespace std;

class Queue {
private:
    vector<int> pushStack, popStack;
    void transferStack() {
        if (popStack.empty()) {
            copy(pushStack.rbegin(), pushStack.rend(), back_inserter(popStack));
            pushStack.clear();
        }
    }
    
public:
    // Push element x to the back of queue.
    void push(int x) {
        pushStack.push_back(x);
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        transferStack();
        popStack.pop_back();
    }
    
    // Get the front element.
    int peek(void) {
        transferStack();
        return popStack.back();
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        return pushStack.empty() && popStack.empty();
    }
};