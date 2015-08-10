//
//  217.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/31.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Contains Duplicate
//

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> history;
        for (int i = 0; i < nums.size(); i++) {
            if (!history.insert(nums[i]).second) {
                return true;
            }
        }
        return false;
    }
};