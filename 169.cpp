//
//  169.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/11.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Majority Element
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int start = 0, end = (int) nums.size() - 1, count = 0;
        while (start < end) {
            if (nums[start] != nums[end]) {
                if (count) {
                    count--;
                }
                else {
                    start++;
                }
            }
            else {
                count++;
            }
            end--;
        }
        return nums[start];
    }
};