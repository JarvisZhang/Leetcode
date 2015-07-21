//
//  120.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/15.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Triangle
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) {
            return INT_MAX;
        }
        long height = triangle.size();
        vector<int> currentMin(height, 0);
        currentMin[0] = triangle[0][0];
        for (int i = 1; i < height; i++) {
            currentMin[i] = currentMin[i-1] + triangle[i][i];
            for (int j = i - 1; j > 0; j--) {
                currentMin[j] = min(currentMin[j-1], currentMin[j]) + triangle[i][j];
            }
            currentMin[0] += triangle[i][0];
        }
        int minimum = INT_MAX;
        for (int total : currentMin) {
            minimum = min(minimum, total);
        }
        return minimum;
    }
};

class Test {
public:
    void sample() {
        vector<vector<int>> triangle1;
        triangle1.push_back({-1});
        triangle1.push_back({-2,-3});
        Solution solution;
        cout << solution.minimumTotal(triangle1) << endl;
    }
};