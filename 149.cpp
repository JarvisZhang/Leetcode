//
//  149.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/9/1.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Max Points on a Line
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        unordered_map<double, int> slopes;
        int result = 0;
        for (int i = 0; i < points.size(); i++) {
            slopes.clear();
            int duplicates = 1, currentMax = 0;
            for (int j = i + 1; j < points.size(); j++) {
                int deltaX = points[j].x - points[i].x;
                int deltaY = points[j].y - points[i].y;
                if (!deltaY && !deltaX) {
                    duplicates++;
                    continue;
                }
                double currentSlope = numeric_limits<double>::infinity();
                if (deltaX) {
                    currentSlope = (double) (deltaY) / (double) (deltaX);
                }
                if (slopes.find(currentSlope) == slopes.end()) {
                    slopes[currentSlope] = 1;
                }
                else {
                    slopes[currentSlope]++;
                }
                currentMax = max(currentMax, slopes[currentSlope]);
            }
            result = max(result, currentMax + duplicates);
        }
        return result;
    }
};