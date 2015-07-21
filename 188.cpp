//
//  188.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/21.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Best Time to Buy and Sell Stock IV
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0 || prices.empty()) {
            return 0;
        }
        int n = (int) prices.size();
        if ((n - 1) / 2 < k) {
            int result = 0;
            for (int i = 1; i < prices.size(); i++) {
                int latest = prices[i] - prices[i-1];
                result += latest > 0 ? latest : 0;
            }
            return result;
        }
        vector<vector<int>> profit(n, vector<int>(k, 0)), current(n, vector<int>(k, 0));
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k; j++) {
                int lastTran = prices[i] - prices[i-1];
                current[i][j] = max(current[i-1][j] + lastTran, profit[i-1][j-1] + max(lastTran, 0));
                profit[i][j] = max(profit[i-1][j], current[i][j]);
            }
        }
        return profit[n-1][k-1];
    }
};