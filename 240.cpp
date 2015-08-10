//
//  240.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/23.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Search a 2D Matrix II
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        int m = (int) matrix.size(), n = (int) matrix[0].size();
        int row = 0, col = n - 1;
        while (row < m && col >= 0) {
            if (matrix[row][col] > target) {
                col--;
            }
            else if (matrix[row][col] < target) {
                row++;
            }
            else {
                return true;
            }
        }
        return false;
    }
};