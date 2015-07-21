//
//  74.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/16.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Search a 2D Matrix
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start1 = 0, end1 = (int) matrix.size();
        while (start1 < end1) {
            int middle = start1 + (end1 - start1) / 2;
            if (matrix[middle][0] == target) {
                return true;
            }
            else if (matrix[middle][0] > target) {
                end1 = middle;
            }
            else {
                start1 = middle + 1;
            }
        }
        int row = start1 - 1;
        if (row < 0 || row > matrix.size()) {
            return false;
        }
        int start2 = 0, end2 = (int) matrix[start1 - 1].size();
        while (start2 < end2) {
            int middle = start2 + (end2 - start2) / 2;
            if (matrix[row][middle] == target) {
                return true;
            }
            else if (matrix[row][middle] > target) {
                end2 = middle;
            }
            else {
                start2 = middle + 1;
            }
        }
        return false;
    }
};