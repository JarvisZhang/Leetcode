//
//  220.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/9.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Contains Duplicate III
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> history;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                history.erase(nums[i-k-1]);
            }
            auto lower = history.lower_bound(nums[i] - t);
            if (lower != history.end() && *lower - nums[i] <= t) {
                return true;
            }
            history.insert(nums[i]);
        }
        
        return false;
    }
};

class Test {
public:
    void sample() {
        vector<int> nums({4,2});
        int k = 2, t = 1;
        Solution solution;
        cout << solution.containsNearbyAlmostDuplicate(nums, k, t);
    }
};