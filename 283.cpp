//
//  283.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/9/21.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Move Zeroes
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int loc = 0;
        for (int &num: nums) {
            if (num) {
                swap(num, nums[loc++]);
            }
        }
    }
};