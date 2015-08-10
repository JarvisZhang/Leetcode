//
//  54.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/8.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Spiral Matrix 
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return vector<int>();
        }
        int m = (int) matrix.size(), n = (int) matrix[0].size();
        vector<int> result(m * n);
        int loc = 0, circle = min (m, n) / 2;
        for (int i = 0; i < circle; i++) {
            for (int j = i; j < n - i - 1; j++) {
                result[loc++] = matrix[i][j];
            }
            for (int j = i; j < m - i - 1; j++) {
                result[loc++] = matrix[j][n-i-1];
            }
            for (int j = n - i - 1; j > i; j--) {
                result[loc++] = matrix[m-i-1][j];
            }
            for (int j = m - i - 1; j > i; j--) {
                result[loc++] = matrix[j][i];
            }
        }
        if (m <= n && m % 2) {
            copy(matrix[m/2].begin() + circle, matrix[m/2].end() - circle, result.begin() + loc);
        }
        else if (m > n && n % 2) {
            for (int j = circle; j < m - circle; j++) {
                result[loc++] = matrix[j][n/2];
            }
        }
        return result;
    }
};