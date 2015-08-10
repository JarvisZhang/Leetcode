//
//  191.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/2.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Number of 1 Bits
//

#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
};