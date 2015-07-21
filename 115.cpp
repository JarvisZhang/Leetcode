//
//  115.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/20.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Distinct Subsequences
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = (int) s.size(), n = (int) t.size();
        int distinct[m+1][n+1];
        distinct[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            distinct[0][i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            distinct[i][0] = 1;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                distinct[i][j] = s[i-1] == t[j-1] ? distinct[i-1][j-1] + distinct[i-1][j] : distinct[i-1][j];
            }
        }
        return distinct[m][n];
    }
};