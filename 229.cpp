//
//  229.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/28.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Majority Element II
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = INT_MIN, count1 = 0, num2 = INT_MAX, count2 = 0, length = (int) nums.size();
        for (int i = 0; i < length; i++) {
            if (count1 == 0 && nums[i] != num2) {
                count1++;
                num1 = nums[i];
            }
            else if (nums[i] == num1) {
                count1++;
            }
            else if (count2 == 0 && nums[i] != num1) {
                count2++;
                num2 = nums[i];
            }
            else if (nums[i] == num2) {
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }
        int i;
        for (i = 0, count1 = 0, count2 = 0; i < length && (count1 <= length / 3 || count2 <= length / 3); i++) {
            if (nums[i] == num1) {
                count1++;
            }
            else if (nums[i] == num2) {
                count2++;
            }
        }
        vector<int> result;
        if (count1 > length / 3) {
            result.push_back(num1);
        }
        if (count2 > length / 3) {
            result.push_back(num2);
        }
        return result;
    }
};