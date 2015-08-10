//
//  39.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/29.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Combination Sum
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        combinationSumRecur(results, current, candidates, target, 0);
        return results;
    }
    
    void combinationSumRecur(vector<vector<int>> &result, vector<int> &current, vector<int> &candidates, int target, int loc) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            result.push_back(current);
            return;
        }
        for (int i = loc; i < candidates.size(); i++) {
            if (i > 0 && candidates[i] == candidates[i-1]) {
                continue;
            }
            current.push_back(candidates[i]);
            combinationSumRecur(result, current, candidates, target - candidates[i], i);
            current.pop_back();
        }
    }
};

class Test {
public:
    void sample() {
        vector<int> input({2,3,6,7});
        int target = 7;
        Solution solution;
        vector<vector<int>> results = solution.combinationSum(input, target);
        for (auto result : results) {
            for (auto num : result) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};