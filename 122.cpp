//
//  122.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/21.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Best Time to Buy and Sell Stock II
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int current = prices[0], profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > current) {
                profit += prices[i] - current;
            }
            current = prices[i];
        }
        return profit;
    }
};