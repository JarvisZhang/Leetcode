//
//  200.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/8.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Number of Islands
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    markIsland(grid, i, j);
                }
            }
        }
        return count;
    }
    
    void markIsland(vector<vector<char>> &grid, int row, int col) {
        if (grid[row][col] != '1') {
            return;
        }
        grid[row][col] = '0';
        if (row > 0) {
            markIsland(grid, row - 1, col);
        }
        if (row < grid.size() - 1) {
            markIsland(grid, row + 1, col);
        }
        if (col > 0) {
            markIsland(grid, row, col - 1);
        }
        if (col < grid[0].size() - 1) {
            markIsland(grid, row, col + 1);
        }
    }
};
