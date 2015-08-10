//
//  47.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/30.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Permutations II
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> current;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        permuteUniqueRecur(results, nums, current, visited);
        return results;
    }
    
    void permuteUniqueRecur(vector<vector<int>> &results, vector<int> &nums, vector<int> &current, vector<bool> &visited) {
        if (current.size() == nums.size()) {
            results.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] || (i > 0 && nums[i] == nums[i-1] && !visited[i-1])) {
                continue;
            }
            visited[i] = true;
            current.push_back(nums[i]);
            permuteUniqueRecur(results, nums, current, visited);
            current.pop_back();
            visited[i] = false;
        }
    }
};

class Test {
public:
    void sample() {
        vector<int> nums({0,2,2});
        Solution solution;
        vector<vector<int>> results = solution.permuteUnique(nums);
        for (auto result : results) {
            for (auto num : result) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};