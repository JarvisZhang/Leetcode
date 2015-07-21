//
//  16.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/3.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: 3Sum Closest
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) {
            return 0;
        }
        int absDistance = INT_MAX, distance = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int start = i + 1, end = (int) nums.size() - 1;
            while (start < end) {
                int current = nums[i] + nums[start] + nums[end] - target;
                if (current < 0) {
                    if (-current < absDistance) {
                        distance = current;
                        absDistance = -current;
                    }
                    start++;
                }
                else if (current > 0) {
                    if (current < absDistance) {
                        distance = current;
                        absDistance = current;
                    }
                    end--;
                }
                else {
                    return target;
                }
            }
        }
        return target + distance;
    }
};

class Test {
public:
    void sample() {
        int input1[] = {1, 1, 1, 0}, length1 = 4, target1 = 100;
        runTest(input1, length1, target1);
    }
    
private:
    static void runTest(int input[], int length, int target) {
        vector<int> v(input, input + length);
        Solution solution;
        int result = solution.threeSumClosest(v, target);
        cout << result << endl;
    }
};