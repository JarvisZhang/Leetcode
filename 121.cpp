//
//  121.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/20.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Best Time to Buy and Sell Stock
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfitDP(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int current = 0, profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            current = max(current - prices[i-1] + prices[i], 0);
            profit = max(current, profit);
        }
        return profit;
    }
    
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int maximum = prices[0], minimum = prices[0], profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > maximum) {
                maximum = prices[i];
                profit = max(profit, maximum - minimum);
            }
            if (prices[i] < minimum) {
                minimum = prices[i];
                maximum = minimum;
            }
        }
        return profit;
    }
};