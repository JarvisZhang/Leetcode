//
//  96.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/5.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Unique Binary Search Trees
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> nums(n + 1, 0);
        nums[0] = 1;
        for (int i = 1; i < n + 1; i++) {
            for (int j = 0; j < i; j++) {
                nums[i] += nums[i-j-1] * nums[j];
            }
        }
        return nums[n];
    }
};