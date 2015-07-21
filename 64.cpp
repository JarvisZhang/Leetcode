//
//  64.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/17.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Minimum Path Sum
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int m = (int) grid.size(), n = (int) grid[0].size();
        int path[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i != 0 && j!= 0) {
                    path[i][j] = min(path[i-1][j], path[i][j-1]) + grid[i][j];
                }
                else if (i == 0 && j != 0) {
                    path[i][j] = path[i][j-1] + grid[i][j];
                }
                else if (i != 0 && j == 0) {
                    path[i][j] = path[i-1][j] + grid[i][j];
                }
                else {
                    path[i][j] = grid[i][j];
                }
            }
        }
        return path[m-1][n-1];
    }
};
