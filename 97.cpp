//
//  97.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/18.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Interleaving String
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = (int) s1.size(), n = (int) s2.size();
        if (m == 0) {
            return s2 == s3;
        }
        if (n == 0) {
            return s1 == s3;
        }
        if (m + n != s3.size()) {
            return false;
        }
        bool matched[m+1][n+1];
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                matched[i][j] = (i > 0 && matched[i-1][j] && s1[i-1] == s3[i+j-1]) ||
                                (j > 0 && matched[i][j-1] && s2[j-1] == s3[i+j-1]) ||
                                (i == 0 && j == 0);
            }
        }
        return matched[m][n];
    }
};
