//
//  41.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/27.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: First Missing Positive
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (0 < nums[i] && nums[i] < nums.size() && nums[i] != i + 1 && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
            else {
                i++;
            }
        }
        i = 0;
        while (i < nums.size() && nums[i] == i + 1) {
            i++;
        }
        return i + 1;
    }
};