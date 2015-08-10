//
//  31.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/27.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Next Permutation
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int left = -1, right = -1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i+1]) {
                left = i;
                right = i + 1;
            }
            else if (left >= 0 && nums[left] < nums[i+1] && nums[i+1] <= nums[right]) {
                right = i + 1;
            }
        }
        swap(nums[left], nums[right]);
        for (int i = left + 1, j = (int) nums.size() - 1; i < j; i++, j--) {
            swap(nums[i], nums[j]);
        }
    }
};