//
//  268.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/9/9.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Missing Number
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int miss = (int) nums.size();
        for (int i = 0; i < nums.size(); i++) {
            miss ^= i;
            miss ^= nums[i];
        }
        return miss;
    }
};