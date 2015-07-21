//
//  70.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/20.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Climbing Stairs
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int current = 2, pre = 1;
        for (int i = 2; i < n; i++) {
            int next = current + pre;
            pre = current;
            current = next;
        }
        return current;
    }
};