//
//  137.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/31.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Single Number II
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0, threes = 0;
        for (int i = 0; i < nums.size(); i++) {
            twos |= ones & nums[i];
            ones ^= nums[i];
            threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }
};