//
//  221.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/17.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Maximal Square
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int height = (int) matrix.size(), width = (int) matrix[0].size();
        int length[height][width], maximum = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (matrix[i][j] == '0') {
                    length[i][j] = 0;
                }
                else {
                    if (i == 0 || j == 0) {
                        length[i][j] = 1;
                    }
                    else {
                        length[i][j] = min(min(length[i-1][j], length[i][j-1]), length[i-1][j-1]) + 1;
                    }
                    maximum = max(maximum, length[i][j]);
                }
            }
        }
        return maximum * maximum;
    }
};