//
//  45.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/25.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Jump Game II
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int current = 0, maxDistance = 0, step = 0;
        for (int i = 0; i < nums.size() && maxDistance < nums.size() - 1; i++) {
            if (i > maxDistance) {
                step++;
                maxDistance = current;
            }
            else if (i > current) {
                return -1;
            }
            current = max(current, i + nums[i]);
        }
        return step;
    }
    
    int jump_step(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        vector<int> step(nums.size(), 0);
        for (int i = 0, j = 1; i < nums.size() && j < step.size() && i < j; i++) {
            int current = step[i] + 1;
            while (j <= i + nums[i] && j < step.size()) {
                step[j++] = current;
            }
        }
        return step[step.size() - 1] == 0 ? -1 : step[nums.size() - 1];
    }
};