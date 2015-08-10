//
//  78.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/30.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Subsets
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int length = pow(2, nums.size());
        vector<vector<int>> results(length, vector<int>());
        vector<int> current;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < length; j++) {
                if (((j >> i) & 1 ) == 1) {
                    results[j].push_back(nums[i]);
                }
            }
        }
        return results;
    }

    void subsetsRecur(vector<vector<int>> &results, vector<int> &nums, vector<int> &current, int loc) {
        if (loc == nums.size()) {
            results.push_back(current);
            return;
        }
        subsetsRecur(results, nums, current, loc + 1);
        current.push_back(nums[loc]);
        subsetsRecur(results, nums, current, loc + 1);
        current.pop_back();
    }
};

class Test {
public:
    void sample() {
        vector<int> nums({1,2,3});
        Solution solution;
        vector<vector<int>> results = solution.subsets(nums);
        for (auto result : results) {
            for (auto num : result) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};