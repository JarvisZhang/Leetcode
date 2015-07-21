//
//  34.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/16.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//
//  Title: Search for a Range

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return vector<int>({-1, -1});
        }
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
        int left = (nums[start] == target) ? start : -1;
        start = 0, end = (int) nums.size();
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (nums[middle] <= target) {
                start = middle + 1;
            }
            else {
                end = middle;
            }
        }
        int right = (nums[start - 1] == target) ? (start - 1) : -1;
        return vector<int>({left, right});
    }
};