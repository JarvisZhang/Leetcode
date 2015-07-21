//
//  81.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/16.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Search in Rotated Sorted Array II
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = (int) nums.size();
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (nums[middle] == target) {
                return true;
            }
            if ((nums[start] <= target && target <= nums[middle]) ||
                ((nums[start] > nums[middle]) && (nums[start] <= target || target <= nums[middle]))) {
                end = middle;
            }
            else if (nums[start] == nums[middle]) {
                while (start <= middle && nums[++start] == nums[middle]) ;
            }
            else {
                start = middle + 1;
            }
        }
        return false;
    }
};