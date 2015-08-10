//
//  216.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/31.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Combination Sum III
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> results;
        vector<int> current;
        combinationSum3Recur(results, current, n, 1, k);
        return results;
    }
    
    void combinationSum3Recur(vector<vector<int>> &results, vector<int> &current, int sum, int pos, int &k) {
        if (current.size() == k) {
            if (sum == 0) {
                results.push_back(current);
            }
            return;
        }
        for (int i = pos; i <= 9; i++) {
            current.push_back(i);
            combinationSum3Recur(results, current, sum - i, i + 1, k);
            current.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3Iter(int k, int n) {
        vector<vector<int>> results;
        if (k <= 0) {
            return results;
        }
        vector<int> current(k,1);
        int index = 1, sum = 1;
        while (index > 0 && current[0] <= min(n / k, 9)) {
            if (sum >= n) {
                if (sum == n && index == k) {
                    results.push_back(current);
                }
                sum = sum - current[--index] + 1;
                current[index-1]++;
            }
            else {
                if (current[index-1] == 9) {
                    sum = sum - current[--index] + 1;
                    if (index > 0) {
                        current[index-1]++;
                    }
                }
                else if (index < k) {
                    current[index] = current[index-1] + 1;
                    sum += current[index++];
                }
                else {
                    current[index-1]++;
                    sum++;
                }
            }
        }
        return results;
    }
};

class Test {
public:
    void sample() {
        int k = 3, n = 9;
        Solution solution;
        vector<vector<int>> results = solution.combinationSum3(k, n);
        for (auto result : results) {
            for (auto num : result) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};