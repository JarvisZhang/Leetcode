//
//  46.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/30.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Permutations
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> results;
        permuteRecur(results, nums, 0);
        return results;
    }
    
    void permuteRecur(vector<vector<int>> &results, vector<int> &nums, int loc) {
        if (loc == nums.size()) {
            results.push_back(nums);
            return;
        }
        permuteRecur(results, nums, loc + 1);
        for (int i = loc + 1; i < nums.size(); i++) {
            swap(nums[i], nums[loc]);
            permuteRecur(results, nums, loc + 1);
            swap(nums[i], nums[loc]);
        }
    }
};

class Test {
public:
    void sample() {
        vector<int> nums({1,2,3});
        Solution solution;
        vector<vector<int>> results = solution.permute(nums);
        for (auto result : results) {
            for (auto num : result) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};