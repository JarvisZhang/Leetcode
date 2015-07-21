//
//  63.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/15.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Unique Paths II
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) {
            return INT_MIN;
        }
        long m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!obstacleGrid[i][j]) {
                    int fromLeft = j == 0 ? 0 : grid[i][j-1];
                    int fromTop = i == 0 ? 0 : grid[i-1][j];
                    grid[i][j] = (i == 0 && j == 0) ? 1 : fromLeft + fromTop;
                }
            }
        }
        return grid[m-1][n-1];
    }
};