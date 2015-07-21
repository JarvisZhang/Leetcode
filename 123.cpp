//
//  123.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/21.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Best Time to Buy and Sell Stock III
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
        int n = (int) prices.size(), current = 0;
        int singleProfit[n];
        singleProfit[0] = 0;
        for (int i = 0; i < n - 1; i++) {
            current = max(current + prices[i+1] - prices[i], 0);
            singleProfit[i+1] = max(singleProfit[i], current);
        }
        int reverserProfit = 0, result = 0;
        current = 0;
        for (int i = n - 2; i >= 0; i--) {
            current = max(current + prices[i+1] - prices[i], 0);
            reverserProfit = max(reverserProfit, current);
            result = max(result, reverserProfit + singleProfit[i]);
        }
        return result;
    }
};