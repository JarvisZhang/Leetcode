//
//  225.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/1.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Implement Stack using Queues
//

#include <iostream>
#include <queue>

using namespace std;

class Stack {
public:
    queue<int> myQueue1;
    queue<int> myQueue2;
    
    void moveQueue(queue<int> &source, queue<int> &destination) {
        while (!source.empty()) {
            destination.push(source.front());
            source.pop();
        }
    }
    
    // Push element x onto stack.
    void push(int x) {
        if (myQueue1.empty()) {
            myQueue1.push(x);
            moveQueue(myQueue2, myQueue1);
        }
        else {
            myQueue2.push(x);
            moveQueue(myQueue1, myQueue2);
        }
    }
    
    // Removes the element on top of the stack.
    void pop() {
        if (!myQueue1.empty()) {
            myQueue1.pop();
        }
        else {
            myQueue2.pop();
        }
    }
    
    // Get the top element.
    int top() {
        if (!myQueue1.empty()) {
            return myQueue1.front();
        }
        return myQueue2.front();
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return myQueue1.empty() && myQueue2.empty();
    }
};