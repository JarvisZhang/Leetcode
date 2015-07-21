//
//  42.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/4.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Trapping Rain Water
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0, start = 0, end = (int) height.size() - 1;
        while (start < end) {
            if (height[start] <= height[end]) {
                int border = height[start];
                while (++start < end && height[start] <= border) {
                    water += border - height[start];
                }
            }
            else {
                int border = height[end];
                while(start < --end && height[end] <= border) {
                    water += border -height[end];
                }
                
            }
        }
        return water;
    }
};

class Test {
public:
    void sample() {
        int input1[] = {}, length1 = 0;
        int input2[] = {0,1,0,2,1,0,1,3,2,1,2,1}, length2 = 12;
        int input3[] = {4,2,3}, length3 = 3;
        runTest(input1, length1);
        runTest(input2, length2);
        runTest(input3, length3);
    }
    
private:
    static void runTest(int input[], int length) {
        vector<int> v(input, input + length);
        Solution solution;
        int result = solution.trap(v);
        cout << result << endl;
    }
};