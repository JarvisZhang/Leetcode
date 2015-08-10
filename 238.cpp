//
//  238.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/23.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Product of Array Except Self
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = (int) nums.size();
        vector<int> result (length, 1);
        if (nums.empty()) {
            return result;
        }
        for (int i = 1; i < length; i++) {
            result[i] = result[i-1] * nums[i-1];
        }
        int right = nums[length-1];
        for (int i = length - 2; i >= 0; i--) {
            result[i] *= right;
            right *= nums[i];
        }
        return result;
    }
};