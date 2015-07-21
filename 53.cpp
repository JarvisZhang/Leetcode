//
//  53.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/5.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Maximum Subarray
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN, i = 0, nsize = (int) nums.size(), current = 0;
        while (i < nsize) {
            current += nums[i++];
            result = max(current, result);
            current = (current < 0) ? 0 : current;
        }
        return result;
    }
};
