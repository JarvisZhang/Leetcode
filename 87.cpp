//
//  87.cpp
//  LeetCode
//
//  Created by 张佐玮 on 15/7/16.
//  Copyright (c) 2015年 JarvisZhang. All rights reserved.
//
//  Title: Scramble String
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        const long length = s1.size();
        if (s1.size() != s2.size()) {
            return false;
        }
        if (length == 0) {
            return true;
        }
        bool sramble[length][length][length];
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                sramble[0][i][j] = s1[i] == s2[j];
            }
        }
        for (int k = 1; k < length; k++) {
            for (int i = 0; i < length - k; i++) {
                for (int j = 0; j < length - k; j++) {
                    bool current = false;
                    for (int l = 0; l < k && !current; l++) {
                        current = (sramble[l][i][j] && sramble[k-l-1][i+l+1][j+l+1]) || (sramble[l][i][j+k-l] && sramble[k-l-1][i+l+1][j]);
                    }
                    sramble[k][i][j] = current;
                }
            }
        }
        return sramble[length-1][0][0];
    }
};