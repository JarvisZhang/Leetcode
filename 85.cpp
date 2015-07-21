//
//  85.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/30.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int maxArea = 0, row = (int) matrix.size(), col = (int) matrix[0].size();
        vector<vector<int>> heights(row, vector<int>(col + 1, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!i && matrix[i][j] == '1') {
                    heights[i][j] = 1;
                }
                else if (matrix[i][j] == '1') {
                    heights[i][j] = heights[i-1][j] + 1;
                }
            }
        }
        stack<int> incremental;
        for (int i = 0; i < row; i++) {
            int j = 0, start = 0;
            while (j <= col) {
                if (incremental.empty() || heights[i][incremental.top()] <= heights[i][j]) {
                    if (heights[i][j]) {
                        incremental.push(j++);
                    }
                    else {
                        start = ++j;
                    }
                }
                else {
                    int highest = incremental.top();
                    incremental.pop();
                    maxArea = max(maxArea, heights[i][highest] * (incremental.empty() ? j - start : j - incremental.top() - 1));
                }
            }
        }
        return maxArea;
    }
};

class Test {
private:
    static void runTest(char ch) {
        vector<vector<char>> matrix(1, vector<char>(1, '1'));
        Solution solution;
        int result = solution.maximalRectangle(matrix);
        cout << result << endl;
    }
    
public:
    void sample() {
        char ch = '1';
        runTest(ch);
    }
};