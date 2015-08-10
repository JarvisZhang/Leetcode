//
//  136.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/31.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Single Number
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.empty()) {
            return INT_MIN;
        }
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            result ^= nums[i];
        }
        return result;
    }
};