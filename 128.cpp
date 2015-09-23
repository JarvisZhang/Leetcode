//
//  128.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/31.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Longest Consecutive Sequence
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unique;
        int length = 1;
        for (int num: nums) {
            unique.insert(num);
        }
        for (int num: nums) {
            int ceil = num + 1, floor = num - 1;
            unique.erase(num);
            while (unique.find(ceil) != unique.end()) {
                unique.erase(ceil++);
            }
            while (unique.find(floor) != unique.end()) {
                unique.erase(floor--);
            }
            length = max(length, ceil - floor - 1);
        }
        return length;
    }
};