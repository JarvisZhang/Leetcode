//
//  118.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/1.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Pascal's Triangle
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> results;
        if (numRows < 1) {
            return results;
        }
        results.push_back({1});
        for (int i = 1; i < numRows; i++) {
            vector<int> current;
            current.push_back(1);
            for (int j = 1; j < i; j++) {
                current.push_back(results.back()[j] + results.back()[j-1]);
            }
            current.push_back(1);
            results.push_back(current);
        }
        return results;
    }
};