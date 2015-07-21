//
//  213.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/19.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: House Robber II
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int robLine(vector<int>& nums, int start, int end) {
        int robCur = 0, skipCur = 0;
        for (int i = start; i < end; i++) {
            int temp = skipCur + nums[i];
            skipCur = max(robCur, skipCur);
            robCur = temp;
        }
        return max(robCur, skipCur);
    }
    
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        int skipFirst = robLine(nums, 1, (int) nums.size());
        int robFirst = robLine(nums, 0, (int) nums.size() - 1);
        return max(skipFirst, robFirst);
    }
};