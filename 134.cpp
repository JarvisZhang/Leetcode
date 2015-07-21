//
//  134.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/6/28.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Gas Station
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.empty() || cost.empty()) {
            return -1;
        }
        int start = 0, end = 0, current = gas[start] - cost[start], length = (int) gas.size();
        while (start % length != (end + 1) % length) {
            if (current > 0) {
                end = (end + 1) % length;
                current += gas[end] - cost[end];
            }
            else {
                start = (start + length - 1) % length;
                current += gas[start] - cost[start];
            }
        }
        return current >= 0 ? start : -1;
    }
};