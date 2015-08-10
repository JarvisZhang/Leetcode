//
//  90.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/31.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Subsets II
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> results;
        int preCount = 1;
        sort(nums.begin(), nums.end());
        results.push_back(vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            int currentTotal = (int) results.size(), j = 0;
            if (i > 0 && nums[i] == nums[i-1]) {
                j = currentTotal - preCount;
            }
            preCount = 0;
            while (j < currentTotal) {
                results.push_back(results[j]);
                results.back().push_back(nums[i]);
                preCount++;
                j++;
            }
        }
        return results;
    }
    
    void subsetWithDupRecur(vector<vector<int>> &results, vector<int> &nums, vector<int> &current, vector<bool> selected, int loc) {
        if (loc == nums.size()) {
            results.push_back(current);
            return;
        }
        subsetWithDupRecur(results, nums, current, selected, loc + 1);
        if (loc > 0 && nums[loc-1] == nums[loc] && !selected[loc-1]) {
            return;
        }
        selected[loc] = true;
        current.push_back(nums[loc]);
        subsetWithDupRecur(results, nums, current, selected, loc + 1);
        current.pop_back();
    }
};

class Test {
public:
    void sample() {
        vector<int> nums({1,2,2,2,3});
        Solution solution;
        vector<vector<int>> results = solution.subsetsWithDup(nums);
        for (auto result : results) {
            for (auto num : result) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};