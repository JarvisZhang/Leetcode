//
//  84.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/30.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Largest Rectangle in Histogram
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        stack<int> incremental;
        int maxArea = 0, current = 0, start = 0;
        while (current <= height.size()) {
            if (incremental.empty() || (current < height.size() && height[incremental.top()] <= height[current])) {
                if (height[current] != 0) {
                    incremental.push(current++);
                }
                else {
                    start = ++current;
                }
            }
            else {
                int highest = incremental.top();
                incremental.pop();
                maxArea = max(maxArea, height[highest] * (incremental.empty() ? current - start : current - incremental.top() - 1));
            }
        }
        return maxArea;
    }
};

class Test {
private:
    static void runTest(int input[], int length) {
        vector<int> v(input, input + length);
        Solution solution;
        int result = solution.largestRectangleArea(v);
        cout << result << endl;
    }
    
public:
    void sample() {
        int input1[] = {4, 2}, length1 = 2;
        int input2[] = {4, 2, 0, 3, 2, 5}, length2 = 6;
        int input3[] = {3, 6, 5, 7, 4, 8, 1, 0}, length3 = 8;
        runTest(input1, length1);
        runTest(input2, length2);
        runTest(input3, length3);
    }
};