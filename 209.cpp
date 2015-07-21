//
//  209.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/2.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Minimum Size Subarray Sum
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int maxLength = INT_MAX, start = 0, end = 0, sum = 0;
        while (end < nums.size() || sum >= s) {
            if (sum >= s) {
                int currentLength = end - start;
                maxLength = (currentLength < maxLength) ? currentLength : maxLength;
                sum -= nums[start++];
            }
            else {
                sum += nums[end++];
            }
        }
        return (maxLength == INT_MAX) ? 0 : maxLength;
    }
};