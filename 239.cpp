//
//  239.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/27.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Sliding Window Maximum
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> potentialMax;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (potentialMax.empty()) {
                potentialMax.push_back(i);
            }
            else {
                if (i - potentialMax.front() >= k) {
                    potentialMax.pop_front();
                }
                while (!potentialMax.empty() && nums[potentialMax.back()] <= nums[i]) {
                    potentialMax.pop_back();
                }
                potentialMax.push_back(i);
            }
            if (i >= k - 1) {
                result.push_back(nums[potentialMax.front()]);
            }
        }
        return result;
    }
};