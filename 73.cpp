//
//  73.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/8.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Set Matrix Zeroes
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        int i, j;
        for (i = 0; i < matrix.size() && matrix[i][0]; i++) ;
        for (j = 0; j < matrix[0].size() && matrix[0][j]; j++) ;
        const bool setFirstRow = j != matrix[0].size(), setFirstCol = i != matrix.size();
        for (i = 1; i < matrix.size(); i++) {
            for (j = 1; j < matrix[0].size(); j++) {
                if (!matrix[i][j]) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (i = 1; i < matrix.size(); i++) {
            for (j = 1; j < matrix[0].size() && !matrix[i][0]; j++) {
                matrix[i][j] = 0;
            }
        }
        for (j = 1; j < matrix[0].size(); j++) {
            for (i = 1; i < matrix.size() && !matrix[0][j]; i++) {
                matrix[i][j] = 0;
            }
        }
        for (j = 0; setFirstRow && j < matrix[0].size(); j++) {
            matrix[0][j] = 0;
        }
        for (i = 0; setFirstCol && i < matrix.size(); i++) {
            matrix[i][0] = 0;
        }
    }
};

class Test {
public:
    void sample() {
        vector<vector<int>> matrix({{0,0,0,5},{4,3,1,4},{0,1,1,4},{1,2,1,3},{0,0,1,1}});
        Solution solution;
        solution.setZeroes(matrix);
        for (auto row: matrix) {
            for (auto col: row) {
                cout << col;
            }
            cout << endl;
        }
    }
};