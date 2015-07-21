//
//  35.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/15.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Search Insert Position
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = (int) nums.size();
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (nums[middle] >= target) {
                end = middle;
            }
            else {
                start = middle + 1;
            }
        }
        return start;
    }
};
