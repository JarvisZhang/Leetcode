//
//  152.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/17.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return INT_MIN;
        }
        int currentMax = nums[0], currentMin = nums[0], result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int temp1 = currentMin * nums[i], temp2 = currentMax * nums[i];
            currentMax = max(max(temp1, temp2), nums[i]);
            currentMin = min(min(temp1, temp2), nums[i]);
            result = max(currentMax, result);
        }
        return result;
    }
};