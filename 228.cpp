//
//  228.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/8/1.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Summary Ranges
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> results;
        if (nums.empty()) {
            return results;
        }
        int start = 0, end = 0;
        for (int i = 1; i <= nums.size(); i++) {
            if (i < nums.size() && nums[i] == nums[i-1] + 1) {
                end = i;
            }
            else {
                string newRange;
                newRange += to_string(nums[start]);
                if (start != end) {
                    newRange += "->" + to_string(nums[end]);
                }
                results.push_back(newRange);
                start = ++end;
            }
        }
        return results;
    }
};