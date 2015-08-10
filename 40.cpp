//
//  40.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/29.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Combination Sum II
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        combinationSum2Recur(results, current, candidates, target, 0);
        return results;
    }
    
    void combinationSum2Recur(vector<vector<int>> &result, vector<int> &current, vector<int> &candidates, int target, int loc) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0 || loc >= candidates.size()) {
            return;
        }
        for (int i = loc; i < candidates.size(); i++) {
            if (i > loc && candidates[i] == candidates[i-1]) {
                continue;
            }
            current.push_back(candidates[i]);
            combinationSum2Recur(result, current, candidates, target - candidates[i], i + 1);
            current.pop_back();
        }
    }
};

class Test {
public:
    void sample() {
        vector<int> input({1,1,1,1,2});
        int target = 2;
        Solution solution;
        vector<vector<int>> results = solution.combinationSum2(input, target);
        for (auto result : results) {
            for (auto num : result) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};