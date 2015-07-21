//
//  62.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/15.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Unique Paths
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = (i == 0 || j ==0) ? 1 : grid[i][j-1] + grid[i-1][j];
            }
        }
        return grid[m-1][n-1];
    }
};