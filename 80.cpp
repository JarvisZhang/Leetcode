//
//  80.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/2.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Remove Duplicates from Sorted Array II
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int loc = 0;
        bool duplicated = false;
        for (int i = 1; i < nums.size(); i++) {
            if (!duplicated && nums[i] == nums[loc]) {
                duplicated = true;
                nums[++loc] = nums[i];
            }
            else if (nums[loc] != nums[i]) {
                duplicated = false;
                nums[++loc] = nums[i];
            }
        }
        return loc + 1;
    }
};