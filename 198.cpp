//
//  198.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/19.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: House Robber
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int robCur = 0, skipCur = 0;
        for (int i = 0; i < nums.size(); i++) {
            int temp = skipCur + nums[i];
            skipCur = max(robCur, skipCur);
            robCur = temp;
        }
        return max(robCur, skipCur);
    }
};