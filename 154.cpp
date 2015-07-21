//
//  154.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/17.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Find Minimum in Rotated Sorted Array II
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) {
            return INT_MIN;
        }
        int start = 0, end = (int) nums.size(), minimum = nums[0];
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (nums[start] < nums[middle]) {
                minimum = min(minimum, nums[start]);
                start = middle + 1;
            }
            else if (nums[start] > nums[middle]) {
                minimum = min(minimum, nums[middle]);
                end = middle;
            }
            else {
                minimum = min(minimum, nums[middle]);
                start++;
            }
        }
        return minimum;
    }
};