//
//  219.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/1.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Contains Duplicate II
//

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> history;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                history.erase(nums[i-k-1]);
            }
            if (!history.insert(nums[i]).second) {
                return true;
            }
        }
        return false;
    }
};