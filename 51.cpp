//
//  51.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/28.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: N-Queens
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(vector<int> &queens, int current) {
        for (int i = 0; i < current; i++) {
            if (queens[i] == queens[current] || abs(queens[i] - queens[current]) == abs(i - current)) {
                return false;
            }
        }
        return true;
    }
    
    vector<string> generateResult(vector<int> &queens) {
        vector<string> current;
        for (int i = 0; i < queens.size(); i++) {
            string row(queens.size(), '.');
            row[queens[i]] = 'Q';
            current.push_back(row);
        }
        return current;
    }
    
    void solveNQueensRecur(vector<vector<string>> &result, vector<int> &queens, int n) {
        if (n == queens.size()) {
            result.push_back(generateResult(queens));
            return;
        }
        for (int i = 0; i < queens.size(); i++) {
            queens[n] = i;
            if (isValid(queens, n)) {
                solveNQueensRecur(result, queens, n + 1);
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> queues(n);
        solveNQueensRecur(result, queues, 0);
        return result;
    }
};

class Test {
public:
    void sample() {
        Solution solution;
        int n = 10;
        vector<vector<string>> results = solution.solveNQueens(n);
        for (auto result : results) {
            for (auto str : result) {
                cout << str << endl;
            }
            cout << endl;
        }
    }
};