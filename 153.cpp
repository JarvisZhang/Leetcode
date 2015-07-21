//
//  153.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/17.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Find Minimum in Rotated Sorted Array
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = (int) nums.size(), minimum = nums[0];
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (nums[start] < nums[middle]) {
                minimum = min(minimum, nums[start]);
                start = middle + 1;
            }
            else {
                minimum = min(minimum, nums[middle]);
                end = middle;
            }
        }
        return minimum;
    }
    
    int findMin_compare3(vector<int>& nums) {
        int start = 0, end = (int) nums.size() - 1;
        while (start <= end) {
            int middle = start + (end - start) / 2;
            int smaller = (nums[start] > nums[middle]) ? nums[middle] : nums[start];
            int smallest = (nums[end] > smaller) ? smaller : nums[end];
            if (nums[start] == smallest) {
                return smallest;
            }
            else if (nums[end] == smallest) {
                start = middle + 1;
            }
            else {
                end = middle;
            }
        }
        return INT_MIN;
    }
};
