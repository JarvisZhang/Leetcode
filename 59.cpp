//
//  59.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/8.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Spiral Matrix II
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n < 1) {
            return vector<vector<int>>();
        }
        vector<vector<int>> matrix(n, vector<int>(n));
        int num = 1;
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - i - 1; j++) {
                matrix[i][j] = num++;
            }
            for (int j = i; j < n - i - 1; j++) {
                matrix[j][n-i-1] = num++;
            }
            for (int j = n - i - 1; j > i; j--) {
                matrix[n-i-1][j] = num++;
            }
            for (int j = n - i - 1; j > i; j--) {
                matrix[j][i] = num++;
            }
        }
        if (n % 2) {
            matrix[n/2][n/2] = num;
        }
        return matrix;
    }
};