//
//  218.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/9/3.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: The Skyline Problem
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> edge;
        for (auto &build: buildings) {
            edge.push_back({build[0], -build[2]});
            edge.push_back({build[1], build[2]});
        }
        sort(edge.begin(), edge.end());
        multiset<int> height({0});
        vector<pair<int, int>> result;
        int preHeight = 0, curHeight = 0;
        for (auto &point: edge) {
            if (point.second < 0) {
                height.insert(-point.second);
            }
            else {
                height.erase(height.lower_bound(point.second));
            }
            curHeight = *height.rbegin();
            if (curHeight != preHeight) {
                result.push_back({point.first, curHeight});
                preHeight = curHeight;
            }
        }
        return result;
    }
};

class Test {
public:
    void sample() {
        vector<vector<int>> buildings;
        buildings.push_back({0,2,3});
        buildings.push_back({2,5,3});
        Solution solution;
        vector<pair<int, int>> result = solution.getSkyline(buildings);
        for (auto &point: result) {
            cout << point.first << ", " << point.second << endl;
        }
    }
};