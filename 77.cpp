//
//  77.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/30.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Combinations
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current(k, 1);
        int index = 0;
        while (true) {
            if (current[0] == n - k + 2) {
                break;
            }
            else if (current[index] == n + 1) {
                current[--index]++;
            }
            else if (index == k - 1) {
                result.push_back(current);
                current[index]++;
            }
            else {
                index++;
                current[index] = current[index-1] + 1;
            }
        }
        return result;
    }
    
    void combineRecur(vector<vector<int>> &result, vector<int> &current, int n, int k, int loc) {
        int length = (int) current.size();
        if (length == k) {
            result.push_back(current);
            return;
        }
        if (loc > n - (k - length) + 1) {
            return;
        }
        combineRecur(result, current, n, k, loc + 1);
        current.push_back(loc);
        combineRecur(result, current, n, k, loc + 1);
        current.pop_back();
    }
};

class Test {
public:
    void sample() {
        int n = 4, k = 2;
        Solution solution;
        vector<vector<int>> results = solution.combine(n, k);
        for (auto result : results) {
            for (auto num : result) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};