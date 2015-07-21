//
//  72.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/20.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Edit Distance
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = (int) word1.size(), n = (int) word2.size();
        int distance[m+1][n+1];
        for (int i = 0; i <= n; i++) {
            distance[0][i] = i;
        }
        for (int i = 0; i <= m; i++) {
            distance[i][0] = i;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    distance[i][j] = distance[i-1][j-1];
                }
                else {
                    distance[i][j] = min(min(distance[i-1][j], distance[i][j-1]), distance[i-1][j-1]) + 1;
                }
            }
        }
        return distance[m][n];
    }
};