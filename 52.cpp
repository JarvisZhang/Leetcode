//
//  52.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/28.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: N-Queens II 
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int total;
    bool isValid(vector<int> &queens, int current) {
        for (int i = 0; i < current; i++) {
            if (queens[i] == queens[current] || abs(queens[i] - queens[current]) == (current - i)) {
                return false;
            }
        }
        return true;
    }
    
    void totalNQueensRecur(vector<int> &queens, int &total, int n){
        if (n == queens.size()) {
            total++;
            return;
        }
        for (int i = 0; i < queens.size(); i++) {
            queens[n] = i;
            if (isValid(queens, n)) {
                totalNQueensRecur(queens, total, n + 1);
            }
        }
    }
    int totalNQueens(int n) {
        total = 0;
        vector<int> queens(n);
        totalNQueensRecur(queens, total, 0);
        return total;
    }
};

class Test {
public:
    void sample() {
        int n1 = 6;
        Solution solution;
        cout << solution.totalNQueens(n1) << endl;
    }
};