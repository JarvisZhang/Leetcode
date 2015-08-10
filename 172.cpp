//
//  172.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/2.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Factorial Trailing Zeroes
//

#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        long factor = 5, current = n / factor;
        while (current != 0) {
            result += current;
            factor *= 5;
            current = n / factor;
        }
        return result;
    }
};