//
//  162.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/17.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Find Peak Element
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = (int) nums.size();
        while (start < end) {
            int middle = start + (end - start) / 2;
            if ((middle == 0 || nums[middle-1] < nums[middle]) &&
                (middle == nums.size() - 1 || nums[middle+1] < nums[middle])) {
                return middle;
            }
            else if (middle != 0 && nums[middle-1] >= nums[middle]) {
                end = middle;
            }
            else if (middle != nums.size() - 1 && nums[middle+1] >= nums[middle]) {
                start = middle + 1;
            }
        }
        return -1;
    }
};