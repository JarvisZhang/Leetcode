//
//  55.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/25.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Jump Game
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int distance = 0;
        for (int i = 0; i <= distance && distance < (nums.size() - 1) && i < nums.size(); i++) {
            distance = max(distance, i + nums[i]);
        }
        return distance >= (nums.size() - 1);
    }
};